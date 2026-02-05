#include <iostream>

using namespace std;

class calc {
private:
    string name;
    int age;
public:
    void set_name(string a) {
        name = a;
    }
    string get_name() {
        return name;
    }

    void set_age(int b) {
        age = b;
    }
    int get_age() {
        return age;
    }
};

int main() {
    cout << "enter name and age" << endl;
    string temp1;
    int temp2;
    cin >> temp1 >> temp2;

    calc obj1;
    obj1.set_name(temp1);
    obj1.set_age(temp2);

    cout << "hello, im " << obj1.get_name() << ",im " << obj1.get_age() << " years old" << endl;

    return 0;
}
