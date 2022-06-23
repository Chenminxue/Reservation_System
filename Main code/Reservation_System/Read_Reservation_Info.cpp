#include "Read_Reservation_Info.h"

Read_Reservation_Info::Read_Reservation_Info()
{
	ifstream ifs;
	ifs.open(RESERVATION, ios::in);

	// temporary variables
	string date;
	string timeslot;
	string empID;
	string empName;
	string offNum;
	string status;

	m_Size = 0;

	while (ifs >> date && ifs >> timeslot && ifs >> empID && ifs >> empName && ifs >> offNum && ifs >> status)
	{
		// date: 1
		string key;
		string value;
		map<string, string> m;

		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1); // size = 9, pos = 4, size - pos - 1 = 4

			m.insert(make_pair(key, value));
		}
	

		pos = timeslot.find(":");
		if (pos != -1)
		{
			key = timeslot.substr(0, pos);
			value = timeslot.substr(pos + 1, timeslot.size() - pos - 1); // size = 9, pos = 4, size - pos - 1 = 4

			m.insert(make_pair(key, value));
		}

		pos = empID.find(":");
		if (pos != -1)
		{
			key = empID.substr(0, pos);
			value = empID.substr(pos + 1, empID.size() - pos - 1); // size = 9, pos = 4, size - pos - 1 = 4

			m.insert(make_pair(key, value));
		}

		pos = empName.find(":");
		if (pos != -1)
		{
			key = empName.substr(0, pos);
			value = empName.substr(pos + 1, empName.size() - pos - 1); // size = 9, pos = 4, size - pos - 1 = 4

			m.insert(make_pair(key, value));
		}

		pos = offNum.find(":");
		if (pos != -1)
		{
			key = offNum.substr(0, pos);
			value = offNum.substr(pos + 1, offNum.size() - pos - 1); // size = 9, pos = 4, size - pos - 1 = 4

			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1); // size = 9, pos = 4, size - pos - 1 = 4

			m.insert(make_pair(key, value));
		}

		// Store the sub map in base map
		m_Reservation.insert(make_pair(m_Size, m));
		m_Size++;
	}

	ifs.close();
}

void Read_Reservation_Info::update()
{
	if (m_Size == 0)
	{
		return;
	}

	ofstream ofs(RESERVATION, ios::out | ios::trunc);
	for (int i = 0; i < m_Size; i++)
	{
		ofs << "Date:" << m_Reservation[i]["Date"] << " ";
		ofs << "Timeslot:" << m_Reservation[i]["Timeslot"] << " ";
		ofs << "Employee_ID:" << m_Reservation[i]["Employee_ID"] << " ";
		ofs << "Employee_name:" << m_Reservation[i]["Employee_name"] << " ";
		ofs << "Office_room:" << m_Reservation[i]["Office_room"] << " ";
		ofs << "Status:" << m_Reservation[i]["Status"] << endl;
	}
	ofs.close();
}
