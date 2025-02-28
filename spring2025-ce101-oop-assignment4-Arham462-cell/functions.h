#include <iostream>
using namespace std;
#include <string>

// creating the class of Car
class Car
{

private:
    // data properties
    string brand;
    string model;
    int year;

    static int carCount;

public:
    // default constructor
    Car()
    {
        brand = "";
        model = "";
        year = 0;
        carCount++;
    }

    // parameterized constructor
    Car(string brand1, string model1, int year1)
    {
        brand = brand1;
        model = model1;
        year = year1;
        carCount++;
    }

    // copy constructor
    Car(const Car &obj)
    {
        brand = obj.brand;
        model = obj.model;
        year = obj.year;
        carCount++;
    }

    // member funciton

    void setBrand(string b)
    {
        brand = b;
    }

    string getBrand()
    {
        return brand;
    }

    void setModel(string m)
    {
        model = m;
    }

    string getModel()
    {
        return model;
    }

    void setYear(int y)
    {
        year = y;
    }

    int getYear()
    {
        return year;
    }

    inline bool isClassicCar()
    {
        // car's age
        if (year < 2000)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    static int getCarCount()
    {
        return carCount;
    }

    Car compareCars(Car &car)
    {
        if (year < car.year)
        {
            return *this;
        }
        else
        {
            return car;
        }
    }

    // destructor
    ~Car()
    {
        cout << "Car object destroyed" << endl;
        carCount--;
    }
};

// creating a class for laptop
class Laptop
{
private:
    // data properties
    string brand;
    string processor;
    int ram;

    static int laptopCount;

public:
    // default constructor
    Laptop()
    {
        brand = "";
        processor = "";
        ram = 0;
        laptopCount++;
    }

    // parameterized constructor
    Laptop(string brand1, string processor1, int ram1)
    {
        brand = brand1;
        processor = processor1;
        ram = ram1;
        laptopCount++;
    }

    // copy constructor
    Laptop(const Laptop &obj)
    {
        brand = obj.brand;
        processor = obj.processor;
        ram = obj.ram;
        laptopCount++;
    }

    // member function
    void setBrand(string b)
    {
        brand = b;
    }

    string getBrand()
    {
        return brand;
    }

    void setProcessor(string p)
    {
        processor = p;
    }

    string getProcessor()
    {
        return processor;
    }

    void setRam(int r)
    {
        ram = r;
    }

    int getRam()
    {
        return ram;
    }

    inline bool isHighPerformance()
    {
        // laptop performance
        if (ram >= 16)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    static int getLaptopCount()
    {
        return laptopCount;
    }

    Laptop compareLaptops(Laptop &laptop)
    {
        if(ram>laptop.ram)
        {
            return *this;
        }
        else
        {
            return laptop;
        }
    }

    // destructor
    ~Laptop()
    {
        cout << "Laptop object destroyed" << endl;
    }
};

// function declaration
Car cloneCar(const Car &original);
Laptop cloneLaptop(const Laptop &original);