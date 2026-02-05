#include <iostream>
#include <cstring> 
using namespace std;

class MyString {
private:
    char* str;
    int length;

    static int object_count;
    static int max_length;

public:
    MyString() {
        length = 0;
        str = new char[1];
        str[0] = '\0';
        object_count++;
        if (length > max_length) max_length = length;
    }

    MyString(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy_s(str, length + 1, s);
        object_count++;
        if (length > max_length) max_length = length;
    }

    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
        object_count++;
        if (length > max_length) max_length = length;
    }

    ~MyString() {
        delete[] str;
        object_count--;
    }

    void print() const {
        cout << str << endl;
    }

    static int get_object_count() {
        return object_count;
    }

    static int get_max_length() {
        return max_length;
    }
};

int MyString::object_count = 0;
int MyString::max_length = 0;

int main() {
    MyString s1("hello");
    MyString s2 = s1;
    MyString s3("longer_example_string");

    cout << "s1: "; s1.print();
    cout << "s2: "; s2.print();
    cout << "s3: "; s3.print();

    cout << "Objects alive: " << MyString::get_object_count() << endl;
    cout << "Max string length: " << MyString::get_max_length() << endl;

    return 0;
}
