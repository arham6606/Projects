#include <iostream>
using namespace std;
#include <string>
// header files

// creating a class of matrix
class Matrix
{
private:
    // data properties
    int mat[3][3];

public:
    // default constructor
    Matrix()
    {
        // using nested loops to set zero to each element at the given position
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                mat[i][j] = 0;
            }
        }
    }

    // parameterized constructor
    Matrix(int arr[3][3])
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                mat[i][j] = arr[i][j];
            }
        }
    }

    // copy constructor
    Matrix(const Matrix &other)
    {
        // copying each element
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                mat[i][j] = other.mat[i][j];
            }
        }
    }

    // member functions
    void setElement(int row, int col, int value)
    {
        // setting the element
        mat[row][col] = value;
    }

    // member funtions
    int getElement(int row, int col) const
    {
        // returning the elememt
        return mat[row][col];
    }

    // overloaded function + operator
    Matrix operator+(const Matrix &m) const
    {
        Matrix result;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                result.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return result;
    }

    // overloaded function - operator
    Matrix operator-(const Matrix &m) const
    {
        Matrix result;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                result.mat[i][j] = mat[i][j] - m.mat[i][j];
            }
        }
        return result;
    }

    // overloaded function * operator
    Matrix operator*(const Matrix &m) const
    {
        Matrix result;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    result.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return result;
    }

    // overloaded function == operator
    bool operator==(const Matrix &m) const
    {
        int a = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (mat[i][j] == m.mat[i][j])
                {
                    a++;
                }
            }
        }

        if (a == 9)
        {
            return true;
        }
        return false;
    }

    // overloaded function != operator
    bool operator!=(const Matrix &m) const
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (mat[i][j] != m.mat[i][j])
                {
                    return true;
                }
            }
        }
        return false;
    }

    // overloaded funciton < operator
    bool operator<(const Matrix &m) const
    {
        int matrix1 = 0;
        int matrix2 = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrix1 += mat[i][j];
                matrix2 += m.mat[i][j];
            }
        }

        if (matrix1 < matrix2)
        {
            return true;
        }
        return false;
    }

    // overloaded funciton > operator
    bool operator>(const Matrix &m) const
    {
        int matrix1 = 0;
        int matrix2 = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrix1 += mat[i][j];
                matrix2 += m.mat[i][j];
            }
        }

        if (matrix1 > matrix2)
        {
            return true;
        }
        return false;
    }

    // overloaded funciton - operator
    Matrix operator-() const
    {
        Matrix result;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                result.mat[i][j] = -(mat[i][j]);
            }
        }
        return result;
    }

    // overloaded function ++ operator
    Matrix &operator++()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                mat[i][j] += 1;
            }
        }
        return *this;
    }

    // overloaded funciton = operator
    Matrix &operator=(const Matrix &m)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                mat[i][j] = m.mat[i][j];
            }
        }
        return *this;
    }

    // friend function decalration
    friend istream &operator>>(std::istream &in, Matrix &m);
    friend ostream &operator<<(std::ostream &out, const Matrix &m);

    // destructor
    ~Matrix()
    {
        // cout << "Destructor Called" << endl;
    }
};

// function declaration
void enterMatrix(Matrix &dis);
void displayMatrix(const Matrix &dis);