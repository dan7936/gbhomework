#pragma once

//==========================================Объявляем структуры для функций=======================================================

enum SomeCondition { EVEN = 0, ODD = 1, DOUBLE = 2, FieldSize = 3, BuffErazer = 32750, MachineLogic = 1 }; // массив значений для устранения в коде MagicNumbers

enum FieldCoords {FieldZERO=0, FieldONE=1, FieldTWO=2}; // массив для хранения нумерации клеток поля от 0 до 2

enum RandomizerCond {RandMin=0, RandMax=1000, RandHalf=500}; // условия для генератора случайных чисел

enum FieldCorners { CornerOne = 1, CornerTwo = 2, CornerThree = 3, CornerFour = 4 }; // массив перечисления углов на игровом поле

enum TicTacToeChars { CROSS = 'X', ZERO = 'O', EMPTY = ' ' }; // пользовательский массив с исползуемыми на поле символами

struct TiTaToCoordinats { size_t CoordX; size_t CoordY; }; // структура с координатами

enum TiTaToProgress { InProgress, HumanWon, ArtIntWon, Draw }; // пользовательский массив для контроля состояния игры

#pragma pack(push, 1)
struct TiTaToField // структура поля
{
	TicTacToeChars** ppField = nullptr; // объявляем указатель для создания двухмерного динамического массива
	const size_t SIZE{ FieldSize }; // константный размер для массива поля
	TicTacToeChars Human = EMPTY; // чем будет ходить человек
	TicTacToeChars ArtInt = EMPTY; // чем будет ходить компьютер
	size_t Turn{}; // чей ход
	TiTaToProgress GameProgress = InProgress; // текущее состояние игры
};
#pragma pack (pop)