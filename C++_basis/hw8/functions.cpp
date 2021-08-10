#include "protofunc.h"

//===================================================================Объявляем функции=============================================================================
/*
* =================================================================================================================================================================
* --------------------------------------------------------------Функция генератора случайных чисел-----------------------------------------------------------------
* =================================================================================================================================================================
*/
int32_t getRandomNum(int32_t min, int32_t max)
{
	const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	static std::mt19937_64 generator(seed);
	std::uniform_int_distribution<int32_t> dis(min, max);
	return dis(generator);
}
/*
* =================================================================================================================================================================
* -----------------------------------Функция для инициализации поля и определения знаков которыми будут ходить игроки----------------------------------------------
* =================================================================================================================================================================
*/
void InitField(TiTaToField& Field) 
{
	Field.ppField = new TicTacToeChars * [Field.SIZE];
	for (size_t Index{}; Index < Field.SIZE; Index++)
	{
		Field.ppField[Index] = new TicTacToeChars[Field.SIZE];
	}
	for (size_t CoordX{}; CoordX < Field.SIZE; CoordX++)
	{
		for (size_t CoordY{}; CoordY < Field.SIZE; CoordY++)
		{
			Field.ppField[CoordX][CoordY] = EMPTY;
		}
	}
	if (getRandomNum(RandMin, RandMax) > RandHalf)
	{
		Field.Human = CROSS;
		Field.ArtInt = ZERO;
		Field.Turn = EVEN;
	}
	else
	{
		Field.Human = ZERO;
		Field.ArtInt = CROSS;
		Field.Turn = ODD;
	}
}
/*
* =================================================================================================================================================================
* ------------------------------------------------------Функция для удаления динамического массива поля игры-------------------------------------------------------
* =================================================================================================================================================================
*/
void DeInitField(TiTaToField& Field) 
{
	for (size_t Index{}; Index < Field.SIZE; Index++)
	{
		delete[] Field.ppField[Index];
	}
	delete[] Field.ppField;
	Field.ppField = nullptr;
}
/*
* =================================================================================================================================================================
* -------------------------------------------------------Функция для отображения игрового поля на экране-----------------------------------------------------------
* =================================================================================================================================================================
*/
void PrintField(const TiTaToField& Field) 
{
	std::cout << std::endl << "       ";
	for (size_t CoordY{}; CoordY < Field.SIZE; CoordY++)
	{
		std::cout << "   " << CoordY + ODD;
	}
	std::cout << std::endl;
	std::cout << "        -------------" << std::endl;
	for (size_t CoordX{}; CoordX < Field.SIZE; CoordX++)
	{
		std::cout << "      " << CoordX + ODD << " | ";
		for (size_t CoordY{}; CoordY < Field.SIZE; CoordY++)
		{
			std::cout << static_cast<char>(Field.ppField[CoordX][CoordY]) << " | ";
		}
		std::cout << std::endl;
		std::cout << "        -------------" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "   Human playing with: " << static_cast<char>(Field.Human) << std::endl;
	std::cout << "      AI playing with: " << static_cast<char>(Field.ArtInt) << std::endl;
}
/*
* =================================================================================================================================================================
* -------------------------------------------------------------------Функция для очистки экрана--------------------------------------------------------------------
* =================================================================================================================================================================
*/
void ClearScreen() 
{
	system("cls");
}
/*
* =================================================================================================================================================================
* ---------------------------------------------Функция ввода координат от пользователя для совершения хода---------------------------------------------------------
* =================================================================================================================================================================
*/
TiTaToCoordinats getHumanCoordinats(TiTaToField& Field) 
{
	TiTaToCoordinats Coords;
	do
	{
		while (true)
		{
			std::cout << "Pls enter coordinat X: ";
			std::cin >> Coords.CoordX;
			if (std::cin.fail() || Coords.CoordX == EVEN || Coords.CoordX > FieldSize)
			{
				std::cin.clear();
				std::cin.ignore(BuffErazer, '\n');
				std::cout << "Error! Pls enter a valid coordinat!" << std::endl;
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			std::cout << "Pls enter coordinat Y: ";
			std::cin >> Coords.CoordY;
			if (std::cin.fail() || Coords.CoordY == EVEN || Coords.CoordY > FieldSize)
			{
				std::cin.clear();
				std::cin.ignore(BuffErazer, '\n');
				std::cout << "Error! Pls enter a valid coordinat!" << std::endl;
			}
			else
			{
				break;
			}
		}
		if (Field.ppField[Coords.CoordX - MachineLogic][Coords.CoordY - MachineLogic] != EMPTY)
		{
			std::cout << "Error! Choosen field cell is not EMPTY!" << std::endl;
		}
	} while (Field.ppField[Coords.CoordX - MachineLogic][Coords.CoordY - MachineLogic] != EMPTY);
	Coords.CoordX--;
	Coords.CoordY--;
	return Coords;
}
/*
* =================================================================================================================================================================
* -----------------------------------------------------------Функция логики ходов компьютера-----------------------------------------------------------------------
* =================================================================================================================================================================
*/
TiTaToCoordinats getArtIntCoordinats(TiTaToField& Field) 
{
	// компьютер будет искать выиграшную для себя ситуацию
	for (size_t CoordX = 0; CoordX < Field.SIZE; CoordX++)
	{
		for (size_t CoordY = 0; CoordY < Field.SIZE; CoordY++)
		{
			if (Field.ppField[CoordX][CoordY] == EMPTY)
			{
				Field.ppField[CoordX][CoordY] = Field.ArtInt;
				if (WhosWon(Field) == ArtIntWon)
				{
					Field.ppField[CoordX][CoordY] = EMPTY;
					return { CoordX,CoordY };
				}
				else
				{
					Field.ppField[CoordX][CoordY] = EMPTY;
				}
			}
		}
	}

	// компьютер будет мешать игроку выиграть
	for (size_t CoordX = 0; CoordX < Field.SIZE; CoordX++)
	{
		for (size_t CoordY = 0; CoordY < Field.SIZE; CoordY++)
		{
			if (Field.ppField[CoordX][CoordY] == EMPTY)
			{
				Field.ppField[CoordX][CoordY] = Field.Human;
				if (WhosWon(Field) == HumanWon)
				{
					Field.ppField[CoordX][CoordY] = EMPTY;
					return { CoordX,CoordY };
				}
				else
				{
					Field.ppField[CoordX][CoordY] = EMPTY;
				}
			}
		}
	}

	// ход компьютера в центр поля
	if (Field.ppField[FieldONE][FieldONE] == EMPTY)
	{
		return{ FieldONE,FieldONE };
	}

	// ход компьютера по углам поля
	TiTaToCoordinats FieldArray[CornerFour]{};
	size_t CornerIndex = FieldZERO;
	if (Field.ppField[FieldZERO][FieldZERO] == EMPTY)
	{
		FieldArray[CornerIndex++] = { FieldZERO,FieldZERO };
	}
	if (Field.ppField[FieldTWO][FieldTWO] == EMPTY)
	{
		FieldArray[CornerIndex++] = { FieldTWO,FieldTWO };
	}
	if (Field.ppField[FieldTWO][FieldZERO] == EMPTY)
	{
		FieldArray[CornerIndex++] = { FieldTWO,FieldZERO };
	}
	if (Field.ppField[FieldZERO][FieldTWO] == EMPTY)
	{
		FieldArray[CornerIndex++] = { FieldZERO,FieldTWO };
	}
	if (CornerIndex > EVEN)
	{
		size_t Index = getRandomNum(RandMin, RandMax) % CornerIndex;
		return FieldArray[Index];
	}

	// ход компьютера не в углы поля
	size_t FieldIndex = FieldZERO;
	if (Field.ppField[FieldZERO][FieldONE] == EMPTY)
	{
		FieldArray[FieldIndex++] = { FieldZERO,FieldONE };
	}
	if (Field.ppField[FieldONE][FieldZERO] == EMPTY)
	{
		FieldArray[FieldIndex++] = { FieldONE,FieldZERO };
	}
	if (Field.ppField[FieldONE][FieldTWO] == EMPTY)
	{
		FieldArray[FieldIndex++] = { FieldONE,FieldTWO };
	}
	if (Field.ppField[FieldTWO][FieldONE] == EMPTY)
	{
		FieldArray[FieldIndex++] = { FieldTWO,FieldONE };
	}
	if (FieldIndex > EVEN)
	{
		size_t Index = getRandomNum(RandMin, RandMax) % FieldIndex;
		return FieldArray[Index];
	}
	return { FieldONE,FieldONE };
}
/*
* =================================================================================================================================================================
* -----------------------------------------------------------Функция определения победителя------------------------------------------------------------------------
* =================================================================================================================================================================
*/
TiTaToProgress WhosWon(const TiTaToField& Field) 
{
	// поиск выигрыша в строках
	for (size_t CoordX = FieldZERO; CoordX < Field.SIZE; CoordX++)
	{
		if (Field.ppField[CoordX][FieldZERO] == Field.ppField[CoordX][FieldONE] && Field.ppField[CoordX][FieldZERO] == Field.ppField[CoordX][FieldTWO])
		{
			if (Field.ppField[CoordX][FieldZERO] == Field.ArtInt)
			{
				return ArtIntWon;
			}
			else if (Field.ppField[CoordX][FieldZERO] == Field.Human)
			{
				return HumanWon;
			}
		}
	}

	// поиск выигрыша в столбцах
	for (size_t CoordY = FieldZERO; CoordY < Field.SIZE; CoordY++)
	{
		if (Field.ppField[FieldZERO][CoordY] == Field.ppField[FieldONE][CoordY] && Field.ppField[FieldZERO][CoordY] == Field.ppField[FieldTWO][CoordY])
		{
			if (Field.ppField[FieldZERO][CoordY] == Field.ArtInt)
			{
				return ArtIntWon;
			}
			else if (Field.ppField[FieldZERO][CoordY] == Field.Human)
			{
				return HumanWon;
			}
		}
	}

	// поиск по диагоналям
	if (Field.ppField[FieldZERO][FieldZERO] == Field.ppField[FieldONE][FieldONE] && Field.ppField[FieldZERO][FieldZERO] == Field.ppField[FieldTWO][FieldTWO])
	{
		if (Field.ppField[FieldZERO][FieldZERO] == Field.ArtInt)
		{
			return ArtIntWon;
		}
		else if (Field.ppField[FieldZERO][FieldZERO] == Field.Human)
		{
			return HumanWon;
		}
	}
	if (Field.ppField[FieldZERO][FieldTWO] == Field.ppField[FieldONE][FieldONE] && Field.ppField[FieldZERO][FieldTWO] == Field.ppField[FieldTWO][FieldZERO])
	{
		if (Field.ppField[FieldZERO][FieldTWO] == Field.ArtInt)
		{
			return ArtIntWon;
		}
		else if (Field.ppField[FieldZERO][FieldTWO] == Field.Human)
		{
			return HumanWon;
		}
	}

	// определяем ничью, через поиск пустых клеток
	bool draw = true;
	{
		size_t Index{};
		for (size_t CoordX = FieldZERO; CoordX < Field.SIZE; CoordX++)
		{
			for (size_t CoordY = FieldZERO; CoordY < Field.SIZE; CoordY++)
				if (Field.ppField[CoordX][CoordY] == EMPTY)
				{
					draw = false;
					break;
				}
			if (!draw)
			{
				break;
			}
		}
		if (draw)
		{
			return Draw;
		}
		else
		{
			return InProgress;
		}
	}
	return InProgress;
}
/*
* =================================================================================================================================================================
* --------------------------------------------------------Функция для поздравления победителя----------------------------------------------------------------------
* =================================================================================================================================================================
*/
void Congratulations(TiTaToProgress Progress) 
{
	std::cout << std::endl << "   Result is ..." << std::endl;
	if (Progress == HumanWon)
	{
		std::cout << "   Congratulations player! You WON!" << std::endl;
	}
	else if (Progress == ArtIntWon)
	{
		std::cout << "   Too BAD! Computer WON!" << std::endl;
	}
	else if (Progress == Draw)
	{
		std::cout << "   It's a DRAW!" << std::endl;
	}
}
/*
* =================================================================================================================================================================
* ---------------------------------------------------------Функция для игры в крестики нолики----------------------------------------------------------------------
* =================================================================================================================================================================
*/
void PlayingGame(TiTaToField& Field) 
{
	char Choose{};
	do
	{
		while (true)
		{
			std::cout << "Press key 'e' to close the game, else press key 'c' to continue: ";
			std::cin >> Choose;
			if (std::cin.fail() || Choose != 'c' && Choose != 'e')
			{
				std::cin.clear();
				std::cin.ignore(BuffErazer, '\n');
				std::cout << "Error! Wrong input!" << std::endl;
			}
			else
			{
				break;
			}
		}
		if (Choose == 'c')
		{
			InitField(Field);
			ClearScreen();
			PrintField(Field);
			do
			{
				if (Field.Turn % DOUBLE == EVEN) // если ход четный
				{
					//ходит человек
					TiTaToCoordinats Coords = getHumanCoordinats(Field);
					Field.ppField[Coords.CoordX][Coords.CoordY] = Field.Human;
				}
				else
				{
					// ходит компьютер
					TiTaToCoordinats Coords = getArtIntCoordinats(Field);
					Field.ppField[Coords.CoordX][Coords.CoordY] = Field.ArtInt;
				}
				Field.Turn++;
				ClearScreen();
				PrintField(Field);
				Field.GameProgress = WhosWon(Field);
			} while (Field.GameProgress == InProgress);
			Congratulations(Field.GameProgress);
			DeInitField(Field);
		}
	} while (Choose != 'e');
}