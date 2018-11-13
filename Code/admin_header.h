
#include "user.h"

class Admin : public user
{   private:
        string username,password;
    public:
        int deleteAllStudents();
        int checkListOfStudentsRegistered();
        int registerStudent();
};
