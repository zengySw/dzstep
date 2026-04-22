#include <iostream>

// 1. Базовый абстрактный класс Animal
class Animal {
public:
    // Чисто виртуальные методы (как указано в задании)
    virtual void move() = 0;
    virtual void eat() = 0;

    // Виртуальный деструктор для безопасного освобождения памяти
    virtual ~Animal() = default;
};

// 2. Промежуточный класс "Травоядные" (Herbivore)
class Herbivore : public Animal {
public:
    // Реализуем метод eat() для всех травоядных
    void eat() override {
        std::cout << "Питается растениями." << std::endl;
    }
    // Метод move() не реализуем, оставляя класс абстрактным, 
    // так как каждое животное двигается по-своему
};

// 3. Промежуточный класс "Плотоядные" (Carnivore)
class Carnivore : public Animal {
public:
    // Реализуем метод eat() для всех плотоядных
    void eat() override {
        std::cout << "Питается мясом." << std::endl;
    }
};

// --- Конкретные классы Травоядных ---

class Elephant : public Herbivore {
public:
    void move() override { std::cout << "Слон тяжело шагает." << std::endl; }
};

class Rabbit : public Herbivore {
public:
    void move() override { std::cout << "Кролик прыгает." << std::endl; }
};

class Giraffe : public Herbivore {
public:
    void move() override { std::cout << "Жираф грациозно идет." << std::endl; }
};

// --- Конкретные классы Плотоядных ---

class Wolf : public Carnivore {
public:
    void move() override { std::cout << "Волк бежит рысцой." << std::endl; }
};

class Eagle : public Carnivore {
public:
    void move() override { std::cout << "Орел летит." << std::endl; }
    
    // Дополнительный метод для орла (fly), указанный на вашей схеме
    void fly() { std::cout << "Орел парит высоко в небе." << std::endl; }
};

class Shark : public Carnivore {
public:
    void move() override { std::cout << "Акула быстро плывет." << std::endl; }
};

// --- Главная функция ---

int main() {
    setlocale(LC_ALL, "Russian");

    // Выполнение условия: 
    // "через указатель 'травоядные' - создать травоядных животных"
    Herbivore* elephant = new Elephant();
    Herbivore* rabbit = new Rabbit();
    Herbivore* giraffe = new Giraffe();

    // Выполнение условия:
    // "через указатель 'плотоядные' - создать плотоядных животных"
    Carnivore* wolf = new Wolf();
    Carnivore* eagle = new Eagle();
    Carnivore* shark = new Shark();

    // Демонстрация работы полиморфизма
    std::cout << "--- Демонстрация травоядных ---" << std::endl;
    elephant->move(); 
    elephant->eat(); // Вызовет метод из класса Herbivore

    std::cout << "\n--- Демонстрация плотоядных ---" << std::endl;
    eagle->move();
    eagle->eat(); // Вызовет метод из класса Carnivore
    
    // Примечание: Чтобы вызвать уникальный метод fly() через базовый указатель, 
    // потребуется приведение типов (Downcasting):
    // static_cast<Eagle*>(eagle)->fly();

    // Очистка выделенной памяти
    delete elephant;
    delete rabbit;
    delete giraffe;
    delete wolf;
    delete eagle;
    delete shark;

    return 0;
}