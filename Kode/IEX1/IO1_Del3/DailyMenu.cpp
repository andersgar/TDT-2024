#include "DailyMenu.h"

const map<string, double> mainDishPrices{
    // Main dishes
    {"Burger", 55},
    {"Lasagna", 70},
    {"Chicken", 60},
    {"Porkchops", 65},
    {"Beef", 90},
    {"Soup", 50},
    {"Cinnamon bun", 25},
    {"Baguette", 54},
};

const map<string, double> sideDishPrices{
    {"Salad", 40},
    {"Fries", 30},
    {"Rice", 20},
    {"Mashed potatoes", 25},
    {"Pasta", 35},
    {"Caviar", 150},
    {"Couscous", 50},
    {"Root vegetables", 35}};

const map<string, double> adjectivePriceModifiers{
    {"Vegan", 1.4},
    {"Vegetarian", 1.2},
    {"Gluten-free", 2.5},
    {"Lactose-free", 1.3},
    {"Sugar-free", 1.1},
    {"Whole grain", 1.2},
    {"Organic", 1.4},
    {"Local", 1.6}

};

//------------------------------------------------------------------------------------------------

DailyMenu createDailyMenu(string adjective, string mainDish, string sideDish)
{
    // BEGIN: 1a
    double price = adjectivePriceModifiers.at(adjective) * (mainDishPrices.at(mainDish) + sideDishPrices.at(sideDish));
    DailyMenu newDailyDish = {adjective, mainDish, sideDish, price};
    return newDailyDish;
    // END: 1a
}
ostream &operator<<(ostream &os, DailyMenu d)
{

    // BEGIN: 1b
    os << d.adjective << " " << d.mainDish << " with " << d.sideDish << " for only " << d.price << "kr!";
    return os;
    // END: 1b
}

string getDishFromNumber(map<string, double> m, int n)
{
    int i = 0;
    for (const auto &dish : m)
    {
        if (i == n)
        {
            return dish.first;
        }
        i++;
    }

    return "";
}

DailyMenu getRandomMenu()
{
    int mapSize = 8;
    // BEGIN: 2b
    DailyMenu rm;

    random_device rd;
    default_random_engine gen(rd());
    uniform_int_distribution<int> dist(0, mapSize - 1);

    rm.adjective = getDishFromNumber(adjectivePriceModifiers, dist(gen));
    rm.mainDish = getDishFromNumber(mainDishPrices, dist(gen));
    rm.sideDish = getDishFromNumber(sideDishPrices, dist(gen));
    rm.price = adjectivePriceModifiers.at(rm.adjective) * (mainDishPrices.at(rm.mainDish) + sideDishPrices.at(rm.sideDish));

    return rm;
    // END: 2b
}