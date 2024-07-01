// Citation and Sources

//Final Project Milestone 1
//Module:   Date
//Filename: Date.h
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

#ifndef SENECA_DATE_H__
#define SENECA_DATE_H__
#include <iostream>
namespace seneca {

    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int YEAR_ERROR = 2;
    const int MON_ERROR = 3;
    const int  DAY_ERROR = 4;
    const char DATE_ERROR[5][16] = {
      "No Error",
      "cin Failed",
      "Bad Year Value",
      "Bad Month Value",
      "Bad Day Value"
    };
    const int MIN_YEAR = 1500;
    const int BUFFER_CLEARER = 2000;

    class Date {
    private:
        int m_year;                         // 1500 ~ 2024
        int m_mon;                          // 0 ~ 12
        int m_day;                          // 0 ~ 31 {1, 3, 5, 7, 8, 10, 12}, 0 ~ 30 {4, 6, 9, 11}, 0 ~ 28 {2}
                                            // 0 ~ 29 {2} when year % 4 == 0 then year % 100 != 0 || year % 400 == 0
        int m_ErrorCode;
        int m_CUR_YEAR;
        int daysSince0001_1_1() const;      // returns number of days passed since the date 0001/1/1
        bool validate();                    /* validates the date setting the error code and then returning the result
                                                true, if valid, and false if invalid.*/
        void errCode(int);                  // sets the error code
        int systemYear() const;             // returns the current system year
        bool bad() const;                   // return true if
        int mdays() const;                  // returns the number of days in current month
        void setToToday();                  // sets the date to the current date (system date)

    public:
        Date();                             // creates a date with current date
        Date(int year, int mon, int day);   /* create a date with assigned values
                                                 then validates the date and sets the
                                                 error code accordingly */

        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout) const;

        bool operator== (const Date& rhs) const;
        bool operator>= (const Date& rhs) const;
        bool operator<= (const Date& rhs) const;
        bool operator!= (const Date& rhs) const;
        bool operator> (const Date& rhs) const;
        bool operator< (const Date& rhs) const;

        int operator-(const Date& rhs);
        operator bool() const;

        int errCode() const;                // returns the error code or zero if date is valid
        const char* dateStatus()const;      // returns a string corresponding the current status of the date
        int currentYear()const;             // returns the m_CUR_YEAR value;

   };

   std::ostream& operator<<(std::ostream& os, const Date& RO);
   std::istream& operator>>(std::istream& is, Date& RO);

}

#endif