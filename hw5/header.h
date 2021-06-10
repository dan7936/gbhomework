#include <iostream>
#pragma once
enum VariousCondition { ZERO = 0, ONE = 1, START = 1, ZERtoONEinit = -98, BuffErazer = 35476};
const size_t ArrSize1 = 10;
const size_t ArrSize2 = 8;
const int T4LimitMax = 10;
const int T4LimitMin = -10;

void ArrayInit(double* Arr, const size_t ArrSize, int RandCond=ZERO);
void ArrayInit(int* Arr, const size_t ArrSize, int RandCond=ZERO);
void PrintArray(double Arr[], size_t ArrSize);
void PrintArray(int Arr[], size_t ArrSize);
void ChangeArray(int* Arr, size_t ArrSize);
void ArrayInitT3(int* Arr, size_t ArrSize);
void ReadInput(int* Change);
void ArrayShift(int* Arr, size_t ArrSize, int Change);

