#include "functions.h"

int main()
{
    // code to check the first test case
    cout << endl;

    Person p1;
    p1.setName("Arham");
    p1.setAge(20);
    p1.setBondScore(10);
    p1.setPreference("Educated");
    p1.setMaritalStatus(false);
    p1.display();
    ++p1;
    cout << "Updated Bond Score: " << p1.getBondScore() << endl;
    Person p2;
    p2.setPreference("Educated");
    if (p1 + p2)
    {
        cout << "Prefernce is matched" << endl;
    }
    else
    {
        cout << "Prefernce is not matched" << endl;
    }

    // code for the second test case

    cout << endl;
    BasicPerson bp("John", 28, "Funny", 5, false);
    PremiumPerson pp("Emma", 26, "Intelligent", 8, false);
    bp.findMatch();
    pp.findMatch();

    // code for third test case

    cout << endl;
    Nikah n(5000, "Ali", "Ahmed");
    cout << "Mahr: " << n.getMahr() << endl;
    cout << "Witness 1: " << n.getWitness(0) << endl;
    cout << "Witness 2: " << n.getWitness(1) << endl;
    n.finalizeNikah();
    if (n.isNikahFinalized())
    {
        cout << "Nikkafied" << endl;
    }
    else
    {
        cout << "Sorry,Better luck next time" << endl;
    }

    // code for the fourth test case

    cout << endl;
    Person groom("Omar", 32, "Caring", 15, false);
    Person bride("Aisha", 29, "Loving", 12, false);
    Nikah nikah(10000, "Bilal", "Zaid");
    nikah.finalizeNikah();
    Marriage m(&groom, &bride, nikah);
    cout << "Groom Name: " << m.getGroom()->getName() << endl;
    cout << "Bride Name: " << m.getBride()->getName() << endl;
    m.completeMarriage();
    if (m.getNikah().isNikahFinalized() == true)
    {
        cout << "Nikkafied" << endl;
    }
    else
    {
        cout << "Better luck next time" << endl;
    }

    // code to check the fifth text case

    cout << endl;
    MarriageBureau bureau;
    bureau.registerMarriage(&m);
    cout << "Marraige Count: " << bureau.getMarriageCount() << endl;
    Person groom1("Khalid", 35, "Supportive", 20, false);
    Person bride1("Hina", 27, "Loyal", 18, false);
    Nikah nikah1(15000, "Faisal", "Hamza");
    Marriage marriage(&groom1, &bride1, nikah1);
    bureau.registerMarriage(&marriage);
    cout << "Marraige Count: " << bureau.getMarriageCount() << endl;

    cout << endl;

    // code to check the 6 test case
/*
    MatchMakingSystem system;

    // Add some BasicPerson and PremiumPerson objects
    BasicPerson bp1("Adam", 30, "Kind", 7, false);
    PremiumPerson pp1("Sara", 29, "Funny", 10, false);

    system.addBasicPerson(bp1);
    system.addPremiumPerson(pp1);

    // Show initial data
    cout << "Basic People Count: " << system.getBasicCount() << endl;
    cout << "Premium People Count: " << system.getPremiumCount() << endl;

    // Increase bond between Adam and Sara
    cout << "\nIncreasing Bond between Adam and Sara..." << endl;
    system.increaseBond("Adam", "Sara");

    // Test matching system
    int matchCount = 0;
    Person *matches = system.matchPeople(matchCount);

    if (matches == nullptr)
    {
        cout << "No matches found." << endl;
    }
    else
    {
        cout << "Match found! Total pairs: " << matchCount / 2 << endl;
    }

    // Remove Adam and check counts
    cout << "\nRemoving Adam..." << endl;
    system.removePerson("Adam");
    cout << "Basic People Count after removal: " << system.getBasicCount() << endl;

    // Save and reload data to check file I/O
    cout << "\nSaving data to file..." << endl;
    system.saveToFile();

    cout << "Reloading data from file..." << endl;
    MatchMakingSystem loadedSystem;
    loadedSystem.loadFromFile();

    cout << "Loaded Basic People Count: " << loadedSystem.getBasicCount() << endl;
    cout << "Loaded Premium People Count: " << loadedSystem.getPremiumCount() << endl;
*/
}