#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class str {
private:
    char* line;
    int length;
    static int obj_count;

public:
    str();
    str(int p_length);
    str(const str& obj);
    str(const char* p_char);
    str(str&& other);
    ~str();

    void print();
    void input();
    void myline_cpy(str& obj);
    bool myline_line(const char* liner);
    int my_chr(char c);
    int myline_len();
    void myline_cat(str& b);
    void my_del_chr(char c);
    int myline_cmp(str& b);

    str& operator=(const str& other);
    str& operator=(str&& other);

    const char* get_line() const;
    int get_length() const;
    void set_line(const char* new_line);

    static int get_obj_count();
};
