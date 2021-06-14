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
	* Выделить в памяти динамический одномерный массив типа int. Размер массива запросить у пользователя. 
	* Инициализировать его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 … Вывести массив на экран. 
	* Не забыть освободить память. =) Разбить программу на функции.
	*/
	std::cout << "---------------Task 1---------------" << std::endl;
	std::cout << "Pls, enter an integer for Array creation: ";
	ConsoleInput(pIndex);
	MakeDynamicArray(pT1Arr, INDEX);
	/*
	* Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными числами через функцию rand.
	* Вывести на экран. Разбейте вашу программу на функции которые вызываются из main.
	*/
	std::cout << "---------------Task 2---------------" << std::endl;
	MakeDynamicArray(pT2Arr, T2ArrSize);
	/*
	* Написать программу c 2-я функциями, которая создаст два текстовых файла (*.txt), примерно по 50-100 символов 
	* в каждом (особого значения не имеет с каким именно содержимым). Имена файлов запросить у польлзователя.
	*/
	std::cout << "---------------Task 3---------------" << std::endl;
	std::cout << "Pls, enter file name for creation of first txt file: ";
	ConsoleInput(pFileName1);
	CreateTextFile(pFileName1);
	std::cout << "Pls, enter file name for creation of second txt file: ";
	ConsoleInput(pFileName2);
	CreateTextFile(pFileName2);
	/*
	* "*" Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя файлов спросить у пользователя).
	*/
	std::cout << "---------------Task 4---------------" << std::endl;
	std::cout << "Pls, enter file name for creation of third txt file: ";
	ConsoleInput(pFileName3);
	CreateTextFile(pFileName3, FileName1, FileName2);
	/*
	* "*" Написать программу, которая проверяет присутствует ли указанное пользователем 
	* при запуске программы слово в указанном пользователем файле (для простоты работаем только с латиницей).
	*/
	std::cout << "---------------Task 5---------------" << std::endl;
	std::cout << "Pls, enter a word what you'll be searching in your third txt file: ";
	ConsoleInput(pKeyWord);
	FileSearch(pFileName3, KeyWord);
	return 0;
}
