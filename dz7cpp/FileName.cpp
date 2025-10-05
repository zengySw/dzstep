#include <iostream>
#include "str.h"
#include <cstring>
using namespace std;

int str::obj_count = 0;

str::str() {
    length = 80;
    line = new char[length + 1];
    line[0] = '\0';
    obj_count++;
}

str::str(int p_length) {
    if (p_length < 0) {
        cout << "error length" << endl;
        length = 1;
        line = new char[1];
        line[0] = '\0';
    }
    else {
        length = p_length;
        line = new char[length + 1];
        line[0] = '\0';
    }
    obj_count++;
}

str::str(const str& obj) {
    length = strlen(obj.line);
    line = new char[length + 1];
    strcpy_s(line, length + 1, obj.line);
    obj_count++;
}

str::str(const char* p_char) {
    length = strlen(p_char);
    line = new char[length + 1];
    strcpy_s(line, length + 1, p_char);
    obj_count++;
}

str::str(str&& other) {
    line = other.line;
    length = other.length;
    other.line = nullptr;
    other.length = 0;
    obj_count++;
}

str::~str() {
    delete[] line;
    obj_count--;
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

void str::myline_cpy(str& obj) {
    delete[] line;
    length = strlen(obj.line);
    line = new char[length + 1];
    strcpy_s(line, length + 1, obj.line);
}

bool str::myline_line(const char* liner) {
    return strstr(line, liner) != nullptr;
}

int str::my_chr(char c) {
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == c)
            return i;
    }
    return -1;
}

int str::myline_len() {
    return strlen(line);
}

void str::myline_cat(str& b) {
    int new_len = strlen(line) + strlen(b.line);
    char* temp = new char[new_len + 1];
    strcpy_s(temp, new_len + 1, line);
    strcat_s(temp, new_len + 1, b.line);
    delete[] line;
    line = temp;
    length = new_len;
}

void str::my_del_chr(char c) {
    int i = 0, j = 0;
    while (line[i]) {
        if (line[i] != c) {
            line[j++] = line[i];
        }
        i++;
    }
    line[j] = '\0';
}

int str::myline_cmp(str& b) {
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

const char* str::get_line() const {
    return line;
}

int str::get_length() const {
    return length;
}

void str::set_line(const char* new_line) {
    delete[] line;
    length = strlen(new_line);
    line = new char[length + 1];
    strcpy_s(line, length + 1, new_line);
}

int str::get_obj_count() {
    return obj_count;
}

int main() {
    str s1("Hello");
    str s2(" World");

    cout << "Objects alive: " << str::get_obj_count() << endl;

    s1.myline_cat(s2);
    cout << "After concat: ";
    s1.print();

    cout << "Length: " << s1.get_length() << endl;

    s2.set_line("New string!");
    cout << "s2 updated: ";
    s2.print();

    cout << "Objects alive: " << str::get_obj_count() << endl;
}
