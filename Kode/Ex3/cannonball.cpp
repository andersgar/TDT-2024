#include "cannonball.h"
#include "utilities.h"
#include "cannonball_viz.h"
#include "std_lib_facilities.h"

double acclY()
{
    return -9.81;
}

double velX(double initVelocityX, double time)
{
    return initVelocityX;
}

double velY(double initVelocityY, double time)
{
    return initVelocityY + acclY() * time;
}

double posX(double initPositionX, double initVelocityX, double time)
{
    return initPositionX + initVelocityX * time;
}

double posY(double initPositionY, double initVelocityY, double time)
{
    return initPositionY + initVelocityY * time + (acclY() * pow(time, 2)) / 2;
}

void printTime(double time)
{
    int hours, minutes = 0;
    while (time > 3600)
    {
        hours++;
        time -= 3600;
    }
    while (time > 60)
    {
        minutes++;
        time -= 60;
    }
    cout << hours << ":" << minutes << ":" << time << endl;
}

double flightTime(double initVelocityY)
{
    return (-2 * initVelocityY) / acclY();
}

double getUserInputTheta()
{
    cout << "Input angle in degrees: " << endl;
    double theta;
    cin >> theta;
    return theta;
}

double getUserInputInitVelocity()
{
    cout << "Input initial velocity in m/s: " << endl;
    double initVelocity;
    cin >> initVelocity;
    return initVelocity;
}

double degToRad(double deg)
{
    return (deg * M_PI) / 180;
}

double getVelocityX(double thetha, double initVelocity)
{
    return initVelocity * cos(degToRad(thetha));
}

double getVelocityY(double thetha, double initVelocity)
{
    return initVelocity * sin(degToRad(thetha));
}

vector<double> getVelocityVector(double thetha, double initVelocity)
{
    vector<double> velocity(2);
    velocity.at(0) = getVelocityX(thetha, initVelocity);
    velocity.at(1) = getVelocityY(thetha, initVelocity);
    return velocity;
}

double getDistanceTraveled(double velocityX, double velocityY)
{
    return posX(0.0, velocityX, flightTime(velocityY));
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY)
{
    return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
}

void playTargetPractice()
{
    double targetPlacement = randomWithLimits(100.0, 1000.0);
    int tries = 10;
    cout << "---------------------------\n"
            "Welcome to target practice!\n"
            "You will get ten attempts at hitting the target, good luck!"
         << endl;

    while (tries > 0)
    {
        cout << "--------\n"
                "ROUND "
             << abs(tries - 11) << ":" << endl;

        double thetha = getUserInputTheta();
        double velocity = getUserInputInitVelocity();

        double distanceFault = targetPractice(targetPlacement, getVelocityX(thetha, velocity), getVelocityY(thetha, velocity));
        cannonBallViz(targetPlacement, 1000, getVelocityX(thetha, velocity), getVelocityY(thetha, velocity), 100);

        if (abs(distanceFault) < 5)
        {
            cout << "Congratulations! You've hit the target!\n"
                    "The target was "
                 << fixed << setprecision(1) << targetPlacement << " meters away." << endl;
            break;
        }
        else
        {
            tries--;
            if (distanceFault < 0)
            {
                cout << fixed << setprecision(1) << "Unfortunately, you have overshot the target by " << -distanceFault << " meters, try to aim a bit shorter." << endl;
            }
            else
            {
                cout << fixed << setprecision(1) << "Unfortunately, you have undershot the target by " << distanceFault << " meters, try to aim a bit further." << endl;
            }

            cout << "you have " << tries << " tries remaining" << endl;
        }
    }
}