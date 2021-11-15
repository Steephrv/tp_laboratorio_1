#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "controller.h"
#include "miBiblioteca.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	FILE* pFile = NULL;

	if ( path != NULL && pArrayListEmployee != NULL )
	{

		pFile = fopen( path, "r");
		if ( pFile == NULL )
		{
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			if ( parser_EmployeeFromText( pFile, pArrayListEmployee ) )
			{
				printf( "Carga de archivo de texto exitosa\n" );
				todoOk = 1;
			}
		}
	}
	fclose(pFile);
	return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo datos.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	FILE* pFile= NULL;

	if ( path != NULL && pArrayListEmployee != NULL )
	{
		pFile = fopen( path, "rb");
		if ( pFile == NULL )
		{
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			if ( parser_EmployeeFromBinary( pFile, pArrayListEmployee ) )
			{
				printf( "Carga de archivo binario exitoso!!\n" );
				todoOk = 1;
			}
		}
	}
	fclose(pFile);
	return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	Employee* auxEmpleado = NULL;

	if ( pArrayListEmployee != NULL )
	{
		printf("     *** Alta de empleado *** \n");


		auxEmpleado = employee_new();
		id = buscarIdMayor(pArrayListEmployee);
		id++;

		printf("El ID asignado sera: %d\n", id);

		pedirString(nombre, "Ingrese su  nombre: ", 128);
		validarInt(&horasTrabajadas, "Ingrese las horas trabajadas: ", "ERROR, Ingrese cantidad de horas validas (0-1000): ", 0, 1000, 6);
		validarInt(&sueldo, "Ingrese  sueldo: ", "ERROR, Ingrese un sueldo valido (8000-120000): ", 8000, 120000, 6);

		if ( employee_setId(auxEmpleado, id) &&
			 employee_setNombre(auxEmpleado, nombre) &&
			 employee_setSueldo(auxEmpleado, sueldo) &&
			 employee_setHorasTrabajadas(auxEmpleado, horasTrabajadas)
		   )
		{
			ll_add( pArrayListEmployee, auxEmpleado );
			printf("Alta exitosa!!\n");
			todoOk =1;
		}
		else
		{
			employee_delete(auxEmpleado);
		}
	}
	return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk= 0;
	int id;
	Employee* auxEmpleado;
	int indice;
	char seguir = 's';
	char confirma;

	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;


	controller_ListEmployee(pArrayListEmployee);

	if(pArrayListEmployee != NULL)
	{

		printf("   *** MODIFICACION EMPLEADOS *** \n\n");

		printf("Ingrese ID del empleado: \n");
		scanf("%d", &id);

		indice = buscarEmpleadoId(pArrayListEmployee, id);

		if ( indice != -1)
		{
			auxEmpleado = ll_get(pArrayListEmployee, indice);

			do
			{
				printf("\n");
				printf(" ID      NOMBRE         HORAS-TRABAJADAS        SUELDO\n");
				printf("--------------------------------------------------------\n");
				mostrarEmpleado(auxEmpleado);


				switch (menuModificar())
				{
				case 1:

					pedirString(auxNombre,"Ingrese nuevo nombre: \n",128);

					printf("Confirma mofidicacion? (S/N): \n");
					fflush(stdin);
					scanf("%c", &confirma);
					confirma = toupper(confirma);
					if (confirma == 'S')
					{
						employee_setNombre(auxEmpleado, auxNombre);
						printf("MODIFICACION EXITOSA!!\n");
					}
					else
					{
						printf("MODIFICACION CANCELADA POR EL USUARIO\n");
					}
					break;

				case 2:

					validarInt(&auxHorasTrabajadas,"Ingrese nueva cantidad de horas trabajadas: \n", "ERROR,Ingrese cantidad de horas trabajadas(0-1000) ", 0, 1000, 10 );
					printf("confirma modificacion? (S/N): \n");
					fflush(stdin);
					scanf("%c", &confirma);
					confirma = toupper(confirma);
					if (confirma == 'S')
					{
						employee_setHorasTrabajadas(auxEmpleado, auxHorasTrabajadas);
						printf("MODIFICACION EXITOSA!!\n");
					}
					else
					{
						printf("MODIFICACION CANCELADA POR EL USUARIO\n");
					}

					break;

				case 3:

					validarInt(&auxSueldo,"Ingrese nuevo sueldo: (8000-120000): \n", "ERROR, Ingrese nuevo sueldo valido (8000-120000): \n", 8000, 120000, 10 );
					printf("Confirma modificacion? (S/N): \n");
					fflush(stdin);
					scanf("%c", &confirma);
					confirma = toupper(confirma);
					if (confirma == 'S')
					{
						employee_setSueldo(auxEmpleado, auxSueldo);
						printf("MODIFICACION EXITOSA!!\n");
					}
					else
					{
						printf("MODIFICACION CANCELADA POR EL USUARIO\n");
					}
					break;

				case 4:
					printf("Ha seleccionado salir\n");
					seguir='n';
					break;

				default:
					printf("Opcion invalida!!\n");
					break;
				}
				system("pause");
			}
			while(seguir == 's');
		}

		todoOk=1;
	}
	return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int id;
	int indice;
	char confirma;

	Employee* auxEmpleado;

	controller_ListEmployee(pArrayListEmployee);

	if ( pArrayListEmployee != NULL )
	{
		printf("\n        *** BAJA EMPLEADO ***\n");

		printf("Ingrese ID del empleado: ");
		scanf("%d", &id);
		indice = buscarEmpleadoId( pArrayListEmployee, id );
		if ( indice == -1 )
		{
			printf("No se pudo encontrar al empleado!!\n");
		}
		else
		{
			auxEmpleado = ll_get(pArrayListEmployee, indice);
			printf(" ID      NOMBRE         HORAS-TRABAJADAS        SUELDO\n");
			printf("--------------------------------------------------------\n");
			mostrarEmpleado(auxEmpleado);

			printf("Confirma baja? (S/N)\n");
			fflush(stdin);
			scanf("%c", &confirma);
			confirma = toupper(confirma);

			if ( confirma == 'S' )
			{
				ll_remove(pArrayListEmployee, indice);
				printf("BAJA EXITOSA!!\n");
				todoOk = 1;
			}
			else
			{
				printf("BAJA CANCELADA POR EL USUARIO!!\n");
			}
		}

	}
	return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	Employee* auxEmpleado;
	if (pArrayListEmployee != NULL)
	{

		printf("              *** LISTA EMPLEADOS ***	\n");
		printf("----------------------------------------------------\n");
		printf(" ID      NOMBRE      HORAS-TRABAJADAS    SUELDO\n");
		for (int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			auxEmpleado = (Employee*) ll_get( pArrayListEmployee, i );
			mostrarEmpleado(auxEmpleado);
		}
		todoOk = 1;
	}
	return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	char seguir = 's';
	int todoOk = 0;

	if ( pArrayListEmployee != NULL )
	{

		printf("         *** ORDENAMIENTO EMPLEADOS ***\n");

		do
		{

			switch (menuOrdenamiento())
			{
			case 1:
				ll_sort( pArrayListEmployee, compararEmpleadosHorasTrabajadas, 1 );
				controller_ListEmployee(pArrayListEmployee);

				break;

			case 2:
				ll_sort( pArrayListEmployee, compararEmpleadosHorasTrabajadas, 0 );
				controller_ListEmployee(pArrayListEmployee);

				break;

			case 3:

				ll_sort( pArrayListEmployee, compararEmpleadosSueldo, 1 );
				controller_ListEmployee(pArrayListEmployee);
				break;
			case 4:
				ll_sort( pArrayListEmployee, compararEmpleadosSueldo, 0 );
				controller_ListEmployee(pArrayListEmployee);
				break;

			case 5:
				printf("Ha seleccionado salir\n");
				seguir='n';
				break;

			default:
				printf("Opcion invalida!!\n");
				break;
			}
			system("pause");
		}
		while(seguir == 's');
	}
	return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	FILE* pFile;
	int id;
	char nombre[50];
	int horasTrabajadas;
	int sueldo;
	Employee* auxEmpleado;

	if ( path != NULL && pArrayListEmployee != NULL )
	{
		pFile = fopen(path, "w");
		if ( pFile == NULL )
		{
			printf("ERROR,No se pudo abrir el archivo\n");

		}

		fprintf( pFile, "id,nombre,horasTrabajadas,sueldo\n" );

		for (int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee, i);
			if ( employee_getId(auxEmpleado, &id) &&
					employee_getNombre(auxEmpleado, nombre) &&
					employee_getHorasTrabajadas( auxEmpleado, &horasTrabajadas) &&
					employee_getSueldo(auxEmpleado, &sueldo)
			   )
			{
				fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
				todoOk = 1;
			}
		}
		fclose(pFile);
	}

	return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	FILE* pFile;
	Employee* auxEmpleado;

	if ( path != NULL && pArrayListEmployee != NULL )
	{
		pFile = fopen(path, "wb");
		if ( pFile == NULL )
		{
			printf("ERROR, No se pudo abrir el archivo\n");

		}

		for (int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee, i);

			if ( auxEmpleado != NULL )
			{
				fwrite( auxEmpleado, sizeof(Employee), 1, pFile );
				todoOk = 1;
			}
		}
		fclose(pFile);
	}

	return todoOk;
}

