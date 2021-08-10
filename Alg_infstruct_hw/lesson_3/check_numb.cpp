#include <iostream>

/*
* =============================================================================================
* ---------------------------------- Conditions and variables ---------------------------------
* =============================================================================================
*/
enum VariousConditions { BuffErazer = 32750, Zero = 0, MaxInd = 10 };
enum PrimeNumberCond { Cond1 = 2, Cond2 = 3, Cond3 = 5, Cond4 = 7, Cond5 = 11 };
char ContinueFlag{};
unsigned int Number{};

/*
* =============================================================================================
* --------------------------------------- ProtoFunctions --------------------------------------
* =============================================================================================
*/
void GetNumber(unsigned int& Number);
void PrimeNumberCheck(unsigned int& Number);
void ContinueOrNot(char& Continue);
void ClearScreen();
void Task1();
void Task2();

/*
* =============================================================================================
* ---------------------------------------- MainFunction ---------------------------------------
* =============================================================================================
*/
int main()
{
	Task1();
	Task2();
	return 0;
}

/*
* =============================================================================================
* ----------------------------------------- Functions -----------------------------------------
* =============================================================================================
*/
void GetNumber(unsigned int& Number) // function for getting number from user
{
	while (true)
	{
		std::cout << "Your number is ";
		std::cin >> Number;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(BuffErazer, '\n');
			std::cout << "Error! Wrong input." << std::endl;
		}
		else
		{
			break;
		}
	}
}

void PrimeNumberCheck(unsigned int& Number) // function for checking number for being prime number or not
{
	if (Number == Cond1 || Number == Cond2 || Number == Cond3 || Number == Cond4 || Number == Cond5)
	{
		std::cout << "Your number is prime number." << std::endl;
	}
	else
	{
		if (Number % Cond1 == Zero || Number % Cond2 == Zero || Number % Cond3 == Zero || Number % Cond4 == Zero || Number % Cond5 == Zero)
		{
			std::cout << "Your number is not prime number." << std::endl;
		}
		else
		{
			std::cout << "Your number is prime number." << std::endl;
		}
	}
}

void GetInput(char& Continue) // function for getting user input on willing to continue testing
{
	while (true)
	{
		std::cout << "If you want to test another number pls type 'c', else type 'e': ";
		std::cin >> Continue;
		if (std::cin.fail() || Continue != 'c' && Continue != 'e')
		{
			std::cin.clear();
			std::cin.ignore(BuffErazer, '\n');
			std::cout << "Error! Wrong input." << std::endl;
		}
		else
		{
			break;
		}
	}
}

void ClearScreen() // function for clearing screen
{
	system("cls");
}

void ContinueOrNot(char & Continue) // function for continue testing or closing
{
	while (true)
	{
		GetInput(Continue);
		if (Continue == 'c')
		{
			ClearScreen();
			std::cout << "-------------------- Task 1 --------------------" << std::endl;
			std::cout << "Pls enter some whole non-negative number." << std::endl;
			GetNumber(Number);
			PrimeNumberCheck(Number);
		}
		else
		{
			std::cout << "Thank you for testing this programm!" << std::endl;
			break;
		}
	}
}

void Task1() // main function for task 1
{
	std::cout << "-------------------- Task 1 --------------------" << std::endl;
	std::cout << "Pls enter some whole non-negative number." << std::endl;
	GetNumber(Number);
	PrimeNumberCheck(Number);
	ContinueOrNot(ContinueFlag);
}

void Task2() // main function for task 2
{
	std::cout << "-------------------- Task 2 --------------------" << std::endl;
	int Summ{};
	for (int Index = Zero; Index <= MaxInd; Index++)
	{
		Summ += Index;
	}
	std::cout << "Summ of numbers from 1 to 10 is " << Summ << std::endl;
}