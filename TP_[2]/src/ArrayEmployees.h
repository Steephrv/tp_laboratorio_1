/*
 * ArrayEmployees.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Steeph Rios Valdivia
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty; //1 esta vacio,0 esta lleno
}typedef Employee;



#endif /* ARRAYEMPLOYEES_H_ */



/// @fn int menu()
/// @brief menu de opcion
///
/// @return  opcion
int menu();

/// @fn int initEmployees(Employee[], int)
/// @brief inicializacion de empleados
///
/// @param list parametro de la estructura
/// @param len parametro largo
/// @return 1 si la inicializacion esta todo ok o 0 si salio algo mal
int initEmployees(Employee list[],int len);


///
///
/// @fn int changeMayus(char[], int)
/// @brief funcion para cambiar las primera letras de nombre y apellido a mayuscula
///
/// @param vector parametro  vector
/// @param len	parametro largo
/// @return 1 si salio todo Ok o 0 si hubo algun error.
int changeMayus(char vector[], int len);

/// @fn int findFree(Employee[], int)
/// @brief buscar libre a un empleado
///
/// @param list parametro estructura lista
/// @param len parametro largo
/// @return i del indice buscado o -1 si hubo algun error
 int findFree(Employee list[], int len);

/// @fn int addEmployees(Employee[], int, int*)
/// @brief alta de empleados
///
/// @param list parametro de estructura lista
/// @param len parametro largo
/// @param pId puntero ID
/// @return 1 si salio bien el alta de empleados o 0 si hubo algun error
int addEmployees(Employee list[], int len, int* pId);

/// @fn void printfEmployee(Employee)
/// @brief muestra datos de empleado
///
/// @param p parametro p (empleado)
void printfEmployee(Employee p);

/// @fn int printfEmployees(Employee[], int)
/// @brief  mostrar lista con sus respectivos datos de empleados
///
/// @param list parametro estructura lista
/// @param len parametro largo
/// @return 1 si salio todo bien o 0 si hubo algun error
int printfEmployees(Employee list[], int len);

/// @fn int removeEmployee(Employee[], int)
/// @brief baja de empleado seleccionado por su ID
///
/// @param list parametro estructura "lista"
/// @param len parametro largo
/// @return 1 si salio todo bien la baja o 0 si hubo algun error
int removeEmployee(Employee list[], int len);

/// @fn int findEmployeeById(Employee[], int, int)
/// @brief  buscar empleado por su ID
///
/// @param list parametro de estructura "lista"
/// @param len parametro largo
/// @param id parametro del ID
/// @return 1 si se busco bien o 0 si hubo algun error
int findEmployeeById(Employee list[], int len, int id);

/// @fn int menuModify()
/// @brief  menu de opciones de modificar
///
/// @return opciones del menu
int menuModify();

/// @fn int modifyEmployee(Employee[], int)
/// @brief  funcion ara modificar empleado mediante la busqueda de su ID
///
/// @param list parametro de estructura "Lista"
/// @param len parametro largo
/// @return 1 si la modificacion salio todo bien o 0 si hubo algun error.
int modifyEmployee(Employee list[], int len);

/// @fn int menuInformEmployees()
/// @brief menu de opciones de informar empleados
///
/// @return opcion del menu
int menuInformEmployees();

#define ASC 1
#define DESC 0

/// @fn int sortEmployees(Employee[], int, int)
/// @brief Ordenamiento de la lista de empleados cargada
///
/// @param list parametro estructura "lista"
/// @param len parametro largo
/// @param order parametro de criterio u orden  ( ascendente o descendente)
/// @return 1 si el ordenamiento salio todo bien o 0 si hubo algun error
int sortEmployees(Employee list[], int len , int order);

/// @fn int salariesEmployees(Employee[], int, float*)
/// @brief ACUMULADOR Y CONTADOR total DE SALARIOS
///
/// @param list parametro de estructura "lista"
/// @param len parametro largo
/// @param pSalario puntero a salario
/// @return 0 si salio todo bien8 con el promedio y un printf , o -1 si hubo algun error
int salariesEmployees(Employee list[], int len, float* pSalario);

/// @fn int cobranBienEmployees(Employee[], int, float)
/// @brief Cantidad de empleados que cobran mas del salario promedio
///
/// @param list parametro de estructura "lista"
/// @param len parametro largo
/// @param salario parametro de salario
/// @return 1 si el contador de empleados estuvo bien o 0 si hubo algun error
int cobranBienEmployees(Employee list[], int len, float salario);

/// @fn int informEmployees(Employee[], int)
/// @brief  informar total , promedio salarial y cantidad empleados
///
/// @param list parametro estructura "lista"
/// @param len parametro largo
/// @return 1 si la informacion estuvo todo bien o 0 si hubo algun error
int informEmployees(Employee list[], int len);
