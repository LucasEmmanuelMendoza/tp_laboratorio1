/* Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerol�neas Argentinas
para ofrecerlos a sus clientes.
Se deber� ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicaci�n es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciar� y contar� con un men� de opciones:
1. Ingresar Kil�metros: ( km=x)

2. Ingresar Precio de Vuelos: (Aerol�neas=y, Latam=z)
- Precio vuelo Aerol�neas:
- Precio vuelo Latam:

3. Calcular todos los costos:
a) Tarjeta de d�bito (descuento 10%)
b) Tarjeta de cr�dito (inter�s 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerol�neas)

4. Informar Resultados
�Latam:
a) Precio con tarjeta de d�bito: r
b) Precio con tarjeta de cr�dito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerol�neas:
a) Precio con tarjeta de d�bito: r
b) Precio con tarjeta de cr�dito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r �

5. Carga forzada de datos

6. Salir */

#include "biblioteca.h"
#define KM5 7090
#define AER5 162965
#define LAT5 159339

int main(void){
	setbuf(stdout,NULL);

	int bandera1;
	int bandera2;
	int bandera3;
	float precioAerolineas;
	float precioLatam;
	int opcion;
	int seguir;
	double kmIngresados;
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

	precioLatam = 0;
	precioAerolineas = 0;
	kmIngresados = 0;
	bandera1 = 0;
	bandera2 = 0;
	bandera3 = 0;
	seguir = 1;

	while (seguir == 1){

		opcion = Opcion(bandera1, bandera2, bandera3, kmIngresados, precioLatam, precioAerolineas);

		switch (opcion){
			case 1:
				kmIngresados = PedirFlotante("Ingrese km: ");
				while (kmIngresados == 0){
					kmIngresados= PedirFlotante ("Ingrese una distancia v�lida para un viaje: \n");
				}
				bandera1 = 1;
				break;

			case 2:
				precioAerolineas = PedirFlotante ("Ingrese el precio de Aerolineas: ");
				precioLatam = PedirFlotante ("Ingrese el precio de Latam: ");
				bandera2 = 1;
				break;

			case 3:
				precioAerolineasCredito = CalcularPrecioCredito(precioAerolineas);
				precioAerolineasDebito = CalcularPrecioDebito(precioAerolineas);
				precioAerolineasBitcoin = CalcularUnitario(precioAerolineas, bitcoinActual);
				precioAerolineasUnitario = CalcularUnitario(precioAerolineas, kmIngresados);

				precioLatamCredito = CalcularPrecioCredito (precioLatam);
				precioLatamDebito = CalcularPrecioDebito(precioLatam);
				precioLatamBitcoin = CalcularUnitario(precioLatam, bitcoinActual);
				precioLatamUnitario = CalcularUnitario(precioLatam, kmIngresados);

				diferenciaDePrecios = CalcularDiferencia(precioLatam, precioAerolineas);
				printf ("C�lculos realizados con �xito\n");
				bandera3 = 1;
				break;

			case 4:
				ImprimirResultados(precioAerolineas, precioLatam, kmIngresados, precioLatamDebito, precioLatamCredito, precioLatamBitcoin, precioLatamUnitario, precioAerolineasDebito, precioAerolineasCredito, precioAerolineasBitcoin, precioAerolineasUnitario, diferenciaDePrecios);

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
