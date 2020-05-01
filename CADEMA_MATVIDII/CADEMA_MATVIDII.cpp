// --------------------------------------------------
// ENCABEZADOS
// --------------------------------------------------
#include "Funciones.h"
#include "Matrices.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>

using namespace std;

// --------------------------------------------------
// VARIABLES GLOBALES
// --------------------------------------------------
float MT[4][4];
float MT2[4][4];
float MCF[4][4];
int filas1, columnas1, filas2, columnas2;
int op = 0, op2 = 0, op3 = 0, op4 = 0;

// --------------------------------------------------
// PROTOTIPOS
// --------------------------------------------------
void Init();
void Finish();
void Operaciones();
void SumaMatrices();
void RestaMatrices();
void MultiplicacionMatrices();
void MatrizCompuesta();
void MatrizPorVector();
void Cuaterniones();
void SolicitarMatriz(float**&, float**&);

// --------------------------------------------------
// MAIN
// --------------------------------------------------
int main()
{
	// --------------------------------------------------
	Init();
	// --------------------------------------------------

	do
	{
		/*
		cout << ">> Seleccione una opcion\n\n";
		cout << "1.- Operaciones basicas con matrices\n";
		cout << "2.- Cuaterniones\n";
		cout << "3.- Matrices compuestas\n";
		cout << "4.- Salir\n\n";
		*/
		// cout << "Opcion a elegir #";

		cout << ">> Seleccione una opcion\n\n";
		cout << "1.- Suma de Matrices\n";
		cout << "2.- Resta de Matrices\n";
		cout << "3.- Multiplicacion de Matrices\n";
		cout << "4.- Matrices compuesta de un primitivo grafico segun angulos dados\n";
		cout << "5.- Matriz por Vector\n";
		cout << "6.- Generacion de nuevas coordenadas por cuaterniones\n";
		cout << "7.- Salir\n\n";

		op = Funciones::GetNumber("Opcion a elegir #");

		system("cls");

		Operaciones();

	} while (op != 7);

	delete[] Matrices::MR;

	// --------------------------------------------------
	Finish();
	// --------------------------------------------------

	return 0;
}

// --------------------------------------------------
// IMPLEMENTACIONES
// --------------------------------------------------

void Init()
{
	cout << "--------------------------------------------------------------------------------------------------------------\n";
	cout << "Calculadora de Matrices - Matematicas para Videojuegos II\n";
	cout << "--------------------------------------------------------------------------------------------------------------\n\n";

	printf_s("%10s %-10s\n", "Maestra:", "Adriana Guadalupe");
	printf_s("%10s %-10s\n", "Alumno:", "Ian Alexandro Solis Cardona");
	printf_s("%-10s %-10d\n\n", "Matricula:", 1669117);

	cout << "Presione alguna tecla para continuar...";
	system("pause>nul");
	system("cls");
}

void Finish()
{
	system("cls");
}

void Operaciones()
{
	switch (op)
	{

	case 1:
	{
		SumaMatrices();
		break;
	}

	case 2:
	{
		RestaMatrices();
		break;
	}

	case 3:
	{
		MultiplicacionMatrices();
		break;
	}

	case 4:
	{
		MatrizCompuesta();
		break;
	}

	case 5:
	{
		MatrizPorVector();
		break;
	}

	case 6:
	{
		Cuaterniones();
		break;
	}

	case 7: { return; }

	default:
	{
		cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
		cout << "\nOpcion no valida, intente de nuevo...";
		cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n";
		return;
	}

	}

	cout << "\n\nPresione cualquier tecla para regresar al menu...";
	system("pause>nul");
	system("cls");
}

void SumaMatrices()
{
	cout << ">> Suma de Matrices\n\n";

	float** M1 = 0;
	float** M2 = 0;

	SolicitarMatriz(M1, M2);

	if (filas1 == filas2 && columnas1 == columnas2)
	{
		Matrices::Suma(M1, M2, filas1, columnas1);

		cout << "\nMatriz resultante de la suma: \n\n";

		for (int i = 0; i < filas1; i++)
		{
			for (int j = 0; j < columnas1; j++)
			{
				printf("%-15.4f ", Matrices::MR[i][j]);
			}

			cout << endl;
		}
	}
	else
		cout << "No se pueden sumar las matrices";

	delete[] M1;
	delete[] M2;
}

