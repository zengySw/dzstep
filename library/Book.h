#pragma once
#include <iostream>
using namespace std;

class Book
{
private:
	int id;
	string name;
	string authtor;
	string genre;
	bool is_avalible;
	int owner_id;
	static int count;
	friend ostream& operator<< (ostream& os, const Book& obj);
	friend istream& operator>> (istream& is, Book& obj);
public:
	Book();
	Book(string name, string authtor, string genre);
	void SetOwner(int id);
	int GetOwerId() { return this->owner_id; };
	void RemoveOwner();
	void SetAvalible(bool is_avalible);
	int GetId() { return this->id; };
	bool IsAvalible() { return this->is_avalible; };
	string GetAuthtor() { return this->authtor; };
	string GetName() { return this->name; };
	string GetGenre() { return this->genre; };

	Book& operator= (const Book& obj);
};

inline ostream& operator<< (ostream& os, const Book& obj)
{
	os << obj.authtor << ": " << obj.name << " ( " << obj.genre << " ) " << obj.is_avalible ? "avalible" : "no avalible";
	return os;
}

inline istream& operator>> (istream& is, Book& obj)
{
	cout << "Name: ";
	is >> obj.name;
	cout << "Authtor: ";
	is >> obj.authtor;
	cout << "Genre: ";
	is >> obj.genre;
	obj.is_avalible = true;
	return is;
}