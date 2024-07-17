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

#include "LibApp.h"
#include <iostream>
namespace seneca {
	bool LibApp::confirm(const char* message)
	{
		Menu objMenu(message);
		objMenu << "Yes"; //overloading operator
		return objMenu.run() == 1;
	}
	void LibApp::load()
	{
		std::cout << "Loading Data" << std::endl;
	}
	void LibApp::save()
	{
		std::cout << "Saving Data" << std::endl;
	}
	void LibApp::search()
	{
		std::cout << "Searching for publication" << std::endl;
	}
	void LibApp::returnPub() //case 4
	{
		search();
		std::cout << "Returning publication" << std::endl;
		std::cout << "Publication returned" << std::endl;
		m_changed = true;
	}
	void LibApp::newPublication() //case 1
	{
		std::cout << "Adding new publication to library" << std::endl;
		if (confirm("Add this publication to library?"))
		{
			m_changed = true;

		}

	}
	void LibApp::removePublication() //case 2
	{
		std::cout << "Removing publication from library" << std::endl;
		search();
		if (confirm("Remove this publication from the library?"))
		{
			m_changed = true;
			std::cout << "Publication removed" << std::endl;
		}
		
	}
	void LibApp::checkOutPub() //case 3
	{
		search();
		if (confirm("Check out publication?"))
		{
			m_changed = true;
			std::cout << "Publication checked out" << std::endl;
		}
	}
	LibApp::LibApp():
		m_changed(false),
		m_mainMenu("Seneca Library Application"),
		m_exitMenu("Changes have been made to the data, what would you like to do?")
	{
		m_mainMenu << "Add New Publication"
				   << "Remove Publication"
				   << "Checkout publication from library"
				   << "Return publication to library";
		
		m_exitMenu << "Save changes and exit"
			   	   << "Cancel and go back to the main menu";

		load();
	}
	LibApp::~LibApp()
	{
	}
	void LibApp::run() {
		bool done = false;
		while (!done) {
			switch (m_mainMenu.run()) {
			case 1:
				newPublication();
				std::cout << std::endl; //added to match the output
				break;
			case 2:
				removePublication();
				std::cout << std::endl; //added to match the output
				break;
			case 3:
				checkOutPub();
				std::cout << std::endl; //added to match the output
				break;
			case 4:
				returnPub();
				std::cout << std::endl; //added to match the output
				break;
			case 0:
				if (m_changed) {
					switch (m_exitMenu.run()) {
					case 1:
						save();
						done = true;
						std::cout << std::endl; //added to match the output
						break;
					case 0:
						if (confirm("This will discard all the changes are you sure?")) {
							done = true;
						}
						std::cout << std::endl; //added to match the output
						break;
					case 2:
						done = false; //return to main menu
						std::cout << std::endl; //added to match the output
						break;
					}
				}
				else {
					done = true;
					std::cout << std::endl; //added to match the output
				}
				break;
			}
		}
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}
}
