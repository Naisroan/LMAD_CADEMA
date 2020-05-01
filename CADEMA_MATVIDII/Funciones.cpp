#include "Funciones.h"

float Funciones::PI = 3.14159265359;

void Funciones::gotoxy(int x, int y) 
{
	HANDLE hcon;
	COORD dwPos;

	hcon = GetStdHandle(STD_OUTPUT_HANDLE);

	dwPos.X = x;
	dwPos.Y = y;

	SetConsoleCursorPosition(hcon, dwPos);
}

int Funciones::GetNumber(const char* message)
{
	bool isNumber = true;
	int number = -1;
	char* strNumber = new char[15];
	char* aux;

	do
	{
		std::cout << message;
		std::cin >> strNumber;

		aux = strNumber;

		while (*aux != '\0')
		{
			if (*aux != '-' && !isdigit(*aux))
			{
				isNumber = false;
				std::cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
				std::cout << "\nNumero no valido, intente de nuevo...";
				std::cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n";
				break;
			}
			else
				isNumber = true;

			aux++;
		}

	} while (!isNumber);

	number = atoi(strNumber);
	delete[] strNumber;

	return number;
}

float Funciones::GetNumberFloat(const char* message)
{
	float numero = 0.0;
	bool repetir = false;

	do
	{
		try
		{
			char* strExpression = new char[50];

			std::cout << message;
			std::cin >> strExpression;

			if (!Funciones::IsFraction(strExpression))
			{
				if (!IsValidNumber(strExpression))
				{
					delete[] strExpression;
					throw "EXPRESION INVALIDA";
				}
				else
				{
					numero = atof(strExpression);
					repetir = false;
				}
			}
			else
			{
				numero = GetNumberFromFraction(strExpression);
				repetir = false;
			}

			delete[] strExpression;
		}
		catch (const char* ex)
		{
			if (strcmp(ex, "EXPRESION INVALIDA") == 0)
			{
				std::cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
				std::cout << "\nExpresion/numero no valido, intente de nuevo...";
				std::cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n";
			}
			else
			{
				std::cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
				std::cout << "\nHa ocurrido un error, intente de nuevo...";
				std::cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n";
			}

			repetir = true;
		}
	} while (repetir);

	return numero;
}

float Funciones::GetNumberFromFraction(const char* strFraction)
{
	if (!IsStrValidNumbersOperations(strFraction))
		throw "EXPRESION INVALIDA";

	char strPrimerNumero[50] = "";
	char strSegundoNumero[50] = "";

	float primerNumero = 0;
	float segundoNumero = 0;

	while (*strFraction != '/' && *strFraction != '\\')
	{
		char* charActual = new char[2];

		charActual[0] = *strFraction;
		charActual[1] = '\0';

		strcat_s(strPrimerNumero, charActual);

		delete[] charActual;

		strFraction++;
	}

	strFraction++;

	while (*strFraction != '\0')
	{
		char* charActual = new char[2];

		charActual[0] = *strFraction;
		charActual[1] = '\0';

		strcat_s(strSegundoNumero, charActual);

		delete[] charActual;

		strFraction++;
	}

	primerNumero = atof(strPrimerNumero);
	segundoNumero = atof(strSegundoNumero);

	return primerNumero / segundoNumero;
}

bool Funciones::IsFraction(const char* str)
{
	if (!IsStrValidNumbersOperations(str))
		throw "EXPRESION INVALIDA";

	while (*str != '\0')
	{
		if (*str == '/' || *str == '\\')
		{
			return true;
		}

		str++;
	}

	return false;
}

bool Funciones::IsStrValidNumbersOperations(const char* str)
{
	char charsValids[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '-', '/', '\\', '+' };

	while (*str != '\0')
	{
		char charActual = *str;
		bool isValidChar = false;

		for (int i = 0; i < sizeof(charsValids); i++)
		{
			if (charActual == charsValids[i])
			{
				isValidChar = true;
				break;
			}
		}

		if (!isValidChar)
			return false;

		str++;
	}

	return true;
}

bool Funciones::IsValidNumber(const char* strNumber)
{
	char charAnterior;

	while (*strNumber != '\0')
	{
		if (*strNumber != '-' && *strNumber != '.' && !isdigit(*strNumber))
		{
			return false;
		}

		strNumber++;
	}

	return true;
}