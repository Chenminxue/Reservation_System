#include<iostream>
using namespace std;


int main(){

	int select = 0; // User's selection

	while (true) {
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
			break;	
		case 2:		// System Manager
			break;
		case 3:		// Boss
			break;
		case 0:		// Exit
			cout << "Thank you for using the system!" << endl;
			system("pause");
			exit(0);
		default:
			cout << "Input error! Please try again!" << endl;
			system("pause");
			system("clr");
			break;
		}
	}



	system("pause");

	return 0;
}