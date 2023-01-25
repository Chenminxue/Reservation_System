#include <iostream>
#include "Login.hpp"
#include "../header/GlobalFile.h"

using std::cout;
using std::cin;
using std::endl;

int main(){

        int select = 0;

        while(true){

		// Main menu
		cout << "==================== WELCOME TO THE SYSTEM! ====================\n" << endl;
		cout << "\t -------------------------------------------\n";
		cout << "\t |                                          |\n";
		cout << "\t |               1. Student                 |\n";
		cout << "\t |                                          |\n";
		cout << "\t |               2. Teacher                 |\n";
		cout << "\t |                                          |\n";
		cout << "\t |               3. System Manager          |\n";
		cout << "\t |                                          |\n";
		cout << "\t |               0. Exit!                   |\n";
		cout << "\t |                                          |\n";
		cout << "\t -------------------------------------------\n";
		cout << endl << "Please chose one to log in" << endl;\

        cin >> select;

        switch (select)
        {
        case 1:     // Student
            system("clear");
            Login(STUDENT_FILE, 1);
            break;
        case 2:     // Teacher
            system("clear");
            Login(TEACHER_FILE, 2);
            break;
        case 3:     // Administrator
            system("clear");
            Login(ADMIN_FILE, 3);
            break;
        case 0:     // Exit
            cout << "Goodbye!" << endl;
            exit(0);
            break;
        default:
            system("clear");
            cout << "Input Error! Please try again!" << endl;
            break;
        }
    }
    return 0;
}