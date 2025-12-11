#include <iostream>
#include <string>
#include <vector>
using namespace std;

class point
{
protected:
    int x;
    int y;
public:
    point() : x(0), y(0) {}

    point(int initial_x, int initial_y) : x(initial_x), y(initial_y) {}
    void print() const {
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    vector<point> a;

    point p1(10, 20);

    a.push_back(p1);

    a.push_back(point());
    a.push_back(point(67, 62));
    a.push_back(point());
    a.push_back(point(3,4));

    cout << "vector:" << endl;
    for (const auto& p : a) {
        p.print();
        cout << "---" << endl;
    }
}
