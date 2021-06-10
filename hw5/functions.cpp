#include "header.h"

void ArrayInit(double* Arr, const size_t ArrSize, int RandCond) // ��������� ������� ������������� double ������� �� 1�� �������
{
	srand(time(NULL));
	for (size_t Index = ZERO; Index < ArrSize; ++Index)
	{
		Arr[Index] = rand() % (100 + RandCond);
	}
}

void ArrayInit(int* Arr, const size_t ArrSize, int RandCond) // ��������� ������� ������������� ��� int ������� �� 2�� �������
{
	srand(time(NULL));
	for (size_t Index = ZERO; Index < ArrSize; ++Index)
	{
		Arr[Index] = rand() % (100 + RandCond);
	}
}

void PrintArray(double Arr[], size_t ArrSize) // ��������� ������� ��� ������ ����������� double ������� �� ����� �� 1�� �������
{
	for (size_t Index = ZERO; Index < ArrSize; ++Index)
	{
		std::cout << Arr[Index] << " ";
	}
	std::cout << std::endl;
}

void PrintArray(int Arr[], size_t ArrSize) // ��������� ������� ��� ������ ����������� int ������� �� ����� �� 2�� � 3�� �������
{
	for (size_t Index = ZERO; Index < ArrSize; ++Index)
	{
		std::cout << Arr[Index] << " ";
	}
	std::cout << std::endl;
}

void ChangeArray(int* Arr, size_t ArrSize) // ��������� ������� ��� ����� �������� ��������� ������� � 1 �� 0 � �������� ��� 2�� �������
{
	for (size_t Index = ZERO; Index < ArrSize; ++Index)
	{
		if (Arr[Index] == ZERO)
		{
			Arr[Index] = ONE;
		}
		else
		{
			Arr[Index] = ZERO;
		}
	}
}

void ArrayInitT3(int* Arr, size_t ArrSize) // ��������� ������� ��� ������������� ������� � 3-� �������
{
	int Integer = ONE;
	for (int Index = ZERO; Index < ArrSize; ++Index)
	{
		Arr[Index] = Integer;
		Integer+=3;
	}
}

void ReadInput(int *Change) // ��������� ������� ��� ���������� ����������� �����
{
	while (true)
	{
		std::cout << "Pls input your integer in diaposon from -10 to 10: ";
		std::cin >> *Change;
		if (std::cin.fail() || *Change > T4LimitMax || *Change == ZERO || *Change < T4LimitMin)
		{
			std::cin.clear();
			std::cin.ignore(BuffErazer, '\n');
			std::cout << "Whong! Pls try again" << std::endl;
		}
		else
		{
			break;
		}
	}
}

void ArrayShift(int* Arr, size_t ArrSize, int Change) // ������� ��� ������ ������� ������ ��� ����� � 4-� �������
{
	int ShiftArray[ArrSize1]{};
	if (Change < ZERO)
	{
		Change++;
		unsigned int Change2 = ArrSize + Change;
		Change2--;
		for (int Index = ZERO; Index < ArrSize; Index++)
		{
			ShiftArray[Change2] = Arr[Index];
			Change2++;
			if (Change2 >= ArrSize1)
			{
				Change2 = ZERO;
			}
		}
		PrintArray(ShiftArray, ArrSize1);
	}
	else
	{
		Change--;
		for (int Index = ZERO; Index < ArrSize; Index++)
		{
			ShiftArray[Change] = Arr[Index];
			Change++;
			if (Change >= ArrSize1)
			{
				Change = ZERO;
			}
		}
		PrintArray(ShiftArray, ArrSize1);
	}
}