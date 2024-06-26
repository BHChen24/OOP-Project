// Citation and Sources

//Final Project Milestone 1
//Module:   Date
//Filename: Date.cpp
//Version   0.1
//Author:   Baihua Chen

//Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Baihua Chen        2024-06-25           First version, v0.1
// -----------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>
#include <ctime>

using namespace std;

#include "Date.h"

namespace seneca {

    bool Date::validate() {
        errCode(NO_ERROR);
        if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
            errCode(YEAR_ERROR);
        } else if (m_mon < 1 || m_mon > 12) {
            errCode(MON_ERROR);
        } else if (m_day < 1 || m_day > mdays()) {
            errCode(DAY_ERROR);
        }
        return !bad();
    }

    int Date::mdays() const {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1};
        int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
    }

    int Date::systemYear() const {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        return lt.tm_year + 1900;
    }

    void Date::setToToday() {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        m_day = lt.tm_mday;
        m_mon = lt.tm_mon + 1;
        m_year = lt.tm_year + 1900;
        errCode(NO_ERROR);
    }

    int Date::daysSince0001_1_1() const { // Rata Die day since 0001/01/01
        int ty = m_year;
        int tm = m_mon;
        if (tm < 3) {
            ty--;
            tm += 12;
        }
        return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
    }

    Date::Date() : m_CUR_YEAR(systemYear()) {
        setToToday();
    }

    Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
        m_year = year;
        m_mon = mon;
        m_day = day;
        validate();
    }

    const char* Date::dateStatus() const {
        return DATE_ERROR[errCode()];
    }

    int Date::currentYear() const {
        return m_CUR_YEAR;
    }

    void Date::errCode(int readErrorCode) {
        m_ErrorCode = readErrorCode;
    }

    int Date::errCode() const {
        return m_ErrorCode;
    }

    bool Date::bad() const {
        return m_ErrorCode != 0;
    }

    ostream& operator<<(ostream& os, const Date& RO) {
        return RO.write(os);
    }

    istream& operator>>(istream& is, Date& RO) {
        return RO.read(is);
    }

    std::istream& Date::read(istream& is) {
        errCode(NO_ERROR);

//        if (is >> m_year) {
//            is.ignore();
//        } else {
//            errCode(CIN_FAILED);
//            is.clear();
//        }
//        if (is >> m_mon) {
//            is.ignore();
//        } else {
//            errCode(CIN_FAILED);
//            is.clear();
//        }
//        if (is >> m_day) {
//            validate();
//        } else {
//            errCode(CIN_FAILED);
//            is.clear();
//        }

        if (!(is >> m_year)) {
            errCode(CIN_FAILED);
            is.clear();
        } else if (is.ignore(), !(is >> m_mon)) {
            errCode(CIN_FAILED);
            is.clear();
        } else if (is.ignore(), !(is >> m_day)) {
            errCode(CIN_FAILED);
            is.clear();
        }

        if (!bad()) {
            validate();
        }

        is.ignore(BUFFER_CLEARER,'\n');

        return is;
    }

    std::ostream& Date::write(ostream& os) const {
        if (bad()) {
            os << dateStatus() << '\n';
            return os;
        }

        os << m_year << '/';
        os.width(2);
        os.fill('0');
        os << m_mon << '/';
        os.width(2);
        os << m_day;
        os.fill(' ');

        return os;
    }

    bool Date::operator==(const Date& rhs) const{

        return daysSince0001_1_1() == rhs.daysSince0001_1_1();
    }

    bool Date::operator>=(const Date& rhs) const{

        return daysSince0001_1_1() >= rhs.daysSince0001_1_1();
    }

    bool Date::operator<=(const Date& rhs) const{

        return daysSince0001_1_1() <= rhs.daysSince0001_1_1();
    }

    bool Date::operator!=(const Date& rhs) const{

        return daysSince0001_1_1() != rhs.daysSince0001_1_1();
    }

    bool Date::operator>(const Date& rhs) const{

        return daysSince0001_1_1() > rhs.daysSince0001_1_1();
    }

    bool Date::operator<(const Date& rhs) const{

        return daysSince0001_1_1() < rhs.daysSince0001_1_1();
    }

    int Date::operator-(const Date& rhs) {

        return daysSince0001_1_1() - rhs.daysSince0001_1_1();
    }

    Date::operator bool() const{

        return m_ErrorCode == 0;
    }
}
