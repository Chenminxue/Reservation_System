#include "System_Manager.h"
#include <fstream>
#include <algorithm>
#include "Files.h"

// ID, name, password
System_Manager::System_Manager(string name, string pwd)
{
	// Initialization
	m_Name = name;
	m_Pwd = pwd;

	// Employee and Boss's container Initialization
	initVector();

	// Office room initialization
	initOfficeRoom();
}

// Menu UI of Employee
void System_Manager::menu()
{
	// Main menu
	cout << "==================== System Manager Menu ====================\n" << endl;
	cout << "\t -------------------------------------------\n";
	cout << "\t |                                          |\n";
	cout << "\t |               1. Add Account             |\n";
	cout << "\t |                                          |\n";
	cout << "\t |               2. Check Account           |\n";
	cout << "\t |                                          |\n";
	cout << "\t |               3. Check System            |\n";
	cout << "\t |                                          |\n";
	cout << "\t |               4. Clear history           |\n";
	cout << "\t |                                          |\n";
	cout << "\t |               0. Log out!                |\n";
	cout << "\t |                                          |\n";
	cout << "\t -------------------------------------------\n";
	cout << endl << "Please chose one to log in" << endl;
}

// Add account
void System_Manager::addAccount()
{
	cout << "Please choose the type of the account." << endl;
	cout << "1. Employee " << endl;
	cout << "2. Boss " << endl;

	string fileName; // File name

	ofstream ofs;    // File operation

	int select(0);
	cin >> select;

	if (select == 1)	// Employee
	{
		fileName = EMPLOYEE;
	}
	else if (select == 2)	// Boss
	{
		fileName = BOSS;
	}
	else
	{
		cout << "Wrong choice, please choose again!" << endl;
		system("pause");
		system("cls");
		return;
	}

	// Open the file for writting
	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name, pwd;

	while (true)
	{
		cout << "Please enter your ID..." << endl;
		cin >> id;
		bool res = checkRepeat(id, select);
		if (res) 
		{
			cout << "Wrong ID! Please check again!" << endl;
		}
		else 
		{
			break;
		}
	}

	cout << "Please enter your name..." << endl;
	cin >> name;

	cout << "Please enter your password..." << endl;
	cin >> pwd;

	// Write the file
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "New account added!" << endl;

	system("pause");
	system("cls");

	ofs.close();

	initVector();
}

// Check account
void System_Manager::checkAccount()
{
	cout << "1. Employee" << endl;
	cout << "2. Boss" << endl;

	int select(0);
	cin >> select;

	if (select == 1)
	{
		for_each(vEmployee.begin(), vEmployee.end(), printEmployee);
	}
	else if (select == 2)
	{
		for_each(vBoss.begin(), vBoss.end(), printBoss);
	}
	else
	{
		cout << "Wrong input! Please try again!" << endl;
	}

	system("pause");
	system("cls");
}

// Check system Info
void System_Manager::checkSystem()
{
	cout << "Office room info: " << endl;
	for (vector<OfficeRoom>::iterator it = vOff.begin(); it != vOff.end(); it++)
	{
		cout << "Room ID: " << it->m_Id << "\tMax number of computers: " << it->m_Max << endl;
	}
	system("pause");
	system("cls");
}

// Clear history
void System_Manager::clear()
{
	ofstream ofs(RESERVATION, ios::trunc);
	ofs.close();

	cout << "Cleared successfully!" << endl;
	system("pause");
	system("cls");
}

void System_Manager::initVector()
{
	// Empty the containers
	vEmployee.clear();
	vBoss.clear();

	// Read Employee's file
	ifstream ifs;
	ifs.open(EMPLOYEE, ios::in);
	if(!ifs.is_open())
	{
		cout << "Read file failed!" << endl;
		return;
	}

	Employee emp;
	while (ifs >> emp.m_Id && ifs >> emp.m_Name && ifs >> emp.m_Pwd)
	{
		vEmployee.push_back(emp);
	}

	cout << "Number of Employee: " << vEmployee.size() << endl;
	
	ifs.close();

	// Read Boss's file
	ifs.open(BOSS, ios::in);
	if (!ifs.is_open())
	{
		cout << "Read file failed!" << endl;
		return;
	}

	Boss boss;
	while (ifs >> boss.m_Id && ifs >> boss.m_Name && ifs >> boss.m_Pwd)
	{
		vBoss.push_back(boss);
	}

	cout << "Number of Boss: " << vBoss.size() << endl;

	ifs.close();
}

void System_Manager::initOfficeRoom()
{
	ifstream ifs;
	ifs.open(OFFICEROOM, ios::in);

	OfficeRoom off;
	while (ifs >> off.m_Id && ifs >> off.m_Max)
	{
		vOff.push_back(off);
	}

	cout << "Number of Office: " << vOff.size() << endl;
	
	ifs.close();
}

bool System_Manager::checkRepeat(int id, int type)
{
	if (type == 1)				// Check Employee
	{
		for (vector<Employee>::iterator it = vEmployee.begin(); it != vEmployee.end(); it++) 
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else                        // Check Boss
	{
		for (vector<Boss>::iterator it = vBoss.begin(); it != vBoss.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	return false;
}


// For printing employee
void printEmployee(Employee & emp) 
{
	cout << "ID: " << emp.m_Id << " name:  " << emp.m_Name << endl;
}

// For printing boss
void printBoss(Boss& boss)
{
	cout << "ID: " << boss.m_Id << " name:  " << boss.m_Name << endl;
}
