#include "Person.h"
#include "Meeting.h"
#include "MeetingWindow.h"
#include <iostream>
#include <string>
#include <memory>

int main()
{
    //* Test task 4:
    MeetingWindow window(200, 200, 500, 200, "Meeting window");
    window.wait_for_close();
    window.printAllPeople();

    return 0;
}
