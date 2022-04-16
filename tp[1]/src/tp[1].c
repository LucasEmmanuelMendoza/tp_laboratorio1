/* Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: ( km=x)

2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:

3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)

4. Informar Resultados
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “

5. Carga forzada de datos

6. Salir */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#define KM5 7090
#define AER5 162965
#define LAT5 159339

int main(void){
	setbuf(stdout,NULL);

	int bandera1;
	int bandera2;
	int bandera3;
	float kmIngresados;
	float precioAerolineas;
	float precioLatam;
	int opcion;
	int seguir;
	double bitcoinActual = 4621005.32;
	float precioAerolineasCredito;
	float precioAerolineasDebito;
	float precioAerolineasBitcoin;
	float precioAerolineasUnitario;
	float precioLatamCredito;
	float precioLatamDebito;
	float precioLatamBitcoin;
	float precioLatamUnitario;
	float diferenciaDePrecios;

	kmIngresados = 0;
	bandera1 = 0;
	bandera2 = 0;
	bandera3 = 0;

	seguir=1;

	while (seguir == 1){
		printf ("\nMenú de opciones:\n");

		if(bandera1 == 0){
			printf("1)Ingresar kilometros:\n");
		}else{
			printf ("1)Ingresar kilometros: (km = %.2f)\n", kmIngresados);
		}
		printf ("2)Ingresar precio de vuelos:\n");
		printf ("3)Calcular todos los costos\n");
		printf ("4)Informar Resultados\n");
		printf ("5)Carga forzada de datos\n");
		printf ("6)Salir\n");
		opcion = IngresarEntero ("Seleccione una opcion: \n", 1, 6);

		while (opcion == 3 && bandera1 == 0){
			printf ("Primero debe ingresar los kilometros (opcion 1)\n");
			opcion = IngresarEntero ("Seleccione una opción: \n", 1, 6);
		}

		while (opcion == 3 && bandera2 == 0){
			printf ("Primero debe ingresar el precio de las aerolíneas (opcion 2)\n");
			opcion = IngresarEntero ("Seleccione una opcion: \n", 1, 6);
		}

		while (opcion == 4 && bandera3 == 0){
			printf ("Pimero debe calcular los costos (opcion 3)\n");
			opcion = IngresarEntero ("Seleccione una opcion: \n", 1, 6);
		}

		switch (opcion){
			case 1:
				kmIngresados=IngresarFlotante("Ingrese km: ");
				while (kmIngresados == 0){
					kmIngresados= IngresarFlotante ("Ingrese una distancia válida para un viaje: \n");
				}
				bandera1 = 1;
				break;

			case 2:
				precioAerolineas = IngresarFlotante ("Ingrese el precio de Aerolineas: ");
				precioLatam = IngresarFlotante ("Ingrese el precio de Latam: ");
				bandera2 = 1;
				break;

			case 3:
				precioAerolineasCredito = CalcularPrecioCredito(precioAerolineas);
				precioAerolineasDebito = CalcularPrecioDebito(precioAerolineas);
				precioAerolineasBitcoin = CalcularEnBitcoin(precioAerolineas, bitcoinActual);
				precioAerolineasUnitario = CalcularPrecioPorKm(precioAerolineas, kmIngresados);

				precioLatamCredito = CalcularPrecioCredito (precioLatam);
				precioLatamDebito = CalcularPrecioDebito(precioLatam);
				precioLatamBitcoin = CalcularEnBitcoin(precioLatam, bitcoinActual);
				precioLatamUnitario = CalcularPrecioPorKm(precioLatam, kmIngresados);

				diferenciaDePrecios = CalcularDiferencia(precioLatam, precioAerolineas);
				printf ("Cálculos realizados con éxito\n");
				bandera3 = 1;
				break;

			case 4:
				printf ("Latam:\na) Precio con tarjeta de débito: %.2f\n", precioLatamDebito);
				printf ("b) Precio con tarjeta de crédito: %.2f\n", precioLatamCredito);
				printf ("c) Precio pagando con bitcoin : %.2f\n", precioLatamBitcoin);
				printf ("d) Precio unitario: %.2f\n", precioLatamUnitario);
				printf ("\nAerolíneas: \na) Precio con tarjeta de débito: %.2f \n", precioAerolineasDebito );
				printf ("b) Precio con tarjeta de crédito: %.2f \n", precioAerolineasCredito);
				printf ("c) Precio pagando con bitcoin : %.2f \n", precioAerolineasBitcoin);
				printf ("d) Precio unitario: %.2f \n", precioAerolineasUnitario);
				printf ("La diferencia de precio es: %.2f\n", diferenciaDePrecios);
				break;

			case 5:
				CargaForzada (KM5, AER5, LAT5, bitcoinActual);
				break;

			case 6:
				seguir = 0;
				break;
			}
	}

	return EXIT_SUCCESS;
}
