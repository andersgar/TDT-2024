#include "cannonball.h"
#include "utilities.h"
#include "std_lib_facilities.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name);

int main()
{
    double maxError = 0.0001;
    // vel:
    testDeviation(velX(50.0, 2.5), 50.0, maxError, "velX(50.0 2.5)");
    testDeviation(velX(50.0, 5.0), 50.0, maxError, "velX(50.0 5.0)");
    testDeviation(velY(25.0, 2.5), 0.475, maxError, "velY(25.0 2.5)");
    testDeviation(velY(25.0, 5.0), -24.05, maxError, "velY(25.0 5.0)");
    // pos:
    testDeviation(posX(0.0, 50.0, 2.5), 125.0, maxError, "posX(0.0, 50.0, 2.5)");
    testDeviation(posX(0.0, 50.0, 5.0), 250.0, maxError, "posX(0.0, 50.0, 5.0)");
    testDeviation(posY(0.0, 25.0, 2.5), 31.84, maxError, "posY(0.0, 25.0, 2.5)");
    testDeviation(posY(0.0, 25.0, 5.0), 2.375, maxError, "posY(0.0, 25.0, 5.0)");
    // getVelocityVector:
    testDeviation(getVelocityVector(27.5, 15.64).at(0), 13.8728, maxError, "x-component of getVelocityVector(27.5, 15.64)");
    testDeviation(getVelocityVector(27.5, 15.64).at(1), 7.22175, maxError, "y-component of getVelocityVector(27.5, 15.64)");
    // getDistanceTraveled:
    testDeviation(getDistanceTraveled(13.8728, 7.22175), 20.5253, maxError, "getDistanceTraveled(13.8728,7.22175)");
    // targetPractice:
    testDeviation(abs(targetPractice(20, 13.8728, 7.22175)), 0.5253, maxError, "targetPractice(20,13.8728,7.22175)");

    playTargetPractice();
    return 0;
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name)
{
    if (abs(compareOperand - toOperand) <= maxError)
    {
        cout << name << " is valid" << endl;
    }
    else
    {
        cout << name << " is not valid, expected " << toOperand << ", got " << compareOperand << endl;
    }
}
