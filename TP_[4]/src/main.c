/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
#include "../testing/inc/main_test.h"
*/

#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
     10- Eliminar empleados de la lista
  	 11- Eliminar la lista de empleados
  	 12- Crear una nueva lista de empleados
  	 13- Clonar la lista de empleados
  	 14- Eliminar empleado por indice elegido
  	 15- SALIR

*****************************************************/


int main(void)
{
	/* startTesting(1);  // ll_newLinkedList
	    startTesting(2);  // ll_len
	    startTesting(3);  // getNode - test_getNode
		startTesting(4);  // addNode - test_addNode
		startTesting(5);  // ll_add
		startTesting(6);  // ll_get
		startTesting(7);  // ll_set
		startTesting(8);  // ll_remove
		startTesting(9);  // ll_clear
		startTesting(10); // ll_deleteLinkedList
		startTesting(11); // ll_indexOf
		startTesting(12); // ll_isEmpty
		startTesting(13); // ll_push
		startTesting(14); // ll_pop
		startTesting(15); // ll_contains
		startTesting(16); // ll_containsAll
		startTesting(17); // ll_subList
		startTesting(18); // ll_clone
		startTesting(19); // ll_sort

	*/
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
			if ( !controller_loadFromBinary("datas.bin", listaEmpleados) )
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
			if(!controller_clearLista(listaEmpleados) )
			{
				printf("Hubo un error al eliminar empleados de la lista!!\n");
			}
			break;

		case 11:
			if(!controller_deleteLista(listaEmpleados) )
			{
				printf("Hubo un error al eliminar la lista de empleados!!\n");
			}
			break;

		case 12:
			if(!controller_crearNuevaLista(listaEmpleados) )
			{
				printf("Hubo un error al crear una lista nueva!!\n");
			}
			break;

		case 13:
			if(!controller_clonarLista(listaEmpleados) )
			{
				printf("Hubo un error al clonar la lista!!\n");
			}
			break;

		case 14:
			if(!controller_removePorIndice(listaEmpleados) )
			{
				printf("Hubo un error al eliminar empleado por el indice elegido!!\n");
			}
			break;


		case 15:
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
