#include "Vehicle.h"



Vehicle::Vehicle()
{
	date = new Date();
	type = "NONE";
	mileage = 0;
	vehicle_id = "0000";

	for (int i = 0; i < 361; i++)
		availability_array[i] = 0;
}

Vehicle::Vehicle(Date* d, std::string t, int m, std::string id)
{
	date = new Date(); date = d;
	type = t;
	mileage = m;
	vehicle_id = id;

	for (int i = 0; i < 361; i++)
		availability_array[i] = 0;
}

Date* Vehicle::getDate()
{
	return date;
}

std::string Vehicle::getType()
{
	return type;
}

int Vehicle::getMileage()
{
	return mileage;
}

std::string Vehicle::getID()
{
	return vehicle_id;
}

bool Vehicle::getAvailability(int start, int end)
{
	for (int i = start; i < end; i++)
	{
		if (availability_array[i] != 0)
			return false;
	}
	return true;
}

void Vehicle::setDate(Date* d)
{
	date = d;
}

void Vehicle::setType(std::string t)
{
	type = t;
}

void Vehicle::setMileage(int m)
{
	mileage = m;
}

void Vehicle::setID(std::string id)
{
	vehicle_id = id;
}

void Vehicle::setAvailability(int start, int stop, int contractNumber)
{
	for (int i = start; i < stop; i++)
		availability_array[i] = contractNumber;
}

Vehicle::~Vehicle()
{
	//need to delete date since it was created using dynamic memory allocation
	delete date;
}
