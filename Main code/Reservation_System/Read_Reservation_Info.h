#pragma once
#include "Interface.h"

class Read_Reservation_Info 
{
public:
	Read_Reservation_Info();

	void update();

public:
	// Number of reservation.
	int m_Size;

	// For loading the reservation info.
	map<int, map<string, string>> m_Reservation;


};
