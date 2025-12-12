#include <iostream>
using namespace std;

class Transport
{
protected:
	string name;
	int year;
	int mSpeed;
	double tWeight;
	int human_Capacity;
public:
	Transport()
	{
		name = "";
		year = 0;
		mSpeed = 0;
		tWeight = 0.0;
		human_Capacity = 0;
	}
	Transport(string name, int year, int mSpeed, double tWeight, int human_Capacity)
	{
		this->name = name;
		this->year = year;
		this->mSpeed = mSpeed;
		this->tWeight = tWeight;
		this->human_Capacity = human_Capacity;
	}
	void Set_Name(string name) { this->name = name; }
	void Set_Year(int year) { this->year = year; }
	void Set_MSpeed(int mSpeed) { this->mSpeed = mSpeed; }
	void Set_TWeight(double tWeight) { this->tWeight = tWeight; }
	void Set_HumanCapacity  (int human_Capacity) { this->human_Capacity = human_Capacity; }

	string Get_Name() { return this->name; }
	int Get_Year() { return this->year; }
	int Get_MSpeed() { return this->mSpeed; }
	double Get_TWeight() { return this->tWeight; }
	int Get_HumanCapacity() { return this->human_Capacity; }
	void Print() {
		cout << "Name: " << this->name << "\tYear: " << this->year << " y" << "\tMax speed: " << this->mSpeed << " km/h" << "\tWeight:" << this->tWeight << " T" << "\tCapacity: " << this->human_Capacity << " human's" << endl;
	}
};

class Cargo : public Transport
{
	double dWheels;
	int vEngine;
public:
	Cargo(string name, int year, int mSpeed, double tWeight, int human_Capacity, double dWheels, int vEngine)
	{
		this->name = name;
		this->year = year;
		this->mSpeed = mSpeed;
		this->tWeight = tWeight;
		this->human_Capacity = human_Capacity;
		this->dWheels = dWheels;
		this->vEngine = vEngine;
	}
	void Set_dWheels(double dWheels) { this->dWheels = dWheels; }
	void Set_VEngine(int vEngine) { this->vEngine = vEngine; }

	double Get_dWheels() { return this->dWheels; }
	int Get_VEngine() { return this->vEngine; }
	void Print()
	{
		Transport::Print();
		cout << "Weels D: " << dWheels << " sm" << "\tEngine V: " << vEngine << endl;
	}
};

class Plane : public Transport
{
	double mWingsScope;
	int vEngine;
	Plane(string name, int year, int mSpeed, double tWeight, int human_Capacity, double mWingsScope, int vEngine)
	{
		this->name = name;
		this->year = year;
		this->mSpeed = mSpeed;
		this->tWeight = tWeight;
		this->human_Capacity = human_Capacity;
		this->mWingsScope = mWingsScope;
		this->vEngine = vEngine;
	}
	void Set_MWing_Scope(double mWingsScope) { this->mWingsScope = mWingsScope; }
	void Set_VEngine(int vEngine) { this->vEngine = vEngine; }

	double Get_MWing_Scope() { return this->mWingsScope; }
	int Get_VEngine() { return this->vEngine; }
	void Print()
	{
		Transport::Print();
		cout << "Wings scope: " << mWingsScope << " m" << "\tEngine V: " << vEngine << endl;
	}
};

class Boat : public Transport
{
	double mLong;
	int screwCount;
	double mWaterlineHi;
public:
	Boat(string name, int year, int mSpeed, double tWeight, int human_Capacity, double mLong, int screwCount, double mWaterlineHi)
	{
		this->name = name;
		this->year = year;
		this->mSpeed = mSpeed;
		this->tWeight = tWeight;
		this->human_Capacity = human_Capacity;
		this->mLong = mLong;
		this->screwCount = screwCount;
		this->mWaterlineHi = mWaterlineHi;
	}
	void Set_MLong(double mLong) { this->mLong = mLong; }
	void Set_Screw_Count(int screwCount) { this->screwCount = screwCount; }
	void Set_MWater_lineHi(double mWaterlineHi) { this->mWaterlineHi = mWaterlineHi; }

