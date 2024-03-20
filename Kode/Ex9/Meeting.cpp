#include "Meeting.h"

std::ostream &operator<<(std::ostream &os, const Campus campus)
{
    switch (campus)
    {
    case Campus::Trondheim:
        os << "Trondheim";
        break;
    case Campus::Alesund:
        os << "Alesund";
        break;
    case Campus::Gjovik:
        os << "Gjovik";
        break;
    }
    return os;
}

int Meeting::getDay() const { return day; }
int Meeting::getStartTime() const { return startTime; }
int Meeting::getEndTime() const { return endTime; }
Campus Meeting::getCampus() const { return location; }
std::string Meeting::getSubject() const { return subject; }
std::shared_ptr<Person> Meeting::getLeader() const { return leader; }

void Meeting::addParticipant(std::shared_ptr<Person> newParticipant)
{
    participants.push_back(newParticipant);
}

Meeting::Meeting(int mDay, int mStartTime, int mEndTime, Campus mLocation, std::string mSubject, std::shared_ptr<Person> mLeader)
    : day(mDay), startTime(mStartTime), endTime(mEndTime), location(mLocation), subject(std::move(mSubject)), leader(mLeader)
{
    addParticipant(mLeader); // The leader is also a participant.
};

std::vector<std::string> Meeting::getParcitipantList() const
{
    std::vector<std::string> resultList;
    for (const auto &participant : participants)
    {
        resultList.emplace_back(participant->getName());
    }
    return resultList;
}

std::ostream &operator<<(std::ostream &os, const Meeting &meeting)
{
    os << "Meeting details:" << std::endl;
    os << "Subject: " << meeting.getSubject() << std::endl;
    os << "Location: " << meeting.getCampus() << std::endl;
    os << "Time: " << meeting.getStartTime() << " - " << meeting.getEndTime() << std::endl;
    os << "Meeting leader: " << meeting.getLeader()->getName() << std::endl;

    return os;
}

std::vector<std::shared_ptr<Person>> Meeting::findPotentialCoDriving(Meeting &rhs) const
{
    std::vector<std::shared_ptr<Person>> applicableParticipants;
    if (rhs.location == location && rhs.day == day && abs(startTime - rhs.startTime) < 1 && abs(endTime - rhs.endTime) < 1)
    {
        for (auto participant : rhs.participants)
        {
            if (participant->hasAvailibleSeats())
            {
                applicableParticipants.emplace_back(participant);
            }
        }
    }
    else
    {
        applicableParticipants.push_back(nullptr);
    }
    return applicableParticipants;
}
