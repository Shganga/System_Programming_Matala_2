# Square Matrix Project

Email: yanivg1000@gmail.com

## Overview
This project implements a fully functional SquareMat class for square matrices of doubles, supporting a wide range of matrix operations.
The matrices are dynamically allocated, and the class manages all memory safely.

## Features

### Matrix Creation and Management
- Dynamic allocation and deallocation of square matrices
- Copy constructor and assignment operator for deep copies

### Arithmetic Operators
- Addition and subtraction of two matrices (+, -)
- Scalar multiplication and division (*, /)
- Matrix multiplication (*)
- Hadamard (element-wise) product (% with another matrix)
- Modulo operation for each element (% with scalar)

### Unary Operators
- Unary minus (-mat) to negate all elements
- Transpose of the matrix (~mat)
- Increment and decrement operators (++, --) in both prefix and postfix forms

### Power and Exponentiation
- Raise a matrix to an integer non-negative power (mat^n)

### Comparison Operators
- Equality (==) and inequality (!=)
- Greater than, less than, and their inclusive versions (>, <, >=, <=)
- Comparisons are based on the sum of all elements in the matrices

### Access and Indexing
- Element access via mat[i][j] notation with bounds checking

### Other Functionality
- Calculation of the matrix determinant recursively
- Stream output (<<) to print the matrix in a readable format

## Project Structure
- src/: Contains the source code and class implementation.
- tests/: Contains unit tests using the Doctest framework.
- Makefile: Script to build the project easily.

## How to Build and Run

To build the project:
```bash
make Main
```

To run the program:
```bash
./main
```

To make the tests:
```bash
make test
```

To run the tests:
```bash
./test_square_mat
```

To make and run valgrind:
```bash
make valgrind
```