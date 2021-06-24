#pragma once
#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>
#include "structs.h"

//==========================================��������� ��������� �������=============================================================

int32_t getRandomNum(int32_t min, int32_t max); // �������� ������������
void InitField(TiTaToField& Field); // �������� ������� �������� ������������� �������
void DeInitField(TiTaToField& Field); // �������� ������� �������� ������������� �������
void PrintField(const TiTaToField& Field); // �������� ������� �������������� ����
void ClearScreen(); // �������� ������� ��� ������� ������
TiTaToCoordinats getHumanCoordinats(TiTaToField& Field); // �������� ������� ��� ��������� ����������� ��������
TiTaToCoordinats getArtIntCoordinats(TiTaToField& Field); // �������� ������� ��� ��������� ����������� ����������
TiTaToProgress WhosWon(const TiTaToField& Field); // �������� ������� ��� ����������� ����������
void Congratulations(TiTaToProgress Progress); // �������� ������� ��� ������������ ����������
void PlayingGame(TiTaToField& Field); // �������� ������� ���� � �������� ������
