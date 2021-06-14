#include "header.h"

// ќбъ€вл€ю функцию дл€ инициализации массива дл€ 1го задани€
void InitArray(int * pArr, const int INDEX)
{
	int a=TWO, b=ZERO;
	for (int Index = ZERO; Index < INDEX; ++Index)
	{
		pArr[Index] = pow(a,b);
		++b;
	}
}

// ќбъ€вл€ю функцию дл€ инициализации массива дл€ 2го задани€
void InitArray(int** pArr, const size_t Row, const size_t Col) 
{
	srand(time(NULL));
	for (size_t IndexRow = ZERO; IndexRow < Row; ++IndexRow)
	{
		for (size_t IndexCol = ZERO; IndexCol < Col; ++IndexCol)
		{
			pArr[IndexRow][IndexCol] = rand() % 100;
		}
	}
}

// ќбъ€вл€ю функцию дл€ распечатывани€ массива дл€ 1го задани€
void PrintArray(int* pArr, const int INDEX) 
{
	for (int Index = ZERO; Index < INDEX; ++Index)
	{
		std::cout << pArr[Index] << " ";
	}
	std::cout << std::endl;
}

// ќбъ€вл€ю функцию дл€ распечатывани€ массива дл€ 2го задани€
void PrintArray(int** pArr, const size_t Row, const size_t Col)
{
	for (size_t IndexRow = ZERO; IndexRow < Row; ++IndexRow)
	{
		for (size_t IndexCol = ZERO; IndexCol < Col; ++IndexCol)
		{
			std::cout << pArr[IndexRow][IndexCol] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// ќбъ€вл€ю функцию дл€ создани€ массива дл€ 1го задани€
void MakeDynamicArray(int *pT1Arr, int INDEX)
{
	pT1Arr = new (std::nothrow) int [INDEX];
	if (pT1Arr != nullptr)
	{
		InitArray(pT1Arr, INDEX);
		PrintArray(pT1Arr, INDEX);
		delete[] pT1Arr;
		pT1Arr = nullptr;
	}
	else
	{
		std::cout << "Error! Can not allocate memory!" << std::endl;
	}
}

// ќбъ€вл€ю функцию дл€ создани€ массива дл€ 2го задани€
void MakeDynamicArray(int** pT2Arr, const int T2ArrSize) 
{
	const size_t Row = T2ArrSize;
	const size_t Col = T2ArrSize;
	pT2Arr = new int* [Row];
	for (size_t Index = 0; Index < Row; ++Index)
	{
		pT2Arr[Index] = new int[Col];
	}
	InitArray(pT2Arr, Row, Col);
	PrintArray(pT2Arr, Row, Col);
	for (size_t Index = 0; Index < Row; ++Index)
	{
		delete[] pT2Arr[Index];
	}
	delete[] pT2Arr;
	pT2Arr = nullptr;
}

// ќбъ€вл€ю функцию дл€ считывани€ консольного ввода
void ConsoleInput(int *INDEX)
{
	while (true)
	{
		std::cin >> *INDEX;
		if (std::cin.fail() || *INDEX < 1)
		{
			std::cin.clear();
			std::cin.ignore(iBufErazer, '\n');
			std::cout << "Error! Pls, enter a valid input!" << std::endl;
		}
		else
		{
			std::cin.ignore(iBufErazer, '\n');
			break;
		}
	}
}

// ќбъ€вл€ю функцию дл€ считывани€ консольного ввода типа string
void ConsoleInput(std::string * Name)
{
	while (true)
	{
		std::getline(std::cin, * Name);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(iBufErazer, '\n');
			std::cout << "Error! Pls, enter a valid input!" << std::endl;
		}
		else
		{
			break;
		}
	}
}

// ќбъ€вл€ю функцию дл€ записи текста в файл
void CreateTextFile(std::string * pFileName)
{
	std::ofstream fout(* pFileName += ".txt");
	std::cout << "Text file name: " << * pFileName << " succesfully created!" << std::endl;
	std::cout << "Pls, enter some data to write in our txt file: ";
	std::string FileData;
	std::string* pFileData = &FileData;
	ConsoleInput(pFileData);
	fout << FileData << std::endl;
	fout.close();
}

// ќбъ€вл€ю функцию дл€ записи текстов из 2х файлов в 3й файл
void CreateTextFile(std::string* pFileName3, std::string FileName1, std::string FileName2)
{
	std::ofstream fout3(*pFileName3 += ".txt");
	std::cout << "Text file name: " << *pFileName3 << " succesfully created!" << std::endl;
	std::string FileData;
	std::ifstream fin1(FileName1);
	while(std::getline(fin1, FileData))
	fout3 << FileData << std::endl;
	fin1.close();
	std::ifstream fin2(FileName2);
	while (std::getline(fin2, FileData))
	fout3 << FileData << std::endl;
	fin2.close();
	fout3.close();
}

// объ€вл€ю функцию дл€ поиска ключевого слова
void FileSearch(std::string* pFileName3, std::string KeyWord)
{
	std::ifstream fin3(*pFileName3);
	std::string FileData;
	int index = ONE;
	while (!fin3.eof())
	{
		std::getline(fin3, FileData);
		if (FileData.find(KeyWord) != std::string::npos)
		{
			std::cout << "We find " << KeyWord << std::endl;
			++index;
		}
		else
		{
			std::cout << "In " << index << " row!" << "We can't find your keyword!" << std::endl;
			++index;
		}
	}
}