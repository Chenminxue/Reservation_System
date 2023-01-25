#pragma once
#include "Identity.h"


class Student : public Identity{
public:
    Student();

    Student(int id, string name, string pwd);

    // Open menu
    virtual void open_Menu();

    // Request a reservation
    void request_Reservation();

    // Check self reservation
    void check_Self_Reservation();

    // Check all reservation
    void check_All_Reservation();

    // Cancel reservation
    void cancel_Reservation();

public:
    // Student ID
    int m_Student_Id;

};
