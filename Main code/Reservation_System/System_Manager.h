#pragma once
#include "Files.h"
#include "Interface.h"
#include "Employee.h"
#include "Boss.h"
#include "OfficeRoom.h"
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

	// Initialize employee and boss
	void initVector();

	// Initialize office room
	void initOfficeRoom();

	// Avoid repeat ID number
	bool checkRepeat(int id, int type);

public:
	// Employee container
	vector<Employee> vEmployee;

	// Boss container
	vector<Boss> vBoss;

	// Office container
	vector<OfficeRoom> vOff;
};


// For printing employee
void printEmployee(Employee& emp);

// For printing boss
void printBoss(Boss& boss);



