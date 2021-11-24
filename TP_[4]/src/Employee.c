/*
 * Employee.c
 *
 *  Created on: 23 nov. 2021
 *      Author: Steeph Rios Valdivia
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "../inc/LinkedList.h"

Employee* employee_new()
{
	Employee* nuevoEmpleado = (Employee*) malloc(sizeof(Employee));
	if(nuevoEmpleado != NULL)
	{
		nuevoEmpleado->id = 0;
		strcpy(nuevoEmpleado->nombre, "");
		nuevoEmpleado->horasTrabajadas = 0;
		nuevoEmpleado->sueldo = 0;
	}
	return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* nuevoEmpleado = employee_new();
	if(nuevoEmpleado != NULL)
	{
		if(!(employee_setId(nuevoEmpleado, atoi(idStr)) &&
			employee_setNombre(nuevoEmpleado,nombreStr) &&
			employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadasStr)) &&
			employee_setSueldo(nuevoEmpleado,atoi(sueldoStr) ) ))
		{
			free(nuevoEmpleado);
			nuevoEmpleado = NULL;
		}
	}

	return nuevoEmpleado;
}

void employee_delete(Employee* pEmployee)
{

	if(pEmployee != NULL)
	{
		free(pEmployee);

	}
}


int employee_setId(Employee* this,int id)
{
	int todoOk =0;

	if(this != NULL && id > 0 )
	{
		this->id = id;
		todoOk =1;
	}

	return todoOk;
}

int employee_getId(Employee* this,int* id)
{
	int todoOk = 0;
	if(this != NULL && id != NULL )
	{
		*id = this->id;
		todoOk = 1;
	}

	return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int todoOk =0;
	char auxCadena[128];

	if(this != NULL && nombre != NULL && strlen(nombre) >= 3 && strlen(nombre) < 128 )
	{
		strcpy(auxCadena, nombre);
		strlwr(auxCadena);
		auxCadena[0]= toupper(auxCadena[0]);
		strcpy(this->nombre,auxCadena);
		todoOk =1;
	}

	return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int todoOk = 0;
	if(this != NULL && nombre != NULL )
	{
		strcpy(nombre,this->nombre);
		todoOk = 1;
	}

	return todoOk;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int todoOk =0;

	if(this != NULL && horasTrabajadas > 0 )
	{
		this->horasTrabajadas = horasTrabajadas;
		todoOk =1;
	}

	return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int todoOk = 0;
		if(this != NULL && horasTrabajadas != NULL )
		{
			*horasTrabajadas = this->horasTrabajadas;
			todoOk = 1;
		}

		return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int todoOk =0;

	if(this != NULL &&  sueldo > 0)
	{
		this->sueldo = sueldo;
		todoOk =1;
	}

	return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int todoOk = 0;
	if(this != NULL && sueldo != NULL )
	{
		*sueldo = this->sueldo;
		todoOk = 1;
	}

	return todoOk;
}

int menu()
{
    int opcion;

    printf("     *** ABM EMPLEADOS ***\n");
    printf("  1- Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("  2- Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
    printf("  3- Alta de empleado\n");
    printf("  4- Modificar datos de empleado\n");
    printf("  5- Baja de empleado\n");
    printf("  6- Listar empleados\n");
    printf("  7- Ordenar empleados\n");
    printf("  8- Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("  9- Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
    printf("  10- Eliminar empleados de la lista\n");
    printf("  11- Eliminar la lista de empleados\n");
    printf("  12- Crear una nueva lista de empleados\n");
    printf("  13- Clonar la lista de empleados\n");
    printf("  14- Eliminar empleado por indice elegido\n");
    printf("  15- SALIR\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int mostrarEmpleado(Employee* employee)
{
    int todoOk = 0;
    int id;
    char nombre[40];
    int horasTrabajadas;
    int sueldo;

    if (employee != NULL)
    {
        if ( employee_getId( employee, &id ) &&
             employee_getNombre( employee, nombre ) &&
             employee_getHorasTrabajadas( employee, &horasTrabajadas) &&
             employee_getSueldo(employee, &sueldo)
           )
        {
            printf ("  %-5d  %-15s %-4d             %-8d\n", id, nombre, horasTrabajadas, sueldo);
            todoOk = 1;
        }
    }
    return todoOk;
}

int buscarIdMayor(LinkedList* pArrayListEmployee)
{
	Employee* auxEmpleado = NULL;
	int mayor= 0;
	int id;
	if(pArrayListEmployee != NULL)
	{

		for( int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(auxEmpleado, &id);
			if( i==0 || id > mayor)
			{
				mayor = id;
			}
		}

	}
	return mayor;
}


int buscarEmpleadoId(LinkedList* pArrayListEmployee, int id)
{
    int indice = -1;
    int auxId;
    Employee* auxEmployee;

    for (int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        auxEmployee = ll_get(pArrayListEmployee, i);
        if(employee_getId(auxEmployee, &auxId) && auxId == id)
        {
            indice = i;
        }
    }

    return indice;
}

int menuModificar()
{
    int opcion;

    printf("\n");
    printf("     *** MENU DE MODIFICACION ***\n");
    printf("  1- MODIFICAR NOMBRE\n");
    printf("  2- MODIFICAR HORAS-TRABAJADAS\n");
    printf("  3- MODIFICAR SUELDO\n");
    printf("  4- SALIR\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    //printf("\n");
    return opcion;
}


int menuOrdenamiento()
{
    int opcion;

    printf("    *** OPCIONES DE ORDENAMIENTO ***\n");
    printf("1- ORDENAR EMPLEADOS POR HORAS TRABAJADAS ASCENDENTE \n");
    printf("2- ORDENAR EMPLEADOS POR HORAS TRABAJADAS DESCENDENTE\n");
    printf("3- ORDENAR EMPLEADOS POR SALARIO ASCENDENTE\n");
    printf("4- ORDENAR EMPLEADOS POR SALARIO DESCENDENTE \n");
    printf("5- SALIR\n");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}


int compararEmpleadosHorasTrabajadas(void* pEmpleadoA,void* pEmpleadoB)
{
    int todoOk= 0;

    if(((Employee*)pEmpleadoA)->horasTrabajadas > ((Employee*)pEmpleadoB)->horasTrabajadas)
    {
        todoOk= 1;
    }
    if(((Employee*)pEmpleadoA)->horasTrabajadas < ((Employee*)pEmpleadoB)->horasTrabajadas)
    {
        todoOk = -1;
    }
    return todoOk;
}


int compararEmpleadosSueldo(void* pEmpleadoA,void* pEmpleadoB)
{
    int todoOk= 0;

    if(((Employee*)pEmpleadoA)->sueldo > ((Employee*)pEmpleadoB)->sueldo)
    {
        todoOk= 1;
    }
    if(((Employee*)pEmpleadoA)->sueldo < ((Employee*)pEmpleadoB)->sueldo)
    {
        todoOk = -1;
    }
    return todoOk;

}



