#pragma once
#include "../include/ParentDisplay.h"
#include "AdminUser.h"


class AdminDisplay: private ParentDisplay {
    public:
        void removeBook(AdminUser* admin);
        void addBook(AdminUser* admin);
        void editBook(AdminUser* admin);
};

