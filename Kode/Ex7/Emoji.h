#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

class Emoji
{

public:
    virtual void draw(AnimationWindow &) = 0;
    virtual ~Emoji(){}; // Destructor
};

class Face : public Emoji
{
protected:
    Point centre;
    int radius;

public:
    Face(Point c, int r) : centre(c), radius(r){};
    virtual void draw(AnimationWindow &) override = 0;
};

class EmptyFace : public Face
{
protected:
    Point leftEyeCentre;
    Point rightEyeCentre;
    int eyeRadius;
    int pupilRadius;
    bool wink = false;

public:
    EmptyFace(Point c, int r) : Face(c, r)
    {
        leftEyeCentre = {centre.x - radius / 3, centre.y - radius / 3};
        rightEyeCentre = {centre.x + radius / 3, centre.y - radius / 3};
        eyeRadius = radius / 5;
        pupilRadius = eyeRadius / 5;
    };
    virtual void draw(AnimationWindow &) override;
};

class SmilingFace : public EmptyFace
{
protected:
    Point mouthCentre;
    int mouthHeight;
    int mouthWidth;
    int mouthStartDegree = 180;
    int mouthEndDegree = 360;

public:
    SmilingFace(Point c, int r) : EmptyFace(c, r)
    {
        mouthCentre = {centre.x, centre.y};
        mouthHeight = radius / 2;
        mouthWidth = radius / 2;
    };
    virtual void draw(AnimationWindow &) override;
};

class SadFace : public SmilingFace
{
protected:
    Point leftEyebrowStart;
    Point leftEyebrowEnd;
    Point rightEyebrowStart;
    Point rightEyebrowEnd;

public:
    SadFace(Point c, int r) : SmilingFace(c, r)
    {
        mouthCentre = {centre.x, centre.y + radius / 2};
        mouthStartDegree = 0;
        mouthEndDegree = 180;
        leftEyebrowStart = {centre.x - radius / 5, centre.y - radius / 3 - radius / 3};
        leftEyebrowEnd = {centre.x - radius / 2, centre.y - radius / 2};
        rightEyebrowStart = {centre.x + radius / 5, centre.y - radius / 3 - radius / 3};
        rightEyebrowEnd = {centre.x + radius / 2, centre.y - radius / 2};
    };
    virtual void draw(AnimationWindow &) override;
};

class AngryFace : public SadFace
{
public:
    AngryFace(Point c, int r) : SadFace(c, r)
    {
        leftEyebrowStart = {centre.x - radius / 7, centre.y - radius / 3 - radius / 10};
        leftEyebrowEnd = {centre.x - radius / 2, centre.y - radius / 2};
        rightEyebrowStart = {centre.x + radius / 7, centre.y - radius / 3 - radius / 10};
        rightEyebrowEnd = {centre.x + radius / 2, centre.y - radius / 2};
    };
    void draw(AnimationWindow &) override;
};

class WinkingFace : public SmilingFace
{
protected:
    Point winkEyeStart;
    Point winkEyeEndTop;
    Point winkEyeEndBottom;

public:
    WinkingFace(Point c, int r) : SmilingFace(c, r)
    {
        wink = true;
        winkEyeStart = {rightEyeCentre.x - eyeRadius, rightEyeCentre.y};
        winkEyeEndTop = {rightEyeCentre.x + eyeRadius, rightEyeCentre.y - eyeRadius};
        winkEyeEndBottom = {rightEyeCentre.x + eyeRadius, rightEyeCentre.y + eyeRadius};
    };
    void draw(AnimationWindow &) override;
};

class SurprisedFace : public SmilingFace
{
public:
    SurprisedFace(Point c, int r) : SmilingFace(c, r)
    {
        mouthStartDegree = 0;
        mouthHeight = radius / 4;
        mouthCentre = {mouthCentre.x, mouthCentre.y + radius / 3};
    };
    void draw(AnimationWindow &) override;
};

void showAllEmojis(vector<unique_ptr<Emoji>> &emojis, AnimationWindow &win);