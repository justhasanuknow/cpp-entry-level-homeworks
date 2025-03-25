# Movie Database

A simple C++ program that lets users store movies along with their ratings, display the stored movies, calculate average ratings, and highlight movies with the highest and lowest scores.

## Table of Contents

- [Overview](#overview)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Example Output](#example-output)
- [Explanation](#explanation)
- [License](#license)

## Overview

The program serves as a simple movie database that allows users to input movie titles and ratings, list them, calculate average ratings, and identify movies with the highest and lowest ratings.

## Requirements

- C++ compiler (e.g., GCC, Clang)
- Familiarity with `std::vector`, structures (`struct`), and algorithms from `<algorithm>`

## Installation

Compile the provided `main.cpp` using your preferred C++ compiler:

```bash
g++ -o movie_database main.cpp
```

Run the compiled program:

```bash
./movie_database
```

## Usage

- Run the program and input movie titles and ratings as prompted.
- The program will then list all movies, calculate the average rating, and display the highest and lowest-rated movies.

## Example Output

```
How many movies do you want to add? 3

Enter title of movie 1: Inception
Enter rating of movie 1 (0-10): 9

Enter title of movie 2: Interstellar
Enter rating of movie 2 (0-10): 8

Enter title of movie 3: Tenet
Enter rating of movie 3 (0-10): 7

Movies Entered:
1. Inception - Rating: 9
2. Interstellar - Rating: 8
3. Tenet - Rating: 7

Average rating: 8.00
Highest-rated movie: Inception (9)
Lowest-rated movie: Tenet (7)
```

## Explanation

The program performs the following steps:

1. Prompts the user to specify the number of movies to store.
2. Dynamically stores movies and their ratings using `std::vector` and a custom `struct`.
3. Lists all entered movies.
4. Calculates and displays the average rating.
5. Determines and outputs the movies with the highest and lowest ratings using `<algorithm>` library functions.

## License

This project is provided under the MIT License.
