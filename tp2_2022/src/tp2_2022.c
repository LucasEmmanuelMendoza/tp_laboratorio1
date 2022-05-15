/*
 Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
no puede tener más de 2000 pasajeros.
Datos:

El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
número de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o Código de vuelo
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
promedio.
3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’


1-NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún pasajero.
2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.

Para la realización de este programa, se utilizará una biblioteca llamada “ArrayPassenger” que
facilitará el manejo de la lista de pasajeros y su modificación. En la sección siguiente se
detallan las funciones que esta biblioteca debe tener.

struct
{
int id;
char name[51];
char lastName[51];
float price;
char flycode[10];
int typePassenger;
int isEmpty;
}typedef Passenger
*/

/*Usar una variable que incremente para los id
 *Usar un contador para otras operaciones, que decremente cuando das de baja y si ese contador es 0 no podes entrar a otros cases, por ej usar como bandera*/
#include "Index.h"
#include "ArrayPassenger.h"

#define TAM 2000
#define TIPOPASAJERO 3
#define STATUSFLIGHT 2
int main(void) {

	setbuf(stdout, NULL);

	TypePassenger tipoPasajero[TIPOPASAJERO] = {{1,"Turista"},{2,"Business"},{3, "Primera Clase"}};
	Passenger pasajeros[TAM];
	StatusFlight estadosVuelo[STATUSFLIGHT] = {{1, "Activo"},{2, "Inactivo"}};

	int opcion;
	int id;
	int contador;

	char name[51];
	char lastName[51];
	char flycode[10];
	int typePassenger;
	int statusFlight;
	float price;

	int idBaja;

	int retornoAlta;
	int retornoMod;
	int retornoBaja;
	int retornoInforme;

	initPassengers(pasajeros, TAM);

	id = 1;
	contador = 0;

	do{
		printf ("\nMenú de opciones: \n");
		printf ("1)Alta\n");
		printf ("2)Modificar\n");
		printf ("3)Baja\n");
		printf ("4)Informar\n");

		opcion = PedirEntero ("Seleccione una opcion (1/2/3/4): ", 1,4 );
		while(opcion > 1 && contador == 0){
			printf ("Primero debe ingresar un pasajero (opcion 1)\n");
			opcion = PedirEntero ("Seleccione una opcion: ", 1,4 );
		}

		switch(opcion){
		case 1:
			PedirPasajero(name, lastName, flycode, &price, &typePassenger, tipoPasajero, TIPOPASAJERO, estadosVuelo, STATUSFLIGHT, &statusFlight);
			retornoAlta = addPassenger(pasajeros, TAM, id, name, lastName, price, typePassenger, flycode, statusFlight);
			if (retornoAlta == 0){
				//printf("-Pasajero cargado-\n");
				contador = contador + 1;
				id = id + 1;
			}
			break;

		case 2:
			retornoMod = ModificarDatos (pasajeros, TAM, tipoPasajero, TIPOPASAJERO);
			if (retornoMod == 1){
				printf ("-Modificacion realizada-\n");
			}
			break;

		case 3:
			printPassenger(pasajeros, TAM);
			idBaja = PedirEntero ("Ingrese el id del pasajero a dar de baja: \n", 1, 2000);
			retornoBaja = removePassenger(pasajeros, TAM, idBaja);
			if (retornoBaja == 0){
				contador = contador - 1;
				printf ("-Pasajero dado de baja-\n");
			}
			break;

		case 4:
			retornoInforme = Informar(pasajeros, TAM);
			if(retornoInforme == 0){
				printf("-Error al informar-\n");
			}
		}
	}while(opcion != 5);

	return EXIT_SUCCESS;

}
