#include "functions.h"

int main()
{
  // creating object of passport
  Passport passport;
  passport.setPassportNumber("P12345");
  passport.setIssueDate("2043");
  passport.setExpiryDate("2033");

  cout << "Passport Number: " << passport.getPassportNumber() << endl;
  if (passport.isValid())
  {
    cout << "Passport is Valid" << endl;
  }
  else
  {
    cout << "Passport is not valid" << endl;
  }

  // creating object for person
  Person person;
  person.setName("John Doe");
  person.setAge(30);
  person.assignPassport(&passport);

  cout << "Name: " << person.getName() << endl;
  if (person.hasValidPassport())
  {
    cout << "The person Passport is valid" << endl;
  }
  else
  {
    cout << "The person Passport is not valid" << endl;
  }

  cout << endl;

  // creating object for doctor and patient
  Doctor doctor;
  doctor.setName("Dr. Smith");
  doctor.setSpecialization("Cardiology");

  Patient patient1;
  patient1.setName("Alice");
  patient1.setAge(25);
  patient1.assignDoctor(&doctor);

  Patient patient2;
  patient2.setName("Bob");
  patient2.setAge(30);
  patient2.assignDoctor(&doctor);

  doctor.addPatient(&patient1);
  doctor.addPatient(&patient2);
  cout << "Patient Count: " << doctor.getPatientCount() << endl;
  if (patient1.hasDoctor())
  {
    cout << "Doctor is assigned to patient" << endl;
  }
  else
  {
    cout << "Doctor is not assigned to patient" << endl;
  }

  cout << endl;

  // creating object for student
  Student s1;
  s1.setName("Charlie");
  s1.setID(101);

  // creating object for courses
  Course c1;
  c1.setTitle("Math");
  c1.setID(202);

  s1.enrollCourse(&c1);
  c1.enrollStudent(&s1);
  if (s1.isEnrolledInCourse(&c1) == true)
  {
    cout << "Student is enrolled in course" << endl;
  }
  else
  {
    cout << "Student not enrolled in course" << endl;
  }
  cout << "Enrollment of course:" << c1.getEnrollmentCount() << endl;

  cout << endl;

  // creating object for classroom
  Classroom cr1;
  cr1.setClassID(1);

  // creating object for student class
  Students s2;
  s2.setName("David");
  s2.setStudentID(201);

  // creating object for teacher
  Teacher t1;
  t1.setName("Mr.Johnson");
  t1.assignClassroom(&cr1);

  cr1.addStudent(&s2);
  cout << "Total Students in the classrooms: " << cr1.getTotalStudents() << endl;
  if (t1.hasClassroom() == true)
  {
    cout << "Classroom is assigned to teacher" << endl;
  }
  else
  {
    cout << "Classroom is NOT assigned to teacher" << endl;
  }

  if (s2.isAssignedToClassroom(&cr1) == true)
  {
    cout << "Student is enrolled in the class" << endl;
  }
  else
  {
    cout << "Student is enrolled in the class" << endl;
  }

  cout<<endl;

  //creating object for company
  Company cp1;
  cp1.setName("TechCorp");
  //creating object for project class
  Project pj1;
  pj1.setTitle("AI Development");
  pj1.setID(301);
  //creating object for employee class
  Employee el1;
  el1.setName("Emma");
  el1.setID(401);
  el1.assignProject(&pj1);

  cp1.addEmployee(&el1);
  pj1.addEmployee(&el1);
  cout<<"Total Employees in the Company: "<<cp1.getTotalEmployees()<<endl;

  if(el1.isAssignedToProject()==true)
  {
    cout<<"Employee is assigned project"<<endl;
  }
  else
  {
      cout<<"Employee is NOT assigned project"<<endl;
  }
  
  cout<<"Project working Employees: "<<pj1.getTotalEmployees()<<endl;

}
