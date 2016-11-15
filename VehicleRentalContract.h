#pragma once

#include "Vehicle.h"
#include "RentalRequest.h"
class VehicleRentalContract
{
private:
	Vehicle* vehicle;
	RentalRequest* rentalRequest;
	static int currentContractNumber;
	int contractNumber;
public:
	VehicleRentalContract();
	VehicleRentalContract(Vehicle*, RentalRequest*);
	void setVehicle(Vehicle*);
	void setRentalRequest(RentalRequest*);
	Vehicle* getVehicle();
	RentalRequest* getRentalRequest();
	int getContractNumber();
	~VehicleRentalContract();
};

