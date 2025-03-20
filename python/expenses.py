from datetime import datetime

class Expense:
    def __init__(self, date, amount, category, description):
        self.date = self.validate_date(date)
        self.amount = float(amount)
        self.category = category
        self.description = description

    def validate_date(self, date_str):
        try:
            return datetime.strptime(date_str, "%Y-%m-%d")
        except ValueError:
            raise ValueError("Invalid date format. Use YYYY-MM-DD.")

    def to_dict(self):
        return {
            "date": self.date.strftime("%Y-%m-%d"),
            "amount": self.amount,
            "category": self.category,
            "description": self.description
        }

    def __str__(self):
        return f"{self.date.strftime('%Y-%m-%d')} | ${self.amount:.2f} | {self.category} | {self.description}"
    