#include "functions.h"

int main()
{
    cout << "Detail of the cars as follows" << endl;
    // object of car
    Car c1;

    cout << "\ncurrent count: " << c1.getCarCount() << endl;

    // setting the data
    c1.setBrand("Audi");
    c1.setModel("G-Tron");
    c1.setYear(2014);

    // printing the data of car 1
    cout << "\nCar 1" << endl;
    cout << "Brand: " << c1.getBrand() << endl;
    cout << "Model: " << c1.getModel() << endl;
    cout << "Year: " << c1.getYear() << endl;

    // checking if the car is older then 25 years
    if (c1.isClassicCar())
    {
        cout << "\nCar is classical" << endl;
    }
    else
    {
        cout << "\nCar is modern" << endl;
    }

    // object of car
    Car c2;
    c2.setBrand("Ford ");
    c2.setModel("Megatron");
    c2.setYear(1900);

    // printing the data of car 2
    cout << "\n\nCar 2" << endl;
    cout << "Brand: " << c2.getBrand() << endl;
    cout << "Model: " << c2.getModel() << endl;
    cout << "Year: " << c2.getYear() << endl;

    // checking if the car is older
    if (c2.isClassicCar())
    {
        cout << "\nCar is classical" << endl;
    }
    else
    {
        cout << "\nCar is modern" << endl;
    }

    cout << "\ncurrent count: " << c2.getCarCount() << endl;

    // object of car
    Car c3 = cloneCar(c2);
    cout << "\nCar 2 data is copied to car 3" << endl;
    cout << "\n\nCar 3" << endl;
    cout << "Brand: " << c3.getBrand() << endl;
    cout << "Model: " << c3.getModel() << endl;
    cout << "Year: " << c3.getYear() << endl;
    cout << "\ncurrent count: " << c2.getCarCount() << endl;

    // comparing the cars
    Car older = c3.compareCars(c1);
    cout << older.getBrand() << " is the older car" << endl;

    cout << "\n\nDetail of the Laptops as follows" << endl;
    // object of Laptop
    Laptop l1;

    cout << "\ncurrent count: " << l1.getLaptopCount() << endl;

    // setting the data
    l1.setBrand("HP");
    l1.setProcessor("i7 12Gen");
    l1.setRam(16);

    // printing the data of laptop 1
    cout << "Laptop 1" << endl;
    cout << "Brand: " << l1.getBrand() << endl;
    cout << "Processor: " << l1.getProcessor() << endl;
    cout << "RAM: " << l1.getRam() << endl;

    // checking the ram of the laptop
    if (l1.isHighPerformance())
    {
        cout << "Laptop is top notch" << endl;
    }

    else
    {
        cout << "Laptop is not top notch" << endl;
    }

    // object of laptop
    Laptop l2;
    l2.setBrand("Lenovo");
    l2.setProcessor("i9 23Gen");
    l2.setRam(13);

    // printing the data of car 2
    cout << "\nLaptop 2" << endl;
    cout << "Brand: " << l2.getBrand() << endl;
    cout << "Processor: " << l2.getProcessor() << endl;
    cout << "RAM: " << l2.getRam() << endl;

    // checking the ram of the laptop
    if (l2.isHighPerformance())
    {
        cout << "Laptop is top notch" << endl;
    }

    else
    {
        cout << "Laptop is not top notch" << endl;
    }

    cout << "\ncurrent count: " << l2.getLaptopCount() << endl;

    cout << "\nLaptop 2 data is copied to Laptop 3" << endl;

    // object of laptop
    Laptop l3 = cloneLaptop(l2);

    cout << "\nLaptop 3" << endl;
    cout << "Brand: " << l3.getBrand() << endl;
    cout << "Processor: " << l3.getProcessor() << endl;
    cout << "RAM: " << l3.getRam() << endl;

    cout << "\ncurrent count: " << l2.getLaptopCount() << endl;

    // comparing the laptops
    Laptop olders = l3.compareLaptops(l1);
    cout << olders.getBrand() << " has the highest RAM\n\n"
         << endl;
}