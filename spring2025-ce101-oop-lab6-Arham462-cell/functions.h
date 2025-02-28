#include <iostream>
using namespace std;
#include <string>
// header files

// creating the class of vechicel
class Vehicle
{
    // data properties
private:
    string brand;
    int year;

public:
    // constructor
    Vehicle()
    {
        brand = "";
        year = 0;
    }

    Vehicle(string b, int y)
    {
        brand = b;
        year = y;
    }

    // member function to display
    void displayInfo()
    {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }

    // getter and setter functions
    void setBrand(string b)
    {
        brand = b;
    }

    string getBrand()
    {
        return brand;
    }

    void setYear(int y)
    {
        year = y;
    }

    int getYear()
    {
        return year;
    }

    // member function to
    int getVehicleAge()
    {
        return 2025 - year;
    }
};

// creating the derived class Car
class Car : public Vehicle
{
    // data propetties
protected:
    int seats;

public:
    // constructor
    Car()
    {
        seats = 0;
    }

    Car(string b, int y, int s) : Vehicle(b, y)
    {
        seats = s;
    }

    // member function to display
    void showCarDetails()
    {
        displayInfo();
        cout << "Seats: " << seats << endl;
    }

    // setter and getter functions
    void setSeats(int s)
    {
        seats = s;
    }

    int getSeats()
    {
        return seats;
    }

    // member function to modify the seats
    void modifySeats(int newSeats)
    {
        if (newSeats > 0)
        {
            seats = newSeats;
        }
    }
};

// creating the derived alass for bike
class Bike : public Vehicle
{
    // data properties
protected:
    bool hasGear;

public:
    // cinstructor

    Bike()
    {
        hasGear = true;
    }

    Bike(string b, int y, bool g) : Vehicle(b, y)
    {
        hasGear = g;
    }
    // memeber function to display the info
    void showBikeDetails()
    {
        displayInfo();
        if (hasGear)
        {
            cout << "It has gears" << endl;
        }
    }

    // setter and getter function
    void setHasGear(bool g)
    {
        hasGear = g;
    }

    bool getHasGear()
    {
        return hasGear;
    }

    // memeber function to check if it has gears
    bool isGearBike()
    {
        if (hasGear == true)
        {
            return true;
        }

        else
        {
            return false;
        }
    }
};

// creating the derived class for sports
class SportsCar : public Car
{
    // data properties
protected:
    double topSpeed;

public:
    // construcotr
    SportsCar()
    {
        topSpeed = 0;
    }

    SportsCar(string b, int y, int s, double ts) : Car(b, y, s)
    {
        topSpeed = ts;
    }

    // member function to display
    void showSportsCarDetails()
    {
        displayInfo();
        cout << "The Top Speed is : " << topSpeed << endl;
    }

    // getter and setter functions
    void setTopSpeed(double ts)
    {
        topSpeed = ts;
    }

    double getTopSpeed()
    {
        return topSpeed;
    }

    // member function to upgrade the top speed
    void upgradeSpeed(double increase)
    {
        if(increase>0)
        {
           topSpeed+=increase;
        }
    }
};