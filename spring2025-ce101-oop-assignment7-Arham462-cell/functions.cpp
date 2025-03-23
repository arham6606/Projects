#include "functions.h"

// function functionality

// for processor class
bool Processor::isHighPerformance()
{
    if (cores > 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// for computer class
bool Computer::isGamingComputer()
{
    if (processor.isHighPerformance())
    {
        return true;
    }

    else
    {
        return false;
    }
}

// for professor class
bool Professor::teachesSubject(string sub)
{
    if (subject == sub)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// for universiy class
void University::addProfessor(Professor *p)
{
    if (!(professorCount == 10))
    {
        professors[professorCount] = p;
    }
    else
    {
        cout << "All seats were filled" << endl;
    }
    professorCount++;
}

// for patient class
bool Patient::isMinor()
{
    if (age < 18)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// for doctor class
void Doctor::assignPatient(Patient *p)
{
    if (!(patientCount == 10))
    {
        patients[patientCount] = p;
    }
    else
    {
        cout << "No seats available" << endl;
    }
    patientCount++;
}

// for hosital class
void Hospital::addDoctor(Doctor *d)
{
    if (!(doctorCount == 10))
    {
        doctors[doctorCount] = d;
    }
    else
    {
        cout << "All seats were filled" << endl;
    }
    doctorCount++;
}

// for song class
bool Song::isLongSong()
{
    if (duration > 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// for music album class
void MusicAlbum::addSong(string n, double d)
{
    songs[songCounts].setTitle(n);
    songs[songCounts].setDuration(d);
    songCounts++;
}

// for dish class
bool Dish::isExpensiveDish()
{
    if (price > 20)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// for menu class
void Menu::addDish(string name, double price)
{
    dishes[dishCount].setName(name);
    dishes[dishCount].setPrice(price);
    dishCount++;
}

// for resturant class
void Restaurant::setMenu(string name, double price)
{
    menu.addDish(name, price);
}

// for resturant class
bool Restaurant::hasExpensiveDishes()
{
    int count = 1;
    for (int i = 0; i < menu.countDishes(); i++)
    {
        if (menu.getDish(i).isExpensiveDish() == true)
        {
            return true;
        }
    }
    return false;
}
