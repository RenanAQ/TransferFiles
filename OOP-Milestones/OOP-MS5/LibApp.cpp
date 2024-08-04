/* Citation and Sources...
Final Project Milestone 2
Module: LibApp
Filename: LibApp.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include "LibApp.h"
#include "Book.h"
#include "PublicationSelector.h"
#include <iostream>
#include <fstream>

namespace seneca {

    bool LibApp::confirm(const char* message) {
        Menu objMenu(message);
        objMenu << "Yes";
        return objMenu.run() == 1;
    }

    void LibApp::load() {
        std::cout << "Loading Data" << std::endl;
        std::ifstream fin(m_fileName);
        NOLP = 0;
        LLRN = 0;
        char type;
        while (fin >> type) {
            fin.ignore();
            Publication* pub = nullptr;
            if (type == 'P') {
                pub = new Publication();
            }
            else if (type == 'B') {
                pub = new Book();
            }
            if (pub) {
                fin >> *pub;
                if (fin) {
                    PPA[NOLP++] = pub;
                    if (pub->getRef() > LLRN) {
                        LLRN = pub->getRef();
                    }
                }
                else {
                    delete pub;
                }
            }
        }
    }

    void LibApp::save() {
        std::cout << "Saving Data" << std::endl;
        std::ofstream fout(m_fileName);
        for (int i = 0; i < NOLP; ++i) {
            if (PPA[i]->getRef() != 0) {
                fout << *PPA[i] << std::endl;
            }
        }
    }

    int LibApp::search(int mode) {
        std::cout << "Searching for publication" << std::endl;
        PublicationSelector selector("Select one of the following found matches:", 15);
        m_publicationType.displayMenu(std::cout);
        int pubType = m_publicationType.run();
        if (pubType == 0) {
            std::cout << "Aborted!" << std::endl;
            return 0;
        }
        char type = pubType == 1 ? 'B' : 'P';
        char title[256];
        std::cout << "Publication Title: ";
        std::cin.ignore();
        std::cin.getline(title, 256);

        for (int i = 0; i < NOLP; ++i) {
            if (PPA[i]->getRef() != 0 && PPA[i]->type() == type && *PPA[i] == title) {
                if (mode == 1 || (mode == 2 && PPA[i]->onLoan()) || (mode == 3 && !PPA[i]->onLoan())) {
                    selector << PPA[i];
                }
            }
        }

        if (selector) {
            int ref = selector.run();
            if (ref != 0) {
                return ref; // Return the selected reference number
            }
        }
        else {
            std::cout << "No matches found!" << std::endl;
        }
        std::cout << "Aborted!" << std::endl;
        return 0;
    }

    Publication* LibApp::getPub(int libRef) {
        for (int i = 0; i < NOLP; ++i) {
            if (PPA[i]->getRef() == libRef) {
                return PPA[i];
            }
        }
        return nullptr;
    }

    void LibApp::newPublication() { //case 1
        if (NOLP == SENECA_LIBRARY_CAPACITY) {
            std::cout << "Library is at its maximum capacity!" << std::endl;
            return;
        }

        std::cout << "Adding new publication to the library" << std::endl;
        m_publicationType.displayMenu(std::cout);
        int pubType = m_publicationType.run();
        if (pubType == 0) {
            std::cout << "Aborted!" << std::endl;
            return;
        }
        Publication* pub = pubType == 1 ? new Book() : new Publication();
        std::cin >> *pub;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            delete pub;
            std::cout << "Aborted!" << std::endl;
            return;
        }
        if (confirm("Add this publication to the library?")) {
            LLRN++;
            pub->setRef(LLRN);
            PPA[NOLP++] = pub;
            m_changed = true;
            std::cout << "Publication added" << std::endl;
        }
        else {
            delete pub;
            std::cout << "Aborted!" << std::endl;
        }
    }

    void LibApp::removePublication() {
        std::cout << "Removing publication from the library" << std::endl;
        int ref = search(1); // Search all publications
        if (ref != 0 && confirm("Remove this publication from the library?")) {
            getPub(ref)->setRef(0);
            m_changed = true;
            std::cout << "Publication removed" << std::endl;
        }
    }

    void LibApp::checkOutPub() {
        std::cout << "Checkout publication from the library" << std::endl;
        int ref = search(3); // Search available publications
        if (ref != 0 && confirm("Check out publication?")) {
            int membership;
            do {
                std::cout << "Enter membership number: ";
                std::cin >> membership;
                if (membership < 10000 || membership > 99999) {
                    std::cout << "Invalid membership number, try again: ";
                }
            } while (membership < 10000 || membership > 99999);
            getPub(ref)->set(membership);
            getPub(ref)->resetDate();
            m_changed = true;
            std::cout << "Publication checked out" << std::endl;
        }
    }

    void LibApp::returnPub() {
        std::cout << "Return publication to the library" << std::endl;
        int ref = search(2); // Search checked out publications
        if (ref != 0 && confirm("Return publication?")) {
            Date checkoutDate = getPub(ref)->checkoutDate();
            Date today;
            int days = today - checkoutDate;
            if (days > 15) {
                std::cout << "Please pay $" << (days - 15) * 0.5 << " penalty for being " << (days - 15) << " days late!" << std::endl;
            }
            getPub(ref)->set(0);
            m_changed = true;
            std::cout << "Publication returned" << std::endl;
        }
    }

    LibApp::LibApp(const char* fileName) : m_changed(false), 
        m_mainMenu("Seneca Library Application"),
        m_exitMenu("Changes have been made to the data, what would you like to do?"), 
        m_publicationType("Choose the type of publication:") {
        strncpy(m_fileName, fileName, 255);
        m_fileName[255] = '\0';
        m_mainMenu << "Add New Publication"
            << "Remove Publication"
            << "Checkout publication from library"
            << "Return publication to library";
        m_exitMenu << "Save changes and exit"
            << "Cancel and go back to the main menu";
        m_publicationType << "Book"
            << "Publication";
        load();
    }

    LibApp::~LibApp() {
        for (int i = 0; i < NOLP; ++i) {
            delete PPA[i];
        }
    }

    void LibApp::run() {
        bool done = false;
        while (!done) {
            switch (m_mainMenu.run()) {
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            case 0:
                if (m_changed) {
                    switch (m_exitMenu.run()) {
                    case 1:
                        save();
                        done = true;
                        break;
                    case 0:
                        if (confirm("This will discard all the changes are you sure?")) {
                            done = true;
                        }
                        break;
                    case 2:
                        break;
                    }
                }
                else {
                    done = true;
                }
                break;
            }
        }
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Thanks for using Seneca Library Application" << std::endl;
    }
}
