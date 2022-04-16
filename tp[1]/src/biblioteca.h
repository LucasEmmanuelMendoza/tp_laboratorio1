/*
 * biblioteca.h
 *
 *  Created on: 16 abr. 2022
 *      Author: lukit
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

float CalcularPrecioDebito (float monto);
float IngresarFlotante (char mensaje[]); //agregar validaciones
float CalcularPrecioCredito (float monto);
float CalcularEnBitcoin (float monto, double bitcoinActual);
float CalcularPrecioPorKm (float precioTotal, float kmTotales);
float CalcularDiferencia (float precio1, float precio2);
int IngresarEntero (char mensaje[], int min, int max);
void CargaForzada (float km, float aerolineas, float latam, double bitcoinActual);

#endif /* BIBLIOTECA_H_ */
