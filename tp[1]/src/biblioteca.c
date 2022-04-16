#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @fn int IngresarEntero(char[], int, int) Pide el ingreso de un entero validado en un rango
/// @param mensaje
/// @param min
/// @param max
/// @return retorna el entero
int IngresarEntero (char mensaje[], int min, int max){
	int retorno;

	do{
	printf ("%s", mensaje);
	fflush(stdin);
	scanf ("%d", &retorno);
	}while(retorno < min || retorno > max);

	return retorno;
}

/// @fn float IngresarFlotante(char[]) Pide el ingreso un flotante validando que sea mayor a cero
/// @param mensaje
/// @return retorna el flotante
float IngresarFlotante (char mensaje[]){ //agregar validaciones
	float retorno;

	do{
		printf ("%s", mensaje);
		fflush(stdin);
		scanf ("%f", &retorno);
	}while (retorno <0);

	return retorno;
}

/// @fn float CalcularPrecioDebito(float) Calcula un precio con 10% de descuento
/// @param monto
/// @return retorna el nuevo precio
//a) Tarjeta de débito (descuento 10%)
float CalcularPrecioDebito (float monto){
	float retorno;

	retorno = monto - monto * 10/100;

	return retorno;
}

/// @fn float CalcularPrecioCredito(float) Calcula un precio con 25% de intereses
/// @param monto
/// @return	retorna el nuevo precio
//b) Tarjeta de crédito (interés 25%)
float CalcularPrecioCredito (float monto){
	float retorno;

	retorno = monto + monto * 25/100;

	return retorno;
}

/// @fn float CalcularEnBitcoin(float, double) Calcular la conversión a bitcoin de un monto ingresado
/// @param monto
/// @param bitcoinActual
/// @return retorna la conversión
//c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
//float
//double
//%lf
//%.3lf
float CalcularEnBitcoin (float monto, double bitcoinActual){
	float retorno;

	retorno = (float) monto / bitcoinActual;

	return retorno;
}

/// @fn float CalcularPrecioPorKm(float, float) Calcula el precio por kilómetro de un viaje
/// @param precioTotal
/// @param kmTotales
/// @return retorna el precio por km
//d) Mostrar precio por km (precio unitario)
float CalcularPrecioPorKm (float precioTotal, float kmTotales){
	float retorno;

	retorno = precioTotal / kmTotales;

	return retorno;
}

/// @fn float CalcularDiferencia(float, float) Calcula la diferencia entre dos números en módulo
/// @param precio1
/// @param precio2
/// @return retorna la diferencia
//e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
float CalcularDiferencia (float precio1, float precio2){
	float retorno;

	if (precio1 > precio2)
	{
		retorno = precio1 - precio2;
	}
	else
	{
		retorno = precio2 - precio1;
	}

	return retorno;
}

/// @fn void CargaForzada(float, float, float, double) Calcula y muestra todos los precios y la diferencia entre aerolineas y latam
/// @param km
/// @param aerolineas
/// @param latam
/// @param bitcoinActual
void CargaForzada (float km, float aerolineas, float latam, double bitcoinActual){
	float precioAerolineasCredito;
	float precioAerolineasDebito;
	float precioAerolineasBitcoin;
	float precioAerolineasUnitario;
	float precioLatamCredito;
	float precioLatamDebito;
	float precioLatamBitcoin;
	float precioLatamUnitario;
	float diferenciaDePrecios;

	precioAerolineasCredito = CalcularPrecioCredito(aerolineas);
	precioAerolineasDebito = CalcularPrecioDebito(aerolineas);
	precioAerolineasBitcoin = CalcularEnBitcoin(aerolineas, bitcoinActual);
	precioAerolineasUnitario = CalcularPrecioPorKm(aerolineas, km);

	precioLatamCredito = CalcularPrecioCredito (latam);
	precioLatamDebito = CalcularPrecioDebito(latam);
	precioLatamBitcoin = CalcularEnBitcoin(latam, bitcoinActual);
	precioLatamUnitario = CalcularPrecioPorKm(latam, km);

	diferenciaDePrecios = CalcularDiferencia(latam, aerolineas);

	printf ("Latam:\na) Precio con tarjeta de débito: %.2f\n", precioLatamDebito);
	printf ("b) Precio con tarjeta de crédito: %.2f\n", precioLatamCredito);
	printf ("c) Precio pagando con bitcoin : %.2f\n", precioLatamBitcoin);
	printf ("d) Precio unitario: %.2f\n", precioLatamUnitario);
	printf ("\nAerolíneas: \na) Precio con tarjeta de débito: %.2f \n", precioAerolineasDebito );
	printf ("b) Precio con tarjeta de crédito: %.2f \n", precioAerolineasCredito);
	printf ("c) Precio pagando con bitcoin : %.2f \n", precioAerolineasBitcoin);
	printf ("d) Precio unitario: %.2f \n", precioAerolineasUnitario);
	printf ("La diferencia de precio es: %.2f\n", diferenciaDePrecios);
}


