#include"functions.h"

int main()
{
    //checking the regular constructors
    Patient p1;
    p1.setName("Abdul");
    p1.setAge(23);
    p1.setMedicalHistory("Cancer");
    p1.setAdvice(true);
    //checking basic info
    Patient p2("ali",34);
    Patient p3("Last Stage");
    
    cout<<"Current Score of this Patient: "<<p1.getHealthScore()<<endl;
    

    if(p1.getAdvice()==true)
    {
        ++p1;
    cout<<"Patient followed the doctor's advice"<<endl;
        cout<<"Current Score of this Patient: "<<p1.getHealthScore()<<endl;
    }
    else
    {
        cout<<"Patient do not followed the doctor's advice"<<endl;
    }

   GeneralDoctors gd1;
   gd1.setName("Tahir");
   gd1.setCases("regular");
   gd1.checkingCasesType();

   Specialists s1;
   s1.setName("Arham");
   s1.setCases("critical");
   s1.checkingCasesType();
   
   Beds b;
   b.setFoarm("Molty");
   HospitalWard *h1 = new HospitalWard ;
   h1->setNumBeds(3);
   delete h1;
  // cout<<b.getFoarm();

  json j;
  j["Name"] = p1.getName();
  j["Age"] = p1.getAge();
  j[ "Health Socre"] = p1.getHealthScore();
  j["General Doctors"] = gd1.getName();
  j["Cases"] = gd1.getCases();
  j["Specialists"] = s1.getName();
  j["cases"] = s1.getCases();
  fstream file;
  file.open("Output.json",ios::out);
  file<<j.dump(4);
  file.close();

  file.open("Output.json",ios::in);
  file<<j;
  cout<<j.dump(4)<<endl;




   


   
   



   



}