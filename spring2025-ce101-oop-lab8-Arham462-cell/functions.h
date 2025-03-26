#include <iostream>
using namespace std;
#include <string>
#include "json.hpp"
#include<fstream>
using json = nlohmann::json;
// header files

// making a class for person
class Person
{
private:
    // data properties
    string name;
    int age;
    string preference;
    int bondScore;
    bool isMarried;

public:
    // constructors
    Person()
    {
        name = "";
        age = 0;
        preference = "";
        bondScore = 0;
        isMarried = false;
    }

    Person(string name, int age, string preference, int bondScore, bool isMarried)
    {
        this->name = name;
        this->age = age;
        this->preference = preference;
        this->bondScore = bondScore;
        this->isMarried = isMarried;
    }

    // getters funcitons
    string getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }

    string getPreference()
    {
        return preference;
    }

    int getBondScore() const
    {
        return bondScore;
    }

    bool getMaritalStatus()
    {
        return isMarried;
    }

    // setter functions
    void setName(string name)
    {
        this->name = name;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    void setPreference(string preference)
    {
        this->preference = preference;
    }

    void setBondScore(int bondScore)
    {
        this->bondScore = bondScore;
    }

    void setMaritalStatus(bool status)
    {
        this->isMarried = status;
    }

    // member functions
    // operator overloaded
    bool operator+(const Person &other);

    void operator++();

    // information displaying
    void display();

    virtual void findMatch();
};

// class for basic person inherits form person
class BasicPerson : public Person
{
public:
    // constructors
    BasicPerson() : Person()
    {
    }

    BasicPerson(string name, int age, string preference, int bondScore, bool isMarried)
        : Person(name, age, preference, bondScore, isMarried) {}

    // member function
    void findMatch() override;
};

// class for permium person inherits from person
class PremiumPerson : public Person
{
public:
    // constructors
    PremiumPerson()
        : Person() {}

    PremiumPerson(string name, int age, string preference, int bondScore, bool isMarried)
        : Person(name, age, preference, bondScore, isMarried) {}

    // member function
    void findMatch() override;
};

// class for nikkah
class Nikah
{
private:
    // data propeties
    int mahr;
    string witnesses[2];
    bool nikahStatus;

public:
    // constructors
    Nikah()
    {
        mahr = 0;
        nikahStatus = false;
        for (int i = 0; i <= 1; i++)
        {
            witnesses[i] = "";
        }
    }

    Nikah(int mahr, string witness1, string witness2)
    {
        this->mahr = mahr;
        this->witnesses[0] = witness1;
        this->witnesses[1] = witness2;
    }

    // getter functions
    int getMahr() const
    {
        return mahr;
    }

    string getWitness(int index) const
    {
        if (index == 0 || index == 1)
        {
            return witnesses[index];
        }
        else
        {
            cout << "Only 2 witnesses" << endl;
        }
        return "null";
    }

    bool isNikahFinalized() const
    {
        return nikahStatus;
    }

    // setter funcitons
    void setMahr(int mahr)
    {
        this->mahr = mahr;
    }

    void setWitness(int index, string witness)
    {
        this->witnesses[index] = witness;
    }

    void setNikahStatus(bool status)
    {
        this->nikahStatus = status;
    }

    // member functions
    void finalizeNikah();
    void cancelNikah();
};

// class for marriage
class Marriage
{
private:
    // data properties
    Person *groom;
    Person *bride;
    Nikah nikah;

public:
    // constructors
    Marriage(Person *groom, Person *bride, Nikah nikah)
    {
        this->groom = groom;
        this->bride = bride;
        this->nikah = nikah;
    }

    // getter functions
    Person *getGroom() const
    {
        return groom;
    }

    Person *getBride() const
    {
        return bride;
    }

    Nikah getNikah() const
    {
        return nikah;
    }

    // setter functions
    void setGroom(Person *groom)
    {
        this->groom = groom;
    }

    void setBride(Person *bride)
    {
        this->bride = bride;
    }

    void setNikah(Nikah nikah)
    {
        this->nikah = nikah;
    }

    // member funciton
    void completeMarriage();
};

// class for marriage bura
class MarriageBureau
{
private:
    // data properties
    Marriage *marriages[100];
    int marriageCount;

public:
    // constructors
    MarriageBureau()
    {
        marriageCount = 0;
    }

    // getter functions
    int getMarriageCount() const
    {
        return marriageCount;
    }

    // member function
    void registerMarriage(Marriage *newMarriage);
};

// class for match making system
class MatchMakingSystem
{
private:
    // data properties
    BasicPerson basicPeople[100];
    PremiumPerson premiumPeople[100];
    int basicCount;
    int premiumCount;
    MarriageBureau bureau;

public:
    // constructors
    MatchMakingSystem()
    {
        basicCount = 0;
        premiumCount = 0;
    }

    // memeber functions
    void addBasicPerson(BasicPerson p);
    void addPremiumPerson(PremiumPerson p);
    void removePerson(string name);
    Person *matchPeople(int &matchCount);
    void increaseBond(string name1, string name2);
    void saveToFile();
    void loadFromFile();

    // getter functions
    BasicPerson *getBasicPeople()
    {
        return basicPeople;
    }

    PremiumPerson *getPremiumPeople()
    {
        return premiumPeople;
    }

    int getBasicCount()
    {
        return basicCount;
    }

    int getPremiumCount()
    {
        return premiumCount;
    }
};