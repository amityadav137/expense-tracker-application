from collections import defaultdict

def total_expenses(expenses):
    return sum(exp.amount for exp in expenses)

def expenses_by_category(expenses):
    category_totals = defaultdict(float)
    for exp in expenses:
        category_totals[exp.category] += exp.amount
    return category_totals