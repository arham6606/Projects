#include <iostream>
using namespace std;
#include <string>
// header files

// creating class for processor
class Processor
{
private:
    // data properties
    string brand;
    int cores;

public:
    // construcotrs

    Processor()
    {
        brand = "";
        cores = 0;
    }

    Processor(string brand, int cores)
        : brand(brand), cores(cores) {}

    // getter and setter funcitons
    void setBrand(string b)
    {
        brand = b;
    }

    string getBrand()
    {
        return brand;
    }

    void setCores(int c)
    {
        cores = c;
    }

    int getCores()
    {
        return cores;
    }

    // membe funciton for high performance
    bool isHighPerformance();
};

// creating class for computer
class Computer
{
private:
    // data properties
    string model;
    Processor processor;

public:
    // constructors
    Computer()
    {
        model = "";
    }

    Computer(string m)
        : model(m) {}

    // getter and setter functoions
    void setModel(string m)
    {
        model = m;
    }

    string getModel()
    {
        return model;
    }

    void setProcessor(string b, int c)
    {
        processor.setBrand(b);
        processor.setCores(c);
    }

    Processor getProcessor()
    {
        return processor;
    }

    // member function to check if it is gaming
    bool isGamingComputer();
};

// creating class for professor
class Professor
{
private:
    // data properties
    string name;
    string subject;

public:
    // constructors
    Professor()
    {
        name = "";
        subject = "";
    }

    Professor(string n, string s)
        : name(n), subject(s) {}

    // getter and setter functions
    void setName(string n)
    {
        name = n;
    }

    string getName()
    {
        return name;
    }

    void setSubject(string s)
    {
        subject = s;
    }

    string getSubject()
    {
        return subject;
    }

    // member function to check if teaches
    bool teachesSubject(string sub);
};

// creating class for university
class University
{
private:
    // data properties
    string universityName;
    Professor *professors[10];
    int professorCount;

public:
    // constructors
    University()
    {
        universityName = "";
        professorCount = 0;
    }

    University(string n, int pc)
        : universityName(n), professorCount(pc) {}

    // getter and setter functions
    void setUniversityName(string n)
    {
        universityName = n;
    }

    string getUniversityName()
    {
        return universityName;
    }

    Professor *getProfessor(int p)
    {
        return professors[p];
    }

    int countProfessors()
    {
        return professorCount;
    }

    // memebr function to add
    void addProfessor(Professor *p);
};

// creating class for patient
class Patient
{
private:
    // data properties
    string name;
    int age;

public:
    // constructors
    Patient()
    {
        name = "";
        age = 0;
    }

    Patient(string n, int a)
        : name(n), age(a) {}

    // getter and setter functions
    void setName(string n)
    {
        name = n;
    }

    string getName()
    {
        return name;
    }

    void setAge(int a)
    {
        age = a;
    }

    int getAge()
    {
        return age;
    }

    // member funciton to check if it is a minor
    bool isMinor();
};

// creating class for doctor
class Doctor
{
private:
    // data properties
    string name;
    string specialization;
    Patient *patients[10];
    int patientCount;

public:
    // construcotors
    Doctor()
    {
        name = "";
        patientCount = 0;
        specialization = "";
    }

    Doctor(string n, string special)
        : name(n), specialization(special) {}

    // getter and setter
    void setName(string n)
    {
        name = n;
    }

    string getName()
    {
        return name;
    }

    void setSpecialization(string s)
    {
        specialization = s;
    }

    string getSpecialization()
    {
        return specialization;
    }

    Patient *getPatient(int p)
    {
        return patients[p];
    }

    int countPatients()
    {
        return patientCount;
    }

    // member funciton to add the patients
    void assignPatient(Patient *p);
};

// creating class for hospital
class Hospital
{
private:
    // data properties
    string hospitalName;
    Doctor *doctors[10];
    int doctorCount;

public:
    // constructors
    Hospital()
    {
        hospitalName = "";
        doctorCount = 0;
    }

    Hospital(string n)
        : hospitalName(n) {}

    // getter and setter functions
    void setHospitalName(string n)
    {
        hospitalName = n;
    }

    string getHospitalName()
    {
        return hospitalName;
    }

    Doctor *getDoctor(int d)
    {
        return doctors[d];
    }

    int countDoctors()
    {
        return doctorCount;
    }

    // memeber function to add the doctors
    void addDoctor(Doctor *d);
};

// class of song
class Song
{
private:
    // data properties
    string title;
    double duration;

public:
    // constructors
    Song()
    {
        title = "";
        duration = 0;
    }

    Song(string t, double d)
        : title(t), duration(d) {}

    // getter and setter functions
    void setTitle(string n)
    {
        title = n;
    }

    string getTitle()
    {
        return title;
    }

    void setDuration(double d)
    {
        duration = d;
    }

    double getDuration()
    {
        return duration;
    }

    // member function to check song length
    bool isLongSong();
};

// creating class of music album
class MusicAlbum
{
private:
    // data properties
    string albumName;
    Song songs[10];
    int songCounts;

public:
    // construcotrs
    MusicAlbum()
    {
        albumName = "";
        songCounts = 0;
    }

    // getter and setter functions
    void setAlbumName(string n)
    {
        albumName = n;
    }

    string getAlbumName()
    {
        return albumName;
    }

    Song getSong(int s)
    {
        return songs[s];
    }

    int countSongs()
    {
        return songCounts;
    }

    // member function to add songs
    void addSong(string n, double d);
};

// creating the class of dish
class Dish
{
private:
    // data properties
    string name;
    double price;

public:
    // construcotors
    Dish()
    {
        name = "";
        price = 0;
    }

    // getter and setter functions
    void setName(string n)
    {
        name = n;
    }

    string getName()
    {
        return name;
    }

    void setPrice(double p)
    {
        price = p;
    }

    double getPrice()
    {
        return price;
    }

    // member functtion to check expensive
    bool isExpensiveDish();
};

// creating class for menu
class Menu
{
private:
    // data properties
    Dish dishes[10];
    int dishCount;

public:
    // construcotrs
    Menu()
    {
        dishCount = 0;
    }

    // getter and setter funcitons
    Dish getDish(int d)
    {
        return dishes[d];
    }

    int countDishes()
    {
        return dishCount;
    }

    // memeebr function to add dish
    void addDish(string n, double p);
};

// creating class for resturant
class Restaurant
{
private:
    // data properties
    string resturantName;
    Menu menu;

public:
    // construcotors
    Restaurant()
    {
        resturantName = "";
    }

    // setter and getter functions
    void setRestaurantName(string n)
    {
        resturantName = n;
    }

    string getRestaurantName()
    {
        return resturantName;
    }

    Menu getMenu()
    {
        return menu;
    }

    // memeber funciton to add dishes
    void setMenu(string n, double p);

    // member function to check expensive dish
    bool hasExpensiveDishes();
};