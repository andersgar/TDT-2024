#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include <map>
#include <fstream>

struct Config
{
    int colorUp;
    int colorDown;
    int speed;

    bool operator==(const Config &other) const
    { // Defines the == operator to check all three elements in the Config type when comparing.
        return (colorUp == other.colorUp && colorDown == other.colorDown && speed == other.speed);
    }
};

const map<int, Color> colorMap{
    {1, Color::red},
    {2, Color::green},
    {3, Color::blue},
    {4, Color::yellow}};

istream &operator>>(istream &is, Config &cfg);

pair<Config, Config> getConfigValues();
void bouncingBall();
