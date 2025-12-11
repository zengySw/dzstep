#pragma once
#include "Human.h"
#include "Entity.h"
#include <iostream>
using namespace std;

class Vehicle : public Entity {
protected:
	Human* driver;
	double fuel;
	double fuelConsumption; // fuel consumption per 100 km
	double fuelCapacity;
	friend istream& operator>>(istream& in, Vehicle& vehicle)
	{
		cout << "Enter fuel consumption (L/100km): ";
		in >> vehicle.fuelConsumption;
		cout << "Enter fuel capacity (liters): ";
		in >> vehicle.fuelCapacity;
		cout << "Enter current fuel amount (liters): ";
		in >> vehicle.fuel;
		if (vehicle.fuel > vehicle.fuelCapacity) {
			vehicle.fuel = vehicle.fuelCapacity;
		}
		return in;
	}
public:
	Vehicle() : Entity(), driver(nullptr), fuel(0.0), fuelConsumption(0.0), fuelCapacity(0.0) {}
	Vehicle(bool isActive, Human* driver, double fuel, double fuelConsumption, double fuelCapacity)
		: Entity(isActive), driver(driver), fuel(fuel), fuelConsumption(fuelConsumption), fuelCapacity(fuelCapacity) {
		if (fuel > fuelCapacity) {
			this->fuel = fuelCapacity;
		}
	}
	Vehicle(double petrol_amount, double tank_volume)
		: Entity(), driver(nullptr), fuel(petrol_amount), fuelConsumption(0.0), fuelCapacity(tank_volume) {
		if (fuel > fuelCapacity) {
			this->fuel = fuelCapacity;
		}
	}
	Vehicle(double tank_volume)
		: Entity(), driver(nullptr), fuel(0.0), fuelConsumption(0.0), fuelCapacity(tank_volume) {
	}
	Vehicle(Human* driver,bool isActive, double fuelCapacity)
		: Entity(isActive), driver(driver), fuel(0.0), fuelConsumption(0.0), fuelCapacity(fuelCapacity) {
	}
	void set_Driver(Human* driver) {
		this->driver = driver;
	}
	Human* get_Driver() const {
		return driver;
	}
	void refuel(double amount) {
		if (amount > 0) {
			fuel += amount;
		}
	}
	bool drive(double distance) {
		double requiredFuel = (fuelConsumption / 100.0) * distance;
		if (requiredFuel <= fuel) {
			fuel -= requiredFuel;
			return true;
		}
		return false;
	}
	double get_Petrol_Amount() const {
		return fuel;
	}
	double get_Fuel_Consumption() const {
		return fuelConsumption;
	}
	void set_Fuel_Consumption(double consumption) {
		fuelConsumption = consumption;
	}
	double get_Tank_Volume() const {
		return fuelCapacity;
	}

	virtual void arrive();
	virtual bool leave();
	virtual void Print() const
	{
		cout << "Vehicle driven by ";
		if (driver != nullptr) {
			driver->Print_Name();
		}
		else {
			cout << "No Driver\n";
		}
		cout << "Active: " << (isActive ? "Yes" : "No") << ", Fuel: " << fuel << " / " << fuelCapacity
			<< " liters, Fuel Consumption: " << fuelConsumption << " L/100km\n";
	}
};