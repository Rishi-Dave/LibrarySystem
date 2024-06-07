#pragma once
#include <iostream>
using namespace std;

class ParentDisplay{
    public:
        std::string trim(const std::string& str);
        std::string getInput(const std::string& prompt);
        void printPageBreak();
};