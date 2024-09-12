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
    if (month == 1 || month == 3 || month == 5 || month == 7
        || month == 8 || month == 10 || month == 12)
        return 31;
    else if (month == 2) {
        return isLeapYear() ? 29 : 28;
    }
    return 30;
}

void Date::nextDate()
{
    if (month == 12 && day == 31) {
        day = 1;
        month = 1;
        year++;
    }
    else if (day == monthDays()) {
        day = 1;
        month++;
    }
    else {
        day++;
    }
}

void Date::prevDate()
{
    if (day == 1 && month == 1) {
        day = 31;
        month = 12;
        year--;
    }
    else if (day == 1) {
        month--;
        day = monthDays();
    }
    else day--;
}

bool Date::valid() const
{
    return (month >= 1 && month <= 12) && (day >= 1 && day <= monthDays());
}

void Date::setYear(int year){
    this->year = year;
}

int Date::getYear() const{
    return year;
}

void Date::setMonth(int month){
    if (month >= 1 && month <= 12)
        this->month = month;
}

int Date::getMonth() const{
    return month;
}

void Date::setDay(int day){
    if (day >= 1 && day <= monthDays())
        this->day = day;
}

int Date::getDay() const{
    return day;
}

Date& Date::operator--(){
    this->prevDate();
    return *this;
}

Date Date::operator--(int){
    Date tmp = *this;
    this->prevDate();
    return tmp;
}

Date& Date::operator++(){
    this->nextDate();
    return *this;
}

Date Date::operator++(int){
    Date tmp = *this;
    this->nextDate();
    return tmp;
}

bool Date::operator==(const Date& obj) const&
{
    return year == obj.year && month == obj.month && day == obj.day;
}

bool Date::operator!=(const Date& obj) const&
{
    //return year != obj.year || month != obj.month || day != obj.day;
    return !(*this == obj);
}

bool Date::operator>(const Date& obj) const&
{
    if (year > obj.year) return true;
    else  if (year == obj.year && month > obj.month) return true;
    else  if (year == obj.year && month == obj.month &&  day > obj.day) 
        return true;

    return false;
}

bool Date::operator<(const Date& obj) const&{
    return !(*this> obj) && *this != obj;
}

bool Date::operator>=(const Date& obj) const&{
    return (*this > obj) || * this == obj;
}

bool Date::operator<=(const Date& obj) const&{
    return (*this < obj) || *this == obj;
}

ostream& operator<<(ostream& os, const Date& t)
{
    os << t.day / 10 << t.day % 10 << "."
        << t.month / 10 << t.month % 10 << "."
        << t.year;

    return os;
}

istream& operator>>(istream& is, Date& t)
{
    do   {
        cout << "dd mm yyyy: ";
        is >> t.day >> t.month >> t.year;
    } while (!t.valid());

    return is;
}
