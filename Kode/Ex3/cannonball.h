#include "std_lib_facilities.h"
#pragma once

double acclY();

double velX(double initVelocityX, double time);
double velY(double initVelocityY, double time);

double posX(double initPositionX, double initVelocityX, double time);
double posY(double initPositionY, double initVelocityY, double time);

void printTime(double time);

double flightTime(double initVelocityY);

double getUserInputTheta();
double getUserInputInitVelocity();
double degToRad(double deg);

double getVelocityX(double thetha, double initVelocity);
double getVelocityY(double thetha, double initVelocity);

vector<double> getVelocityVector(double thetha, double initVelocity);

double getDistanceTraveled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget, double velocityX, double velocityY);

void playTargetPractice();