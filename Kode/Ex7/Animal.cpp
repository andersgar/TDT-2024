#include "Animal.h"

string Animal::toString()
{
    return "Animal: " + name + ", " + to_string(age);
};

string Cat::toString()
{
    return "Cat: " + name + ", " + to_string(age);
};

string Dog::toString()
{
    return "Dog: " + name + ", " + to_string(age);
};

void testAnimal()
{
    vector<unique_ptr<Animal>> animals;

    animals.emplace_back(new Cat("Nils", 5));
    animals.emplace_back(new Dog("Stian", 7));
    animals.emplace_back(new Animal("Freddy", 2));
    animals.emplace_back(new Dog("Cris", 1));
    animals.emplace_back(new Animal("Claus", 5));

    for (const auto &currentAnimal : animals)
    {
        cout << currentAnimal->toString() << endl;
    }
};