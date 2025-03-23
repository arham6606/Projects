#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions.h"

// Question 1: Composition - Computer and Processor
TEST_CASE("Computer and Processor Composition") {
    Computer comp;
    comp.setModel("Gaming PC");
    comp.setProcessor("Intel", 8);
    
    REQUIRE(comp.getModel() == "Gaming PC");
    REQUIRE(comp.getProcessor().getBrand() == "Intel");
    REQUIRE(comp.getProcessor().getCores() == 8);
    REQUIRE(comp.isGamingComputer() == true);
}
// Question 2: Aggregation - University and Professors
TEST_CASE("University and Professors Aggregation") {
    University uni;
    Professor prof1, prof2;
    
    prof1.setName("Dr. Smith");
    prof1.setSubject("Mathematics");
    prof2.setName("Dr. John");
    prof2.setSubject("Physics");
    
    uni.addProfessor(&prof1);
    uni.addProfessor(&prof2);
    
    REQUIRE(uni.countProfessors() == 2);
    REQUIRE(uni.getProfessor(0)->getName() == "Dr. Smith");
    REQUIRE(uni.getProfessor(1)->teachesSubject("Physics") == true);
}

// Question 3: Aggregation - Hospital, Doctors, and Patients
TEST_CASE("Hospital, Doctors, and Patients Aggregation") {
    Hospital hospital;
    Doctor doc;
    Patient pat;
    
    doc.setName("Dr. Adams");
    doc.setSpecialization("Cardiology");
    pat.setName("Alice");
    pat.setAge(25);
    
    doc.assignPatient(&pat);
    hospital.addDoctor(&doc);
    
    REQUIRE(hospital.countDoctors() == 1);
    REQUIRE(hospital.getDoctor(0)->countPatients() == 1);
    REQUIRE(hospital.getDoctor(0)->getPatient(0)->getName() == "Alice");
}

// Question 4: Composition - Music Album and Songs
TEST_CASE("Music Album and Songs Composition") {
    MusicAlbum album;
    album.setAlbumName("Greatest Hits");
    album.addSong("Song A", 4.5);
    album.addSong("Song B", 6.0);
    
    REQUIRE(album.getAlbumName() == "Greatest Hits");
    REQUIRE(album.countSongs() == 2);
    REQUIRE(album.getSong(1).isLongSong() == true);
}

// Question 5: Composition - Restaurant, Menu, and Dish
TEST_CASE("Restaurant, Menu, and Dish Composition") {
    Restaurant restaurant;
    restaurant.setRestaurantName("Fine Dining");
    restaurant.setMenu("Steak", 25.0);
    restaurant.setMenu("Salad", 10.0);
    
    REQUIRE(restaurant.getRestaurantName() == "Fine Dining");
    REQUIRE(restaurant.hasExpensiveDishes() == true);
}

