#include "functions.h"

int main()
{
    // object for Course
    Course c1("OOPs", 2025);
    Course c2("EDC", 2025);
    // object for student
    Student s1("Arham", 20, 2.5, c1);
    Student s2("Rashid", 24, 3.5, c2);

    // function calling
    assignCourseToStudent(s1, c1);
    assignCourseToStudent(s2, c2);

    cout << "Course has been assigned to the student" << endl;

    // function calling
    Student *max = compareStudents(s1, s2);
    cout << "The student with the maximum GPA is: " << max->name << endl;
    cout << "And his GPA is: " << max->gpa << endl;

    // function calling
    string fileName = "output.json";
    saveToFile(s2, fileName);
    cout << "Data has been saved to file" << endl;

    // function calling
    cout<<"Loaded form file"<<endl;
    loadFromFile(&s2, fileName);

    //entering new gpa
    float cgpa;
    cout<<"Enter the new gpa: ";
    cin>>cgpa;

    //function calling
    updateGPA(s2,cgpa);
    cout<<"CGPA has been updated"<<endl;
    cout<<"New GPA of "<<s2.name<<" is "<<s2.gpa<<endl;
}


