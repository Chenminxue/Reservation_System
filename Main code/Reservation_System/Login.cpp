#include "Login.h"
#include "EnterMenu.h"

string Login(string fileName, int type)
{
	Identity* person = NULL;

	// Read files
	ifstream ifs;
	ifs.open(fileName, ios::in);

	// Check whether the file exist or not
	if (!ifs.is_open())
	{
		cout << "Error! File doesn't exist!" << endl;
		ifs.close();
		return "Error! File doesn't exist!";
	}

	// Input from the user
	int id = 0;
	string name, pwd;

	// Verify the user info, 1. Employee, 2. Boss 3. System manager(No ID)
	if (type == 1)
	{
		// Enter Employee ID
		cout << "Employee, please enter your ID." << endl;
		cin >> id;

		// Enter Employeee name
		cout << "Please Enter your name." << endl;
		cin >> name;

		// Enter Employee password
		cout << "Please Enter your password." << endl;
		cin >> pwd;

		// Verification starts
		int verifyID;
		string verifyName, verifyPassword;

		while (ifs >> verifyID && ifs >> verifyName && ifs >> verifyPassword)
		{
			if (verifyID == id && verifyName == name && verifyPassword == pwd)
			{
				cout << "Employee login succeeded!" << endl;
				system("pause");
				system("cls");

				// After verification, create the identity 
				person = new Employee(id, name, pwd);

				// Enter the Menu of Employee
				enterEmployeeMenu(person);

				return "Employee login succeeded!";
			}
		}
	}
	else if (type == 2)
	{
		// Enter Boss ID
		cout << "Boss, please enter your ID." << endl;
		cin >> id;

		// Enter Boss name
		cout << "Please Enter your name." << endl;
		cin >> name;

		// Enter Boss password
		cout << "Please Enter your password." << endl;
		cin >> pwd;

		// Verification starts
		int verifyID;
		string verifyName, verifyPassword;

		while (ifs >> verifyID && ifs >> verifyName && ifs >> verifyPassword)
		{
			if (verifyID == id && verifyName == name && verifyPassword == pwd)
			{
				cout << "Boss login succeeded!" << endl;
				system("pause");
				system("cls");

				// After verification, create the identity 
				person = new Boss(id, name, pwd);

				// Enter the Menu of Boss
				enterBossMenu(person);

				return "Boss login succeeded!";
			}
		}
	}
	else if (type == 3)
	{
		// Enter Manager name
		cout << "System manager, please Enter your name." << endl;
		cin >> name;

		// Enter Manager password
		cout << "Please Enter your password." << endl;
		cin >> pwd;

		// Verification starts
		string verifyName, verifyPassword;

		while (ifs >> verifyName && ifs >> verifyPassword)
		{
			if (verifyName == name && verifyPassword == pwd)
			{
				cout << "System manager login succeeded!" << endl;
				system("pause");
				system("cls");

				// After verification, create the identity 
				person = new System_Manager(name, pwd);

				// Enter the Menu of Manager
				enterManagerMenu(person);

				return "System manager login succeeded!";
			}
		}
	}

	cout << "Verification failed!\n" << endl;
	system("pause");
	system("cls");

	return "Verification failed!\n";
}