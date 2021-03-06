#pragma once
#include "Interface.h"
using namespace std;

class Boss : public Identity 
{
public:
	// Default constructor
	Boss();

	// ID, name, password
	Boss(int id, string name, string pwd);

	// Menu UI of Employee
	virtual void menu();

	// Check reservation
	void showInfo();

	// Verify the request from the employee
	void verify();

public:
	// ID number
	int m_Id;
};

