#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Animal
{
protected:
	string type;
	double weight;
	double height;
	double width;
	double length;
	int population;
	int age;
public:
	Animal() { type = ""; weight = 0; height = 0; width = 0; length = 0; population = 0; age = 0; }
	Animal(string type, double weight, double height, double width, double length, int population, int age)
	{
		init(type, weight, height, width, length, population, age);
	}

	virtual void print() { cout << "Type: " << type << "\tWeight: " << weight << "\tHeight: " << height << "\tWidth: " << width << "\tLength: " << length << "\tPopulation: " << population << "\tAge: " << age << endl; }
	virtual void init(string type, double weight, double height, double width, double length, int population, int age)
	{
		this->type = type;
		this->weight = weight;
		this->height = height;
		this->width = width;
		this->length = length;
		this->population = population;
		this->age = age;
	}
	void eat() { cout << "Animal eats" << endl; }
	void move() { cout << "Animal moves" << endl; }
};

class Elephant : public Animal
{
	string land;
	double max_habitat_length;
public:
	Elephant() : Animal() { max_habitat_length = 0; }
	Elephant(string type, double weight, double height, double width, double length, int population, int age, string land, double max_habitat_length) : Animal(type, weight, height, width, length, population, age)
	{
		this->land = land;
		this->max_habitat_length = max_habitat_length;
	}

	void print() override
	{
		Animal::print();
		cout << "Land: " << land << "\tMax habitat length: " << max_habitat_length << " m" << endl;
	}
	void init(string type, double weight, double height, double width, double length, int population, int age, string land, double max_habitat_length)
	{
		Animal::init(type, weight, height, width, length, population, age);
		this->land = land;
		this->max_habitat_length = max_habitat_length;
	}
};

class Penguin : public Animal
{
	string land;
	string color;
public:
	Penguin() : Animal() { land = ""; color = ""; }
	Penguin(string type, double weight, double height, double width, double length, int population, int age, string land, string color) : Animal(type, weight, height, width, length, population, age)
	{
		this->land = land;
		this->color = color;
	}
	void print() override
	{
		Animal::print();
		cout << "Land: " << land << "\tColor: " << color << endl;
	}
	void init(string type, double weight, double height, double width, double length, int population, int age, string land, string color)
	{
		Animal::init(type, weight, height, width, length, population, age);
		this->land = land;
		this->color = color;
	}
};

class Parrot : public Animal
{
	bool can_talk;
	string color;
public:
	Parrot() : Animal() { can_talk = false; color = ""; }
	Parrot(string type, double weight, double height, double width, double length, int population, int age, bool can_talk, string color) : Animal(type, weight, height, width, length, population, age)
	{
		this->can_talk = can_talk;
		this->color = color;
	}
	void print() override
	{
		Animal::print();
		cout << (can_talk ? "Can talk" : "Can't talk") << "\tColor: " << color << endl;
	}
	void init(string type, double weight, double height, double width, double length, int population, int age, bool can_talk, string color)
	{
		Animal::init(type, weight, height, width, length, population, age);
		this->can_talk = can_talk;
		this->color = color;
	}
};

class Shark : public Animal
{
	double bite_force_nm;
public:
	Shark() : Animal() { bite_force_nm = 0; }
	Shark(string type, double weight, double height, double width, double length, int population, int age, double bite_force_nm) : Animal(type, weight, height, width, length, population, age)
	{
		this->bite_force_nm = bite_force_nm;
	}
	void print() override
	{
		Animal::print();
		cout << "Bite force: " << bite_force_nm << " N/m" << endl;
	}
	void init(string type, double weight, double height, double width, double length, int population, int age, double bite_force_nm)
	{
		Animal::init(type, weight, height, width, length, population, age);
		this->bite_force_nm = bite_force_nm;
	}
};

int main() {
	Animal* obj = nullptr;

	cout << "Choose animal:\n";
	cout << "1 - Elephant\n";
	cout << "2 - Shark\n";
	cout << "3 - Penguin\n";
	cout << "4 - Parrot\n";
	cout << "Your choice: ";

	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "\nYou chose: ELEPHANT\n\n";
		obj = new Elephant("Elephant", 6000, 3.2, 1.5, 6.0, 300000, 60, "Africa", 2.4);
		break;

	case 2:
		cout << "\nYou chose: SHARK\n\n";
		obj = new Shark("Great White Shark", 1100, 1.5, 0.8, 4.5, 50000, 30, 2000);
		break;

	case 3:
		cout << "\nYou chose: PENGUIN\n\n";
		obj = new Penguin("Penguin", 35, 1.1, 0.4, 0.8, 25000000, 20, "Antarctica", "Black-White");
		break;

	case 4:
		cout << "\nYou chose: Parrot\n\n";
		obj = new Parrot("Parrot", 0.3, 0.25, 0.05, 0.3, 10000000, 1, true, "Orange");
		break;

	default:
		cout << "\nWrong choice\n";
		return 0;
	}
	obj->print();
	obj->eat();
	obj->move();

	delete obj;
	return 0;
}