void RestaMatrices()
{
	cout << ">> Resta de Matrices\n\n";

	float** M1 = 0;
	float** M2 = 0;

	SolicitarMatriz(M1, M2);

	if (filas1 == filas2 && columnas1 == columnas2)
	{
		Matrices::Resta(M1, M2, filas1, columnas1);

		cout << "\nMatriz resultante de la resta: \n\n";

		for (int i = 0; i < filas1; i++)
		{
			for (int j = 0; j < columnas1; j++)
				printf("%-15.4f ", Matrices::MR[i][j]);

			cout << endl;
		}
	}
	else
		cout << "No se pueden restar las matrices";

	delete[] M1;
	delete[] M2;
}

void MultiplicacionMatrices()
{
	cout << ">> Multiplicacion de Matrices\n\n";

	float** M1 = 0;
	float** M2 = 0;

	SolicitarMatriz(M1, M2);

	if (columnas1 == filas2)
	{
		Matrices::Multiplicacion(M1, M2, filas1, columnas1, columnas2);

		cout << "\nMatriz resultante de la multiplicacion: \n\n";

		for (int a = 0; a < filas1; a++)
		{
			for (int b = 0; b < columnas2; b++)
				printf("%-15.4f ", Matrices::MR[a][b]);

			cout << endl;
		}
	}
	else
		cout << "No se pueden multiplicar las matrices";

	delete[] M1;
	delete[] M2;
}

void SolicitarMatriz(float**& m1, float**& m2)
{
	if (op == 1 || op == 2 || op == 3)
	{
		cout << "MATRIZ #1\n\n";

		filas1 = Funciones::GetNumber("Numero de filas #");
		columnas1 = Funciones::GetNumber("Numero de columnas #");

		cout << "\n\tAhora ingrese los datos:\n\n";

		m1 = new float* [filas1];

		for (int i = 0; i < filas1; i++)
			m1[i] = new float[columnas1];

		for (int i = 0; i < filas1; i++)
		{
			for (int j = 0; j < columnas1; j++)
			{
				char strDatoAPedir[50] = "";
				sprintf_s(strDatoAPedir, "\tFILA #%d, COLUMNA #%d, VALOR: ", i + 1, j + 1);
				m1[i][j] = Funciones::GetNumberFloat(strDatoAPedir);
			}

			cout << endl;
		}

		cout << "\n--------------------------------------------------\n\n";

		cout << "MATRIZ #2\n\n";

		filas2 = Funciones::GetNumber("Numero de filas #");
		columnas2 = Funciones::GetNumber("Numero de columnas #");

		m2 = new float* [filas2];

		for (int i = 0; i < filas2; i++)
			m2[i] = new float[columnas2];

		cout << "\n\tAhora ingrese los datos:\n\n";

		for (int i = 0; i < filas2; i++)
		{
			for (int j = 0; j < columnas2; j++)
			{
				char strDatoAPedir[50] = "";
				sprintf_s(strDatoAPedir, "\tFILA #%d, COLUMNA #%d, VALOR: ", i + 1, j + 1);
				m2[i][j] = Funciones::GetNumberFloat(strDatoAPedir);
			}

			cout << endl;
		}

		system("cls");

		cout << "Recopilando...\n\n";

		cout << "Matriz #1:\n\n";

		for (int i = 0; i < filas1; i++)
		{
			for (int j = 0; j < columnas1; j++)
			{
				printf("%-15.4f ", m1[i][j]);
			}

			cout << endl;
		}

		cout << "\nMatriz #2:\n\n";

		for (int i = 0; i < filas2; i++)
		{
			for (int j = 0; j < columnas2; j++)
			{
				printf("%-15.4f ", m2[i][j]);
			}

			cout << endl;
		}
	}
}

