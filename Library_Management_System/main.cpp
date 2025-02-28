// this is the header file
#include"functions.h"

int main()
{
while(true)
{
    // giving the user some choices....
    cout<<"...............................................................................";
    cout<<"\n'1' For Admin\n'2' For Show All Books\n'3' For Extract Books\n'4' For Exit\n";
    int choice;
    // enter the choice of your choosing
    cout<<"\nEnter Your Choice:";
    cin>>choice;
    cout<<"\n";
    // for admin block of code
    if (choice == 1)
    {
        // to delete spaces...
        cin.ignore();
        //fucntion calling
        admin();
        // this code used to clear console screen 
        // for better understanding
        this_thread::sleep_for(chrono::seconds(0));
        #if defined(_Win32)
        system("CLS");
        #else
        system("clear");
        #endif
    }
    // for showing the books to students
    else if (choice == 2)
    {
        //calling function
           cin.ignore();
           show();
    }
    // for extracting the books..
    else if (choice == 3)
    {
         cin.ignore();
         // calling funtion
         extract();
         cout<<"\n";
         // calling function
          who(roll,idb);
         // for clearing the screen
        this_thread::sleep_for(chrono::seconds(3));
        #if defined(Win32)
        system("CLS");
        #else
        system("clear");
        #endif
    }
    //for exit/....
    else if (choice == 4)
    {
     // decalaring variables and initializing them 
     // it is the password...
   string end ="bye world";
   string end_pass;
   cin.ignore();
   //taking input from the user
   cout<<"Enter The PassWord To Close The System:";
   getline(cin,end_pass);
   // if it matches them program will end
   if (end==end_pass)
   {
      cout<<"System is Shutting Dowm.\nSee You again\n";
      quotes();
      break;
   }
    //for invalid  input......
    else
    {
        cout<<"Wrong PassWord\n";
    }
    }
}
}