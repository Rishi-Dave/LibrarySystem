#pragma once
#include <iostream>
using namespace std;

class ParentDisplay{
    protected:
        std::string trim(const std::string& str);
        std::string getInput(const std::string& prompt);
};