void MatrizCompuesta()
{
	cout << ">> Matrices compuesta de un primitivo grafico segun angulos dados\n\n";

	bool first = true;
	float pt[3] = { };
	float angulo = 0.0;
	int puntos = 0;
	int eje = 0;

	do
	{
		cout << "Ingrese el numero de la transformacion que desea realizar:\n\n";

		printf("1.- Traslacion\n");
		printf("2.- Rotacion\n");
		printf("3.- Escalacion\n");
		printf("4.- Aplicar las transformaciones a una figura\n");
		printf("5.- Cancelar \n\n");

		op3 = Funciones::GetNumber("Opcion a elegir #");
		cout << endl;

		if (op3 == 1 || op3 == 2 || op3 == 3) 
		{
			if (first) 
			{
				if (op3 == 1) 
				{
					cout << "\t>> Traslacion\n\n\t\tIngrese los puntos de traslacion:\n\n";

					pt[0] = Funciones::GetNumberFloat("\t\tX: ");
					pt[1] = Funciones::GetNumberFloat("\t\tY: ");
					pt[2] = Funciones::GetNumberFloat("\t\tZ: ");

					Matrices::TraslacionPunto(&pt[0], MT);

					system("cls");
					cout << "Matriz de Traslacion Generada:\n\n";

					for (int i = 0; i < 4; i++) 
					{
						for (int j = 0; j < 4; j++)
						{
							char strNumber[50] = "";
							sprintf_s(strNumber, "%-15.4f", MT[i][j]);
							cout << strNumber;
						}

						cout << endl;
					}

					cout << "\n";
				}
				else if (op3 == 2) 
				{
					cout << "\t>> Rotacion\n\n";

					angulo = Funciones::GetNumberFloat("\tAngulo en el que se desea rotar: ");

					cout << "\n\tEje en el cual rotar:\n\n\t1.- X\n\t2.- Y\n\t3.- Z\n\n";
					eje = Funciones::GetNumber("\tEje a rotar #");

					Matrices::RotacionPunto(angulo, eje, MT);

					system("cls");
					cout << "Matriz de Rotacion Generada:\n\n";

					for (int i = 0; i < 4; i++) 
					{
						for (int j = 0; j < 4; j++)
						{
							char strNumber[50] = "";
							sprintf_s(strNumber, "%-15.4f", MT[i][j]);
							cout << strNumber;
						}

						cout << endl;
					}

					cout << "\n";
				}
				else if (op3 == 3) 
				{
					cout << "\t>> Escalamiento\n\n\t\tIngrese los puntos de escalamiento:\n\n";

					pt[0] = Funciones::GetNumberFloat("\t\tX: ");
					pt[1] = Funciones::GetNumberFloat("\t\tY: ");
					pt[2] = Funciones::GetNumberFloat("\t\tZ: ");

					Matrices::EscalamientoPunto(&pt[0], MT);

					system("cls");
					cout << "Matriz de Escalamiento Generada:\n\n";

					for (int i = 0; i < 4; i++) 
					{
						for (int j = 0; j < 4; j++)
						{
							char strNumber[50] = "";
							sprintf_s(strNumber, "%-15.4f", MT[i][j]);
							cout << strNumber;
						}

						cout << endl;
					}

					cout << "\n";
				}

				first = false;
			}
			else 
			{
				if (op3 == 1) 
				{
					cout << "\t>> Traslacion\n\n\t\tIngrese los puntos de traslacion:\n\n";

					pt[0] = Funciones::GetNumberFloat("\t\tX: ");
					pt[1] = Funciones::GetNumberFloat("\t\tY: ");
					pt[2] = Funciones::GetNumberFloat("\t\tZ: ");

					Matrices::TraslacionPunto(&pt[0], MT2);

					system("cls");
					cout << "Nueva Matriz de Traslacion Generada:\n\n";

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							char strNumber[50] = "";
							sprintf_s(strNumber, "%-15.4f", MT2[i][j]);
							cout << strNumber;
						}

						cout << endl;
					}

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							MCF[i][j] = 0;
							for (int k = 0; k < 4; k++)
								MCF[i][j] = MCF[i][j] + MT[i][k] * MT2[k][j];
						}
					}

					cout << "\nNueva Matriz Resultante con las Transformaciones realizadas hasta el momento:\n\n";

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
							MT[i][j] = MCF[i][j];
					}

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++) 
						{
							char strNumber[50] = "";
							sprintf_s(strNumber, "%-15.4f", MT[i][j]);
							cout << strNumber;
						}

						cout << endl;
					}

					cout << endl;
				}
				else if (op3 == 2) 
				{
					cout << "\t>> Rotacion\n\n";

					angulo = Funciones::GetNumberFloat("\tAngulo en el que se desea rotar: ");

					cout << "\n\tEje en el cual rotar:\n\n\t1.- X\n\t2.- Y\n\t3.- Z\n\n";
					eje = Funciones::GetNumber("\tEje a rotar #");

					Matrices::RotacionPunto(angulo, eje, MT2);

					system("cls");

					cout << "Nueva Matriz de Rotacion Generada:\n\n";

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							char strNumber[50] = "";
							sprintf_s(strNumber, "%-15.4f", MT2[i][j]);
							cout << strNumber;
						}

						cout << endl;
					}

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							MCF[i][j] = 0;
							for (int k = 0; k < 4; k++)
								MCF[i][j] = MCF[i][j] + MT[i][k] * MT2[k][j];
						}
					}

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
							MT[j][i] = MCF[j][i];
					}

					cout << "\nNueva Matriz Resultante con las Transformaciones realizadas hasta el momento:\n\n";

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							char strNumber[50] = "";
							sprintf_s(strNumber, "%-15.4f", MT[i][j]);
							cout << strNumber;
						}

						cout << endl;
					}

					cout << "\n";
				}
				else if (op3 == 3) 
				{
					cout << "\t>> Escalamiento\n\n\t\tIngrese los puntos de escalamiento:\n\n";

					pt[0] = Funciones::GetNumberFloat("\t\tX: ");
					pt[1] = Funciones::GetNumberFloat("\t\tY: ");
					pt[2] = Funciones::GetNumberFloat("\t\tZ: ");

					Matrices::EscalamientoPunto(&pt[0], MT2);

					system("cls");
					cout << "Nueva Matriz de Escalamiento Generada:\n\n";

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							char strNumber[50] = "";
							sprintf_s(strNumber, "%-15.4f", MT2[i][j]);
							cout << strNumber;
						}

						cout << endl;
					}

					cout << "\nNueva Matriz Resultante con las Transformaciones realizadas hasta el momento:\n\n";

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							MCF[i][j] = 0;
							for (int k = 0; k < 4; k++)
								MCF[i][j] = MCF[i][j] + MT[i][k] * MT2[k][j];
						}
					}

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
							MT[j][i] = MCF[j][i];
					}

					for (int i = 0; i < 4; i++) 
					{
						for (int j = 0; j < 4; j++)
						{
							char strNumber[50] = "";
							sprintf_s(strNumber, "%-15.4f", MT[i][j]);
							cout << strNumber;
						}

						cout << endl;
					}

					cout << "\n";
				}

			}
		}
		else if (op3 == 4) 
		{
			if (!first) 
			{
				float** MCRF = new float* [4];

				puntos = Funciones::GetNumber("Total de puntos de figura a transformar: ");
				cout << "\n--------------------------------------------------\n\n";

				float** MF = new float* [4];

				for (int i = 0; i < 4; i++)
					MF[i] = new float[puntos];

				cout << "\tIntroduzca los valores de los puntos:\n\n";

				for (int i = 0; i < puntos; i++)
				{
					cout << "\t>> PUNTO #" << i + 1 << "\n\n";

					MF[0][i] = Funciones::GetNumberFloat("\t\tX: ");
					MF[1][i] = Funciones::GetNumberFloat("\t\tY: ");
					MF[2][i] = Funciones::GetNumberFloat("\t\tZ: ");
					MF[3][i] = 1.0;

					cout << endl;
				}

				system("cls");

				cout << "Matriz Generada con los Puntos de la Figura Ingresada: \n\n";

				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < puntos; j++)
					{
						char strNumber[50] = "";
						sprintf_s(strNumber, "%-15.4f", MF[i][j]);
						cout << strNumber;
					}

					cout << endl;
				}

				cout << "\n--------------------------------------------------\n\n";

				cout << "Matriz con todas las Transformaciones Realizadas:\n\n";

				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						char strNumber[50] = "";
						sprintf_s(strNumber, "%-15.4f", MT[i][j]);
						cout << strNumber;
					}

					cout << endl;
				}

				cout << "\n--------------------------------------------------\n\n";

				for (int i = 0; i < 4; i++)
					MCRF[i] = new float[puntos];

				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < puntos; j++)
					{
						MCRF[i][j] = 0;

						for (int k = 0; k < 4; k++)
							MCRF[i][j] = MCRF[i][j] + MT[i][k] * MF[k][j];
					}
				}

				cout << "Matriz Resultante con transformaciones aplicadas a la Figura: \n\n";

				for (int i = 0; i < 4; i++) 
				{
					for (int j = 0; j < puntos; j++)
					{
						char strNumber[50] = "";
						sprintf_s(strNumber, "%-15.4f", MCRF[i][j]);
						cout << strNumber;
					}

					cout << endl;
				}

				delete[] MCRF;
				delete[] MF;

				op3 = 5;
				op4 = 2;
			}
			else
			{
				system("cls");
				cout << "No ha realizado ninguna transformacion\n\n";
			}
		}

	} while (op3 != 5);
}

