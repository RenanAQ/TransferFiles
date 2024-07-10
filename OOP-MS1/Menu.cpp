/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <cstring>
#include <iostream>

namespace seneca {
	MenuItem::MenuItem(const char* m_value)
	{
		if (m_value && m_value[0] != '\0')
		{
			this->m_value = new char[strlen(m_value) + 1];
			strcpy(this->m_value, m_value);
		}
		else
		{
			this->m_value = nullptr;
		}
	}
	MenuItem::~MenuItem()
	{
		delete[] m_value;
		m_value = nullptr;
	}
	MenuItem::operator bool() const
	{
		return (m_value != nullptr);
	}
	MenuItem::operator const char* () const
	{
		return m_value;
	}
	void MenuItem::view(std::ostream& ostr) const
	{
		if (*this) {
			ostr << m_value;
		}
	}
	Menu::Menu()
	{
		m_title = nullptr;
		m_storedItems = 0;
		for (unsigned int i = 0; i < MAX_MENU_ITEM; i++)
		{
			m_items[i] = nullptr;
		}
	}
	Menu::Menu(const char* name)
	{
		Menu();
		m_title = new MenuItem(name);
	}
	Menu::~Menu()
	{
		delete[] m_title;
		for (unsigned int i = 0; i < m_storedItems; i++)
		{
			delete m_items[i];
		}
	}
	void Menu::viewTitle(std::ostream& ostr) const
	{
		if (m_title) {
			m_title->view(ostr);
		}
	}
	void Menu::displayMenu(std::ostream& ostr) const
	{
		viewTitle(ostr);
		if (m_title)
		{
			ostr << ":" << std::endl;
		}
		for (int i = 1; i < m_storedItems+1; i++)
		{
			ostr << i << "- ";
			m_items[i]->view(ostr);
			ostr << std::endl;
		}
		ostr << "0-Exit" << std::endl << ">";

	}
	unsigned int Menu::run()
	{	
		int a;
		bool isValid = false;
		
		do
		{	
			displayMenu(std::cout);
			std::cin >> a;
			if (!(a >= 0 && a <= m_storedItems))
			{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				std::cout << "Invalid Selection, try again: ";
			}
			else
			{
				isValid = true;
			}

		} while (!isValid);
		
		return a;
	}
	unsigned int Menu::operator~()
	{	
		return run();
	}
	Menu& Menu::operator<<(const char* menuItemContent)
	{
		if (m_storedItems < MAX_MENU_ITEM)
		{
			m_items[m_storedItems++] = new MenuItem(menuItemContent);
		}
		return (*this);
	}
	Menu::operator int() const
	{
		return m_storedItems;
	}
	Menu::operator unsigned int() const
	{
		return m_storedItems;
	}
	Menu::operator bool() const
	{
		return m_storedItems > 0;
	}
	const char* Menu::operator[](unsigned int index) const
	{
		return *m_items[index % m_storedItems];
	}
	std::ostream& operator<<(std::ostream os, const Menu& menu)
	{
		if (menu.m_title) {
			menu.m_title->view(os);
		}
		return os;
	}
}
