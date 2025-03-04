#include"functions.h"

// Define addPatient
void Doctor::addPatient(Patient *p)
{
    if (patientCount < 10)
    {
        patients[patientCount++] = p;
    }
}

// Define addDoctor 
void Patient::addDoctor(Doctor *d)
{
    if (doctorCount < 5)
    {
        doctors[doctorCount++] = d;
    }
}

// Define hasPatient
bool Doctor::hasPatient(string pn)
{
    for (int i = 0; i < patientCount; i++)
    {
        if (patients[i]->getName() == pn)
        {
            return true;
        }
    }
    return false;
}

// Define hasDoctor
bool Patient::hasDoctor(string dn)
{
    for (int i = 0; i < doctorCount; i++)
    {
        if (doctors[i]->getName() == dn)
        {
            return true;
        }
    }
    return false;
}
