#pragma once
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "GlobalFile.h"
#include <fstream>
#include <vector>

using std::ofstream;
using std::cin;
using std::ios;
using std::vector;

class Admin:public Identity{
    public:

    Admin();

    Admin(string name, string pwd);

    // Menu
    virtual void open_Menu();

    // Add Account
    void add_Account();

    // Check Account
    void check_Account();

    // Check room
    void check_Room_Info();

    // Clear history
    void clear_History();

    // initialize vector
    void init_Vector();

public:
    // Student vector
    vector<Student> v_Student;

    // Teacher vector
    vector<Teacher> v_Teacher;
};
