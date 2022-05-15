#ifndef INDEX_H_
#define INDEX_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int PedirEntero (char mensaje[], int min, int max);
float PedirFlotante (char mensaje[]);
int CAL_esFloat(char cadena[], int dimension);
int PedirCadena (char mensaje[], char cadena[]);
void ArregloNombrePropio (char cadena1[]);
int PedirCadenaConNumeros (char mensaje[], char cadena[]);

#endif /* INDEX_H_ */
