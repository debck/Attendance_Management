#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <typeinfo>
#include <stdlib.h>
#include <sstream>
#include "student_header.h"
#include "admin_header.h"
using namespace std;

int studentView(); //student
int studentLogin(); //student
int checkStudentCredentials(string userName, string password); //student
int adminLogin();//a
int markMyAttendance(string username);//studnet
int countMyAttendance(string username);//studnet
int sendLeaveApplication(string username);//student
int m=0;
int total=10;




//student part
int student::studentView()
{
cout<<"\n Enter username : ";
cin>>username;

cout<<"\n Enter password : ";
cin>>password;

int res = checkStudentCredentials(username, password);

if(res  == 0)
{
   cout<<"\n Invalid Credentials !!";
   cout<<"\n Press any key for Main Menu..";
   getchar(); getchar();	
   return 0;
} 

    int goBack = 0;
	while(1)
    {
		system("cls");
	
		cout<<"\n 1 Mark Attendance fo Today ";
		cout<<"\n 2 Count my Attendance";
		cout<<"\n 3 Send a leave application";
		cout<<"\n 0. Go Back <- \n";
		int choice;
		
		cout<<"\n Enter you choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: markMyAttendance(username); break;
			case 2: countMyAttendance(username); break;
			case 3: sendLeaveApplication(username);break;
			case 0: goBack = 1;break;
	                default: cout<<"\n Invalid choice. Enter again ";
	                getchar();           	
	   }   
	   
	   if(goBack == 1)
	   {
	   	break; //break the loop
           }     
    	
   }
   
}



int studentLogin()
{   student s;
    system("cls");
    cout<<"\n -------------------- Student Login -----------------";	
    s.studentView();
    return 0; 
}

int student::checkStudentCredentials(string username, string password)
{
	
	ifstream read;
	read.open("db.dat");
	
	if (read) {
  
        int recordFound = 0;
        string line;
        string temp = username +".dat";
        cout<<"\n file name is : "<<temp;
        while(getline(read, line)) {
        	if(line == temp)
        	{
        		recordFound = 1;
        		break;
		}
        }
        
        if(recordFound == 0)
            return 0;
        else
           return 1;
       }
       else
       {
    	   return 0;
       }
    		
}


int student::markMyAttendance(string username)
{
	string filename = username+".dat";
	ifstream read;
	read.open(filename.c_str(), ios::app);
	// ifstream read;
	// read.open("db.dat");
	string line;
	if(read)
	{	
		int line_no = 0;
	while (line_no != 8 && getline(read, line)) {
    ++line_no;
	}
	if (line_no == 8) {
		int i;
		istringstream(line)>>i;
		
		ofstream out1;
		string temp = username+".dat";
		out1.open(temp.c_str(), ios::app);
		i++;
		out1<<i;
	}
	}	

cout<<"\n Please any key to continue..";

getchar();getchar();

return 0;	
} 

int student::countMyAttendance(string username)
{		
	string filename = username+".dat";
	ifstream read;
	read.open(filename.c_str(), ios::app);
	
	string line;
	if(read)
	{	
		int line_no = 0;
	while (line_no != 8 && getline(read, line)) {
    ++line_no;
	}
	if (line_no == 8) {
		cout<<"\nTotal present: "<<line;
		int i;
		istringstream(line) >> i;
		cout<<"\nPercentage of attendance :\t"<< (i*100/total)<<"%";
	}
	}
	
cout<<"\n Please any key to continue..";

getchar();getchar();

return 0;	
} 

int student::sendLeaveApplication(string username)
{	
	char add[100];
	cout<<"\n Write your application here: ";
	getchar();
	cin.getline(add, 100);

	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	ofstream out;
	out.open("application.dat", ios::app);
	out<<add<<" -> "<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<" -> "<<username<<"\n";
	out.close();
	cout<<"\n Application successfully sent !!";
	cout<<"\n Please any key to continue..";
	getchar();
	return 0;
}
























































int main(int argc, char** argv) {
	
	while(1)
	{
		system("cls");
		
		cout<<"\t\t\t\t\t Attendance Management System \n";
		cout<<"-------------------------------------------------------------------------\n\n";
		
		cout<<"1. Student Login\n";
		cout<<"2. Admin Login\n";
		
		cout<<"0. Exit\n";
		int choice;
		
		cout<<"\n Enter you choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: studentLogin(); break;
			case 2: adminLogin(); break;
			case 0: 
			        while(1)
			        {
					    system("cls");
			        	cout<<"\n Are you sure, you want to exit? y | n \n";
			        	char ex;
			        	cin>>ex;
			        	if(ex == 'y' || ex == 'Y')
			        		exit(0);
			        	else if(ex == 'n' || ex == 'N')
	                     {
	                     	 break;
	                     }
	                     else{
						 
	                     	cout<<"\n Invalid choice !!!";
	                     	getchar();
	                     }
	                    
	
                 	 }	break;
                 	 
            default: cout<<"\n Invalid choice. Enter again ";
                     getchar();
                 	
		}   		        

	}
		
	return 0;
}  