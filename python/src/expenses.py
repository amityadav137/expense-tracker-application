from datetime import datetime

class Expense:
    # Constructor to initialize an expense with date, amount, category, and description
    def __init__(self, date, amount, category, description):
        self.date = self.validate_date(date)
        self.amount = float(amount)
        self.category = category
        self.description = description

    # Method to validate the date format and ensure it is in 'YYYY-MM-DD'
    def validate_date(self, date_str):
        try:
            # Convert the date string to a datetime object
            return datetime.strptime(date_str, "%Y-%m-%d")
        except ValueError:
            # Raise an error if the date is not in the correct format
            raise ValueError("Invalid date format. Use YYYY-MM-DD.")

    # Method to return the expense as a dictionary for easy conversion to JSON
    def to_dict(self):
        return {
            "date": self.date.strftime("%Y-%m-%d"),
            "amount": self.amount,
            "category": self.category,
            "description": self.description
        }
    
    # String representation of the expense (for pretty printing)
    def __str__(self):
        return f"{self.date.strftime('%Y-%m-%d')} | ${self.amount:.2f} | {self.category} | {self.description}"
    