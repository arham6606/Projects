#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h"

using namespace std;

// Shared test cases: These are the main tests to validate core functionality

TEST_CASE("Project Initialization") {
    Project p1;
    REQUIRE(p1.projectId == 0);
    REQUIRE(p1.projectName == "");
    REQUIRE(p1.status == false);

    Project p2(1, "Project1", true);
    REQUIRE(p2.projectId == 1);
    REQUIRE(p2.projectName == "Project1");
    REQUIRE(p2.status == true);
}

TEST_CASE("Performance Initialization") {
    Performance perf1;
    REQUIRE(perf1.rating == 0);
    REQUIRE(perf1.feedback == "");

    Performance perf2(4.5, "Excellent performance");
    REQUIRE(perf2.rating == 4.5);
    REQUIRE(perf2.feedback == "Excellent performance");
}

TEST_CASE("Employee Initialization") {
    Performance perf(4.0, "Good performance");
    Employee emp1(101, "John Doe", "IT", perf);

    REQUIRE(emp1.empId == 101);
    REQUIRE(emp1.name == "John Doe");
    REQUIRE(emp1.department == "IT");
    REQUIRE(emp1.performance.rating == 4.0);
    REQUIRE(emp1.numProjects == 0);
}