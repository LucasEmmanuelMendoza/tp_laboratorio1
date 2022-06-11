#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Input.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2);
//int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2);
#endif /* PARSER_H_ */
