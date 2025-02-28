#include "functions.h"

int main()
{
    // creating the object and checking the default constructor by printing the values
    cout << "Using the default constructor" << endl;
    Matrix m1;
    displayMatrix(m1);

    // creating the object and checking the parameterized constructor by printing the values
    cout << "Using the parameterized constructor" << endl;
    int array[3][3] =
        {
            {1, 4, 7},
            {2, 5, 8},
            {3, 6, 9}

        };
    Matrix m2(array);
    displayMatrix(m2);

    // creating the object and checking the copy constructor
    cout << "Using the copy constructor" << endl;
    Matrix m3 = m2;
    displayMatrix(m3);

    // setting the elements
    Matrix m4;
    enterMatrix(m4);
    cout << "\nThe matrix you have entered" << endl;
    displayMatrix(m4);

    // adding 2 matrixes
    Matrix add;
    cout << "Adding the 2 matrices" << endl;
    add = m3 + m4;
    displayMatrix(add);

    // subtracting 2 matrices
    Matrix sub;
    cout << "Subtracting the 2 matrices" << endl;
    sub = m3 - m4;
    displayMatrix(sub);

    // multiply the 2 matrixes
    Matrix mul;
    cout << "Multiplying the matrixes" << endl;
    mul = m3 * m4;
    displayMatrix(mul);

    // comparing 2 matrices if equal
    if (m3 == m4)
    {
        cout << "Matrices are equal" << endl;
    }

    // comparing 2 matrices if not equal
    if (m3 != m4)
    {
        cout << "Matrices are not equal" << endl;
    }

    // sum of first matrix is smaller
    if (m3 < m4)
    {
        cout << "The sum of elememts of the first matrix is smaller" << endl;
    }

    // sum of first matrix is greater
    if (m3 > m4)
    {
        cout << "The sum of elememts of the first matrix is greater" << endl;
    }

    // negating all the the elements
    cout << "Negating all elements in the matrix" << endl;
    Matrix neg = -m4;
    displayMatrix(neg);

    // increment all elements by one
    cout << "Incrementing all the elements by one" << endl;
    Matrix pos = ++m4;
    displayMatrix(pos);

    // using the assingment operator
    cout << "using the assignment operator" << endl;
    pos = neg;
    displayMatrix(pos);

    //entering the elements by friend function
    Matrix m5;
    cin>>m5;
    cout<<endl;

    //displaying the elements by friend function
    cout<<m5;
}