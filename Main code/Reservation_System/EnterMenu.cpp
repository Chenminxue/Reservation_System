#include "EnterMenu.h"

void enterManagerMenu(Identity*& identity)
{
	while (true)
	{
		// Open the menu of the manager
		identity->menu();

		// Spicify base class(Identity) pointer identify to sub class(System_Manager) pointer manager
		System_Manager* manager = (System_Manager*)identity;

		int select = 0;

		// User's option
		cin >> select;

		if (select == 1)	// Add account
		{
			manager->addAccount();
		}
		else if (select == 2) // Check account
		{
			manager->checkAccount();
		}
		else if (select == 3) // Check system info
		{
			manager->checkSystem();
		}
		else if (select == 4) // Clear history
		{
			manager->clear();
		}
		else                  // If the user chose other numbers, System will log out.
		{
			delete manager;
			cout << "Log out succeeded!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void enterEmployeeMenu(Identity*& identity)
{
	while (true)
	{
		// Open the menu of the employee
		identity->menu();

		// Spicify base class(Identity) pointer identify to sub class(Employee) pointer employee
		Employee* emp = (Employee*)identity;

		int select = 0;

		// User's option
		cin >> select;

		if (select == 1)	// Send request
		{
			emp->request();
		}
		else if (select == 2) // Check self reservation
		{
			emp->showInfo();
		}
		else if (select == 3) // Check all reservation
		{
			emp->showAllInfo();
		}
		else if (select == 4) // Cancel the reservation
		{
			emp->cancel();
		}
		else                  // If the user chose other numbers, System will log out.
		{
			delete emp;
			cout << "Log out succeeded!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void enterBossMenu(Identity*& identity)
{
	while (true)
	{
		// Open the menu of the employee
		identity->menu();

		// Spicify base class(Identity) pointer identify to sub class(Employee) pointer employee
		Boss* b = (Boss*)identity;

		int select = 0;

		// User's option
		cin >> select;

		if (select == 1)	// Send request
		{
			b->showInfo();
		}
		else if (select == 2) // Check self reservation
		{
			b->verify();
		}
		else                  // If the user chose other numbers, System will log out.
		{
			delete b;
			cout << "Log out succeeded!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
