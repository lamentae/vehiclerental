#pragma once

#include <iostream>
#include "Vehicle.h"
class Car : public Vehicle
{
private:
	std::string size;
	static int cars_in_fleet;
public:
	Car();
	Car(Date*, std::string, int, std::string, std::string);
	void setSize(std::string);
	std::string getSize();
	static int getFleetSize();
	~Car();
};

