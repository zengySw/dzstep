#include "milbase.h"

// --- Base ---
int Base::people_on_base = 5000;
int Base::vehicles_on_base = 1500;
double Base::petrol_on_base = 20000.0; 
double Base::goods_on_base = 50.0; 

Base::Base(vector<Human*> soliders, vector<Vehicle*> vehicles)
	: soliders(soliders), vehicles(vehicles) {
}

Base::Base(vector<Human*> soliders, vector<Vehicle*> vehicles, int people_count, int vehicle_count, double petrol_amount, double goods_amount)
	: soliders(soliders), vehicles(vehicles)
{
	people_on_base = people_count;
	vehicles_on_base = vehicle_count;
	petrol_on_base = petrol_amount;
	goods_on_base = goods_amount;
}

bool Base::remove_vehicle(size_t index) {
	if (index < vehicles.size()) {
		vehicles.erase(vehicles.begin() + index);
		vehicles_on_base--;
		return true;
	}
	return false;
}

bool Base::remove_solider(size_t index) {
	if (index < soliders.size()) {
		soliders.erase(soliders.begin() + index);
		people_on_base--;
		return true;
	}
	return false;
}

bool Base::remove_vehicle(Vehicle* vehicle) {
	auto it = find(vehicles.begin(), vehicles.end(), vehicle);
	if (it != vehicles.end()) {
		vehicles.erase(it);
		vehicles_on_base--;
		return true;
	}
	else return false;
}

bool Base::remove_solider(Human* solider) {
	auto it = find(soliders.begin(), soliders.end(), solider);
	if (it != soliders.end()) {
		soliders.erase(it);
		people_on_base--;
		return true;
	}
	else return false;
}

// --- Human ---
istream& operator>>(istream& in, Human& human)
{
	cout << "Enter First Name: ";
	in >> human.f_name;
	cout << "Enter Last Name: ";
	in >> human.l_name;
	cout << "Enter Age: ";
	in >> human.age;
	return in;
}

void Human::arrive()
{
	if (is_active) throw "Human is already on the base.";
	is_active = true;
	Base::set_people(Base::get_people() + 1);
}

bool Human::leave()
{
	if (!is_active) return false;
	if (Base::get_people() <= 0) throw "No people on the base.";
	is_active = false;
	Base::set_people(Base::get_people() - 1);
	return true;
}


// --- Vehicle ---
Vehicle::Vehicle(bool is_active, Human* driver, double fuel, double fuel_consumption, double fuel_capacity)
	: Entity(is_active), driver(driver), fuel(fuel), fuel_consumption(fuel_consumption), fuel_capacity(fuel_capacity) {
	if (fuel > fuel_capacity) {
		this->fuel = fuel_capacity;
	}
}

Vehicle::Vehicle(double petrol_amount, double tank_volume)
	: Entity(), driver(nullptr), fuel(petrol_amount), fuel_consumption(0.0), fuel_capacity(tank_volume) {
	if (fuel > fuel_capacity) {
		this->fuel = fuel_capacity;
	}
}

Vehicle::Vehicle(double tank_volume)
	: Entity(), driver(nullptr), fuel(0.0), fuel_consumption(0.0), fuel_capacity(tank_volume) {
}

Vehicle::Vehicle(Human* driver, bool is_active, double fuel_capacity)
	: Entity(is_active), driver(driver), fuel(0.0), fuel_consumption(0.0), fuel_capacity(fuel_capacity) {
}

istream& operator>>(istream& in, Vehicle& vehicle)
{
	cout << "Enter fuel consumption (L/100km): ";
	in >> vehicle.fuel_consumption;
	cout << "Enter fuel capacity (liters): ";
	in >> vehicle.fuel_capacity;
	cout << "Enter current fuel amount (liters): ";
	in >> vehicle.fuel;
	if (vehicle.fuel > vehicle.fuel_capacity) {
		vehicle.fuel = vehicle.fuel_capacity;
	}
	return in;
}

