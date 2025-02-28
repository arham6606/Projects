#include "functions.h"

int main()
{
    // object of address struct
    Address a1("king Street", "Lahore", "54000");

    // object of teacher struct
    Teacher t1(34, "Rashid", "Mehmood", a1);

    // object of course struct
    Course c1("CE2024O", "OOPs", 3, t1);
    Course c2("CE2024E", "EDC", 3, t1);
    Course c3("CE2024L", "LA", 3, t1);

    Course c4("CE2024OD", "DS", 3, t1);
    Course c5("CE2024Q", "QT", 3, t1);
    Course c6("CE2024I", "IS", 3, t1);

    // object of student struct
    Student s1(54, "Muhammad", "Arham", a1);
    Student s2(64, "Muhammad", "khan", a1);
    Student s3(74, "Muhammad", "Ali", a1);

    // object of classroom struct
    Classroom cr1(123);
    Classroom cr2(345);
    Classroom cr3(563);

    // object of universiy struct
    University u1("ITU");
    University u2("FAST");
    University u3("NUST");

    // file name
    string fileName = "university.json";

    // calling funciton add university to file
    addNewUniversity(u1, fileName);
    addNewUniversity(u2, fileName);
    cout << "University has been added to the file" << endl;

    //  add classroom to university and displaying it
    addClassroomToUniversity(u1, cr1);
    addClassroomToUniversity(u1, cr2);
    // addClassroomToUniversity(u1, cr2);
    cout << "The Number of classrooms of " << u1.name << " are " << u1.numClassrooms << endl;

    // after the classroom has been  added update the file
    addNewUniversity(u1, fileName);

    // adding students to classrooms and displaying it

    addStudentToClassroom(cr1, s1);
    addStudentToClassroom(cr1, s2);
    addStudentToClassroom(cr2, s3);

    // addStudentToClassroom(cr1, s3);
    cout << "The number of students in the classroom are: " << cr1.numStudents << endl;
    // adding students courses and displaying it
    addCourseToStudent(s1, c1);
    addCourseToStudent(s1, c2);
    addCourseToStudent(s1, c3);

    addCourseToStudent(s2, c4);
    addCourseToStudent(s2, c5);
    addCourseToStudent(s2, c6);

    addCourseToStudent(s3, c4);
    addCourseToStudent(s3, c5);
    addCourseToStudent(s3, c6);

    cout << "The number of courses of this student are: " << s1.numCourses << endl;

    // add the grades of the student
    addGrade(s1, "CE2024O", 4.6);
    addGrade(s1, "CE2024E", 3.6);
    addGrade(s1, "CE2024L", 2.6);

    addGrade(s2, "CE2024OD", 4.6);
    addGrade(s2, "CE2024Q", 3.6);
    addGrade(s2, "CE2024I", 2.6);

    addGrade(s3, "CE2024OD", 4.6);
    addGrade(s3, "CE2024Q", 3.6);
    addGrade(s3, "CE2024I", 2.6);

    // student with highest grades
    cr1.students[0] = s1;
    cr1.students[1] = s2;
    cr2.students[0] = s3;
    Student *highest = highestAchiever(cr1);

    if (highest != nullptr)
    {
        cout << "The highest student is: " << highest->firstName << " " << highest->lastName << endl;
    }

    else
    {
        cout << "No student has valid grades in the classroom." << endl;
    }

    // student with the most courses
    Student *most = mostCourses(cr1);
    if (most != nullptr)
    {
        cout << "The Student with most courses are: " << most->lastName << endl;
    }
    else
    {
        cout << "No students in the classroom" << endl;
    }
    u1.classrooms[0] = cr1;
    u1.classrooms[1] = cr2;
    // average grade of the university
    float averageUniversity = universityAverageGrade(u1);
    cout << "The average of this university is: " << averageUniversity << endl;

    // displaying details of the university
    displayUniversityDetails(u1);

    // removing student form classroom
    removeStudentFromClassroom(cr1, 54);

    u1.classrooms[0] = cr1;
    u1.classrooms[1] = cr2;

    // removing classroom form university
    removeClassroomFromUniversity(u1, 345);

    // remove course from student
    string code;
    cout << "Enter The course code you want to remove: ";
    getline(cin, code);
    // cout << s1.numCourses << endl;
    // cout << s2.courses[1].courseCode << endl;
    removeCourseFromStudent(s2, code);
    // cr1.students[0] = s1;
    cr1.students[0] = s2;
    // cr2.students[0] = s3;
    u1.classrooms[0] = cr1;
    // u1.classrooms[1] = cr2;
    //  cout << u1.classrooms[0].students[0].courses[1].courseCode << endl;

    displayUniversityDetails(u1);


     // removing university form file
     removeUniversityFromFile("ITU", fileName);
}
