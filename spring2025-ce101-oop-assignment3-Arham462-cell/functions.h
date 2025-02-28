#include <iostream>
#include <string>
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;
using namespace std;

// struct of address
struct Address
{
    // properties
    string street;
    string city;
    string zipCode;

    // default constructor
    Address()
    {
        street = "";
        city = "";
        zipCode = "";
    }

    // parameterized constructor
    Address(string street, string city, string zipCode)
        : street(street), city(city), zipCode(zipCode) {};
};

// struct of teacher
struct Teacher
{
    // properties
    int teacherId;
    string firstName;
    string lastName;
    Address address;

    // default constructor
    Teacher()
    {
        teacherId = 0;
        firstName = "";
        lastName = "";
        address = Address();
    }

    // parametrized constructor
    Teacher(int teacherId, string firstName, string lastName, Address address)
        : teacherId(teacherId), firstName(firstName), lastName(lastName), address(address) {};
};

// struct of course
struct Course
{
    // properties
    string courseCode;
    string courseName;
    int credits;
    Teacher teacher;

    // default constructor
    Course()
    {
        courseCode = "";
        courseName = "";
        credits = 0;
        teacher = Teacher();
    }

    // parameteried constructor
    Course(string courseCode, string courseName, int credits, Teacher teacher)
        : courseCode(courseCode), courseName(courseName), credits(credits), teacher(teacher) {};
};

// struct of grade report
struct GradeReport
{
    // properties
    string courseCode;
    float grade;

    // default constructor
    GradeReport()
    {
        courseCode = "";
        grade = 0;
    }

    // parametrized constructor
    GradeReport(string courseCode, float grade)

        : courseCode(courseCode), grade(grade) {};
};

// struct of student
struct Student
{
    // properteies
    int studentId;
    string firstName;
    string lastName;
    Address address;
    Course *courses;
    GradeReport *gradeReport;
    int numCourses;

    // default constructor
    Student()
    {
        studentId = 0;
        firstName = "";
        lastName = "";
        address = Address();
        courses = nullptr;
        gradeReport = nullptr;
        numCourses = 0;
    }

    // parametrized constructor
    Student(int studentId, string firstName, string lastName, Address address)
        : studentId(studentId), firstName(firstName), lastName(lastName), address(address),
          courses(nullptr), gradeReport(nullptr), numCourses(0) {};
};

// struct of classroom
struct Classroom
{
    // properties
    int classroomId;
    Student *students;
    int numStudents;

    // default constructor
    Classroom()
    {
        classroomId = 0;
        students = nullptr;
        numStudents = 0;
    }

    // parametrized constructor
    Classroom(int classroomId)
        : classroomId(classroomId), students(nullptr), numStudents(0) {}
};

// struct of university
struct University
{
    // properties
    string name;
    Classroom *classrooms;
    int numClassrooms;

    // default constructor
    University()
    {
        name = "";
        classrooms = nullptr;
        numClassrooms = 0;
    }

    // parameterized constructor
    University(string name)
        : name(name), classrooms(nullptr), numClassrooms(0) {}
};

// function decalration
void addNewUniversity(University &university, const string &filename);
void addClassroomToUniversity(University &university, const Classroom &classroom);
void addStudentToClassroom(Classroom &classroom, const Student &student);
void addCourseToStudent(Student &student, const Course &course);
void addGrade(Student &student, const string &code, const float grade);
Student *highestAchiever(Classroom &classroom);
Student *mostCourses(Classroom &classroom);
float universityAverageGrade(const University &university);
void displayUniversityDetails(const University &university);
void removeStudentFromClassroom(Classroom &classroom, int studentId);
void removeClassroomFromUniversity(University &university, int classroomId);
void removeCourseFromStudent(Student &student, const string &courseCode);
void removeUniversityFromFile(const string &name, const string &filename);
