/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Steeph Rios Valdivia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

#define ELEMENTS 1000
#define ASC 1
#define DESC 0


int main(void) {

	setbuf(stdout,NULL);

	char seguir = 's';
	int nextId = 10000;
	int queHizo = 0;

	Employee list[ELEMENTS];

	if(!initEmployees(list, ELEMENTS))
	   {
		   printf("Problema al inicializar");
	   }


	do
	{
		switch(menu())
		{
		case 1:
			if(!addEmployees(list,ELEMENTS,&nextId))
			{
				printf("\nNo se pudo realizar el alta.\n");
			}
			else
			{
				printf("\nAlta exitosa!!\n");
				queHizo=1;
			}
			break;

		case 2:
			if(queHizo == 1 && !modifyEmployee(list, ELEMENTS))
			{
				printf("\nNo se pudo realizar la modificacion.\n");
			}
			else
			{
				printf("\nNo se puede modificar, sin antes haber dado de alta algun empleado!!!\n");
			}
			break;

		case 3:
			if(queHizo == 0)
			{
				printf("\nNo se puede dar de baja, sin antes haber dado de alta algun empleado!!\n");
			}
			else
			{
				if(!removeEmployee(list,ELEMENTS))
				{
					printf("\nNo se pudo realizar la baja!!\n");
				}
				else
				{
					printf("\nBaja Exitosa!!\n");
				}
			}
			break;

		case 4:
			if(queHizo == 1 && !informEmployees(list,ELEMENTS))
			{
				printf("\nNo se pudo ordenar la lista de empleados.\n");
			}
			else
			{
				printf("\nNo se puede informar, sin antes haber dado de alta algun empleado!!\n");
			}
			break;

		case 5:
			printf("Ha seleccionado salir\n");
			seguir='n';
			break;

		default:
			printf("Opcion invalidad!!!\n");
		}
		system("pause");

	}while(seguir == 's');


	return EXIT_SUCCESS;
}
