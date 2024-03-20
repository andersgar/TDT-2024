#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Person.h"
#pragma once

enum class Campus
{
    Trondheim,
    Alesund,
    Gjovik
};

std::ostream &operator<<(std::ostream &os, const Campus campus);

class Meeting
{
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    std::string subject;
    const std::shared_ptr<Person> leader;
    std::vector<std::shared_ptr<Person>> participants;

public:
    int getDay() const;
    int getStartTime() const;
    int getEndTime() const;
    Campus getCampus() const;
    std::string getSubject() const;
    std::shared_ptr<Person> getLeader() const;

    void addParticipant(std::shared_ptr<Person> newParticipant);
    Meeting(int mDay, int mStartTime, int mEndTime, Campus mLocation, std::string mSubject, std::shared_ptr<Person> mLeader);

    std::vector<std::string> getParcitipantList() const;
    std::vector<std::shared_ptr<Person>> findPotentialCoDriving(Meeting &rhs) const;
};

std::ostream &operator<<(std::ostream &os, const Meeting &meeting);
