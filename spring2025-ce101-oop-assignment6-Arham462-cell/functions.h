#include <iostream>
using namespace std;
#include <string>
// header files

// creating class of person

class Person
{

private:
    // data properties

    string name;
    int age;

public:
    // constructors

    Person()
    {
        name = "Unknown";
        age = 0;
    }

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    // setter and getter functions

    string getName() const
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    int getAge() const
    {
        return age;
    }

    void setAge(int age)
    {
        this->age = age;
    }
};

// class of student inherits form person

class Student : virtual public Person
{

private:
    // data properties

    string studentID;
    double GPA;

public:
    // construcotrs

    Student()
    {
        studentID = "";
        GPA = 0;
    }

    Student(string name, int age, string studentID, double GPA)
        : Person(name, age)
    {
        this->studentID = studentID;
        this->GPA = GPA;
    }

    // getter and setter funtions

    string getStudentID() const
    {
        return studentID;
    }

    void setStudentID(string studentID)
    {
        this->studentID = studentID;
    }

    double getGPA() const
    {
        return GPA;
    }

    void setGPA(double GPA)
    {
        this->GPA = GPA;
    }

    // memebr function to display student dat
    void displaydata()
    {
        cout << "Student Name: " << this->getName() << endl;
        cout << "Student ID: " << this->getStudentID() << endl;
        cout << "Age: " << this->getAge() << endl;
        cout << "GPA: " << this->getGPA() << endl;
    }

    // memeber functon to display GPA category
    string getGPACategory()
    {
        if (this->GPA >= 3.7)
        {
            return "Excellent";
        }

        else if (this->GPA >= 3.0 && this->GPA <= 3.69)
        {
            return "Good";
        }

        else if (this->GPA >= 2.0 && this->GPA <= 2.99)
        {
            return "Average";
        }

        else
        {
            return "Poor";
        }
    }

    // memeber functions to check the eligibility criteria for scholarship
    bool determineStudentType()
    {
        if (this->GPA >= 3.5)
        {
            return true;
        }

        else
        {
            return false;
        }
    }
};

// creting the class of teacher inherits form person

class Teacher : virtual public Person
{

private:
    // data properties

    string teacherID;
    double salary;

public:
    // constructors

    Teacher()
    {
        teacherID = "";
        salary = 0;
    }

    Teacher(string name, int age, string teacherID, double salary)
        : Person(name, age)
    {
        this->teacherID = teacherID;
        this->salary = salary;
    }

    // getter and setter funcitons

    string getTeacherID() const
    {
        return teacherID;
    }

    void setTeacherID(string teacherID)
    {
        this->teacherID = teacherID;
    }

    double getSalary() const
    {
        return salary;
    }

    void setSalary(double salary)
    {
        this->salary = salary;
    }

    // memebr function to display teacher data
    void displaydata()
    {
        cout << "Teacher Name: " << this->getName() << endl;
        cout << "Teacher ID: " << this->getTeacherID() << endl;
        cout << "Age: " << this->getAge() << endl;
        cout << "Salary: " << this->getSalary() << "$" << endl;
    }

    // member function to increase the salary by a given percentage
    void increaseSalary(double percentage)
    {
        salary += salary * (percentage / 100.0);
    }
};

// creating the class of undergraduate student inherits form student

class UndergraduateStudent : public Student
{

private:
    // data properties

    int yearOfStudy;

public:
    // constructors

    UndergraduateStudent()
    {
        yearOfStudy = 0;
    }

    UndergraduateStudent(string name, int age, string studentID, double GPA, int yearOfStudy)
        : Student(name, age, studentID, GPA)
    {
        this->yearOfStudy = yearOfStudy;
    }

    // getter and setter functions

    int getYearOfStudy() const
    {
        return yearOfStudy;
    }

    void setYearOfStudy(int yearOfStudy)
    {
        this->yearOfStudy = yearOfStudy;
    }

    // memebr function to display student data
    void displaydata()
    {
        cout << "Student Name: " << this->getName() << endl;
        cout << "Student ID: " << this->getStudentID() << endl;
        cout << "Age: " << this->getAge() << endl;
        cout << "GPA: " << this->getGPA() << endl;
        cout << this->getYearOfStudy() << " Year" << endl;
    }

