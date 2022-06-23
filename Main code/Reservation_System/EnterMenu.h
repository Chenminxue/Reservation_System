#pragma once
#include<iostream>
#include <fstream>
#include "Files.h"
#include "Interface.h"
#include "Employee.h"
#include "Boss.h"
#include "System_Manager.h"
using namespace std;


// Enter the menu of the manager
void enterManagerMenu(Identity*& manager);

// Enter the menu of the employee
void enterEmployeeMenu(Identity*& employee);

// Enter the menu of the boss
void enterBossMenu(Identity*& boss);