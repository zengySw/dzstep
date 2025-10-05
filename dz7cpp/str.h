#pragma once
#include <iostream>
#include <cstring>  
using namespace std;

class str {
private:
    char* line;
    int length;

    static int object_count;
    static int total_length;
    static int max_length;

public:
    str();                
    str(int Plength);      
    str(const str& obj);   
    str(const char* Pchar);
    str(str&& other);      
    ~str();                

    void print();
    void input();
    void Mylinecpy(str& obj);
    bool Mylineline(const char* liner);
    int MyChr(char c);
    int MylineLen();
    void MylineCat(str& b);
    void MyDelChr(char c);
    int MylineCmp(str& b);

    str& operator=(const str& other);
    str& operator=(str&& other);     

    static int get_object_count();
    static int get_total_length();
    static int get_max_length();
    static void print_stats();
};
