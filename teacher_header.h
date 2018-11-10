#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <typeinfo>
#include <stdlib.h>
#include <sstream>

using namespace std;

class teacher
{   
    string username,password;
    public:
        int markMyAttendance(string username);
        int teacherView();
        int teacherlogin();
};