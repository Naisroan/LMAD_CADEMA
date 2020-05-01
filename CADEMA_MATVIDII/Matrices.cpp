#include "Matrices.h"

float** Matrices::MR;
float Matrices::MCR[3] = { 0, 0, 0 };

void Matrices::Suma(float** M1, float** M2, int filas, int columnas)
{
	MR = new float* [filas];

	for (int i = 0; i < filas; i++)
		MR[i] = new float[columnas];

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
			MR[i][j] = M1[i][j] + M2[i][j];
	}
}

void Matrices::Resta(float** M1, float** M2, int filas, int columnas)
{
	MR = new float* [filas];

	for (int i = 0; i < filas; i++)
		MR[i] = new float[columnas];

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
			MR[i][j] = M1[i][j] - M2[i][j];
	}
}

void Matrices::Multiplicacion(float** M1, float** M2, int filas, int columnas, int columnas2)
{
	MR = new float* [filas];

	for (int i = 0; i < filas; i++)
		MR[i] = new float[columnas];

	for (int a = 0; a < filas; a++)
	{
		for (int b = 0; b < columnas2; b++)
		{
			MR[a][b] = 0;
			for (int k = 0; k < columnas; k++)
				MR[a][b] = MR[a][b] + M1[a][k] * M2[k][b];
		}
	}
}

void Matrices::Cuaternios(float angulo, float* v, float* p) 
{
	float MC[4][4];
	float rad = angulo * Funciones::PI / 180;
	float cosrad = cos(rad / 2);
	float sinrad = sin(rad / 2);
	float s = cosrad;
	float modulo = sqrt(pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2));
	float a = (v[0] / modulo) * sinrad;
	float b = (v[1] / modulo) * sinrad;
	float c = (v[2] / modulo) * sinrad;

	for (int n = 0; n < 3; n++)
	{
		MCR[n] = 0;
	}

	MC[0][0] = (1 - 2 * (pow(b, 2)) - 2 * (pow(c, 2)));
	MC[0][1] = (2 * a * b - 2 * s * c);
	MC[0][2] = (2 * a * c + 2 * s * b);
	MC[0][3] = 0;

	MC[1][0] = (2 * a * b + 2 * s * c);
	MC[1][1] = (1 - 2 * (pow(a, 2)) - 2 * (pow(c, 2)));
	MC[1][2] = (2 * b * c - 2 * s * a);
	MC[1][3] = 0;

	MC[2][0] = (2 * a * c - 2 * s * b);
	MC[2][1] = (2 * b * c + 2 * s * a);
	MC[2][2] = (1 - 2 * (pow(a, 2)) - 2 * (pow(b, 2)));
	MC[2][3] = 0;

	MC[3][0] = 0;
	MC[3][1] = 0;
	MC[3][2] = 0;
	MC[3][3] = 1;

	cout << "Matriz de Cuaterniones Generada:\n\n";

	for (int j = 0; j < 4; j++) 
	{
		for (int l = 0; l < 4; l++)
		{
			printf("%-15.4f ", MC[j][l]);
		}

		cout << endl;
	}

	for (int i = 0; i < 3; i++)
		for (int k = 0; k < 3; k++)
			MCR[i] = (MCR[i] + MC[i][k] * p[k]);
}

void Matrices::TraslacionPunto(float* p, float m[4][4]) 
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			if (i == j)
				m[j][i] = 1;
			else if (i == 3)
				m[j][i] = p[j];
			else m[j][i] = 0;
		}
}

void Matrices::RotacionPunto(float angulo, int eje, float m[4][4]) 
{
	float rad = angulo * Funciones::PI / 180;
	float cosrad = cos(rad);
	float sinrad = sin(rad);

	if (eje == 1) 
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (i == j) {
					m[j][i] = 1;
					if ((i == 1 && j == 1) || (i == 2 && j == 2)) m[j][i] = cosrad;
				}
				else if (i == 1 && j == 2) m[j][i] = sinrad;
				else if (i == 2 && j == 1) m[j][i] = -1 * sinrad;
				else m[j][i] = 0;

	}
	if (eje == 2) 
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				if (i == j) {
					m[j][i] = 1;
					if ((i == 0 && j == 0) || (i == 2 && j == 2)) m[j][i] = cosrad;
				}
				else if (i == 2 && j == 0)
				{
					m[j][i] = sinrad;
				}
				else if (i == 0 && j == 2) {
					m[j][i] = -sinrad;
				}
				else {
					m[j][i] = 0;
				}
			}

	}
	if (eje == 3) 
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) 
			{
				if (i == j) 
				{
					m[i][j] = 1;

					if ((i == 0 && j == 0) || (i == 1 && j == 1)) 
						m[i][j] = cosrad;
				}
				else if (i == 0 && j == 1) 
				{
					m[i][j] = -sinrad;
				}
				else if (i == 1 && j == 0) 
				{
					m[i][j] = sinrad;
				}
				else 
				{
					m[i][j] = 0;
				}
			}
		}
	}

}

void Matrices::EscalamientoPunto(float* p, float m[4][4]) 
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (i == j) {
				m[j][i] = 1;
				if (i == 0) m[j][i] = p[0];
				else if (i == 1) m[j][i] = p[1];
				else if (i == 2) m[j][i] = p[2];
			}
			else m[j][i] = 0;
}