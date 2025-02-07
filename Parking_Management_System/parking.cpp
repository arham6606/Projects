#include "parking.h"

void showMenu()
{
    cout << "\n==============================\n";
    cout << "       PARKING SYSTEM        \n";
    cout << "==============================\n";
    cout << "1. Add Owner & Cars\n";
    cout << "2. Display Owner's Cars\n";
    cout << "3. Remove Car\n";
    cout << "4. Most Expensive Car\n";
    cout << "5. Total Number of Cars\n";
    cout << "6. Exit\n";
    cout << "==============================\n";
}

void assign(Owner &owner, Car &car, string name, string model, int year, float price)
{
    // assigning values
    owner.name = name;
    car.model = model;
    car.price = price;
    car.year = year;
}

void addCar(Owner &owner, const Car &car)
{
    // DMA
    Car *addingCar = new Car[owner.numCars + 1];

    // adding the previous cars in the array
    for (int i = 0; i < owner.numCars; i++)
    {
        addingCar[i] = owner.cars[i];
    }

    // car saved at the last
    addingCar[owner.numCars] = car;
    if (owner.cars != nullptr)
    {
        // deleting the previous memory
        delete[] owner.cars;
    }

    // assigning the new memory to owner cars
    owner.cars = addingCar;

    // incrementing the cars
    owner.numCars++;
}

void removeCar(Owner &owner, const string &model)
{
    // used for storing removing model index
    int index;
    // finding the index which needs to be removed
    for (int i = 0; i < owner.numCars; i++)
    {
        if (owner.cars[i].model == model)
        {
            index = i;
            break;
        }
    }

    // shifting the array to the left
    for (int j = index; j < owner.numCars - 1; j++)
    {
        owner.cars[j] = owner.cars[j + 1];
    }

    // decrementing the cars
    owner.numCars--;
}

Car *listOwnerCars(const Owner &owner)
{
    // making it a dma
    Car *owned = new Car[owner.numCars];

    // if no cars then assign nullptr
    if (owner.numCars == 0)
    {
        return nullptr;
    }

    // copying the owner cars in the array
    for (int i = 0; i < owner.numCars; i++)
    {
        owned[i] = owner.cars[i];
    }

    // returning the array
    return owned;
}

void addOwner(Garage &garage, const Owner &owner)
{
    // memory will be set at run time
    Owner *add = new Owner[garage.numOwners + 1];

    // copying the data in the array
    for (int i = 0; i < garage.numOwners; i++)
    {
        add[i] = garage.owners[i];
    }

    // last element will be entered here
    add[garage.numOwners] = owner;

    // deleting the previous memory
    delete[] garage.owners;

    // updating the data because we need to deallocate the memory
    garage.owners = add;

    // increasing the owners in the garage
    garage.numOwners++;
}

Car findMostExpensiveCar(const Garage &garage)
{
    // if garage has no owners
    if (garage.numOwners == 0)
    {
        throw std::runtime_error("Garage has no owners.");
    }

    // creating a pointer to avoid copies
    Car *highPrice = nullptr;

    // setting first car as expensive
    for (int i = 0; i < garage.numOwners; i++)
    {
        if (garage.owners[i].numCars > 0)
        {
            highPrice = &garage.owners[i].cars[0];
            break;
        }
    }

    // traversing the garage
    for (int i = 0; i < garage.numOwners; i++)
    {
        // traversing the owner cars
        for (int j = 0; j < garage.owners[i].numCars; j++)
        {
            // checking
            if (garage.owners[i].cars[j].price > highPrice->price)
            {
                // updating
                highPrice = &garage.owners[i].cars[j];
            }
        }
    }

    // returning
    return *highPrice;
}

int countTotalCars(const Garage &garage)
{
    // keeping track of cars
    int count = 0;
    // traversing the garage
    for (int i = 0; i < garage.numOwners; i++)
    {
        for (int j = 0; j < garage.owners[i].numCars; j++)
        {
            count++;
        }
    }

    return count;
}
