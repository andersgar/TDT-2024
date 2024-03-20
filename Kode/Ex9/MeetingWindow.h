#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include "AnimationWindow.h"
#include "Person.h"
#include <memory>
#include <string>
#pragma once

class MeetingWindow : public TDT4102::AnimationWindow
{
private:
    inline static constexpr int pad = 20;
    inline static constexpr int btnW = 150;
    inline static constexpr int btnH = 20;
    inline static constexpr int fieldH = 20;
    inline static constexpr int fieldW = 250;

    TDT4102::Button quitBtn;
    TDT4102::TextInput personName;
    TDT4102::TextInput personEmail;
    TDT4102::TextInput personSeats;
    TDT4102::Button personNewBtn;

    std::vector<std::shared_ptr<Person>> people;

public:
    MeetingWindow(int x, int y, int w, int h, const std::string &title);
    void cb_quit();
    void newPerson();
    void printAllPeople() const;
};

bool isInteger(const std::string &toBeChecked); // Used to check number input