#include "std_lib_facilities.h"
#include "AnimationWindow.h"

void Pythagoras()
{
    AnimationWindow win{100, 100, 700, 600, "Pythagoras"};
    Point pointTBC{300, 200};
    Point pointTAB{300, 400};
    Point pointTAC{450, 400};
    Point pointSB1{100, 200};
    Point pointSB2{100, 400};
    Point pointSA1{300, 550};
    Point pointSA2{450, 550};
    Point pointSC1{500, 50};
    Point pointSC2{650, 250};
    win.draw_triangle(pointTAB, pointTAC, pointTBC, Color::black);
    win.draw_quad(pointTAB, pointTBC, pointSB1, pointSB2, Color::green);
    win.draw_quad(pointTAC, pointTBC, pointSC1, pointSC2, Color::blue);
    win.draw_quad(pointTAB, pointSA1, pointSA2, pointTAC, Color::red);
    win.wait_for_close();
}