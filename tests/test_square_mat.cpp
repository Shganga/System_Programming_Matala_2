#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "square_mat.hpp"
#include <stdexcept>
#include <sstream>

using namespace Mat;

TEST_CASE("Constructor initializes with zeros and sum is zero") {
    SquareMat mat(3);
    CHECK(mat.sum() == 0);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            CHECK(mat[i][j] == 0);
}

TEST_CASE("Copy constructor and assignment operator copy values correctly") {
    SquareMat mat1(3);
    mat1[0][0] = 1;
    mat1[1][1] = 2;
    mat1[2][2] = 3;

    SquareMat mat2 = mat1;
    for (int i = 0; i < 3; ++i)
        CHECK(mat2[i][i] == mat1[i][i]);

    SquareMat mat3(3);
    mat3 = mat1;
    for (int i = 0; i < 3; ++i)
        CHECK(mat3[i][i] == mat1[i][i]);
}

TEST_CASE("Addition, subtraction and compound assignment work correctly") {
    SquareMat mat1(3), mat2(3);
    mat1[0][0] = 1; mat1[1][1] = 2; mat1[2][2] = 3;
    mat2[0][0] = 4; mat2[1][1] = 5; mat2[2][2] = 6;

    SquareMat sum = mat1 + mat2;
    SquareMat diff = mat1 - mat2;
    mat1 += mat2;
    mat2 -= mat2;

    CHECK(sum[0][0] == 5);
    CHECK(sum[1][1] == 7);
    CHECK(sum[2][2] == 9);

    CHECK(diff[0][0] == -3);
    CHECK(diff[1][1] == -3);
    CHECK(diff[2][2] == -3);

    CHECK(mat1[2][2] == 9);
    CHECK(mat2.sum() == 0);
}

TEST_CASE("Negation and scalar multiplication/division work correctly") {
    SquareMat mat(3);
    double val = 1;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            mat[i][j] = val++;

    SquareMat neg = -mat;
    CHECK(neg[0][0] == -1);
    CHECK(neg[2][2] == -9);

    SquareMat mul = mat * 2;
    CHECK(mul[0][0] == 2);
    CHECK(mul[2][2] == 18);

    SquareMat mul2 = 3 * mat;
    CHECK(mul2[0][1] == 6);
    CHECK(mul2[2][0] == 21);

    SquareMat div = mat / 2;
    CHECK(div[1][1] == 2.5);

    mat /= 2;
    CHECK(mat[0][0] == 0.5);
    CHECK(mat[2][2] == 4.5);
}

TEST_CASE("Matrix multiplication and power") {
    SquareMat mat(3);
    mat[0][0] = 2; mat[0][1] = 0; mat[0][2] = 1;
    mat[1][0] = 3; mat[1][1] = 0; mat[1][2] = 0;
    mat[2][0] = 5; mat[2][1] = 1; mat[2][2] = 1;

    SquareMat product = mat * mat;
    CHECK(product[0][0] == 9);
    CHECK(product[1][0] == 6);
    CHECK(product[2][0] == 18);

    SquareMat power = mat ^ 2;
    CHECK(power[0][0] == 9);
    CHECK(power[1][0] == 6);

    mat *= mat;
    CHECK(mat[0][0] == 9);
    CHECK(mat[1][0] == 6);
}

TEST_CASE("Modulo and Hadamard Product") {
    SquareMat mat(3);
    mat[0][0] = 10; mat[0][1] = 15; mat[0][2] = 20;
    mat[1][0] = 25; mat[1][1] = 30; mat[1][2] = 35;
    mat[2][0] = 40; mat[2][1] = 45; mat[2][2] = 50;

    SquareMat mod = mat % 6;
    CHECK(mod[0][0] == 4);
    CHECK(mod[1][1] == 0);
    CHECK(mod[2][2] == 2);

    mat %= 10;
    CHECK(mat[0][0] == 0);
    CHECK(mat[1][1] == 0);
    CHECK(mat[2][2] == 0);

    SquareMat m1(3), m2(3);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            m1[i][j] = i + j + 1;
            m2[i][j] = (i + 1) * (j + 1);
        }

    SquareMat hadamard = m1 % m2;
    CHECK(hadamard[2][2] == (2 + 2 + 1) * 9);
}

TEST_CASE("Transpose swaps rows and columns") {
    SquareMat mat(3);
    mat[0][1] = 2;
    mat[1][2] = 3;
    mat[2][0] = 4;

    SquareMat trans = ~mat;

    CHECK(trans[1][0] == 2);
    CHECK(trans[2][1] == 3);
    CHECK(trans[0][2] == 4);
}

TEST_CASE("Comparison operators") {
    SquareMat mat1(3), mat2(3), mat3(3);
    mat1[0][0] = 1;
    mat2[0][0] = 1;
    mat3[0][0] = 10;

    CHECK(mat1 == mat2);
    CHECK(mat1 != mat3);
    CHECK(mat1 < mat3);
    CHECK(mat3 > mat2);
    CHECK(mat1 <= mat2);
    CHECK(mat3 >= mat1);
}

TEST_CASE("Increment and decrement operators") {
    SquareMat mat(3);
    mat[0][0] = 1;

    SquareMat pre = ++mat;
    CHECK(pre[0][0] == 2);

    SquareMat post = mat++;
    CHECK(post[0][0] == 2);
    CHECK(mat[0][0] == 3);

    SquareMat preDec = --mat;
    CHECK(preDec[0][0] == 2);

    SquareMat postDec = mat--;
    CHECK(postDec[0][0] == 2);
    CHECK(mat[0][0] == 1);
}

TEST_CASE("Indexing operator [] gives access to elements") {
    SquareMat mat(3);
    mat[1][2] = 42.0;
    CHECK(mat[1][2] == 42.0);
}

TEST_CASE("Determinant of a known 3x3 matrix") {
    SquareMat mat(3);
    mat[0][0] = 6; mat[0][1] = 1; mat[0][2] = 1;
    mat[1][0] = 4; mat[1][1] = -2; mat[1][2] = 5;
    mat[2][0] = 2; mat[2][1] = 8; mat[2][2] = 7;

    CHECK(mat.determinant() == -306);
}

TEST_CASE("Output stream operator produces expected output") {
    SquareMat mat(3);
    mat[0][0] = 1; mat[0][1] = 2; mat[0][2] = 3;
    mat[1][0] = 4; mat[1][1] = 5; mat[1][2] = 6;
    mat[2][0] = 7; mat[2][1] = 8; mat[2][2] = 9;

    std::ostringstream oss;
    oss << mat;
    std::string out = oss.str();

    CHECK(out.find("1") != std::string::npos);
    CHECK(out.find("9") != std::string::npos);
}
