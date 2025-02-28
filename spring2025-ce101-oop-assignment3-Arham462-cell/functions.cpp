#include "functions.h"

void addNewUniversity(University &university, const string &filename)
{
    json universityArray;

    // Read from file
    fstream inputFile(filename, ios::in);
    // Check if file exists
    if (inputFile)
    {
        inputFile >> universityArray;
        inputFile.close();
    }

    // Creating the JSON object for the university
    json universityJson;
    universityJson["name"] = university.name;
    universityJson["numClassrooms"] = university.numClassrooms;

    // Check if the university exists, update it if found
    bool found = true;
    for (auto &uni : universityArray)
    {
        if (uni["name"] == university.name)
        {
            uni = universityJson;
            found = false;
            break;
        }
    }

    // Add new university if not found
    if (found)
    {
        universityArray.push_back(universityJson);
    }

    // Write data to the file
    fstream outputFile(filename, ios::out);
    if (!outputFile)
    {
        cout << "Error file is not opened " << filename << endl;
        return;
    }

    outputFile << universityArray.dump(4);
    outputFile.close();
}

void addClassroomToUniversity(University &university, const Classroom &classroom)
{
    // Regrowing the array using DMA
    Classroom *temp = new Classroom[university.numClassrooms + 1];

    // copying the data into temp
    for (int i = 0; i < university.numClassrooms; i++)
    {
        temp[i] = university.classrooms[i];
    }

    // put the current classroom in the last
    temp[university.numClassrooms] = classroom;

    // deleting the previous memory
    delete[] university.classrooms;

    // updating the array
    university.classrooms = temp;

    // incrementing the classrooms
    university.numClassrooms++;
}

void addStudentToClassroom(Classroom &classroom, const Student &student)
{
    // setting the size at runtime
    Student *temp = new Student[classroom.numStudents + 1];

    // copying data into temp
    for (int i = 0; i < classroom.numStudents; i++)
    {
        temp[i] = classroom.students[i];
    }

    // adding the new student at the last
    temp[classroom.numStudents] = student;

    // delete the previous memory
    delete[] classroom.students;

    // updating the array
    classroom.students = temp;

    // incrementing the students
    classroom.numStudents++;
}

void addCourseToStudent(Student &student, const Course &course)
{
    Course *temp = new Course[student.numCourses + 1];
    // course and grade are directlty proportional
    GradeReport *tempGrades = new GradeReport[student.numCourses + 1];
    // copy the previous data
    for (int i = 0; i < student.numCourses; i++)
    {
        temp[i] = student.courses[i];
        tempGrades[i] = student.gradeReport[i];
    }

    // adding the cuurent data to the right
    temp[student.numCourses] = course;
    tempGrades[student.numCourses].courseCode = course.courseCode;
    tempGrades[student.numCourses].grade = 0.0;

    // deleting the previous memory
    delete[] student.courses;
    delete[] student.gradeReport;

    // updating the memory
    student.courses = temp;
    student.gradeReport = tempGrades;
    student.numCourses++;
}

void addGrade(Student &student, const string &code, const float grade)
{
    for (int i = 0; i < student.numCourses; i++)
    {
        // if matches then
        if (student.courses[i].courseCode == code)
        {
            // assigning the grade
            student.gradeReport[i].courseCode = code;
            student.gradeReport[i].grade = grade;
            return;
        }
    }
    cout << "Course not found for this student." << endl;
}

