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
        cout << str << endl;
    }
};

int main() {
    MyString s1("hallo");
    MyString s2 = s1;

    cout << "s1: "; s1.print();
    cout << "s2: "; s2.print();

    return 0;
}
