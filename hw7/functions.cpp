#include "functions.h"

namespace MyFunc
{
	// ������� ��� ������������� ������� ���� float (1-� �������)
	void InitArray(float* Array, int ArraySize)
	{
		srand(time(NULL));
		for (int Index = Zero; Index < ArraySize; ++Index)
		{
			Array[Index] = static_cast<float>(rand() % TwoHund - OneHund);
		}
	}

	// ������� ��� ������������� ������� ���� int ����� ���������� ���� (3-� �������)
	void InitArray(int* Array, int ArraySize)
	{
		for (int Index = Zero; Index < ArraySize; ++Index)
		{
			Array[Index] = ConsoleInput();
		}
	}

	// ������� ��� �������������� ������� ���� float (1-� �������)
	void PrintArray(float* Array, int ArraySize)
	{
		for (int Index = Zero; Index < ArraySize; ++Index)
		{
			std::cout << Array[Index] << " ";
		}
		std::cout << std::endl;
	}

	// ������� ��� �������������� ������� ���� int (3-� �������)
	void PrintArray(int* Array, int ArraySize)
	{
		for (int Index = Zero; Index < ArraySize; ++Index)
		{
			std::cout << Array[Index] << " ";
		}
		std::cout << std::endl;
	}

	// ������� ��� ����������� ���������� ������������� � ������������� ����� � ������� (2-� �������)
	void SumArray(float* Array, int ArraySize)
	{
		int Positive{}, Negative{};
		for (int Index = Zero; Index < ArraySize; ++Index)
		{
			Array[Index] > Zero ? ++Positive : ++Negative;
		}
		std::cout << "In our array where is " << Positive << " positive numbers and " << Negative << " negative numbers." << std::endl;
	}

	// ������� ��� ����������� ����� (2-� �������)
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

	// ������� ��� ����������� ����� � ����������� ��������� (3-� �������)
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

	// ������� ��� ���������� ������� (3-� �������)
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