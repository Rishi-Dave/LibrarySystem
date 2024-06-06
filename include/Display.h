#pragma once
#include "UserDatabase.h"
#include "../include/ParentDisplay.h"


class Display: private ParentDisplay {
    public:
        void displayAdmin();     
        void displayWelcome(string pageName);
        void displayInputPrompt(int step);
        void printWelcomeMessage(UserDatabase &database);
};

