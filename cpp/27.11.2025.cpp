#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>

class Figure
{
protected:
    double m_value1 = 0.0;
    double m_value2 = 0.0;

public:
    virtual ~Figure() = default;

    virtual void SetDimension(double v1, double v2 = 0.0) = 0;
    virtual void ShowArea() const = 0;

    virtual void ShowLength() const = 0;
    virtual void Init() = 0;
    virtual void Print() const = 0;
};

static double read_positive(const std::string &prompt)
{
    double val;
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> val && val > 0.0)
            break;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "  Введите положительное число.\n";
    }
    return val;
}

class Circle : public Figure
{
public:
    // SetDimension: v1 = радиус
    void SetDimension(double v1, double /*v2*/) override
    {
        m_value1 = v1;
    }

    void Init() override
    {
        std::cout << "=== Окружность ===\n";
        m_value1 = read_positive("  Радиус: ");
    }

    void ShowArea() const override
    {
        std::cout << std::fixed << std::setprecision(4)
                  << "Площадь круга   : " << M_PI * m_value1 * m_value1 << "\n";
    }

    void ShowLength() const override
    {
        std::cout << std::fixed << std::setprecision(4)
                  << "Длина окружности: " << 2.0 * M_PI * m_value1 << "\n";
    }

    void Print() const override
    {
        std::cout << "Фигура          : Окружность\n"
                  << "Радиус          : " << m_value1 << "\n";
        ShowLength();
        ShowArea();
    }
};

class Rectangle : public Figure
{
public:
    void SetDimension(double v1, double v2) override
    {
        m_value1 = v1;
        m_value2 = v2;
    }

    void Init() override
    {
        std::cout << "=== Прямоугольник ===\n";
        m_value1 = read_positive("  Ширина : ");
        m_value2 = read_positive("  Высота : ");
    }

    void ShowArea() const override
    {
        std::cout << std::fixed << std::setprecision(4)
                  << "Площадь         : " << m_value1 * m_value2 << "\n";
    }

    void ShowLength() const override
    {
        std::cout << std::fixed << std::setprecision(4)
                  << "Периметр        : " << 2.0 * (m_value1 + m_value2) << "\n";
    }

    void Print() const override
    {
        std::cout << "Фигура          : Прямоугольник\n"
                  << "Ширина          : " << m_value1 << "\n"
                  << "Высота          : " << m_value2 << "\n";
        ShowLength();
        ShowArea();
    }
};

class Triangle : public Figure
{
public:
    void SetDimension(double v1, double /*v2*/) override
    {
        m_value1 = v1;
    }

    void Init() override
    {
        std::cout << "=== Равносторонний треугольник ===\n";
        m_value1 = read_positive("  Сторона: ");
    }

    void ShowArea() const override
    {
        double area = (std::sqrt(3.0) / 4.0) * m_value1 * m_value1;
        std::cout << std::fixed << std::setprecision(4)
                  << "Площадь         : " << area << "\n";
    }

    void ShowLength() const override
    {
        std::cout << std::fixed << std::setprecision(4)
                  << "Периметр        : " << 3.0 * m_value1 << "\n";
    }

    void Print() const override
    {
        std::cout << "Фигура          : Равносторонний треугольник\n"
                  << "Сторона         : " << m_value1 << "\n";
        ShowLength();
        ShowArea();
    }
};

class Parallelogram : public Figure
{
public:
    void SetDimension(double v1, double v2) override
    {
        m_value1 = v1;
        m_value2 = v2;
    }

    void Init() override
    {
        std::cout << "=== Параллелограмм (угол 60°) ===\n";
        m_value1 = read_positive("  Основание: ");
        m_value2 = read_positive("  Высота   : ");
    }

    void ShowArea() const override
    {
        std::cout << std::fixed << std::setprecision(4)
                  << "Площадь         : " << m_value1 * m_value2 << "\n";
    }

    void ShowLength() const override
    {
        // боковая сторона = высота / sin(60°)
        double side = m_value2 / std::sin(M_PI / 3.0);
        std::cout << std::fixed << std::setprecision(4)
                  << "Периметр        : " << 2.0 * (m_value1 + side) << "\n";
    }

    void Print() const override
    {
        std::cout << "Фигура          : Параллелограмм\n"
                  << "Основание       : " << m_value1 << "\n"
                  << "Высота          : " << m_value2 << "\n";
        ShowLength();
        ShowArea();
    }
};

