#include <iostream>
using namespace std;
#include <string>
// header files

// creating class for passport
class Passport
{
private:
    // data properties
    string passportNumber;
    string issueDate;
    string expiryDate;

public:
    // constructors
    Passport()
    {
        passportNumber = "";
        issueDate = "";
        expiryDate = "";
    }
    Passport(string p, string i, string e)
    {
        passportNumber = p;
        issueDate = i;
        expiryDate = e;
    }

    // setter and getter functions
    void setPassportNumber(string p)
    {
        passportNumber = p;
    }

    string getPassportNumber()
    {
        return passportNumber;
    }

    void setIssueDate(string i)
    {
        issueDate = i;
    }

    string getIssueDate()
    {
        return issueDate;
    }

    void setExpiryDate(string e)
    {
        expiryDate = e;
    }

    string getExpiryDate()
    {
        return expiryDate;
    }

    // membe funcion to check the validity
    bool isValid();
};

// creating class for person
class Person
{
private:
    // data properties
    string name;
    int age;
    Passport *passport;

public:
    // constructors
    Person()
    {
        name = "";
        age = 0;
        passport = nullptr;
    }

    Person(string n, int a, Passport *p)
    {
        name = n;
        age = a;
        passport = p;
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

    void setAge(int a)
    {
        age = a;
    }

    int getAge()
    {
        return age;
    }

    void assignPassport(Passport *p)
    {
        passport = p;
    }

    Passport *getPassport()
    {
        return passport;
    }

    // member functions to check validity
    bool hasValidPassport();
};

// class declaration
class Doctor;
// creating class for patient
class Patient
{
private:
    // data properties
    string name;
    int age;
    Doctor *assignedDoctor;

public:
    // construcotrs
    Patient()
    {
        name = "";
        age = 0;
        assignedDoctor = nullptr;
    }

    Patient(string n, int a, Doctor *d)
    {
        name = n;
        age = a;
        assignedDoctor = d;
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

    void setAge(int a)
    {
        age = a;
    }

    int getAge()
    {
        return age;
    }

    void assignDoctor(Doctor *d)
    {
        assignedDoctor = d;
    }

    bool hasDoctor();
};

// creating class for doctor
class Doctor
{
private:
    // data properties
    string name;
    string specialization;
    Patient *patients[100];
    int patientCount;

public:
    // constructors
    Doctor()
    {
        name = "";
        specialization = "";
        patientCount = 0;
    }

    Doctor(string n, string s)
    {
        name = n;
        specialization = s;
        patientCount = 0;
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

    void setSpecialization(string s)
    {
        specialization = s;
    }

    string getSpecialization()
    {
        return specialization;
    }

    Patient **getPatients()
    {
        return patients;
    }

    int getPatientCount()
    {
        return patientCount;
    }

    // membe function to add the patient
    void addPatient(Patient *p);
};

class Course;
// creating class for student
class Student
{
private:
    // data properties
    string name;
    int studentID;
    Course *courses[10];
    int courseCount;

public:
    // constructors
    Student()
    {
        name = "";
        studentID = 0;
        courseCount = 0;
    }

    Student(string n, int s)
    {
        name = n;
        studentID = s;
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

    void setID(int a)
    {
        studentID = a;
    }

    int getID()
    {
        return studentID;
    }

    void enrollCourse(Course *c);

    Course **getCourses()
    {
        return courses;
    }

    // member function to check enrollment
    bool isEnrolledInCourse(Course *c);
};

// creating class for course
class Course
{
private:
    // data properties
    string title;
    int courseID;
    Student *students[50];
    int studentCount;

public:
    // Constructor
    Course()
    {
        title = "";
        courseID = 0;
        studentCount = 0;
    }

    Course(string t, int id)
    {
        title = t;
        courseID = id;
        studentCount = 0;
    }

    // getter and setter functions
    void setTitle(string t)
    {
        title = t;
    }

    string getTitle()
    {
        return title;
    }

    void setID(int c)
    {
        courseID = c;
    }

    int getCourseId()
    {
        return courseID;
    }

    Student **getStudents()
    {
        return students;
    }

