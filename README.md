Financial Calculator (Mini Project in C)

Author
Nivindharan A 
Department of Computer Science and Engineering

🧾 Project Overview
This Financial Calculator is a simple console-based C program designed to help users plan and analyze their personal finances. 
It allows users to:
- Split income into savings and expenses
- Plan investments in different asset classes (Mutual Funds, Gold, Equity, US Stocks)
- Calculate Future Value (Lump Sum) returns
- Calculate SIP (Systematic Investment Plan) returns with Future Value computation

This project demonstrates fundamental C programming concepts like:
- Conditional statements (if–else, switch)
- User-defined functions
- Function declaration and call
- Global variables
- Loops and input/output
- Mathematical calculations using math.h

⚙️ Features
 Financial Planner – Automatically divides income into savings and expenses
 Custom Allocation – Allocate savings into multiple investments
 Lump Sum Calculator – Predicts future returns on one-time investments
 SIP Calculator – Calculates total future value and profit based on monthly investments
 User-Friendly Interface – Menu-driven program with clear instructions
 Educational Purpose – Best suited for beginner-level CSE students

🧩 Technical Details
Language: C
Compiler: Turbo C / GCC
Libraries Used:
- stdio.h – for input/output
- math.h – for power and financial calculations

🧠 Learning Outcomes
From this project, you will learn:
- How to structure a C program using multiple functions
- How to implement mathematical formulas (Future Value, SIP formula)
- How to use modular programming and switch-case logic
- How to handle user input validation
- How to make console-based interactive programs

📈 Formulae Used
1️⃣ Future Value (Lump Sum):
FV = P × (1 + r)^t

where
- P = Principal amount
- r = Annual rate of return
- t = Time (in years)

2️⃣ SIP Future Value:
FV = P × ((1 + r)^n - 1) / r × (1 + r)

where
- P = Monthly investment
- r = Monthly rate of return (annual rate ÷ 12)
- n = Total months (years × 12)

🧮 Example Output
========== FINANCIAL CALCULATOR ==========
1. Financial Plan
2. Future Value (Lump Sum)
3. SIP Calculator
==========================================
Enter your choice: 3

===== SIP CALCULATOR =====
Enter monthly investment (Rs):
Mutual Funds: 1000
Gold: 500
Equity: 1000
US Stocks: 500
Enter number of years: 5
...
TOTAL INVESTMENT : Rs 150000
TOTAL FUTURE VALUE: Rs 210256
TOTAL PROFIT      : Rs 60256
