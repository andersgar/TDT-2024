#include "MeetingWindow.h"

MeetingWindow::MeetingWindow(int x, int y, int w, int h, const std::string &title)
    : AnimationWindow(x, y, w, h, title),
      quitBtn({w - pad - btnW, h - btnH - pad}, btnW, btnH, "Quit"),
      personName{{pad, pad}, fieldW, fieldH, "Name"},
      personEmail({pad, 3 * pad + fieldH}, fieldW, fieldH, "Email"),
      personSeats({pad, 5 * pad + 2 * fieldH}, fieldW, fieldH, "Number of seats (incl driver)"),
      personNewBtn({w - pad - btnW, pad}, btnW, btnH, "Add person")
{
    add(quitBtn);
    quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit, this));

    add(personName);
    add(personEmail);
    add(personSeats);
    add(personNewBtn);
    personNewBtn.setCallback(std::bind(&MeetingWindow::newPerson, this));
};

void MeetingWindow::cb_quit() { close(); }

void MeetingWindow::newPerson()
{
    if (personName.getText() != "" && personEmail.getText() != "")
    {
        if (isInteger(personSeats.getText())) // Checks if input string is an int
        {
            people.emplace_back(
                new Person(
                    personName.getText(),
                    personEmail.getText(),
                    std::make_unique<Car>(
                        stoi(
                            personSeats.getText()) -
                        1))); // Reserves one seat for the driver
        }
        else
        {
            people.emplace_back(
                new Person(
                    personName.getText(),
                    personEmail.getText()));
        }
    }

    personName.setText("Name");
    personEmail.setText("Email");
    personSeats.setText("Number of seats (incl. driver)");
}

void MeetingWindow::printAllPeople() const
{
    for (auto person : people)
    {
        std::cout << *person << std::endl;
    }
}

bool isInteger(const std::string &toBeChecked) // Used to check number of seats input
{
    try
    {
        std::stoi(toBeChecked);
        return true;
    }
    catch (...)
    {
        return false;
    }
}