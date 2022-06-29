/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Input.h"

typedef struct{
	int id;
	char descripcion[50];
}TypePassenger;

typedef struct{
	int id;
	char descripcion[50];
}StatusFlight;

typedef struct
{	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[7];
	int estadoDeVuelo;
}Passenger;

typedef struct
{	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[50];
	char codigoVuelo[7];
	char estadoDeVuelo[50];
}PassengerBinary;

PassengerBinary* PassengerB_new();
Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoDeVueloStr, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2);

void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setEstadoDeVuelo(Passenger* this, int estadoDeVuelo);
int Passenger_getEstadoDeVuelo(Passenger* this, int* estadoDeVuelo);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

void PrintTiposPasajero(TypePassenger tiposPasajero[], int tam2);
void PrintEstadosVuelo(StatusFlight estadosDeVuelo[], int tam1);

void PrintOnePassenger (Passenger* pasajero, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2);
//Convertir PrintPassengers en controller_ListEmployee, modificando los parámetros
//void PrintPassengers(LinkedList* this, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2);
Passenger* Passenger_getPassengerById(LinkedList* this, int tam, int idBusqueda);
int CompararNombre(void* pasajero1, void* pasajero2);
int CompararApellido(void* pasajero1, void* pasajero2);

#endif /* PASSENGER_H_ */
