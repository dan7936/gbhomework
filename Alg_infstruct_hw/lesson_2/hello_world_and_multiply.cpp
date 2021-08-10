#include <iostream>

const int BuffEraser = 32750;
void Task1();
void Task2();
void ConsoleInput(unsigned int& Digit);

int main()
{
	/*
	* ==================================================================================
	* ------------------------------------- Task 1 -------------------------------------
	* ==================================================================================
	*/
	// Hello World programm with some tweaks.
	Task1();
	/*
	* ==================================================================================
	* ------------------------------------- Task 2 -------------------------------------
	* ==================================================================================
	*/
	// Numbers multiply.
	Task2();
	return 0;
}

/*
* =====================================================================================
* ------------------------------------- Functions -------------------------------------
* =====================================================================================
*/

void Task1()
{
	while (true)
	{
		std::cout << "Pls, enter letter 'y' and programm will salute the World! Else enter 'n' and programm will close!" << std::endl;
		char letter{};
		std::cin >> letter;
		if (letter != 'n' && letter != 'y')
		{
			std::cin.clear();
			std::cin.ignore(BuffEraser, '\n');
			std::cout << "Error! Pls try again." << std::endl;
		}
		else
			if (letter == 'y')
			{
				std::cout << "Hello World!" << std::endl;
				break;
			}
			else
			{
				break;
			}
	}
}

void Task2()
{
	while (true)
	{
		std::cout << "Pls enter two whole non-negative digits!" << std::endl;
		unsigned int DigitA{};
		std::cout << "A = ";
		ConsoleInput(DigitA);
		unsigned int DigitB{};
		std::cout << "B = ";
		ConsoleInput(DigitB);
		unsigned int Summ{};
		Summ = DigitA * DigitB;
		std::cout << "Summ of two digits is " << Summ << std::endl;
		break;

	}
}

void ConsoleInput(unsigned int& Digit)
{
	while (true)
	{
		std::cin >> Digit;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(BuffEraser, '\n');
			std::cout << "Error! Pls try again." << std::endl;
			std::cout << "Digit = ";
		}
		else
		{
			break;
		}
	}
}