#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

class user{
    private:
        string username,password;
    public:
        int adminLogin();
        int adminView();
        int teacherlogin();
        int studentView();
        int studentLogin();
};