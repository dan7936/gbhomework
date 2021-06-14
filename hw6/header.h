#include <iostream>
#include <string>
#include <cmath>
#include <string>
#include <fstream>
#pragma once

const int iBufErazer = 32750;
enum SomeCondition{ZERO=0, ONE=1, TWO=2, T2ArrSize=4};

void ConsoleInput(int* INDEX);
void InitArray(int* pArr, int INDEX);
void PrintArray(int* pArr, const int INDEX);
void MakeDynamicArray(int* pT1Arr, int INDEX);
void InitArray(int** pArr, const size_t Row, const size_t Col);
void PrintArray(int** pArr, const size_t Row, const size_t Col);
void MakeDynamicArray(int** pT2Arr, const int T2ArrSize);
void ConsoleInput(std::string* Name);
void CreateTextFile(std::string* pFileName);
void CreateTextFile(std::string* pFileName3, std::string FileName1, std::string FileName2);
void FileSearch(std::string* pFileName3, std::string KeyWord);