    // memeber function display student year
    string getYearGroup()
    {
        if (this->yearOfStudy == 1)
        {
            return "Freshman";
        }

        else if (this->yearOfStudy == 2)
        {
            return "Sophomore";
        }

        else if (yearOfStudy == 3)
        {
            return "Junior";
        }

        else if (yearOfStudy == 4)
        {
            return "Senior";
        }
        return "";
    }
};

// creating the class of postgraduates student inherits from studet

class PostgraduateStudent : public Student
{

private:
    // data properties

    string researchTopic;

public:
    // construtor

    PostgraduateStudent()
    {
        researchTopic = "";
    }

    PostgraduateStudent(string name, int age, string studentID, double GPA, string researchTopic)
        : Student(name, age, studentID, GPA)
    {
        this->researchTopic = researchTopic;
    }

    // getter and setter functions

    string getResearchTopic() const
    {
        return researchTopic;
    }

    void setResearchTopic(string researchTopic)
    {
        this->researchTopic = researchTopic;
    }

    // memebr function to display student data
    void displaydata()
    {
        cout << "Student Name: " << this->getName() << endl;
        cout << "Student ID: " << this->getStudentID() << endl;
        cout << "Age: " << this->getAge() << endl;
        cout << "GPA: " << this->getGPA() << endl;
        if (this->getGPA() > 3.5)
        {
            cout << "Research Topic: " << this->getResearchTopic() << endl;
        }
    }

    // member function to check the eligibiluty criteria
    bool isEligibleForResearch()
    {
        if (this->getGPA() > 3.5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// creating class of teacher assistant inherits form student and teacher

class TeachingAssistant : public Student, public Teacher
{

private:
    // data properties

    int hoursWorked;

public:
    // constructor

    TeachingAssistant()
    {
        hoursWorked = 0;
    }

    TeachingAssistant(string name, int age, string studentID, double GPA, string teacherID, double salary, int hoursWorked)
        : Person(name, age), Student(name, age, studentID, GPA), Teacher(name, age, teacherID, salary)
    {
        this->hoursWorked = hoursWorked;
    }

    // getter and setter functions

    int getHoursWorked() const
    {
        return hoursWorked;
    }

    void setHoursWorked(int hoursWorked)
    {
        this->hoursWorked = hoursWorked;
    }

    // memeber funciton to display data of teacher assistant
    void displaydata()
    {
        cout << "Student Name: " << this->getName() << endl;
        cout << "Student ID: " << this->getStudentID() << endl;
        cout << "Age: " << this->getAge() << endl;
        cout << "GPA: " << this->getGPA() << endl;
        cout << "Teacher ID: " << this->getTeacherID() << endl;
        cout << "Salary: " << this->getSalary() << "$" << endl;
        cout << "Hours worked: " << this->getHoursWorked() << endl;
    }

    // member funciton to count total working hours
    double getTotalHours(int weeks)
    {
        return this->hoursWorked * weeks;
    }
};

// creating class of assistant professor inherits form teacher

class AssistantProfessor : public Teacher
{

private:
    // data properties

    int publicationCount;

public:
    // construcotr

    AssistantProfessor()
    {
        publicationCount = 0;
    }

    AssistantProfessor(string name, int age, string teacherID, double salary, int publicationCount)
        : Teacher(name, age, teacherID, salary)
    {
        this->publicationCount = publicationCount;
    }

    // getter and setter funtions

    int getPublicationCount() const
    {
        return publicationCount;
    }

    void setPublicationCount(int publicationCount)
    {
        this->publicationCount = publicationCount;
    }

    // memebr function to display assistnant professor data
    void displaydata()
    {
        cout << "Assistant Professor Name: " << this->getName() << endl;
        cout << "Teacher ID: " << this->getTeacherID() << endl;
        cout << "Age: " << this->getAge() << endl;
        cout << "Salary: " << this->getSalary() << "$" << endl;
        cout << "Publications: " << this->publicationCount << endl;
    }

    // membe funtion for bonus calculation
    double calculateBonus()
    {
        if (this->publicationCount > 10)
        {
            return this->getSalary() * 0.10;
        }
        else
        {
            return this->getSalary() * 0.05;
        }
    }
};
