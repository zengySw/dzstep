#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>
#include <map>

class Transport
{
protected:
    std::string name_;
    int speed_kmh_; // максимальная скорость
    int capacity_;  // пассажировместимость

public:
    Transport(const std::string &name, int speed, int capacity)
        : name_(name), speed_kmh_(speed), capacity_(capacity) {}

    virtual ~Transport() = default;

    virtual void move() const { std::cout << name_ << " движется.\n"; }
    virtual void stop() const { std::cout << name_ << " останавливается.\n"; }
    virtual void refuel() const { std::cout << name_ << " заправляется.\n"; }
    virtual void info() const
    {
        std::cout << "Транспорт  : " << name_ << "\n"
                  << "Тип        : " << type() << "\n"
                  << "Скорость   : " << speed_kmh_ << " км/ч\n"
                  << "Вместимость: " << capacity_ << " чел.\n";
    }

    virtual std::string type() const = 0;

    const std::string &get_name() const { return name_; }
    int get_speed() const { return speed_kmh_; }
    int get_capacity() const { return capacity_; }
};

class Ground : public Transport
{
public:
    using Transport::Transport;

    void move() const override { std::cout << name_ << " едет по дороге.\n"; }
    void refuel() const override { std::cout << name_ << " заправляется на АЗС.\n"; }
    std::string type() const override { return "Наземный"; }
};

class Water : public Transport
{
public:
    using Transport::Transport;

    void move() const override { std::cout << name_ << " плывёт по воде.\n"; }
    void stop() const override { std::cout << name_ << " бросает якорь.\n"; }
    void refuel() const override { std::cout << name_ << " бункеруется в порту.\n"; }
    std::string type() const override { return "Водный"; }
};

class Air : public Transport
{
public:
    using Transport::Transport;

    void move() const override { std::cout << name_ << " летит в небе.\n"; }
    void stop() const override { std::cout << name_ << " совершает посадку.\n"; }
    void refuel() const override { std::cout << name_ << " заправляется в аэропорту.\n"; }
    std::string type() const override { return "Воздушный"; }
};

class Car : public Ground
{
public:
    Car(const std::string &name, int speed, int capacity)
        : Ground(name, speed, capacity) {}

    void move() const override
    {
        std::cout << name_ << " едет по автодороге со скоростью "
                  << speed_kmh_ << " км/ч.\n";
    }
    std::string type() const override { return "Автомобиль"; }
};

class Train : public Ground
{
    int wagon_count_;

public:
    Train(const std::string &name, int speed, int capacity, int wagons)
        : Ground(name, speed, capacity), wagon_count_(wagons) {}

    void move() const override
    {
        std::cout << name_ << " мчится по рельсам (" << wagon_count_ << " вагонов).\n";
    }
    void info() const override
    {
        Ground::info();
        std::cout << "Вагонов    : " << wagon_count_ << "\n";
    }
    std::string type() const override { return "Железнодорожный"; }
};

class Horse : public Ground
{
public:
    Horse(const std::string &name, int speed, int capacity)
        : Ground(name, speed, capacity) {}

    void move() const override { std::cout << name_ << " тащится по просёлку.\n"; }
    void refuel() const override { std::cout << name_ << " жуёт сено.\n"; }
    std::string type() const override { return "Гужевой"; }
};

class Tanker : public Water
{
    int tonnage_;

public:
    Tanker(const std::string &name, int speed, int capacity, int tonnage)
        : Water(name, speed, capacity), tonnage_(tonnage) {}

    void info() const override
    {
        Water::info();
        std::cout << "Дедвейт    : " << tonnage_ << " тонн\n";
    }
    std::string type() const override { return "Танкер"; }
};

class Boat : public Water
{
public:
    using Water::Water;
    std::string type() const override { return "Лодка"; }
};

class Steamship : public Water
{
public:
    Steamship(const std::string &name, int speed, int capacity)
        : Water(name, speed, capacity) {}

