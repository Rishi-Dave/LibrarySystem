#ifndef DISPLAY_H
#define DISPLAY_H

// #include "User.h"

#include <iostream>
#include <vector>

using namespace std;

class Display {
    public:
        void displayWelcome(string pageName);
        void displayInputPrompt(int step);
};

#endif