#pragma once
#include<iostream>
#include "Interface.h"
using namespace std;

class Employee : public Identity 
{
public:
	// ID, name, password
	Employee(int id, string name, string pwd);

	// Menu UI of Employee
	virtual void menu();

	// Request reservation
	void request();

	// Check reservation
	void showInfo();

	// Cancel reservation
	void cancel();

public:
	// ID number
	int m_Id;
};
