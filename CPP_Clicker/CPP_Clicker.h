#pragma once
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <string>
#include <chrono>
#include <thread>

void Menu();
void Clicker();

int CPS;
std::string Hotkey;
int ClickDelay;
bool Debug = false;