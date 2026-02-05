#include <iostream>
using namespace std;

class Geometry {
private:
    static int calc_count;

    // квадратный корень методом Ньютона
    static double my_sqrt(double x) {
        if (x <= 0) return 0;
        double guess = x / 2;
        for (int i = 0; i < 20; i++) {
            guess = (guess + x / guess) / 2;
        }
        return guess;
    }

public:
    static double triangle_area_by_base_height(double base, double height) {
        calc_count++;
        return 0.5 * base * height;
    }

    static double triangle_area_by_sides(double a, double b, double c) {
        calc_count++;
        double p = (a + b + c) / 2;
        double temp = p * (p - a) * (p - b) * (p - c);
        return my_sqrt(temp);
    }

    static double rectangle_area(double width, double height) {
        calc_count++;
        return width * height;
    }

    static double square_area(double side) {
        calc_count++;
        return side * side;
    }

    static double rhombus_area(double d1, double d2) {
        calc_count++;
        return (d1 * d2) / 2;
    }

    static int get_calc_count() {
        return calc_count;
    }
};

int Geometry::calc_count = 0;

int main() {
    cout << "Triangle (base & height): " << Geometry::triangle_area_by_base_height(10, 5) << endl;
    cout << "Triangle (3 sides): " << Geometry::triangle_area_by_sides(3, 4, 5) << endl;
    cout << "Rectangle: " << Geometry::rectangle_area(4, 6) << endl;
    cout << "Square: " << Geometry::square_area(5) << endl;
    cout << "Rhombus: " << Geometry::rhombus_area(8, 6) << endl;

    cout << "\nTotal calculations: " << Geometry::get_calc_count() << endl;
}
