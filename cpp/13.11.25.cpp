#include <iostream>
#include <string>

using namespace std;

class Transport
{
protected:
	string name;
	int year;
	int max_speed;
	double total_weight;
	int human_capacity;
public:
	Transport()
	{
		name = "";
		year = 0;
		max_speed = 0;
		total_weight = 0.0;
		human_capacity = 0;
	}
	Transport(string name, int year, int max_speed, double total_weight, int human_capacity)
	{
		this->name = name;
		this->year = year;
		this->max_speed = max_speed;
		this->total_weight = total_weight;
		this->human_capacity = human_capacity;
	}
	
	void set_name(string name) { this->name = name; }
	void set_year(int year) { this->year = year; }
	void set_max_speed(int max_speed) { this->max_speed = max_speed; }
	void set_total_weight(double total_weight) { this->total_weight = total_weight; }
	void set_human_capacity(int human_capacity) { this->human_capacity = human_capacity; }

	string get_name() { return this->name; }
	int get_year() { return this->year; }
	int get_max_speed() { return this->max_speed; }
	double get_total_weight() { return this->total_weight; }
	int get_human_capacity() { return this->human_capacity; }
	
	virtual void print() {
		cout << "Name: " << this->name << "\tYear: " << this->year << " y" << "\tMax speed: " << this->max_speed << " km/h" << "\tWeight:" << this->total_weight << " T" << "\tCapacity: " << this->human_capacity << " human's" << endl;
	}
};

class Cargo : public Transport
{
	double wheel_diameter;
	int engine_volume;
public:
	Cargo(string name, int year, int max_speed, double total_weight, int human_capacity, double wheel_diameter, int engine_volume)
		: Transport(name, year, max_speed, total_weight, human_capacity)
	{
		this->wheel_diameter = wheel_diameter;
		this->engine_volume = engine_volume;
	}
	
	void set_wheel_diameter(double wheel_diameter) { this->wheel_diameter = wheel_diameter; }
	void set_engine_volume(int engine_volume) { this->engine_volume = engine_volume; }

	double get_wheel_diameter() { return this->wheel_diameter; }
	int get_engine_volume() { return this->engine_volume; }
	
	void print() override
	{
		Transport::print();
		cout << "Wheel D: " << wheel_diameter << " sm" << "\tEngine V: " << engine_volume << " cc" << endl;
	}
};

class Plane : public Transport
{
	double wing_scope;
	int engine_volume;
public: 
	Plane(string name, int year, int max_speed, double total_weight, int human_capacity, double wing_scope, int engine_volume)
		: Transport(name, year, max_speed, total_weight, human_capacity)
	{
		this->wing_scope = wing_scope;
		this->engine_volume = engine_volume;
	}
	
	void set_wing_scope(double wing_scope) { this->wing_scope = wing_scope; }
	void set_engine_volume(int engine_volume) { this->engine_volume = engine_volume; }

	double get_wing_scope() { return this->wing_scope; }
	int get_engine_volume() { return this->engine_volume; }
	
	void print() override
	{
		Transport::print();
		cout << "Wings scope: " << wing_scope << " m" << "\tEngine V: " << engine_volume << " cc" << endl;
	}
};

class Boat : public Transport
{
	double max_long;
	int screw_count;
	double waterline_height;
public:
	Boat(string name, int year, int max_speed, double total_weight, int human_capacity, double max_long, int screw_count, double waterline_height)
		: Transport(name, year, max_speed, total_weight, human_capacity)
	{
		this->max_long = max_long;
		this->screw_count = screw_count;
		this->waterline_height = waterline_height;
	}
	
	void set_max_long(double max_long) { this->max_long = max_long; }
	void set_screw_count(int screw_count) { this->screw_count = screw_count; }
	void set_waterline_height(double waterline_height) { this->waterline_height = waterline_height; }

	double get_max_long() { return this->max_long; }
	int get_screw_count() { return this->screw_count; }
	double get_waterline_height() { return this->waterline_height; }
	
