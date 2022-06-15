#include "System_Manager.h"
#include <fstream>

// ID, name, password
System_Manager::System_Manager(string name, string pwd)
{
	// Initialization
	m_Name = name;
	m_Pwd = pwd;

	// Container Initialization
	initVector();
}

// Menu UI of Employee
void System_Manager::menu()
{
	// Main menu
	cout << "==================== System Manager Menu ====================\n" << endl;
	cout << "\t -------------------------------------------\n";
	cout << "\t |                                          |\n";
	cout << "\t |               1. Add Account             |\n";
	cout << "\t |               2. Check Account           |\n";
	cout << "\t |               3. Check System            |\n";
	cout << "\t |               4. Clear history           |\n";
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

	// Open the file for writting
	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name, pwd;

	cout << "Please enter your ID..." << endl;
	cin >> id;

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
}

// Check account
void System_Manager::checkAccount()
{
}

// Check system Info
void System_Manager::checkSystem()
{
}

// Clear history
void System_Manager::clear()
{
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


