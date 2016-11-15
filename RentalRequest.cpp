#include "RentalRequest.h"

RentalRequest::RentalRequest()
{
	customer_name = "";
	driving_license_number = "";
	rentalDate = new Date();
	returnDate = new Date();
	type = "";
	car_size = "";
	truck_length = 0;
}

//Constructor for car
RentalRequest::RentalRequest(std::string name, std::string license, Date* rentDate, Date* retDate, std::string t, std::string size )
{
	customer_name = name;
	driving_license_number = license;
	rentalDate = new Date(); rentalDate = rentDate;
	returnDate = new Date(); returnDate = retDate;
	type = t;
	car_size = size;
	truck_length = 0;
}

//Constructor for truck
RentalRequest::RentalRequest(std::string name, std::string license, Date* rentDate, Date* retDate, std::string t, int length)
{
	customer_name = name;
	driving_license_number = license;
	rentalDate = new Date(); rentalDate = rentDate;
	returnDate = new Date(); returnDate = retDate;
	type = t;
	car_size = "";
	truck_length = length;
}

void RentalRequest::setCustomerName(std::string name)
{
	customer_name = name;
}

void RentalRequest::setDrivingLicense(std::string license)
{
	driving_license_number = license;
}

void RentalRequest::setRentalDate(Date* d)
{
	rentalDate = d;
}

void RentalRequest::setReturnDate(Date* d)
{
	returnDate = d;
}

void RentalRequest::setType(std::string t)
{
	if (t != "Car" && t != "Truck")
		type = "NONE";
	else
		type = t;
}

void RentalRequest::setCarSize(std::string s)
{
	car_size = s;
}

void RentalRequest::setTruckLength(int l)
{
	truck_length = l;
}

std::string RentalRequest::getCustomerName()
{
	return customer_name;
}

std::string RentalRequest::getDrivingLicense()
{
	return driving_license_number;
}

Date* RentalRequest::getRentalDate()
{
	return rentalDate;
}

Date* RentalRequest::getReturnDate()
{
	return returnDate;
}

std::string RentalRequest::getType()
{
	return type;
}

std::string RentalRequest::getCarSize()
{
	return car_size;
}

int RentalRequest::getTruckLength()
{
	return truck_length;
}

RentalRequest::~RentalRequest()
{
	delete rentalDate;
	delete returnDate;
}
