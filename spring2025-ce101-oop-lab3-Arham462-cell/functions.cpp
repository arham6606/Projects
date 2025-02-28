#include "functions.h"

void assignCourseToStudent(Student &s, const Course &c)
{
    // assigning the course
    s.course.courseName = c.courseName;
    s.course.courseCode = c.courseCode;
}

Student *compareStudents(const Student &s1, const Student &s2)
{
    // compare students
    if (s1.gpa > s2.gpa)
    {
        return new Student(s1);
    }
    //if both have the same gpa
    else if (s1.gpa == s2.gpa)
    {
        return new Student(s1);
    }

    else
    {
        return new Student{s2};
    }
}

void saveToFile(const Student &studentObj, const string &filename)
{
    //creating a json and writing to file
    json j;
    j["course"]["courseName"] = studentObj.course.courseName;
    j["course"]["courseCode"] = studentObj.course.courseCode;
    j["name"] = studentObj.name;
    j["Age"] = studentObj.age;
    j["GPA"] = studentObj.gpa;

    fstream file(filename, ios::out);
    file << j.dump(4);

    file.close();
}

void loadFromFile(Student *studentObj, const string &filename)
{
    fstream file(filename, ios::in);
    
    //creating a json reading from the file
    json j;
    file >> j;
    studentObj->age = j["Age"];
    studentObj->gpa = j["GPA"];
    studentObj->course.courseName = j["course"]["courseName"];
    studentObj->course.courseCode = j["course"]["courseCode"];
    studentObj->name = j["name"];
    
    file.close();
}

void updateGPA(Student& s, float newGPA)
{
    //updating gpa
    s.gpa = newGPA;
}