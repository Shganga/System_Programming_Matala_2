#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

#include <iostream>

namespace Mat {

class SquareMat {
private:
    int size;
    double** data;

    void allocate();
    void deallocate();
    void copyDataFrom(const SquareMat& other);

public:
    SquareMat(int n);
    ~SquareMat();
    SquareMat(const SquareMat& other);
    SquareMat& operator=(const SquareMat& other);

    SquareMat operator+(const SquareMat& other) const;
    SquareMat operator-(const SquareMat& other) const;
    SquareMat operator-() const;
    SquareMat operator*(const SquareMat& other) const;
    SquareMat operator*(double scalar) const;
    friend SquareMat operator*(double scalar, const SquareMat& mat);
    SquareMat operator%(const SquareMat& other) const;
    SquareMat operator%(int scalar) const;
    SquareMat operator/(double scalar) const;
    SquareMat operator^(int power) const;
    SquareMat& operator++();
    SquareMat operator++(int);
    SquareMat& operator--();
    SquareMat operator--(int);
    SquareMat operator~() const;

    double* operator[](int index);

    bool operator==(const SquareMat& other) const;
    bool operator!=(const SquareMat& other) const;
    bool operator<(const SquareMat& other) const;
    bool operator>(const SquareMat& other) const;
    bool operator<=(const SquareMat& other) const;
    bool operator>=(const SquareMat& other) const;

    double determinant() const;

    SquareMat& operator+=(const SquareMat& other);
    SquareMat& operator-=(const SquareMat& other);
    SquareMat& operator*=(const SquareMat& other);
    SquareMat& operator/=(double scalar);
    SquareMat& operator%=(int scalar);

    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);

    double sum() const;
};
}

#endif // SQUAREMAT_HPP
