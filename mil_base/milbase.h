#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm> 

using namespace std;

// --- Entity ---
class Entity {
protected:
	bool is_active;
public:
	Entity() : is_active(true) {}
	Entity(bool is_active) : is_active(is_active) {}
	virtual void arrive() = 0;
	virtual bool leave() = 0;
	bool get_is_active() const {
		return is_active;
	}
};


// --- Human ---
class Human : public Entity {
protected:
	string f_name;
	string l_name;
	int age;
	friend istream& operator>>(istream& in, Human& human);
public:
	Human() : Entity(), f_name("Guest"), l_name("undefined"), age(0) {}
	Human(string f_name, string l_name, int age) : Entity(), f_name(f_name), l_name(l_name), age(age) {}
	Human(bool is_active, string f_name, string l_name, int age) : Entity(is_active), f_name(f_name), l_name(l_name), age(age) {}

	void arrive() override;
	bool leave() override;

	void print_info() const {
		cout << "Name: " << f_name << " " << l_name << ", Age: " << age << ", Active: " << (is_active ? "Yes" : "No") << "\n";
	}
	void print_name() const {
		cout << f_name << " " << l_name << "\n";
	}
	string get_f_name() const { 
		return f_name;
	}
};


// --- Vehicle ---
class Vehicle : public Entity {
protected:
	Human* driver;
	double fuel;
	double fuel_consumption; 
	double fuel_capacity;
	friend istream& operator>>(istream& in, Vehicle& vehicle);
public:
	Vehicle() : Entity(), driver(nullptr), fuel(0.0), fuel_consumption(0.0), fuel_capacity(0.0) {}
	Vehicle(bool is_active, Human* driver, double fuel, double fuel_consumption, double fuel_capacity);
	Vehicle(double petrol_amount, double tank_volume);
	Vehicle(double tank_volume);
	Vehicle(Human* driver, bool is_active, double fuel_capacity);

	void set_driver(Human* driver) {
		this->driver = driver;
	}
	Human* get_driver() const {
		return driver;
	}
	void refuel(double amount) {
		if (amount > 0) {
			fuel += amount;
		}
	}
	bool drive(double distance) {
		double required_fuel = (fuel_consumption / 100.0) * distance;
		if (required_fuel <= fuel) {
			fuel -= required_fuel;
			return true;
		}
		return false;
	}
	double get_petrol_amount() const {
		return fuel;
	}
	double get_fuel_consumption() const {
		return fuel_consumption;
	}
	void set_fuel_consumption(double consumption) {
		fuel_consumption = consumption;
	}
	double get_tank_volume() const {
		return fuel_capacity;
	}

	virtual void arrive() override;
	virtual bool leave() override;
	virtual void print() const
	{
		cout << "Vehicle driven by ";
		if (driver != nullptr) {
			driver->print_name();
		}
		else {
			cout << "No Driver\n";
		}
		cout << "Active: " << (is_active ? "Yes" : "No") << ", Fuel: " << fuel << " / " << fuel_capacity
			<< " liters, Fuel Consumption: " << fuel_consumption << " L/100km\n";
	}
};


// --- Truck ---
class Truck : public Vehicle {
protected:
	double max_load;
	double load; 
	friend istream& operator>>(istream& in, Truck& truck);
public:
	Truck() : Vehicle(), max_load(0.0), load(0.0) {}
	Truck(bool is_active, Human* driver, double fuel_capacity, double max_load);
	Truck(Human* driver, double fuel, double fuel_consumption, double fuel_capacity, double max_load);
	Truck(double petrol_amount, double tank_volume, double max_load);
	Truck(double tank_volume, double max_load);
	Truck(Human* driver, bool is_active, double fuel_capacity, double max_load);

