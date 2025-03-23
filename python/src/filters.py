from datetime import datetime # import datetime module for date handling

# filter expenses with a certain category
def filter_by_category(expenses, category):
    return [exp for exp in expenses if exp.category.lower() == category.lower()]

# filter by start and end date (inclusive)
def filter_by_date_range(expenses, start_date, end_date):
    start = datetime.strptime(start_date, "%Y-%m-%d")
    end = datetime.strptime(end_date, "%Y-%m-%d")
    return [exp for exp in expenses if start <= exp.date <= end]