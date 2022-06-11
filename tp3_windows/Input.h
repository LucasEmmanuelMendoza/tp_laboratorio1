#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int PedirEntero (char mensaje[], int min, int max);
float PedirFlotante (char mensaje[]);
int CAL_esFloat(char cadena[], int dimension);
int PedirCadena (char mensaje[], char cadena[]);
void ArregloNombrePropio (char cadena1[]);
int PedirCadenaNums (char mensaje[], char cadena[]);
int Menu(int flag1, int flag2, int maxOption);

#endif /* INPUT_H_ */
