#include "ExpenseTracker.h"
#include <iostream>


void ExpenseTracker::addExpense(const Expense& expense) {
    expenses.push_back(expense);
}

void ExpenseTracker::editExpense(const int index, const Expense& expense) {
    if (index < expenses.size()) {
        // Modify expenses[index] as needed
        expenses[index] = expense;
        std::cout << "Expense edited successfully.\n";
    }
}

void ExpenseTracker::deleteExpense(const int index) {
    if (index < expenses.size()) {
        expenses.erase(expenses.begin() + index);
        std::cout << "Expense deleted successfully.\n";
    }
}

void ExpenseTracker::getExpensesByIndex(const int index) {
    if (index < expenses.size()) {
        std::cout << "Expense Details:\n";
        std::cout << "Date: " << expenses[index].date 
        << "\nAmount:  $" << expenses[index].amount  
        << "\nCategory: " << expenses[index].category 
        << "\nDescription: " << expenses[index].description << "\n";
    }
}

void ExpenseTracker::setExpenses(const std::vector<Expense>& expenses) {
    this->expenses = expenses;
}

std::vector<Expense> ExpenseTracker::getExpenses() {
    return expenses;
}

std::vector<Expense> ExpenseTracker::filterByDateRange(const std::string& startDate, const std::string& endDate) const {
    std::vector<Expense> filtered;
    for (const auto& expense : expenses) {
        // This simple comparison assumes dates are in ISO format (YYYY-MM-DD)
        if (expense.date >= startDate && expense.date <= endDate) {
            filtered.push_back(expense);
        }
    }
    return filtered;
}

std::vector<Expense> ExpenseTracker::filterByCategory(const std::string& category) const {
    std::vector<Expense> filtered;
    for (const auto& expense : expenses) {
        if (expense.category == category) {
            filtered.push_back(expense);
        }
    }
    return filtered;
}

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

void ExpenseTracker::printSummary() const {
    std::map<std::string, double> categoryTotals;
    double overallTotal = 0.0;
    
    for (const auto& expense : expenses) {
        categoryTotals[expense.category] += expense.amount;
        overallTotal += expense.amount;
    }
    
    std::cout << "\nExpense Summary:\n";
    for (const auto& pair : categoryTotals) {
        std::cout << "Category: " << pair.first << "\n Total: " << pair.second << "\n====================\n";
    }
    std::cout << "Overall Total: " << overallTotal << "\n";
}
