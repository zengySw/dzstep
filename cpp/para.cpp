#include <iostream>
using namespace std;

class human {
protected:
	string name;
	int age;
public:
	human() {
		name = "Oleh";
		age = 16;
	}
	int getage() {
		return age;
	}
	string getname() {
		return name;
	}
	void setname(string a) {
		name = a;
	}
	void setage(int a) {
		age = a;
	}
	void print() {
		cout << "name: " << name << " age: " << age << endl;
	}
};

class employer : public human {
protected:
	string company;
public:
	employer() {
		company = "microsoft";
	}
	string getcomp() {
		return company;
	}
	void setcomp(string a) {
		company = a;
	}
	void print() {
		cout << "name: " << name << " age: " << age << " company: " << company << endl;
	}
};



int main()
{
	employer test;
	test.print();
	cout << endl;
	human test1;
	test1.print();
	cout << endl;
	test.setname("sasa");
	test.print();
}