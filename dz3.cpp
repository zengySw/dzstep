#include <iostream>
using namespace std;

class car {
private:
	int fuel;
	int series;
	string model;
	string mark;
public:
	car() {
		fuel = 0;
		series = 0;
		model = "qx70";
		mark = "infiniti";
	}

	car(int Cfuel, int Cseries, string Cmodel, string Cmark) {
		fuel = Cfuel;
		series = Cseries;
		model = Cmodel;
		mark = Cmark;
	}

	~car() {
		fuel = 0;
		series = 0;
		model = nullptr;
		mark = nullptr;
	}

	void write(int Ffuel, int Fseries, string Fmodel, string Fmark) {
		fuel = Ffuel;
		series = Fseries;
		model = Fmodel;
		mark = Fmark;
	}

};

int main() {
	car obj1;
	obj1.write(99, 1968, "challenger", "dodge");

	car obj2;
	obj2.write(99, 1968, "challenger", "dodge")
}
