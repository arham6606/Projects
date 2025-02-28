#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h"

TEST_CASE("Test University Operations", "[university]") {
    // Define the filename to use for testing
    const string filename = "university.json";

    // Clean up any existing test data
    ofstream outFile(filename);
    outFile << "[]";  // Start with an empty array in the file
    outFile.close();

    University university("Test University");

    SECTION("Add a new university") {
        // Add the university to the file
        addNewUniversity(university, filename);

        ifstream inFile(filename);
        json universityData;
        inFile >> universityData;
        inFile.close();

        // Check if the university is in the file
        bool found = false;
        for (const auto& u : universityData) {
            if (u["name"] == "Test University") {
                found = true;
                break;
            }
        }
        REQUIRE(found == true);
    }

    SECTION("Update an existing university") {
        university.numClassrooms = 2;
        addNewUniversity(university, filename);

        ifstream inFile(filename);
        json universityData;
        inFile >> universityData;
        inFile.close();

        bool found = false;
        for (auto& u : universityData) {
            if (u["name"] == "Test University") {
                found = true;
                REQUIRE(u["numClassrooms"] == 2);
                break;
            }
        }
        REQUIRE(found == true);
    }

    SECTION("Remove a university") {
        removeUniversityFromFile("Test University", filename);

        ifstream inFile(filename);
        json universityData;
        inFile >> universityData;
        inFile.close();

        bool found = false;
        for (const auto& u : universityData) {
            if (u["name"] == "Test University") {
                found = true;
                break;
            }
        }
        REQUIRE(found == false);
    }
}


TEST_CASE("Test Classroom Operations", "[classroom]") {
    University university("Test University");
    Classroom classroom1(101);
    Classroom classroom2(102);

    // Add classrooms to the university
    addClassroomToUniversity(university, classroom1);
    addClassroomToUniversity(university, classroom2);

    SECTION("Add classrooms") {
        REQUIRE(university.numClassrooms == 2);
    }

    SECTION("Remove a classroom") {
        removeClassroomFromUniversity(university, 101);
        REQUIRE(university.numClassrooms == 1);

        // Ensure the classroom with ID 101 is removed
        REQUIRE(university.classrooms[0].classroomId == 102);
    }
}

TEST_CASE("Test Student Operations", "[student]") {
    Classroom classroom1(101);

    Address studentAddress("123 Main St", "City", "12345");
    Student student1(1, "John", "Doe", studentAddress);
    Student student2(2, "Jane", "Smith", studentAddress);

    addStudentToClassroom(classroom1, student1);
    addStudentToClassroom(classroom1, student2);

    SECTION("Add students to a classroom") {
        REQUIRE(classroom1.numStudents == 2);
    }

    SECTION("Remove a student from a classroom") {
        removeStudentFromClassroom(classroom1, 1);
        REQUIRE(classroom1.numStudents == 1);
        REQUIRE(classroom1.students[0].studentId == 2);  // Ensure only student 2 remains
    }
}

TEST_CASE("Test Course Operations", "[course]") {
    Address teacherAddress("456 Elm St", "Town", "67890");
    Address studentAddress("123 Main St", "City", "12345");
    Teacher teacher1(1, "Dr. Smith", "Williams", teacherAddress);
    Course course1("CS101", "Computer Science", 3, teacher1);

    Student student1(1, "John", "Doe", studentAddress);
    addCourseToStudent(student1, course1);

    SECTION("Add a course to a student") {
        REQUIRE(student1.numCourses == 1);
        REQUIRE(student1.courses[0].courseCode == "CS101");
    }

    SECTION("Remove a course from a student") {
        removeCourseFromStudent(student1, "CS101");
        REQUIRE(student1.numCourses == 0);
    }
}

TEST_CASE("Find the highest achiever in a classroom", "[classroom]") {
    Classroom classroom(101);

    // Create some students with different grades
    Address studentAddress("123 Main St", "City", "12345");
    Student student1(1, "John", "Doe", studentAddress);
    Student student2(2, "Jane", "Smith", studentAddress);
    Student student3(3, "Alice", "Johnson", studentAddress);

    // Add courses to students
    Course course1("CS101", "Computer Science", 3, Teacher(1, "Dr. Smith", "Williams", studentAddress));
    addCourseToStudent(student1, course1);
    addCourseToStudent(student2, course1);
    addCourseToStudent(student3, course1);

    // Add grades for the courses
    addGrade(student1, "CS101", 90);  // John
    addGrade(student2, "CS101", 85);  // Jane
    addGrade(student3, "CS101", 95);  // Alice

    // Add students to the classroom
    addStudentToClassroom(classroom, student1);
    addStudentToClassroom(classroom, student2);
    addStudentToClassroom(classroom, student3);

    // Find the highest achiever
    Student* topStudent = highestAchiever(classroom);

    SECTION("Test highest achiever") {
        REQUIRE(topStudent != nullptr);
        REQUIRE(topStudent->firstName == "Alice");
        REQUIRE(topStudent->lastName == "Johnson");
        REQUIRE(topStudent->gradeReport[0].grade == 95);
    }

    SECTION("Test with no students in the classroom") {
        Classroom emptyClassroom(102); // No students
        topStudent = highestAchiever(emptyClassroom);
        REQUIRE(topStudent == nullptr);
    }
}

