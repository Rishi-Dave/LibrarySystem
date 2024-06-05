#pragma once
#include "UserDatabase.h"


class Display {
    public:
        void displayAdmin();     
        void displayWelcome(string pageName);
        void displayInputPrompt(int step);
        void printWelcomeMessage(UserDatabase &database);
};

