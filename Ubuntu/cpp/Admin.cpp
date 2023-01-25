#include "../header/Admin.h"
#include <fstream>

using std::ifstream;
using std::ios;

Admin::Admin()
{
}

Admin::Admin(string name, string pwd)
{
    this->m_Name = name;
    this->m_Pwd = pwd;

	this->init_Vector();
}

void Admin::open_Menu()
{
        // sub menu
		cout << "==================== Administrator " << this->m_Name << " ====================\n" << endl;
		cout << "\t -------------------------------------------\n";
		cout << "\t |                                          |\n";
		cout << "\t |               1. Add Account             |\n";
		cout << "\t |                                          |\n";
		cout << "\t |               2. Check Account           |\n";
		cout << "\t |                                          |\n";
		cout << "\t |               3. Check Room              |\n";
		cout << "\t |                                          |\n";
		cout << "\t |               4. Clear History           |\n";
		cout << "\t |                                          |\n";        
		cout << "\t |               0. Exit!                   |\n";
		cout << "\t |                                          |\n";
		cout << "\t -------------------------------------------\n";
		cout << endl << "Please chose one to log in" << endl;\
}

void Admin::add_Account()
{
	system("clear");
	cout << "Which account you want to add?" << endl;
	cout << "1. Student" << endl;
	cout << "2. Teacher" << endl;

	string fileName; // operated file
	string tip; // id number

	ofstream ofs;

	int select = 0;
	cin >> select; 

	system("clear");
	
	if (select == 1){
		// Add Student
		fileName = STUDENT_FILE;
		tip = "Please input ID number: ";
	}
	else{
		fileName = TEACHER_FILE;
		tip = "Please input ID number: ";
	}

	ofs.open(fileName, ios::out | ios::app);
	
	int id;
	string name;
	string pwd;

	cout << tip << endl;
	cin >> id;

	cout << "Please fill in the name: " << endl;
	cin >> name;

	cout << "Please fill in the password: " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "Account added!" << endl;
	cin.ignore();
	cin.get();
	system("clear");

	ofs.close();
}

void Admin::check_Account()
{
}

void Admin::check_Room_Info()
{
}

void Admin::clear_History()
{

}

void Admin::init_Vector()
{
	v_Student.clear();
	v_Teacher.clear();

	ifstream ifs;

	ifs.open(STUDENT_FILE, ios::in);
	if(! ifs.is_open()){
		cout << "Read file failed!" << endl;
		return;
	}

	Student stu;

	while (ifs >> stu.m_Student_Id && ifs >> stu.m_Name && ifs >> stu.m_Pwd){
		v_Student.push_back(stu);
	}

	cout << "Student number: " << v_Student.size() << endl;
	ifs.close();


	ifs.open(TEACHER_FILE, ios::in);
	if(! ifs.is_open()){
		cout << "Read file failed!" << endl;
		return;
	}

	Teacher tea;

	while (ifs >> tea.m_Employee_Id && ifs >> tea.m_Name && ifs >> tea.m_Pwd){
		v_Teacher.push_back(tea);
	}

	cout << "Teacher number: " << v_Teacher.size() << endl;
	ifs.close();
}
