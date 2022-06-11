#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Input.h"

//int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2);
//int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2);
//int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2);
//int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger,StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2);
//int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2);
int controller_sortPassenger(LinkedList* pArrayListPassenger);

//int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2);
//int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2);

//int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger,StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2);
#endif /* CONTROLLER_H_ */