void MatrizPorVector()
{
	cout << ">> Matriz por Vector\n\n";

	float** M1 = 0;
	float** M2 = 0;

	/*
	filas1 = 4;
	columnas1 = 4;
	*/

	cout << "MATRIZ\n\n";

	filas2 = 4;
	columnas2 = 1;

	filas1 = Funciones::GetNumber("Numero de filas #");
	columnas1 = Funciones::GetNumber("Numero de columnas #");

	if (columnas1 != filas2)
	{
		cout << "No se pueden multiplicar las matrices";
		system("pause>nul");
		system("cls");
		return;
	}

	cout << "\n\tAhora ingrese los datos:\n\n";

	M1 = new float* [filas1];

	for (int i = 0; i < filas1; i++)
		M1[i] = new float[columnas1];

	for (int i = 0; i < filas1; i++)
	{
		for (int j = 0; j < columnas1; j++)
		{
			char strDatoAPedir[50] = "";
			sprintf_s(strDatoAPedir, "\tFILA #%d, COLUMNA #%d, VALOR: ", i + 1, j + 1);
			M1[i][j] = Funciones::GetNumberFloat(strDatoAPedir);
		}

		cout << endl;
	}

	/*
	M1 = new float* [filas1];

	for (int i = 0; i < filas1; i++)
		M1[i] = new float[columnas1];
		*/

	M2 = new float* [filas2];

	for (int i = 0; i < filas2; i++)
		M2[i] = new float[columnas2];

	/*cout << "MATRIZ 4x4\n\n";
	cout << "\n\tIngrese los datos de la matriz:\n\n";

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			char strDatoAPedir[50] = "";
			sprintf_s(strDatoAPedir, "\tFILA #%d, COLUMNA #%d, VALOR: ", i + 1, j + 1);
			M1[i][j] = Funciones::GetNumberFloat(strDatoAPedir);
		}

		cout << endl;
	}*/

	cout << "\n--------------------------------------------------\n\n";

	cout << "VECTOR\n\n";
	cout << "\n\tIngrese los datos del vector:\n\n";

	M2[0][0] = Funciones::GetNumberFloat("\tX: ");
	M2[1][0] = Funciones::GetNumberFloat("\tY: ");
	M2[2][0] = Funciones::GetNumberFloat("\tZ: ");
	M2[3][0] = 1;

	system("cls");

	cout << "Recopilando...\n\n";

	cout << "Matriz:\n\n";

	for (int i = 0; i < filas1; i++)
	{
		for (int j = 0; j < columnas1; j++)
		{
			printf("%-15.4f ", M1[i][j]);
		}

		cout << endl;
	}

	cout << "\nVector:\n\n";

	for (int i = 0; i < filas2; i++)
	{
		for (int j = 0; j < columnas2; j++)
		{
			printf("%-15.4f ", M2[i][j]);
		}

		cout << endl;
	}

	cout << "\nVerificando y calculando...\n\n";

	Matrices::Multiplicacion(M1, M2, filas1, columnas1, columnas2);

	cout << "El resultado de Matriz por Vector es: \n\n";

	for (int a = 0; a < filas1; a++)
	{
		for (int b = 0; b < columnas2; b++)
			printf("%-15.4f ", Matrices::MR[a][b]);

		cout << endl;
	}
}

