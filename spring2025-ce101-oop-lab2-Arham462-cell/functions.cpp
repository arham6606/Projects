#include "functions.h"

void assignProject(Employee &employee, const Project &project)
{
    // Step 1: Regrow the projects array
    Project *newProjects = new Project[employee.numProjects + 1]; // Create a new array with one more slot

    // Step 2: Copy old projects to the new array
    for (int i = 0; i < employee.numProjects; i++)
    {
        newProjects[i] = employee.projects[i];
    }

    // Step 3: Add the new project to the last slot
    newProjects[employee.numProjects] = project;

    // Step 4: Delete the old projects array to avoid memory leak
    delete[] employee.projects;

    // Step 5: Point the employee's projects to the new array
    employee.projects = newProjects;

    // Step 6: Increment the numProjects field
    employee.numProjects++;
}

void evaluatePerformance(Employee &employee, Performance &performance)
{
    employee.performance.rating = performance.rating;
    employee.performance.feedback = performance.feedback;
}

Employee *getEmployeesByDepartment(Company &company, int &count, string &department)
{


    for (int i = 0; i < company.numEmployees; i++)
    {
        if (company.employees[i].department == department)
        {
            count++;
        }
    }

    Employee *emp = new Employee[count];
    int index = 0;
    for (int i = 0; i < company.numEmployees; i++)
    {
        if (company.employees[i].department == department)
        {
            emp[index] = company.employees[i];
            index++;
        }
    }

    return emp;

}


void addEmployee(Company &company, Employee &employee)
{
     // Step 1: Create a new array with one extra space for the new employee
    Employee* newEmployees = new Employee[company.numEmployees + 1];

    // Step 2: Copy all existing employees into the new array
    for (int i = 0; i < company.numEmployees; i++)
    {
        newEmployees[i] = company.employees[i];
    }

    // Step 3: Add the new employee to the last position
    newEmployees[company.numEmployees] = employee;

    // Step 4: Delete the old employee array to avoid memory leak
    delete[] company.employees;

    // Step 5: Update the company to point to the new array
    company.employees = newEmployees;

    // Step 6: Increment the number of employees
    company.numEmployees++;
}