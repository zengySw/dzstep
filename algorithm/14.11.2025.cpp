#include <iostream>
#include <string> 
using namespace std;

class Transport
{
protected:
	string name_;
	int year_;
	int max_speed_;
	double total_weight_;
	int human_capacity_;
public:
	Transport()
	{
		name_ = "";
		year_ = 0;
		max_speed_ = 0;
		total_weight_ = 0.0;
		human_capacity_ = 0;
	}
	Transport(string name, int year, int max_speed, double total_weight, int human_capacity)
	{
		this->name_ = name;
		this->year_ = year;
		this->max_speed_ = max_speed;
		this->total_weight_ = total_weight;
		this->human_capacity_ = human_capacity;
	}
	void set_name(string name) { this->name_ = name; }
	void set_year(int year) { this->year_ = year; }
	void set_max_speed(int max_speed) { this->max_speed_ = max_speed; }
	void set_total_weight(double total_weight) { this->total_weight_ = total_weight; }
	void set_human_capacity(int human_capacity) { this->human_capacity_ = human_capacity; }

	string get_name() { return this->name_; }
	int get_year() { return this->year_; }
	int get_max_speed() { return this->max_speed_; }
	double get_total_weight() { return this->total_weight_; }
	int get_human_capacity() { return this->human_capacity_; }
	void print() {
		cout << "Name: " << this->name_ << "\tYear: " << this->year_ << " y" << "\tMax speed: " << this->max_speed_ << " km/h" << "\tWeight:" << this->total_weight_ << " T" << "\tCapacity: " << this->human_capacity_ << " human's" << endl;
	}
};

class Cargo : public Transport
{
	double diameter_wheels_;
	int volume_engine_;
public:
	Cargo(string name, int year, int max_speed, double total_weight, int human_capacity, double diameter_wheels, int volume_engine)
		: Transport(name, year, max_speed, total_weight, human_capacity)
	{
		this->diameter_wheels_ = diameter_wheels;
		this->volume_engine_ = volume_engine;
	}
	void set_diameter_wheels(double diameter_wheels) { this->diameter_wheels_ = diameter_wheels; }
	void set_volume_engine(int volume_engine) { this->volume_engine_ = volume_engine; }

	double get_diameter_wheels() { return this->diameter_wheels_; }
	int get_volume_engine() { return this->volume_engine_; }
	void print()
	{
		Transport::print();
		cout << "Weels D: " << diameter_wheels_ << " sm" << "\tEngine V: " << volume_engine_ << " cm^3" << endl;
	}
};

class Plane : public Transport
{
	double max_wings_scope_;
	int volume_engine_;
public: 
	Plane(string name, int year, int max_speed, double total_weight, int human_capacity, double max_wings_scope, int volume_engine)
		: Transport(name, year, max_speed, total_weight, human_capacity)
	{
		this->max_wings_scope_ = max_wings_scope;
		this->volume_engine_ = volume_engine;
	}
	void set_max_wings_scope(double max_wings_scope) { this->max_wings_scope_ = max_wings_scope; }
	void set_volume_engine(int volume_engine) { this->volume_engine_ = volume_engine; }

	double get_max_wings_scope() { return this->max_wings_scope_; }
	int get_volume_engine() { return this->volume_engine_; }
	void print()
	{
		Transport::print();
		cout << "Wings scope: " << max_wings_scope_ << " m" << "\tEngine V: " << volume_engine_ << " cm^3" << endl;
	}
};

class Boat : public Transport
{
	double max_long_;
	int screw_count_;
	double max_waterline_height_;
public:
	Boat(string name, int year, int max_speed, double total_weight, int human_capacity, double max_long, int screw_count, double max_waterline_height)
		: Transport(name, year, max_speed, total_weight, human_capacity)
	{
		this->max_long_ = max_long;
		this->screw_count_ = screw_count;
		this->max_waterline_height_ = max_waterline_height;
	}
	void set_max_long(double max_long) { this->max_long_ = max_long; }
	void set_screw_count(int screw_count) { this->screw_count_ = screw_count; }
	void set_max_waterline_height(double max_waterline_height) { this->max_waterline_height_ = max_waterline_height; }

