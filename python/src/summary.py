from collections import defaultdict

# sum all expenses function
def total_expenses(expenses):
    return sum(exp.amount for exp in expenses)

# sum expenses by category using dictionary
def expenses_by_category(expenses):
    category_totals = defaultdict(float)
    for exp in expenses:
        category_totals[exp.category] += exp.amount
    return category_totals