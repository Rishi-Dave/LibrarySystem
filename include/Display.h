#pragma once
#include "UserDatabase.h"
#include "ParentDisplay.h"
#include "Catalog.h"
#include "UserDisplay.h"
#include "CatalogDisplay.h"
#include "AdminDisplay.h"

class Display: public ParentDisplay {
    public:
        bool displayAdmin(AdminDisplay& adminDisplay, UserDatabase& database, CatalogDisplay& catDisplay, Catalog& catalog);     
        void displayWelcome(string pageName);
        bool displayInputPrompt(UserDisplay& userDisplay, UserDatabase& database, CatalogDisplay& catDisplay, Catalog& catalog);
        bool printWelcomeMessage(UserDatabase &database, Catalog& catalog);
};

