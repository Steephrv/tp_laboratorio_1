/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Steeph Rios Valdivia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones_Calculadora.h"


int main(void)
{
	setbuf(stdout,NULL);

	int flagOperador1=0;
	int flagOperador2=0;
	int flagCase3=0;
	char seguir='s';
	int operador1;
	int operador2;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplica;
	float resultadoDivi;
	int resultadoDivide;
	int resultadoFactorialOp1;
	int resultadoFactorialOp2;
	int resultadoFactOp1;
	int resultadoFactOp2;


	do
	{
		switch(menu(flagOperador1,flagOperador2,operador1,operador2))
		{
			case 1:
				operador1=ingresarEntero("Ingrese el primer operador: ");
				flagOperador1= 1;
				system("pause");
				break;

			case 2:

				operador2=ingresarEntero("Ingrese el segundo operador: ");
				flagOperador2=1;
				system("pause");
				break;

			case 3:
				if(flagOperador1==1 && flagOperador2==1)
				{
					resultadoSuma=sumar(operador1,operador2);
					resultadoResta=restar(operador1,operador2);
					resultadoMultiplica=multiplicar(operador1,operador2);
					resultadoDivide=dividir(operador1,operador2, &resultadoDivi);
					resultadoFactorialOp1=factorial(operador1, &resultadoFactOp1);
					resultadoFactorialOp2=factorial(operador2, &resultadoFactOp2);
					flagCase3=1;
					system("pause");
				}
				else
				{
					printf("Para calcular las operaciones, se tiene que ingresar los operadores.\n");
					system("pause");
				}
				break;

			case 4:
				if(flagOperador1==1 && flagOperador2==1 && flagCase3==1)
				{
					printf("El resultado de %d + %d es: %d\n",operador1, operador2, resultadoSuma);
					printf("El resultado de %d - %d es: %d\n",operador1, operador2, resultadoResta);
					printf("El resultado de %d * %d es: %d\n",operador1, operador2, resultadoMultiplica);
					if(resultadoDivide==0)
					{
						printf("El resultado de %d / %d es: %.2f\n",operador1, operador2, resultadoDivi);
					}
					else
					{
						printf("No es posible dividir por cero.\n");
					}

					if(resultadoFactorialOp1==1 && resultadoFactorialOp2==1)
					{
						printf("El resultado de %d! es: %d y el resultado de %d! es: %d \n\n",operador1, resultadoFactOp1, operador2, resultadoFactOp2);

					}
					else
					{
						if(resultadoFactorialOp1==1 && resultadoFactorialOp2==0)
						{
							printf("El resultado de %d! es: %d y el resultado de %d! es: No se puede realizar el factorial de numeros negativos.\n\n",operador1, resultadoFactOp1, operador2);
						}
						else
						{
							if(resultadoFactorialOp1==0 && resultadoFactorialOp2==1)
							{
								printf("El resultado de %d! es: NO se puede realizar el factorial de numeros negativos y el resultado de %d! es: %d\n\n",operador1, operador2, resultadoFactOp2);
							}
							else
							{
								printf("No se puede realizar el factorial de numeros negativos.\n\n");
							}
						}
					}
					system("pause");

				}
				else
				{
					if(flagOperador1==1 && flagOperador2==1 && flagCase3==0)
					{
						printf("Para mostar los resultados, tiene que calcular las operaciones.\n");
						system("pause");
					}
					else
					{
						printf("Para mostrar los resultados, tiene que ingresar los operadores.\n");
						system("pause");
					}
				}
				break;

			case 5:
				seguir = 'n';
				break;

			default:
			printf("Opcion Invalida\n");
			system("pause");
		}

	}while(seguir == 's');

	return EXIT_SUCCESS;
}


