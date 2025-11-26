#include <iostream>
#include <exception>
#include <string>
#include "Library.h"
using namespace std;

int main()
{
    try {
        Book books[30] = {
            Book("Clean Code", "Robert C. Martin", "Programming"),
            Book("Design Patterns", "Gamma, Helm, Johnson, Vlissides", "Software Engineering"),
            Book("The Mythical Man-Month", "Frederick Brooks", "Software Project Management"),
            Book("Grokking Algorithms", "Aditya Bhargava", "Computer Science"),
            
            Book("The Lean Startup", "Eric Ries", "Business"),
            Book("Thinking, Fast and Slow", "Daniel Kahneman", "Psychology/Economics"),
            Book("Principles", "Ray Dalio", "Finance"),
            
            Book("Sapiens: A Brief History of Humankind", "Yuval Noah Harari", "History"),
            Book("Cosmos", "Carl Sagan", "Astronomy"),
            Book("A Brief History of Time", "Stephen Hawking", "Physics"),
            
            Book("Gone Girl", "Gillian Flynn", "Thriller"),
            Book("The Silent Patient", "Alex Michaelides", "Thriller"),
            Book("Where the Crawdads Sing", "Delia Owens", "Literary Fiction"),
            Book("The Love Hypothesis", "Ali Hazelwood", "Romance"),
            Book("Milk and Honey", "Rupi Kaur", "Poetry"),

            Book("Deep Learning with Python", "Francois Chollet", "Machine Learning"),
            Book("The Joy of Cooking", "Irma S. Rombauer", "Cookbook"),
            Book("Zero to One", "Peter Thiel", "Venture Capital"),
            Book("The Art of War", "Sun Tzu", "Strategy"),
            Book("Drive", "Daniel Pink", "Self-Help"),
            Book("Atomic Habits", "James Clear", "Self-Help"),
            Book("Algorithms Unlocked", "Thomas H. Cormen", "Computer Science"),
            Book("The Secret History", "Donna Tartt", "Mystery"),
            Book("Educated", "Tara Westover", "Memoir"),
            Book("Permanent Record", "Edward Snowden", "Memoir"),
            Book("The Power of Habit", "Charles Duhigg", "Psychology"),
            Book("The Martian", "Andy Weir", "Sci-Fi"),
            Book("Exhalation", "Ted Chiang", "Short Stories"),
            Book("The Handmaid's Tale", "Margaret Atwood", "Dystopia"),
            Book("Circe", "Madeline Miller", "Mythology")
        };

        int programmer_books[] = { books[0].GetId(), books[1].GetId(), books[3].GetId() }; 
        int manager_books[] = { books[2].GetId(), books[4].GetId() }; 
        int scientist_books[] = { books[8].GetId(), books[9].GetId(), books[15].GetId() }; 
        int thriller_fan_books[] = { books[10].GetId(), books[11].GetId() }; 
        int business_pro_books[] = { books[6].GetId(), books[17].GetId(), books[18].GetId() }; 
        int selfhelp_reader_books[] = { books[19].GetId(), books[20].GetId(), books[25].GetId() }; 
        int history_buff_books[] = { books[7].GetId() };
        int lit_fan_books[] = { books[12].GetId(), books[22].GetId() }; 
        int memoir_lover_books[] = { books[23].GetId(), books[24].GetId() };
        int cook_books[] = { books[16].GetId() }; 

        User users[10] = {
            User("Elena (Programmer)", programmer_books, 3, 6),
            User("Max (Manager)", manager_books, 2, 4),
            User("Sophia (Scientist)", scientist_books, 3, 5), 
            User("David (Thriller)", thriller_fan_books, 2, 3),
            User("Zoe (Business)", business_pro_books, 3, 6), 
            User("Alex (Self-Help)", selfhelp_reader_books, 3, 5),
            User("Victoria (History)", history_buff_books, 1, 2),
            User("George (Literary)", lit_fan_books, 2, 4),
            User("Liam (Memoir)", memoir_lover_books, 2, 3),
            User("Mia (Cook)", cook_books, 1, 2)
        };

        Library lib(users, 10, books, 30);

        int menu = 0;

        do {
            cout << "\n========= LIBRARY MENU =========\n";
            cout << "1. Search by title;\n";
            cout << "2. Search by genre;\n";
            cout << "3. Search by author;\n";
            cout << "4. Most frequent visitor;\n";
            cout << "5. Records menu;\n";
            cout << "6. Lend/Return;\n";
            cout << "7. Show user;\n";
            cout << "0. Exit.\n";
            cout << "Choose: ";

            cin >> menu;

            if (!cin) throw "Invalid menu input";

            string s;
            int uid, bid;

            switch (menu) {

            case 1:
                cout << "Enter title: ";
                cin >> s;
                try {
                    Book b = lib.FindBookViaName(s);
                    cout << b << endl;
                    lib.ShowUserViaId(b.GetOwerId());
                }
                catch (const std::exception& e) { cout << e.what() << endl; }
                catch (const string& e) { cout << e << endl; }
                catch (const char* e) { cout << e << endl; }
                catch (...) { cout << "Unknown error.\n"; }
                break;

            case 2:
                cout << "Enter genre: ";
                cin >> s;
                try {
                    lib.ShowAllBooksViaGenre(s);
                }
                catch (const std::exception& e) { cout << e.what() << endl; }
                catch (const string& e) { cout << e << endl; }
                catch (const char* e) { cout << e << endl; }
                catch (...) { cout << "Unknown error.\n"; }
                break;

            case 3:
                cout << "Enter author: ";
                cin >> s;
                try {
                    lib.ShowAllBooksViaAuthtor(s);
                }
                catch (const std::exception& e) { cout << e.what() << endl; }
                catch (const string& e) { cout << e << endl; }
                catch (const char* e) { cout << e << endl; }
                catch (...) { cout << "Unknown error.\n"; }
                break;

            case 4:
                try {
                    cout << "Most frequent:\n" << lib.MostFrequenceUs() << endl;
                }
                catch (const std::exception& e) { cout << e.what() << endl; }
                catch (const string& e) { cout << e << endl; }
                catch (const char* e) { cout << e << endl; }
                catch (...) { cout << "Unknown error.\n"; }
                break;

            case 5: {
                int sub;
                cout << "1. Show books\n2. Show users\n3. Add book\n4. Add user\n0. Back\nChoose: ";
                cin >> sub;

                try {
                    switch (sub) {
                    case 1: lib.ShowAllLibrary(); break;
                    case 2: lib.ShowAllUsers(); break;
                    case 3: lib.AddBook(); break;
                    case 4: lib.AddUser(); break;
                    default: break;
                    }
                }
                catch (const std::exception& e) { cout << e.what() << endl; }
                catch (const string& e) { cout << e << endl; }
                catch (const char* e) { cout << e << endl; }
                catch (...) { cout << "Unknown error.\n"; }
                break;
            }

            case 6: {
                int sub;
                cout << "1. Lend\n2. Return\nChoose: ";
                cin >> sub;

                cout << "User id: ";
                cin >> uid;
                cout << "Book id: ";
                cin >> bid;

                try {
                    if (sub == 1) lib.LendBook(uid, bid);
                    else if (sub == 2) lib.ReturnBook(uid, bid);
                    else throw "Wrong option";
                }
                catch (const std::exception& e) { cout << e.what() << endl; }
                catch (const string& e) { cout << e << endl; }
                catch (const char* e) { cout << e << endl; }
                catch (...) { cout << "Unknown error.\n"; }
                break;
            }

            case 7:
                cout << "User id: ";
                cin >> uid;
                try {
                    lib.ShowUserViaId(uid);
                }
                catch (const std::exception& e) { cout << e.what() << endl; }
                catch (const string& e) { cout << e << endl; }
                catch (const char* e) { cout << e << endl; }
                catch (...) { cout << "Unknown error.\n"; }
                break;

            default:
                cout << "Exit.\n";
                menu = 0;
                break;
            }

        } while (menu > 0);
    }
    catch (const std::exception& e) {
        cout << "Fatal error: " << e.what() << endl;
    }
    catch (const string& e) {
        cout << "Fatal error: " << e << endl;
    }
    catch (const char* e) {
        cout << "Fatal error: " << e << endl;
    }
    catch (...) {
        cout << "Fatal error: unknown.\n";
    }

    return 0;
}
