#include "header.h"

double T1Array[ArrSize1]{}; // объ€вл€ем массива дл€ 1-го задани€
int T2Array[ArrSize1]{}; // объ€вл€ем массив дл€ 2-го задани€
int T3Array[ArrSize2]{}; // объ€вл€ем массив дл€ 3-го задани€
int T4Array[ArrSize1]{}; // объ€вл€ем массив дл€ 4-го задани€
int Change{}; // объ€вл€ем переменную которую будем считывать дл€ 4го задани€
int* Change1 = &Change; // объ€вл€ем указатель на нее


int main()
{
	// 1-e задание
	std::cout << "----------Task 1----------" << std::endl;
	ArrayInit(T1Array, ArrSize1);
	PrintArray(T1Array, ArrSize1);
	// 2-е задание
	std::cout << "----------Task 2----------" << std::endl;
	ArrayInit(T2Array, ArrSize1, ZERtoONEinit);
	PrintArray(T2Array, ArrSize1);
	ChangeArray(T2Array, ArrSize1);
	PrintArray(T2Array, ArrSize1);
	// 3-е задание
	std::cout << "----------Task 3----------" << std::endl;
	ArrayInitT3(T3Array, ArrSize2);
	PrintArray(T3Array, ArrSize2);
	// 4-е задание
	std::cout << "----------Task 4----------" << std::endl;
	ArrayInit(T4Array, ArrSize1);
	PrintArray(T4Array, ArrSize1);
	ReadInput(Change1);
	ArrayShift(T4Array, ArrSize1, *Change1);
	return 0;
}


