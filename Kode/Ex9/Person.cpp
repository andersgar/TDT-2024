#include "Person.h"

Person::Person(std::string personName, std::string personEmail, std::unique_ptr<Car> personCar) : name(personName), email(personEmail), car(std::move(personCar)){};

std::string Person::getName() const { return name; }
std::string Person::getEmail() const { return email; }

void Person::setEmail(std::string newEmail) { email = newEmail; }

bool Person::hasAvailibleSeats() const
{
    if (car != nullptr && car->hasFreeSeats())
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::ostream &operator<<(std::ostream &os, const Person &person)
{
    os << person.name + ", " + person.email;
    if (person.car != nullptr && person.car->hasFreeSeats())
    {
        os << ", has a car with free seats availible." << std::endl;
    }
    else if (person.car != nullptr && person.car->hasFreeSeats() == false)
    {
        os << ", has a car but its full." << std::endl;
    }
    else
    {
        os << ", does not have a car" << std::endl;
    }
    return os;
}