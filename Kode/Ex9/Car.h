#pragma once

class Car
{
private:
    int freeSeats;

public:
    Car(int freeSeats) : freeSeats(freeSeats){};
    bool hasFreeSeats() const;
    void reserveFreeSeat();
};
