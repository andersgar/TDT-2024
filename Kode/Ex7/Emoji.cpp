#include "Emoji.h"

void Face::draw(AnimationWindow &win)
{
    Color faceColor = Color::yellow;
    win.draw_circle(centre, radius, faceColor, Color::black);
};

void EmptyFace::draw(AnimationWindow &win)
{
    Color eyeColor = Color::white;
    Face::draw(win);
    win.draw_circle(leftEyeCentre, eyeRadius, eyeColor, Color::black);
    win.draw_circle(leftEyeCentre, pupilRadius, Color::black);
    if (!wink) // Doesnt draw right eye is wink is active.
    {
        win.draw_circle(rightEyeCentre, eyeRadius, eyeColor, Color::black);
        win.draw_circle(rightEyeCentre, pupilRadius, Color::black);
    }
};

void SmilingFace::draw(AnimationWindow &win)
{
    EmptyFace::draw(win);
    win.draw_arc(mouthCentre, mouthWidth, mouthHeight, mouthStartDegree, mouthEndDegree);
};

void SadFace::draw(AnimationWindow &win)
{
    EmptyFace::draw(win);
    win.draw_arc(mouthCentre, mouthWidth, mouthHeight, mouthStartDegree, mouthEndDegree);
    win.draw_line(leftEyebrowStart, leftEyebrowEnd);
    win.draw_line(rightEyebrowStart, rightEyebrowEnd);
}

void AngryFace::draw(AnimationWindow &win)
{
    SadFace::draw(win);
    win.draw_line(leftEyebrowStart, leftEyebrowEnd);
    win.draw_line(rightEyebrowStart, rightEyebrowEnd);
}

void WinkingFace::draw(AnimationWindow &win)
{
    SmilingFace::draw(win);
    win.draw_line(winkEyeStart, winkEyeEndTop);
    win.draw_line(winkEyeStart, winkEyeEndBottom);
}

void SurprisedFace::draw(AnimationWindow &win)
{
    SmilingFace::draw(win);
};

void showAllEmojis(vector<unique_ptr<Emoji>> &emojis, AnimationWindow &win)
{
    for (const auto &emoji : emojis)
    {
        emoji->draw(win);
    }
}