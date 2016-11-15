#include "VehicleRentalContract.h"

int VehicleRentalContract::currentContractNumber = 0;

VehicleRentalContract::VehicleRentalContract()
{
	vehicle = new Vehicle();
	rentalRequest = new RentalRequest();
	currentContractNumber++;
	contractNumber = currentContractNumber;
}

VehicleRentalContract::VehicleRentalContract(Vehicle* v, RentalRequest* rr)
{
	vehicle = new Vehicle(); vehicle = v;
	rentalRequest = new RentalRequest(); rentalRequest = rr;
	currentContractNumber++;
	contractNumber = currentContractNumber;
}

void VehicleRentalContract::setVehicle(Vehicle* v)
{
	vehicle = v;
}

void VehicleRentalContract::setRentalRequest(RentalRequest* rr)
{
	rentalRequest = rr;
}

Vehicle* VehicleRentalContract::getVehicle()
{
	return vehicle;
}

RentalRequest* VehicleRentalContract::getRentalRequest()
{
	return rentalRequest;
}

int VehicleRentalContract::getContractNumber()
{
	return contractNumber;
}

VehicleRentalContract::~VehicleRentalContract()
{
	delete vehicle;
	delete rentalRequest;
}
