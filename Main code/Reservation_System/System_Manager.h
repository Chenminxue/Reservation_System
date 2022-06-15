#pragma once
#include<iostream>
#include <vector>
#include "Files.h"
#include "Interface.h"
#include "Employee.h"
#include "Boss.h"
using namespace std;

class System_Manager : public Identity 
{
public:
	// ID, name, password
	System_Manager(string name, string pwd);

	// Menu UI of Employee
	virtual void menu();

	// Add account
	void addAccount();

	// Check account
	void checkAccount();

	// Check system Info
	void checkSystem();

	// Clear history
	void clear();

	// Initialize container
	void initVector();

public:
	// Employee container
	vector<Employee> vEmployee;

	// Boss container
	vector<Boss> vBoss;
};


