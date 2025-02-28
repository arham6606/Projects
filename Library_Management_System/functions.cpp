#include"functions.h"
// making a file..
// the "file:is used for storing book names and ID used in void admin"
// the "temp:this file is a temporaray file used in void admin"
fstream file,temp;
// the "another:is used in bool student to store the roll number of students"
fstream another;
// the "storing:is used in void who for storing data of the students roll number who have 
// extracted a specifc book with the id"
// the "file2:is used in void admin to store the same data which is in "file" "
fstream storing,file2;
// the name of the file of "file"
string filename="project2.txt";
// these are global variables
string roll,idb;
//..................................................................................
void admin()
{
   // initaliazing a to 0
   int a=0 ;
   // some declarations are passsed here...
   string book;
   string id;
   string password;
   // this is the password set by the university for the liabray
   string pass = "123";
   // enter the admin password to log in
   cout<<"Enter the Admin Password:";
   getline(cin,password);
   cout<<"\n";
   //if it matches then process goes forward
   if (pass == password)
   { 
      quotes();
      cout<<"\n\nLogin Successfull....\n\n";
      // opening the file in output and apppend mode
      file.open(filename,ios::out|ios::app);
      file2.open("project21.txt",ios::out|ios::app);
      int number;
      // number of books to enter..
      cout<<"How many Books Do You Want To Enter:";
      // this loop is used for error handling..
      while(!(cin>>number))
      {
         // this is used to clear the flags
         //if we not use cin.clear() we can not do further processing
         cin.clear();
         // this line is used to ignore the characters
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
         cout<<"Please Enter An Integer:";
      }
      cout<<"you have Entered:"<<number<<endl;
      cout<<"Press Only Enter To Continue";
      cin.ignore();
      //for entering the books....
      while(a<=number)
      {
         // to run if the file is opened
      if (file.is_open())
      {
         cin.ignore();
         // inputting the bookn name and id...
      cout<<"Enter The Book Name: ";
      getline(cin,book);
      file<<book<<"*";
      file2<<book<<"*";
      cout<<"Enter Book Id: ";
      getline(cin,id);
      file<<id<<"\n";
      file2<<id<<"\n";
      cout<<"Press Only Enter To Continue";
      // for incrementing one in a;;;
      a++;
      }
      // if it matches then 
      if (a==number)
      {
         // giving user the choicee to add more books or can exit
         int choice;
         cout<<"\n\nPress '1' To Continue Adding Books\nPress '2' To Exit..\n";
         cout<<"Enter Your Choice:";
         cin>>choice;
         //if it matches then loop breaks..
         if (choice==2)
         {
            break;
         }
         else
         {
            //if not ask the user again to enter how many books...
            a=0;
            cin.ignore();
            cout<<"\nEnter The Number of Books You Want To Enter:";
            cin>>number;
            number;
            cin.ignore();
         }
      }
      }                                                                                                                               
   }
   // if passsword not matches then log in is failed
   else
   {
      cout<<"Login is Failed.....";
   }
   //closing the file is very important if not as it generates error
   file.close();
   file2.close();
}

//...........................................................................

void show()
{ //declaring the vaiables
   string r_book,r_id;
   //opening the file
   file.open(filename,ios::in);
   //if file is opened. then
   if (file.is_open())
   {
      // displaying input ont the screen
      cout<<setw(30)<<"Book"<<setw(30)<<"Id"<<endl;
      // reading one line at a time form the file..
      while(getline(file,r_book,'*')&&getline(file,r_id,'\n'))
      {
         //displaying the input on the screen
      cout<<setw(30)<<r_book<<setw(30)<<r_id<<endl;
      }
   }
   else
   {
      //if file is not opened
     cout<<"File Not Opened...";
   }
   //closing the file..
   file.close();
}

//...............................................................

