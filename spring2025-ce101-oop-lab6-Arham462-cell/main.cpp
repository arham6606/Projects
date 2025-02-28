#include "functions.h"

int main()
{
    // creating the object and checking the functionality for the car
    Car c1;
    c1.setBrand("Audi");
    c1.setSeats(4);
    c1.setYear(2024);
    c1.showCarDetails();
    cout << endl;
    // c1.displayInfo();

    // creating the object and checking the functionality for the bike
    Bike b1;
    b1.setBrand("CD-70");
    b1.setYear(2020);
    b1.setHasGear(true);
    b1.showBikeDetails();
    cout << endl;

    // creating the object and checking the functionality for the sports car
    SportsCar sc1;
    sc1.setBrand("F1");
    sc1.setSeats(1);
    sc1.setYear(2023);
    sc1.setTopSpeed(300);
    sc1.showSportsCarDetails();

    // getting the vechile age
    cout << "The age of " << sc1.getBrand() << " is: " << sc1.getVehicleAge();

    // modifying the seats of cars
    cout << "The seats of " << c1.getBrand() << " is: " << c1.getSeats() << endl;
    c1.modifySeats(7);
    cout << "After Modifying the seats become: " << c1.getSeats() << endl;

    // checking the gears of bikes
    if (b1.isGearBike())
    {
        cout << "Bike has Gears" << endl;
    }

    else
    {
        cout << "Bike has no Gears" << endl;
    }

    //upgrading the top speed
    cout << "The Top speed of " << sc1.getBrand() << " is: " << sc1.getTopSpeed() << endl;
    sc1.upgradeSpeed(500);
    cout<<"Modifying the Speed: "<<sc1.getTopSpeed()<<endl;
    
}