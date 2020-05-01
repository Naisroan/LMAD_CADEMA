#pragma once
#ifndef _FUNCIONES_
#define _FUNCIONES_

#include <Windows.h>
#include <iostream>
#include <string>
#include <ctype.h>

class Funciones
{

private:

public:

	static float PI;

	static void gotoxy(int, int);

	static int GetNumber(const char*);

	static float GetNumberFloat(const char*);

	static float GetNumberFromFraction(const char*);

	static bool IsFraction(const char*);

	static bool IsStrValidNumbersOperations(const char*);

	static bool IsValidNumber(const char*);
};

#endif