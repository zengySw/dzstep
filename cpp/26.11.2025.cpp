#include <iostream>
#include <vector>
#include <string>

using namespace std;

class employee {
protected:
	int salary;
	string name;
	int age;
public:
	employee() { salary = 0; name = ""; age = 0; }
	virtual int getsalary() { return salary; };

};

class manager : public employee {
	
protected:
	int salary;
public:
	manager() { salary = 11000; }
	int getsalary() override { return salary; };
};

class developer : public employee{

protected:
	int salary;
public:
	developer() { salary = 3500; }
	int getsalary() override { return salary; };
};

int main() {
	manager temp;	
	developer tempp;
	employee *ptr;
	manager& test = temp;
	developer& test1 = tempp;
	ptr = &test;
	cout << ptr->getsalary() << endl;
	ptr = &test1;
	cout << ptr->getsalary() << endl;

}
