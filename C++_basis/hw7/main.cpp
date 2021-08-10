#include "functions.h"

float Task1fArray[T1ASize]{};
int T2Integer{};
int * pT2Integer = &T2Integer;

int main()
{
	std::cout << "-------------------Task 1-------------------" << std::endl;
	MyFunc::InitArray(Task1fArray, T1ASize);
	MyFunc::PrintArray(Task1fArray, T1ASize);
	MyFunc::SumArray(Task1fArray, T1ASize);
	std::cout << "-------------------Task 2-------------------" << std::endl;
	MyFunc::ConsoleInput(pT2Integer);
	COMPARISON(T2Integer);
	std::cout << "-------------------Task 3-------------------" << std::endl;
	int Task3iArray[dArrSize]{};
	MyFunc::InitArray(Task3iArray, dArrSize);
	std::cout << "This is your array!" << std::endl;
	MyFunc::PrintArray(Task3iArray, dArrSize);
	std::cout << "Let's sort it out!" << std::endl;
	MyFunc::SortArray(Task3iArray, dArrSize);
	MyFunc::PrintArray(Task3iArray, dArrSize);
	return 0;
}