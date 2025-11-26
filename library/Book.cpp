#include "Book.h"

int Book::count = 0;

Book::Book()
{
	this->name = "";
	this->authtor = "";
	this->genre = "";
	this->id = count++;
	this->is_avalible = true;
	this->owner_id = -1;
	count++;
}

Book::Book(string name, string authtor, string genre)
{
	this->id = count++;
	this->name = name;
	this->authtor = authtor;
	this->genre = genre;
	this->is_avalible = true;
	this->owner_id = -1;
	count++;
}

void Book::SetOwner(int id)
{
	if (id < 0) throw "owner id can't be < 0";
	this->owner_id = id;
	this->is_avalible = false;
}

void Book::RemoveOwner()
{
	this->owner_id = -1;
	this->is_avalible = true;
}

void Book::SetAvalible(bool is_avalible)
{
	if (this->is_avalible == is_avalible) throw this->is_avalible ? "Book already avalible" : "Book already not avalible";
	this->is_avalible = is_avalible;
}

Book& Book::operator=(const Book& obj)
{
	if (this == &obj) return *this;
	this->id = obj.id;
	this->name = obj.name;
	this->authtor = obj.authtor;
	this->genre = obj.genre;
	this->is_avalible = obj.is_avalible;

	return *this;
}