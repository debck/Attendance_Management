
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <typeinfo>
#include <stdlib.h>
#include <sstream>
using namespace std;
class Admin
{   private:
        string username,password;
    public:
        int adminLogin();
        int adminView();
        int deleteAllStudents();
        int checkListOfStudentsRegistered();
        int checkPresenseCountbyRollno();
        int getListOfStudentsWithTheirPresenseCount();
        int registerStudent();
};
