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
	void add_user();
	void add_list_users(const User* users = nullptr, const int users_count = 0);
	void add_book();
	void add_library(const Book* lib = nullptr, const int books_count = 0);
	void remove_user(const int id);
	void remove_book(const int id);
	Book& find_book_via_name(string name);
	Book* find_book_via_genre(string genre);
	Book* find_book_via_author(string author);
	User& get_user(const int id) { return this->users[id]; };
	User& most_frequent_user();
	void show_all_library();
	void show_available_library();
	void show_all_users();
	void show_user_via_id(const int id);
	void show_book_via_id(const int id);
	void show_all_books_via_genre(const string genre);
	void show_all_books_via_author(const string author);
	int get_books_count() { return this->books_count; };
	int get_users_count() { return this->users_count; };
	void lend_book(const int u_id, const int b_id);
	void return_book(const int u_id, const int b_id);
	~Library();
};