//============================================================================
// Name        : Horce.cpp  
// Author      : Yu Kuwahara
//============================================================================

#include "Horse.h"

// constructor
Horse::Horse(std::string name, std::string rider) 
{
	mName = name;
	mRider = rider;
	mMaxRunningDistPerSecond = rand() % 100 + 1; // add 1 because distance can never be 0, now 1 to 100
	mDistanceTraveled = 0; 
	mRaceWon = 0; 
}

//===========FUNCTION DEFINITIONS=============================================

// keep horses running toward the goal every second
void Horse::runASecond()
{
	mDistanceTraveled += mMaxRunningDistPerSecond;
}

// send horses to the goal everytime the race begins
void Horse::sendToGate()
{
	mDistanceTraveled = 0;
}

// display horses running toward the goal 
void Horse::toString(int goalLength)
{
	// display the starting point
	std::cout << "|"; 

	// display the distance traveled
	// avoid displaying too many dashlines by giving the two conditions below
	for (int i = 0; i < (goalLength / 25) && i < mDistanceTraveled / 25; ++i) 
	{
		std::cout << "-";
	}

	// once any rider reaches to the goal,
	// display a sign for winning
	if (mDistanceTraveled >= goalLength)
	{
		std::cout << "|> ";
	}

	// if nobody has reached to the goal yet,
	// keep horses running 
	else
	{
		// display current horse position
		std::cout << ">"; 

		// display remaining track
		// subtract 1 to always line "|" up below by adjusting the number of white space
		for (int i = 0; i < (goalLength - mDistanceTraveled - 1) / 25; ++i) 
		{
			std::cout << " ";
		}

		// display at the end of course track
		std::cout << "|  "; 

	}

	// display which horse is ridden by which rider
	std::cout << mName << " ridden by " << mRider << "." << std::endl;

}

// create a getter for distace traveled since it is set as private
int Horse::getDistanceTraveled() 
{
	return mDistanceTraveled;
}

// create a getter to increment the number of wins
void Horse::incrementWins()
{
	mRaceWon++;
}

// create a getter for horse name
std::string Horse::getName()
{
	return mName;
}

// make a getter for rider name
std::string Horse::getRider()
{
	return mRider;
}

// make a getter for the number of wins
int Horse::getWins()
{
	return mRaceWon;
}