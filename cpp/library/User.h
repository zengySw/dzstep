#pragma once
#include <iostream>
using namespace std;

class Book;

class User
{
private:
	int id;
	string name;
	Book* library;
	int lib_size;
	int frequency;
	static int count;

	friend ostream& operator<< (ostream& os, const User& obj);
	friend istream& operator>> (istream& is, User& obj);
public:
	User() : name(""), lib_size(0), library(nullptr), id(count++), frequency(1) {};
	User(string name, const Book* library = nullptr, const int size = 0, int frequency = 1);
	User(string name, Book& book, int frequency = 1);
	User(const User& obj);
	Book* get_library() { return this->library; };
	int get_id() { return this->id; };
	string get_name() { return this->name; };
	int get_frequency() { return this->frequency; };
	int get_library_size() { return this->lib_size; };
	void add_book(Book& obj);
	void remove_book(int id);

	User& operator= (const User& obj);
	~User();

};