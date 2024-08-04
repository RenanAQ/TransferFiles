/*
Student: Renan de Alencar Queiroz
ID: 129280236
*/

#ifndef SENECA_LIBAPP_H
#define SENECA_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
#include "PublicationSelector.h"
#include "Book.h"
#include "Utils.h"
namespace seneca {
    class LibApp {
        bool m_changed{};
        Menu m_mainMenu = { "Seneca Library Application" };
        Menu m_exitMenu = { "Changes have been made to the data, what would you like to do?" };
        Menu m_pubType = { "Choose the type of publication:" };
        char m_fileName[256]{};
        Publication* PPA[SENECA_LIBRARY_CAPACITY]{};
        int LLRN{};
        int NOLP{};
        Publication* getPub(int libRef);
        bool confirm(const char* message);
        void load();
        void save();
        int search(int);
        void returnPub();
        void newPublication();
        void removePublication();
        void checkOutPub();
    public:
        LibApp();
        explicit LibApp(const char*&);
        ~LibApp();
        void run();
    };
}
#endif