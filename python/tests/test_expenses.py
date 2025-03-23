import unittest
import sys
import os

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "../src")))

from expenses import Expense

class TestExpense(unittest.TestCase):
    def test_expense_creation(self):
        exp = Expense("2025-03-17", 20.5, "Food", "Lunch")
        self.assertEqual(exp.date.strftime("%Y-%m-%d"), "2025-03-17")
        self.assertEqual(exp.amount, 20.5)
        self.assertEqual(exp.category, "Food")
        self.assertEqual(exp.description, "Lunch")

    def test_invalid_date(self):
        with self.assertRaises(ValueError):
            Expense("invalid-date", 20.5, "Food", "Lunch")

if __name__ == "__main__":
    unittest.main()
