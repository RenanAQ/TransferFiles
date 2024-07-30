/*
Student: Renan de Alencar Queiroz
ID: 129280236
*/
#include "Book.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>

namespace seneca {

	seneca::Book::Book() : m_authorName(nullptr)
	{
	}

	seneca::Book::~Book()
	{
		delete[] m_authorName;
	}

	seneca::Book::Book(const Book& other) : Publication(other)
	{
		if (other.m_authorName) {
			m_authorName = new char[std::strlen(other.m_authorName) + 1];
			std::strcpy(m_authorName, other.m_authorName);
		}
		else {
			m_authorName = nullptr;
		}
	}

	Book& seneca::Book::operator=(const Book& other)
	{
		if (this != &other) {
			Publication::operator=(other);
			delete[] m_authorName;
			if (other.m_authorName) {
				m_authorName = new char[std::strlen(other.m_authorName) + 1];
				std::strcpy(m_authorName, other.m_authorName);
			}
			else {
				m_authorName = nullptr;
			}
		}
		return *this;
	}

	char seneca::Book::type() const
	{
		return 'B';
	}

	std::ostream& seneca::Book::write(std::ostream& os) const
	{
		Publication::write(os);
		if (conIO(os))
		{
			if (std::strlen(m_authorName) <= SENECA_AUTHOR_WIDTH)
			{
				os << " " << std::setw(SENECA_AUTHOR_WIDTH) << m_authorName << " |";;
			}
			else
			{
				os << " " << std::setw(SENECA_AUTHOR_WIDTH);
				for (int i = 0; i < SENECA_AUTHOR_WIDTH; i++)
				{
					os << m_authorName[i];
				}
				os << " |";
			}
		}
		else
		{
			os << '\t' << m_authorName;
		}
		return os;
	}

	std::istream& seneca::Book::read(std::istream& is)
	{
		char authorName[256]{};
		Publication::read(is);

		delete[] m_authorName;
		m_authorName = nullptr;

		if (conIO(is))
		{
			is.ignore();
			std::cout << "Author: ";
			is.getline(authorName, SENECA_AUTHOR_WIDTH + 1);
		}
		else
		{
			is.ignore();
			is.getline(authorName, SENECA_AUTHOR_WIDTH + 1);
		}
		if (is)
		{
			if (authorName[0] != '\0')
			{
				m_authorName = new char(std::strlen(authorName) + 1);
				std::strcpy(m_authorName, authorName);
			}
		}
		return is;
	}

	void seneca::Book::set(int member_id)
	{
		Publication::set(member_id);
		Publication::resetDate();
	}

	seneca::Book::operator bool() const
	{
		return (m_authorName != nullptr && m_authorName[0] != '\0' && Publication::operator bool());
	}
}