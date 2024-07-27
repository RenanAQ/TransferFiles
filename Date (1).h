// Final Project Milestone 1 
// Date Module
// File	Date.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name:Agenor Junior       Date: 2024-07-25       Reason: MS3
// 
/////////////////////////////////////////////////////////////////
#ifndef DATE_H
#define DATE_H

#include <iostream>

namespace seneca {
    extern bool seneca_test;
    extern int seneca_year;
    extern int seneca_mon;
    extern int seneca_day;

    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int YEAR_ERROR = 2;
    const int MON_ERROR = 3;
    const int DAY_ERROR = 4;

    class Date {
        int m_year;
        int m_mon;
        int m_day;
        int m_ErrorCode;
        int m_CUR_YEAR;

        int daysSince0001_1_1() const;
        bool validate();
        void errCode(int);
        int systemYear() const;
        bool bad() const;
        int mdays() const;

    public:
        void setToToday();
        Date();
        Date(int year, int mon, int day);
        int errCode() const;
        const char* dateStatus() const;
        int currentYear() const;
        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout) const;
        bool operator==(const Date& rhs) const;
        bool operator!=(const Date& rhs) const;
        bool operator>=(const Date& rhs) const;
        bool operator<=(const Date& rhs) const;
        bool operator<(const Date& rhs) const;
        bool operator>(const Date& rhs) const;
        int operator-(const Date& rhs) const;
        operator bool() const;
    };

    std::ostream& operator<<(std::ostream& os, const Date& RO);
    std::istream& operator>>(std::istream& is, Date& RO);
}

#endif // DATE_H
