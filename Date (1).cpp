// Final Project Milestone 3 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name: Agenor Junior    Date: 2024-07-25        Reason: MS3
// 
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Date.h"

namespace seneca {
    bool seneca_test = false;
    int seneca_year = 2024;
    int seneca_mon = 12;
    int seneca_day = 25;

    int Date::daysSince0001_1_1() const {
        int ty = m_year;
        int tm = m_mon;
        if (tm < 3) {
            ty--;
            tm += 12;
        }
        return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
    }

    bool Date::validate() {
        errCode(NO_ERROR);
        if (m_year < 1500 || m_year > systemYear() + 1) {
            errCode(YEAR_ERROR);
        }
        else if (m_mon < 1 || m_mon > 12) {
            errCode(MON_ERROR);
        }
        else if (m_day < 1 || m_day > mdays()) {
            errCode(DAY_ERROR);
        }
        return !bad();
    }

    void Date::errCode(int errorCode) {
        m_ErrorCode = errorCode;
    }

    int Date::systemYear() const {
        int theYear = seneca_year;
        if (!seneca_test) {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            theYear = lt.tm_year + 1900;
        }
        return theYear;
    }

    bool Date::bad() const {
        return m_ErrorCode != NO_ERROR;
    }

    int Date::mdays() const {
        int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31, -1 };
        int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
        mon--;
        return days[mon] + ((mon == 1) * ((m_year % 4 == 0 && m_year % 100 != 0) || (m_year % 400 == 0)));
    }

    void Date::setToToday() {
        if (seneca_test) {
            m_day = seneca_day;
            m_mon = seneca_mon;
            m_year = seneca_year;
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            m_day = lt.tm_mday;
            m_mon = lt.tm_mon + 1;
            m_year = lt.tm_year + 1900;
        }
        errCode(NO_ERROR);
    }

    Date::Date() : m_year(0), m_mon(0), m_day(0), m_ErrorCode(NO_ERROR), m_CUR_YEAR(systemYear()) {
        setToToday();
    }

    Date::Date(int year, int mon, int day) : m_year(year), m_mon(mon), m_day(day), m_ErrorCode(NO_ERROR), m_CUR_YEAR(systemYear()) {
        validate();
    }

    int Date::errCode() const {
        return m_ErrorCode;
    }

    const char* Date::dateStatus() const {
        static const char* status[] = { "No Error", "cin Failed", "Bad Year Value", "Bad Month Value", "Bad Day Value" };
        return status[m_ErrorCode];
    }

    int Date::currentYear() const {
        return m_CUR_YEAR;
    }

    std::istream& Date::read(std::istream& is) {
        is >> m_year;
        is.ignore();
        is >> m_mon;
        is.ignore();
        is >> m_day;
        if (is.fail()) {
            errCode(CIN_FAILED);
            is.clear();
        }
        else {
            validate();
        }
        return is;
    }

    std::ostream& Date::write(std::ostream& os) const {
        if (bad()) {
            os << dateStatus();
        }
        else {
            os << m_year << "/" << std::setw(2) << std::setfill('0') << m_mon << "/" << std::setw(2) << std::setfill('0') << m_day;
        }
        return os;
    }

    bool Date::operator==(const Date& rhs) const {
        return m_year == rhs.m_year && m_mon == rhs.m_mon && m_day == rhs.m_day;
    }

    bool Date::operator!=(const Date& rhs) const {
        return !(*this == rhs);
    }

    bool Date::operator>=(const Date& rhs) const {
        return daysSince0001_1_1() >= rhs.daysSince0001_1_1();
    }

    bool Date::operator<=(const Date& rhs) const {
        return daysSince0001_1_1() <= rhs.daysSince0001_1_1();
    }

    bool Date::operator<(const Date& rhs) const {
        return daysSince0001_1_1() < rhs.daysSince0001_1_1();
    }

    bool Date::operator>(const Date& rhs) const {
        return daysSince0001_1_1() > rhs.daysSince0001_1_1();
    }

    int Date::operator-(const Date& rhs) const {
        return daysSince0001_1_1() - rhs.daysSince0001_1_1();
    }

    Date::operator bool() const {
        return !bad();
    }

    std::ostream& operator<<(std::ostream& os, const Date& RO) {
        return RO.write(os);
    }

    std::istream& operator>>(std::istream& is, Date& RO) {
        return RO.read(is);
    }
}