void extract()
{   //this the functions call here written below
   if (student())
   {
   // we have opened both the files here/..
   file.open(filename,ios::in);
   temp.open("temp.txt",ios::out);
   // delarationg of string varaibles/..
   string line1,line2;
   //string idb;
   // user input of id of the book
   cout<<"Enter ID of The Book:";
   cin>>idb;
   // checking if both the files are opened
   if(!file.is_open()||!temp.is_open())
   {
        cout<<"Error Opening the Files."<<endl;
   }
   // seeting bool to false
   bool found  = false;
   //this loop checks the id is equal to line 2 which is the id,
   while(getline(file,line1,'*')&& getline(file,line2,'\n'))
   {
      //if it equals then show book is extracted..
      if (line2 == idb)
      {
         cout<<"The Book is Extracted.";
         found = true;
         break;
      }
   }
   
   if (found)
   {
      // these 2 line are used to reset the file from start to end.
      file.clear();
      file.seekg(0);
      string line;
// this loop used to fill up the second file,.
      while(getline(file,line1,'*')&&getline(file,line2,'\n'))
      {
         //2!=4 then it runs
         if (line2 != idb)
         {
            temp<<line1<<"*"<<line2<<"\n";
         }
      }
   }
   //if not book id is not found
   else
   {
      cout<<"Book ID not found"<<endl;
   }
    //closing the files
    file.close();
    temp.close();
    //"temp" and "file" only one will remain and one will be deleted
    remove(filename.c_str());
    rename("temp.txt",filename.c_str());
  }
  //if it is false 
  else
  {
   cout<<"Roll No Was Not Found.";
  }
}

//............................................................................

void quotes()
{
   //genrationg a random number from 1 to 5.
   int random;
   srand(static_cast<int>(time(0)));
   random = (rand() % 5) + 1 ;
   // in this if else statements we are just generating some quotes for library 
   if (random==1)
   {
      cout<<"\t\t\tThe Most Important Asset of Any Library goes Home at Night.";
   }
   else if(random==2)
   {
      cout<<"\t\t\tLibrarian Because Book Wizard isn't an Official Job Title.";
   }
   else if (random==3)
   {
      cout<<"\t\tLibrarian Don't Know Everything.They just Know how to find out everything.";
   }
   else if (random == 4)
   {
      cout<<"\t\t\tLibrarian are the Tour-Guides for all of Knowledge.";
   }
   else if (random==5)
   {
      cout<<"\t\t\tLibraries change lives for the better.";
   }
}

//....................................................................................

bool student()
{
   //check is for true and false
    bool check;
    //opening the file
    another.open("student.txt",ios::in);
    //declaring variables
    string check_roll,check_roll1;
    cout<<"Enter Your University Roll No:";
    getline(cin,roll);
    //this loop will convert lowercase into uppercase
    for (char&c:roll)
    {
      c = toupper(c);
    }
    //displaying with uppercase
    cout<<"Your Roll No is:"<<roll<<endl;
    //if file is open then
    if (another.is_open())
    {
      //reading the file 
    while(getline(another,check_roll,'.')&& getline(another,check_roll1,'\n'))
    {
       if ( check_roll == roll)
       { 
         check = true;
         break;
       }
       else
       {
          check = false;
       }
    }
    }
    else
    {
      cout<<"Error Opening file.";
    }
    if(check)
    {
      check =  true;
    }
    else
    {
      check =  false;
    }
    another.close();
    return check;
}

//..........................................................................................
void who(string roll,string idb)
{
   //opening the files
   another.open("student.txt",ios::in);
   file2.open("project21.txt",ios::in);
   //declaring the variables
   string check_roll,check_roll1;
   string check_idb,check_idb1;
   //opening the file
    storing.open("store.txt",ios::app);
    if(storing.is_open())
    {
      //reading the files
      while(getline(another,check_roll,'.')&&getline(another,check_roll1,'\n'))
      {
      if (check_roll == roll)
      {
         //writing this into storing file
      storing<<check_roll<<"*";
      }   
      }
     while(getline(file2,check_idb,'*')&&getline(file2,check_idb1,'\n'))
     {
      //same with this
        if (check_idb1 == idb)
        {
           storing<<check_idb1<<"\n";
        }
         }
    
    }
    else
    {
      cout<<"Error while opening file\n";
    }
    //closing the files...
storing.close();
another.close();
file2.close();
}