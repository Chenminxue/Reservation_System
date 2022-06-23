#include "Boss.h"
#include "Read_Reservation_Info.h"

// Default constructor
Boss::Boss()
{
}

// ID, name, password
Boss::Boss(int id, string name, string pwd)
{
	// Initialization
	m_Id = id;
	m_Name = name;
	m_Pwd = pwd;
}

// Menu UI of Employee
void Boss::menu()
{
	// Main menu
	cout << "==================== Boss Menu ====================\n" << endl;
	cout << "\t -------------------------------------------\n";
	cout << "\t |                                          |\n";
	cout << "\t |               1. Check All info          |\n";
	cout << "\t |                                          |\n";
	cout << "\t |               2. Verify                  |\n";
	cout << "\t |                                          |\n";
	cout << "\t |               0. Log out!                |\n";
	cout << "\t |                                          |\n";
	cout << "\t -------------------------------------------\n";
	cout << endl << "Please chose one to log in" << endl;
}

// Check reservation
void Boss::showInfo()
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

// Verify the request from the employee
void Boss::verify()
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

	cout << "The reservation to be verified are as follows" << endl;

	vector<int> v;
	int index = 0;

	for (int i = 0; i < rri.m_Size; i++)
	{

		if (rri.m_Reservation[i]["Status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "  ";

			cout << "--------------------------------------------------------" << endl;
			cout << "Reservation date: Week " << rri.m_Reservation[i]["Date"];
			cout << " Time slot: " << (rri.m_Reservation[i]["Timeslot"] == " 1 " ? " Morning " : " Afternoon ");
			cout << " Office room: " << rri.m_Reservation[i]["Office_room"];

			string status = "  Status:  ";

			if (rri.m_Reservation[i]["Status"] == "1")
			{
				status += "Waiting for the confirmation...";
			}

			cout << status << endl;

			cout << "--------------------------------------------------------" << endl << endl;

		}
	}

	cout << "Select one to verify, 0: return back" << endl;
	int select = 0;
	int ret = 0;
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
				cout << "Please verify" << endl;
				cout << "1. Pass" << endl;
				cout << "2. Reject" << endl;

				cin >> ret;

				if (ret == 1)
				{
					rri.m_Reservation[v[select - 1]]["Status"] = "2";
				}
				else
				{
					rri.m_Reservation[v[select - 1]]["Status"] = "-1";
				}
				rri.update();
				cout << "Verified" << endl;
				break;
			}
		}
		cout << "Input Error! Please try again!" << endl;
	}
	system("pause");
	system("cls");
}