	void print() override
	{
		Transport::print();
		cout << "Long: " << max_long << " m" << "\tScrews count: " << screw_count << "\tWater line height:" << waterline_height << " m" << endl;
	}
};

class Car : public Transport
{
	string fuel_type;
	string gearbox_type;
	string carcase_type;
public:
	Car(string name, int year, int max_speed, double total_weight, int human_capacity, string fuel_type, string gearbox_type, string carcase_type)
		: Transport(name, year, max_speed, total_weight, human_capacity)
	{
		this->fuel_type = fuel_type;
		this->gearbox_type = gearbox_type;
		this->carcase_type = carcase_type;
	}
	
	void set_fuel_type(string fuel_type) { this->fuel_type = fuel_type; }
	void set_gearbox_type(string gearbox_type) { this->gearbox_type = gearbox_type; }
	void set_carcase_type(string carcase_type) { this->carcase_type = carcase_type; }

	string get_fuel_type() { return this->fuel_type; }
	string get_gearbox_type() { return this->gearbox_type; }
	string get_carcase_type() { return this->carcase_type; }
	
	void print() override
	{
		Transport::print();
		cout << "Fuel type: " << fuel_type << "\tGearbox type: " << gearbox_type << "\tCarcase type: " << carcase_type << endl;
	}
};

class Bike : public Transport
{
	string chassis_type;
	double wheel_diameter;
public:
	Bike(string name, int year, int max_speed, double total_weight, int human_capacity, string chassis_type, double wheel_diameter)
		: Transport(name, year, max_speed, total_weight, human_capacity)
	{
		this->chassis_type = chassis_type;
		this->wheel_diameter = wheel_diameter;
	}
	
	void set_chassis_type(string chassis_type) { this->chassis_type = chassis_type; }
	void set_wheel_diameter(double wheel_diameter) { this->wheel_diameter = wheel_diameter; }

	string get_chassis_type() { return this->chassis_type; }
	double get_wheel_diameter() { return this->wheel_diameter; }
	
	void print() override
	{
		Transport::print();
		cout << "Chassis type: " << chassis_type << "\tWheels D: " << wheel_diameter << " sm" << endl;
	}
};

class Tank : public Transport
{
	string tank_type;
	string fuel_type;
	bool fire_available;
public:
	Tank(string name, int year, int max_speed, double total_weight, int human_capacity, string tank_type, string fuel_type, bool fire_available)
		: Transport(name, year, max_speed, total_weight, human_capacity)
	{
		this->tank_type = tank_type;
		this->fuel_type = fuel_type;
		this->fire_available = fire_available;
	}
	
	void set_tank_type(string tank_type) { this->tank_type = tank_type; }
	void set_fuel_type(string fuel_type) { this->fuel_type = fuel_type; }
	void set_fire_available(bool fire_available) { this->fire_available = fire_available; }

	string get_tank_type() { return this->tank_type; }
	string get_fuel_type() { return this->fuel_type; }
	bool get_fire_available() { return this->fire_available; }
	
	void print() override
	{
		Transport::print();
		cout << "Tank type: " << tank_type << "\tFuel type: " << fuel_type << "\tFire: " << (fire_available ? "available" : "not available") << endl;
	}
};

int main() {
    
	Transport* transports[] = {
		new Car("Tesla Model S", 2023, 250, 2.1, 5, "Electric", "Automatic", "Sedan"),
		new Cargo("Volvo FH16", 2018, 90, 40.0, 2, 90.0, 16000),
		new Plane("Boeing 747", 1970, 920, 440.0, 600, 64.4, 25000),
		new Boat("Titanic", 1912, 43, 52000.0, 2435, 269.1, 3, 10.5),
		new Tank("T-14 Armata", 2015, 80, 55.0, 3, "Main Battle Tank", "Diesel", true),
		new Bike("Yamaha R1", 2021, 299, 0.2, 2, "Sport", 43.18)
	};
	
	cout << "--- Transport List ---\n";
	for (Transport* t : transports) {
		t->print();
	}
	cout << "----------------------\n";

	for (Transport* t : transports) {
		delete t;
	}

	return 0;
}