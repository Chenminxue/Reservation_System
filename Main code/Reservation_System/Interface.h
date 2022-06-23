#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <fstream>
#include <map>
#include"Files.h"

using namespace std;

// Interface class.
class Identity 
{
public:
	// Menu UI
	virtual void menu() = 0;

	// name
	string m_Name;

	// password
	string m_Pwd;
};