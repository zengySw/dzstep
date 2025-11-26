#pragma once
#include <iostream>
#include "Book.h"
using namespace std;

class User
{
private:
	int id;
	string name;
	int* library_ids;
	int lib_size;
	int frequency;
	static int count;

	friend ostream& operator<< (ostream& os, const User& obj);
	friend istream& operator>> (istream& is, User& obj);
public:
	User() : name(""), lib_size(0), library_ids(nullptr), id(count++), frequency(1) {};
	User(string name, int* library_ids, const int size, int frequency = 1);
	User(string name, int book_id, int frequency = 1);
	User(string name, Book* library, const int size, int frequency = 1);
	User(string name, Book& book, int frequency = 1);
	User(const User& obj);
	/*User(User&& obj);*/
	int* GetLibIds() { return this->library_ids; };
	int GetId() { return this->id; };
	string GetName() { return this->name; };
	int GetFreq() { return this->frequency; };
	int GetLibSize() { return this->lib_size; };
	void AddBook(int id);
	void RemoveBook(int id);

	User& operator= (const User& obj);
	~User();

};

inline ostream& operator<< (ostream& os, const User& obj)
{
	os << "Name: " << obj.name << endl << "Frequency: " << obj.frequency << endl;
	return os;
}

inline istream& operator>> (istream& is, User& obj)
{
	cout << "Name: ";
	is >> obj.name;
	cout << "Lib size: ";
	is >> obj.lib_size;
	if (obj.lib_size < 0) throw "lib size can't be < 0";
	if (obj.library_ids != nullptr) delete[] obj.library_ids;
	obj.library_ids = new int[obj.lib_size];
	for (size_t i = 0; i < obj.lib_size; i++)
	{
		cout << i << " book id: ";
		is >> obj.library_ids[i];
		if (obj.library_ids[i] < 0) throw "book id can't be < 0";
	}
	return is;
}