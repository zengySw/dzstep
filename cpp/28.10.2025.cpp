#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//  CLASS BOOK
class Book {
private:
    string title;
    string author;
    string genre;
    bool is_taken;
    int user_id;
public:
    Book(string title, string author, string genre)
        : title(title), author(author), genre(genre), is_taken(false), user_id(-1) {
    }

    string get_title() const { return title; }
    string get_author() const { return author; }
    string get_genre() const { return genre; }
    bool get_status() const { return is_taken; }
    int get_user_id() const { return user_id; }

    void borrow_book(int id) {
        if (!is_taken) {
            is_taken = true;
            user_id = id;
        }
        else {
            cout << "The book is already borrowed.\n";
        }
    }

    void return_book() {
        is_taken = false;
        user_id = -1;
    }

    void print_info() const {
        cout << "Title: " << title
            << " | Author: " << author
            << " | Genre: " << genre
            << " | Status: " << (is_taken ? "Borrowed" : "Available");
        if (is_taken)
            cout << " | Borrowed by User ID: " << user_id;
        cout << endl;
    }
};

// CLASS USER
class User {
private:
    string surname;
    int id;
    int books_taken;
public:
    User(string surname, int id) : surname(surname), id(id), books_taken(0) {}

    string get_surname() const { return surname; }
    int get_id() const { return id; }
    int get_books_taken() const { return books_taken; }

    void take_book() { books_taken++; }
    void return_book() { if (books_taken > 0) books_taken--; }

    void print_info() const {
        cout << "Surname: " << surname << " | ID: " << id << " | Books borrowed: " << books_taken << endl;
    }
};

// CLASS LIBRARY 
class Library {
private:
    vector<Book> books;
    vector<User> users;
    map<int, int> borrow_count;
public:
    void add_book(const Book& book) { books.push_back(book); }
    void add_user(const User& user) { users.push_back(user); }

    void show_books() const {
        cout << "\nAll Books:\n";
        for (const auto& book : books)
            book.print_info();
    }

    void show_users() const {
        cout << "\nAll Users:\n";
        for (const auto& user : users)
            user.print_info();
    }

    void search_by_title(const string& title) const {
        cout << "\nSearch by Title: " << title << endl;
        for (const auto& book : books)
            if (book.get_title() == title)
                book.print_info();
    }

    void search_by_author(const string& author) const {
        cout << "\nSearch by Author: " << author << endl;
        for (const auto& book : books)
            if (book.get_author() == author)
                book.print_info();
    }

    void search_by_genre(const string& genre) const {
        cout << "\nSearch by Genre: " << genre << endl;
        for (const auto& book : books)
            if (book.get_genre() == genre)
                book.print_info();
    }

    void borrow_book(const string& title, int user_id) {
        for (auto& book : books) {
            if (book.get_title() == title && !book.get_status()) {
                auto it = find_if(users.begin(), users.end(),
                    [&](const User& u) { return u.get_id() == user_id; });
                if (it != users.end()) {
                    if (it->get_books_taken() < 3) {
                        book.borrow_book(user_id);
                        const_cast<User&>(*it).take_book();
                        borrow_count[user_id]++;
                        cout << it->get_surname() << " borrowed \"" << title << "\"\n";
                    }
                    else {
                        cout << "The user already has 3 books borrowed.\n";
                    }
                }
                else {
                    cout << "User not found.\n";
                }
                return;
            }
        }
        cout << "Book not found or already borrowed.\n";
    }

    void return_book(const string& title, int user_id) {
        for (auto& book : books) {
            if (book.get_title() == title && book.get_status() && book.get_user_id() == user_id) {
                auto it = find_if(users.begin(), users.end(),
                    [&](const User& u) { return u.get_id() == user_id; });
                if (it != users.end()) {
                    book.return_book();
                    const_cast<User&>(*it).return_book();
                    cout << "Book \"" << title << "\" successfully returned.\n";
                }
                return;
            }
        }
        cout << "Return failed: book or user mismatch.\n";
    }

    void most_frequent_user() const {
        if (borrow_count.empty()) {
            cout << "No borrow records yet.\n";
            return;
        }
        int max_count = 0;
        int top_user_id = -1;
        for (auto& [id, count] : borrow_count)
            if (count > max_count) {
                max_count = count;
                top_user_id = id;
            }

        auto it = find_if(users.begin(), users.end(),
            [&](const User& u) { return u.get_id() == top_user_id; });

        if (it != users.end()) {
            cout << "\nMost Frequent Visitor: " << it->get_surname() << " (ID: " << it->get_id() << "), borrowed " << max_count << " books.\n";
        }
    }
};

// ==================== MENU SYSTEM ====================
int main() {
    Library library;
    int choice;

    // Some test data
    library.add_user(User("Smith", 1));
    library.add_user(User("Johnson", 2));
    library.add_book(Book("1984", "Orwell", "Dystopia"));
    library.add_book(Book("The Hobbit", "Tolkien", "Fantasy"));
    library.add_book(Book("It", "King", "Horror"));

    do {
        cout << "\n========== LIBRARY MENU ==========\n";
        cout << "1. Show all books\n";
        cout << "2. Show all users\n";
        cout << "3. Add new book\n";
        cout << "4. Add new user\n";
        cout << "5. Search by title\n";
        cout << "6. Search by author\n";
        cout << "7. Search by genre\n";
        cout << "8. Borrow a book\n";
        cout << "9. Return a book\n";
        cout << "10. Show most frequent visitor\n";
        cout << "0. Exit\n";
        cout << "=====================================\n";
        cout << "Enter your choice> ";
        cin >> choice;

        string title, author, genre, surname;
        int id;

        switch (choice) {
        case 1:
            library.show_books();
            break;
        case 2:
            library.show_users();
            break;
        case 3:
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter genre: ";
            getline(cin, genre);
            library.add_book(Book(title, author, genre));
            cout << "Book added.\n";
            break;
        case 4:
            cout << "Enter surname: ";
            cin.ignore();
            getline(cin, surname);
            cout << "Enter user ID: ";
            cin >> id;
            library.add_user(User(surname, id));
            cout << "User added.\n";
            break;
        case 5:
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            library.search_by_title(title);
            break;
        case 6:
            cout << "Enter author: ";
            cin.ignore();
            getline(cin, author);
            library.search_by_author(author);
            break;
        case 7:
            cout << "Enter genre: ";
            cin.ignore();
            getline(cin, genre);
            library.search_by_genre(genre);
            break;
        case 8:
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter user ID: ";
            cin >> id;
            library.borrow_book(title, id);
            break;
        case 9:
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter user ID: ";
            cin >> id;
            library.return_book(title, id);
            break;
        case 10:
            library.most_frequent_user();
            break;
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid option.\n";
            break;
        }

    } while (choice != 0);
}
