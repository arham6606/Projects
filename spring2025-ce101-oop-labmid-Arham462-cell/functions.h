#include<iostream>
using namespace std;
#include<string>
#include"json.hpp"
#include<fstream>

using json = nlohmann::json;
//header files

//creating class for patient
class Patient
{
private:
//data properties
string name;
int age;
string medicalHistory;
int healthScore;
bool advice;

public:
//constructors
Patient()
{
    name = "";
    age= 0;
    medicalHistory = "";
    healthScore = 0;
    advice = false;
}

Patient(string n,string mh,int a,bool ad)
{
    name = n;
    age = a;
    medicalHistory = mh;
    advice = ad;
}

//multiple constructors to handle info
Patient(string n,int a)
{
    name = n;
    age = a;
}

Patient(string mh)
{
    medicalHistory = mh;
}

//setter functions
void setName(string n)
{
     name = n;
}

void setAge(int a)
{
    age = a;
}

void setMedicalHistory(string mh)
{
    medicalHistory = mh;
}

void setHealthScore(int h)
{
    healthScore = h;
}

//getter functions
string getName()
{
    return name;
}

int getAge()
{
    return age;
}

string getMedicalHistory()
{
    return medicalHistory;
}

int getHealthScore()
{
    return healthScore;
}

bool getAdvice()
{
    return advice;
}

void setAdvice(bool ad)
{
    advice =  ad;
}



friend int operator ++ ( Patient &p);
};




//creating class for Doctors
class Doctors
{
    private:
    string cases;

public:
Doctors()
{
    cases = "";
}

Doctors(string c)
{
    cases = c;
}

void setCases(string c)
{
    cases = c;
}

string getCases()
{
    return cases;
}
   
   void checkingCasesType()
   {
    if(cases == "regular")
    {
        cout<<"Case will be forwarded to General Doctors"<<endl;
    }
    else if(cases == "critical")
    {
        cout<<"Case will be forwarded to Specialists"<<endl;
    }
    else
    {
        cout<<"No Doctor of this type found"<<endl;
    }
   }

};

class GeneralDoctors:public Doctors
{
private:
string name;

public:
GeneralDoctors()
{
    name = "";
}

GeneralDoctors(string n)
{
    name = n;
}

void setName(string n)
{
    name = n ;
}

string getName()
{
    return name;
}

};

class Specialists:public Doctors
{
  private:
  string name;

public:
Specialists()
{
    name = "";
}

Specialists(string n)
{
    name = n;
}

void setName(string n)
{
    name = n ;
}

string getName()
{
    return name;
}

};


class Beds
{
 private:
 string foarmType;
public:
Beds()
{
    foarmType = "";
}
Beds(string f)
{
    foarmType =f;
}

void setFoarm(string f)
{
    foarmType = f;
}

string getFoarm()
{
  return foarmType;
}
};


class HospitalWard
{
    private:
    int numberBeds;
   Beds bed;

public:
HospitalWard()
{
    numberBeds = 0 ;
}

HospitalWard(int n)
{
      numberBeds = n ;
      
}

void setNumBeds(int n)
{
    numberBeds = n;
}

int getNumBeds()
{
  return numberBeds;
}

};


class Hospital
{
  private:
  string name;

  public:
  Hospital()
  {
    name = "";
  }

};


class System
{
   private:
   Hospital * hospital;

   
   
   
};




