#include <string>
#include "User.h"
#include "Book.h"

int User::count = 0;

User::User(string name, const Book* library, const int size, int frequency)
{
	this->id = count++;
	if (size < 0) throw "Size can't be < 0";
	if (size > 3) throw "1 User can't owned more than 3 books";
	this->lib_size = size;
	if (library != nullptr && size > 0)
	{
		this->library = new Book[this->lib_size];
		for (size_t i = 0; i < this->lib_size; i++)
		{
			this->library[i] = library[i];
		}
	}
	else this->library = nullptr;
	this->name = name;
	if (frequency <= 0) throw "frequency can't be <= 0";
	this->frequency = frequency;
}

User::User(string name, Book& book, int frequency)
{
	this->id = count++;
	this->lib_size = 1;
	this->library = new Book[1];
	if (book.get_id() < 0) throw "book id can't be < 0";
	this->library[0] = book;
	this->name = name;
	if (frequency <= 0) throw "frequency can't be <= 0";
	this->frequency = frequency;
}

User::User(const User& obj)
{
	this->id = obj.id;
	this->name = obj.name;
	this->lib_size = obj.lib_size;
	this->frequency = obj.frequency;

	if (obj.library != nullptr && obj.lib_size > 0)
	{
		this->library = new Book[obj.lib_size];
		for (int i = 0; i < obj.lib_size; i++)
			this->library[i] = obj.library[i];
	}
	else this->library = nullptr;
}

void User::add_book(Book& obj)
{
	if (id < 0) throw "book id can't be < 0";
	if (this->lib_size + 1 > 3) throw "1 User can't owned more than 3 books";
	Book* temp = new Book[this->lib_size + 1];
	for (size_t i = 0; i < this->lib_size; i++)
	{
		temp[i] = this->library[i];
	}
	temp[this->lib_size++] = obj;
	delete[] this->library;
	this->library = temp;
}

void User::remove_book(int id)
{
	if (id < 0) throw "book id can't be < 0";
	if (this->lib_size == 0 || this->library == nullptr) return;

	if (this->lib_size == 1)
	{
		delete[] this->library;
		this->library = nullptr;
		this->lib_size = 0;
		return;
	}

	Book* temp = new Book[this->lib_size - 1];
	int j = 0;
	for (int i = 0; i < this->lib_size; ++i)
	{
		if (this->library[i].get_id() != id) temp[j++] = this->library[i];
	}

	delete[] this->library;
	if (j > 0)
	{
		this->library = temp;
		this->lib_size = j;
	}
	else
	{
		delete[] temp;
		this->library = nullptr;
		this->lib_size = 0;
	}
}

User& User::operator=(const User& obj)
{
	if (this == &obj) return *this;
	delete[] this->library;
	this->library = nullptr;
	this->id = obj.id;
	this->name = obj.name;
	this->lib_size = obj.lib_size;
	if (obj.library != nullptr && obj.lib_size > 0)
	{
		this->library = new Book[obj.lib_size];
		for (int i = 0; i < obj.lib_size; i++)
		{
			this->library[i] = obj.library[i];
		}
	}
	else this->library = nullptr;
	this->frequency = obj.frequency;
	return *this;
}

User::~User()
{
	delete[] library;
}

istream& operator>> (istream& is, User& obj)
{
	cout << "Name: ";
	getline(is >> ws, obj.name);

	int size;
	cout << "Lib size: ";
	if (!(is >> size)) throw "Invalid size input";
	if (size < 0) throw "lib size can't be < 0";

	if (obj.library != nullptr) {
		delete[] obj.library;
		obj.library = nullptr;
	}

	obj.lib_size = size;
	if (obj.lib_size > 0) {
		obj.library = new Book[obj.lib_size];
		for (int i = 0; i < obj.lib_size; ++i) {
			cout << i << " book: ";
			is >> obj.library[i];
		}
	}
	else {
		obj.library = nullptr;
	}
	return is;
}

ostream& operator<< (ostream& os, const User& obj)
{
	os << "Name: " << obj.name << endl << "Frequency: " << obj.frequency << endl;
	return os;
}