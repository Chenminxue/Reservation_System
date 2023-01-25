#pragma once
#include "Identity.h"


class Teacher:public Identity{
public:
    int m_Employee_Id;

public:
    
    Teacher();

    Teacher(int empId, string name, string pwd);

    // Menu
    virtual void open_Menu();

    // Check all reservation
    void check_All_Reservation();

    // Validate reservation
    void validate_Reservation();

};