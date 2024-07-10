/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author	Renan Queiroz
Revision History
-----------------------------------------------------------
Date      Reason
2024/7/1  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_MENU_H__
#define SENECA_MENU_H__
#include <iostream>
using namespace std;
namespace seneca {
	const unsigned int MAX_MENU_ITEM = 20;

	class Menu;

	class MenuItem {
		char* m_value;
		MenuItem(const char* m_value = nullptr);
		~MenuItem();
		MenuItem(const MenuItem&) = delete;
		MenuItem& operator=(const MenuItem&) = delete;
		operator bool()const;
		operator const char* ()const;
		void view(std::ostream& ostr)const;

		friend class Menu;
	};
	class Menu
	{
		MenuItem* m_title;
		MenuItem* m_items[MAX_MENU_ITEM];
		unsigned int m_storedItems;

	public:
		Menu(const Menu&) = delete;
		Menu& operator=(const Menu&) = delete;
		Menu();
		Menu(const char* name);
		~Menu();
		void viewTitle(std::ostream& ostr)const;
		void displayMenu(std::ostream& ostr)const;
		unsigned int run();
		unsigned int operator~();
		Menu& operator<<(const char* menuItemContent);
		operator int()const;
		operator unsigned int()const;
		operator bool()const;
		const char* operator[](unsigned int index)const;

		friend ostream& operator<<(ostream& os, Menu& menu);
	};
}
#endif