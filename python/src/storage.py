import json
import os
from expenses import Expense

# Path to the JSON data file where expenses are stored
DATA_FILE = "python/data/expenses.json"

# Function to load expenses from the JSON file
def load_expenses():
    # Check if the data file exists
    if not os.path.exists(DATA_FILE):
        print(f"Error: {DATA_FILE} does not exist.")
        return []
    
    # Open and read the data from the file
    with open(DATA_FILE, "r") as file:
        try:
            data = json.load(file)
            return [Expense(**exp) for exp in data]
        except json.JSONDecodeError:
            return []
        
# Function to save the list of expenses back to the JSON file
def save_expenses(expenses):
    expenses.sort(key = lambda x: x.date) # make sure transactions are sorted

    with open(DATA_FILE, "w") as file:
        json.dump([exp.to_dict() for exp in expenses], file, indent=4)

# Function to edit an existing expense with new details
def edit_expenses(exp, new_date, new_category, new_amount, new_description):
    exp.date = exp.validate_date(new_date)
    exp.category = new_category
    exp.amount = float(new_amount)
    exp.description = new_description

    print(f"Updated expense: {exp}")

# Function to delete an expense from the list
def delete_expenses(exp, expenses):
    expenses.remove(exp)
