#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <stdexcept>
#include <typeinfo>
using namespace std;

class animal {
protected:
	string name;
	int age;
public:
	animal() {
		name = "BASE_CLASS";
		age = 0;
	}
	string getName() {
		return name;
	}
	void setName(string a) {
		name = a;
	}
	virtual void print() const = 0;
};


class herbivores : public animal {
protected:
	string land;
	string team; // like cats or else

public:
	herbivores() {
		land = "no_set";
	}
};

class elephant :public herbivores {
protected:

public:
	elephant() {
		name = "DEFAULT";
		age = 0;
		team = "DEFAULT";
		land = "DEFAULT";
	}
	elephant(string l, int a, string n, string t) {
		name = n;
		age = a;
		team = t;
		land = l;
	}
	void input() {
		cout << "enter name: "; cin >> name;
		cout << "enter land: "; cin >> land;
		cout << "enter age: "; cin >> age;
		cout << "enter team: "; cin >> team;
	}
	void print() const override {
		cout << "name: " << name << endl;
		cout << "land: " << land << endl;
		cout << "age: " << age << endl;
		cout << "team: " << team << endl;
	}
	void move() {

		cout << "is move" << endl;
	}
};

class rabbit :public herbivores {
protected:

public:
	rabbit() {
		name = "DEFAULT";
		age = 0;
		team = "DEFAULT";
		land = "DEFAULT";
	}
	rabbit(string l, int a, string n, string t) {
		name = n;
		age = a;
		team = t;
		land = l;
	}
	void input() {
		cout << "enter name: "; cin >> name;
		cout << "enter land: "; cin >> land;
		cout << "enter age: "; cin >> age;
		cout << "enter team: "; cin >> team;
	}
	void print() const override {
		cout << "name: " << name << endl;
		cout << "land: " << land << endl;
		cout << "age: " << age << endl;
		cout << "team: " << team << endl;
	}
	void move() {

		cout << "is move" << endl;
	}
};

class jiraffe :public herbivores {
protected:

public:
	jiraffe() {
		name = "DEFAULT";
		age = 0;
		team = "DEFAULT";
		land = "DEFAULT";
	}
	jiraffe(string l, int a, string n, string t) {
		name = n;
		age = a;
		team = t;
		land = l;
	}
	void input() {
		cout << "enter name: "; cin >> name;
		cout << "enter land: "; cin >> land;
		cout << "enter age: "; cin >> age;
		cout << "enter team: "; cin >> team;
	}
	void print() const override {
		cout << "name: " << name << endl;
		cout << "land: " << land << endl;
		cout << "age: " << age << endl;
		cout << "team: " << team << endl;
	}
	void move() {

		cout << "is move" << endl;
	}
};
//------------------
class carnivores : public animal {
protected:
	string land;
	string team; // like cats or else
public:
	carnivores() {
		age = 0;
	}
	carnivores(int a) {
		age = a;
	}
	void print() const override {
		cout << "name: " << name << endl;
		cout << "age: " << age << endl;
	}

};

class wolf :public carnivores {
protected:

public:
	wolf() {
		name = "DEFAULT";
		age = 0;
		team = "DEFAULT";
		land = "DEFAULT";
	}
	wolf(string l, int a, string n, string t) {
		name = n;
		age = a;
		team = t;
		land = l;
	}
	void input() {
		cout << "enter name: "; cin >> name;
		cout << "enter land: "; cin >> land;
		cout << "enter age: "; cin >> age;
		cout << "enter team: "; cin >> team;
	}
	void print() const override {
		cout << "name: " << name << endl;
		cout << "land: " << land << endl;
		cout << "age: " << age << endl;
		cout << "team: " << team << endl;
	}
	void move() {

		cout << "is move" << endl;
	}
};

class eagle :public carnivores {
protected:

public:
	eagle() {
		name = "DEFAULT";
		age = 0;
		team = "DEFAULT";
		land = "DEFAULT";
	}
	eagle(string l, int a, string n, string t) {
		name = n;
		age = a;
		team = t;
		land = l;
	}
	void input() {
		cout << "enter name: "; cin >> name;
		cout << "enter land: "; cin >> land;
		cout << "enter age: "; cin >> age;
		cout << "enter team: "; cin >> team;
	}
	void print() const override {
		cout << "name: " << name << endl;
		cout << "land: " << land << endl;
		cout << "age: " << age << endl;
		cout << "team: " << team << endl;
	}
	void fly() {

		cout << "is fly" << endl;
	}
};

class shark :public carnivores {
protected:

public:
	shark() {
		name = "DEFAULT";
		age = 0;
		team = "DEFAULT";
		land = "DEFAULT";
	}
	shark(string l, int a, string n, string t) {
		name = n;
		age = a;
		team = t;
		land = l;
	}
	void input() {
		cout << "enter name: "; cin >> name;
		cout << "enter land: "; cin >> land;
		cout << "enter age: "; cin >> age;
		cout << "enter team: "; cin >> team;
	}
	void print() const override {
		cout << "name: " << name << endl;
		cout << "land: " << land << endl;
		cout << "age: " << age << endl;
		cout << "team: " << team << endl;
	}
	void swim() {

		cout << "is swim" << endl;
	}
};

class snake :public carnivores {
protected:

public:
	snake() {
		name = "DEFAULT";
		age = 0;
		team = "DEFAULT";
		land = "DEFAULT";
	}
	snake(string l, int a, string n, string t) {
		name = n;
		age = a;
		team = t;
		land = l;
	}
	void input() {
		cout << "enter name: "; cin >> name;
		cout << "enter land: "; cin >> land;
		cout << "enter age: "; cin >> age;
		cout << "enter team: "; cin >> team;
	}
	void print() const override {
		cout << "name: " << name << endl;
		cout << "land: " << land << endl;
		cout << "age: " << age << endl;
		cout << "team: " << team << endl;
	}
	void crawl() {

		cout << "is crawl" << endl;
	}
};


int main() {
	int temp;
	while (true)
	{
		cout << "between 1-7" << endl;
		cout << "try yourself: ";
		cin >> temp;
		switch (temp)
		{
		case 1: {
			elephant a;
			a.input();
			a.print();
			break;
		}
		case 2: {
			rabbit a;
			a.input();
			a.print();
			break;
		}
		case 3: {
			jiraffe a;
			a.input();
			a.print();
			break;
		}
		case 4: {
			wolf a;
			a.input();
			a.print();
			break;
		}
		case 5: {
			eagle a;
			a.input();
			a.print();
			break;
		}
		case 6: {
			shark a;
			a.input();
			a.print();
			break;
		}
		case 7: {
			snake a;
			a.input();
			a.print();
			break;
		}
		default:
			cout << "incorrect" << endl;
			break;
		}
	}
	
}