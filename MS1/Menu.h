// Citation and Sources

//Final Project Milestone 1
//Module:   Menu
//Filename: Menu.h
//Version   0.1
//Author:   Baihua Chen

//Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Baihua Chen        2024-07-01           First version, v0.1
// -----------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstring>
namespace seneca {
    const unsigned int MAX_MENU_ITEMS = 20;
    const unsigned int MAX_STRING_LEN = 20;

    class MenuItem {

        char* itemName;

        MenuItem() : itemName(nullptr) {};
        ~MenuItem() {
            delete[] itemName;
        };

        explicit MenuItem(char* name) : itemName(new char[MAX_STRING_LEN]) {
            std::memset(itemName,'\0',MAX_STRING_LEN);
            if (name != nullptr) {
                std::strcpy(itemName, name);
                itemName[MAX_STRING_LEN-1] = '\0';
            }
        };
        MenuItem(MenuItem& rMenuItem) = delete;
        MenuItem& operator=(MenuItem& rMenuItem) = delete;

        operator bool() const;
        operator const char*() const;

        std::ostream& display(std::ostream cout);

        friend class Menu;
    };

    class Menu {

        MenuItem currMenuItem;
        MenuItem menuItems[MAX_MENU_ITEMS];
        int menuItemsNum;

    public:

        Menu(): currMenuItem(), menuItemsNum(0), menuItems() {};
        ~Menu() = default;

        explicit Menu(char* title):
            currMenuItem(title),
            menuItems(),
            menuItemsNum(0) {};
        Menu(Menu& rMenu) = delete;
        Menu& operator=(Menu& rMenu) = delete;



    };
}

#endif