
# Personal Finance Tracker

Course: 24B15CS111 – Software Development Fundamentals Lab-1

Shaurya Srivastava (Enrollment No: 2501200086)
Rohit Kalra (Enrollment No: 2501200084)
Course: B.Tech
Subject: C Programming
_________________________________________________________________________
## 1. Description of Project
The Personal Finance Tracker is a C-based console program designed to help users keep track of their income and expenses using simple input and calculations. The project demonstrates how arrays, pointers, and functions can be used together to handle and process financial data efficiently.
Through a simple menu-driven interface, the user can:
●	Add income and expense records
●	View total income, total expenses, and remaining balance
●	Display categorized expenses using strings (e.g., “Food”, “Rent”, “Transport”)
## 2. Objectives
1.	To track and categorize income and expenses efficiently.
2.	To calculate savings and generate financial summaries.
3.	To learn and implement concepts of C programming including arrays, pointers, functions, and file handling.
4.	To develop an efficient management system that helps hostel and PG students handle daily activities such as room allocation, fee payment, and maintenance requests digitally.

## 3. Software Requirement Specification(SRS)
a. Functional Requirements
●	The program should allow the user to input multiple income and expense entries.
●	It should display the total income, expenses, and savings balance.
●	It should categorize expenses using strings and arrays
b. Non-Functional Requirements
●	The interface should be simple and text-based.
●	The code should be well modularized using user-defined functions.
●	Input validation should ensure correct numeric and string inputs.
c. Software and Hardware Requirements
●	Language: C Programming
●	Compiler: GCC
●	Operating System: Windows or Linux or macOS
## 4. Explanation of Elements Used
a. Arrays (1D, 2D):
Arrays will store multiple income and expense values.
 For example:
float income[100], expense[100];
char category[100][30];
2D arrays of strings will hold transaction descriptions.
b. Functions:
Functions will divide the program into manageable parts:
void addIncome(float *incomes, int *count);
void addExpense(float *expenses, int *count);
float calculateTotal(float *arr, int count);
void displaySummary(float *incomes, float *expenses, int inCount, int exCount);
c. Pointers:
Pointers will be used to pass arrays and variables to functions by reference for direct modification.
 For example:
addIncome(income, &incomeCount);
d. Control Flow & Loops:
●	if-else and switch statements are used for decision-making (menu options).
●	for and while loops are used for repeatedly accepting or displaying data.



## 5. Control Flow
 


## 8. References
- Let Us C by Yashavant Kanetkar
- Online tutorials and documentation on C programming
- Sample projects for personal finance management

