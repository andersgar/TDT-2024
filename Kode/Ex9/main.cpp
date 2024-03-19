#include "Person.h"
#include <iostream>

int main()
{
    //* Tests task 1 and 2:
    Car car1(1);
    Person person1("Anders Garberg", "anders@garberg.no", std::make_unique<Car>(car1));
    std::cout << person1;

    Car car2(0);
    Person person2("Andreas Gradberg", "andreas@gradberg.no", std::make_unique<Car>(car2));
    std::cout << person2;

    Person person3("Andy Gard", "andy@gard.no");
    std::cout << person3;

    person1.setEmail("anders@garberg.com");
    std::cout << person1;
    return 0;
}
