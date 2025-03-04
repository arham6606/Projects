#include <iostream>
using namespace std;
#include <string>
// header files

// creating class for library
class Library
{
private:
    // data properties
    bool isBorrowed;

public:
    // constructors
    Library()
    {
        isBorrowed = false;
    }

    // getter and setter functions
    void setIsBorrowed(bool ib)
    {
        isBorrowed = ib;
    }

    bool getIsBorrowed()
    {
        return isBorrowed;
    }
};

// creating class for students

class Student
{
private:
    // data properties
    int id;
    string name;
    Library *library;

public:
    // constructors
    Student()
    {
        id = 0;
        name = "Unknown";
        library = nullptr;
    }

    // getter and setter functions
    void setId(int i)
    {
        id = i;
    }

    int getId()
    {
        return id;
    }

    void setName(string n)
    {
        name = n;
    }

    string getName()
    {
        return name;
    }

    void setLibrary(Library *lib)
    {
        library = lib;
    }

    // memeber functions to borrow
    bool canBorrowBook()
    {
        if (this->isEligibleForLibrary() && library != nullptr)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    // memeber functions to check eligibilyt
    bool isEligibleForLibrary()
    {
        if (id % 2 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// creating class for engine

class Engine
{
private:
    // data properties
    string engineType;

public:
    // constructors
    Engine()
    {
        engineType = "";
    }

    // getter and setter functions
    void setEngineType(string et)
    {
        engineType = et;
    }

    string getEngineType()
    {
        return engineType;
    }

    // member function to check the performance
    bool isHighPerformance()
    {
        if (engineType == "V8" || engineType == "Turbo")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// creating the class for car
class Car
{
private:
    // data properties
    string carName;
    Engine *engine;

public:
    // constructors
    Car()
    {
        carName = "";
        engine = nullptr;
    }

    // getter and setter functions
    void setCarName(string n)
    {
        carName = n;
    }

    string getCarName()
    {
        return carName;
    }

    void setEngine(Engine *eng)
    {
        engine = eng;
    }

    Engine *getEngine()
    {
        return engine;
    }

    // member function to check if it is sports car
    bool isSportsCar()
    {
        if (engine->isHighPerformance() == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// creating the class for room
class Room
{
private:
    // data properties
    int roomNumber;

public:
    // construcotr
    Room()
    {
        roomNumber = 0;
    }

    // getter and setter functions
    void setRoomNumber(int rn)
    {
        roomNumber = rn;
    }

    int getRoomNumber()
    {
        return roomNumber;
    }

    // member function for even room
    bool isEvenRoom()
    {
        if (roomNumber % 2 == 0)
        {
            return true;
        }

        else
        {
            return false;
        }
    }
};

// creating the class for building
class Building
{
private:
    // data properties
    string buildingName;
    Room rooms[3];

public:
    // construcotr
    Building(Room r[3])
    {
        for (int i = 0; i < 3; i++)
        {
            rooms[i] = r[i];
        }
        buildingName = "";
    }

    // getter and setter functions
    void setBuildingName(string n)
    {
        buildingName = n;
    }

    string getBuildingName()
    {
        return buildingName;
    }

    // member function even room
    bool hasEvenRoom()
    {
        for (int i = 0; i < 3; i++)
        {
            if (rooms[i].isEvenRoom() == true)
            {
                return true;
            }
        }
        return false;
    }
};
class Patient;
class Doctor
{
private:
    // data properties
    string name;
    Patient *patients[10];
    int patientCount;

public:
    // Constructor
    Doctor()
    {
        name = "";
        patientCount = 0;
    }

    // Setters and Getters
    void setName(string n)
    {
        name = n;
    }
    string getName()
    {
        return name;
    }

    // member function Add a patient
    void addPatient(Patient *p);

    // member function to Check
    bool hasPatient(string pn);
};

class Patient
{
private:
    string name;
    Doctor *doctors[5];
    int doctorCount;

public:
    // Constructor
    Patient()
    {
        name = "";
        doctorCount = 0;
    }

    // Setters and Getters
    void setName(string n) 
    {
         name = n; 
    }
    string getName() 
    { 
        return name;
         }

    // member function to Add a doctor
    void addDoctor(Doctor *d);

    // member function to  Check
    bool hasDoctor(string dn);
};

