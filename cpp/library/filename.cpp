#include <iostream>
#include "Library.h"
using namespace std;

// idk ww it call err

int main() {
    Book books[30] = {
        Book("Dune", "Frank Herbert", "Sci-Fi"),
        Book("1984", "George Orwell", "Dystopia"),
        Book("The Hobbit", "J.R.R. Tolkien", "Fantasy"),
        Book("Fahrenheit 451", "Ray Bradbury", "Dystopia"),
        Book("Brave New World", "Aldous Huxley", "Dystopia"),
        Book("The Catcher in the Rye", "J.D. Salinger", "Drama"),
        Book("To Kill a Mockingbird", "Harper Lee", "Classic"),
        Book("The Great Gatsby", "F. Scott Fitzgerald", "Classic"),
        Book("Moby Dick", "Herman Melville", "Adventure"),
        Book("The Lord of the Rings", "J.R.R. Tolkien", "Fantasy"),
        Book("Crime and Punishment", "Fyodor Dostoevsky", "Philosophical"),
        Book("The Brothers Karamazov", "Fyodor Dostoevsky", "Drama"),
        Book("War and Peace", "Leo Tolstoy", "Historical"),
        Book("Anna Karenina", "Leo Tolstoy", "Drama"),
        Book("The Picture of Dorian Gray", "Oscar Wilde", "Philosophical"),
        Book("Dracula", "Bram Stoker", "Horror"),
        Book("Frankenstein", "Mary Shelley", "Horror"),
        Book("The Shining", "Stephen King", "Horror"),
        Book("It", "Stephen King", "Horror"),
        Book("Pet Sematary", "Stephen King", "Horror"),
        Book("Harry Potter", "J.K. Rowling", "Fantasy"),
        Book("The Silmarillion", "J.R.R. Tolkien", "Fantasy"),
        Book("A Game of Thrones", "George R.R. Martin", "Fantasy"),
        Book("The Name of the Wind", "Patrick Rothfuss", "Fantasy"),
        Book("Mistborn", "Brandon Sanderson", "Fantasy"),
        Book("The Way of Kings", "Brandon Sanderson", "Fantasy"),
        Book("The Martian", "Andy Weir", "Sci-Fi"),
        Book("Ready Player One", "Ernest Cline", "Sci-Fi"),
        Book("Ender's Game", "Orson Scott Card", "Sci-Fi"),
        Book("Neuromancer", "William Gibson", "Cyberpunk")
    };

    Book alice_books[] = { books[0], books[1], books[2] };
    Book bob_books[] = { books[3], books[4] };
    Book charlie_books[] = { books[5], books[6], books[7] };
    Book dave_books[] = { books[8] };
    Book eve_books[] = { books[9], books[10], books[11], books[12] };
    Book frank_books[] = { books[13], books[14] };
    Book grace_books[] = { books[15], books[16], books[17] };
    Book heidi_books[] = { books[18] };
    Book ivan_books[] = { books[19], books[20], books[21] };
    Book judy_books[] = { books[22], books[23] };

    User users[10] = {
        User("Alice", alice_books, 3, 5),
        User("Bob", bob_books, 2, 3),
        User("Charlie", charlie_books, 3, 4),
        User("Dave", dave_books, 1, 2),
        User("Eve", eve_books, 4, 5),
        User("Frank", frank_books, 2, 3),
        User("Grace", grace_books, 3, 4),
        User("Heidi", heidi_books, 1, 2),
        User("Ivan", ivan_books, 3, 5),
        User("Judy", judy_books, 5, 4)
    };

    Library lib(users, 10, books, 30);


    int menu = 0;
    do {
        cout << "\n========= LIBRARY MENU =========\n";
        cout << "1. Search by title;\n";
        cout << "2. Search by genre;\n";
        cout << "3. Search by author;\n";
        cout << "4. Find the most frequent library visitor;\n";
        cout << "5. Display/add records (books, visitors);\n";
        cout << "6. Organize book lending/return;\n";
        cout << "0. Exit.\n";
        cout << "Choose: ";
        cin >> menu;

        string title, genre, author;
        int u_id, b_id;
        switch (menu) {
        case 1:
            cout << "Enter book title: ";
            cin.ignore();
            cin >> title;
            try {
                Book n = lib.find_book_via_name(title);
                cout << n << endl;
                cout << n.get_owner() << endl;
            }
            catch (const char* e) {
                cout << e << endl;
            }
            break;

        case 2:
            cout << "Enter genre: ";
            cin.ignore();
            cin >> genre;
            try {
                lib.show_all_books_via_genre(genre);
            }
            catch (const char* e) {
                cout << e << endl;
            }
            break;

        case 3:
            cout << "Enter author: ";
            cin.ignore();
            cin >> author;
            try {
                lib.show_all_books_via_author(author);
            }
            catch (const char* e) {
                cout << e << endl;
            }
            break;

        case 4:
            try {
                cout << "Most frequent visitor:\n" << lib.most_frequent_user() << endl;
            }
            catch (const char* e) {
                cout << e << endl;
            }
            break;

        case 5: {
            int sub = 0;
            cout << "\n--- Records Menu ---\n";
            cout << "1. Show all books;\n";
            cout << "2. Show all users;\n";
            cout << "3. Add a new book;\n";
            cout << "4. Add a new user;\n";
            cout << "0. Back;\n";
            cout << "Choose: ";
            cin >> sub;
            switch (sub) {
            case 1:
                lib.show_all_library();
                break;
            case 2:
                lib.show_all_users();
                break;
            case 3:
                lib.add_book();
                break;
            case 4:
                lib.add_user();
                break;
            default:
                break;
            }
            break;
        }

        case 6: {
            int sub = 0;
            cout << "\n--- Lending/Return Menu ---\n";
            cout << "1. Lend book;\n";
            cout << "2. Return book;\n";
            cout << "0. Back;\n";
            cout << "Choose: ";
            cin >> sub;

            cout << "Enter user id: ";
            cin >> u_id;
            cout << "Enter book id: ";
            cin >> b_id;

            try {
                if (sub == 1)
                    lib.lend_book(u_id, b_id);
                else if (sub == 2)
                    lib.return_book(u_id, b_id);
            }
            catch (const char* e) {
                cout << e << endl;
            }
            break;
        }
        case 7:
            cout << "User id: ";
            cin >> u_id;
            try
            {
                lib.show_user_via_id(u_id);
            }
            catch (const char* e)
            {
                cout << e << endl;
            }
            break;
        default:
            menu = 0;
            cout << "Exit.\n";
            break;
        }

    } while (menu > 0);

    return 0;
}