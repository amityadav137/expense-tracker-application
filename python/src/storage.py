import json
import os
from expenses import Expense

DATA_FILE = "python/data/expenses.json"

def load_expenses():
    if not os.path.exists(DATA_FILE):
        print(f"Error: {DATA_FILE} does not exist.")
        return []
    
    with open(DATA_FILE, "r") as file:
        try:
            data = json.load(file)
            return [Expense(**exp) for exp in data]
        except json.JSONDecodeError:
            return []

def save_expenses(expenses):
    expenses.sort(key = lambda x: x.date) # make sure transactions are sorted

    with open(DATA_FILE, "w") as file:
        json.dump([exp.to_dict() for exp in expenses], file, indent=4)

def edit_expenses(expenses, exp, new_date, new_category, new_amount, new_description):
    exp.date = exp.validate_date(new_date)
    exp.category = new_category
    exp.amount = float(new_amount)
    exp.description = new_description

    print(f"Updated expense: {exp}")

def delete_expenses(exp, expenses):
    expenses.remove(exp)