//============================================================================
// Name        : Horse.h  
// Author      : Yu Kuwahara
//============================================================================

#pragma once
#include <iostream>
#include <string>
#include <cstdlib> // generate a random number
#include <random> // pseudo-random number generation
#include <time.h> // ".h" since it is a header file

class Horse
{
private: // any data are in public
	std::string mName; // it is a member variable
	std::string mRider; // add "m" to differentiate from "name", "rider", and etc in Horce.cpp
	int mMaxRunningDistPerSecond; 
	int mDistanceTraveled;
	int mRaceWon;
public: // any functions are in public
	Horse(std::string name, std::string rider);
	void runASecond();
	void sendToGate();
	void toString(int goalLength);
	int getDistanceTraveled();
	void incrementWins();
	std::string getName();
	std::string getRider();
	int getWins();
};
