#include <iostream>
#include <vector>
#include <string>

class Herbivore {
protected:
    int weight; 
    bool life;  

public:
    Herbivore(int w) : weight(w), life(true) {}
    virtual ~Herbivore() = default;

    virtual void eatGrass() = 0; 

    int getWeight() const { return weight; }
    bool isAlive() const { return life; }
    void setLife(bool status) { life = status; }
    void addWeight(int value) { weight += value; }
};

class Wildebeest : public Herbivore {
public:
    Wildebeest() : Herbivore(100) {} 
    void eatGrass() override {
        if (life) {
            addWeight(10); // +10 к весу [cite: 14]
            std::cout << "Антилопа Гну поела травы. Вес: " << weight << "\n";
        }
    }
};

class Bison : public Herbivore {
public:
    Bison() : Herbivore(150) {}
    void eatGrass() override {
        if (life) {
            addWeight(10); // +10 к весу [cite: 18]
            std::cout << "Бизон поел травы. Вес: " << weight << "\n";
        }
    }
};

class Carnivore {
protected:
    int power; // Сила [cite: 22, 26]

public:
    Carnivore(int p) : power(p) {}
    virtual ~Carnivore() = default;

    virtual void eat(Herbivore* target) = 0;

    int getPower() const { return power; }
};

class Lion : public Carnivore {
public:
    Lion() : Carnivore(120) {} // Начальная сила льва
    void eat(Herbivore* target) override {
        if (!target->isAlive()) return;

        if (power > target->getWeight()) {
            power += 10; // Победа: +10 к силе [cite: 24]
            target->setLife(false);
            std::cout << "Лев съел добычу! Сила выросла до: " << power << "\n";
        } else {
            power -= 10; // Поражение: -10 к силе [cite: 24]
            std::cout << "Лев не справился. Сила упала до: " << power << "\n";
        }
    }
};

class Wolf : public Carnivore {
public:
    Wolf() : Carnivore(90) {} 
    void eat(Herbivore* target) override {
        if (!target->isAlive()) return;

        if (power > target->getWeight()) {
            power += 10; // [cite: 28]
            target->setLife(false);
            std::cout << "Волк съел добычу! Сила выросла до: " << power << "\n";
        } else {
            power -= 10; // [cite: 28]
            std::cout << "Волк отступил. Сила упала до: " << power << "\n";
        }
    }
};

class Continent {
public:
    virtual ~Continent() = default;
    virtual Herbivore* createHerbivore() = 0;
    virtual Carnivore* createCarnivore() = 0;
};

class Africa : public Continent {
public:
    Herbivore* createHerbivore() override { return new Wildebeest(); }
    Carnivore* createCarnivore() override { return new Lion(); }
};

class NorthAmerica : public Continent {
public:
    Herbivore* createHerbivore() override { return new Bison(); } 
    Carnivore* createCarnivore() override { return new Wolf(); }   
};

class AnimalWorld {
private:
    std::vector<Herbivore*> herbivores;
    std::vector<Carnivore*> carnivores;

public:
    AnimalWorld(Continent* factory, int count) {
        for (int i = 0; i < count; ++i) {
            herbivores.push_back(factory->createHerbivore());
            carnivores.push_back(factory->createCarnivore());
        }
    }

    ~AnimalWorld() {
        for (auto h : herbivores) delete h;
        for (auto c : carnivores) delete c;
    }

    void mealsHerbivores() {
        std::cout << "\n Травоядные вышли на пастбище \n";
        for (auto h : herbivores) h->eatGrass();
    }

    void nutritionCarnivores() {
        std::cout << "\nНачалась охота хищников\n";
        for (size_t i = 0; i < carnivores.size(); ++i) {
            carnivores[i]->eat(herbivores[i]);
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "ЭКОСИСТЕМА АФРИКИ\n";
    Continent* africa = new Africa();
    AnimalWorld world1(africa, 2);
    world1.mealsHerbivores();
    world1.nutritionCarnivores();

    std::cout << "\nЭКОСИСТЕМА СЕВЕРНОЙ АМЕРИКИ\n";
    Continent* na = new NorthAmerica();
    AnimalWorld world2(na, 2);
    world2.mealsHerbivores();
    world2.nutritionCarnivores();

    delete africa;
    delete na;

    return 0;
}