Student *highestAchiever(Classroom &classroom)
{
    // if no students in the classroom
    if (classroom.numStudents == 0)
    {
        return nullptr;
    }

    // making it a pointer because of return type
    Student *highestStudent = nullptr;
    float highestAverage = 0;

    for (int i = 0; i < classroom.numStudents; i++)
    {
        // as only pointer stores memeory address
        Student *student = &classroom.students[i];

        // Skip students with no courses
        if (student->numCourses == 0)
        {
            continue;
        }

        // important results
        float totalGrade = 0.0;
        int numCourses = 0;

        // traversing through each student course grades
        for (int j = 0; j < student->numCourses; j++)
        {
            totalGrade += student->gradeReport[j].grade;
            numCourses++;
        }

        // calculation of average
        float average;
        if (numCourses > 0)
        {
            average = totalGrade / numCourses;
        }
        else
        {
            average = 0.0;
        }

        // if currrent average is greater more then current highest student
        if (average > highestAverage)
        {
            // updating the checks
            highestAverage = average;
            // current student becomes highest
            highestStudent = student;
        }
    }

    return highestStudent;
}

Student *mostCourses(Classroom &classroom)
{
    // if classroom is empty
    if (classroom.numStudents == 0)
    {
        return nullptr;
    }

    // making a pointer because of return type
    Student *busyStudent = nullptr;
    int maxCourses = 0;

    // traversing through classroom
    for (int i = 0; i < classroom.numStudents; i++)
    {
        // checking each student num courses
        if (classroom.students[i].numCourses > maxCourses)
        {
            // updating the values
            maxCourses = classroom.students[i].numCourses;
            busyStudent = &classroom.students[i];
        }
    }

    return busyStudent;
}

float universityAverageGrade(const University &university)
{
    // used to store the results
    float totalSum = 0.0;
    int totalGrades = 0;

    // traversing through the university classrooms
    for (int i = 0; i < university.numClassrooms; i++)
    {
        // Loop through each student in the classroom
        for (int j = 0; j < university.classrooms[i].numStudents; j++)
        {
            // Loop through each grade report of the student
            for (int k = 0; k < university.classrooms[i].students[j].numCourses; k++)
            {
                totalSum += university.classrooms[i].students[j].gradeReport[k].grade;
                totalGrades++;
            }
        }
    }
    // If no grades exist
    if (totalGrades == 0)
        return 0.0;

    // Calculate and return the average grade
    return totalSum / totalGrades;
}

void displayUniversityDetails(const University &university)
{
    // Display university details
    cout << "University Name: " << university.name << endl;
    cout << "Number of Classrooms: " << university.numClassrooms << endl;

    // Check if there are no classrooms
    if (university.numClassrooms == 0)
    {
        cout << "No classrooms available.\n";
        return;
    }

    // Traversing through university classrooms
    for (int i = 0; i < university.numClassrooms; i++)
    {
        cout << "\n========== Classroom " << i + 1 << " ==========\n";

        // Check if the classroom has no students
        if (university.classrooms[i].numStudents == 0)
        {
            cout << "No students in this classroom.\n";
            continue;
        }

        // Traversing through classroom students
        for (int j = 0; j < university.classrooms[i].numStudents; j++)
        {
            cout << "\nStudent Name  : " << university.classrooms[i].students[j].firstName
                 << " " << university.classrooms[i].students[j].lastName << endl;
            cout << "Student ID    : " << university.classrooms[i].students[j].studentId << endl;
            cout << "Courses Enrolled:\n";

            // Traversing through student courses
            for (int k = 0; k < university.classrooms[i].students[j].numCourses; k++)
            {
                cout << "  " << k + 1 << ". " << university.classrooms[i].students[j].courses[k].courseName << endl;
            }

            // Display Grade Report only if grades exist
            if (university.classrooms[i].students[j].numCourses > 0)
            {
                cout << "Grade Report:\n";
                for (int m = 0; m < university.classrooms[i].students[j].numCourses; m++)
                {
                    cout << "  Course " << m + 1 << " Grade: "
                         << university.classrooms[i].students[j].gradeReport[m].grade << endl;
                }
            }
            else
            {
                cout << "No courses enrolled, so no grades available.\n";
            }
        }
    }
}

