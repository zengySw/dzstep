#include "Library.h"

Library::Library()
{
	this->users = nullptr;
	users_count = 0;
	this->catalog = nullptr;
	books_count = 0;
}

Library::Library(const Book* catalog, const int books_count)
{
	if (catalog == nullptr) throw "Catalog can't be = nullptr";
	if (books_count <= 0) throw "Books count can't be <= 0";
	add_library(catalog, books_count);
}

Library::Library(const User* users, const int users_count, const Book* catalog, const int books_count)
{
	if (users == nullptr) throw "Users can't be = nullptr";
	if (users_count <= 0) throw "Users count can't be <= 0";
	if (catalog == nullptr) throw "Catalog can't be = nullptr";
	if (books_count <= 0) throw "Books count can't be <= 0";
	add_list_users(users, users_count);
	add_library(catalog, books_count);
}

void Library::add_user()
{
	int new_size = this->users_count + 1;
	User* temp = new User[new_size];
	for (int i = 0; i < this->users_count; ++i) temp[i] = this->users[i];
	cin >> temp[this->users_count];
	delete[] this->users;
	this->users = temp;
	this->users_count = new_size;
}


void Library::add_list_users(const User* users, const int users_count)
{
	if (users_count <= 0) throw "Count of users can't be <= 0";
	if (users == nullptr) throw "Users can't = nullptr";
	if (this->users != nullptr) delete[] this->users;
	this->users_count = users_count;
	this->users = new User[this->users_count];
	for (size_t i = 0; i < this->users_count; i++)
	{
		this->users[i] = users[i];
	}
}

void Library::add_book()
{
	Book* temp = new Book[this->books_count + 1];
	for (size_t i = 0; i < this->books_count; i++)
	{
		temp[i] = this->catalog[i];
	}
	delete[] this->catalog;
	cin >> temp[this->books_count++];
	this->catalog = temp;
}

void Library::add_library(const Book* lib, const int books_count)
{
	if (books_count <= 0) throw "Count of books can't be <= 0";
	if (lib == nullptr) throw "Lib can't = nullptr";
	if (this->catalog != nullptr) delete[] this->catalog;
	this->books_count = books_count;
	this->catalog = new Book[this->books_count];
	for (size_t i = 0; i < this->books_count; i++)
	{
		this->catalog[i] = lib[i];
	}
}

void Library::remove_user(const int id)
{
	if (users_count == 0) return;
	int new_size = this->users_count - 1;
	User* temp = new User[new_size];
	int j = 0;
	for (int i = 0; i < this->users_count; ++i)
	{
		if (this->users[i].get_id() != id)
		{
			if (j < new_size) temp[j++] = this->users[i];
		}
	}
	delete[] this->users;
	this->users = (j > 0 ? temp : nullptr);
	this->users_count = j;
	if (j == 0) delete[] temp;
}

void Library::remove_book(const int id)
{
	if (books_count == 0) return;
	int new_size = this->books_count - 1;
	Book* temp = new Book[new_size];
	int j = 0;
	for (int i = 0; i < this->books_count; ++i)
	{
		if (this->catalog[i].get_id() != id)
		{
			if (j < new_size) temp[j++] = this->catalog[i];
		}
	}
	delete[] this->catalog;
	this->catalog = (j > 0 ? temp : nullptr);
	this->books_count = j;
	if (j == 0) delete[] temp;
}


Book& Library::find_book_via_name(string name)
{
	if (name.empty()) throw "Name can't be empty";
	for (size_t i = 0; i < this->books_count; i++)
	{
		if (this->catalog[i].get_name() == name) return this->catalog[i];
	}
	throw "book " + name + " does not exist";
}

Book* Library::find_book_via_genre(string genre)
{
	if (genre.empty()) throw "Genre can't be empty";
	int res_count = 0;
	for (size_t i = 0; i < this->books_count; i++)
	{
		if (this->catalog[i].get_genre() == genre) res_count++;
	}
	if (res_count == 0) throw "Some books in " + genre + " does not exist";
	Book* res = new Book[res_count];
	int j = 0;
	for (size_t i = 0; i < this->books_count; i++)
	{
		if (this->catalog[i].get_genre() == genre) res[j++] = this->catalog[i];
	}

	return res;
}

Book* Library::find_book_via_author(string author)
{
	if (author.empty()) throw "Author can't be empty";
	int res_count = 0;
	for (size_t i = 0; i < this->books_count; i++)
	{
		if (this->catalog[i].get_author() == author) res_count++;
	}
	if (res_count == 0) throw "Some books of " + author + " does not exist";
	Book* res = new Book[res_count];
	int j = 0;
	for (size_t i = 0; i < this->books_count; i++)
	{
		if (this->catalog[i].get_author() == author) res[j++] = this->catalog[i];
	}

	return res;
}

User& Library::most_frequent_user()
{
	int max_freq = 0;
	int id = -1;
	for (int i = 0; i < this->users_count; i++)
	{
		if (this->users[i].get_frequency() > max_freq)
		{
			max_freq = this->users[i].get_frequency();
			id = i;
		}
	}
	if (id == -1) throw "No users exist";
	return this->users[id];
}

void Library::show_all_library()
{
	for (size_t i = 0; i < this->books_count; i++)
	{
		cout << i + 1 << ": " << catalog[i] << endl;
	}
}

void Library::show_available_library()
{
	for (size_t i = 0; i < this->books_count; i++)
	{
		if (catalog[i].get_is_available()) cout << i << ": " << catalog[i] << endl;
	}
}

void Library::show_all_users()
{
	for (size_t i = 0; i < this->users_count; i++)
	{
		cout << i + 1 << ": " << this->users[i] << endl;
	}
}

void Library::show_user_via_id(const int id)
{
	if (id < 0) throw "id can't be < 0";
	cout << this->users[id] << endl;
	if (this->users[id].get_library_size() > 0) cout << "Owned: " << endl;
	for (size_t i = 0; i < this->users[id].get_library_size(); i++)
	{
		cout << this->users[id].get_library()[i] << endl;
	}
}

void Library::show_book_via_id(const int id)
{
	if (id < 0) throw "id can't be < 0";
	cout << this->catalog[id] << endl;
	if (!this->catalog[id].get_is_available()) cout << "Owner: " << endl;
	cout << this->catalog[id].get_owner() << endl;
}

void Library::show_all_books_via_genre(const string genre)
{
	if (genre.empty()) throw "Genre can't be empty";
	for (size_t i = 0; i < this->books_count; i++)
	{
		if (this->catalog[i].get_genre() == genre) cout << catalog[i] << endl;
	}
}

void Library::show_all_books_via_author(const string author)
{
	if (author.empty()) throw "Author can't be empty";
	for (size_t i = 0; i < this->books_count; i++)
	{
		if (this->catalog[i].get_author() == author) cout << this->catalog[i] << endl;
	}
}

void Library::lend_book(const int u_id, const int b_id)
{
	this->users[u_id].add_book(this->catalog[b_id]);
	this->catalog[b_id].set_owner(&this->users[u_id]);
}

void Library::return_book(const int u_id, const int b_id)
{
	this->users[u_id].remove_book(b_id);
	this->catalog[b_id].remove_owner();
}

Library::~Library()
{
	delete[] users;
	delete[] catalog;
}