void Vehicle::arrive()
{
	if (driver == nullptr) throw "Vehicle has no driver.";
	if (fuel <= 0 || fuel_consumption / 100.0 > fuel) throw "Vehicle has no enought fuel.";
	if (is_active) throw "Vehicle is already on the base.";
	is_active = true;
	Base::set_vehicles(Base::get_vehicles() + 1);
	Base::set_people(Base::get_people() + 1);
	fuel -= fuel_consumption / 100.0;
}

bool Vehicle::leave()
{
	if (driver == nullptr || Base::get_people() <= 0 || !is_active || Base::get_vehicles() <= 0) return false;

	if (fuel < fuel_capacity && Base::get_petrol() > 0)
	{
		double needed_fuel = fuel_capacity - fuel;
		if (needed_fuel <= Base::get_petrol())
		{
			Base::set_petrol(Base::get_petrol() - needed_fuel);
			fuel = fuel_capacity;
		}
		else return false; 
	}

	if (fuel <= 0 || fuel_consumption / 100.0 > fuel) return false;

	Base::set_vehicles(Base::get_vehicles() - 1);
	Base::set_people(Base::get_people() - 1);
	fuel -= fuel_consumption / 100.0;
	is_active = false;
	return true;
}


// --- Truck ---
Truck::Truck(bool is_active, Human* driver, double fuel_capacity, double max_load)
	: Vehicle(is_active, driver, 0, 0, fuel_capacity), max_load(max_load), load(0.0) {
}

Truck::Truck(Human* driver, double fuel, double fuel_consumption, double fuel_capacity, double max_load)
	: Vehicle(true, driver, fuel, fuel_consumption, fuel_capacity), max_load(max_load), load(0.0) {
}

Truck::Truck(double petrol_amount, double tank_volume, double max_load)
	: Vehicle(petrol_amount, tank_volume), max_load(max_load), load(0.0) {
}

Truck::Truck(double tank_volume, double max_load)
	: Vehicle(tank_volume), max_load(max_load), load(0.0) {
}

Truck::Truck(Human* driver, bool is_active, double fuel_capacity, double max_load)
	: Vehicle(driver, is_active, fuel_capacity), max_load(max_load), load(0.0) {
}

istream& operator>>(istream& in, Truck& truck)
{
	cout << "Enter max load (tons): ";
	in >> truck.max_load;
	Vehicle temp;
	in >> temp;
	truck.fuel = temp.get_petrol_amount();
	truck.fuel_capacity = temp.get_tank_volume();
	truck.fuel_consumption = temp.get_fuel_consumption();
	return in;
}

void Truck::arrive()
{
	if (driver == nullptr) throw "Truck has no driver.";
	if (is_active) throw "Truck is already on the base.";
	if (fuel <= 0 || fuel_consumption / 100.0 > fuel) throw "Truck has no enough fuel.";

	is_active = true;
	fuel -= fuel_consumption / 100.0;
	Base::set_vehicles(Base::get_vehicles() + 1);
	Base::set_goods(Base::get_goods() + load);
	Base::set_people(Base::get_people() + 1);
	load = 0.0;
}

bool Truck::leave()
{
	if (driver == nullptr || Base::get_people() <= 0 || !is_active || Base::get_vehicles() <= 0) return false;

	if (fuel < fuel_capacity && Base::get_petrol() > 0)
	{
		double needed_fuel = fuel_capacity - fuel;
		if (needed_fuel <= Base::get_petrol())
		{
			Base::set_petrol(Base::get_petrol() - needed_fuel);
			fuel = fuel_capacity;
		}
		else return false;
	}

	if (fuel <= 0 || fuel_consumption / 100.0 > fuel) return false;

	if (max_load > 0)
	{
		double goods_to_load = max_load - load;
		if (goods_to_load > Base::get_goods()) {
			goods_to_load = Base::get_goods();
		}

		if (goods_to_load > 0) {
			load += goods_to_load;
			Base::set_goods(Base::get_goods() - goods_to_load);
		}
	}

	Base::set_vehicles(Base::get_vehicles() - 1);
	Base::set_people(Base::get_people() - 1);
	fuel -= fuel_consumption / 100.0;
	is_active = false;
	return true;
}