TEST_CASE("Find the student with the most courses in a classroom", "[classroom]") {
    Classroom classroom(101);

    Address studentAddress("123 Main St", "City", "12345");
    Student student1(1, "John", "Doe", studentAddress);
    Student student2(2, "Jane", "Smith", studentAddress);
    Student student3(3, "Alice", "Johnson", studentAddress);

    // Add courses to students
    Course course1("CS101", "Computer Science", 3, Teacher(1, "Dr. Smith", "Williams", studentAddress));
    addCourseToStudent(student1, course1);
    addCourseToStudent(student2, course1);
    addCourseToStudent(student3, course1);

    Course course2("CS102", "Calculus", 3, Teacher(2, "Dr. Johnson", "Miller", studentAddress));
    addCourseToStudent(student2, course2);

    // Add students to the classroom
    addStudentToClassroom(classroom, student1);
    addStudentToClassroom(classroom, student2);
    addStudentToClassroom(classroom, student3);

    // Test most enrolled student
    Student* mostEnrolledStudent = mostCourses(classroom);

    SECTION("Test student with most courses") {
        REQUIRE(mostEnrolledStudent != nullptr);
        REQUIRE(mostEnrolledStudent->firstName == "Jane");
        REQUIRE(mostEnrolledStudent->numCourses == 2);  // Jane has 2 courses
    }

    SECTION("Test with no students in the classroom") {
        Classroom emptyClassroom(102);  // No students
        mostEnrolledStudent = mostCourses(emptyClassroom);
        REQUIRE(mostEnrolledStudent == nullptr);
    }
}


TEST_CASE("Calculate the average grade of the university", "[university]") {
    University university("Test University");
    Classroom classroom1(101);

    Address studentAddress("123 Main St", "City", "12345");
    Student student1(1, "John", "Doe", studentAddress);
    Student student2(2, "Jane", "Smith", studentAddress);
    Student student3(3, "Alice", "Johnson", studentAddress);

    // Add courses to students
    Course course1("CS101", "Computer Science", 3, Teacher(1, "Dr. Smith", "Williams", studentAddress));
    addCourseToStudent(student1, course1);
    addCourseToStudent(student2, course1);
    addCourseToStudent(student3, course1);

    Course course2("CE102", "Calculus", 3, Teacher(1, "Dr. Smith", "Williams", studentAddress));
    addCourseToStudent(student1, course2);
    addCourseToStudent(student2, course2);
    addCourseToStudent(student3, course2);


    // Add students to the classroom
    addStudentToClassroom(classroom1, student1);
    addStudentToClassroom(classroom1, student2);
    addStudentToClassroom(classroom1, student3);

    addClassroomToUniversity(university, classroom1);

    addGrade(student1, "CS101", 90);
    addGrade(student2, "CS101", 80);
    addGrade(student3, "CS101", 70);

    addGrade(student1, "CE102", 20);
    addGrade(student2, "CE102", 10);
    addGrade(student3, "CE102", 50);

    float avg = universityAverageGrade(university);

    SECTION("Calculate university average grade") {
        float avg = universityAverageGrade(university);
        REQUIRE(avg == Approx(53.33).epsilon(0.1));
    }

    SECTION("Test university average grade with no students") {
        University emptyUniversity("Empty University");
        emptyUniversity.numClassrooms = 0;
        float avg = universityAverageGrade(emptyUniversity);
        REQUIRE(avg == 0.0f);
    }

    SECTION("Test university average grade with no courses or grades") {
        University emptyUniversity("Empty University");
        Classroom classroom2(102);
        emptyUniversity.classrooms = new Classroom[1]{classroom2};
        emptyUniversity.numClassrooms = 1;

        Student student3(3, "Bob", "Brown", studentAddress);
        addStudentToClassroom(classroom2, student3);

        float avg = universityAverageGrade(emptyUniversity);
        REQUIRE(avg == 0.0f);  // No grades, so average should be 0
    }
}

