#include <iostream>
using namespace std;
#include <string>
#include"json.hpp"
using json = nlohmann::json;
#include<fstream>

// making struct for Course
struct Course
{
    // properties for courses
    string courseName;
    int courseCode;

    // default constructor
    Course()
    {
        courseName = "";
        courseCode = 0;
    }

    // Parameterized constructor
    Course(string course_Name, int course_Code)
    {
        courseName = course_Name;
        courseCode = course_Code;
    }
};

// struct for Student

struct Student
{
    // properties for student
    string name;
    int age;
    float gpa;
    Course course;

    // default constructor
    Student()
    {
        name = "";
        age = 0;
        gpa = 0.0;
        course = Course();
    }

    // paremeterized constructor
    Student(string name, int age, float gpa, Course c)
    {
        this->name = name;
        this->age = age;
        this->gpa = gpa;
        course = c;
    }
};

// function declaration
void assignCourseToStudent(Student &s, const Course &c);
Student *compareStudents(const Student &s1, const Student &s2);
void saveToFile(const Student& studentObj, const string& filename);
void loadFromFile(Student* studentObj, const string& filename);
void updateGPA(Student& s, float newGPA);

