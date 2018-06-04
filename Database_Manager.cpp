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
             goto correct;
         }
    }
    void info()
    {
        system("cls");
        cout<<"\nName:"<<us_name;
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
        cout<<"\nEnter Username:";
        cin>>us_name;
        cout<<"\nEnter Password:";
        cin>>pass;
        ifstream st;
        if(st.fail())
         {
           cout<<"\nAccount Doesnt Exist, Try Again";
         }
        else
        {
        st.open(us_name,ios::out);
        char ch;
        while(!st.eof())
        {
            st.get(ch);
            cout<<ch;
        }
        st.close();
        }

    }

};
int main()
{
    login l;
    int choice_menu;
    menu:
    system("cls");
    cout<<"\n1.Create New Account\n2.Login";
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
    return 0;
}
