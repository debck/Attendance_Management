#include <iostream>
#include <string>
#include<bits/stdc++.h>
#include <fstream>
#include <cstring>
#include <time.h>
#include <typeinfo>
#include <stdlib.h>
#include <sstream>
#include "student_header.h"
#include "admin_header.h"
#include "teacher_header.h"
using namespace std;


int markMyAttendance();
int teacherView();
int teacherlogin();


int teacherlogin()
{
	system("cls");
	cout<<"\n -------------------- Teacher Login -----------------";	

        string username;
	string password;
	
	cout<<"\n Enter username : ";
	cin>>username;
	cout<<"\n Enter password : ";
	cin>>password;
	
	if(username=="teacher" && password=="teacher") 
	{   teacherView();
	    getchar();	
       }   
       else
       {
        cout<<"\n Error ! Invalid Credintials..";	
        cout<<"\n Press any key for main menu ";
        getchar();getchar();
      }
   
   return 0;
	
}





int markMyAttendance()
{   ifstream read;
    read.open("db.dat");
    
    if(read)
    {       int recordFound =0; 
	    string line;
    	    while(getline(read, line)) {
    	    	
    	    	char name[100];
    	    	strcpy(name, line.c_str());
    	    	string filename = name;
	            ifstream read;
	read.open(filename.c_str(), ios::app);
	// ifstream read;
	// read.open("db.dat");
    cout<<"name:"<<filename<<endl;
    int c;
    cout<<"1: present:"<<"\n"<<"O -> absent:"<<endl;
    cout<<"enter choice:"<<endl;
    cin>>c;
    switch(c)
    {
        case 1: 
                { string line;
                if(read)
                {	
                    int line_no = 0;
                while (line_no != 8 && getline(read, line)) {
                ++line_no;
                }
                if (line_no == 8) {
                    int i;
                    istringstream(line)>>i;
                    int rem = i%10;
                    rem++;
                    ofstream out1;
                    string temp = name;
                    out1.open(temp.c_str(), ios::app);
                    out1<< rem;

                }
                }	
                break;
                }
        case 0:
                break;

    }
	
    read.close();        
    }
     
    }
    read.close();

cout<<"\n Please any key to continue..";

getchar();getchar();

return 0;	
}

int teacherView()
{	
    int goBack = 0;
    while(1)
    {
		system("cls");
		cout<<"\n 1 Mark Attendance";
		cout<<"\n 0. Go Back <- \n";
		int choice;
		
		cout<<"\n Enter you choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: markMyAttendance();break;  
			case 0: goBack = 1;break;
	                default: cout<<"\n Invalid choice. Enter again ";
	                 getchar();           	
	   }   
	   
	   if(goBack == 1)
	   {
	   	break; 
           }     
    	
   }
   
   
   return 0;

}