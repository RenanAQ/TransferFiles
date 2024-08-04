/* Citation and Sources...
Final Project Milestone 2
Module: LibApp
Filename: LibApp.h
Version 1.0
Author	Renan Queiroz
Revision History
-----------------------------------------------------------
Date      Reason
2024/7/16  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_LIBAPP_H
#define SENECA_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
#include <fstream>
#include <cstring>

namespace seneca {
    class LibApp {
        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;
        Menu m_publicationType; // Publication Type Menu
        char m_fileName[256]; // File name
        Publication* PPA[SENECA_LIBRARY_CAPACITY]; // Publication Pointers Array
        int NOLP; // Number Of Loaded Publications
        int LLRN; // Last Library Reference Number

        bool confirm(const char* message);
        void load();
        void save();
        int search(int mode); // modified to accept a mode argument
        void returnPub();
        void newPublication();
        void removePublication();
        void checkOutPub();
        Publication* getPub(int libRef); // new method

    public:
        LibApp(const char* fileName); // constructor to initialize with a file name
        ~LibApp();
        void run();
    };
}
#endif // !SENECA_LIBAPP_H



