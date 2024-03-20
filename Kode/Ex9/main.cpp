#include "Person.h"
#include "Meeting.h"
#include <iostream>
#include <string>
#include <memory>

int main()
{
    //* Tests task 1 and 2:
    Car car1(1);
    Car car2(4);
    Car car3(1);
    Car car4(2);
    Person person1("Anders Garberg", "anders@garberg.no", std::make_unique<Car>(car1));
    // std::cout << person1;

    // Car car2(0);
    // Person person2("Andreas Gradberg", "andreas@gradberg.no", std::make_unique<Car>(car2));
    // std::cout << person2;

    // Person person3("Andy Gard", "andy@gard.no");
    // std::cout << person3;

    // person1.setEmail("anders@garberg.com");
    // std::cout << person1;

    //* Test task 3:
    // std::shared_ptr<Person> newLeader = std::make_shared<Person>(person1);

    std::shared_ptr<Person> leader1 = std::make_shared<Person>("Leader One", "l1@example.com", std::make_unique<Car>(car1));
    std::shared_ptr<Person> participant1 = std::make_shared<Person>("Participant One", "p1@example.com");
    std::shared_ptr<Person> participant2 = std::make_shared<Person>("Participant Two", "p2@example.com", std::make_unique<Car>(car4));

    std::shared_ptr<Person> leader2 = std::make_shared<Person>("Leader Two", "l1@example.com");
    std::shared_ptr<Person> participant3 = std::make_shared<Person>("Participant TwoOne", "p1@example.com", std::make_unique<Car>(car2));
    std::shared_ptr<Person> participant4 = std::make_shared<Person>("Participant TwoTwo", "p2@example.com");

    std::shared_ptr<Person> leader3 = std::make_shared<Person>("Leader Three", "l1@example.com");
    std::shared_ptr<Person> participant5 = std::make_shared<Person>("Participant ThreeOne", "p1@example.com", std::make_unique<Car>(car4));
    std::shared_ptr<Person> participant6 = std::make_shared<Person>("Participant ThreeTwo", "p2@example.com", std::make_unique<Car>(car3));

    Meeting meeting1(2, 1200, 1400, Campus::Trondheim, "Maths", leader1);
    meeting1.addParticipant(participant1);
    meeting1.addParticipant(participant2);

    Meeting meeting2(2, 1200, 1400, Campus::Alesund, "English", leader2);
    meeting2.addParticipant(participant3);
    meeting2.addParticipant(participant4);

    Meeting meeting3(2, 1200, 1400, Campus::Trondheim, "Physics", leader3);
    meeting3.addParticipant(participant5);
    meeting3.addParticipant(participant6);

    // std::cout << meeting1.getDay() << meeting1.getStartTime() << meeting1.getEndTime() << meeting1.getCampus() << meeting1.getSubject() << meeting1.getLeader() << std::endl;
    // std::cout << meeting1.getLeader()->getName();

    // std::vector<std::string> meeting1List = meeting1.getParcitipantList();
    // for (std::string participantInMeeting : meeting1List)
    // {
    //     std::cout << participantInMeeting << std::endl;
    // }

    std::cout << meeting1;

    std::vector<std::shared_ptr<Person>> potentialCoDrivers = meeting1.findPotentialCoDriving(meeting3);

    for (std::shared_ptr<Person> driver : potentialCoDrivers)
    {
        std::cout << driver->getName() << std::endl;
    }

    // std::vector<std::string> meeting1List = meeting1.getParcitipantList();
    // for (std::string participantInMeeting : meeting1List)
    // {
    //     std::cout << participantInMeeting << std::endl;
    // }

    return 0;
}