	double Get_MLong() { return this->mLong; }
	int Get_Screw_Count() { return this->screwCount; }
	double Get_MWater_lineHi() { return this->mWaterlineHi; }
	void Print()
	{
		Transport::Print();
		cout << "Long: " << mLong << " m" << "\tScrews count: " << screwCount << "\tWater line height" << mWaterlineHi << " m" << endl;
	}
};

class Car : public Transport
{
	string fuelType;
	string gearboxType;
	string carcaseType;
public:
	Car(string name, int year, int mSpeed, double tWeight, int human_Capacity, string fueType, string gearboxType, string carcaseType)
	{
		this->name = name;
		this->year = year;
		this->mSpeed = mSpeed;
		this->tWeight = tWeight;
		this->human_Capacity = human_Capacity;
		this->fuelType = fueType;
		this->gearboxType = gearboxType;
		this->carcaseType = carcaseType;
	}
	void Set_Fuel_Type(string fuelType) { this->fuelType = fuelType; }
	void Set_Gearbox_Type(string gearboxType) { this->gearboxType = gearboxType; }
	void Set_Carcase_Type(string carcaseType) { this->carcaseType = carcaseType; }

	string Get_Fuel_Type() { return this->fuelType; }
	string Get_Gearbox_Type() { return this->gearboxType; }
	string Get_Carcase_Type() { return this->carcaseType; }
	void Print()
	{
		Transport::Print();
		cout << "Fuel type: " << fuelType << "\tGearbox type: " << gearboxType << "\tCarcase type: " << carcaseType << endl;
	}
};

class Bike : public Transport
{
	string chasissType;
	double dWheels;
public:
	Bike(string name, int year, int mSpeed, double tWeight, int human_Capacity, string chasissType, double dWheels)
	{
		this->name = name;
		this->year = year;
		this->mSpeed = mSpeed;
		this->tWeight = tWeight;
		this->human_Capacity = human_Capacity;
		this->chasissType = chasissType;
		this->dWheels = dWheels;
	}
	void Set_Chasiss_Type(string chasissType) { this->chasissType = chasissType; }
	void Set_DWheels(double dWheels) { this->dWheels = dWheels; }

	string Get_Chasiss_Type() { return this->chasissType; }
	double Get_DWheels() { return this->dWheels; }
	void Print()
	{
		Transport::Print();
		cout << "Chasiss type: " << chasissType << "\tWheels D: " << dWheels << " sm" << endl;
	}
};

class Tank : public Transport
{
	string tankType;
	string fuelType;
	bool fireAvalible;
public:
	Tank(string name, int year, int mSpeed, double tWeight, int human_Capacity, string tankType, string fuelType, bool fireAvalible)
	{
		this->name = name;
		this->year = year;
		this->mSpeed = mSpeed;
		this->tWeight = tWeight;
		this->human_Capacity = human_Capacity;
		this->tankType = tankType;
		this->fuelType = fuelType;
		this->fireAvalible = fireAvalible;
	}
	void Set_Tank_Type(string tankType) { this->tankType = tankType; }
	void Set_Fuel_Type(string fuelType) { this->fuelType = fuelType; }
	void Set_Fire_Avalible(bool fireAvalible) { this->fireAvalible = fireAvalible; }

	string Get_Tank_Type() { return this->tankType; }
	string Get_Fuel_Type() { return this->fuelType; }
	bool Get_Fire_Avalible() { return this->fireAvalible; }
	void Print()
	{
		Transport::Print();
		cout << "Tank type: " << tankType << "\tFuel type: " << fuelType << "\tFire: " << (fireAvalible ? "avalible" : "not avalible") << endl;
	}
};

int main() {

    return 0;
}