#include<iostream>
#include <fstream>
#include "Files.h"
#include "Interface.h"
#include "Employee.h"
#include "Boss.h"
#include "System_Manager.h"
#include "Login.h"
using namespace std;

int main(){

	int select = 0; // User's selection

	while (true) 
	{
		// Main menu
		cout << "==================== WELCOME TO THE SYSTEM! ====================\n" << endl;
		cout << "\t -------------------------------------------\n";
		cout << "\t |                                          |\n";
		cout << "\t |               1. Employee                |\n";
		cout << "\t |               2. System Manager          |\n";
		cout << "\t |               3. Boss                    |\n";
		cout << "\t |               0. Exit!                   |\n";
		cout << "\t |                                          |\n";
		cout << "\t -------------------------------------------\n";
		cout << endl << "Please chose one to log in" << endl;

		cin >> select;

		switch (select)
		{
		case 1:		// Employee
			Login(EMPLOYEE, 1);
			break;	
		case 2:		// Boss
			Login(BOSS, 2);
			break;
		case 3:		// System Manager
			Login(SYSTEM_MANAGER, 3);
			break;
		case 0:		// Exit
			cout << "Thank you for using the system!" << endl;
			system("pause");
			exit(0);
		default:
			cout << "Input error! Please try again!\n" << endl;
			system("pause");
			system("cls");
			break;
		}
	}



	system("pause");

	return 0;
}