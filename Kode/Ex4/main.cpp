#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"
#include "masterVisual.h"

int main()
{
    bool userActive = true;
    int chosenFunc;

        while (userActive)
    {
        cout << "-------------\n"
                "Input number according to function:\n"
                "0: Quit\n"
                "1: testCallByValue()\n"
                "2: testCallByReference()\n"
                "3: testSwapNumbers()\n"
                "4: testStudStruct()\n"
                "5: testString()\n"
                "6: playMasterMind()\n"
                "7: playMasterMindVisual()\n"
             << endl;

        cin >> chosenFunc;

        switch (chosenFunc)
        {
        case 0:
            userActive = false;
            cout << "Quitting..." << endl;
            break;
        case 1:
            testCallByValue();
            break;
        case 2:
            testCallByReference();
            break;
        case 3:
            testSwapNumbers();
            break;
        case 4:
            testStudStruct();
            break;
        //** 2e Står ikke #pragma once i utilities.h, og Student blir dermed definert både når den blir
        //** callet fra tests og main.
        case 5:
            testString();
            break;
        case 6:
            playMastermind();
            break;

        case 7:
            playMastermindVisual();
            break;
        }
    }

    return 0;
}
