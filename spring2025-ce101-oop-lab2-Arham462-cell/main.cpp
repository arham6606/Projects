#include "functions.h"

int main()
{
    Project p1(23, "Student Management System", true);
    Project p2(26, "University Management System", true);
    Performance pp1(56.7, "good");
    Employee e1(1, "Arham", "DSA", pp1);
    Company c1("DeepSeek");
    assignProject(e1, p1);
    evaluatePerformance(e1, pp1);
    string dep;
    int count = 0;
    cout << "Enter the department:";
    getline(cin, dep);
    Employee *retrieve = getEmployeesByDepartment(c1, count, dep);
    
    int empId;
    cout << "Enter the Employer ID you want to remove:";
    cin >> empId;
   
    int empId2;
    cout << "Enter the Employer ID you want to search:";
    cin >> empId2;
    
    addEmployee(c1, e1);
    
    delete[] retrieve;
    /*
     */
}