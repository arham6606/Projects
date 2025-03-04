#include "functions.h"

int main()
{

    // creating the object of teacher
    Teacher t1;
    t1.setName("Sir Nadir Abbas");
    t1.setAge(40);
    t1.setSalary(3000);
    t1.setTeacherID("CE2025");
    t1.displaydata();
    t1.increaseSalary(10);
    cout << "Updated Salary: " << t1.getSalary() << endl;

    cout << endl;

    // creating the object of under graduate student
    UndergraduateStudent ugs1;
    ugs1.setName("Doctor Strange");
    ugs1.setAge(24);
    ugs1.setGPA(3.3);
    ugs1.setStudentID("BSCE24069");
    ugs1.setYearOfStudy(3);
    ugs1.displaydata();
    cout << "GPA Remarks: " << ugs1.getGPACategory() << endl;
    cout << "Student Type: " << ugs1.getYearGroup() << endl;
    if (ugs1.determineStudentType())
    {
        cout << "Student is eligible for scholarship" << endl;
    }
    else
    {
        cout << "Student is Ineligible for scholarship" << endl;
    }

    cout << endl;

    // creating the object of post graduate student
    PostgraduateStudent pgs1;
    pgs1.setName("Marcus Auralius");
    pgs1.setAge(26);
    pgs1.setGPA(3.6);
    pgs1.setStudentID("BSCE29089");
    if (pgs1.isEligibleForResearch())
    {
        pgs1.setResearchTopic("Chat-Gpt");
    }
    else
    {
        cout << "Not Eligible for research" << endl;
    }
    pgs1.displaydata();
    cout << "GPA Remarks: " << pgs1.getGPACategory() << endl;
    if (pgs1.determineStudentType())
    {
        cout << "Student is eligible for scholarship" << endl;
    }
    else
    {
        cout << "Student is Ineligible for scholarship" << endl;
    }

    cout << endl;

    // creating the object of teacher assistant
    TeachingAssistant ts1;
    ts1.setName("Cesar Roman");
    ts1.setAge(29);
    ts1.setGPA(1.6);
    ts1.setStudentID("BSCE26325");
    ts1.setSalary(1500);
    ts1.setTeacherID("CE20266");
    ts1.setHoursWorked(5);
    ts1.displaydata();
    ts1.increaseSalary(30);
    cout << "GPA Remarks: " << ts1.getGPACategory() << endl;
    cout << "Updated Salary: " << ts1.getSalary() << endl;
    cout << "Total Hours working in the given No of weeks: " << ts1.getTotalHours(5) << endl;

    cout << endl;

    // creating the object of assistant professor
    AssistantProfessor as1;
    as1.setName("Iron Man");
    as1.setAge(45);
    as1.setPublicationCount(60);
    as1.setSalary(80000);
    as1.setTeacherID("CE35232");
    as1.displaydata();
    as1.increaseSalary(30);
    cout << "Updated Salary: " << as1.getSalary() << endl;
    cout << "Bonus calculation: " << as1.calculateBonus() << endl;
}