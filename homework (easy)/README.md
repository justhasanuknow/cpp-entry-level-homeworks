# Student Grade Calculator

A simple C++ program to calculate the average of student grades and determine how many students scored above and below the average.

## Table of Contents

- [Overview](#overview)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Example Output](#example-output)
- [Explanation](#explanation)
- [License](#license)

## Overview

This project aims to take user input for the number of students and their corresponding grades, calculate the class average, and display how many students have scored above or below the average.

## Requirements

- C++ compiler (e.g., GCC, Clang)
- Basic knowledge of dynamic memory management (`new`, `delete`)

## Installation

Compile the provided `main.cpp` using your preferred C++ compiler:

```bash
g++ -o grade_calculator main.cpp
```

Run the compiled program:

```bash
./grade_calculator
```

## Usage

- Run the program and input the number of students when prompted.
- Enter each student's grade individually.

## Example Output

```
Enter the number of students: 5
Enter grade for student 1: 70
Enter grade for student 2: 85
Enter grade for student 3: 90
Enter grade for student 4: 60
Enter grade for student 5: 75

Average grade: 76
Students above average: 2
Students below average: 3
```

## Explanation

The program performs the following steps:

1. Asks the user to enter the number of students.
2. Dynamically allocates memory to store grades using `new`.
3. Calculates the average grade.
4. Counts and displays how many students scored above and below the average.
5. Ensures memory is properly freed using `delete` to avoid memory leaks.

## License

This project is provided under the MIT License.
