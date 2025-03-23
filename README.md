# Expense Tracker Application

This repository contains two implementations of an Expense Tracker application.  
- The **Python version** demonstrates dynamic typing, dictionaries for data storage, and JSON-based persistence.  
- The **C++ version** showcases memory management, the use of structs/classes, and STL containers.

---

## Table of Contents

- [Overview](#overview)
- [Project Structure](#project-structure)
- [Running the Python Application](#running-the-python-application)
- [Running the C++ Application](#running-the-c-application)
- [Additional Information](#additional-information)

---

## Overview

The Expense Tracker application allows users to record, view, and categorize expenses. Core features include:
- Data storage for expenses with fields: date, amount, category, and description.
- Ability to filter and search expenses by criteria (e.g., date range, category).
- A summary function to display total expenses by category and overall totals.

---

## Project Structure

```
Repo/
│
├── cpp/
│   ├── Expense.h
│   ├── ... (other C++ source files)
│   └── README.md  ← Contains C++-specific setup and run instructions.
│
└── python/
    ├── data/
    │   └── expense.json  ← Data file for storing expenses.
    └── src/
        ├── main.py       ← Main Python application.
        └── ... (other Python modules)
```

---

## Running the Python Application

No prerequisites are required to run the Python version.

1. **Open a Terminal**  
2. **Navigate to the Python Source Directory:**
   ```bash
   cd python/src
   ```
3. **Run the Application:**
   - For Python 3, execute:
     ```bash
     python main.py
     ```
     or
     ```bash
     python3 main.py
     ```
4. The application will load expense data from the `python/data/expense.json` file and run interactively.

---

## Running the C++ Application

For details on setting up a C++ environment (e.g., installing compilers, setting up VS Code, etc.) and running the C++ version of the application, please refer to the **README.md** file located in the `cpp/` folder.

---

## Additional Information

- **Python Version:** Uses Python's built-in data structures and JSON for persistence.  
- **C++ Version:** Demonstrates the use of STL containers, memory management, and structured programming with classes/structs.  
- Both implementations provide the same core functionality while highlighting language-specific features.

---

Feel free to explore each folder for further details on the respective implementations. Enjoy tracking your expenses!

