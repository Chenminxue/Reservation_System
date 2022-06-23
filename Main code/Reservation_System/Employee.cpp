#include<iostream>
#include "Employee.h"
#include "Read_Reservation_Info.h"
using namespace std;

// Default constructor
Employee::Employee()
{
}

// ID, name, password
Employee::Employee(int id, string name, string pwd)
{
	// Initialization
	m_Id = id;
	m_Name = name;
	m_Pwd = pwd;
	
	ifstream ifs;
	ifs.open(OFFICEROOM, ios::in);

	OfficeRoom off;
	while (ifs >> off.m_Id && ifs >> off.m_Max)
	{
		// Save info into the container
		vOff.push_back(off);
	}

	ifs.close();
}

// Menu UI of Employee
void Employee::menu()
{
	// Main menu
	cout << "==================== Employee Menu ====================\n" << endl;
	cout << "\t -------------------------------------------------------\n";
	cout << "\t |                                                      |\n";
	cout << "\t |               1. Make a reservation                  |\n";
	cout << "\t |                                                      |\n";
	cout << "\t |               2. Check my reservation                |\n";
	cout << "\t |                                                      |\n";
	cout << "\t |               3. Check all reservation               |\n";
	cout << "\t |                                                      |\n";
	cout << "\t |               4. Cancel the request                  |\n";
	cout << "\t |                                                      |\n";
	cout << "\t |               0. Log out!                            |\n";
	cout << "\t |                                                      |\n";
	cout << "\t -------------------------------------------------------\n";
	cout << endl << "Please chose one to log in" << endl;
}

