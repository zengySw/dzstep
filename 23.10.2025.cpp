#include<iostream>
using namespace std;

class A
{
    int a;
    double b;
public:
    A()
    {
        a = 0;
        b = 0;
    }
    A(int a1, double b1)
    {
        a = a1;
        b = b1;
    }
    int GetA()const
    {
        return a;
    }
    int GetB()const
    {
        return b;
    }
};

class B
{
    double b;
public:
    B()
    {
        b = 0;
    }
    B(double b1)
    {
        b = b1;
    }
    double GetB()const
    {
        return b;
    }
};

template<class T1, class T2>
class templatee
{
    T1 a;
    T2 b;
public:
    templatee()
    {
        a = 0;
        b = 0;
    }
    templatee(T1 a1, T2 b1)
    {
        a = a1;
        b = b1;
    }
    templatee operator +(templatee& obj2)
    {
        templatee rez(a + obj2.a, b + obj2.b);
        return rez;
    }
    void Show()
    {
        cout << "A - " << a << "B - " << b << endl;
    }
};

void main()
{
    templatee<int, double> obj1(1, 1.3);
    templatee<int, double> obj2(2, 2.3);

    templatee<int, double> obj3 = obj1 + obj2;
    obj3.Show();




    system("pause");
}