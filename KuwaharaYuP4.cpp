//============================================================================
// Name        : KuwaharaYuP4.cpp  
// Author      : Yu Kuwahara
//============================================================================

#include "Horse.h" // the header file contains all the include directives
#include <vector> // horse vector needs to be created in main.cpp

int main()
{
	srand(time(NULL)); // generate random numbers
	std::vector <Horse> raceHorses; // create an empty vector
	int raceEntrants = 0; // initialize the number of horse
	int raceDistance = 0; // initialize the distance of race
	int numRaces = 0; // initialize the number of race

//=============================================================================

	std::cout << "Welcome to horse racing game!\n" << std::endl;

	// prompt the user for number of horse
	std::cout << "How many horses are in the race: ";
	std::cin >> raceEntrants;
	std::cin.ignore();

	// prompt the user for names of horse and rider for all the horses
	for (int i = 0; i < raceEntrants; ++i) 
	{
		std::string name;
		std::string rider;

		std::cout << "Please give me the name of horse #" << i + 1 << " : ";
		std::getline(std::cin, name); // in case the horse has a whitespace between the first and last names
		std::cout << "Please give me the name of rider #" << i + 1 << " : ";
		std::getline(std::cin, rider); // in case the use types both first and last names

		raceHorses.push_back(Horse(name, rider)); // fill up the empty vector
	}

	// prompr the user for distance of a race
	// since the max speed of horse could be 100, the distance needs to be min 100
	std::cout << "Please enter the distance of the race (100 - 1000): ";
	std::cin >> raceDistance;
	
	// warn the user if he types an invalid number
	// else, he will be asked to enter again
	if (raceDistance < 100 || raceDistance > 1000) 
	{
		std::cout << "Invalid number of distance of a race" << std::endl;
		std::cout << "Please enter distance of the race again between 100 and 1000: ";
		std::cin >> raceDistance;
	}
	
	// set a flag for keep running the race or not
	bool stillRacing = true; 

	// set a flag for starting a new race or not
	bool raceAgain = true;

//=============================================================================

	// while loop for having a new race
	while (raceAgain)
	{
		// send horses to a gate everytime a race begins
		for (auto &i : raceHorses)
		{
			i.sendToGate();
		}

		stillRacing = true;

		std::cout << "===========================================\n";
		std::cout << "The start!" << std::endl;

		// display the horses and riders 
		for (auto &i : raceHorses) // pass by reference to modify the original
		{
			i.toString(raceDistance); // i is an element such as horse name Jim
		}

		/* instead of auto,
		 for (size_t i = 0; i < raceHorses.size(); ++i)
		{
			raceHorses[i].toString(raceDistance)
		}
		*/ 

//=============================================================================

		// while loop for keep running in the same race until once any rider wins
		while (stillRacing)
		{
			// ask the user if he wants to keep going to race
			char input;
			std::cout << "Are you ready for the next second (y / n) ?: " << std::endl;
			std::cin.ignore();
			std::cin >> input;

//=============================================================================

			// if the user wants to keep going,
			if (input == 'y')
			{
				for (auto &i : raceHorses)
				{
	                // run another second
					i.runASecond();
					i.toString(raceDistance);

					// once any rider reachs to the goal, the race is over
					if (i.getDistanceTraveled() >= raceDistance)
					{
						stillRacing = false;
					}

				}

				if (!stillRacing)
				{
					// count how many races were done in total
					++numRaces; 

					// find the horse which ran the longest distance
					int longestHorse = 0;
					for (auto &i : raceHorses)
					{
						if (i.getDistanceTraveled() >= raceDistance)
						{
							longestHorse = i.getDistanceTraveled(); 
						}
					}

					std::cout << "\n===========================================\n\n";

					// display which rider won the race
					for (auto &i : raceHorses)
					{
						if (i.getDistanceTraveled() == longestHorse)
						{
							i.incrementWins();
							std::cout << i.getName() << " of " << i.getRider() << " won!\n" << std::endl;
						}
					}

					// display the statistics of the race
					for (auto &i : raceHorses)
					{
						std::cout << i.getName() << " has won " << i.getWins() << " / " << numRaces << std::endl;
					}

					// ask the user if he wants to have another race
					char choice;
					std::cout << "\nDo you wish to continue (y / n) ?: " << std::endl;
					std::cin >> choice;

					// if yes, race another game
					if (choice == 'y')
					{
						raceAgain = true; 
					}

					// if no, exit the game
					else if (choice == 'n')
					{
						std::cout << "Thank you for racing!";
						raceAgain = false; 
					}

					// display an error message for invalid choice for starting a new race
					else
					{
						std::cout << "Please enter a valid choice!" << std::endl;
						std::cin >> choice;
					}
				}
			}

//=============================================================================
			
			// the user wants to stop the race
			else if (input == 'n')
			{
				// stop running the race
				stillRacing = false;

				std::cout << "Thank you for racing!" << std::endl; 

				// ask if the user wants to have a new race
				char choice;
				std::cout << "Do you want to have another race (y / n) ?: " << std::endl;
				std::cin >> choice;

				// if yes, start a new race
				if (choice == 'y')
				{
					raceAgain = true;
				}

				// if no, exit the window
				else if (choice == 'n')
				{
					raceAgain = false;  
				}

				// display an error message for invalid choice for starting a new race
				else
				{
					std::cout << "Please enter a valid choice!" << std::endl;
					std::cin >> choice;
				}

			}

//=============================================================================

            // display an error message for invalid choice for keep running the same race
			else
			{
				std::cout << "Please enter a valid choice!" << std::endl;
				std::cin >> input;
			}

		}

	}

	return 0;
}
