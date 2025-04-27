//yanivg1000@gmail.com
#include "square_mat.hpp"
#include <iostream>

using namespace Mat;

void printHeader(const std::string& title) {
    std::cout << "\n=== " << title << " ===\n";
}

int main() {
    SquareMat A(3), B(3), C(3);

    // Fill A
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;
    A[2][0] = 7; A[2][1] = 8; A[2][2] = 9;

    // Fill B
    B[0][0] = 9; B[0][1] = 8; B[0][2] = 7;
    B[1][0] = 6; B[1][1] = 5; B[1][2] = 4;
    B[2][0] = 3; B[2][1] = 2; B[2][2] = 1;

    C[0][0] = 6;  C[0][1] = 1;  C[0][2] = 1;
    C[1][0] = 4;  C[1][1] = -2; C[1][2] = 5;
    C[2][0] = 2;  C[2][1] = 8;  C[2][2] = 7;

    printHeader("Matrix A");
    std::cout << A;

    printHeader("Matrix B");
    std::cout << B;

    printHeader("Matrix C");
    std::cout << C;

    printHeader("A + B");
    std::cout << (A + B);

    printHeader("A - B");
    std::cout << (A - B);

    printHeader("Unary -A");
    std::cout << (-A);

    printHeader("A * B (Matrix multiplication)");
    std::cout << (A * B);

    printHeader("A * 2 (Scalar multiplication)");
    std::cout << (A * 2);

    printHeader("2 * A (Scalar multiplication - external operator)");
    std::cout << (2 * A);

    printHeader("A % B (Element-wise multiplication)");
    std::cout << (A % B);

    printHeader("A % 3 (Modulo each element by 3)");
    std::cout << (A % 3);

    printHeader("A / 2 (Scalar division)");
    std::cout << (A / 2.0);

    printHeader("A ^ 2 (Matrix raised to power 2)");
    SquareMat Apow2 = A ^ 2;
    std::cout << Apow2;

    printHeader("Prefix ++A");
    ++A;
    std::cout << A;

    printHeader("Postfix A++");
    SquareMat tmpA = A++;
    std::cout << "Before:\n" << tmpA << "After:\n" << A;

    printHeader("Prefix --A");
    --A;
    std::cout << A;

    printHeader("Postfix A--");
    tmpA = A--;
    std::cout << "Before:\n" << tmpA << "After:\n" << A;

    printHeader("Transpose of A (~A)");
    std::cout << (~A);

    printHeader("A == B?");
    std::cout << (A == B ? "True\n" : "False\n");

    printHeader("A != B?");
    std::cout << (A != B ? "True\n" : "False\n");

    printHeader("A < B?");
    std::cout << (A < B ? "True\n" : "False\n");

    printHeader("A > B?");
    std::cout << (A > B ? "True\n" : "False\n");

    printHeader("A <= B?");
    std::cout << (A <= B ? "True\n" : "False\n");

    printHeader("A >= B?");
    std::cout << (A >= B ? "True\n" : "False\n");

    printHeader("Determinant of A and C");
    std::cout << A.determinant() << "\n";
    std::cout << C.determinant() << "\n";

    printHeader("Operator += (A += B)");
    A += B;
    std::cout << A;

    printHeader("Operator -= (A -= B)");
    A -= B;
    std::cout << A;

    printHeader("Operator *= (A *= B)");
    A *= B;
    std::cout << A;

    printHeader("Operator /= (A /= 2)");
    A /= 2;
    std::cout << A;

    printHeader("Operator %= (A %= 5)");
    A %= 5;
    std::cout << A;

    return 0;
}
