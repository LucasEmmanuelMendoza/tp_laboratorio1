#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Index.h"

typedef struct{
	int id;
	char descripcion[51];
}StatusFlight;

typedef struct{
	int id;
	char descripcion[51];
}TypePassenger;

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
	int statusFlight;
}Passenger;

int CargaForzada( StatusFlight estadosVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2);
void ImprimirUnPasajero (Passenger pasajero, StatusFlight estadosVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2);
void initPassengers (Passenger lista[], int tam);
int Informar (Passenger lista[], int len, StatusFlight estadosVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2);
int sortPassengers(Passenger* list, int len, int order);
int sortPassengersByCode(Passenger list[], int len, int order);
int ImprimirActivos (Passenger lista[], int len, StatusFlight estadosVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2);
void Ordenar (Passenger list[], int i, int j);
int MostrarTotalYPromedioDePrecios (Passenger lista[], int len);
void ImprimirEstadosDeVuelo(StatusFlight lista[], int tam);
void ImprimirTiposPasajero (TypePassenger lista[], int tam);
void initPassengers (Passenger lista[], int tam);
int PedirPasajero (char name[], char lastName[], char flycode[], float* precio, int* typePassenger, TypePassenger lista[], int tam, StatusFlight lista2[], int tam2, int* statusFlight);
int addPassenger (Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFlight);
int ModificarDatos (Passenger lista[], int tam, TypePassenger lista2[], int tam2, StatusFlight estadosVuelo[], int tam3);
int removePassenger(Passenger* list, int len, int id);
int printPassenger(Passenger list[], int length, StatusFlight estadosVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2);
int findPassengerById(Passenger* list, int len,int id);

#endif /* ARRAYPASSENGER_H_ */
