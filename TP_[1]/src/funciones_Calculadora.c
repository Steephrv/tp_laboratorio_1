/*
 * funciones_Calculadora.c
 *
 *  Created on: 21 set. 2021
 *      Author: Steeph Rios Valdivia
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones_Calculadora.h"



 int menu(int flagOperador1,int flagOperador2,int num1, int num2)
{
	int opcion;

	system("cls");
	printf("Menu de opciones\n\n");
	printf("1. Primer operador (A = X): ");
	if(flagOperador1==1){
		printf("A = %d\n",num1);
	}
	else{
		printf("\n");
	}

	printf("2. Segundo operador (B = Y): ");
	if(flagOperador2==1){

		printf("B = %d\n",num2);
	}
	else{
		printf("\n");
	}

	printf("3. Calcular todas las operaciones\n");
	printf("   * Suma (A+B)\n");
	printf("   * Resta (A-B)\n");
	printf("   * Multiplicacion (A*B)\n");
	printf("   * Division (A/B)\n");
	printf("   * Factorial (A!) y (B!)\n");
	printf("4. Mostrar resultados\n");
	printf("5. SALIR: ");
	printf("\nIndique opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}

int ingresarEntero( char mensaje[])
{
	int numeroIngresado;

	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}

int sumar (int num1, int num2)
{
	int resultadoSum;

	resultadoSum= num1+num2;

	return resultadoSum;

}

int restar(int num1, int num2)
{
	int resultadoRest;

	resultadoRest=num1-num2;

	return resultadoRest;
}

int multiplicar(int num1, int num2)
{
	int resultadoMulti;

	resultadoMulti=num1*num2;

	return resultadoMulti;
}

int dividir( int num1, int num2, float* pResultado)
{
	float resultadoDivi;
	int retorno=-1;

	if(pResultado!= NULL && num2 != 0)
	{
		resultadoDivi= (float) num1/num2;
		*pResultado= resultadoDivi;
		retorno=0;
	}

	return retorno;
}

long long int factorial(int numeroIngresado,int* pResultado)
{


	int resultadoFact=0;
	int retorno=0;
	if(pResultado != NULL && numeroIngresado>=0)
	{
		resultadoFact=1;
		for(int i =2 ; i<= numeroIngresado ; i++)
		{
			resultadoFact=resultadoFact*i;
		}
		retorno=1;
	}
	*pResultado=resultadoFact;

	return retorno;
}