	bool load_cargo(double amount) {
		if (amount > 0 && (load + amount) <= max_load) {
			load += amount;
			return true;
		}
		return false;
	}
	bool unload_cargo(double amount) {
		if (amount > 0 && amount <= load) {
			load -= amount;
			return true;
		}
		return false;
	}
	double get_current_load() const {
		return load;
	}
	double get_max_load() {
		return max_load;
	}
	void arrive() override;
	bool leave() override;
};


// --- Bus ---
class Bus : public Vehicle {
protected:
	int passenger_capacity;
	int current_passengers;
	friend istream& operator>>(istream& in, Bus& bus);
public:
	Bus() : Vehicle(), passenger_capacity(0), current_passengers(0) {}
	Bus(bool is_active, Human* driver, double fuel_capacity, int passenger_capacity);
	Bus(Human* driver, double fuel, double fuel_consumption, double fuel_capacity, int passenger_capacity);
	Bus(double petrol_amount, double tank_volume, int passenger_capacity);
	Bus(double tank_volume, int passenger_capacity);
	Bus(Human* driver, bool is_active, double fuel_capacity, int passenger_capacity);

	bool board_passengers(int number) {
		if (number > 0 && (current_passengers + number) <= passenger_capacity) {
			current_passengers += number;
			return true;
		}
		return false;
	}
	bool disembark_passengers(int number) {
		if (number > 0 && number <= current_passengers) {
			current_passengers -= number;
			return true;
		}
		return false;
	}
	int get_current_passengers() const {
		return current_passengers;
	}
	int get_passenger_capacity() {
		return passenger_capacity;
	}
	void arrive() override;
	bool leave() override;
};


// --- Base ---
class Base {
protected:
	static int people_on_base;
	static int vehicles_on_base;
	static double petrol_on_base;
	static double goods_on_base;
	vector<Human*> soliders;
	vector<Vehicle*> vehicles;
public:
	Base(vector<Human*> soliders = {}, vector<Vehicle*> vehicles = {});
	Base(vector<Human*> soliders, vector<Vehicle*> vehicles, int people_count, int vehicle_count, double petrol_amount, double goods_amount);

	void static set_people(int count) {
		people_on_base = count;
	}
	void static set_vehicles(int count) {
		vehicles_on_base = count;
	}
	void static set_petrol(double amount) {
		petrol_on_base = amount;
	}
	void static set_goods(double amount) {
		goods_on_base = amount;
	}
	int static get_people() {
		return people_on_base;
	}
	int static get_vehicles() {
		return vehicles_on_base;
	}
	double static get_petrol() {
		return petrol_on_base;
	}
	double static get_goods() {
		return goods_on_base;
	}

	void print_status() const {
		cout << "Base Status:\n";
		cout << "People on Base: " << get_people() << "\n";
		cout << "Vehicles on Base: " << get_vehicles() << "\n";
		cout << "Petrol on Base: " << get_petrol() << " liters\n";
		cout << "Goods on Base: " << get_goods() << " tons\n";
	}
	void print_vehicles() const {
		cout << "Vehicles on Base:\n";
		for (size_t i = 0; i < vehicles.size(); i++) {
			cout << "Vehicle " << i + 1 << ":\n";
			vehicles[i]->print();
		}
	}
	void print_soliders() const {
		cout << "Soliders on Base:\n";
		for (size_t i = 0; i < soliders.size(); i++) {
			cout << "Solider " << i + 1 << ":\n";
			soliders[i]->print_info();
		}
	}

	void add_vehicle(Vehicle* vehicle) {
		vehicles.push_back(vehicle);
		vehicles_on_base++;
	}
	void add_solider(Human* solider) {
		soliders.push_back(solider);
		people_on_base++;
	}

	bool remove_vehicle(size_t index);
	bool remove_solider(size_t index);
	bool remove_vehicle(Vehicle* vehicle);
	bool remove_solider(Human* solider);

	size_t get_solider_count() const {
		return soliders.size();
	}
	vector<Human*> get_soliders_list() const {
		return soliders;
	}
	vector<Vehicle*> get_vehicles_list() const {
		return vehicles;
	}
};