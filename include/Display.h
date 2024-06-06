#pragma once
#include "UserDatabase.h"
#include "ParentDisplay.h"
#include "Catalog.h"
#include "UserDisplay.h"
#include "CatalogDisplay.h"
#include "AdminDisplay.h"

class Display: private ParentDisplay {
    public:
        void displayAdmin(AdminDisplay& adminDisplay, UserDatabase& database, CatalogDisplay& catDisplay, Catalog& catalog);     
        void displayWelcome(string pageName);
        void displayInputPrompt(UserDisplay& userDisplay, UserDatabase& database, CatalogDisplay& catDisplay, Catalog& catalog);
        void printWelcomeMessage(UserDatabase &database, Catalog& catalog);
};

