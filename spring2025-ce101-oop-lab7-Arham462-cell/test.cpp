#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions.h"

TEST_CASE("Student eligibility for library") {
    Student s1, s2;
    s1.setId(1002);
    s2.setId(1003);
    REQUIRE(s1.isEligibleForLibrary() == true);
    REQUIRE(s2.isEligibleForLibrary() == false);
}

TEST_CASE("Library book borrowing with aggregation") {
    Student s;
    Library lib;
    s.setId(1002);
    lib.setIsBorrowed(false);
    s.setLibrary(&lib); // Set library for student
    REQUIRE(s.canBorrowBook() == true);
}

// Q2: Aggregation (Car and Engine Example)
TEST_CASE("Engine Performance Check") {
    Engine e1, e2;
    e1.setEngineType("V8");
    e2.setEngineType("Normal");
    REQUIRE(e1.isHighPerformance() == true);
    REQUIRE(e2.isHighPerformance() == false);
}

TEST_CASE("Car Sports Type Check") {
    Car car;
    Engine e;
    e.setEngineType("Turbo");
    car.setEngine(&e);
    REQUIRE(car.isSportsCar() == true);
}
// Q3: Composition (Building and Room Example)
TEST_CASE("Room Number Even Check") {
    Room r;
    r.setRoomNumber(102);
    REQUIRE(r.isEvenRoom() == true);
}

TEST_CASE("Building contains an even-numbered room") {
    Room rooms[3] = { Room(), Room(), Room() };
    rooms[0].setRoomNumber(101);
    rooms[1].setRoomNumber(102);
    rooms[2].setRoomNumber(103);
    Building b(rooms);
    REQUIRE(b.hasEvenRoom() == true);
}

// Q4: Association (Doctor and Patient Example)
TEST_CASE("Doctor-Patient Association") {
    Doctor d;
    Patient p;
    d.setName("Dr. Smith");
    p.setName("John Doe");
    d.addPatient(&p);
    p.addDoctor(&d);
    REQUIRE(d.hasPatient("John Doe") == true);
    REQUIRE(p.hasDoctor("Dr. Smith") == true);
}

