#include "Emoji.h"

void Emoji::setNewCentre(Point &newCentre) { centre = newCentre; }

string Emoji::toString() { return to_string(centre.x) + " : " + to_string(centre.y); } // todo for debug, prints current centre

void Face::draw(AnimationWindow &win)
{
    cout << Emoji::toString() << " - Draw face" << endl; // todo debug
    Color faceColor = Color::yellow;
    win.draw_circle(centre, radius, faceColor, Color::black);
};

void EmptyFace::draw(AnimationWindow &win)
{
    Color eyeColor = Color::white;
    cout << Emoji::toString() << " - Draw emptyface" << endl; // todo debug

    Face::draw(win);
    win.draw_circle(leftEyeCentre, eyeRadius, eyeColor, Color::black);
    cout << to_string(leftEyeCentre.x) + " : " + to_string(leftEyeCentre.y) << " - Left eye centre emptyface draw" << endl; // todo debug
    win.draw_circle(leftEyeCentre, pupilRadius, Color::black);
    if (!wink) // Doesnt draw right eye is wink is active.
    {
        win.draw_circle(rightEyeCentre, eyeRadius, eyeColor, Color::black);
        win.draw_circle(rightEyeCentre, pupilRadius, Color::black);
    }
};

void SmilingFace::draw(AnimationWindow &win)
{
    cout << Emoji::toString() << " - Draw smilingface" << endl; // todo debug
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
    Point currentEmojiCenter = {100, 100};
    for (const auto &emoji : emojis)
    {
        emoji->setNewCentre(currentEmojiCenter);

        cout << emoji->toString() << " - Current centre in showAllEmojis()" << endl; // todo debug
        emoji->draw(win);

        if (currentEmojiCenter.x >= win.width())
        {
            currentEmojiCenter.y += 200;
            currentEmojiCenter.x = 100;
            cout << "End of window, lineshift" << endl; // todo debug
        }
        else
        {
            currentEmojiCenter.x += 200;
            cout << "Adds 200 in x-coordinate" << endl;
        }
    }
}