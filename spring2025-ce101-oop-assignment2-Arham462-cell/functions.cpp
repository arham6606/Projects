#include "functions.h"

Project *listEmployeeProjects(Employee &employee)
{
    // first we will filter the projects which status are true
    int count = 0;
    for (int i = 0; i < employee.numProjects; i++)
    {
        if (employee.projects[i].status == true)
        {
            count++;
        }
    }

    if (count == 0)
    {
        return nullptr;
    }

    // this array is used to store the active projects list
    Project *pro = new Project[count];
    int index = 0;
    // this is will put the active projects in the newly created array
    for (int i = 0; i < employee.numProjects; i++)
    {
        if (employee.projects[i].status == true)
        {
            pro[index] = employee.projects[i];
            index++;
        }
    }

    return pro;
}

Employee findTopPerformer(const Company &company)
{
    // if there is no employee in the companey
    if (company.numEmployees == 0)
    {
        return Employee();
    }
    // object of Employee struct
    Employee best;
    // making the first employee the top performer in the starting
    best = company.employees[0];
    float max = company.employees[0].performance.rating;
    // checking the top performer in the companey
    for (int i = 1; i < company.numEmployees; i++)
    {

        if (company.employees[i].performance.rating > max)
        {
            max = company.employees[i].performance.rating;
            best = company.employees[i];
        }
    }

    return best;
}

int countActiveProjects(const Company &company)
{
    // keeping track of active projects
    int count = 0;
    // nested loop for counting the active projects
    for (int i = 0; i < company.numEmployees; i++)
    {
        for (int j = 0; j <= company.employees[i].numProjects; j++)
        {
            if (company.employees[i].projects[j].status == true)
            {
                count++;
            }
        }
    }
    return count;
}

void removeEmployee(Company &company, int empId)
{
    // No employees to remove
    if (company.numEmployees == 0)
        return;

    int index = -1;

    // Find the employee with the given empId
    for (int i = 0; i < company.numEmployees; i++)
    {
        if (company.employees[i].empId == empId)
        {
            index = i;
            break;
        }
    }

    // If employee not found, return
    if (index == -1)
        return;

    // Shift employees left to overwrite the removed employee
    for (int i = index; i < company.numEmployees - 1; i++)
    {
        company.employees[i] = company.employees[i + 1];
    }

    // Decrease the number of employees
    company.numEmployees--;
    cout<<"Employee Removed Successfully"<<endl;
}

bool searchEmployee(Company &company, int empId)
{
    for(int i = 0 ; i<company.numEmployees;i++)
    {
        if(company.employees[i].empId==empId)
        {
            return true;
        }
    }
    return false;
}





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
    Employee *newEmployees = new Employee[company.numEmployees + 1];

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