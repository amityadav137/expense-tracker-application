// ExpenseStorage.cpp
#include "ExpenseStorage.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

void saveExpenses(const std::vector<Expense>& expenses, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file for writing: " << filename << "\n";
        return;
    }
    // Save each expense on a new line in the format: date|amount|category|description
    for (const auto& exp : expenses) {
        file << exp.date << "|" << exp.amount << "|" << exp.category << "|" << exp.description << "\n";
    }
}

void loadExpenses(std::vector<Expense>& expenses, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file for reading: " << filename << "\n";
        return;
    }
    expenses.clear();
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        std::istringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(ss, token, '|')) {
            tokens.push_back(token);
        }
        if (tokens.size() < 4) {
            std::cerr << "Error: Invalid expense format: " << line << "\n";
            continue;
        }
        Expense exp;
        exp.date = tokens[0];
        try {
            exp.amount = std::stod(tokens[1]);
        } catch (const std::exception& e) {
            std::cerr << "Error converting amount: " << e.what() << "\n";
            continue;
        }
        exp.category = tokens[2];
        exp.description = tokens[3];
        expenses.push_back(exp);
    }
}
