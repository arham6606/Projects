#include "functions.h"

// using this to display matrix
void displayMatrix(const Matrix &dis)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << dis.getElement(i, j) << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

// setting the values in the matrix by user inputting
void enterMatrix(Matrix &dis)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int value;
            cout << "Enter the Value at the position" << i + 1 << "x" << j + 1 << ": ";
            cin >> value;
            dis.setElement(i, j, value);
        }
    }
}

// inputting the matrix
istream &operator>>(std::istream &in, Matrix &m)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << i + 1 << "x" << j + 1 << ":";
            in >> m.mat[i][j];
        }
    }
    return in;
}

// outputting the matrix
ostream &operator<<(std::ostream &out, const Matrix &m)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            out<<m.mat[i][j]<<" ";
        }
        out<<endl;
    }
    return out;
}
