# C++ Assignments (Pre-OOP Level)

This repository contains programming assignments categorized into three difficulty levels to help you practice and master fundamental concepts of C++ before diving into Object-Oriented Programming (OOP).

---

## 🟢 Easy Level: Student Grade Calculator

**Objective:**  
Create a program that calculates the average grade based on user-inputted student scores and displays the number of students above and below the average.

### Tasks

- Prompt the user to input the number of students.
- Use dynamic memory allocation (`new`, `delete`) to store students' grades.
- Calculate the average and display how many students scored above and below it.

### 📌 Important

- Ensure proper memory management to avoid memory leaks.
- Design user-friendly input/output messages.

---

## 🟡 Medium Level: Movie Database

**Objective:**  
Create a simple database to store movies along with their ratings, provided by the user.

### Features

- Define a `struct` to store movie information (title and rating).
- Use `std::vector` to dynamically store movie data.
- Allow users to enter movie titles and ratings.
- Display all stored movies.
- Calculate and show the average rating.
- Identify and display movies with the highest and lowest ratings.

### 📌 Tips

- Utilize `std::vector` and functions from the `<algorithm>` library for efficiency.

---

## 🟠 Hard Level: Simple Bank Account Management System

**Objective:**  
Develop a simple bank account management system.

### Features

- Allow users to open accounts with initial balances.
- Enable money transfers between user accounts.
- Dynamically manage user data (use pointers and dynamic memory).
- Log all transactions to a `.txt` file and read from it.

### 📌 Important

- Permanently store account information using file operations (`fstream`).
- Carefully manage pointers and dynamic memory allocation.
- Provide a simple, intuitive console-based user interface.

---
