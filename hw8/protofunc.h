#pragma once
#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>
#include "structs.h"

//==========================================Объявляем прототипы функции=============================================================

int32_t getRandomNum(int32_t min, int32_t max); // прототип рандомайзера
void InitField(TiTaToField& Field); // прототип функции создания динамического массива
void DeInitField(TiTaToField& Field); // прототип функции удаления динамического массива
void PrintField(const TiTaToField& Field); // прототип функции распечатывания поля
void ClearScreen(); // прототип функции для очистки экрана
TiTaToCoordinats getHumanCoordinats(TiTaToField& Field); // прототип функции для получения координатов человека
TiTaToCoordinats getArtIntCoordinats(TiTaToField& Field); // прототип функции для получения координатов компьютера
TiTaToProgress WhosWon(const TiTaToField& Field); // прототип функции для определения победителя
void Congratulations(TiTaToProgress Progress); // прототип функции для поздравления победителя
void PlayingGame(TiTaToField& Field); // прототип функции игры в крестики нолики
