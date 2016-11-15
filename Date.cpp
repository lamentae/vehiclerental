#include "Date.h"



Date::Date()
{
	day = 1;
	month = 1;
	year = 2016;
}

Date::Date(int m, int d, int y)
{
	setMonth(m);
	setDay(d);
	setYear(y);
}

int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}

int Date::getYear()
{
	return year;
}

void Date::setMonth(int m)
{
	//Check if input is valid. Else, set to default value
	if (m > 12 || m < 1)
		m = 1;
	month = m;
}

void Date::setDay(int d)
{
	//Check if input is valid. Else, set to default value
	if (d > 30 || d < 1)
		d = 1;
	day = d;
}

void Date::setYear(int y)
{
	//Check if input is valid. Else, set to default value
	if (y > 2020 || y < 2000)
		y = 2016;
	year = y;
}

Date::~Date()
{
}
