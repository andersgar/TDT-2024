#include "Cafeteria.h"

Cafeteria::Cafeteria(string n, Location l) : name{n}, location{l}
{
    for (auto p : mainDishPrices)
    {
        stock.insert({p.first, 0});
    }
    for (auto p : sideDishPrices)
    {
        stock.insert({p.first, 0});
    }
}

vector<DailyMenu> Cafeteria::getWeeklyMenu()
{
    return weeklyMenu;
}

void Cafeteria::setWeeklyMenu(vector<DailyMenu> menu)
{
    weeklyMenu = menu;
}

int Cafeteria::getStock(string item)
{
    return stock.at(item);
}

void Cafeteria::setStock(string item, int amount)
{
    stock.at(item) = amount;
}

void Cafeteria::removeStock(string item)
{
    stock.at(item)--;
}

//------------------------------------------------------------------------------------------------

DailyMenu Cafeteria::getDailyMenu(Weekday w)
{
    // BEGIN: 1c

    DailyMenu dailyMenu = Cafeteria::weeklyMenu.at(static_cast<int>(w));
    return dailyMenu;

    // END: 1c
}

bool Cafeteria::isInStock(DailyMenu menu)
{
    // BEGIN: 1d
    ifstream stockInput{"stock.txt"};
    if (!stockInput)
    {
        cout << "Could not open stock-file," << endl;
        return false;
    }
    string line;
    while (getline(stockInput, line))
    {
        stringstream ss(line);
        string mealName, mealCount;
        getline(ss, mealName, ',');
        getline(ss, mealCount);
        if (menu.mainDish == mealName && mealCount == " 0")
        {
            return false;
        }
        if (menu.sideDish == mealName && mealCount == " 0")
        {
            return false;
        }
    }
    return true;

    // END: 1d
}

void Cafeteria::saveToFile(string fileName)
{
    // BEGIN: 1e
    ofstream saveLocation{fileName};
    auto menu = getWeeklyMenu();
    for (auto line : menu)
    {
        saveLocation << line;
    }

    // END: 1e
}

void Cafeteria::importStock(string fileName)
{
    // BEGIN: 2a
    ifstream stockInput{fileName};
    if (!stockInput)
    {
        cout << "Could not open stock-file," << endl;
        return;
    }
    string line;
    while (getline(stockInput, line))
    {
        stringstream ss(line);
        string mealName, mealCount;
        getline(ss, mealName, ',');
        getline(ss, mealCount);
        int mealCountInt = pow(stoi(mealCount), 2);
        stock[mealName] = mealCountInt;
    }
    // END: 2a
}

vector<DailyMenu> generateWeeklyMenu()
{
    // BEGIN: 2c
    vector<DailyMenu> wm;
    for (int i = 0; i < 7; i++)
    {
        DailyMenu dm = getRandomMenu();
        wm.emplace_back(dm);
    }

    return wm;

    // END: 2c
}