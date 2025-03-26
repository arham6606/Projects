#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions.h"

TEST_CASE("Person Class Tests")
{
    Person p("Alice", 30, "Kind", 10, false);
    REQUIRE(p.getName() == "Alice");
    REQUIRE(p.getAge() == 30);
    REQUIRE(p.getPreference() == "Kind");
    REQUIRE(p.getBondScore() == 10);
    REQUIRE(p.getMaritalStatus() == false);
}
TEST_CASE("BasicPerson and PremiumPerson Class Tests")
{
    BasicPerson bp("John", 28, "Funny", 5, false);
    PremiumPerson pp("Emma", 26, "Intelligent", 8, false);

    REQUIRE_NOTHROW(bp.findMatch());
    REQUIRE_NOTHROW(pp.findMatch());
}

TEST_CASE("Nikah Class Tests")
{
    Nikah n(5000, "Ali", "Ahmed");
    REQUIRE(n.getMahr() == 5000);
    REQUIRE(n.getWitness(0) == "Ali");
    REQUIRE(n.getWitness(1) == "Ahmed");

    n.finalizeNikah();
    REQUIRE(n.isNikahFinalized() == true);
}

TEST_CASE("Marriage Class Tests")
{
    Person groom("Omar", 32, "Caring", 15, false);
    Person bride("Aisha", 29, "Loving", 12, false);
    Nikah nikah(10000, "Bilal", "Zaid");
    nikah.finalizeNikah();

    Marriage m(&groom, &bride, nikah);

    REQUIRE(m.getGroom()->getName() == "Omar");
    REQUIRE(m.getBride()->getName() == "Aisha");

    m.completeMarriage();
    REQUIRE(m.getNikah().isNikahFinalized() == true);
}

TEST_CASE("MarriageBureau Class Tests")
{
    MarriageBureau bureau;
    REQUIRE(bureau.getMarriageCount() == 0);

    Person groom("Khalid", 35, "Supportive", 20, false);
    Person bride("Hina", 27, "Loyal", 18, false);
    Nikah nikah(15000, "Faisal", "Hamza");
    Marriage marriage(&groom, &bride, nikah);

    bureau.registerMarriage(&marriage);
    REQUIRE(bureau.getMarriageCount() == 1);
}

TEST_CASE("MatchMakingSystem Class Tests")
{
    MatchMakingSystem system;

    BasicPerson bp("Adam", 30, "Kind", 7, false);
    PremiumPerson pp("Sara", 29, "Funny", 10, false);

    system.addBasicPerson(bp);
    system.addPremiumPerson(pp);

    int matchCount = 0;
    REQUIRE(system.matchPeople(matchCount) == nullptr); // No matches expected initially

    system.increaseBond("Adam", "Sara");

    system.removePerson("Adam");
    REQUIRE(system.matchPeople(matchCount) == nullptr); // Ensure Adam is removed
}

TEST_CASE("MatchMakingSystem Save and Load Tests") {
    MatchMakingSystem system;

    // Create test data
    BasicPerson bp1("Adam", 30, "Kind", 7, false);
    BasicPerson bp2("Eve", 28, "Caring", 5, false);
    PremiumPerson pp1("Sara", 29, "Funny", 10, false);
    PremiumPerson pp2("David", 35, "Supportive", 8, false);

    // Add test data
    system.addBasicPerson(bp1);
    system.addBasicPerson(bp2);
    system.addPremiumPerson(pp1);
    system.addPremiumPerson(pp2);

    // Save the data
    system.saveToFile();

    // Create a new instance to test loading
    MatchMakingSystem loadedSystem;
    loadedSystem.loadFromFile();

    // Ensure the loaded data matches the original data
    REQUIRE(loadedSystem.getBasicCount() == 2);
    REQUIRE(loadedSystem.getPremiumCount() == 2);

    REQUIRE(loadedSystem.getBasicPeople()[0].getName() == "Adam");
    REQUIRE(loadedSystem.getBasicPeople()[0].getAge() == 30);
    REQUIRE(loadedSystem.getBasicPeople()[0].getPreference() == "Kind");
    REQUIRE(loadedSystem.getBasicPeople()[0].getBondScore() == 7);
    REQUIRE(loadedSystem.getBasicPeople()[0].getMaritalStatus() == false);

    REQUIRE(loadedSystem.getBasicPeople()[1].getName() == "Eve");
    REQUIRE(loadedSystem.getBasicPeople()[1].getAge() == 28);
    REQUIRE(loadedSystem.getBasicPeople()[1].getPreference() == "Caring");
    REQUIRE(loadedSystem.getBasicPeople()[1].getBondScore() == 5);
    REQUIRE(loadedSystem.getBasicPeople()[1].getMaritalStatus() == false);

    REQUIRE(loadedSystem.getPremiumPeople()[0].getName() == "Sara");
    REQUIRE(loadedSystem.getPremiumPeople()[0].getAge() == 29);
    REQUIRE(loadedSystem.getPremiumPeople()[0].getPreference() == "Funny");
    REQUIRE(loadedSystem.getPremiumPeople()[0].getBondScore() == 10);
    REQUIRE(loadedSystem.getPremiumPeople()[0].getMaritalStatus() == false);

    REQUIRE(loadedSystem.getPremiumPeople()[1].getName() == "David");
    REQUIRE(loadedSystem.getPremiumPeople()[1].getAge() == 35);
    REQUIRE(loadedSystem.getPremiumPeople()[1].getPreference() == "Supportive");
    REQUIRE(loadedSystem.getPremiumPeople()[1].getBondScore() == 8);
    REQUIRE(loadedSystem.getPremiumPeople()[1].getMaritalStatus() == false);
}
/*
*/