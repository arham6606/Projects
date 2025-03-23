#include "functions.h"

// for passport class
bool Passport::isValid()
{
    if (issueDate < expiryDate)
    {
        return true;
    }

    else
    {
        return false;
    }
}

// for person class
bool Person::hasValidPassport()
{
    if (passport)
    {
        return passport->isValid();
    }
    else
    {
        return false;
    }
}

bool Patient::hasDoctor()
{
    if (assignedDoctor != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// for doctor class
void Doctor::addPatient(Patient *p)
{
    patients[patientCount] = p;
    patientCount++;
}

// for student class
void Student::enrollCourse(Course *c)
{
    courses[courseCount] = c;
    courseCount++;
}

bool Student::isEnrolledInCourse(Course *c)
{
    for (int i = 0; i < courseCount; i++)
    {
        if (courses[i] == c)
            return true;
    }
    return false;
}

// for course class
void Course::enrollStudent(Student *s)
{
    if (studentCount < 50)
    {
        students[studentCount] = s;
        studentCount++;
    }
    else
    {
        cout << "Course is full!" << endl;
    }
}

// for students class
bool Students::isAssignedToClassroom(Classroom *c)
{
    for (int i = 0; i < c->getTotalStudents(); i++)
    {
        if (c->getStudents()[i] == this)
        {
            return true;
        }
    }
    return false;
}

// for classroom class
void Classroom ::addStudent(Students *s)
{
    if (studentCount < 30)
    {
        students[studentCount] = s;
        studentCount++;
    }
    else
    {
        cout << "Classroom is full!" << endl;
    }
}

// for teacher class
bool Teacher::hasClassroom()
{

    return assignedClassroom != nullptr;
}

// for project class
void Project::addEmployee(Employee *e)
{
    if (employeeCount < 20)
    {
        employees[employeeCount++] = e;
    }
}

// for companey class
void Company::addEmployee(Employee *e)
{
    if (employeeCount < 100)
    {
        employees[employeeCount++] = e;
    }
}