#pragma once
#include <iostream>
using namespace std;

class User;

class Book
{
private:
	int id;
	string name;
	string author;
	string genre;
	bool is_available;
	User* owner;
	static int count;
	friend ostream& operator<< (ostream& os, const Book& obj);
	friend istream& operator>> (istream& is, Book& obj);
public:
	Book();
	Book(string name, string author, string genre);
	void set_owner(User* smb);
	User* get_owner() { return this->owner; };
	void remove_owner();
	void set_available(bool is_available);
	int get_id() { return this->id; };
	bool get_is_available() { return this->is_available; }; 
	string get_author() { return this->author; };
	string get_name() { return this->name; };
	string get_genre() { return this->genre; };

	Book& operator= (const Book& obj);
};