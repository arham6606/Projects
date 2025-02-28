#include "functions.h"

int main()
{
    // creting the object
    Complex c1, c2, r;
    // setting the values
    c1.setReal(1);
    c1.setImaginary(2);
    c2.setReal(3);
    c2.setImaginary(4);

    // addin the real into real and imag into imag
    r = c1 + c2;
    // displaying
    cout << "Adding" << endl;
    cout << "Real: " << r.getReal() << endl;
    cout << "Imaginary: " << r.getImaginary() << endl;

    // subtracting the real into real and imag into imag
    r = c1 - c2;
    // displaying
    cout << "Subtracting" << endl;
    cout << "Real: " << r.getReal() << endl;
    cout << "Imaginary: " << r.getImaginary() << endl;

    // multiplicating the real into real and imag into imag
    r = c1 * c2;
    // displaying
    cout << "Multiplying" << endl;
    cout << "Real: " << r.getReal() << endl;
    cout << "Imaginary: " << r.getImaginary() << endl;

    // comparing
    if (c1 == c2)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not equal" << endl;
    }

    // magnitude
    cout << "magnitude of first: " << c1.magnitude() << endl;
    cout << "magnitude of second: " << c2.magnitude() << endl;

    //comparing magnitude
    if(c1>c2)
    {
        cout<<"first one is greater"<<endl;
    }
    else if(c1<c2)
    {
        cout<<"Second one is greater"<<endl;
    }
    else
    {
        cout<<"Equal"<<endl;
    }

    //displaying in the complex in a nice form
    cin>>c1;
    cout<< c1;

}