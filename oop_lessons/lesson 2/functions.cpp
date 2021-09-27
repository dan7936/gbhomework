#include "header.h"

/*
* =================================================================
* ----------------------------Functions----------------------------
* =================================================================
*/
void Task1() // primal function for TASK 1
{
	std::cout << "------------------------Task 1------------------------" << std::endl;
	int sizeOfDatabase = setSizeOfDatabase();
	Student* p_studentDatabase = new Student[sizeOfDatabase];
	char c_userChoise{};
	int databaseIndex{};
	bool databaseClosing{};
	while (!databaseClosing)
	{
		std::cout << "Do you want to input a new student in database? y/n: ";
		c_userChoise = userChoosing();
		if (databaseIndex > sizeOfDatabase)
		{
			std::cout << "Sorry the database is full!" << std::endl;
		}
		else if (c_userChoise == 'y')
		{
			p_studentDatabase[databaseIndex].getInfo();
			databaseIndex++;
		}
		else
		{
			std::cout << "Do you want to increment existing student's year of study? y/n: ";
			c_userChoise = userChoosing();
			if (c_userChoise == 'y')
			{
				std::cout << "Pls choose a student's number who's year of study you want to increment: ";
				dataBaseNavigationYear(p_studentDatabase, databaseIndex);
			}
			else
			{
				std::cout << "Right now we have a " << databaseIndex << " students in our database!" << std::endl;
				std::cout << "Do you want to see info about your students? y/n: ";
				c_userChoise = userChoosing();
				if (c_userChoise == 'y')
				{
					std::cout << "Pls choose a student's number who's info you want to read: ";
					dataBaseNavigationPrint(p_studentDatabase, databaseIndex);
				}
				else
				{
					std::cout << "Do you want to stop working with database? y/n: ";
					c_userChoise = userChoosing();
					if (c_userChoise == 'y')
					{
						databaseClosing = true;
					}
					else
					{
						databaseClosing = false;
					}
				}
			}
		}
	}
	delete[] p_studentDatabase;
}

int setSizeOfDatabase() // function for seting size of database in TASK 1
{
	std::cout << "Let's create our student database." << std::endl;
	std::cout << "Pls, enter the size of our database: ";
	int sizeOfDatabase = getUserInput();
	return sizeOfDatabase;
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

char userChoosing() // function for geting user input on continue or not
{
	char c_choise{};
	bool cinFlag{};
	while (!cinFlag)
	{
		cinFlag = true;
		std::cin >> c_choise;
		if (std::cin.fail() || c_choise != 'y' && c_choise != 'n')
		{
			cinFlag = false;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Error! Pls try again." << std::endl;
		}
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return c_choise;
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

void dataBaseNavigationYear(Student student[], int databaseIndex) // function for database naviagation and years increment
{
	int databaseNavig = getUserInput();
	if (databaseNavig > databaseIndex)
	{
		std::cout << "Sorry, we don't have so much students in our database!" << std::endl;
	}
	else
	{
		databaseNavig--;
		student[databaseNavig].incrYearOfStudy();
	}
}

void dataBaseNavigationPrint(Student student[], int databaseIndex) // function for database naviagation and printing student's info
{
	int databaseNavig = getUserInput();
	if (databaseNavig > databaseIndex)
	{
		std::cout << "Sorry, we don't have so much students in our database!" << std::endl;
	}
	else
	{
		databaseNavig--;
		student[databaseNavig].printStudentInfo();
	}
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