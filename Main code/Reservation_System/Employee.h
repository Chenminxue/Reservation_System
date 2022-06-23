#pragma once
#include "OfficeRoom.h"
#include "Interface.h"
using namespace std;

class Employee : public Identity 
{
public:
	// Default constructor
	Employee();

	// ID, name, password
	Employee(int id, string name, string pwd);

	// Menu UI of Employee
	virtual void menu();

	// Request reservation
	void request();

	// Check self reservation
	void showInfo();

	// Check all reservation
	void showAllInfo();

	// Cancel reservation
	void cancel();

public:
	// ID number
	int m_Id;

	// Office room container
	vector<OfficeRoom> vOff;
};
