#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

struct Expense {
    std::string date;       // Expected format: YYYY-MM-DD
    double amount;        // Expense amount in dollars
    std::string category;   // Category of the expense
    std::string description;    // Description of the expense
    
    // Default constructor
    Expense() : date(""), amount(0.0), category(""), description("") {}
    
    // Parameterized constructor for initializing all fields
    Expense(const std::string& date, double amount, const std::string& category, const std::string& description)
        : date(date), amount(amount), category(category), description(description) {}
};

#endif // EXPENSE_H
