/*
 * biblioteca.h
 *
 *  Created on: 16 abr. 2022
 *      Author: lukit
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"

float CalcularUnitario (float monto, double valor);
int Opcion (int bandera1, int bandera2, int bandera3, double kmIngresados, float precioAerolineas, float precioLatam);
float CalcularPrecioDebito (float monto);
float CalcularPrecioCredito (float monto);
//float CalcularEnBitcoin (float monto, double bitcoinActual);
//float CalcularPrecioPorKm (float precioTotal, float kmTotales);
float CalcularDiferencia (float precio1, float precio2);
void CargaForzada (float km, float aerolineas, float latam, double bitcoinActual);
void ImprimirResultados (float precioAerolineas, float precioLatam, double km, float precioLatamDebito, float precioLatamCredito, float precioLatamBitcoin, float precioLatamUnitario, float precioAerolineasDebito, float precioAerolineasCredito, float precioAerolineasBitcoin, float precioAerolineasUnitario, float diferenciaDePrecios);

#endif /* BIBLIOTECA_H_ */
