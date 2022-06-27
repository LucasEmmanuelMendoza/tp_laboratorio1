/*
 * Input.h
 *
 *  Created on: 26 jun. 2022
 *      Author: lukit
 */

#ifndef INPUT_H_
#define INPUT_H_

#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int PedirCadena (char mensaje[], char cadena[]);
int PedirCadenaConNumeros (char mensaje[], char cadena[]);
int CAL_esFloat(char cadena[], int dimension);
float PedirFlotante (char mensaje[]);
int PedirEntero (char mensaje[], int min, int max);



#endif /* INPUT_H_ */
