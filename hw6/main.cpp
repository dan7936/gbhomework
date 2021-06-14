#include "header.h"

int * pT1Arr;
int INDEX{};
int* pIndex = &INDEX;
int** pT2Arr;
std::string FileName1;
std::string* pFileName1 = &FileName1;
std::string FileName2;
std::string* pFileName2 = &FileName2;
std::string FileName3;
std::string* pFileName3 = &FileName3;
std::string KeyWord;
std::string* pKeyWord = &KeyWord;

int main()
{
	/*
	* �������� � ������ ������������ ���������� ������ ���� int. ������ ������� ��������� � ������������. 
	* ���������������� ��� ������� ��������� ������: 1, 2, 4, 8, 16, 32, 64, 128 � ������� ������ �� �����. 
	* �� ������ ���������� ������. =) ������� ��������� �� �������.
	*/
	std::cout << "---------------Task 1---------------" << std::endl;
	std::cout << "Pls, enter an integer for Array creation: ";
	ConsoleInput(pIndex);
	MakeDynamicArray(pT1Arr, INDEX);
	/*
	* ����������� �������� ������� 4�4 ���� int. ���������������� �� ���������������� ������� ����� ������� rand.
	* ������� �� �����. �������� ���� ��������� �� ������� ������� ���������� �� main.
	*/
	std::cout << "---------------Task 2---------------" << std::endl;
	MakeDynamicArray(pT2Arr, T2ArrSize);
	/*
	* �������� ��������� c 2-� ���������, ������� ������� ��� ��������� ����� (*.txt), �������� �� 50-100 �������� 
	* � ������ (������� �������� �� ����� � ����� ������ ����������). ����� ������ ��������� � �������������.
	*/
	std::cout << "---------------Task 3---------------" << std::endl;
	std::cout << "Pls, enter file name for creation of first txt file: ";
	ConsoleInput(pFileName1);
	CreateTextFile(pFileName1);
	std::cout << "Pls, enter file name for creation of second txt file: ";
	ConsoleInput(pFileName2);
	CreateTextFile(pFileName2);
	/*
	* "*" �������� �������, ������������� ��� ����� � ������ ��������� ���� (��� ������ �������� � ������������).
	*/
	std::cout << "---------------Task 4---------------" << std::endl;
	std::cout << "Pls, enter file name for creation of third txt file: ";
	ConsoleInput(pFileName3);
	CreateTextFile(pFileName3, FileName1, FileName2);
	/*
	* "*" �������� ���������, ������� ��������� ������������ �� ��������� ������������� 
	* ��� ������� ��������� ����� � ��������� ������������� ����� (��� �������� �������� ������ � ���������).
	*/
	std::cout << "---------------Task 5---------------" << std::endl;
	std::cout << "Pls, enter a word what you'll be searching in your third txt file: ";
	ConsoleInput(pKeyWord);
	FileSearch(pFileName3, KeyWord);
	return 0;
}
