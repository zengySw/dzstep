#pragma once
#include "Vehicle.h"
#include "Human.h"
#include "Base.h"

class Truck : public Vehicle {
protected:
	double max_load; // in tons
	double load;  // in tons
	friend istream& operator>>(istream& in, Truck& truck)
	{
		cout << "Enter max load (tons): ";
		in >> truck.max_load;
		Vehicle temp;
		in >> temp;
		truck.fuel = temp.get_Petrol_Amount();
		truck.fuelCapacity = temp.get_Tank_Volume();
		truck.fuelConsumption = temp.get_Fuel_Consumption();
		return in;
	}
public:
	Truck() : Vehicle(), max_load(0.0), load(0.0) {}
	Truck(double isActive, Human* driver, double fuelCapacity, double max_load)
		: Vehicle(isActive, driver, 0, 0, fuelCapacity), max_load(max_load), load(0.0) {
	}
	Truck(Human* driver, double fuel, double fuelConsumption, double fuelCapacity, double max_load)
		: Vehicle(true, driver, fuel, fuelConsumption, fuelCapacity), max_load(max_load), load(0.0) {
	}
	Truck(double petrol_amount, double tank_volume, double max_load)
		: Vehicle(petrol_amount, tank_volume), max_load(max_load), load(0.0) {
	}
	Truck(double tank_volume, double max_load)
		: Vehicle(tank_volume), max_load(max_load), load(0.0) {
	}
	Truck(Human* driver, bool isActive, double fuelCapacity, double max_load)
		: Vehicle(driver, isActive, fuelCapacity), max_load(max_load), load(0.0) {
	}
	bool loadCargo(double amount) {
		if (amount > 0 && (load + amount) <= max_load) {
			load += amount;
			return true;
		}
		return false;
	}
	bool unloadCargo(double amount) {
		if (amount > 0 && amount <= load) {
			load -= amount;
			return true;
		}
		return false;
	}
	double getCurrentLoad() const {
		return load;
	}
	double getMaxLoad() {
		return max_load;
	}
	void arrive() override
	{
		if (driver == nullptr) throw "Truck has no driver.";
		if (isActive) throw "Truck is already on the base.";
		if (fuel <= 0 || fuelConsumption / 100 > fuel) throw "Truck has no enough fuel.";
		isActive = true;
		fuel -= fuelConsumption / 100;
		Base::set_Vehicles(Base::get_Vehicles() + 1);
		Base::set_Goods(Base::get_Goods() + load);
		Base::set_People(Base::get_People() + 1);
		load = 0.0;
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
		if (fuel <= 0 || fuelConsumption / 100 > fuel) return 0;
		if (load > 0)
		{
			if (load <= Base::get_Goods())
			{
				Base::set_Goods(Base::get_Goods() - load);
				load = 0;
			}
			else
			{
				load -= Base::get_Goods();
				Base::set_Goods(0);
			}
		}
		Base::set_Vehicles(Base::get_Vehicles() - 1);
		Base::set_People(Base::get_People() - 1);
		fuel -= fuelConsumption / 100;
		isActive = false;
		return 1;
	}
};