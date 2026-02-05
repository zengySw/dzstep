#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student
{
	string name;
	string surname;
	int age;
public:
	Student(string n, string s, int a)
	{
		name = n;
		surname = s;
		age = a;
	}
	void Print()
	{
		cout << "Name: " << name << "Surname: " << surname << "\tAge: " << age << endl;
	}
	void Input()
	{
		cout << "Enter Name: ";
		cin >> name;

		cout << "Enter Surname: ";
		cin >> surname;

		cout << "Enter Age: ";
		cin >> age;
	}

	void SaveFile()
	{
		ofstream file("student.txt");
		if (!file.is_open()) {
			cout << "File error\n";
			return;
		}

		file << name << endl;
		file << surname << endl;
		file << age << endl;

		file.close();
		cout << "Saved.\n";
	}
	void LoadFile()
	{
		ifstream file("student.txt");
		if (!file.is_open()) {
			cout << "File error\n";
			return;
		}
		string temp;

		getline(file, name); 
		getline(file, surname);
		file >> age;

		file.close();
		cout << "Loaded.\n";
	}

};

int main()
{
	Student obj1("Ivan", "Ivanov", 19);
	obj1.SaveFile();
	obj1.LoadFile();
	obj1.Print();

}