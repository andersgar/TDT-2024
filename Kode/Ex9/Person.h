#pragma once
#include <memory>
#include <string>
#include <iostream>
#include "Car.h"

class Person
{
private:
    std::string name;
    std::string email;
    std::unique_ptr<Car> car;

public:
    Person(std::string personName, std::string personEmail, std::unique_ptr<Car> personCar = nullptr);
    std::string getName() const;
    std::string getEmail() const;
    void setEmail(std::string newEmail);
    bool hasAvailibleSeats() const;
    friend std::ostream &operator<<(std::ostream &os, const Person &person);
};
