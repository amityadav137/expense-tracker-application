#ifndef EXPENSE_TRACKER_H
#define EXPENSE_TRACKER_H

#include "Expense.h"
#include <vector>
#include <string>
#include <map>

class ExpenseTracker {
private:
    std::vector<Expense> expenses;
    
public:
    // Adds a new expense to the tracker.
    void addExpense(const Expense& expense);

    //Edits an existing expense in the tracker.
    void editExpense(const int index, const Expense& expense);

    //Deletes an existing expense in the tracker.
    void deleteExpense(const int index);
    
    void getExpensesByIndex(const int index);

    void setExpenses(const std::vector<Expense>& expenses);

    std::vector<Expense> getExpenses();

    // Returns expenses within the provided date range.
    std::vector<Expense> filterByDateRange(const std::string& startDate, const std::string& endDate) const;
    
    // Returns expenses that match the provided category.
    std::vector<Expense> filterByCategory(const std::string& category) const;
    
    // Prints a list of expenses.
    void printExpenses(const std::vector<Expense>& expensesToPrint) const;
    
    // Prints a summary of total expenses by category and overall.
    void printSummary() const;
};

#endif // EXPENSE_TRACKER_H
