#include <iostream>
#include <string>

#include "Car.h";
#include "Date.h";
#include "RentalRequest.h";
#include "Truck.h";
#include "Vehicle.h";
#include "VehicleRentalContract.h";

using namespace std;

int VerifyRentalRequest(Vehicle** vehicle_array, RentalRequest* rental_request, const int NUM_OF_VEHCILES);
VehicleRentalContract* SetupContract(RentalRequest* rental_request, Vehicle* vehicle);
void DeleteRequest(VehicleRentalContract** contracts, int contractNumber, int mileage);

//global variables:
static const int NUM_OF_VEHICLES = 10;
static const int NUM_OF_CONTRACTS = 5;

int main()
{
	//Declare strings holding Car and Truck to avoid making spelling mistakes further on
	const string CAR = "Car";
	const string TRUCK = "Truck";

	//Declare array of pointers to vehicle objects
	Vehicle** vehicle_array = new Vehicle*[NUM_OF_VEHICLES];

	//Initialize all elements of vehicle array to null
	for (int i = 0; i < NUM_OF_VEHICLES; i++)
	{
		vehicle_array[i] = nullptr;
	}

	//Create car and truck objects and store in vehicle array


	//test default constructor
	Car* c1 = new Car;
	Date* d1 = new Date();
	d1->setDay(12);
	d1->setMonth(10);
	d1->setYear(2012);

	//Test setters
	c1->setDate(d1);
	c1->setID("1234");
	c1->setMileage(700);
	c1->setSize("Medium");
	c1->setType("Car");

	vehicle_array[0] = new Car(*c1);

	//Create other cars with parametrized constructor
	Date* d2 = new Date(2, 25, 2012);
	Car* c2 = new Car(d2, CAR, 1025, "2048", "Luxury");
	vehicle_array[1] = new Car(*c2);
	
	Date* d3 = new Date(5, 7, 2015);
	Car* c3 = new Car(d3, CAR, 70500, "5678", "Small");
	vehicle_array[2] = new Car(*c3);

	Date* d4 = new Date(6, 7, 2015);
	Car* c4 = new Car(d4, CAR, 7000, "4125", "Small");
	vehicle_array[3] = new Car(*c4);

	Date* d5 = new Date(5, 11, 2015);
	Car* c5 = new Car(d5, CAR, 700, "5211", "Luxury");
	vehicle_array[4] = new Car(*c5);

	Date* d6 = new Date(10, 7, 2014);
	Truck* t1 = new Truck(d6, TRUCK, 70500, "5489", 5);
	vehicle_array[5] = new Truck(*t1);

	Date* d7 = new Date(9, 7, 2014);
	Truck* t2 = new Truck(d7, TRUCK, 7600, "7145", 12);
	vehicle_array[6] = new Truck(*t2);

	Date* d8 = new Date(10, 7, 2012);
	Truck* t3 = new Truck(d8, TRUCK, 7260, "5489", 8);
	vehicle_array[7] = new Truck(*t3);

	Date* d9 = new Date(4, 7, 2014);
	Truck* t4 = new Truck(d9, TRUCK, 70500, "9974",  5);
	vehicle_array[8] = new Truck(*t4);

	Date* d10 = new Date(10, 7, 2015);
	Truck* t5 = new Truck(d10, TRUCK, 50000, "1645", 10);
	vehicle_array[9] = new Truck(*t5);

	//Declare array of pointers to VehicleContract objects, initialized to null values
	VehicleRentalContract** vehicle_contracts = new VehicleRentalContract*[NUM_OF_CONTRACTS];
	for (int i = 0; i < NUM_OF_CONTRACTS; i++)
		vehicle_contracts[i] = nullptr;


	/*TESTING:
	1- Request to rent a luxury car for Jan. 25 to Jan. 30
	2- Make the same request (should work since two such cars exist)
	3- Make a request for the same type of car for dates included in two previous dates (should NOT work)
	4- Request to rent a truck with an invalid size
	5- Request to rent a truck with a valid size
	6- Delete a request for a luxury car
	7- Retry booking for luxury car that had previosuly failed (should work now)
	8- Verify number of cars in fleet and trucks in fleet
	*/

	//1- Create a rental request for luxury car
	Date* rentalDate1 = new Date(1, 25, 2016);
	Date* returnDate1 = new Date(1, 30, 2016);
	RentalRequest* RR1 = new RentalRequest("John Doe", "123ABC", rentalDate1, returnDate1, CAR, "Luxury");
	int vehicleToRent = VerifyRentalRequest(vehicle_array, RR1, NUM_OF_VEHICLES);

	if (vehicleToRent == -1)
	{
		cout << "There is no available vehicle to reserve for " << RR1->getCustomerName() << endl;
	}
	else
	{
		VehicleRentalContract* contract1 = SetupContract(RR1, vehicle_array[vehicleToRent]);
		for (int i = 0; i < NUM_OF_CONTRACTS; i++)
		{
			if (vehicle_contracts[i] == nullptr)
				vehicle_contracts[i] = contract1;
		}
	}

	//2- Create rental request for same type of car at same dates (will work because there are two such cars)
	Date* rentalDate2 = new Date(1, 25, 2016);
	Date* returnDate2 = new Date(1, 30, 2016);
	RentalRequest* RR2 = new RentalRequest("Jane Doe", "123DEF", rentalDate2, returnDate2, CAR, "Luxury");
	vehicleToRent = VerifyRentalRequest(vehicle_array, RR2, NUM_OF_VEHICLES);

	if (vehicleToRent == -1)
	{
		cout << "There is no available vehicle to reserve for " << RR2->getCustomerName() << endl;
	}
	else
	{
		VehicleRentalContract* contract2 = SetupContract(RR2, vehicle_array[vehicleToRent]);
		for (int i = 0; i < NUM_OF_CONTRACTS; i++)
		{
			if (vehicle_contracts[i] == nullptr)
				vehicle_contracts[i] = contract2;
		}
	}

	//3- Create rental request for same type of car at same dates (will NOT work because there are only two such cars)
	Date* rentalDate3 = new Date(1, 25, 2016);
	Date* returnDate3 = new Date(1, 28, 2016);
	RentalRequest* RR3 = new RentalRequest("George Doe", "456DEF", rentalDate3, returnDate3, CAR, "Luxury");
	vehicleToRent = VerifyRentalRequest(vehicle_array, RR3, NUM_OF_VEHICLES);

	if (vehicleToRent == -1)
	{
		cout << "There is no available vehicle to reserve for " << RR3->getCustomerName() << endl;
	}
	else
	{
		VehicleRentalContract* contract3 = SetupContract(RR3, vehicle_array[vehicleToRent]);
		for (int i = 0; i < NUM_OF_CONTRACTS; i++)
		{
			if (vehicle_contracts[i] == nullptr)
				vehicle_contracts[i] = contract3;
		}
	}

	//4- Create a rental request for a trcuk with invalid length
	Date* rentalDate4 = new Date(1, 25, 2016);
	Date* returnDate4 = new Date(1, 30, 2016);
	RentalRequest* RR4 = new RentalRequest("Jack Smith", "789GEF", rentalDate4, returnDate4, TRUCK, 13);
	vehicleToRent = VerifyRentalRequest(vehicle_array, RR4, NUM_OF_VEHICLES);

	if (vehicleToRent == -1)
	{
		cout << "There is no available vehicle to reserve for " << RR4->getCustomerName() << endl;
	}
	else
	{
		VehicleRentalContract* contract4 = SetupContract(RR4, vehicle_array[vehicleToRent]);
		for (int i = 0; i < NUM_OF_CONTRACTS; i++)
		{
			if (vehicle_contracts[i] == nullptr)
				vehicle_contracts[i] = contract4;
		}
	}

	//5- Create a rental request for a trcuk with valid length
	Date* rentalDate5 = new Date(1, 25, 2016);
	Date* returnDate5 = new Date(1, 30, 2016);
	RentalRequest* RR5 = new RentalRequest("Tom Smith", "789REF", rentalDate5, returnDate5, TRUCK, 12);
	vehicleToRent = VerifyRentalRequest(vehicle_array, RR5, NUM_OF_VEHICLES);

	if (vehicleToRent == -1)
	{
		cout << "There is no available vehicle to reserve for " << RR5->getCustomerName() << endl;
	}
	else
	{
		VehicleRentalContract* contract5 = SetupContract(RR5, vehicle_array[vehicleToRent]);
		for (int i = 0; i < NUM_OF_CONTRACTS; i++)
		{
			if (vehicle_contracts[i] == nullptr)
				vehicle_contracts[i] = contract5;
		}
	}

	//6- Delete request for luxury car
	DeleteRequest(vehicle_contracts, vehicle_contracts[0]->getContractNumber(), 2000);

	//7- Make request for luxury again (should work)
	vehicleToRent = VerifyRentalRequest(vehicle_array, RR3, NUM_OF_VEHICLES);

	if (vehicleToRent == -1)
	{
		cout << "There is no available vehicle to reserve for " << RR3->getCustomerName() << endl;
	}
	else
	{
		VehicleRentalContract* contract3 = SetupContract(RR3, vehicle_array[vehicleToRent]);
		for (int i = 0; i < NUM_OF_CONTRACTS; i++)
		{
			if (vehicle_contracts[i] == nullptr)
				vehicle_contracts[i] = contract3;
		}
	}

	//8- Verify size of fleets
	cout << "\n\nThe total number of cars in the fleet is " << dynamic_cast<Car*>(vehicle_array[0])->getFleetSize() << endl;
	cout << "The total number of trucks in the fleet is " << dynamic_cast<Truck*>(vehicle_array[6])->getFleetSize() << endl;

	system("pause");
}

