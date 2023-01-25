#pragma once
#include  <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

///////////////////////////////////////////////////////
//                                                   //
//                    Interface                      //
//                                                   //
///////////////////////////////////////////////////////

class Identity{

public:
    string m_Name;
    string m_Pwd;

public:
    virtual void open_Menu() = 0;
};

