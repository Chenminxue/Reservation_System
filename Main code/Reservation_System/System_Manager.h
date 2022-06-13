#pragma once
#include<iostream>
#include "Interface.h"
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
};


