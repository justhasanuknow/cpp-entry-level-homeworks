# Simple Bank Account Management System

A basic C++ program designed to manage bank accounts, allowing users to create accounts, perform money transfers, and maintain a permanent transaction log using file operations.

## Table of Contents

- [Overview](#overview)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Example Output](#example-output)
- [Explanation](#explanation)
- [License](#license)

## Overview

This application serves as a fundamental banking management system, supporting account creation with an initial balance, money transfers between accounts, and permanent transaction logging through file operations.

## Requirements

- C++ compiler (e.g., GCC, Clang)
- Knowledge of dynamic memory allocation (pointers, dynamic arrays)
- Familiarity with file handling (`fstream`)

## Installation

Compile the provided `main.cpp` using your preferred C++ compiler:

```bash
g++ -o bank_system main.cpp
```

Run the compiled program:

```bash
./bank_system
```

## Usage

- Run the program and follow prompts to create user accounts.
- Perform account operations such as deposits, withdrawals, and transfers.
- Transactions will be automatically recorded in a `.txt` file.

## Example Output

```
Welcome to Simple Bank Management System

1. Create Account
2. Transfer Money
3. View Account Transactions
4. Exit
Choose an option: 1

Enter account holder's name: John Doe
Enter initial balance: 1000

Account successfully created!

Choose an option: 2
From (account holder's name): John Doe
To (account holder's name): Jane Smith
Enter amount to transfer: 250

Transfer successful!

Choose an option: 3
Enter account holder's name: John Doe

Transactions for John Doe:
- Created account with initial balance: 1000
- Transferred 250 to Jane Smith
- Current balance: 750
```

## Explanation

The program performs the following:

1. Allows users to create new bank accounts with an initial balance.
2. Facilitates secure transfers between accounts.
3. Manages account information dynamically (pointers, dynamic memory).
4. Logs all account activities permanently to a text file using the `fstream` library.
5. Provides a user-friendly console-based interface.

## License

This project is provided under the MIT License.
