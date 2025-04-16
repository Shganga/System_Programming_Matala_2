#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "square_mat.hpp"
#include <stdexcept>

using namespace Mat;

TEST_CASE("Constructor, Destructor and Sum") {
    SquareMat mat(3);
    CHECK(mat.sum() == 0);
}

TEST_CASE("Copy Constructor and Assignment Operator") {
    SquareMat mat1(3);
    mat1[0][0] = 1;
    mat1[1][1] = 2;
    mat1[2][2] = 3;

    SquareMat mat2 = mat1;
    CHECK(mat2[1][1] == 2);

    SquareMat mat3(3);
    mat3 = mat1;
    CHECK(mat3[2][2] == 3);
}

TEST_CASE("Addition, Subtraction and Assignment Operators") {
    SquareMat mat1(3), mat2(3);
    mat1[0][0] = 1; mat1[1][1] = 2; mat1[2][2] = 3;
    mat2[0][0] = 4; mat2[1][1] = 5; mat2[2][2] = 6;

    SquareMat sum = mat1 + mat2;
    SquareMat diff = mat1 - mat2;
    mat1 += mat2;
    mat2 -= mat2;

    CHECK(sum[0][0] == 5);
    CHECK(diff[1][1] == -3);
    CHECK(mat1[2][2] == 9);
    CHECK(mat2.sum() == 0);
}

TEST_CASE("Negation and Scalar Operations") {
    SquareMat mat(3);
    mat[0][0] = 1; mat[0][1] = 2; mat[0][2] = 3;
    mat[1][0] = 4; mat[1][1] = 5; mat[1][2] = 6;
    mat[2][0] = 7; mat[2][1] = 8; mat[2][2] = 9;

    SquareMat neg = -mat;
    CHECK(neg[0][0] == -1);

    SquareMat mul = mat * 2;
    CHECK(mul[2][2] == 18);

    SquareMat mul2 = 3 * mat;
    CHECK(mul2[0][1] == 6);

    SquareMat div = mat / 2;
    CHECK(div[1][1] == 2.5);

    mat /= 2;
    CHECK(mat[0][0] == 0.5);
}

TEST_CASE("Matrix Multiplication and Power") {
    SquareMat mat(3);
    mat[0][0] = 2; mat[0][1] = 0; mat[0][2] = 1;
    mat[1][0] = 3; mat[1][1] = 0; mat[1][2] = 0;
    mat[2][0] = 5; mat[2][1] = 1; mat[2][2] = 1;

    SquareMat result = mat * mat;
    CHECK(result[0][0] == 9);

    SquareMat power = mat ^ 2;
    CHECK(power[1][0] == 6);

    mat *= mat;
    CHECK(mat[0][0] == 9);
}

TEST_CASE("Modulo and Assignment Modulo") {
    SquareMat mat(3);
    mat[0][0] = 10; mat[0][1] = 15; mat[0][2] = 20;
    mat[1][0] = 25; mat[1][1] = 30; mat[1][2] = 35;
    mat[2][0] = 40; mat[2][1] = 45; mat[2][2] = 50;

    SquareMat mod = mat % 6;
    CHECK(mod[0][0] == 4);

    mat %= 10;
    CHECK(mat[2][2] == 0);
}

TEST_CASE("Hadamard Product") {
    SquareMat mat1(3), mat2(3);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            mat1[i][j] = i + j + 1;
            mat2[i][j] = (i + 1) * (j + 1);
        }

    SquareMat hadamard = mat1 % mat2;
    CHECK(hadamard[2][2] == (2 + 2 + 1) * 9);
}

TEST_CASE("Transpose") {
    SquareMat mat(3);
    mat[0][1] = 2; mat[1][2] = 3;

    SquareMat trans = ~mat;
    CHECK(trans[1][0] == 2);
    CHECK(trans[2][1] == 3);
}

TEST_CASE("Comparison Operators") {
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

TEST_CASE("Increment and Decrement Operators") {
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

TEST_CASE("Indexing operator []") {
    SquareMat mat(3);
    mat[1][2] = 42.0;
    CHECK(mat[1][2] == 42.0);
}

TEST_CASE("Determinant") {
    SquareMat mat(3);
    mat[0][0] = 6; mat[0][1] = 1; mat[0][2] = 1;
    mat[1][0] = 4; mat[1][1] = -2; mat[1][2] = 5;
    mat[2][0] = 2; mat[2][1] = 8; mat[2][2] = 7;

    CHECK(mat.determinant() == -306);
}

TEST_CASE("Output Stream Operator") {
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
