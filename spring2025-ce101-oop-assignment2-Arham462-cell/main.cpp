#include "functions.h"

int main()
{
    while(true)
    {
     //for running the program until user wants
     int choice;
     cout<<"Enter -1 to terminate the program"<<endl;
     cout<<"Enter any other key to continue";
     cin>>choice;
     if(choice == -1)
     {
        break;
     }
    // objects of project struct
    Project pp1(23, "DeepSeek", true);
    Project pp2(25, "ChatGpt", true);
    Project pp3(23, "BlackBox", true);
    Project pp4(23, "GitHub Co-Piolt", true);
    Project pp5(23, "Perplexity", true);
    // object of performance struct
    Performance p1(8.6, "Very Good");
    Performance p2(8.0, "Very Good");
    // object of employee struct
    Employee e1(54, "Arham", "AI Development", p1);
    Employee e2(64, "Rashid", "AI Department", p2);

    // calling function
    assignProject(e1, pp1);
    assignProject(e1, pp2);
    assignProject(e1, pp3);
    assignProject(e2, pp4);
    assignProject(e2, pp5);

    // calling the function
    Project *pro = listEmployeeProjects(e1);
    // if no active projects of the employee
    if (pro == nullptr)
    {
        cout << "No Active Projects" << endl;
    }
    // for if there is an active project assigned to the employee
    else
    {

        for (int i = 0; i < e1.numProjects - 1; i++)
        {
            if (pro[i].status == true)
            {
                cout << "Name: " << pro[i].projectName << endl;
            }
        }
    }

    // object of companey struct
    Company c1("Open AI");

    // calling the function
    addEmployee(c1, e1);
    addEmployee(c1, e2);

    // calling the function
    Employee top = findTopPerformer(c1);
    // to display the top performer in the companey
    if (c1.numEmployees > 0)
    {
        cout << "The Top Performer is: " << top.name << endl;
    }
    // if there is no employee in the companey
    else
    {
        cout << "No employees in the companey" << endl;
    }
    // function calling
    int active = countActiveProjects(c1);
    cout << "The active projects in the companey are: " << active << endl;

    // this is for removing the employee
    int id;
    cout << "Enter the employee ID is: ";
    cin >> id;
    removeEmployee(c1, id);

    // this is for searching the employeee
    int id1;
    cout << "Enter the employee ID you want to search: ";
    cin >> id1;
    bool result;
    result = searchEmployee(c1, id1);
    if(result)
    {
        cout<<"Employee is present in the companey"<<endl;
    }
    else
    {
        cout<<"Employee is not present in the companey"<<endl;
    }
    // freeing the memory
    delete[] pro;
    
    }
}