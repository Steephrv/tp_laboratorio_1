/*
 * miBiblioteca.h
 *
 *  Created on: 23 nov. 2021
 *      Author: lenovo
 */

#ifndef SRC_MIBIBLIOTECA_H_
#define SRC_MIBIBLIOTECA_H_

void GetString(char *msj, char value[]);
int encontrarParidad(int numero);
int pedirEntero();
int pedirEnteroRango(int min, int max);
int validarDistintoDeCero(int numero);
int validarDecimales(float numero);
int miStrlen(char vect[]);
int validarCadena(char vect[]);
int pedirString(char cadena[], char mensaje[], int limite);
int convertirPrimerCaracterMayus(char cadena[]);
int getInt(int *pResultado);
int myGets(char *cadena, int longitud);
int validarInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int esNumerica(char *cadena);
int getFloat(float *pResultado);
int validarFloat(float *pResultado, char *mensaje, char *mensajeError,float minimo, float maximo, int reintentos);
int esNumericoFlotante(char cadena[]);

#endif /* SRC_MIBIBLIOTECA_H_ */
