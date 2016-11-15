#include "Truck.h"

int Truck::trucks_in_fleet = 0;

Truck::Truck() : Vehicle()
{
	length = 0;
	trucks_in_fleet++;
}

Truck::Truck(Date* d, std::string t, int m, std::string id, int l) : Vehicle(d, t, m, id)
{
	length = l;
	trucks_in_fleet++;
}

void Truck::setLength(int l)
{
	length = l;
}

int Truck::getLength()
{
	return length;
}

int Truck::getFleetSize()
{
	return trucks_in_fleet;
}

Truck::~Truck()
{
}
