#ifndef DISPLAY_H
#define DISPLAY_H


#include "user.h"

#include <iostream>
#include <vector>

using namespace std;

class Display {
    public:
        void displayAdmin();     
        void displayWelcome(string pageName);
        void displayInputPrompt(int step);
};

#endif