#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

#include <iostream>

namespace Mat{

class SquareMat {
private:
    int size;  // The size of the matrix (it's square)
    double** data;  // 2D array to store matrix elements

    void allocate();  // Allocate memory for the matrix
    void deallocate();  // Deallocate memory for the matrix
    void copyDataFrom(const SquareMat& other);  // Helper function to copy data

public:
    // Constructor and Destructor
    SquareMat(int n);  // Constructor
    ~SquareMat();  // Destructor
    SquareMat(const SquareMat& other);  // Copy Constructor
    SquareMat& operator=(const SquareMat& other);  // Copy Assignment Operator

    // Operators
    SquareMat operator+(const SquareMat& other) const;  // Addition
    SquareMat operator-(const SquareMat& other) const;  // Subtraction
    SquareMat operator-() const;  // Unary minus (negate all elements)
    SquareMat operator*(const SquareMat& other) const;  // Matrix multiplication
    SquareMat operator*(double scalar) const;  // Scalar multiplication
    friend SquareMat operator*(double scalar, const SquareMat& mat);  // Scalar multiplication (commutative)
    SquareMat operator%(const SquareMat& other) const;  // Element-wise multiplication (Hadamard product)
    SquareMat operator%(int scalar) const;  // Element-wise modulo with a scalar
    SquareMat operator/(double scalar) const;  // Scalar division
    SquareMat operator^(int power) const;  // Matrix exponentiation
    SquareMat& operator++();  // Pre-increment
    SquareMat operator++(int);  // Post-increment
    SquareMat& operator--();  // Pre-decrement
    SquareMat operator--(int);  // Post-decrement
    SquareMat operator~() const;  // Transpose

    // Indexing operator
    double* operator[](int index);  // Accessing row

    // Comparison operators
    bool operator==(const SquareMat& other) const;  // Equality
    bool operator!=(const SquareMat& other) const;  // Inequality
    bool operator<(const SquareMat& other) const;  // Less than (based on sum of elements)
    bool operator>(const SquareMat& other) const;  // Greater than (based on sum of elements)
    bool operator<=(const SquareMat& other) const;  // Less than or equal to
    bool operator>=(const SquareMat& other) const;  // Greater than or equal to

    // Determinant
    double determinant() const;

    // Assignment operators
    SquareMat& operator+=(const SquareMat& other);  // Addition assignment
    SquareMat& operator-=(const SquareMat& other);  // Subtraction assignment
    SquareMat& operator*=(const SquareMat& other);  // Multiplication assignment
    SquareMat& operator/=(double scalar);  // Division assignment
    SquareMat& operator%=(int scalar);  // Modulo assignment

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);

    // Helper function to sum the elements of the matrix
    double sum() const;
};
}

#endif // SQUAREMAT_HPP
