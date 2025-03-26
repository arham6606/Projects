#include "functions.h"

// for person class
bool Person::operator+(const Person &other)
{
  if (preference == other.preference)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// for person class
void Person::operator++()
{
  bondScore = bondScore + 5;
}

// for person class
void Person::display()
{
  cout << "Name: " << name << endl;
  cout << "Age: " << age << endl;
  cout << "Bond Score: " << bondScore << endl;
  cout << "Prefernce: " << preference << endl;
  if (isMarried)
  {
    cout << "Married" << endl;
  }
  else
  {
    cout << "UnMarried" << endl;
  }
}

// for person class
void Person::findMatch()
{
  cout << "Person match finding" << endl;
}

// for basic person classs
void BasicPerson::findMatch()
{
  cout << "basic Person match finding" << endl;
}

// for permium person class
void PremiumPerson::findMatch()
{
  cout << "Premium Person match finding" << endl;
}

// for nikkah class
void Nikah::finalizeNikah()
{
  nikahStatus = true;
}

// for nikkah class
void Nikah::cancelNikah()
{
  nikahStatus = false;
}

// for marriage class
void Marriage::completeMarriage()
{
  nikah.finalizeNikah();
}

// for marriage burua class
void MarriageBureau::registerMarriage(Marriage *newMarriage)
{
  marriageCount++;
}

// for match making system class
void MatchMakingSystem::addBasicPerson(BasicPerson p)
{
  basicPeople[basicCount] = p;
  basicCount++;
}

// for match making system class
void MatchMakingSystem::addPremiumPerson(PremiumPerson p)
{
  premiumPeople[premiumCount] = p;
  premiumCount++;
}

// for match making system class
void MatchMakingSystem::removePerson(string name)
{
  // Handle basic people removal
  for (int i = 0; i < basicCount; i++)
  {
    if (basicPeople[i].getName() == name)
    {
      // Shift remaining elements left
      for (int j = i; j < basicCount - 1; j++)
      {
        basicPeople[j] = basicPeople[j + 1];
      }
      basicCount--; // Reduce count after shifting
      i--;          // Re-check the current index (in case of consecutive matches)
    }
  }

  // Handle premium people removal
  for (int i = 0; i < premiumCount; i++)
  {
    if (premiumPeople[i].getName() == name)
    {
      // Shift remaining elements left
      for (int j = i; j < premiumCount - 1; j++)
      {
        premiumPeople[j] = premiumPeople[j + 1];
      }
      premiumCount--; // Reduce count after shifting
      i--;            // Re-check current index
    }
  }
}

// for match making system class
void MatchMakingSystem::increaseBond(string name1, string name2)
{
  // Handle basic people
  for (int i = 0; i < basicCount; i++)
  {
    if (basicPeople[i].getName() == name1 || basicPeople[i].getName() == name2)
    {
      ++basicPeople[i];
    }
  }

  // Handle premium people
  for (int i = 0; i < premiumCount; i++)
  {
    if (premiumPeople[i].getName() == name1 || premiumPeople[i].getName() == name2)
    {
      ++premiumPeople[i];
    }
  }
}

// for match making sytem class
Person *MatchMakingSystem::matchPeople(int &matchCount)
{
  static Person matches[100];
  matchCount = 0;

  // Basic to premium matching
  for (int i = 0; i < basicCount; i++)
  {
    for (int j = 0; j < premiumCount; j++)
    {
      if (basicPeople[i] + premiumPeople[j])
      {

        matches[matchCount++] = basicPeople[i];
        matches[matchCount++] = premiumPeople[j];
      }
    }
  }
  if (matchCount == 0)
  {
    return nullptr;
  }
  return matches;
}

// for match making system class
// for match making system class
void MatchMakingSystem::saveToFile()
{
  json j;

  // Save basic people
  for (int i = 0; i < basicCount; i++)
  {
    j["basicPeople"].push_back({{"name", basicPeople[i].getName()},
                                {"age", basicPeople[i].getAge()},
                                {"preference", basicPeople[i].getPreference()},
                                {"bondScore", basicPeople[i].getBondScore()},
                                {"isMarried", basicPeople[i].getMaritalStatus()}});
  }

  // Save premium people
  for (int i = 0; i < premiumCount; i++)
  {
    j["premiumPeople"].push_back({{"name", premiumPeople[i].getName()},
                                  {"age", premiumPeople[i].getAge()},
                                  {"preference", premiumPeople[i].getPreference()},
                                  {"bondScore", premiumPeople[i].getBondScore()},
                                  {"isMarried", premiumPeople[i].getMaritalStatus()}});
  }

  // Write JSON data to a file
  ofstream file("output.json");
  file << j.dump(4); // Pretty-print JSON with 4-space indentation
  file.close();

  cout << "Data saved successfully!" << endl;
}

// for match making system class
void MatchMakingSystem::loadFromFile()
{
  ifstream file("output.json");
  if (!file.is_open())
  {
    cout << "Failed to open file!" << endl;
    return;
  }

  json data;
  file >> data;

  // Load basic people
  basicCount = 0;
  for (const auto &person : data["basicPeople"])
  {
    BasicPerson bp(
        person["name"],
        person["age"],
        person["preference"],
        person["bondScore"],
        person["isMarried"]);
    addBasicPerson(bp);
  }

  // Load premium people
  premiumCount = 0;
  for (const auto &person : data["premiumPeople"])
  {
    PremiumPerson pp(
        person["name"],
        person["age"],
        person["preference"],
        person["bondScore"],
        person["isMarried"]);
    addPremiumPerson(pp);
  }

  file.close();
  cout << "Data loaded successfully!" << endl;
}