    void move() const override
    {
        std::cout << name_ << " идёт по курсу, гудок: «ТУТУ!»\n";
    }
    std::string type() const override { return "Теплоход"; }
};

class Airplane : public Air
{
    int engine_count_;

public:
    Airplane(const std::string &name, int speed, int capacity, int engines)
        : Air(name, speed, capacity), engine_count_(engines) {}

    void move() const override
    {
        std::cout << name_ << " набирает высоту на " << engine_count_
                  << " двигателях.\n";
    }
    void info() const override
    {
        Air::info();
        std::cout << "Двигателей : " << engine_count_ << "\n";
    }
    std::string type() const override { return "Самолёт"; }
};

class Helicopter : public Air
{
public:
    using Air::Air;

    void move() const override
    {
        std::cout << name_ << " зависает над землёй и летит вперёд.\n";
    }
    std::string type() const override { return "Вертолёт"; }
};

class Airship : public Air
{
public:
    Airship(const std::string &name, int speed, int capacity)
        : Air(name, speed, capacity) {}

    void move() const override
    {
        std::cout << name_ << " медленно дрейфует в небе.\n";
    }
    std::string type() const override { return "Дирижабль"; }
};

using TransportPtr = std::unique_ptr<Transport>;
using FactoryFunction = TransportPtr (*)();

std::map<std::string, FactoryFunction> g_registry;

int read_int(const std::string &prompt, int min_val = 0, int max_val = 100000)
{
    int val;
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> val && val >= min_val && val <= max_val)
            break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  Введите целое число в диапазоне ["
                  << min_val << ".." << max_val << "]\n";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return val;
}

std::string read_line(const std::string &prompt)
{
    std::string s;
    std::cout << prompt;
    std::getline(std::cin, s);
    return s.empty() ? "Без названия" : s;
}

TransportPtr make_car()
{
    auto name = read_line("  Название автомобиля: ");
    auto speed = read_int("  Макс. скорость (км/ч): ", 1, 500);
    auto capacity = read_int("  Вместимость (чел.): ", 1, 100);
    return std::make_unique<Car>(name, speed, capacity);
}

TransportPtr make_train()
{
    auto name = read_line("  Название поезда: ");
    auto speed = read_int("  Макс. скорость (км/ч): ", 1, 600);
    auto capacity = read_int("  Вместимость (чел.): ", 1, 10000);
    auto wagons = read_int("  Количество вагонов: ", 1, 200);
    return std::make_unique<Train>(name, speed, capacity, wagons);
}

TransportPtr make_horse()
{
    auto name = read_line("  Название повозки: ");
    auto speed = read_int("  Макс. скорость (км/ч): ", 1, 50);
    auto capacity = read_int("  Вместимость (чел.): ", 1, 20);
    return std::make_unique<Horse>(name, speed, capacity);
}

TransportPtr make_tanker()
{
    auto name = read_line("  Название танкера: ");
    auto speed = read_int("  Макс. скорость (км/ч): ", 1, 100);
    auto capacity = read_int("  Экипаж (чел.): ", 1, 500);
    auto tonnage = read_int("  Дедвейт (тонн): ", 1, 500000);
    return std::make_unique<Tanker>(name, speed, capacity, tonnage);
}

TransportPtr make_boat()
{
    auto name = read_line("  Название лодки: ");
    auto speed = read_int("  Макс. скорость (км/ч): ", 1, 100);
    auto capacity = read_int("  Вместимость (чел.): ", 1, 50);
    return std::make_unique<Boat>(name, speed, capacity);
}

TransportPtr make_steamship()
{
    auto name = read_line("  Название теплохода: ");
    auto speed = read_int("  Макс. скорость (км/ч): ", 1, 60);
    auto capacity = read_int("  Вместимость (чел.): ", 1, 5000);
    return std::make_unique<Steamship>(name, speed, capacity);
}

TransportPtr make_airplane()
{
    auto name = read_line("  Название самолёта: ");
    auto speed = read_int("  Макс. скорость (км/ч): ", 1, 4000);
    auto capacity = read_int("  Вместимость (чел.): ", 1, 1000);
    auto engines = read_int("  Количество двигателей: ", 1, 10);
    return std::make_unique<Airplane>(name, speed, capacity, engines);
}

