#pragma once
#include "UserDatabase.h"
#include "../include/ParentDisplay.h"
#include "../include/Catalog.h"
#include "../include/UserDisplay.h"
#include "../include/CatalogDisplay.h"

class Display: private ParentDisplay {
    public:
        void displayAdmin();     
        void displayWelcome(string pageName);
        void displayInputPrompt(UserDisplay& userDisplay, UserDatabase& database, CatalogDisplay& catDisplay, Catalog& catalog);
        void printWelcomeMessage(UserDatabase &database, Catalog& catalog);
};

