#include "header.h"

double T1Array[ArrSize1]{}; // ��������� ������� ��� 1-�� �������
int T2Array[ArrSize1]{}; // ��������� ������ ��� 2-�� �������
int T3Array[ArrSize2]{}; // ��������� ������ ��� 3-�� �������
int T4Array[ArrSize1]{}; // ��������� ������ ��� 4-�� �������
int Change{}; // ��������� ���������� ������� ����� ��������� ��� 4�� �������
int* Change1 = &Change; // ��������� ��������� �� ���


int main()
{
	// 1-e �������
	std::cout << "----------Task 1----------" << std::endl;
	ArrayInit(T1Array, ArrSize1);
	PrintArray(T1Array, ArrSize1);
	// 2-� �������
	std::cout << "----------Task 2----------" << std::endl;
	ArrayInit(T2Array, ArrSize1, ZERtoONEinit);
	PrintArray(T2Array, ArrSize1);
	ChangeArray(T2Array, ArrSize1);
	PrintArray(T2Array, ArrSize1);
	// 3-� �������
	std::cout << "----------Task 3----------" << std::endl;
	ArrayInitT3(T3Array, ArrSize2);
	PrintArray(T3Array, ArrSize2);
	// 4-� �������
	std::cout << "----------Task 4----------" << std::endl;
	ArrayInit(T4Array, ArrSize1);
	PrintArray(T4Array, ArrSize1);
	ReadInput(Change1);
	ArrayShift(T4Array, ArrSize1, *Change1);
	return 0;
}


