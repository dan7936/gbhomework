#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#define COMPARISON(Integer) ((Integer) >= Zero && (Integer) < OneHund ? std::cout << "TRUE" << std::endl : std::cout << "FALSE" << std::endl)
#define SWAP(Int1, Int2) int Int3=Int1; Int1=Int2; Int2=Int3;
#define dArrSize 6

enum VariousConditions{T1ASize=30, Zero=0, One=1, OneHund=100, TwoHund=200, BufErazer=32750};
namespace MyFunc
{
	void InitArray(float* Array, int ArraySize);
	void InitArray(int* Array, int ArraySize);
	void PrintArray(float* Array, int ArraySize);
	void PrintArray(int* Array, int ArraySize);
	void SumArray(float* Array, int ArraySize);
	void ConsoleInput(int* Integer);
	int ConsoleInput();
	void SortArray(int* Array, int ArraySize);
}