//Verifies if a vehicle matching the description is available at requested dates.
//If such a vehicle exists, returns the index of thevehicle in the index array. Else, returns -1
int VerifyRentalRequest(Vehicle** vehicle_array, RentalRequest* rental_request, const int NUM_OF_VEHCILES)
{
	int vehicle_to_rent = -1; //will hold the index of the vehicle to rent

	string type = rental_request->getType();
	string size = rental_request->getCarSize();
	string customerName = rental_request->getCustomerName();
	int length = rental_request->getTruckLength();

	Date* rentalDate = rental_request->getRentalDate();
	Date* returnDate = rental_request->getReturnDate();

	//First, check if entered dates are valid
	if (rentalDate->getYear() != 2016 || returnDate->getYear() != 2016)
	{
		cout << "Rental and return date must be in 2016." << endl;
		return -1;
	}

	int start = (rentalDate->getMonth() - 1) * 30 + rentalDate->getDay(); //Get starting position in availability array
	int stop = (returnDate->getMonth() - 1) * 30 + returnDate->getDay(); //Get ending position in availabiloity array

	//Make sure rental and return dates are valid
	if (stop < start)
	{
		cout << "Return date must be AFTER rental date." << endl;
		return -1;
	}

	//Iterate through vehicle array and find vehciles of correct type
	for (int i = 0; i < NUM_OF_VEHCILES; i++)
	{
		if (vehicle_array[i]->getType() == type) //Car or truck
		{
			if (type == "Car") //If we are seraching for a car, check car size
			{
				Car* car = dynamic_cast<Car*>(vehicle_array[i]);
				if (car != nullptr) //If the vehicle in the array actually is a car (will be null if is a truck)
				{
					if (car->getSize() == size) //Car has correct size
					{
						//Check if available during those dates
						bool available = vehicle_array[i]->getAvailability(start, stop);

						if (available)
						{
							vehicle_to_rent = i;
							break;
						}
					}
				}
			}
			else //If we are searching for a truck, check truck length
			{
				Truck* truck = dynamic_cast<Truck*>(vehicle_array[i]);
				if (truck != nullptr)
				{
					if (truck->getLength() == rental_request->getTruckLength())
					{
						//Check if available during those dates
						bool available = vehicle_array[i]->getAvailability(start, stop);

						if (available)
						{
							vehicle_to_rent = i;
							break;
						}
					}
				}
			}
		}
	}
	return vehicle_to_rent;
}

