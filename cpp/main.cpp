#include <iostream>
#include <limits>
#include "ExpenseTracker.h"  // Provides class for managing expenses
#include "ExpenseStorage.h"  // Offers functions to load/save expenses

#include <sstream>
#include <algorithm>
#include <cctype>

/**
 * Formats a given string by capitalizing the first letter of each word
 * and converting the rest to lowercase.
 * @param s Input string.
 * @return Formatted string.
 */
std::string fmtText(const std::string &s)
{
    std::istringstream iss(s);
    std::string word, result;
    while (iss >> word)
    {
        word.front() = std::toupper(word.front());
        std::transform(word.begin() + 1, word.end(), word.begin() + 1, ::tolower);
        result += (result.empty() ? "" : " ") + word;
    }
    return result;
}

/**
 * Displays the main menu options to the user.
 */
void displayMenu()
{
    std::cout << "\nExpense Tracker Menu:\n";
    std::cout << "1. Add Expense\n";
    std::cout << "2. Edit Expense\n";
    std::cout << "3. Delete Expense\n";
    std::cout << "4. View All Expenses\n";
    std::cout << "5. Filter Expenses by Date Range\n";
    std::cout << "6. Filter Expenses by Category\n";
    std::cout << "7. Print Summary\n";
    std::cout << "8. Exit\n";
    std::cout << "Enter your choice: ";
}

/**
 * Main function that drives the Expense Tracker application.
 * Loads existing expenses, handles user menu input, and saves data on exit.
 */
int main()
{
    std::vector<Expense> expenses;
    const std::string filename = "expenses.txt";

    // Load expenses from file when the program starts
    loadExpenses(expenses, filename);

    ExpenseTracker tracker;
    int choice;
    bool running = true;

    // Set the loaded expenses in the tracker
    tracker.setExpenses(expenses);

    while (running)
    {
        displayMenu();

        // Validate input for numeric choice
        if (!(std::cin >> choice))
        {
            // Clear error flag and ignore the rest of the input buffer
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        // Clear input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Add expense
        if (choice == 1)
        {
            std::string date, category, description;
            double amount;
            std::cout << "Enter date (YYYY-MM-DD): ";
            std::getline(std::cin, date);
            std::cout << "Enter amount: ";
            std::cin >> amount;
            std::cin.ignore();
            std::cout << "Enter category: ";
            std::getline(std::cin, category);
            std::cout << "Enter description: ";
            std::getline(std::cin, description);

            // Format category and description
            category = fmtText(category);
            description = fmtText(description);
            tracker.addExpense(Expense(date, amount, category, description));
        }

        // Edit expense
        else if (choice == 2)
        {
            std::string date, category, description;
            double amount;
            int sno;
            tracker.printExpenses(tracker.filterByDateRange("0000-00-00", "9999-12-31"));
            std::cout << "Enter S.no of expense to edit.\nOr '0' to stop edit: ";
            std::cin >> sno;
            std::cin.ignore();// Clear input buffer

            // Skip edit if sno is 0
            if (sno == 0)
            {
                continue;
            }

            // Get expense details to edit
            tracker.getExpensesByIndex(sno - 1);

            // Get new expense details
            std::cout << "Enter date (YYYY-MM-DD) of expense to edit: ";
            std::getline(std::cin, date);
            std::cout << "Enter amount of expense to edit: ";
            std::cin >> amount;
            std::cin.ignore();
            std::cout << "Enter category of expense to edit: ";
            std::getline(std::cin, category);
            std::cout << "Enter description of expense to edit: ";
            std::getline(std::cin, description);

            // Format category and description
            category = fmtText(category);
            description = fmtText(description);

            // Edit the expense
            tracker.editExpense(sno - 1, Expense(date, amount, category, description));

            // Display updated expenses
            tracker.printExpenses(tracker.filterByDateRange("0000-00-00", "9999-12-31"));
        }

        // Delete expense
        else if (choice == 3)
        {
            int sno;
            tracker.printExpenses(tracker.filterByDateRange("0000-00-00", "9999-12-31"));
            std::cout << "Enter S.no of expense to delete.\nOr '0' to stop delete: ";
            std::cin >> sno;
            std::cin.ignore();// Clear input buffer
            
            // Skip delete if sno is 0
            if (sno != 0)
            {
                tracker.deleteExpense(sno - 1);// Delete the expense
                tracker.printExpenses(tracker.filterByDateRange("0000-00-00", "9999-12-31"));// Display updated expenses
            }
        }

        // View all expenses
        else if (choice == 4)
        {
            tracker.printExpenses(tracker.filterByDateRange("0000-00-00", "9999-12-31"));// Display all expenses
        }

        // Filter expenses by date range
        else if (choice == 5)
        {
            std::string startDate, endDate;
            std::cout << "Enter start date (YYYY-MM-DD): ";
            std::getline(std::cin, startDate);
            std::cout << "Enter end date (YYYY-MM-DD): ";
            std::getline(std::cin, endDate);
            
            auto filtered = tracker.filterByDateRange(startDate, endDate);
            std::cout << "Filtered By Dates\n";
            tracker.printExpenses(filtered);// Display filtered expenses
        }
        // Filter expenses by category
        else if (choice == 6)
        {
            std::string category;
            std::cout << "Enter category: ";
            std::getline(std::cin, category);
            category = fmtText(category);// Format category
            auto filtered = tracker.filterByCategory(category);// Filter by category

            std::cout << "Filtered By Category\n";
            tracker.printExpenses(filtered);
        }
        // Print summary of expenses
        else if (choice == 7)
        {
            tracker.printSummary();
        }
        // Exit the program
        else if (choice == 8)
        {
            running = false;
        }
        // Invalid choice
        else
        {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    expenses = tracker.getExpenses();// Get updated expenses from the tracker
    // Save expenses to file when the program exits
    saveExpenses(expenses, filename);

    return 0;
}
