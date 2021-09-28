#include "header.h"

/*
* =================================================================
* ----------------------------Functions----------------------------
* =================================================================
*/
void Task1() // primal function for TASK 1
{
	std::cout << "------------------------Task 1------------------------" << std::endl;
	StudentDataBase dataBase;
	dataBase.databaseWork();
}

int getUserInput() // function for geting user input
{
	int RealityCheck{ 1 };
	int userInput{};
	bool cinFlag{};
	while (!cinFlag)
	{
		cinFlag = true;
		std::cin >> userInput;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.fail() || userInput < RealityCheck)
		{
			cinFlag = false;
			std::cin.clear();
			std::cout << "Error! Pls try again." << std::endl;
		}
	}
	return userInput;
}

bool getUserInputWom() // function for geting user input
{
	bool userInput{};
	bool cinFlag{};
	while (!cinFlag)
	{
		cinFlag = true;
		std::cin >> userInput;
		if (std::cin.fail())
		{
			cinFlag = false;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Error! Pls try again." << std::endl;
		}
	}
	return userInput;
}

std::string getUserWords() // function for geting user input on words for string
{
	std::string userInput{};
	bool cinFlag{};
	while (!cinFlag)
	{
		cinFlag = true;
		std::getline(std::cin, userInput);
		if (std::cin.fail())
		{
			cinFlag = false;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Error! Pls try again." << std::endl;
		}
	}
	return userInput;
}

void Task2() // primal function for TASK 2
{
	std::cout << "------------------------Task 2------------------------" << std::endl;
	Apple apple("red");
	Banana banana;
	GrannySmith grannySmith;
	std::cout << "My " << apple.getName() << " is " << apple.getColor() << ".\n";
	std::cout << "My " << banana.getName() << " is " << banana.getColor() << ".\n";
	std::cout << "My " << grannySmith.getName() << " is " << grannySmith.getColor() << ".\n";
}