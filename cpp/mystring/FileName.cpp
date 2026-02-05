#include <iostream>
#include <cstring>
using namespace std;

class MyString {
private:
    char* str;
    int length;

public:
    MyString() {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }

    MyString(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy_s(str, length + 1, s);
    }

    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
    }

    ~MyString() {
        delete[] str;
    }

    void print() const {
        cout << str;
    }

    MyString& operator=(const MyString& other) {
        if (this == &other) return *this;
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
        return *this;
    }

    MyString operator+(const MyString& other) const {
        MyString temp;
        temp.length = length + other.length;
        delete[] temp.str;
        temp.str = new char[temp.length + 1];
        strcpy_s(temp.str, length + 1, str);
        strcat_s(temp.str, temp.length + 1, other.str);
        return temp;
    }

    bool operator==(const MyString& other) const {
        return strcmp(str, other.str) == 0;
    }

    void print_to_stream(ostream& os) const {
        os << str;
    }

    void read_from_stream(istream& is) {
        char buffer[1024];
        is >> buffer;
        delete[] str;
        length = strlen(buffer);
        str = new char[length + 1];
        strcpy_s(str, length + 1, buffer);
    }
};

int main() {
    MyString s1("Hello");
    MyString s2("World");
    MyString s3;

    cout << "s1: ";
    s1.print_to_stream(cout);
    cout << endl;

    cout << "s2: ";
    s2.print_to_stream(cout);
    cout << endl;

    s3 = s1 + MyString(" ") + s2;
    cout << "s3: ";
    s3.print_to_stream(cout);
    cout << endl;

    cout << "Enter a string: ";
    MyString s4;
    s4.read_from_stream(cin);
    cout << "You entered: ";
    s4.print_to_stream(cout);
    cout << endl;

    if (s1 == MyString("Hello")) {
        cout << "s1 is Hello" << endl;
    }

    return 0;
}
