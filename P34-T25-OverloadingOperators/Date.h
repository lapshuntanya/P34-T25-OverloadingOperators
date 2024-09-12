#pragma once
#include <iostream>
using namespace std;

class Date
{
	int year;
	int month;
	int day;

public:
	//--------- КОНСТРУКТОРИ та ДЕСТРУКТОРИ ---------
	Date(); // За замовчуванням - поточна дата
	Date(int year, int month, int day); // З параметрами - задана дата	 

	bool isLeapYear()const; //Перевірка на високосний рік
	int monthDays()const; //Кількість днів за місяцем
	void nextDate(); // Наступна дата
	void prevDate(); // Попередня дата        
	bool valid()const; // Перевірка дати на коректність

	//--------- АКСЕСОРИ ---------
	void setYear(int year);
	int getYear()const;
	void setMonth(int month);
	int getMonth()const;
	void setDay(int day);
	int getDay()const;


	//--------- ОПЕРАТОРИ виведення та введення
	friend ostream& operator << (ostream& os, const Date& t);
	friend istream& operator >> (istream& is, Date& t);

};

