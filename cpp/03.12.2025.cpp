#include <iostream>
#include <vector>

struct IAnimal {
    virtual void move() = 0;
    virtual void eat() = 0;
    virtual ~IAnimal() = default; // Виртуальный деструктор обязателен
};

struct IFly {
    virtual void fly() = 0;
    virtual ~IFly() = default;
};

struct ISwim {
    virtual void swim() = 0;
    virtual ~ISwim() = default;
};

struct ICreep {
    virtual void creep() = 0;
    virtual ~ICreep() = default;
};

class Animal : public IAnimal {
public:
    virtual ~Animal() = default;
};

class Herbivore : public Animal {
public:
    void eat() override {
        std::cout << "Питается растениями." << std::endl;
    }
};

class Carnivore : public Animal {
public:
    void eat() override {
        std::cout << "Питается мясом." << std::endl;
    }
};


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


class Wolf : public Carnivore {
public:
    void move() override { std::cout << "Волк бежит рысцой." << std::endl; }
};

class Eagle : public Carnivore, public IFly {
public:
    void move() override { std::cout << "Орел перемещается по воздуху." << std::endl; }
    void fly() override { std::cout << "Орел парит высоко в небе." << std::endl; }
};

class Shark : public Carnivore, public ISwim {
public:
    void move() override { std::cout << "Акула перемещается в толще воды." << std::endl; }
    void swim() override { std::cout << "Акула быстро плывет за добычей." << std::endl; }
};

class Snake : public Carnivore, public ICreep {
public:
    void move() override { std::cout << "Змея извивается по земле." << std::endl; }
    void creep() override { std::cout << "Змея бесшумно ползет к жертве." << std::endl; }
};

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Тестирование способностей" << std::endl;
    
    IAnimal* animalSnake = new Snake();
    animalSnake->eat(); 
    animalSnake->move(); 

    std::cout << "\nТестирование" << std::endl;

    // Демонстрация работы интерфейсов
    IFly* flyingAnimal = new Eagle();
    flyingAnimal->fly();

    ISwim* swimmingAnimal = new Shark();
    swimmingAnimal->swim();

    ICreep* creepingAnimal = new Snake();
    creepingAnimal->creep();

    delete animalSnake;
    delete flyingAnimal;
    delete swimmingAnimal;
    delete creepingAnimal;

    std::cout << "\nПроект готов к сдаче!" << std::endl;

    return 0;
}