void removeStudentFromClassroom(Classroom &classroom, int studentId)
{
    bool found = true;
    int index = 0;

    // traversing the classroom
    for (int i = 0; i < classroom.numStudents; i++)
    {
        // checking the student ID
        if (classroom.students[i].studentId == studentId)
        {
            index = i;
            found = false;
            break;
        }
    }

    // If student is not found
    if (found)
    {
        cout << "No student with this ID exists..." << endl;
        return;
    }

    // Create a new array with one less student
    Student *temp = new Student[classroom.numStudents - 1];

    // Copy elements before the removed student
    for (int i = 0; i < index; i++)
    {
        temp[i] = classroom.students[i];
    }

    // Copy elements after the removed student
    for (int i = index; i < classroom.numStudents - 1; i++)
    {
        temp[i] = classroom.students[i + 1];
    }
    // delete previous memory
    delete[] classroom.students;

    // Update students array and count
    classroom.students = temp;
    classroom.numStudents--;
}

void removeClassroomFromUniversity(University &university, int classroomId)
{
    bool found = true;
    int index = 0;

    // traversing through classrooms
    for (int i = 0; i < university.numClassrooms; i++)
    {
        // checking classroom id
        if (university.classrooms[i].classroomId == classroomId)
        {
            index = i;
            found = false;
            break;
        }
    }

    // If classroom is not found
    if (found)
    {
        cout << "No classroom with this ID exists..." << endl;
        return;
    }

    // Create a new array with one less element
    Classroom *temp = new Classroom[university.numClassrooms - 1];

    // copy elements befor the removed one
    for (int i = 0; i < index; i++)
    {
        temp[i] = university.classrooms[i];
    }

    // Copy elements before the removed oen
    for (int i = index; i < university.numClassrooms - 1; i++)
    {

        temp[i] = university.classrooms[i + 1];
    }

    // delete previous memory
    delete[] university.classrooms;

    // Update classrooms array and count
    university.classrooms = temp;
    university.numClassrooms--;
}

void removeCourseFromStudent(Student &student, const string &courseCode)
{
    if (student.numCourses == 0)
    {
        return;
    }

    bool found = false;
    int index = 0;

    // traversing through courses
    for (int i = 0; i < student.numCourses; i++)
    {
        if (student.courses[i].courseCode == courseCode)
        {
            index = i;
            found = true;
            break;
        }
    }

    // If course is not found
    if (!found)
    {
        cout << "No course with this ID exists..." << endl;
        return;
    }

    // Create a new array with one less course
    Course *temp = new Course[student.numCourses - 1];

    // copy element before the removed one
    for (int i = 0; i < index; i++)
    {
        temp[i] = student.courses[i];
    }

    // Copy elements after the removed one
    for (int i = index; i < student.numCourses - 1; i++)
    {

        temp[i] = student.courses[i + 1];
    }

    // delete previous memory
    delete[] student.courses;

    // Update courses array and count
    student.courses = temp;
    student.numCourses--;
}

void removeUniversityFromFile(const string &name, const string &filename)
{
    // file in read mode
    fstream inFile(filename, ios::in);

    // if file not opened
    if (!inFile)
    {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }

    // creating an object of jsaon
    json universities;

    // storing the data of file in the universities
    inFile >> universities;
    inFile.close();

    // checking if json file has this []
    if (!universities.is_array()) // Ensure valid format
    {
        cout << "Error: JSON format is incorrect!" << endl;
        return;
    }

    bool found = false;

    // Use `erase-remove_if` to safely remove elements
    auto newEnd = remove_if(universities.begin(), universities.end(),
                            [&](const json &uni)
                            { return uni["name"] == name; });

    if (newEnd != universities.end())
    {
        universities.erase(newEnd, universities.end());
        found = true;
    }

    if (!found)
    {
        cout << "No university with the name \"" << name << "\" found." << endl;
        return;
    }

    // Write the updated JSON back to the file
    ofstream outFile(filename);
    if (!outFile)
    {
        cout << "Error: Could not write to file " << filename << endl;
        return;
    }

    outFile << universities.dump(4);
    outFile.close();

    cout << "University \"" << name << "\" removed successfully." << endl;
}
