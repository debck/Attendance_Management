#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <typeinfo>
#include <stdlib.h>
#include <sstream>
#include "admin_header.h"

using namespace std;

int adminView();  //admin
int deleteAllStudents();      //a
int checkListOfStudentsRegistered(); //a
int checkPresenseCountbyRollno();//a
int getListOfStudentsWithTheirPresenseCount();//a
int adminLogin();//a
int registerStudent();//a




int adminLogin()
{
	system("cls");
	cout<<"\n -------------------- Admin Login -----------------";	

        string username;
	string password;
	
	cout<<"\n Enter username : ";
	cin>>username;
	cout<<"\n Enter password : ";
	cin>>password;
	
	if(username=="admin" && password=="admin") 
	{
	    adminView();
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

int adminView()
{	
    int goBack = 0;
    while(1)
    {
		system("cls");
		cout<<"\n 1 Register a Student";
		cout<<"\n 2 Delete All students name registered";
		cout<<"\n 3 Check List of Student registered by userame";
		cout<<"\n 4 Check presense count of any student by Roll No";
		cout<<"\n 5 Get List of student with their attendance count";
		cout<<"\n 0. Go Back <- \n";
		int choice;
		
		cout<<"\n Enter you choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: registerStudent();break;  
			case 2: deleteAllStudents(); break;
			case 3: checkListOfStudentsRegistered(); break;
			case 4: checkPresenseCountbyRollno(); break;  ////
			case 5: getListOfStudentsWithTheirPresenseCount(); break; // 
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


int deleteAllStudents()
{
	remove("db.dat");
	cout<<"\n Please any key to continue..";
	
	getchar(); getchar();
	return 0;
}


int checkListOfStudentsRegistered(){
    cout<<"\n ---------- Check List of Student Registered by Username----------- ";	
	
	    //check if record already exist..
    ifstream read;
    read.open("db.dat");
    
    if(read)
    {       int recordFound =0; 
	    string line;
    	    while(getline(read, line)) {
    	    	
    	    	char name[100];
    	    	strcpy(name, line.c_str());
    	    	char onlyname[100];
    	    	strncpy(onlyname, name, (strlen(name) - 4));
    	    	cout<<" \n " << onlyname;

            }
    read.close();        
    }
    else
    {
    	cout<<"\n No Record found :(";
    }
	
	
    cout<<"\n Please any key to continue..";
    getchar(); getchar();
    return 0;
}

int checkPresenseCountbyRollno()
{
	cout<<"checkPresenseCountbyRollno"<<"\n";
	return 0;
}

int getListOfStudentsWithTheirPresenseCount()
{
	cout<<"\n All Students with their Presense count !!";
	
        cout<<"\n Please any key to continue..";
	getchar(); getchar();
	return 0;
}

int registerStudent()
{
    cout<<"\n ----- Form to Register Student ---- \n";	

    string name, username, password, rollno, address, father, mother;
     int total,m;

    cout<<"\n Enter Name : ";     cin>>name;
    
    cout<<"\n Enter Username : ";     cin>>username;
    
    
    cout<<"\n Enter password : ";     cin>>password;
    
    cout<<"\n Enter rollno : ";     cin>>rollno;
    getchar();
    
    char add[100];
    cout<<"\n Enter address : ";     cin.getline(add, 100);
    
    cout<<"\n Enter father : ";     cin>>father;
    
    cout<<"\n Enter mother : ";     cin>>mother;
    
	cout<<"\n Enter initial number of presents :"; cin>>m;

    
    //check if record already exist..
    ifstream read;
    read.open("db.dat");
    
    if(read)
    {      int recordFound =0; 
	   string line;
    	    while(getline(read, line)) {
        	if(line == username+".dat" )
        	{
        		recordFound = 1 ;
        	    break;
			}
        }
        if(recordFound == 1)
        {
        	cout<<"\n Username already Register. Please choose another username ";
        	getchar(); getchar();
        	read.close();
        	return 0;
		}
	}
    read.close();

        ofstream out;
	out.open("db.dat", ios::app);
	out<<username+".dat"<<"\n";
	out.close();

	ofstream out1;
	string temp = username+".dat";
	out1.open(temp.c_str());
	out1<<name<<"\n"; 	out1<<username<<"\n"; 	out1<<password<<"\n";
	out1<<rollno<<"\n"; 	out1<<add<<"\n"; 	out1<<father<<"\n";
	out1<<mother<<"\n"; 

	out1<<m;  

	out1.close();

	cout<<"\n Student Registered Successfully !!";
    
        cout<<"\n Please any key to continue..";
	getchar(); getchar();
	return 0;		
}
