#include "user.h"
using namespace std;

class teacher: public user
{   
    string username,password;
    public:
        int Attendance();
        int teacherView();
};