TransportPtr make_helicopter()
{
    auto name = read_line("  Название вертолёта: ");
    auto speed = read_int("  Макс. скорость (км/ч): ", 1, 400);
    auto capacity = read_int("  Вместимость (чел.): ", 1, 80);
    return std::make_unique<Helicopter>(name, speed, capacity);
}

TransportPtr make_airship()
{
    auto name = read_line("  Название дирижабля: ");
    auto speed = read_int("  Макс. скорость (км/ч): ", 1, 150);
    auto capacity = read_int("  Вместимость (чел.): ", 1, 200);
    return std::make_unique<Airship>(name, speed, capacity);
}

void register_factories()
{
    g_registry["авто"] = make_car;
    g_registry["поезд"] = make_train;
    g_registry["жд"] = make_train;
    g_registry["гужевой"] = make_horse;
    g_registry["танкер"] = make_tanker;
    g_registry["лодка"] = make_boat;
    g_registry["теплоход"] = make_steamship;
    g_registry["самолёт"] = make_airplane;
    g_registry["самолет"] = make_airplane;
    g_registry["вертолёт"] = make_helicopter;
    g_registry["вертолет"] = make_helicopter;
    g_registry["дирижабль"] = make_airship;
}

void print_menu()
{
    std::cout << "  1. Создать транспортное средство     \n"
              << "  2. Показать все объекты              \n"
              << "  3. Команда объекту (move/stop/fuel)  \n"
              << "  0. Выход                             \n"
              << "Выбор: ";
}

void print_types()
{
    std::cout << "\nДоступные типы транспорта:\n"
              << "  Наземный : авто, поезд (жд), гужевой\n"
              << "  Водный   : танкер, лодка, теплоход\n"
              << "  Воздушный: самолёт, вертолёт, дирижабль\n";
}

int main()
{
    register_factories();

    std::vector<TransportPtr> fleet; // Парк техники
    int choice = -1;

    while (choice != 0)
    {
        print_menu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
        {
            print_types();
            std::string key;
            std::cout << "Введите тип: ";
            std::getline(std::cin, key);

            for (auto &ch : key)
                ch = static_cast<char>(std::tolower(
                    static_cast<unsigned char>(ch)));

            auto it = g_registry.find(key);
            if (it == g_registry.end())
            {
                std::cout << "Неизвестный тип. Повторите.\n";
                break;
            }
            auto obj = it->second(); // вызов фабрики — тип неизвестен здесь!
            std::cout << "\nСоздан объект: " << obj->get_name()
                      << " (" << obj->type() << ")\n";
            fleet.push_back(std::move(obj));
            break;
        }
        case 2:
        {
            if (fleet.empty())
            {
                std::cout << "Парк пуст.\n";
                break;
            }
            std::cout << "\nВсе транспортные средства\n";
            for (size_t i = 0; i < fleet.size(); ++i)
            {
                std::cout << "\n[" << i << "] ";
                fleet[i]->info();
            }
            break;
        }
        case 3:
        {
            if (fleet.empty())
            {
                std::cout << "Парк пуст.\n";
                break;
            }
            int idx = read_int("Номер объекта [0.." +
                                   std::to_string(fleet.size() - 1) + "]: ",
                               0, static_cast<int>(fleet.size() - 1));
            std::cout << "Команда (move / stop / fuel): ";
            std::string cmd;
            std::getline(std::cin, cmd);
            if (cmd == "move")
                fleet[idx]->move();
            else if (cmd == "stop")
                fleet[idx]->stop();
            else if (cmd == "fuel")
                fleet[idx]->refuel();
            else
                std::cout << "Неизвестная команда.\n";
            break;
        }
        case 0:
            std::cout << "До свидания!\n";
            break;
        default:
            std::cout << "Неверный пункт меню.\n";
        }
    }
    return 0;
}