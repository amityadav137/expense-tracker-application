// ExpenseStorage.h
#ifndef EXPENSE_STORAGE_H
#define EXPENSE_STORAGE_H

#include <vector>
#include <string>
#include "ExpenseTracker.h"  // Assumes Expense is defined with date, amount, category, description

// Saves the expenses vector to the specified file.
// Each expense is saved in the format: date|amount|category|description
void saveExpenses(const std::vector<Expense>& expenses, const std::string& filename);

// Loads expenses from the specified file into the vector.
// Expects each line in the file to be formatted as: date|amount|category|description
void loadExpenses(std::vector<Expense>& expenses, const std::string& filename);

#endif // EXPENSE_STORAGE_H
