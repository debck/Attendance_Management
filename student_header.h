#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <typeinfo>
#include <stdlib.h>
#include <sstream>

using namespace std;

class student
{   
    string username,password;
    public:
        int studentView();
        int studentLogin();
        int checkStudentCredentials(string username,string password);
        int markMyAttendance(string username);
        int countMyAttendance(string username);
        int sendLeaveApplication(string username);
};