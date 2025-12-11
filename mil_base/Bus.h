#pragma once
#include "Vehicle.h"
#include "Human.h"
#include "Base.h"

class Bus : public Vehicle {
	protected:
	int passengerCapacity;
	int currentPassengers;
	friend istream& operator>>(istream& in, Bus& bus)
	{
		cout << "Enter passenger capacity: ";
		in >> bus.passengerCapacity;
		Vehicle temp;
		in >> temp;
		bus.fuel = temp.get_Petrol_Amount();
		bus.fuelCapacity = temp.get_Tank_Volume();
		bus.fuelConsumption = temp.get_Fuel_Consumption();
		return in;
	}
public:
	Bus() : Vehicle(), passengerCapacity(0), currentPassengers(0) {}
	Bus(double isActive, Human* driver, double fuel_Capacity, int passenger_Capacity)
		: Vehicle(isActive, driver, 0, 0, fuel_Capacity), passengerCapacity(passenger_Capacity), currentPassengers(0) {
	}
	Bus(Human* driver, double fuel, double fuelConsumption, double fuelCapacity, int passenger_Capacity)
		: Vehicle(true, driver, fuel, fuelConsumption, fuelCapacity), passengerCapacity(passenger_Capacity), currentPassengers(0) {
	}
	Bus(double petrol_amount, double tank_volume, int passenger_Capacity)
		: Vehicle(petrol_amount, tank_volume), passengerCapacity(passenger_Capacity), currentPassengers(0) {
	}
	Bus(double tank_volume, int passenger_Capacity)
		: Vehicle(tank_volume), passengerCapacity(passenger_Capacity), currentPassengers(0) {
	}
	Bus(Human* driver, bool isActive, double fuelCapacity, int passengerCapacity)
		: Vehicle(driver, isActive, fuelCapacity), passengerCapacity(passengerCapacity), currentPassengers(0) {
	}
	bool boardPassengers(int number) {
		if (number > 0 && (currentPassengers + number) <= passengerCapacity) {
			currentPassengers += number;
			return true;
		}
		return false;
	}
	bool disembarkPassengers(int number) {
		if (number > 0 && number <= currentPassengers) {
			currentPassengers -= number;
			return true;
		}
		return false;
	}
	int getCurrentPassengers() const {
		return currentPassengers;
	}
	int getPassengerCapacity() {
		return passengerCapacity;
	}
	void arrive() override
	{
		if (driver == nullptr) throw "Bus has no driver.";
		if (isActive) throw "Bus is already on the base.";
		if (fuel <= 0 || fuelConsumption / 100 > fuel) throw "Bus has no enough fuel.";
		isActive = true;
		Base::set_Vehicles(Base::get_Vehicles() + 1);
		Base::set_People(Base::get_People() + currentPassengers + 1);
		currentPassengers = 0;
	}
	bool leave() override
	{
		if (driver == nullptr || Base::get_People() <= 0 || !isActive || Base::get_Vehicles() <= 0) return 0;
		if (fuel < fuelCapacity && Base::get_Petrol() > 0)
		{
			if (fuelCapacity - fuel <= Base::get_Petrol())
			{
				Base::set_Petrol(Base::get_Petrol() - (fuelCapacity - fuel));
				fuel = fuelCapacity;
			}
			else return 0;
		}
		if (currentPassengers < passengerCapacity && Base::get_People() > 0)
		{
			if (passengerCapacity - currentPassengers + 1 <= Base::get_People())
			{
				Base::set_People(Base::get_People() - (passengerCapacity - currentPassengers + 1));
				currentPassengers = passengerCapacity;
			}
			else
			{
				currentPassengers += Base::get_People() - 1;
				Base::set_People(0);
			}
		}
		if (fuel <= 0 || fuelConsumption / 100 > fuel) return 0;
		isActive = false;
		Base::set_Vehicles(Base::get_Vehicles() - 1);
		return 1;
	}

};