#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <limits>
#include <chrono>
#include <thread>

// creating a struct of Car
struct Car
{
    string model;
    int year;
    float price;

    // default constructor
    Car()
    {
        model = "Unknown";
        year = 0;
        price = 0.0;
    }

    // Parameterized Constructor
    Car(string model, int year, float price)
        : model(model), year(year), price(price) {}
};

// creating the struct of the class owner;
struct Owner
{
    string name;
    Car *cars;
    int numCars;

    // default constructor
    Owner()
    {
        name = "Unknown";
        cars = nullptr;
        numCars = 0;
    }

    // parameterized constructor
    Owner(string name)
        : name(name), cars(nullptr), numCars(0) {}
};

// creating the struct of garage for cars
struct Garage
{
    string name;
    Owner *owners;
    int numOwners;

    // default constructor
    Garage()
    {
        name = "Unknown";
        owners = nullptr;
        numOwners = 0;
    }

    // parameterized constructor
    Garage(string name)
        : name(name), owners(nullptr), numOwners(0) {}
};

// template
//  Function to simulate loading effect
template <typename T>
void loadingEffect(T message)
{
    cout << message;
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    cout << endl;
}

// function declaration
void showMenu();
void addCar(Owner &owner, const Car &car);
void assign(Owner &owner, Car &car, string name, string model, int year, float price);
void removeCar(Owner &owner, const string &model);
Car *listOwnerCars(const Owner &owner);
void addOwner(Garage &garage, const Owner &owner);
Car findMostExpensiveCar(const Garage &garage);
int countTotalCars(const Garage& garage);