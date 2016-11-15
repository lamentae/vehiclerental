#include "Car.h"

int Car::cars_in_fleet = 0;

Car::Car() : Vehicle()
{
	size = "NONE";
	cars_in_fleet++;
}

Car::Car(Date* d, std::string t, int m, std::string id, std::string s) : Vehicle(d, t, m, id)
{
	size = s;
	cars_in_fleet++;
}

void Car::setSize(std::string s)
{
	size = s;
}

std::string Car::getSize()
{
	return size;
}

int Car::getFleetSize()
{
	return cars_in_fleet;
}

Car::~Car()
{
}
