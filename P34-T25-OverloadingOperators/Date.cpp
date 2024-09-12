#include "Date.h"
#include <ctime>

Date::Date()
{
    time_t now = time(0);
    tm* info = new tm;
    localtime_s(info, &now);
        
    year = info->tm_year + 1900;
    month = info->tm_mon + 1;
    day = info->tm_mday;
    delete info;
}

Date::Date(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

bool Date::isLeapYear() const
{
    return year%4 == 0&& year%100!=0 || year%400 == 0 ;
}

int Date::monthDays() const
{
    return 0;
}

void Date::nextDate()
{
}

void Date::prevDate()
{
}

bool Date::valid() const
{
    return false;
}

void Date::setYear(int year)
{
}

int Date::getYear() const
{
    return 0;
}

void Date::setMonth(int month)
{
}

int Date::getMonth() const
{
    return 0;
}

void Date::setDay(int day)
{
}

int Date::getDay() const
{
    return 0;
}
