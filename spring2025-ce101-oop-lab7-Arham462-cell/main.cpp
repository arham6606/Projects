#include "functions.h"

int main()
{
    // creating object for student
    Student s1, s2;
    s1.setId(34);
    s2.setId(45);
    s1.setName("Arham");
    s2.setName("Marcus");
    // for checking eligibility for first student
    if (s1.isEligibleForLibrary() == true)
    {
        cout << s1.getName() << " is eligible for library" << endl;
    }
    else
    {
        cout << s1.getName() << " is not eligible for library" << endl;
    }

    // for checking eligibilty for senfond student
    if (s2.isEligibleForLibrary() == true)
    {
        cout << s2.getName() << " is eligible for library" << endl;
    }
    else
    {
        cout << s2.getName() << " is not eligible for library" << endl;
    }

    // creating the object for library
    Library lib;
    lib.setIsBorrowed(false);
    s1.setLibrary(&lib);

    if (s1.canBorrowBook() == true)
    {
        cout << s1.getName() << " have borrowed book" << endl;
    }
    else
    {
        cout << s1.getName() << " have not borrowed book" << endl;
    }

    // creating the object for engine
    Engine e1, e2;
    e1.setEngineType("V8");
    e2.setEngineType("Normal");

    if (e2.isHighPerformance() == true)
    {
        cout << "Faster" << endl;
    }

    else
    {
        cout << "Slower" << endl;
    }

    // creating the class for car
    Car c1;
    c1.setCarName("Mercedes");
    c1.setEngine(&e2);
    if (c1.isSportsCar() == true)
    {
        cout << "Faster" << endl;
    }
    else
    {
        cout << "Slower" << endl;
    }

    // creating objects for rooms and building
    Room rooms[3];
    rooms[0].setRoomNumber(101);
    rooms[1].setRoomNumber(202);
    rooms[2].setRoomNumber(303);
    Building building(rooms);
    building.setBuildingName("Arfa Tower");

    if(building.hasEvenRoom()==true)
    {
        cout<<"has Even Rooms "<<endl;
    }
    

     Doctor doc1, doc2;
    doc1.setName("Dr. Smith");
    doc2.setName("Dr. Johnson");

    Patient pat1, pat2;
    pat1.setName("Alice");
    pat2.setName("Bob");

}