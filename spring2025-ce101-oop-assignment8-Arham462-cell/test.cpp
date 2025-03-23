#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions.h"

// Question 1: One-to-One Association - Person and Passport
TEST_CASE("Passport validity and Person association") {
    Passport passport("P12345", "2023-01-01", "2033-01-01");
    REQUIRE(passport.getPassportNumber() == "P12345");
    REQUIRE(passport.isValid() == true);
    
    Person person("John Doe", 30, &passport);
    REQUIRE(person.getName() == "John Doe");
    REQUIRE(person.hasValidPassport() == true);
}

// Question 2: One-to-Many Association - Doctor and Patients
TEST_CASE("Doctor-Patient assignment") {
    Doctor doctor("Dr. Smith", "Cardiology");
    Patient patient1("Alice", 25, &doctor);
    Patient patient2("Bob", 30, &doctor);
    
    doctor.addPatient(&patient1);
    doctor.addPatient(&patient2);
    
    REQUIRE(doctor.getPatientCount() == 2);
    REQUIRE(patient1.hasDoctor() == true);
    REQUIRE(patient2.hasDoctor() == true);
}
// Question 3: Many-to-Many Association - Students and Courses
TEST_CASE("Student-Course enrollment") {
    Student student("Charlie", 101);
    Course course("Math", 202);
    
    student.enrollCourse(&course);
    course.enrollStudent(&student);
    
    REQUIRE(student.isEnrolledInCourse(&course) == true);
    REQUIRE(course.getEnrollmentCount() == 1);
}

// Question 4: Multiple Associations - Teacher, Classroom, and Students
TEST_CASE("Teacher-Classroom and Classroom-Students Association") {
    Classroom classroom(1);
    Students student("David", 201);
    Teacher teacher("Mr. Johnson", &classroom);
    
    classroom.addStudent(&student);
    
    REQUIRE(classroom.getTotalStudents() == 1);
    REQUIRE(teacher.hasClassroom() == true);
    REQUIRE(student.isAssignedToClassroom(&classroom) == true);
}

// Question 5: Association with Different Roles - Company, Employees, and Projects
TEST_CASE("Company-Employees and Employees-Projects Association") {
    Company company("TechCorp");
    Project project("AI Development", 301);
    Employee employee("Emma", 401, &project);
    
    company.addEmployee(&employee);
    project.addEmployee(&employee);
    
    REQUIRE(company.getTotalEmployees() == 1);
    REQUIRE(employee.isAssignedToProject() == true);
    REQUIRE(project.getTotalEmployees() == 1);
}
