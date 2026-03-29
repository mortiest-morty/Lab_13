#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include <deque>
#include <list>
#include <cctype>
#include <algorithm>
#include <numeric>

// проверка ввода
std::string getText();
int getNumber();

// Ввод и вывод контейнера "Vector"
void inputVector(std::vector<int>& V);
void outputVector(std::vector<int>& V);

// Ввод и вывод контейнера "List"
void inputList(std::list<int>& L);
void outputList(std::list<int>& L);

// Ввод и вывод контейнера "Deque"
void inputDeque(std::deque<int>& D);
void outputDeque(std::deque<int>& D);

// Задачи
void task_1();
void task_2();
void task_3();
void task_4();


#endif
