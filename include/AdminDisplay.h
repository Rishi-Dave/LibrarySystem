#pragma once

#include "AdminUser.h"


class AdminDisplay {
    public:
        void removeBook(AdminUser* admin);
        void addBook(AdminUser* admin);
        void editBook(AdminUser* admin);
};

