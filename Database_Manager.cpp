#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<stdio.h>
#include<time.h>
using namespace std;
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
class login
{
protected:
    char us_name[20],pass[20],confirm[20];
public:
    void getdata()
    {
         system("cls");
         cout<<"\n--------ACCOUNT SETUP PAGE--------";
         cout<<"\nEnter Username:";
         cin>>us_name;
         correct:
         cout<<"\n";
         cout<<"\nEnter Password:";
         cin>>pass;
         cout<<"\n";
         cout<<"\nConfirm Password:";
         cin>>confirm;
         if(strcmp(pass,confirm)==0)
         {
          info();
         }
         else
         {
             system("cls");
             cout<<"Passwords didnt match, try again.";
             cout<<"\n\n\nLoading.......";
             delay(1000);
             goto correct;
         }
    }
    void info()
    {
        system("cls");
        cout<<"\n\nName:"<<us_name;
        cout<<"\nPassword:"<<pass;
        cout<<"\n\nWriting Data To File";
        cout<<"\nPlease wait";
        for(int i=0;i<=10;i++)
        {
            delay(500);
            cout<<".";
        }
        char filename[20];
        strcpy(filename,us_name);
        fstream file;
        file.open(filename,ios::app);
        file<<"\n------------------";
        file<<"\nUsername:"<<us_name;
        file<<"\nPassword:"<<pass;
        file.close();
    }
    void read()
    {
        system("cls");
        start:
        cout<<"\n-----LOGIN-----";
        cout<<"\n\nEnter Username:";
        cin>>us_name;
        cout<<"\nEnter Password:";
        cin>>pass;
        ifstream st;
        st.open(us_name,ios::out);
        if(!st)
        {
            system("cls");
            cout<<"\nAccount Not Found";
            cout<<"\nPress 1 to try again\n";
            int cho;
            cin>>cho;
            if(cho==1)
            {
                system("cls");
                goto start;
            }

        }
        char ch;
        while(!st.eof())
        {
            st.get(ch);
            cout<<ch;
        }
        st.close();


    }

};
int main()
{
    login l;
    int choice_menu;
    menu:
    system("cls");
    cout<<"\n-----DATABASE MANAGER-----";
    cout<<"\n1.Create New Account\n2.Login\n3.Credits\n99.Exit";
    cout<<"\nEnter Your Choice And Hit Return Button:";
    cin>>choice_menu;
    if(choice_menu==1)
    {
        l.getdata();
        goto menu;
    }
    else if(choice_menu==2)
    {
        l.read();
    }
    else if(choice_menu==3)
    {
        system("cls");
        cout<<"\n-----CREDITS AND VERSION INFO-----\n\n";
        cout<<"\n\nDeveloper:Jaskaran Singh Sembhi";
        cout<<"\n\nContact Me: https://www.facebook.com/jaskaran.sembhi.3";
        cout<<"\n\nVersion=1.0-ALPHA BUILD";
        cout<<"\n\nKnown Bugs=Password Authorisation Didn't Added Yet";
        cout<<"\n\nEnter 1 to return to Main Menu:";
        cin>>choice_menu;
        if(choice_menu==1)
            goto menu;
        for(int i=0;i<10;i++)
        {
            cout<<"\n";
        }

    }
    else if(choice_menu==99)
        system("exit");
    return 0;
}