// Request reservation
void Employee::request()
{
	cout << "Apply from Monday to Friday..." << endl;
	cout << "1. Monday" << endl;
	cout << "2. Tuesday" << endl;
	cout << "3. Wednesday" << endl;
	cout << "4. Thursday" << endl;
	cout << "5. Friday" << endl;

	int date = 0;		// date
	int timeslot = 0;	// timne interval
	int officeNum = 0;	// Office number

	while(true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "Input error! Please try again!" << endl;
	}

	cout << "Please choose your time slots..." << endl;
	cout << "1. 9:00 - 12:00" << endl;
	cout << "2. 13:00 - 17:00" << endl;

	while (true)
	{
		cin >> timeslot;
		if (timeslot >= 1 && timeslot <= 2)
		{
			break;
		}
		cout << "Input error! Please try again!" << endl;
	}

	cout << "Please choose your office..." << endl;

	for (int i = 0; i < vOff.size(); i++) 
	{
		cout << "Office " << vOff[i].m_Id << " has " << vOff[i].m_Max << " seats in total" << endl;
	}

	while (true)
	{
		cin >> officeNum;
		if (officeNum >= 1 && officeNum <= 3)
		{
			break;
		}
		cout << "Input error! Please try again!" << endl;
	}

	cout << "Appointment reserved! Waiting for the confirmation..." << endl;

	ofstream ofs(RESERVATION, ios::app);

	ofs << "Date:" << date << " ";
	ofs << "Timeslot:" << timeslot << " ";
	ofs << "Employee_ID:" << m_Id << " ";
	ofs << "Employee_name:" << m_Name << " ";
	ofs << "Office_room:" << officeNum << " ";
	ofs << "Status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

// Check self reservation
void Employee::showInfo()
{
	Read_Reservation_Info rri;

	if (rri.m_Size == 0)
	{
		system("cls");
		cout << "No reservation!" << endl;
		system("pause");
		system("cls");
		return;
	}


	system("cls");
	for (int i = 0; i < rri.m_Size; i++)
	{

		if (atoi(rri.m_Reservation[i]["Employee_ID"].c_str()) == m_Id)
		{
			cout << "--------------------------------------------------------" << endl;
			cout << " Reservation date: Week " << rri.m_Reservation[i]["Date"];
			cout << " Time slot: " << (rri.m_Reservation[i]["Timeslot"] == " 1 " ? " Morning " : " Afternoon ");
			cout << " Office room: " << rri.m_Reservation[i]["Office_room"];

			// 0: cancel, 1: Waiting for the confirmation, 2. Reserved, 3. Failed
			string status = "  Status:  ";
			if (rri.m_Reservation[i]["Status"] == "1")
			{
				status += "Waiting for the confirmation";
			}
			else if (rri.m_Reservation[i]["Status"] == "2")
			{
				status += "Reservation confirmed";
			}
			else if (rri.m_Reservation[i]["Status"] == "3")
			{
				status += "Reservation denied";
			}
			else
			{
				status += "Reservation canceled";
			}
			cout << status << endl;
			cout << "--------------------------------------------------------" << endl << endl;
		}
	}
	system("pause");
	system("cls");
}

// Check all reservation
void Employee::showAllInfo()
{
	Read_Reservation_Info rri;
	if (rri.m_Size == 0)
	{
		system("cls");
		cout << "No reservation!" << endl;
		system("pause");
		system("cls");
		return;
	}

	system("cls");
	for (int i = 0; i < rri.m_Size; i++)
	{
		cout << i + 1 << ".  ";

		cout << "--------------------------------------------------------" << endl;
		cout << "Reservation date: Week " << rri.m_Reservation[i]["Date"];
		cout << " Time slot: " << (rri.m_Reservation[i]["Timeslot"] == " 1 " ? " Morning " : " Afternoon ");
		cout << " Employee ID: " << rri.m_Reservation[i]["Employee_ID"];
		cout << " Employee Name: " << rri.m_Reservation[i]["Employee_name"];
		cout << " Office room: " << rri.m_Reservation[i]["Office_room"];

		// 0: cancel, 1: Waiting for the confirmation, 2. Reserved, 3. Failed
		string status = "  Status:  ";
		if (rri.m_Reservation[i]["Status"] == "1")
		{
			status += "Waiting for the confirmation...";
		}
		else if (rri.m_Reservation[i]["Status"] == "2")
		{
			status += "Reservation confirmed";
		}
		else if (rri.m_Reservation[i]["Status"] == "-1")
		{
			status += "Reservation denied";
		}
		else
		{
			status += "Reservation canceled";
		}
		cout << status << endl;

		cout << "--------------------------------------------------------" << endl << endl;


	}
	system("pause");
	system("cls");
}

// Cancel reservation
void Employee::cancel()
{
	Read_Reservation_Info rri;
	if (rri.m_Size == 0)
	{
		system("cls");
		cout << "No reservation!" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "Cancel options" << endl;

	vector<int> v;
	int index = 1;

	for (int i = 0; i < rri.m_Size; i++)
	{

		if (atoi(rri.m_Reservation[i]["Employee_ID"].c_str()) == m_Id)
		{
			if (rri.m_Reservation[i]["Status"] == "1" || rri.m_Reservation[i]["Status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "  ";

				cout << "--------------------------------------------------------" << endl;
				cout << "Reservation date: Week " << rri.m_Reservation[i]["Date"];
				cout << " Time slot: " << (rri.m_Reservation[i]["Timeslot"] == " 1 " ? " Morning " : " Afternoon ");
				cout << " Office room: " << rri.m_Reservation[i]["Office_room"];
				
				string status = "  Status:  ";

				if (rri.m_Reservation[i]["Status"] == "1")
				{
					status += "Waiting for the confirmation...";
				}
				else if (rri.m_Reservation[i]["Status"] == "2")
				{
					status += "Reservation confirmed";
				}

				cout << status << endl;

				cout << "--------------------------------------------------------" << endl << endl;

			}
		}
	}

	cout << "Select one that you want to cancel, 0: return back" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				rri.m_Reservation[v[select - 1]]["Status"] = "0";
				rri.update();
				cout << "Canceled" << endl;
				break;
			}
		}
		cout << "Input Error! Please try again!" << endl;
	}
	system("pause");
	system("cls");
}
