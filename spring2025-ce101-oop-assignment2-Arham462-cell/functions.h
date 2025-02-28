#include <iostream>
using namespace std;
#include <string>

//struct of projrct..
struct Project
{
    int projectId;
    string projectName;
    bool status;

    Project() : projectId(0), projectName(""), status(false) {}

    Project(int id, string name, bool status)
        : projectId(id), projectName(name), status(status) {}
};

//struct of performance

struct Performance
{
    float rating;
    string feedback;

    Performance() : rating(0.0), feedback("") {}

    Performance(float rating, string feedback)
        : rating(rating), feedback(feedback) {}
};

//struct of employee

struct Employee
{
    int empId;
    string name;
    string department;
    Project *projects;
    int numProjects;
    Performance performance;

    Employee()
        : empId(0), name(""), department(""),
          projects(nullptr), numProjects(0), performance() {}

    Employee(int id, string name, string department, Performance performance)
        : empId(id), name(name), department(department),
          performance(performance), projects(nullptr), numProjects(0) {}
};

//struct of companey

struct Company
{
    string name;
    int numEmployees;
    Employee *employees;

    Company() : name(""), numEmployees(0), employees(nullptr) {}

    Company(string name)
        : name(name), numEmployees(0), employees(nullptr) {}
};
//function declaration
Project *listEmployeeProjects(Employee &employee);
Employee findTopPerformer(const Company &company);
int countActiveProjects(const Company &company);
void removeEmployee(Company &company, int empId);
bool searchEmployee(Company &company, int empId);
void assignProject(Employee &employee, const Project &project);
void evaluatePerformance(Employee &employee, Performance &performance);
Employee *getEmployeesByDepartment(Company &company, int &count, string &department);
void addEmployee(Company &company, Employee &employee);
