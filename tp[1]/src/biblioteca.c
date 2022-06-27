#include "biblioteca.h"

int Opcion (int bandera1, int bandera2, int bandera3, double kmIngresados, float precioAerolineas, float precioLatam){
	int opcion;
	int continuar;

	continuar = 0;

	do{
		printf ("\nMenú de opciones:\n");
		printf("1)Ingresar kilometros: (km: %.2f)\n", kmIngresados);
		printf("2)Ingresar precio de vuelos:(Aerolineas: %.2f, Latam: %.2f)\n", precioLatam, precioAerolineas);
		printf("3)Calcular todos los costos\n");
		printf("4)Informar Resultados\n");
		printf("5)Carga forzada de datos\n");
		printf("6)Salir\n");

	opcion = PedirEntero ("Seleccione una opcion: \n", 1, 6);

	if(opcion == 3 && bandera1 == 0){
		printf("Primero debe ingresar los km (Opcion 1)\n");
	    }else{
	    	if(opcion == 3 && bandera2 == 0){
			    printf("Primero debe ingresar los precios de las aerolineas (Opcion 2)\n");
		    }else{
			    if(opcion == 4 && bandera3 == 0){
			    	printf("Primero debe realizar los calculos (Opcion 3)\n");
			    }else{
				    continuar = 1;
			    }
		    }
	    }
	}while(continuar == 0);

	return opcion;
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

/*
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

	if(bitcoinActual != 0){
		retorno = (float) monto / bitcoinActual;
	}

	return retorno;
}*/

float CalcularUnitario (float monto, double valor){
	float retorno;

	if(valor != 0){
		retorno = (float) monto / valor;
	}

	return retorno;
}
/*
/// @fn float CalcularPrecioPorKm(float, float) Calcula el precio por kilómetro de un viaje
/// @param precioTotal
/// @param kmTotales
/// @return retorna el precio por km
//d) Mostrar precio por km (precio unitario)
float CalcularPrecioPorKm (float precioTotal, float kmTotales){
	float retorno;

	if(kmTotales != 0){
		retorno = precioTotal / kmTotales;
	}

	return retorno;
}*/

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
	precioAerolineasBitcoin = CalcularUnitario(aerolineas, bitcoinActual);
	precioAerolineasUnitario = CalcularUnitario(aerolineas, km);

	precioLatamCredito = CalcularPrecioCredito (latam);
	precioLatamDebito = CalcularPrecioDebito(latam);
	precioLatamBitcoin = CalcularUnitario(latam, bitcoinActual);
	precioLatamUnitario = CalcularUnitario(latam, km);

	diferenciaDePrecios = CalcularDiferencia(latam, aerolineas);

	ImprimirResultados(aerolineas, latam, km, precioLatamDebito, precioLatamCredito, precioLatamBitcoin, precioLatamUnitario, precioAerolineasDebito, precioAerolineasCredito, precioAerolineasBitcoin, precioAerolineasUnitario, diferenciaDePrecios);
}

void ImprimirResultados (float precioAerolineas, float precioLatam, double km, float precioLatamDebito, float precioLatamCredito, float precioLatamBitcoin, float precioLatamUnitario, float precioAerolineasDebito, float precioAerolineasCredito, float precioAerolineasBitcoin, float precioAerolineasUnitario, float diferenciaDePrecios){
	printf ("Km ingresados: %f\n", km);

	printf ("Precio Latam: %f\n", precioLatam);
	printf ("a) Precio con tarjeta de débito: %.2f\n", precioLatamDebito);
	printf ("b) Precio con tarjeta de crédito: %.2f\n", precioLatamCredito);
	printf ("c) Precio pagando con bitcoin : %.2f\n", precioLatamBitcoin);
	printf ("d) Precio unitario: %.2f\n", precioLatamUnitario);

	printf ("Precio Aerolineas: %f\n", precioAerolineas);
	printf ("a) Precio con tarjeta de débito: %.2f \n", precioAerolineasDebito );
	printf ("b) Precio con tarjeta de crédito: %.2f \n", precioAerolineasCredito);
	printf ("c) Precio pagando con bitcoin : %.2f \n", precioAerolineasBitcoin);
	printf ("d) Precio unitario: %.2f \n", precioAerolineasUnitario);

	printf ("La diferencia de precio es: %.2f\n", diferenciaDePrecios);
}
