#ifndef ADMINDISPLAY_H
#define ADMINDISPLAY_H


#include "AdminUser.h"

#include <iostream>
#include <vector>

using namespace std;

class AdminDisplay {
    public:
        void removeBook(AdminUser* admin);
        void addBook(AdminUser* admin);
        void editBook(AdminUser* admin);
};

#endif