class Rhombus : public Figure
{
public:
    void SetDimension(double v1, double v2) override
    {
        m_value1 = v1;
        m_value2 = v2;
    }

    void Init() override
    {
        std::cout << "Ромб\n";
        m_value1 = read_positive("  Диагональ d1: ");
        m_value2 = read_positive("  Диагональ d2: ");
    }

    void ShowArea() const override
    {
        std::cout << std::fixed << std::setprecision(4)
                  << "Площадь         : " << (m_value1 * m_value2) / 2.0 << "\n";
    }

    void ShowLength() const override
    {
        double side = std::sqrt(
            (m_value1 / 2.0) * (m_value1 / 2.0) +
            (m_value2 / 2.0) * (m_value2 / 2.0));
        std::cout << std::fixed << std::setprecision(4)
                  << "Периметр        : " << 4.0 * side << "\n";
    }

    void Print() const override
    {
        std::cout << "Фигура          : Ромб\n"
                  << "Диагональ d1    : " << m_value1 << "\n"
                  << "Диагональ d2    : " << m_value2 << "\n";
        ShowLength();
        ShowArea();
    }
};

class Square : public Figure
{
public:
    void SetDimension(double v1, double /*v2*/) override
    {
        m_value1 = v1;
    }

    void Init() override
    {
        std::cout << "=== Квадрат ===\n";
        m_value1 = read_positive("  Сторона: ");
    }

    void ShowArea() const override
    {
        std::cout << std::fixed << std::setprecision(4)
                  << "Площадь         : " << m_value1 * m_value1 << "\n";
    }

    void ShowLength() const override
    {
        std::cout << std::fixed << std::setprecision(4)
                  << "Периметр        : " << 4.0 * m_value1 << "\n";
    }

    void Print() const override
    {
        std::cout << "Фигура          : Квадрат\n"
                  << "Сторона         : " << m_value1 << "\n";
        ShowLength();
        ShowArea();
    }
};

static void demo_polymorphism()
{
    std::cout << "  Демо: полиморфный вывод через Figure*\n";
    std::vector<std::unique_ptr<Figure>> shapes;

    auto c = std::make_unique<Circle>();
    c->SetDimension(5.0, 0.0);
    shapes.push_back(std::move(c));

    auto r = std::make_unique<Rectangle>();
    r->SetDimension(4.0, 6.0);
    shapes.push_back(std::move(r));

    auto t = std::make_unique<Triangle>();
    t->SetDimension(7.0, 0.0);
    shapes.push_back(std::move(t));

    auto p = std::make_unique<Parallelogram>();
    p->SetDimension(8.0, 4.0);
    shapes.push_back(std::move(p));

    auto rh = std::make_unique<Rhombus>();
    rh->SetDimension(6.0, 8.0);
    shapes.push_back(std::move(rh));

    auto sq = std::make_unique<Square>();
    sq->SetDimension(5.0, 0.0);
    shapes.push_back(std::move(sq));

    for (const auto &fig : shapes)
    {
        fig->Print(); // виртуальный вызов — конкретный Print()
        std::cout << "---\n";
    }
}
int main()
{
    demo_polymorphism();

    std::cout << "  Создать фигуру вручную?\n"
              << "  1. Окружность     4. Параллелограмм\n"
              << "  2. Прямоугольник  5. Ромб\n"
              << "  3. Треугольник    6. Квадрат\n"
              << "  0. Выход\n";

    int choice;
    while (std::cout << "Выбор: ", std::cin >> choice, choice != 0)
    {
        std::unique_ptr<Figure> fig;
        switch (choice)
        {
        case 1:
            fig = std::make_unique<Circle>();
            break;
        case 2:
            fig = std::make_unique<Rectangle>();
            break;
        case 3:
            fig = std::make_unique<Triangle>();
            break;
        case 4:
            fig = std::make_unique<Parallelogram>();
            break;
        case 5:
            fig = std::make_unique<Rhombus>();
            break;
        case 6:
            fig = std::make_unique<Square>();
            break;
        default:
            std::cout << "Неверный пункт.\n";
            continue;
        }
        fig->Init();
        std::cout << "\n";
        fig->Print();
        std::cout << "\n";
    }

    std::cout << "До свидания!\n";
    return 0;
}