#include "Book.h"
#include "User.h"

int Book::count = 0;

Book::Book()
{
	this->name = "";
	this->author = "";
	this->genre = "";
	this->id = count++;
	this->is_available = true;
	this->owner = nullptr;
}

Book::Book(string name, string author, string genre)
{
	this->id = count++;
	this->name = name;
	this->author = author;
	this->genre = genre;
	this->is_available = true;
	this->owner = nullptr;
}

void Book::set_owner(User* smb)
{
	if (id < 0) throw "owner id can't be < 0";
	this->owner = smb;
	this->is_available = false;
}

void Book::remove_owner()
{
	this->owner = nullptr;
	this->is_available = true;
}

void Book::set_available(bool is_available)
{
	if (this->is_available == is_available) throw this->is_available ? "Book already avalible" : "Book already not avalible";
	this->is_available = is_available;
}

Book& Book::operator=(const Book& obj)
{
	if (this == &obj) return *this;
	this->id = obj.id;
	this->name = obj.name;
	this->author = obj.author;
	this->genre = obj.genre;
	this->is_available = obj.is_available;
	this->owner = obj.owner;

	return *this;
}

ostream& operator<< (ostream& os, const Book& obj)
{
	os << obj.author << ": " << obj.name << " ( " << obj.genre << " ) " << (obj.is_available ? "avalible" : "no avalible");
	return os;
}

istream& operator>> (istream& is, Book& obj)
{
	cout << "Name: ";
	is >> obj.name;
	cout << "Author: ";
	is >> obj.author;
	cout << "Genre: ";
	is >> obj.genre;
	obj.is_available = true;
	return is;
}