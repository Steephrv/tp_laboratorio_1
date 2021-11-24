/*
 * parser.h
 *
 *  Created on: 23 nov. 2021
 *      Author: Steeph Rios Valdivia
 */

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* SRC_PARSER_H_ */