// --- Bus ---
Bus::Bus(bool is_active, Human* driver, double fuel_capacity, int passenger_capacity)
	: Vehicle(is_active, driver, 0, 0, fuel_capacity), passenger_capacity(passenger_capacity), current_passengers(0) {
}

Bus::Bus(Human* driver, double fuel, double fuel_consumption, double fuel_capacity, int passenger_capacity)
	: Vehicle(true, driver, fuel, fuel_consumption, fuel_capacity), passenger_capacity(passenger_capacity), current_passengers(0) {
}

Bus::Bus(double petrol_amount, double tank_volume, int passenger_capacity)
	: Vehicle(petrol_amount, tank_volume), passenger_capacity(passenger_capacity), current_passengers(0) {
}

Bus::Bus(double tank_volume, int passenger_capacity)
	: Vehicle(tank_volume), passenger_capacity(passenger_capacity), current_passengers(0) {
}

Bus::Bus(Human* driver, bool is_active, double fuel_capacity, int passenger_capacity)
	: Vehicle(driver, is_active, fuel_capacity), passenger_capacity(passenger_capacity), current_passengers(0) {
}

istream& operator>>(istream& in, Bus& bus)
{
	cout << "Enter passenger capacity: ";
	in >> bus.passenger_capacity;
	Vehicle temp;
	in >> temp;
	bus.fuel = temp.get_petrol_amount();
	bus.fuel_capacity = temp.get_tank_volume();
	bus.fuel_consumption = temp.get_fuel_consumption();
	return in;
}

void Bus::arrive()
{
	if (driver == nullptr) throw "Bus has no driver.";
	if (is_active) throw "Bus is already on the base.";
	if (fuel <= 0 || fuel_consumption / 100.0 > fuel) throw "Bus has no enough fuel.";

	is_active = true;
	Base::set_vehicles(Base::get_vehicles() + 1);
	Base::set_people(Base::get_people() + current_passengers + 1);
	current_passengers = 0;
}

bool Bus::leave()
{
	if (driver == nullptr || Base::get_people() <= 0 || !is_active || Base::get_vehicles() <= 0) return false;

	if (fuel < fuel_capacity && Base::get_petrol() > 0)
	{
		double needed_fuel = fuel_capacity - fuel;
		if (needed_fuel <= Base::get_petrol())
		{
			Base::set_petrol(Base::get_petrol() - needed_fuel);
			fuel = fuel_capacity;
		}
		else return false;
	}

	if (fuel <= 0 || fuel_consumption / 100.0 > fuel) return false;

	int people_needed = passenger_capacity - current_passengers;
	if (people_needed > Base::get_people()) {
		people_needed = Base::get_people();
	}

	if (people_needed > 0) {
		current_passengers += people_needed;
		Base::set_people(Base::get_people() - people_needed);
	}

	Base::set_vehicles(Base::get_vehicles() - 1);

	fuel -= fuel_consumption / 100.0;
	is_active = false;
	return true;
}


