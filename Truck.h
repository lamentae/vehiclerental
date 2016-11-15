#pragma once
#include "Vehicle.h"
class Truck : public Vehicle
{
private:
	int length;
	static int trucks_in_fleet;
public:
	Truck();
	Truck(Date*, std::string, int, std::string, int);
	void setLength(int);
	int getLength();
	static int getFleetSize();
	~Truck();
};

