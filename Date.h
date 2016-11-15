#pragma once
class Date
{
private:
	int month; //1-12
	int day; //1-30
	int year; //2016 - 
public:
	Date();
	Date(int, int, int);
	int getMonth();
	int getDay();
	int getYear();
	void setMonth(int);
	void setDay(int);
	void setYear(int);
	~Date();
};

