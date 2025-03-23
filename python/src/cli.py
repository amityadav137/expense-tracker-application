# import class and functions
from expenses import Expense
from storage import load_expenses, save_expenses, edit_expenses, delete_expenses
from filters import filter_by_category, filter_by_date_range
from summary import total_expenses, expenses_by_category

def run_cli():
    # load current data from JSON file
    expenses = load_expenses()

    while True: # print menu options
        print("\nExpense Tracker Menu:")
        print("1. Add Expense")
        print("2. View Expenses")
        print("3. Edit an Expense")
        print("4. Delete an Expense")
        print("5. Filter Expenses")
        print("6. Show Summary")
        print("7. Exit")

        choice = input("Select an option: ")

        if choice == "1": # add expense
            # take input for the new expense
            date = input("Enter date (YYYY-MM-DD): ")
            amount = input("Enter amount: ")
            category = input("Enter category: ")
            description = input("Enter description: ")
            
            # make sure the new expense is properly formatted
            try:
                expense = Expense(date, amount, category, description)
                expenses.append(expense)
                save_expenses(expenses)
                print("Expense added successfully!")
            except ValueError as e:
                print(f"Error: {e}")

        elif choice == "2": #print all expenses
            print("\nExpenses:")
            for exp in expenses:
                print(exp)

        elif choice == "3": # edit an existing expense
            print("\nChoose an expense:")
            for i in range(len(expenses)):
                print(f"{i + 1}. {expenses[i]}")
            
            # choose an expense to edit
            while True:
                idx = int(input("Make your selection: "))
                if idx <= 0 or idx > len(expenses):
                    print("Invalid choice! Please choose again!")
                else:       
                    exp = expenses[idx - 1]
                    break
            
            # collect new data to make changes
            new_date = input("Enter new date (YYYY-MM-DD): ")
            new_amount = input("Enter new amount: ")
            new_category = input("Enter new category: ")
            new_description = input("Enter new description: ")
            
            # make the edit and save
            edit_expenses(exp, new_date, new_category, new_amount, new_description)
            save_expenses(expenses)

        elif choice == "4": # delete an expense
            # print current expenses
            print("\nChoose an expense:")
            for i in range(len(expenses)):
                print(f"{i + 1}. {expenses[i]}")
            
            # choose an expense to delete
            while True:
                idx = int(input("Make your selection: "))
                if idx <= 0 or idx > len(expenses):
                    print("Invalid choice! Please choose again!")
                else:       
                    exp = expenses[idx - 1]
                    break
            
            # delete and save
            delete_expenses(exp, expenses)
            save_expenses(expenses)
            print("\nExpense is successfully deleted!")

        elif choice == "5": # filter
            # filter options
            filter_choice = input("Filter by (1) Category or (2) Date Range? ")
            if filter_choice == "1": # filter by category
                category = input("Enter category: ")
                filtered = filter_by_category(expenses, category)
            elif filter_choice == "2": # filter by date
                start_date = input("Enter start date (YYYY-MM-DD): ")
                end_date = input("Enter end date (YYYY-MM-DD): ")
                filtered = filter_by_date_range(expenses, start_date, end_date)
            else:
                print("Invalid choice.")
                continue
            
            # print out filtered expenses
            print("\nFiltered Expenses:")
            for exp in filtered:
                print(exp)

        elif choice == "6": #summary
            # total expenses
            print(f"Total Expenses: ${total_expenses(expenses):.2f}")
            # total by category
            category_totals = expenses_by_category(expenses)
            for category, total in category_totals.items():
                print(f"{category}: ${total:.2f}")

        elif choice == "7": # exit 
            print("Goodbye!")
            break

        else: # invalid input
            print("Invalid option. Try again.")