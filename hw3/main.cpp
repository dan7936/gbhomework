#include <iostream>
#include <clocale> // подключаем библиотеку с языками
#include <stdint.h> // подключаем библиотеку для использования кроссплатформенных целочисленных переменных

enum iTask2Conditions { iMagicNumber = 21, iFactor = 2 };
enum iTask3PtrArrayConditions { iArraySize = 3, iPtrLimit = 25, iRememb0to26 = 1 };
enum iTask3ArrayPicture { iIntUpperLimit = 2147483647, iIntLowerLimit = 0, iArrUpperLimit = 27, iArrLowerLimit = 1 };
// в коде попробуем поиспользовать венгерскую нотацию (i = int) (f = float)
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

	Написать программу, вычисляющую выражение a * (b + (c / d)) и выводящую результат с плавающей точкой, 
	где a, b, c, d – целочисленные константы. Используйте static_cast или СStyle cast к float чтобы выполнить точное деление.
	*/
	/*
	{
		// объявляем целочисленные константы для выражения 
		const int32_t iA = 27;
		const int32_t iB = 34;
		const int32_t iC = 94;
		const int32_t iD = 101;
		// в выражении проводим операцию кастования (превращения?) из 'int c' во 'float c'
		float fResult = iA * (iB + (static_cast<float>(iC) / iD));
		// выводим результат на экран
		std::cout << "Результат выражения " << iA << "*(" << iB << "+(" << iC << "/" << iD << ")) равен " << fResult << std::endl;
	}*/
	/*
	================================================================================================
	---------------------------------------------Task 2---------------------------------------------
	================================================================================================

	Дано целое число. Если оно меньше или равно 21, то выведите на экран разницу между этим числом и числом 21. 
	Если же заданное число больше, чем 21, необходимо вывести удвоенную разницу между этим числом и 21. 
	При выполнении задания следует использовать тернарный оператор (?:).

	Сделаем задание немного интерактивным, люблю интерактивность
	*//*
	{
		while (true)
		{
			std::cout << "Введите, пожалуйста, целочисленную переменную: ";
			int32_t iMyInteger{}, iResult{};
			std::cin >> iMyInteger;
			if(std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(iBuf_Erazer, '\n');
				std::cout << "Ошибка! Введите, пожалуства, целое число." << std::endl;
			}
			else
			{
				iResult = (iMyInteger <= iMagicNumber) ? (iMagicNumber - iMyInteger) : ((iMyInteger - iMagicNumber) * iFactor);
				if (iResult <= iMagicNumber)
				{
					std::cout << "Ваше число меньше или равно числу 21, выводим результат операции (21 - "<< iMyInteger << ") равный " << iResult << std::endl;
				}
				else 
				{
					std::cout << "Ваше число больше числа 21, выводим результат операции ((" << iMyInteger << " - 21)*2) равный " << iResult << std::endl;
				}
				break;
			}
		}
	}*/
	/*
	================================================================================================
	---------------------------------------------Task 3---------------------------------------------
	================================================================================================

	* Описать трёхмерный целочисленный массив, размером 3х3х3 и указатель на значения внутри массива и 
	при помощи операции разыменования вывести на экран значение центральной ячейки получившегося куба [1][1][1].
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
		// Делаем проверку
		pMyMagicPointer = &iMyMagical3DArray[0][0][0];
		int32_t iIndexArr{}, iIntegerArr{};
		std::cout << "Введите любое целое число от 1 до 27: ";
		while (true)
		{
			std::cin >> iIndexArr;
			if (std::cin.fail() || iIndexArr < iArrLowerLimit || iIndexArr >= iArrUpperLimit)
			{
				std::cin.clear();
				std::cin.ignore(iBuf_Erazer, '\n');
				std::cout << "Ошибка! Введите, пожалуйста, целое число от 1 до 27." << std::endl;
				std::cout << "Попробуйте еще раз: ";
			}
			else
			{
				std::cout << "Введите любое целое число от 0 до 2'147'483'647: ";
				std::cin >> iIntegerArr;
				if (std::cin.fail() || iIntegerArr > iIntUpperLimit || iIntegerArr < iIntLowerLimit)
				{
					std::cin.clear();
					std::cin.ignore(iBuf_Erazer, '\n');
					std::cout << "Ошибка! Введите, пожалуйста, целое число от 0 до 2'147'483'648." << std::endl;
					std::cout << "Попробуйте еще раз: ";
				}
				else
				{
					break;
				}
			}
		}
		std::cout << "Внесем значение переменной: " << iIntegerArr << " в " << iIndexArr << " элемент массива." << std::endl;
		pMyMagicPointer += (iIndexArr - iRememb0to26);
		* pMyMagicPointer = iIntegerArr;
		// выводим массив на экран
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

	** Написать программу, вычисляющую выражение из первого задания, а переменные для неё объявлены и 
	инициализировать в другом cpp файле. Используйте extern.
	*/
	/*
	{
		// в выражении проводим операцию кастования (превращения?) из 'int c' во 'float c'
		float fResult = iA * (iB + (static_cast<float>(iC) / iD));
		// выводим результат на экран
		std::cout << "Результат выражения " << iA << "*(" << iB << "+(" << iC << "/" << iD << ")) равен " << fResult << std::endl;
	}
	*/
	return 0;
}