    int getEnrollmentCount()
    {
        return studentCount;
    }

    // Enroll a student
    void enrollStudent(Student *s);
};

// class declaration
class Classroom;

// creating class for students
class Students
{
private:
    // data properties
    string name;
    int studentID;

public:
    // Constructor

    Students()
    {
        name = "";
        studentID = 0;
    }

    Students(string n, int id)
        : name(n), studentID(id) {}

    // setter and  getter functions
    void setName(string n)
    {
        name = n;
    }

    void setStudentID(int id)
    {
        studentID = id;
    }

    string getName()
    {
        return name;
    }

    int getStudentID()
    {
        return studentID;
    }

    // Check if the student is in class
    bool isAssignedToClassroom(Classroom *c);
};

// creating class of classroom
class Classroom
{
private:
    // data properties
    int classID;
    Students *students[30];
    int studentCount;

public:
    // Constructor

    Classroom()
    {
        classID = 0;
        studentCount = 0;
    }

    Classroom(int id)
        : classID(id), studentCount(0) {}

    // setter and  getters
    int getClassID()
    {
        return classID;
    }
    Students **getStudents()
    {
        return students;
    }
    int getTotalStudents()
    {
        return studentCount;
    }

    void setClassID(int id)
    {
        classID = id;
    }

    // Add a student to the classroom
    void addStudent(Students *s);
};

// creating class of teacher
class Teacher
{
private:
    // data properties
    string name;
    Classroom *assignedClassroom;

public:
    // Constructor

    Teacher()
    {
        name = "";
    }
    Teacher(string n, Classroom *c = nullptr)
        : name(n), assignedClassroom(c) {}

    // setter and Getters
    string getName()
    {
        return name;
    }
    Classroom *getClassroom()
    {
        return assignedClassroom;
    }

    void setName(string n)
    {
        name = n;
    }
    void assignClassroom(Classroom *c)
    {
        assignedClassroom = c;
    }

    // Check if the teacher has a classroom assigned
    bool hasClassroom();
};

// class declaration
class Project;

// creating clss for employeee
class Employee
{
private:
    // data properties
    string name;
    int employeeID;
    Project *project;

public:
    // construcotrrs
    Employee()
    {
        name = "";
        employeeID = 0;
    }

    Employee(string n, int id, Project *p = nullptr)
        : name(n), employeeID(id), project(p) {}

    // setter and getter functions
    void assignProject(Project *p)
    {
        project = p;
    }

    Project *getProject()
    {
        return project;
    }

    bool isAssignedToProject()
    {
        return project != nullptr;
    }

    void setName(string n)
    {
        name = n;
    }

    string getName()
    {
        return name;
    }

    void setID(int id)
    {
        employeeID = id;
    }

    int getID()
    {
        return employeeID;
    }
};

// creating class for project
class Project
{
private:
    // data properties
    string title;
    int projectID;
    Employee *employees[20];
    int employeeCount;

public:
    // constructors

    Project()
    {
        title = "";
        projectID = 0;
        employeeCount = 0;
    }

    Project(string t, int id)
        : title(t), projectID(id), employeeCount(0) {}

    Employee **getEmployees()
    {
        return employees;
    }

    int getTotalEmployees()
    {
        return employeeCount;
    }

    void setTitle(string t)
    {
        title = t;
    }

    string getTitle()
    {
        return title;
    }

    void setID(int id)
    {
        projectID = id;
    }

    int getID()
    {
        return projectID;
    }

    // member function to add employee
    void addEmployee(Employee *e);
};

// creating class for companey
class Company
{
private:
    // data properties
    string name;
    Employee *employees[100];
    int employeeCount;

public:
    // constructors

    Company()
    {
        name = "";
        employeeCount = 0;
    }

    Company(string n)
        : name(n), employeeCount(0) {}

    Employee **getEmployees()
    {
        return employees;
    }

    int getTotalEmployees()
    {
        return employeeCount;
    }

    void setName(string n)
    {
        name = n;
    }

    string getName()
    {
        return name;
    }

    // to add the employess in the company
    void addEmployee(Employee *e);
};
