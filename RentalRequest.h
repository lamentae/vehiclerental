#pragma once

#include <iostream>

#include "Date.h"
class RentalRequest
{
private:
	std::string customer_name;
	std::string driving_license_number;
	Date* rentalDate;
	Date* returnDate;
	std::string type;
	std::string car_size;
	int truck_length;
public:
	RentalRequest();
	RentalRequest(std::string, std::string, Date*, Date*, std::string, std::string); //for cars
	RentalRequest(std::string, std::string, Date*, Date*, std::string, int); //for trucks
	void setCustomerName(std::string);
	void setDrivingLicense(std::string);
	void setRentalDate(Date*);
	void setReturnDate(Date*);
	void setType(std::string);
	void setCarSize(std::string);
	void setTruckLength(int);
	std::string getCustomerName();
	std::string getDrivingLicense();
	Date* getRentalDate();
	Date* getReturnDate();
	std::string getType();
	std::string getCarSize();
	int getTruckLength();
	~RentalRequest();
};

