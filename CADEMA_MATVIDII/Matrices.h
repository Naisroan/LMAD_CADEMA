#pragma once
#ifndef _MATRICES_
#define _MATRICES_

#include "Funciones.h"
#include <iostream>
#include <math.h>

using namespace std;

class Matrices
{

public:

	static float** MR;
	static float MCR[3];

	static void Suma(float**, float**, int, int);
	static void Resta(float**, float**, int, int);
	static void Multiplicacion(float**, float**, int, int, int);
	static void Cuaternios(float, float*, float*);
	static void TraslacionPunto(float*, float[4][4]);
	static void RotacionPunto(float, int, float[4][4]);
	static void EscalamientoPunto(float*, float[4][4]);

};

#endif

