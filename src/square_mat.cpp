#include "square_mat.hpp"
#include <stdexcept>
#include <iostream>

namespace Mat{

void SquareMat::allocate() {
    data = new double*[size];  // Allocate memory for rows
    for (int i = 0; i < size; ++i) {
        data[i] = new double[size];  // Allocate memory for columns
    }
}

void SquareMat::deallocate() {
    for (int i = 0; i < size; ++i) {
        delete[] data[i];  // Deallocate each row
    }
    delete[] data;  // Deallocate the array of rows
}

void SquareMat::copyDataFrom(const SquareMat& other) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = other.data[i][j];  // Copy element-wise
        }
    }
}

SquareMat::SquareMat(int n) {
    size = n;
    allocate();
    // Optionally initialize the matrix with specific values (like zeros)
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = 0.0;  // Initialize all elements to 0
        }
    }
}



SquareMat::~SquareMat() {
    deallocate();
}

SquareMat::SquareMat(const SquareMat& other) : size(other.size) {
    allocate();
    copyDataFrom(other);
}

SquareMat& SquareMat::operator=(const SquareMat& other) {
    if (this != &other) {
        deallocate();
        size = other.size;
        allocate();
        copyDataFrom(other);
    }
    return *this;
}

SquareMat SquareMat::operator+(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrix sizes must match for addition.");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

SquareMat SquareMat::operator-(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrix sizes must match for subtraction.");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

SquareMat SquareMat::operator-() const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = -data[i][j];
        }
    }
    return result;
}

SquareMat SquareMat::operator*(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrix sizes must match for multiplication.");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

SquareMat SquareMat::operator*(double scalar) const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

SquareMat operator*(double scalar, const SquareMat& mat) {
    return mat * scalar;
}

SquareMat SquareMat::operator%(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrix sizes must match for element-wise multiplication.");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] * other.data[i][j];
        }
    }
    return result;
}

SquareMat SquareMat::operator%(int scalar) const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = static_cast<int>(data[i][j]) % scalar;
        }
    }
    return result;
}

SquareMat SquareMat::operator/(double scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Cannot divide by zero.");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] / scalar;
        }
    }
    return result;
}

SquareMat SquareMat::operator^(int power) const {
    if (power < 0) {
        throw std::invalid_argument("Exponent must be non-negative.");
    }
    SquareMat result = *this;
    for (int i = 1; i < power; ++i) {
        result = result * *this;
    }
    return result;
}

SquareMat& SquareMat::operator++() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            ++data[i][j];
        }
    }
    return *this;
}

SquareMat SquareMat::operator++(int) {
    SquareMat temp = *this;
    ++(*this);
    return temp;
}

SquareMat& SquareMat::operator--() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            --data[i][j];
        }
    }
    return *this;
}

SquareMat SquareMat::operator--(int) {
    SquareMat temp = *this;
    --(*this);
    return temp;
}

SquareMat SquareMat::operator~() const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[j][i];  // Transpose the matrix
        }
    }
    return result;
}

double* SquareMat::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds.");
    }
    return data[index];
}

bool SquareMat::operator==(const SquareMat& other) const {
    if (size != other.size) {
        return false;
    }
    return sum() == other.sum();
}

bool SquareMat::operator!=(const SquareMat& other) const {
    return !(*this == other);
}

bool SquareMat::operator<(const SquareMat& other) const {
    return sum() < other.sum();
}

bool SquareMat::operator>(const SquareMat& other) const {
    return sum() > other.sum();
}

bool SquareMat::operator<=(const SquareMat& other) const {
    return sum() <= other.sum();
}

bool SquareMat::operator>=(const SquareMat& other) const {
    return sum() >= other.sum();
}

double SquareMat::sum() const {
    double total = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            total += data[i][j];
        }
    }
    return total;
}

double SquareMat::determinant() const {
    if (size == 1) {
        return data[0][0];
    }

    double det = 0;
    for (int p = 0; p < size; ++p) {
        SquareMat subMat(size - 1);  // Submatrix for cofactor expansion
        for (int i = 1; i < size; ++i) {
            int subMatCol = 0;
            for (int j = 0; j < size; ++j) {
                if (j == p) continue;
                subMat.data[i - 1][subMatCol] = data[i][j];
                ++subMatCol;
            }
        }
        det += (p % 2 == 0 ? 1 : -1) * data[0][p] * subMat.determinant();  // Cofactor expansion
    }
    return det;
}


SquareMat& SquareMat::operator+=(const SquareMat& other) {
    *this = *this + other;
    return *this;
}

SquareMat& SquareMat::operator-=(const SquareMat& other) {
    *this = *this - other;
    return *this;
}

SquareMat& SquareMat::operator*=(const SquareMat& other) {
    *this = *this * other;
    return *this;
}

SquareMat& SquareMat::operator/=(double scalar) {
    *this = *this / scalar;
    return *this;
}

SquareMat& SquareMat::operator%=(int scalar) {
    *this = *this % scalar;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
    for (int i = 0; i < mat.size; ++i) {
        for (int j = 0; j < mat.size; ++j) {
            os << mat.data[i][j] << " ";  // Print each element followed by a space
        }
        os << std::endl;  // Move to the next line after printing a row
    }
    return os;
}
}