	double get_max_long() { return this->max_long_; }
	int get_screw_count() { return this->screw_count_; }
	double get_max_waterline_height() { return this->max_waterline_height_; }
	void print()
	{
		Transport::print();
		cout << "Long: " << max_long_ << " m" << "\tScrews count: " << screw_count_ << "\tWater line height: " << max_waterline_height_ << " m" << endl;
	}
};

class Car : public Transport
{
	string fuel_type_;
	string gearbox_type_;
	string carcase_type_;
public:
	Car(string name, int year, int max_speed, double total_weight, int human_capacity, string fuel_type, string gearbox_type, string carcase_type)
		: Transport(name, year, max_speed, total_weight, human_capacity)
	{
		this->fuel_type_ = fuel_type;
		this->gearbox_type_ = gearbox_type;
		this->carcase_type_ = carcase_type;
	}
	void set_fuel_type(string fuel_type) { this->fuel_type_ = fuel_type; }
	void set_gearbox_type(string gearbox_type) { this->gearbox_type_ = gearbox_type; }
	void set_carcase_type(string carcase_type) { this->carcase_type_ = carcase_type; }

	string get_fuel_type() { return this->fuel_type_; }
	string get_gearbox_type() { return this->gearbox_type_; }
	string get_carcase_type() { return this->carcase_type_; }
	void print()
	{
		Transport::print();
		cout << "Fuel type: " << fuel_type_ << "\tGearbox type: " << gearbox_type_ << "\tCarcase type: " << carcase_type_ << endl;
	}
};

class Bike : public Transport
{
	string chassis_type_;
	double diameter_wheels_;
public:
	Bike(string name, int year, int max_speed, double total_weight, int human_capacity, string chassis_type, double diameter_wheels)
		: Transport(name, year, max_speed, total_weight, human_capacity)
	{
		this->chassis_type_ = chassis_type;
		this->diameter_wheels_ = diameter_wheels;
	}
	void set_chassis_type(string chassis_type) { this->chassis_type_ = chassis_type; }
	void set_diameter_wheels(double diameter_wheels) { this->diameter_wheels_ = diameter_wheels; }

	string get_chassis_type() { return this->chassis_type_; }
	double get_diameter_wheels() { return this->diameter_wheels_; }
	void print()
	{
		Transport::print();
		cout << "Chassis type: " << chassis_type_ << "\tWheels D: " << diameter_wheels_ << " sm" << endl;
	}
};

class Tank : public Transport
{
	string tank_type_;
	string fuel_type_;
	bool fire_available_;
public:
	Tank(string name, int year, int max_speed, double total_weight, int human_capacity, string tank_type, string fuel_type, bool fire_available)
		: Transport(name, year, max_speed, total_weight, human_capacity)
	{
		this->tank_type_ = tank_type;
		this->fuel_type_ = fuel_type;
		this->fire_available_ = fire_available;
	}
	void set_tank_type(string tank_type) { this->tank_type_ = tank_type; }
	void set_fuel_type(string fuel_type) { this->fuel_type_ = fuel_type; }
	void set_fire_available(bool fire_available) { this->fire_available_ = fire_available; }

	string get_tank_type() { return this->tank_type_; }
	string get_fuel_type() { return this->fuel_type_; }
	bool get_fire_available() { return this->fire_available_; }
	void print()
	{
		Transport::print();
		cout << "Tank type: " << tank_type_ << "\tFuel type: " << fuel_type_ << "\tFire: " << (fire_available_ ? "available" : "not available") << endl;
	}
};

int main() {
	Car car("Toyota Corolla", 2020, 180, 1.5, 5, "Gasoline", "Automatic", "Sedan");
	car.print();

	Tank tank("T-90", 1993, 60, 46.5, 3, "Main Battle Tank", "Diesel", true);
	tank.print();

}
