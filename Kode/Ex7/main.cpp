#include "std_lib_facilities.h"
#include "Animal.h"
#include "Emoji.h"

// * 1A)
//  Public: tilgjengelig for alle funksjoner i programmet
//  Private: kun åpent for funksjoner deklarert i samme klasse
//  Restricted: åpent for funksjoner i samme klasser og for klasser definert i samme klasse

constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 100;

int main()
{
    //* Test task 1
    // testAnimal();

    const Point tl{200, 200};
    const string win_label{"Emoji factory"};
    AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

    //* Test emojies
    /* SadFace testEmoji{tl, emojiRadius};
    testEmoji.draw(win); */

    //* Draw all emojis
    //! This is a simplified and working version.
    vector<unique_ptr<Emoji>> emojiVector;
    emojiVector.emplace_back(new SmilingFace({tl.x, tl.y}, emojiRadius));
    emojiVector.emplace_back(new SadFace({tl.x + 200, tl.y}, emojiRadius));
    emojiVector.emplace_back(new AngryFace({tl.x + 400, tl.y}, emojiRadius));
    emojiVector.emplace_back(new WinkingFace({tl.x, tl.y + 200}, emojiRadius));
    emojiVector.emplace_back(new SurprisedFace({tl.x + 200, tl.y + 200}, emojiRadius));

    showAllEmojis(emojiVector, win);

    win.wait_for_close();
    return 0;
}
