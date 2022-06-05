#pragma once
#include<iostream>
#include<string>
using namespace std;

// Interface class.
class Identity {
public:
	// Menu UI
	virtual void menu() = 0;

	// name
	string m_Name;

	// password
	string m_Pwd;
};