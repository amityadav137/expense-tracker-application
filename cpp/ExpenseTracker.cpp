/**
 * @file ExpenseTracker.cpp
 * @brief Implementation of ExpenseTracker class to manage a collection of expenses.
 */

#include "ExpenseTracker.h"
#include <iostream>

/**
 * @brief Adds a new expense to the tracker.
 * @param expense The expense to add.
 */
void ExpenseTracker::addExpense(const Expense& expense) {
    expenses.push_back(expense);
}

/**
 * @brief Edits an existing expense at the given index.
 * @param index The position of the expense in the collection.
 * @param expense The updated expense data.
 */
void ExpenseTracker::editExpense(const int index, const Expense& expense) {
    if (index < expenses.size()) {
        expenses[index] = expense;
        std::cout << "Expense edited successfully.\n";
    }
}

/**
 * @brief Deletes an expense at the given index.
 * @param index The position of the expense to delete.
 */
void ExpenseTracker::deleteExpense(const int index) {
    if (index < expenses.size()) {
        expenses.erase(expenses.begin() + index);
        std::cout << "Expense deleted successfully.\n";
    }
}

/**
 * @brief Prints the details of an expense at the given index.
 * @param index The position of the expense to view.
 */
void ExpenseTracker::getExpensesByIndex(const int index) {
    if (index < expenses.size()) {
        std::cout << "Expense Details:\n";
        std::cout << "Date: " << expenses[index].date
                  << "\nAmount:  $" << expenses[index].amount
                  << "\nCategory: " << expenses[index].category
                  << "\nDescription: " << expenses[index].description << "\n";
    }
}

/**
 * @brief Sets the entire expenses list.
 * @param expenses The new list of expenses.
 */
void ExpenseTracker::setExpenses(const std::vector<Expense>& expenses) {
    this->expenses = expenses;
}

/**
 * @brief Retrieves the entire list of expenses.
 * @return A vector containing all expenses.
 */
std::vector<Expense> ExpenseTracker::getExpenses() {
    return expenses;
}

/**
 * @brief Filters expenses by a date range.
 * @param startDate The start date in YYYY-MM-DD format.
 * @param endDate The end date in YYYY-MM-DD format.
 * @return A vector of expenses within the given range.
 */
std::vector<Expense> ExpenseTracker::filterByDateRange(const std::string& startDate, const std::string& endDate) const {
    std::vector<Expense> filtered;
    for (const auto& expense : expenses) {
        if (expense.date >= startDate && expense.date <= endDate) {
            filtered.push_back(expense);
        }
    }
    return filtered;
}

/**
 * @brief Filters expenses by a specific category.
 * @param category The category to filter by.
 * @return A vector of expenses matching the category.
 */
std::vector<Expense> ExpenseTracker::filterByCategory(const std::string& category) const {
    std::vector<Expense> filtered;
    for (const auto& expense : expenses) {
        if (expense.category == category) {
            filtered.push_back(expense);
        }
    }
    return filtered;
}

/**
 * @brief Prints expenses to the console.
 * @param expensesToPrint A vector of expenses to display.
 */
void ExpenseTracker::printExpenses(const std::vector<Expense>& expensesToPrint) const {
    std::cout << "\nExpenses:\n";
    std::cout << "S.no | Date | Amount | Category | Description\n";
    std::cout << "----------------------------------------------------\n";
    if(expensesToPrint.empty()){
        std::cout << "No expenses to display\n";
    }
    for (size_t i = 0; i < expensesToPrint.size(); ++i) {
        std::cout << (i + 1) << ". "
                  << expensesToPrint[i].date << " | "
                  << "$" << expensesToPrint[i].amount << " | "
                  << expensesToPrint[i].category << " | "
                  << expensesToPrint[i].description << "\n";
    }
}

/**
 * @brief Prints a summary of expenses grouped by category.
 */
void ExpenseTracker::printSummary() const {
    std::map<std::string, double> categoryTotals;
    double overallTotal = 0.0;

    for (const auto& expense : expenses) {
        categoryTotals[expense.category] += expense.amount;
        overallTotal += expense.amount;
    }

    std::cout << "\nExpense Summary:\n";
    for (const auto& pair : categoryTotals) {
        std::cout << "Category: " << pair.first
                  << "\n Total: " << pair.second
                  << "\n====================\n";
    }
    std::cout << "Overall Total: " << overallTotal << "\n";
}