//Creates a VehicleRentalContract for a given rental request and vehicle. Returns a pointer to the created contract.
VehicleRentalContract* SetupContract(RentalRequest* rental_request, Vehicle* vehicle)
{
	Date* rentalDate = rental_request->getRentalDate();
	Date* returnDate = rental_request->getReturnDate();

	int start = (rentalDate->getMonth() - 1) * 30 + rentalDate->getDay(); //Get starting position in availability array
	int stop = (returnDate->getMonth() - 1) * 30 + returnDate->getDay(); //Get ending position in availabiloity array

	VehicleRentalContract* contract = new VehicleRentalContract(vehicle, rental_request);
	int contractNumber = contract->getContractNumber();

	vehicle->setAvailability(start, stop, contractNumber);

	cout << "Contract for " << rental_request->getCustomerName() << " successfully created. Contract number is " << contract->getContractNumber() << endl;
	return contract;
}

//Terminates a vehicleRentalContract. The spot is freed in the vehicle_contract array
//The car that was returned has its availabilities updated to indicate it is no longer being used and its mileage updated.
void DeleteRequest(VehicleRentalContract** contracts, int contractNumber, int mileage)
{
	Vehicle* vehicle;
	for (int i = 0; i < NUM_OF_CONTRACTS; i++)
	{
		if (contracts[i]->getContractNumber() == contractNumber)
		{
			//Set new vehicle mileage
			vehicle = contracts[i]->getVehicle();
			vehicle->setMileage(mileage);

			//Reset vehicle availabilities
			Date* d = contracts[i]->getRentalRequest()->getRentalDate();
			int start = (d->getMonth() - 1) * 30 + d->getDay();
			d = contracts[i]->getRentalRequest()->getReturnDate();
			int stop = (d->getMonth() - 1) * 30 + d->getDay();

			vehicle->setAvailability(start, stop, 0);

			//Set contract to null
			contracts[i] = nullptr;
			break;
		}
	}
}