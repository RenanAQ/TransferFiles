/*
Student: Renan de Alencar Queiroz
ID: 129280236
*/
#include "Lib.h"
#include "Publication.h"
#include "Date.h"
#include <iomanip>
#include <sstream>
#include <cstring>

namespace seneca {

    Publication::Publication() : m_title(nullptr), m_membership(0), m_date() {
        m_shelfId[0] = '\0'; // This attribute is an empty string by default.
        m_libRef = -1; // This attribute is -1 by default.
    }

    Publication::~Publication() {
        delete[] m_title;
        m_title = nullptr;
    }

    Publication::Publication(const Publication& other) : Publication() {
        *this = other;
    }

    Publication& Publication::operator=(const Publication& other) {
        if (this != &other) {
            delete[] m_title;
            m_title = nullptr;
            m_title = new char[std::strlen(other.m_title) + 1];
            std::strcpy(m_title, other.m_title);
            std::strcpy(m_shelfId, other.m_shelfId);
            m_membership = other.m_membership;
            m_libRef = other.m_libRef;
            m_date = other.m_date;
        }
        return *this;
    }

    bool Publication::conIO(std::ios& io) const {
        return &io == &std::cin || &io == &std::cout;
    }
    std::string intToString(int num) {
        std::ostringstream oss;
        oss << num;
        return oss.str();
    }

    std::ostream& Publication::write(std::ostream& os) const {
        if (conIO(os)) {
            os << "| " << m_shelfId << " | "
                << std::left << std::setw(SENECA_TITLE_WIDTH) << std::setfill('.') << m_title
                << " | " << std::setw(5) << std::setfill(' ') << (m_membership != 0 ? intToString(m_membership) : " N/A")
                << " | " << m_date << " |";
        }
        else {
            os << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t'
                << m_title << '\t' << m_membership << '\t' << m_date;
        }
        return os;
    }

    std::istream& Publication::read(std::istream& is) {
        char title[256] = { 0 }, shelfId[SENECA_SHELF_ID_LEN + 1] = { 0 };
        int membership = 0, libRef = 0;
        Date date;

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
            }
            if (date.errCode() != NO_ERROR) {
                is.setstate(std::ios::failbit);
            }
            else if (is) {
                delete[] m_title;
                m_title = nullptr;
                m_title = new char[std::strlen(title) + 1];
                std::strcpy(m_title, title);
                std::strcpy(m_shelfId, shelfId);
                m_membership = membership;
                m_date = date;
                m_libRef = libRef;
            }
        }
        else {
            is >> libRef;
            is.ignore();
            is.getline(shelfId, SENECA_SHELF_ID_LEN + 1, '\t');
            is.getline(title, 256, '\t');
            is >> membership;
            is >> date;
            if (is) {
                delete[] m_title;
                m_title = nullptr;
                m_title = new char[std::strlen(title) + 1];
                std::strcpy(m_title, title);
                std::strcpy(m_shelfId, shelfId);
                m_membership = membership;
                m_date = date;
                m_libRef = libRef;
            }
        }

        return is;
    }

    Publication::operator bool() const {
        return m_title != nullptr && m_shelfId[0] != '\0';
    }

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
}
