#pragma once

//==========================================��������� ��������� ��� �������=======================================================

enum SomeCondition { EVEN = 0, ODD = 1, DOUBLE = 2, FieldSize = 3, BuffErazer = 32750, MachineLogic = 1 }; // ������ �������� ��� ���������� � ���� MagicNumbers

enum FieldCoords {FieldZERO=0, FieldONE=1, FieldTWO=2}; // ������ ��� �������� ��������� ������ ���� �� 0 �� 2

enum RandomizerCond {RandMin=0, RandMax=1000, RandHalf=500}; // ������� ��� ���������� ��������� �����

enum FieldCorners { CornerOne = 1, CornerTwo = 2, CornerThree = 3, CornerFour = 4 }; // ������ ������������ ����� �� ������� ����

enum TicTacToeChars { CROSS = 'X', ZERO = 'O', EMPTY = ' ' }; // ���������������� ������ � ������������ �� ���� ���������

struct TiTaToCoordinats { size_t CoordX; size_t CoordY; }; // ��������� � ������������

enum TiTaToProgress { InProgress, HumanWon, ArtIntWon, Draw }; // ���������������� ������ ��� �������� ��������� ����

#pragma pack(push, 1)
struct TiTaToField // ��������� ����
{
	TicTacToeChars** ppField = nullptr; // ��������� ��������� ��� �������� ����������� ������������� �������
	const size_t SIZE{ FieldSize }; // ����������� ������ ��� ������� ����
	TicTacToeChars Human = EMPTY; // ��� ����� ������ �������
	TicTacToeChars ArtInt = EMPTY; // ��� ����� ������ ���������
	size_t Turn{}; // ��� ���
	TiTaToProgress GameProgress = InProgress; // ������� ��������� ����
};
#pragma pack (pop)