void Cuaterniones()
{
	cout << ">> Generacion de nuevas coordenadas por cuaterniones\n\n";

	float p[3] = {};
	float v[3] = {};
	float angulo;

	cout << "Ingrese el punto a rotar: \n\n";

	p[0] = Funciones::GetNumberFloat("X: ");
	p[1] = Funciones::GetNumberFloat("Y: ");
	p[2] = Funciones::GetNumberFloat("Z: ");

	cout << "\nIngrese los puntos del vector sobre al cual va a rotar el punto: \n\n";

	v[0] = Funciones::GetNumberFloat("X: ");
	v[1] = Funciones::GetNumberFloat("Y: ");
	v[2] = Funciones::GetNumberFloat("Z: ");

	angulo = Funciones::GetNumberFloat("\nAngulo de Rotacion: ");

	cout << endl;

	Matrices::Cuaternios(angulo, &v[0], &p[0]);
	
	cout << "\n\nMatriz de Cuaternios Resultante: \n\n";

	for (int i = 0; i < 3; i++) 
	{
		printf("%-15.4f ", Matrices::MCR[i]);
		cout << endl;
	}

	cout << "\n\nResultado <i, j, k>:\n\n";

	char strNumber0[25] = "";
	char strNumber1[25] = "";
	char strNumber2[25] = "";

	sprintf_s(strNumber0, "%f", Matrices::MCR[0]);
	sprintf_s(strNumber1, "%f", Matrices::MCR[1]);
	sprintf_s(strNumber2, "%f", Matrices::MCR[2]);

	printf("< %d, %d, %d >", atoi(strNumber0), atoi(strNumber1), atoi(strNumber2));
}