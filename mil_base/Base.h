#pragma once
#include "Human.h"
#include "Vehicle.h"
#include <vector>
#include <iostream>
using namespace std;

class Base {
protected:
	static int people_on_base;
	static int vehicles_on_base;
	static double petrol_on_base;
	static double goods_on_base;
	vector<Human*> soliders;
	vector<Vehicle*> vehicles;
public:
	Base(vector<Human*> soliders = {}, vector<Vehicle*> vehicles = {})
		: soliders(soliders), vehicles(vehicles) {}
	Base(vector<Human*> soliders, vector<Vehicle*> vehicles, int people_count, int vehicle_count, double petrol_amount, double goods_amount)
		: soliders(soliders), vehicles(vehicles)
	{
		people_on_base = people_count;
		vehicles_on_base = vehicle_count;
		petrol_on_base = petrol_amount;
		goods_on_base = goods_amount;
	}
	void static set_People(int count) {
		people_on_base = count;
	}
	void static set_Vehicles(int count) {
		vehicles_on_base = count;
	}
	void static set_Petrol(double amount) {
		petrol_on_base = amount;
	}
	void static set_Goods(double amount) {
		goods_on_base = amount;
	}
	int static get_People() {
		return people_on_base;
	}
	int static get_Vehicles() {
		return vehicles_on_base;
	}
	double static get_Petrol() {
		return petrol_on_base;
	}
	double static get_Goods() {
		return goods_on_base;
	}
	void PrintStatus() const {
		cout << "Base Status:\n";
		cout << "People on Base: " << get_People() << "\n";
		cout << "Vehicles on Base: " << get_Vehicles() << "\n";
		cout << "Petrol on Base: " << get_Petrol() << " liters\n";
		cout << "Goods on Base: " << get_Goods() << " tons\n";
	}
	void PrintVehicles() const {
		cout << "Vehicles on Base:\n";
		for (size_t i = 0; i < vehicles.size(); i++) {
			cout << "Vehicle " << i + 1 << ":\n";
			vehicles[i]->Print();
		}
	}
	void PrintSoliders() const {
		cout << "Soliders on Base:\n";
		for (size_t i = 0; i < soliders.size(); i++) {
			cout << "Solider " << i + 1 << ":\n";
			soliders[i]->Print_Info();
		}
	}
	void AddVehicle(Vehicle* vehicle) {
		vehicles.push_back(vehicle);
		vehicles_on_base++;
	}
	void AddSolider(Human* solider) {
		soliders.push_back(solider);
		people_on_base++;
	}
	bool RemoveVehicle(size_t index) {
		if (index < vehicles.size()) {
			vehicles.erase(vehicles.begin() + index);
			vehicles_on_base--;
			return 1;
		}
		return 0;
	}
	bool RemoveSolider(size_t index) {
		if (index < soliders.size()) {
			soliders.erase(soliders.begin() + index);
			people_on_base--;
			return 1;
		}
		return 0;
	}
	bool RemoveVehicle(Vehicle* vehicle) {
		auto it = find(vehicles.begin(), vehicles.end(), vehicle);
		if (it != vehicles.end()) {
			vehicles.erase(it);
			vehicles_on_base--;
			return 1;
		}
		else return 0;
	}
	bool RemoveSolider(Human* solider) {
		auto it = find(soliders.begin(), soliders.end(), solider);
		if (it != soliders.end()) {
			soliders.erase(it);
			people_on_base--;
			return 1;
		}
		else return 0;
	}
	size_t getSoliderCount() const {
		return soliders.size();
	}
	vector<Human*> getSolidersList() const {
		return soliders;
	}
	vector<Vehicle*> get_VehiclesList() const {
		return vehicles;
	}
};