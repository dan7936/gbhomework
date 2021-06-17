#include "functions.h"

namespace MyFunc
{
	// функция для инициализации массива типа float (1-е задание)
	void InitArray(float* Array, int ArraySize)
	{
		srand(time(NULL));
		for (int Index = Zero; Index < ArraySize; ++Index)
		{
			Array[Index] = static_cast<float>(rand() % TwoHund - OneHund);
		}
	}

	// функция для инициализации массива типа int через консольный ввод (3-е задание)
	void InitArray(int* Array, int ArraySize)
	{
		for (int Index = Zero; Index < ArraySize; ++Index)
		{
			Array[Index] = ConsoleInput();
		}
	}

	// функция для распечатывания массива типа float (1-е задание)
	void PrintArray(float* Array, int ArraySize)
	{
		for (int Index = Zero; Index < ArraySize; ++Index)
		{
			std::cout << Array[Index] << " ";
		}
		std::cout << std::endl;
	}

	// функция для распечатывания массива типа int (3-е задание)
	void PrintArray(int* Array, int ArraySize)
	{
		for (int Index = Zero; Index < ArraySize; ++Index)
		{
			std::cout << Array[Index] << " ";
		}
		std::cout << std::endl;
	}

	// функция для определения количества положительных и отрицательных чисел в массиве (2-е задание)
	void SumArray(float* Array, int ArraySize)
	{
		int Positive{}, Negative{};
		for (int Index = Zero; Index < ArraySize; ++Index)
		{
			Array[Index] > Zero ? ++Positive : ++Negative;
		}
		std::cout << "In our array where is " << Positive << " positive numbers and " << Negative << " negative numbers." << std::endl;
	}

	// функция для консольного ввода (2-е задание)
	void ConsoleInput(int* Integer)
	{
		while (true)
		{
			std::cout << "Pls enter some integer number: ";
			std::cin >> *Integer;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(BufErazer, '\n');
				std::cout << "Error! Pls enter a correct integer number!" << std::endl;
			}
			else
			{
				break;
			}
		}
	}

	// функция для консольного ввода с возращаемым значением (3-е задание)
	int ConsoleInput()
	{
		while (true)
		{
			int Integer;
			std::cout << "Pls enter some integer number: ";
			std::cin >> Integer;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(BufErazer, '\n');
				std::cout << "Error! Pls enter a correct integer number!" << std::endl;
			}
			else
			{
				return Integer;
			}
		}
	}

	// функция для сортировки массива (3-е задание)
	void SortArray(int* Array, int ArraySize) 
	{
		for(int Index = Zero; Index < ArraySize-One;)
		{
			if (Array[Index] > Array[Index + 1])
			{
				SWAP(Array[Index], Array[Index + 1]);
				Index = Zero;
			}
			else
			{
				++Index;
			}
		}
	}
}