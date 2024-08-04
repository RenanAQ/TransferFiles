/*
Student: Renan de Alencar Queiroz
ID: 129280236
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>

namespace seneca {

	Book::Book() : m_authorName(nullptr)
	{
	}

	Book::~Book()
	{
		delete[] m_authorName;
	}

	Book::Book(const Book& other) : Publication(other)
	{
		if (other.m_authorName) {
			m_authorName = new char[std::strlen(other.m_authorName) + 1];
			std::strcpy(m_authorName, other.m_authorName);
		}
		else {
			m_authorName = nullptr;
		}
	}

	Book& Book::operator=(const Book& other)
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

	char Book::type() const
	{
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os) const
	{
		Publication::write(os);
		if (conIO(os)) {
            os << " ";
            if (strlen(m_authorName) > SENECA_AUTHOR_WIDTH) {
                os << std::setw(SENECA_AUTHOR_WIDTH) << std::left << std::string(m_authorName).substr(0, SENECA_AUTHOR_WIDTH);
            }
            else {
                os << std::setw(SENECA_AUTHOR_WIDTH) << std::left << m_authorName;
            }
            os << " |";
        }
        else {
            os << "\t" << m_authorName;
        }
        return os;
	}

	std::istream& Book::read(std::istream& is)
	{
		char authorName[256];
        Publication::read(is);

        delete[] m_authorName;
        m_authorName = nullptr;

        if (conIO(is)) {
            is.ignore();
            std::cout << "Author: ";
            is.getline(authorName, 256);
        }
        else {
            is.get();
            is.getline(authorName, 256, '\n');
            is.putback('\n');
        }

        if (is) {
            delete[] m_authorName;
			if (authorName[0] != '\0') {
				m_authorName = new char[strlen(authorName) + 1];
				strcpy(m_authorName, authorName);
			}
			else {
				m_authorName = nullptr;
			}
        }

        return is;
	}

	void Book::set(int member_id)
	{
		Publication::set(member_id);
		Publication::resetDate();
	}

	Book::operator bool() const
	{
		return (m_authorName != nullptr && m_authorName[0] != '\0' && Publication::operator bool());
	}
}