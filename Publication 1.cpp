#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include "Publication.h"
#include "Lib.h"

namespace seneca {

    std::string intToString(int num) {
        std::ostringstream oss;
        oss << num;
        return oss.str();
    }

    Publication::Publication()
        : m_title(nullptr), m_membership(0), m_libRef(-1), m_date() {
        m_shelfId[0] = '\0';
    }

    Publication::~Publication() {
        delete[] m_title;
    }

    Publication::Publication(const Publication& other) : Publication() {
        *this = other;
    }

    Publication& Publication::operator=(const Publication& other) {
        if (this != &other) {
            deallocate();
            allocateAndCopy(other.m_title);
            std::strcpy(m_shelfId, other.m_shelfId);
            m_membership = other.m_membership;
            m_libRef = other.m_libRef;
            m_date = other.m_date;
        }
        return *this;
    }
    ////

    void Publication::set(int member_id) {
        m_membership = member_id;
    }

    void Publication::setRef(int value) {
        m_libRef = value;
    }

    void Publication::resetDate() {
        m_date.setToToday();
    }

    char Publication::type() const {
        return 'P';
    }

    bool Publication::onLoan() const {
        return m_membership != 0;
    }

    Date Publication::checkoutDate() const {
        return m_date;
    }

    bool Publication::operator==(const char* title) const {
        return std::strstr(m_title, title) != nullptr;
    }

    Publication::operator const char* () const {
        return m_title;
    }

    int Publication::getRef() const {
        return m_libRef;
    }
    /// @brief /
    /// @param io 
    /// @return 
    bool Publication::conIO(std::ios& io) const {
        return &io == &std::cin || &io == &std::cout;
    }

    std::ostream& Publication::write(std::ostream& os) const {
        if (conIO(os)) {
            os << "| " << m_shelfId << " | "
                << std::left << std::setw(SENECA_TITLE_WIDTH) << std::setfill('.') << m_title
                << " | " << std::setw(5) << std::setfill(' ') << (m_membership != 0 ? intToString(m_membership).c_str() : " N/A")
                << " | " << m_date << " |";
        }
        else {
            os << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t'
                << m_title << '\t' << m_membership << '\t' << m_date;
        }
        return os;
    }

    std::istream& Publication::read(std::istream& is) {
        char title[256]{}, shelfId[SENECA_SHELF_ID_LEN + 1]{};
        int membership{}, libRef{};
        Date date;

        deallocate();

        if (conIO(is)) {
            std::cout << "Shelf No: ";
            is.getline(shelfId, SENECA_SHELF_ID_LEN + 1);
            if (std::strlen(shelfId) != SENECA_SHELF_ID_LEN) {
                is.setstate(std::ios::failbit);
            }
            else {
                std::cout << "Title: ";
                is.getline(title, 256);
                std::cout << "Date: ";
                is >> date;
               // is.ignore(); // Ignore the remaining newline character
            }
        }
        else {
            is >> libRef;
            is.ignore();
            is.getline(shelfId, SENECA_SHELF_ID_LEN + 1, '\t');
            is.getline(title, 256, '\t');
            is >> membership;
            is.ignore();
            is >> date;
        }

        if (date.errCode() != NO_ERROR) {
            is.setstate(std::ios::failbit);
        }
        else if (is) {
            allocateAndCopy(title);
            std::strcpy(m_shelfId, shelfId);
            m_membership = membership;
            m_date = date;
            m_libRef = libRef;
        }

        return is;
    }

    Publication::operator bool() const {
        return m_title != nullptr && m_shelfId[0] != '\0';
    }

    void Publication::allocateAndCopy(const char* title) {
        if (title) {
            m_title = new char[std::strlen(title) + 1];
            std::strcpy(m_title, title);
        }
    }

    void Publication::deallocate() {
        delete[] m_title;
        m_title = nullptr;
    }
}
