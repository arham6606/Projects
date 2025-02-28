// header files
#include <iostream>
using namespace std;
#include <string>
#include <cmath>

// creating a class
class Complex
{
    // data properties
private:
    int real;
    int imaginary;

public:
    // default
    Complex()
    {
        real = 0;
        imaginary = 0;
    }

    // parameterized
    Complex(int real1, int imaginary1)
    {
        real = real1;
        imaginary = imaginary1;
    }

    // copy concstructor
    Complex(const Complex &obj)
    {
        real = obj.real;
        imaginary = obj.imaginary;
    }

    // member functions
    void setReal(int r)
    {
        real = r;
    }

    void setImaginary(int i)
    {
        imaginary = i;
    }

    int getReal() const
    {
        return real;
    }

    int getImaginary() const
    {
        return imaginary;
    }

    float magnitude() const
    {
        float result;
        result = sqrt((real * real) + (imaginary * imaginary));
        return result;
    }

    // overloaded function with +
    Complex operator+(const Complex &c)
    {
        Complex result;
        result.real = real + c.real;
        result.imaginary = imaginary + c.imaginary;
        return result;
    }

    // overloaded function with -
    Complex operator-(const Complex &c)
    {
        Complex result;
        result.real = real - c.real;
        result.imaginary = imaginary - c.imaginary;
        return result;
    }

    // overloaded function with *
    Complex operator*(const Complex &c)
    {
        int newReal = (real * c.real) - (imaginary * c.imaginary);
        int newImaginary = (real * c.imaginary) + (imaginary * c.real);
        return Complex(newReal, newImaginary);
    }

    // overloaded function with ==
    bool operator==(const Complex &c) const
    {
        return (real == c.real) && (imaginary == c.imaginary);
    }

    // overloaded functions with !=
    bool operator!=(const Complex &c) const
    {
        return !(*this == c);
    }

    // overloaded function with <
    bool operator<(const Complex &c) const
    {
        return magnitude() < c.magnitude();
    }

    // overloaded function with <
    bool operator>(const Complex &c) const
    {
        return magnitude() > c.magnitude();
    }

    // for inputting
    friend istream &operator>>(std::istream &in, Complex &c)
    {
        cout << "Enter real and imaginary part: ";
        in >> c.real;
        in >> c.imaginary;
        return in;
    }

    // for outputting
    friend ostream &operator<<(std::ostream &out, const Complex &c)
    {
        out << c.real << " + " << c.imaginary << "i" ;
        return out;
    }

    // destructor
    ~Complex()
    {
        cout << "Complex removed" << endl;
    }
};
