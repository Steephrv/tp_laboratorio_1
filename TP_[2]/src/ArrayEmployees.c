/*
 * ArrayEmployees.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Steeph Rios Valdivia
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

int menu()
{
    int opcion;
    system("cls");
    printf("       ***ABM EMPLEADOS*** \n\n");
    printf("1-ALTA \n");
    printf("2-MODIFICAR \n");
    printf("3-BAJA \n");
    printf("4-INFORMAR \n");
    printf("5-SALIR\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int initEmployees(Employee list[],int len)
{
    int todoOk =0;

    if(list != NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
        todoOk=1;
    }
    return todoOk;
}

int findFree(Employee list[], int len)
{
    int indice= -1;
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int changeMayus(char vector[], int len)
{
    int todoOk = 0;
    int i =0;
    strlwr(vector);
    vector[0] = toupper(vector[0]);

    while(vector[i] != '\0')
    {
        if(vector[i] == ' ')
        {
            vector[i+1]= toupper(vector[i+1]);
            todoOk = 1;
        }
        i++;
    }
    return todoOk;
}


int addEmployees(Employee list[], int len, int* pId)
{
    int todoOk=0;
    int indice;
    Employee auxEmpleado;

    if(list != NULL && len>0)
    {
        system("cls");
        printf("          *** Alta Empleado ***\n\n");
        indice = findFree(list,len);
        if(indice == -1)
        {
            printf("No hay lugar");
        }
        else
        {
            auxEmpleado.id = *pId;
            (*pId)++;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxEmpleado.name);
            changeMayus(auxEmpleado.name , 51);

            printf("Ingrese apellidos: ");
            fflush(stdin);
            gets(auxEmpleado.lastName);
            changeMayus(auxEmpleado.lastName , 51);

            printf("Ingrese salario: ");
            scanf("%f", &auxEmpleado.salary);

            printf("Ingrese sector: ");
            scanf("%d", &auxEmpleado.sector);

            auxEmpleado.isEmpty = 0;

            list[indice] = auxEmpleado;
            todoOk=1;
        }

    }
    return todoOk;
}

void printfEmployee(Employee p)
{
    printf(" %d      %-20s     %-20s       %10.2f      %2d \n",
           p.id, p.name , p.lastName, p.salary , p.sector);
}


int printfEmployees(Employee list[], int len)
{
    int todoOk=0;;
    int flag=1;
    if(list != NULL && len>0)
    {
        system("cls");
        printf("                           **** Lista de Empleados **** \n");
        printf("----------------------------------------------------------------------------------------\n");
        printf("   ID        Nombre                  Apellido                     Salario    Sector \n");
        printf("----------------------------------------------------------------------------------------\n");

        for(int i=0; i< len ; i++)
        {
            if(!list[i].isEmpty)
            {
                printfEmployee(list[i]);
                flag=0;
            }

        }
        if(flag)
        {
           printf("No hay empleados para mostrar.\n");
        }
        todoOk=1;
    }
    return todoOk;
}

int findEmployeeById(Employee list[], int len, int id)
{
    int indice= -1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0 && list[i].id == id)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int removeEmployee(Employee list[], int len)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirm;
    if(list != NULL && len > 0)
    {
        system("cls");
        printf("        *** Baja Empleado ***\n");
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = findEmployeeById(list,len, id);

        if(indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema.\n", id);
        }
        else
        {
            printfEmployee(list[indice]);
            printf(" Confirma baja?: ");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                list[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }
        }
    }

    return todoOk;
}

int menuModify()
{
    int opcion;

    printf(" Que desea modificar?: \n\n");
    printf("1-Nombre \n");
    printf("2-Apellido \n");
    printf("3-Salario \n");
    printf("4-Sector \n");
    printf("5-SALIR\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int modifyEmployee(Employee list[], int len)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirm;

    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
    if(list != NULL && len > 0)
    {
        system("cls");
        printf("        *** Modificar Empleado ***\n");
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = findEmployeeById(list,len, id);

        if(indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema.\n", id);
        }

        else
        {
            printfEmployee(list[indice]);
            printf("Confirma modificacion?: ");
            fflush(stdin);
            scanf("%c", &confirm);

            if(confirm == 's')
            {
            	do
            	{
            		switch(menuModify())
            		                {
            		                    case 1:
            		                        printf("Ingrese nuevo nombre: \n");
            		                        fflush(stdin);
            		                        gets(auxName);
            		                        changeMayus(auxName,51);
            		                        strcpy(list[indice].name, auxName);
            		                        printf("\nModificacion exitosa!!\n");
            		                        break;

            		                    case 2:
            		                        printf("Ingrese nuevo apellido/s: \n");
            		                        fflush(stdin);
            		                        gets(auxLastName);
            		                        changeMayus(auxLastName,51);
            		                        strcpy(list[indice].lastName, auxLastName);
            		                        printf("\nModificacion exitosa!!\n");
            		                        break;

            		                    case 3:
            		                        printf("Ingrese nuevo salario: \n");
            		                        scanf("%f", &auxSalary);
            		                        list[indice].salary = auxSalary;
            		                        printf("\nModificacion exitosa!!\n");
            		                        break;

            		                    case 4:
            		                        printf("Ingrese nuevo sector: \n");
            		                        scanf("%d", &auxSector);
            		                        list[indice].sector = auxSector;
            		                        printf("\nModificacion exitosa!!\n");
            		                        break;

            		                    case 5:
            		                        printf("Ha seleccionado salir\n");
            		                        confirm='n';
            		                        break;

            		                    default:
            		                        printf("Opcion invalida!!!\n");
            		                }
            						system("pause");


            	}while(confirm == 's');
            	todoOk=1;

            }
            else
            {
                printf("Modificacion cancelada por el usuario\n");
            }
        }
    }

    return todoOk;
}

int menuInformEmployees()
{
    int opcion;

    printf(" \nQue opcion desea?: \n\n");
    printf("1-Mostrar lista empleados ordenados ascendente (sector-apellido) \n");
    printf("2-Mostrar lista empleados ordenados descendente (sector-apellido) \n");
    printf("3-Total y promedio de salarios \n");
    printf("4-Cantidad de empleados que superan el salario promedio \n");
    printf("5-SALIR\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}



int sortEmployees(Employee list[], int len , int order)
{
    int todoOk=0;
    Employee auxEmpleado;

    if(list != NULL && len > 0 && order >= 0 && order <= 1)
    {
        for(int i = 0; i<len-1; i++)
        {
            for(int j = i + 1; j<len; j++)
            {
                if(((list[i].sector == list[j].sector  && strcmp(list[i].lastName, list[j].lastName)> 0 &&  order ) || (list[i].sector == list[j].sector  && strcmp(list[i].lastName, list[j].lastName) < 0 && !order))
                   || ((list[i].sector != list[j].sector && list[i].sector > list[j].sector  && order ) || (list[i].sector != list[j].sector && list[i].sector < list[j].sector  && !order)))
                {
                    auxEmpleado = list[i];
                    list[i] = list[j];
                    list[j] = auxEmpleado;
                }
            }
        }
        todoOk=1;
    }

    return todoOk;
}

int salariesEmployees(Employee list[], int len, float* pSalario)
{
    int todoOk = -1;
    float acumSalarios =0;
    int contSalario = 0;
    if(list != NULL && len > 0 && pSalario != NULL)
    {
        for(int i =0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                acumSalarios += list[i].salary;
                contSalario++;
            }
        }
        todoOk = 0;
        *pSalario= (float)acumSalarios/contSalario;
        printf("\nEl total de los salarios es: $%.2f\n",acumSalarios);

    }

    return todoOk;
}

int cobranBienEmployees(Employee list[], int len, float salario)
{
    int todoOk = -1;
    int contGananBien = 0;

    salariesEmployees(list,len,&salario);

    if(list != NULL && len > 0)
    {
        for(int i =0; i<len; i++)
        {
            if(list[i].isEmpty == 0 && list[i].salary > salario)
            {
                contGananBien++;
            }
        }
        todoOk = 0;
    }
    printf("Hay %d empleados que cobran mas del salario promedio\n",contGananBien);

    return todoOk;
}


int informEmployees(Employee list[], int len)
{
    int todoOk = 0;
    char confirm= 's';
    float totalSalarios;

    if(list != NULL && len > 0)
    {
    	do
    	{
    		switch(menuInformEmployees())
    		        {
    		            case 1:
    		                sortEmployees(list,len,ASC);
    		                printfEmployees(list,len);
    		                printf("\nOrdenamiento exitoso!!\n");

    		                break;

    		            case 2:
    		                sortEmployees(list,len,DESC);
    		                printfEmployees(list,len);
    		                printf("\nOrdenamiento exitoso!!\n");
    		                break;

    		            case 3:
    		            	if(salariesEmployees(list,len,&totalSalarios))
							{
								printf("No se pudo promediar los salarios!! \n");
							}
							else
							{
							   printf("El promedio de todos los salarios es: $%.f\n", totalSalarios);
							}
    		                break;

    		            case 4:
    		            	cobranBienEmployees(list, len, totalSalarios);
    		                break;

    		            case 5:
    		                printf("Ha seleccionado salir\n");
    		                confirm = 'n';
    		                break;

    		            default:
    		                printf("Opcion invalida!!!\n");
    		        }
    				system("pause");


    	}while(confirm == 's');
    	todoOk=1;
    }
    return todoOk;
}

