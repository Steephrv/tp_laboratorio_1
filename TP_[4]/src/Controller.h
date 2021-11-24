/*
 * Controller.h
 *
 *  Created on: 23 nov. 2021
 *      Author: Steeph Rios Valdivia
 */

#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

int controller_clearLista(LinkedList* pArrayListEmployee);
int controller_deleteLista(LinkedList* pArrayListEmployee);
int controller_crearNuevaLista(LinkedList* pArrayListEmployee);
int controller_clonarLista(LinkedList* pArrayListEmployee);
int controller_removePorIndice(LinkedList* pArrayListEmployee);
int controller_buscarEmepleadoPorId(LinkedList* pArrayListEmployee, int id);


#endif /* SRC_CONTROLLER_H_ */
