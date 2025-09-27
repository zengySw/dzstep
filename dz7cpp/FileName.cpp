#include <iostream>
#include "str.h"
#include <cstring>

using namespace std;

str::str() {
    length = 80;
    line = new char[length + 1];
    line[0] = '\0';
}

str::str(int Plength) {
    if (Plength < 0) {
        cout << "error length" << endl;
        length = 1;
        line = new char[1];
        line[0] = '\0';
    }
    else {
        length = Plength;
        line = new char[length + 1];
        line[0] = '\0';
    }
}

str::str(const str& obj) {
    length = strlen(obj.line);
    line = new char[length + 1];
    strcpy_s(line, length + 1, obj.line);
}

str::str(const char* Pchar) {
    length = strlen(Pchar);
    line = new char[length + 1];
    strcpy_s(line, length + 1, Pchar);
}

str::str(str&& other) {
    line = other.line;
    length = other.length;
    other.line = nullptr;
    other.length = 0;
}

str::~str() {
    delete[] line;
}

void str::print() {
    if (line)
        cout << line << endl;
    else
        cout << "(null)" << endl;
}

void str::input() {
    char temp[1024];
    cin >> temp;
    delete[] line;
    length = strlen(temp);
    line = new char[length + 1];
    strcpy_s(line, length + 1, temp);
}

void str::Mylinecpy(str& obj) {
    delete[] line;
    length = strlen(obj.line);
    line = new char[length + 1];
    strcpy_s(line, length + 1, obj.line);
}

bool str::Mylineline(const char* liner) {
    return strstr(line, liner) != nullptr;
}

int str::MyChr(char c) {
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == c)
            return i;
    }
    return -1;
}

int str::MylineLen() {
    return strlen(line);
}

void str::MylineCat(str& b) {
    int new_len = strlen(line) + strlen(b.line);
    char* temp = new char[new_len + 1];
    strcpy_s(temp, new_len + 1, line);
    strcat_s(temp, new_len + 1, b.line);
    delete[] line;
    line = temp;
    length = new_len;
}

void str::MyDelChr(char c) {
    int i = 0, j = 0;
    while (line[i]) {
        if (line[i] != c) {
            line[j++] = line[i];
        }
        i++;
    }
    line[j] = '\0';
}

int str::MylineCmp(str& b) {
    return strcmp(line, b.line);
}

str& str::operator=(const str& other) {
    if (this == &other) return *this;
    delete[] line;
    length = strlen(other.line);
    line = new char[length + 1];
    strcpy_s(line, length + 1, other.line);
    return *this;
}

str& str::operator=(str&& other) {
    if (this == &other) return *this;
    delete[] line;
    line = other.line;
    length = other.length;
    other.line = nullptr;
    other.length = 0;
    return *this;
}



int main() {
    str s1("Hello");
    str s2(" World");

    cout << "s1: ";
    s1.print();

    cout << "s2: ";
    s2.print();

    s1.MylineCat(s2);

    cout << "After concatenation: ";
    s1.print();

    cout << "Length: " << s1.MylineLen() << endl;
}