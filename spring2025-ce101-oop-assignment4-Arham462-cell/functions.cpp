#include "functions.h"

// global
int Car::carCount = 0;
int Laptop::laptopCount = 0;

Car cloneCar(const Car &original)
{
    return Car(original);
}

Laptop cloneLaptop(const Laptop &original)
{
    return Laptop(original);
}