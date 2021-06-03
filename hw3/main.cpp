#include <iostream>
#include <clocale> // ���������� ���������� � �������
#include <stdint.h> // ���������� ���������� ��� ������������� ������������������ ������������� ����������

enum iTask2Conditions { iMagicNumber = 21, iFactor = 2 };
enum iTask3PtrArrayConditions { iArraySize = 3, iPtrLimit = 25, iRememb0to26 = 1 };
enum iTask3ArrayPicture { iIntUpperLimit = 2147483647, iIntLowerLimit = 0, iArrUpperLimit = 27, iArrLowerLimit = 1 };
// � ���� ��������� �������������� ���������� ������� (i = int) (f = float)
const int iBuf_Erazer = 35247;
const extern int32_t iA;
const extern int32_t iB;
const extern int32_t iC;
const extern int32_t iD;

int main()
{
	setlocale(LC_ALL, "Russian");
	/*
	================================================================================================
	---------------------------------------------Task 1---------------------------------------------
	================================================================================================

	�������� ���������, ����������� ��������� a * (b + (c / d)) � ��������� ��������� � ��������� ������, 
	��� a, b, c, d � ������������� ���������. ����������� static_cast ��� �Style cast � float ����� ��������� ������ �������.
	*/
	/*
	{
		// ��������� ������������� ��������� ��� ��������� 
		const int32_t iA = 27;
		const int32_t iB = 34;
		const int32_t iC = 94;
		const int32_t iD = 101;
		// � ��������� �������� �������� ���������� (�����������?) �� 'int c' �� 'float c'
		float fResult = iA * (iB + (static_cast<float>(iC) / iD));
		// ������� ��������� �� �����
		std::cout << "��������� ��������� " << iA << "*(" << iB << "+(" << iC << "/" << iD << ")) ����� " << fResult << std::endl;
	}*/
	/*
	================================================================================================
	---------------------------------------------Task 2---------------------------------------------
	================================================================================================

	���� ����� �����. ���� ��� ������ ��� ����� 21, �� �������� �� ����� ������� ����� ���� ������ � ������ 21. 
	���� �� �������� ����� ������, ��� 21, ���������� ������� ��������� ������� ����� ���� ������ � 21. 
	��� ���������� ������� ������� ������������ ��������� �������� (?:).

	������� ������� ������� �������������, ����� ���������������
	*//*
	{
		while (true)
		{
			std::cout << "�������, ����������, ������������� ����������: ";
			int32_t iMyInteger{}, iResult{};
			std::cin >> iMyInteger;
			if(std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(iBuf_Erazer, '\n');
				std::cout << "������! �������, ����������, ����� �����." << std::endl;
			}
			else
			{
				iResult = (iMyInteger <= iMagicNumber) ? (iMagicNumber - iMyInteger) : ((iMyInteger - iMagicNumber) * iFactor);
				if (iResult <= iMagicNumber)
				{
					std::cout << "���� ����� ������ ��� ����� ����� 21, ������� ��������� �������� (21 - "<< iMyInteger << ") ������ " << iResult << std::endl;
				}
				else 
				{
					std::cout << "���� ����� ������ ����� 21, ������� ��������� �������� ((" << iMyInteger << " - 21)*2) ������ " << iResult << std::endl;
				}
				break;
			}
		}
	}*/
	/*
	================================================================================================
	---------------------------------------------Task 3---------------------------------------------
	================================================================================================

	* ������� ��������� ������������� ������, �������� 3�3�3 � ��������� �� �������� ������ ������� � 
	��� ������ �������� ������������� ������� �� ����� �������� ����������� ������ ������������� ���� [1][1][1].
	*/
	{
		int32_t iMyMagical3DArray[iArraySize][iArraySize][iArraySize] = {};
		int32_t *pMyMagicPointer = &iMyMagical3DArray[0][0][0];
		int32_t iIndex = 0;
		int32_t iVarInt = 1;
		while (true)
		{
			pMyMagicPointer[iIndex] = iVarInt;
			if (iIndex <= iPtrLimit)
			{
				iIndex++;
				iVarInt++;	
			}
			else
			{
				break;
			}
		}
		for (int32_t iDimension = 0; iDimension < iArraySize; ++iDimension)
		{
			for (int32_t iRow = 0; iRow < iArraySize; ++iRow)
			{
				for (int32_t iCol = 0; iCol < iArraySize; ++iCol)

					std::cout << "|" << iMyMagical3DArray[iDimension][iRow][iCol] << "|   ";

				std::cout << '\n';
			}
		}
		// ������ ��������
		pMyMagicPointer = &iMyMagical3DArray[0][0][0];
		int32_t iIndexArr{}, iIntegerArr{};
		std::cout << "������� ����� ����� ����� �� 1 �� 27: ";
		while (true)
		{
			std::cin >> iIndexArr;
			if (std::cin.fail() || iIndexArr < iArrLowerLimit || iIndexArr >= iArrUpperLimit)
			{
				std::cin.clear();
				std::cin.ignore(iBuf_Erazer, '\n');
				std::cout << "������! �������, ����������, ����� ����� �� 1 �� 27." << std::endl;
				std::cout << "���������� ��� ���: ";
			}
			else
			{
				std::cout << "������� ����� ����� ����� �� 0 �� 2'147'483'647: ";
				std::cin >> iIntegerArr;
				if (std::cin.fail() || iIntegerArr > iIntUpperLimit || iIntegerArr < iIntLowerLimit)
				{
					std::cin.clear();
					std::cin.ignore(iBuf_Erazer, '\n');
					std::cout << "������! �������, ����������, ����� ����� �� 0 �� 2'147'483'648." << std::endl;
					std::cout << "���������� ��� ���: ";
				}
				else
				{
					break;
				}
			}
		}
		std::cout << "������ �������� ����������: " << iIntegerArr << " � " << iIndexArr << " ������� �������." << std::endl;
		pMyMagicPointer += (iIndexArr - iRememb0to26);
		* pMyMagicPointer = iIntegerArr;
		// ������� ������ �� �����
		for (int32_t iDimension = 0; iDimension < iArraySize; ++iDimension)
		{
			for (int32_t iRow = 0; iRow < iArraySize; ++iRow)
			{
				for (int32_t iCol = 0; iCol < iArraySize; ++iCol)

					std::cout << "|" << iMyMagical3DArray[iDimension][iRow][iCol] << "|   ";

				std::cout << '\n';
			}
		}
	}
	/*
	================================================================================================
	---------------------------------------------Task 4---------------------------------------------
	================================================================================================

	** �������� ���������, ����������� ��������� �� ������� �������, � ���������� ��� �� ��������� � 
	���������������� � ������ cpp �����. ����������� extern.
	*/
	/*
	{
		// � ��������� �������� �������� ���������� (�����������?) �� 'int c' �� 'float c'
		float fResult = iA * (iB + (static_cast<float>(iC) / iD));
		// ������� ��������� �� �����
		std::cout << "��������� ��������� " << iA << "*(" << iB << "+(" << iC << "/" << iD << ")) ����� " << fResult << std::endl;
	}
	*/
	return 0;
}