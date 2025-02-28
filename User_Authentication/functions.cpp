#include "functions.h"
// for logging up
fstream file;
void login()
{
    // declaration of variables.....
    int n = 2;
    long int a =10 ;
    string user,pass,passed;
    string user_check,pass_check;
    //inputting values from user
    cout<<"Enter Your UserName:";
    getline(cin,user);
    cout<<"Enter Your PassWord:";
    getline(cin,pass);
    cout<<"\n";
    // openeing the files..
    file.open("project1.txt",ios :: in);
    //storing the data in the variables.
    getline(file,user_check,'*');
    getline(file,pass_check, '.');
    getline(file,passed, '\n');
    //getline(file,pass_check,'\n');
    // while true is ......
    while(true)
    {
        // check if the user name matches..
        if (user_check == user)
        {
            // check if the ueer passsowrd matches..
            if(pass_check==pass)
            {
                // it will come out of loop ..
                cout<<"Login is Successful...";
                break;
            } 
            // if the user pass is not equal then
            else if (pass_check != pass)
            {
                // this means that if user enters wrong pass word for 3 
                //times then account will be locked.. 
                if (n==0)
                {
                    // it will here come out of loop..
                cout<<"Contact Adminstration Office...";
                break;
                }
                // this will give user to enter the pssword 2 times if wrong..
                while(true)
                {
                    // getting output from uer again..
                 cout<<"You have only "<<n<<" tries left"<<endl;
                    cout<<"Enter Your PassWord Again:";
                    getline(cin,pass);
                    // if it matches then break this loop
                    if (pass_check==pass)
                    {
                        break;
                    }
                    // if it not matches then also break it..
                    else if (pass_check !=pass)
                    {
                        // but decrement n by 1..
                        n--;
                        break;   
                    }
                }
            } // line 35
        }//line 25
        // a is used because the whole file will be checked so
    else if (user_check != user && a>0)
    {
    getline(file,user_check,'*');
    getline(file,pass_check, '.');
    getline(file,passed, '\n');
    a--;
    } 
    // when count reaches zero program have checked all names in the file..
    else if(user_check != user)
    {
        cout<<"Account not found..";
        break;
    }
    } //first while
// closing the file..
 file.close();
}//functions

// for signing up....

void sign()
{
    string user,pass;
    cout<<"Enter Your UserName:";
    getline(cin,user);
    cout<<"Enter Your PassWord:";
    getline(cin,pass);
    file.open("project1.txt",ios::out | ios:: app);
    if (file.is_open())
    {
        file<<user<<"*"<<pass<<"."<<endl;
       
    }
    else 
    {
        cout<<"File is not Opened..";
    }
    file.close();
    cout<<"\n";
    cin.ignore();
    
}


