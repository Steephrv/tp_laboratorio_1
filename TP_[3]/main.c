#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo datos.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo datos.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
	char seguir = 's';


	LinkedList* listaEmpleados = ll_newLinkedList();
	if (listaEmpleados == NULL)
	{
		printf("No se pudo crear el linkedList\n");
		exit(1);
	}

	do
	{
		switch (menu())
		{
		case 1:
			if ( !controller_loadFromText("data.csv", listaEmpleados) )
			{
				printf("ERROR al cargar archivo texto\n");
			}
			break;
		case 2:
			if ( !controller_loadFromBinary("data.bin", listaEmpleados) )
			{
				printf("ERROR al cargar archivo binario\n");
			}
			break;
		case 3:
			if ( !controller_addEmployee(listaEmpleados) )
			{
				printf("Error al dar de alta empleado!!\n");
			}
			break;
		case 4:
			if ( !controller_editEmployee(listaEmpleados) )
			{
				printf("Error al modificar  empleado\n");
			}
			break;
		case 5:
			if ( !controller_removeEmployee(listaEmpleados) )
			{
				printf("Error en la baja de empleado\n");
			}
			break;
		case 6:
			if ( !controller_ListEmployee(listaEmpleados) )
			{
				printf("Error al listar empleado/s !!!\n");
			}
			break;
		case 7:
			if ( !controller_sortEmployee(listaEmpleados) )
			{
				printf("Error al ordenar  empleados\n");
			}
			break;
		case 8:
			if ( !controller_saveAsText("data.csv", listaEmpleados) )
			{
				printf("Error al guardar archivo de texto\n");
			}

			break;
		case 9:
			if ( !controller_saveAsBinary("data.bin", listaEmpleados) )
			{
				printf("Error al guardar en modo binario!!\n");
			}

			break;

		case 10:
			printf("Ha seleccionado salir\n");
			seguir='n';
			break;
		default:
			printf("Opcion invalida!!\n");
		}
		system("pause");
	}
	while(seguir == 's');
	return 0;
}

