#pragma once
#include<iostream>
#include <fstream>
#include "Files.h"
#include "Interface.h"
#include "Employee.h"
#include "Boss.h"
#include "System_Manager.h"
using namespace std;

// Login function, 1. operational file 2. login identity
string Login(string fileName, int type);