#include <vector>
#include <cstdlib>
#include "string"

class Animal {
protected:
    int calories = 500;
public:
    std::string name = "animal";
    bool dead = false;
    int age = 0;

    Animal(std::string name) {
        this->name = name;
    }

    Animal(std::string name, int age) {
        this->name = name;
        this->age = age;
    }

    void feed(int food_calories) {
        this->calories += food_calories;
    };

    void grow() {
        this->calories -= 100;
        this->age++;
        if (age > 50) {
            die();
        }
    }

    void die() {
        this->dead = true;
        this->calories = 0;
    }

    bool operator==(Animal &animal) const {
        return name == animal.name && calories == animal.calories && dead == animal.dead && age == animal.age;
    }
};

class Mammal : public Animal {
public:
    Mammal(std::string name) : Animal(name) {}

    Mammal(std::string name, int age) : Animal(name, age) {}

    void milk() {
        calories -= 200;
    }
};

class Bird : public Animal {
public:
    Bird(std::string name) : Animal(name) {}

    Bird(std::string name, int age) : Animal(name, age) {}

    void lay_eggs() {
        for (int eggs_count = 0; eggs_count < rand() % 5 + 1; eggs_count++) {
            this->calories -= 100;
        }
    }
};

class Cage {
public:
    std::string animal_name;
    std::vector<Animal *> animals;

    Cage(std::string animal_name) {
        this->animal_name = animal_name;
    }

    void add_animal(Animal *animal) {
        this->animals.push_back(animal);
    }

    void remove_animal(Animal *animal_to_remove) {
        for (int i = 0; i < this->animals.size(); i++) {
            if (*this->animals[i] == *animal_to_remove) {
                this->animals.erase(this->animals.begin() + i);
                break;
            }
        }
    }

    void feed(int food_calorie) {
        for (Animal *animal: this->animals) {
            animal->feed(food_calorie / animals.size());
        }
    }

    void update() {
        for (Animal *animal: this->animals) {
            animal->grow();
        }
    }
};

class Zoo {
public:
    std::vector<Cage *> cages;

    Cage *new_cage(std::string cage_name) {
        Cage *cage = new Cage(cage_name);
        this->cages.push_back(cage);
        return cages[cages.size() - 1];
    }

    void feed_cage(int cageNum) {
        this->cages[cageNum]->feed(1000);
    }

    void feed_cages() {
        for (Cage *cage: this->cages) {
            cage->feed(cage->animals.size() * 200);
        }
    }

    void remove_dead() {
        for (Cage *cage: this->cages){
            for (Animal *animal : cage->animals){
                if (animal->dead){
                    cage->remove_animal(animal);
                }
            }
        }
    }

    void update_cages() {
        for (Cage *cage: this->cages) {
            cage->update();
        }
    }
};