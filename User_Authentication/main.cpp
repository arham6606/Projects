#include"functions.h"
int main()
{
    // we will give the user to select the choice......
     int choice;
     cout<<"Press '1' For Login"<<endl;
     cout<<"Press '2' For Sign up"<<endl;
     cout<<"Press '3' For Forgot Password"<<endl;
     cout<<"Press '4' For Exit"<<endl;\
    cout<<"\n";
    // entering the choice.......
     cout<<"Enter Your Choice: ";
     cin>>choice;

    // 1 is for login so the beolow code is for that
    if (choice == 1)
    {
        // calling the functions.....
        cout<<"\n";
        cin.ignore();
        login();      
    }
    //2 is for signning up
    else if(choice == 2)
    {
        //calling the functions...
        cout<<"\n";
        cin.ignore();
        sign();      
    }
    return 0 ;

}
