#pragma once

#include <iostream>
#include "Date.h"
class Vehicle
{
private:
	Date* date;
	std::string type;
	int mileage;
	std::string vehicle_id;
	int availability_array[361];
public:
	Vehicle();
	Vehicle(Date*, std::string, int, std::string);
	Date* getDate();
	std::string getType();
	int getMileage();
	std::string getID();
	bool getAvailability(int, int);
	void setDate(Date*);
	void setType(std::string);
	void setMileage(int);
	void setID(std::string);
	void setAvailability(int, int, int);
	virtual ~Vehicle();
};