// --- main ---
int main()
{
	Base base(
		vector<Human*>{
		new Human("John", "Doe", 30),
			new Human("Jane", "Smith", 28),
			new Human("Mike", "Johnson", 35),
			new Human("Emily", "Davis", 25),
			new Human("Chris", "Brown", 40),
			new Human("Anna", "Wilson", 32),
			new Human("David", "Taylor", 29),
			new Human("Laura", "Anderson", 27),
			new Human("James", "Thomas", 33),
			new Human("Olivia", "Jackson", 26),
			new Human("Daniel", "White", 31),
			new Human("Sophia", "Harris", 24)
	}, vector<Vehicle*>{
		new Truck(true, new Human("Driver1", "Truck", 45), 20.0, 10.0),
			new Bus(true, new Human("Driver2", "Bus", 38), 15.0, 50),
			new Truck(true, new Human("Driver3", "Truck", 50), 25.0, 15.0),
			new Bus(true, new Human("Driver4", "Bus", 42), 18.0, 60),
			new Truck(true, new Human("Driver5", "Truck", 37), 22.0, 12.0),
			new Bus(true, new Human("Driver6", "Bus", 39), 16.0, 55),
			new Bus(30.0, 120.0, 40),
			new Truck(50.0, 200.0, 20.0),
			new Bus(new Human("Driver7", "Bus", 41), false, 95.0, 65),
			new Truck(new Human("Driver8", "Truck", 36), false, 130.0, 18.0)
	}, 1000, 200, 5000.0, 20.0);

	int menu = 0;
	int vehicle_menu = 0;
	int vehicle_type = 0;
	Vehicle* temp;
	size_t index = -1;
	int personnel_menu = 0;
	Human* new_solider;

	do
	{
		cout << "Base Control Menu:\n";
		cout << "1. View Base Status\n";
		cout << "2. Manage Vehicles\n";
		cout << "3. Manage Personnel\n";
		cout << "0. Exit\n";
		cin >> menu;

		switch (menu)
		{
		case 1:
		{
			base.print_status();
			break;
		}
		case 2:
		{
			cout << "Manage Vehicles selected.\n";

			do
			{
				cout << "Vehicle Management Menu:\n";
				cout << "1. List Vehicles\n";
				cout << "2. Add Vehicle\n";
				cout << "3. Remove Vehicle\n";
				cout << "0. Back to Main Menu\n";
				cin >> vehicle_menu;

				switch (vehicle_menu)
				{
				case 1:
					cout << "Listing Vehicles...\n";
					base.print_vehicles();
					break;
				case 2:
					cout << "Adding Vehicle...\n";

					cout << "Select Vehicle Type to Add:\n";
					cout << "0. Vehicle\n";
					cout << "1. Truck\n";
					cout << "2. Bus\n";
					cin >> vehicle_type;

					switch (vehicle_type)
					{
					case 0:
						temp = new Vehicle();
						cin >> *temp;
						base.add_vehicle(temp);
						break;
					case 1:
						temp = new Truck();
						cin >> *temp;
						base.add_vehicle(temp);
						break;
					case 2:
						temp = new Bus();
						cin >> *temp;
						base.add_vehicle(temp);
						break;
					default:
						cout << "Invalid vehicle type selected.\n";
						continue;
					}
					break;
				case 3:
					cout << "Removing Vehicle...\n";
					cout << "Enter Vehicle Index to Remove: ";
					cin >> index;
					if (base.remove_vehicle(index - 1)) {
						cout << "Vehicle removed successfully.\n";
					}
					else {
						cout << "Invalid index. No vehicle removed.\n";
					}
					break;
				default:
					cout << "Returning to Main Menu...\n";
					break;
				}
			} while (vehicle_menu != 0);
			break;
		}
		case 3:

			do
			{
				cout << "Personnel Management Menu:\n";
				cout << "1. List Personnel\n";
				cout << "2. Add Personnel\n";
				cout << "3. Remove Personnel\n";
				cout << "0. Back to Main Menu\n";
				cin >> personnel_menu;

				switch (personnel_menu)
				{
				case 1:
					cout << "Listing Personnel...\n";
					base.print_soliders();
					break;
				case 2:
					cout << "Adding Personnel...\n";
					new_solider = new Human();
					cin >> *new_solider;
					base.add_solider(new_solider);
					break;
				case 3:
					cout << "Removing Personnel...\n";

					cout << "Enter Personnel Index to Remove: ";
					cin >> index;
					if (base.remove_solider(index - 1)) {
						cout << "Personnel removed successfully.\n";
					}
					else {
						cout << "Invalid index. No personnel removed.\n";
					}
					break;
				default:
					cout << "Returning to Main Menu...\n";
					break;
				}
			} while (personnel_menu != 0);
			break;
		default:
			cout << "Exiting Base Control...\n";
			break;
		}
	} while (menu != 0);

	for (Human* solider : base.get_soliders_list()) {
		delete solider;
	}
	for (Vehicle* vehicle : base.get_vehicles_list()) {
		Human* driver = vehicle->get_driver();
		if (driver != nullptr && driver->get_f_name().find("Driver") != string::npos)
		{
			delete driver;
		}
		delete vehicle;
	}

	return 0;
}