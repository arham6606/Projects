#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions.h"

TEST_CASE("Test Default Constructor")
{
    Matrix m;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            REQUIRE(m.getElement(i, j) == 0);
}

TEST_CASE("Test Parameterized Constructor and GetElement")
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix m(arr);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            REQUIRE(m.getElement(i, j) == arr[i][j]);
}

TEST_CASE("Test Copy Constructor")
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix m1(arr);
    Matrix m2(m1);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            REQUIRE(m2.getElement(i, j) == arr[i][j]);
}

TEST_CASE("Test SetElement")
{
    Matrix m;
    m.setElement(1, 1, 10);
    REQUIRE(m.getElement(1, 1) == 10);
}
TEST_CASE("Test Addition Operator Overloading")
{
    int arr1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    Matrix m1(arr1), m2(arr2), result;

    result = m1 + m2;

    int expected[3][3] = {{10, 10, 10}, {10, 10, 10}, {10, 10, 10}};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            REQUIRE(result.getElement(i, j) == expected[i][j]);
}

TEST_CASE("Test Subtraction Operator Overloading")
{
    int arr1[3][3] = {{5, 5, 5}, {5, 5, 5}, {5, 5, 5}};
    int arr2[3][3] = {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}};
    Matrix m1(arr1), m2(arr2), result;

    result = m1 - m2;

    int expected[3][3] = {{3, 3, 3}, {3, 3, 3}, {3, 3, 3}};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            REQUIRE(result.getElement(i, j) == expected[i][j]);
}

TEST_CASE("Test Multiplication Operator Overloading")
{
    int arr1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    Matrix m1(arr1), m2(arr2), result;

    result = m1 * m2;

    int expected[3][3] = {{30, 24, 18}, {84, 69, 54}, {138, 114, 90}};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            REQUIRE(result.getElement(i, j) == expected[i][j]);
}

TEST_CASE("Test Equality and Inequality Operators")
{
    int arr1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr3[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    Matrix m1(arr1), m2(arr2), m3(arr3);

    REQUIRE(m1 == m2);
    REQUIRE_FALSE(m1 != m2);
    REQUIRE(m1 != m3);
}

TEST_CASE("Test < and > Operators")
{
    int arr1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr2[3][3] = {{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};

    Matrix m1(arr1), m2(arr2);

    REQUIRE(m1 < m2);
    REQUIRE_FALSE(m1 > m2);
}

TEST_CASE("Test Unary Minus Operator")
{
    int arr[3][3] = {{1, -2, 3}, {-4, 5, -6}, {7, -8, 9}};
    Matrix m(arr), result;

    result = -m;

    int expected[3][3] = {{-1, 2, -3}, {4, -5, 6}, {-7, 8, -9}};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            REQUIRE(result.getElement(i, j) == expected[i][j]);
}

TEST_CASE("Test Pre-Increment Operator")
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix m(arr);

    ++m;

    int expected[3][3] = {{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            REQUIRE(m.getElement(i, j) == expected[i][j]);
}

TEST_CASE("Test Assignment Operator")
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix m1(arr), m2;

    m2 = m1;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            REQUIRE(m2.getElement(i, j) == arr[i][j]);
}

TEST_CASE("Test Input and Output Operators") {
    std::stringstream ss;
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix m(arr);

    ss << m;
    std::string expectedOutput = "1 2 3 \n4 5 6 \n7 8 9 \n";

    REQUIRE(ss.str() == expectedOutput);
}

