#include <fstream>
#include <memory>
#include "../header/Identity.h"
#include "../header/Student.h"
#include "../header/Teacher.h"
#include "../header/Admin.h"

using std::shared_ptr;
using std::make_shared;
using std::string;
using std::ifstream;
using std::ios;
using std::cout;
using std::endl;
using std::cin;

// Ask for user's id(optional), name and password
void askInfo(int &id, string &name, string &pwd);
void askInfo(string &name, string &pwd);

// Get user's login input(id, name and password)
bool getUserLoginInput(int id, string name, string pwd, ifstream &ifs);
bool getUserLoginInput(string name, string pwd, ifstream &ifs);

// Admin sub menu
void AdminMenu(shared_ptr<Identity> &admin);

/*
Here we defined a Login platform and 3 sub menus for students, teachers and admin.
*/

// Login platform
void Login(string fileName, int type){

    // Be ready to create the object
    shared_ptr<Identity> person;

    // Read files
    ifstream ifs;
    ifs.open(fileName, ios::in);
    // Check whether the file exist or not
    if (!ifs.is_open()){
        cout << "File doesn't exist!" << endl;
        ifs.close();
        return;
    }

    // Fill in the private info
    int id = 0;
    string name;
    string pwd;

    // Check and validate the user type
    switch (type)
    {
    case 1:                     // Student
        askInfo(id, name, pwd);
        break;
    case 2:                     // Teacher
        askInfo(id, name, pwd);
        break;
    case 3:                     // Admin
        askInfo(name, pwd);
        break;
    default:
        cout << "Wrong type." << endl;
        system("clear");
        break;
    }

    system("clear");
    
    // Validate student info
    if(type == 1){
        if(getUserLoginInput(id, name, pwd, ifs)){
            cout << "Student verification succeed!" << endl;
            cin.ignore();
            cin.get();
            system("clear");

            person = make_shared<Student>(id, name, pwd);

            // Login to Student's sub-menu.

            return;     
        }
    }
    else if(type == 2){
        if(getUserLoginInput(id, name, pwd, ifs)){
            cout << "Teacher verification succeed!" << endl;
            cin.ignore();
            cin.get();
            system("clear");

            person = make_shared<Teacher>(id, name, pwd);

            // Login to Teacher's sub-menu.

            return;
        }       
    }
    else{
        if(getUserLoginInput(name, pwd, ifs)){
            cout << "Admin verification succeed!" << endl;
            cin.ignore();
            cin.get();
            system("clear");

            person = make_shared<Admin>(name, pwd);

            // Login to Admin's sub-menu.
            AdminMenu(person);
            return;
        }       
    }
    cout << "Verification failed." << endl;
    cout << "Press enter to continue." << endl;
    cin.ignore();
    cin.get();
    system("clear");

}

// Admin sub menu
void AdminMenu(shared_ptr<Identity> &admin){
    while(true){
        admin->open_Menu();

        shared_ptr<Admin> administrator = std::dynamic_pointer_cast<Admin> (admin);

        int select = 0;
        cin >> select;

        if (select == 1){
            cout << "Add account" << endl;
            administrator->add_Account();
        }
        else if(select == 2){
            cout << "Check account" << endl;
            administrator->check_Account();
        }
        else if(select == 3){
            cout << "Check room" << endl;
            administrator->check_Room_Info();
        }
        else if(select == 4){
            cout << "Clear reservation" << endl;
            administrator->clear_History();
        }
        else if(select == 0){
            cout << "Exit the Admin menu." << endl;
            cin.ignore();
            cin.get();
            system("clear");
            return;
        }
        else{
            cout << "Wrong selection, exit the menu." << endl;
            cin.ignore();
            cin.get();
            system("clear");
            return;
        }
    }
}


inline void askInfo(int &id, string &name, string &pwd){
    cout << "What is your ID number: " << endl;
    cin >> id;

    cout << "What is your name: " << endl;
    cin >> name;

    cout << "What is your password: " << endl;
    cin >> pwd;
}

inline void askInfo(string &name, string &pwd){
    cout << "What is your name: " << endl;
    cin >> name;

    cout << "What is your password: " << endl;
    cin >> pwd;
}

inline bool getUserLoginInput(int id, string name, string pwd, ifstream &ifs)
{
    int in_File_Id;
    string in_File_Name;
    string in_File_Pwd;
    
    if(ifs.peek() == std::ifstream::traits_type::eof()){
        cout << "0 users!" << endl;
        cout << "Press enter to continue." << endl;
        cin.ignore();
        cin.get();
        system("clear"); 
        return false;
    }


    while(ifs >> in_File_Id && ifs >> in_File_Name && ifs >> in_File_Pwd){
        if(in_File_Id == id && in_File_Name == name && in_File_Pwd == pwd){
            return true;
        }
        else{
            return false;
        }
    }
}

inline bool getUserLoginInput(string name, string pwd, ifstream &ifs)
{
    string in_File_Name;
    string in_File_Pwd;

    if(ifs.peek() == std::ifstream::traits_type::eof()){
        cout << "0 users!" << endl;
        cout << "Press enter to continue." << endl;
        cin.ignore();
        cin.get();
        system("clear"); 
        return false;
    }
    
    while(ifs >> in_File_Name && ifs >> in_File_Pwd){
        if(in_File_Name == name && in_File_Pwd == pwd){
            return true;
        }
        else{
            return false;
        }
    }
}
