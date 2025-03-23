#include <iostream>
#include <limits>
#include "ExpenseTracker.h"
#include "ExpenseStorage.h"

#include <sstream>
#include <algorithm>
#include <cctype>

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

int main()
{
    std::vector<Expense> expenses;
    const std::string filename = "expenses.txt";

    // Load expenses from file when the program starts
    loadExpenses(expenses, filename);

    ExpenseTracker tracker;
    int choice;
    bool running = true;
    tracker.setExpenses(expenses);

    while (running)
    {
        displayMenu();

        // Validate input for numeric choice
        if (!(std::cin >> choice))
        {
            std::cin.clear();                                                   // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number.\n";
            continue; // Restart loop to prompt again
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any extra input

        if (choice == 1)
        {
            std::string date, category, description;
            double amount;

            std::cout << "Enter date (YYYY-MM-DD): ";
            std::getline(std::cin, date);
            std::cout << "Enter amount: ";
            std::cin >> amount;
            std::cin.ignore(); // Clear newline
            std::cout << "Enter category: ";
            std::getline(std::cin, category);
            std::cout << "Enter description: ";
            std::getline(std::cin, description);
            category = fmtText(category);
            description = fmtText(description);
            tracker.addExpense(Expense(date, amount, category, description));
        }
        else if (choice == 2)
        {
            std::string date, category, description;
            double amount;
            int sno;
            tracker.printExpenses(tracker.filterByDateRange("0000-00-00", "9999-12-31"));
            std::cout << "Enter S.no of expense to edit. \n";
            std::cout << "Or '0' to stop edit: ";
            std::cin >> sno;
            std::cin.ignore(); // Clear newline
            if (sno == 0)
            {
                continue;
            }
            tracker.getExpensesByIndex(sno - 1);
            std::cout << "Enter date (YYYY-MM-DD) of expense to edit:";
            std::getline(std::cin, date);


            std::cout << "Enter amount of expense to edit: ";
            std::cin >> amount;
            std::cin.ignore(); // Clear newline
            std::cout << "Enter category of expense to edit: ";
            std::getline(std::cin, category);
            std::cout << "Enter description of expense to edit: ";
            std::getline(std::cin, description);
            category = fmtText(category);
            description = fmtText(description);
            tracker.editExpense(sno - 1, Expense(date, amount, category, description));
            tracker.printExpenses(tracker.filterByDateRange("0000-00-00", "9999-12-31"));
        }
        else if (choice == 3)
        {
            int sno;
            tracker.printExpenses(tracker.filterByDateRange("0000-00-00", "9999-12-31"));
            std::cout << "Enter S.no of expense to delete.\n";
            std::cout << "Or '0' to stop delete: ";
            std::cin >> sno;
            std::cin.ignore(); // Clear newline
            if (sno != 0)
            {
                tracker.deleteExpense(sno - 1);
                tracker.printExpenses(tracker.filterByDateRange("0000-00-00", "9999-12-31"));
            }
        }
        else if (choice == 4)
        {
            tracker.printExpenses(tracker.filterByDateRange("0000-00-00", "9999-12-31"));
        }
        else if (choice == 5)
        {
            std::string startDate, endDate;
            std::cout << "Enter start date (YYYY-MM-DD): ";
            std::getline(std::cin, startDate);
            std::cout << "Enter end date (YYYY-MM-DD): ";
            std::getline(std::cin, endDate);
            auto filtered = tracker.filterByDateRange(startDate, endDate);
            std::cout << "Filtered By Dates\n";
            tracker.printExpenses(filtered);
        }
        else if (choice == 6)
        {
            std::string category;
            std::cout << "Enter category: ";
            std::getline(std::cin, category);
            category = fmtText(category);
            auto filtered = tracker.filterByCategory(category);
            tracker.printExpenses(filtered);
        }
        else if (choice == 7)
        {
            tracker.printSummary();
        }
        else if (choice == 8)
        {
            running = false;
        }
        else
        {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    expenses = tracker.getExpenses();
    // Save expenses to file when the program exits
    saveExpenses(expenses, filename);

    return 0;
}
