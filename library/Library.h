#pragma once
#include <iostream>
#include "Book.h"
#include "User.h"
using namespace std;

class Library
{
private:
	User* users;
	int users_count;
	Book* catalog;
	int books_count;
public:
	Library();
	Library(const Book* catalog = nullptr, const int books_count = 0);
	Library(const User* users = nullptr, const int users_count = 0, const Book* catalog = nullptr, const int books_count = 0);
	void AddUser();
	void AddListUs(const User* users = nullptr, const int users_count = 0);
	void AddBook();
	void AddLib(const Book* lib = nullptr, const int books_count = 0);
	void RemoveUser(const int id);
	void RemoveBook(const int id);
	Book& FindBookViaName(string name);
	Book* FiindBookViaGenre(string genre);
	Book* FindBookViaAuthtor(string authtor);
	User& GetUser(const int id) { return this->users[id]; };
	User& MostFrequenceUs();
	void ShowAllLibrary();
	void ShowAvalibleLibrary();
	void ShowAllUsers();
	void ShowUserViaId(const int id);
	void ShowBookViaId(const int id);
	void ShowAllBooksViaGenre(const string genre);
	void ShowAllBooksViaAuthtor(const string authtor);
	int GetBooksCount() { return this->books_count; };
	int GetUsersCount() { return this->users_count; };
	void LendBook(const int u_id, const int b_id);
	void ReturnBook(const int u_id, const int b_id);
	~Library();
};