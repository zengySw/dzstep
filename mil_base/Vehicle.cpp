#include "Base.h"
#include "Vehicle.h"

void Vehicle::arrive()
{
	if (driver == nullptr) throw "Vehicle has no driver.";
	if (fuel <= 0 || fuelConsumption / 100 > fuel) throw "Vehicle has no enought fuel.";
	if (isActive) throw "Vehicle is already on the base.";
	isActive = true;
	Base::set_Vehicles(Base::get_Vehicles() + 1);
	Base::set_People(Base::get_People() + 1);
	fuel -= fuelConsumption / 100;
	isActive = true;
}

bool Vehicle::leave()
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
	Base::set_Vehicles(Base::get_Vehicles() - 1);
	Base::set_People(Base::get_People() - 1);
	fuel -= fuelConsumption / 100;
	isActive = false;
	return 1;
}