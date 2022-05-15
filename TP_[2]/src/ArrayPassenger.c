#include "ArrayPassenger.h"

void ImprimirEstadosDeVuelo(StatusFlight lista[], int tam){
	printf ("ID - Descripcion\n");

	for(int i=0; i<tam; i++){
		printf ("%d - %s\n", lista[i].id, lista[i].descripcion);
	}
}

void ImprimirTiposPasajero (TypePassenger lista[], int tam){
	printf(" ID - Descripcion\n");

	for(int i=0; i<tam; i++){
		printf("%d %s\n", lista[i].id, lista[i].descripcion);
	}
}

void initPassengers (Passenger lista[], int tam){
	for (int i=0; i<tam; i++){
		lista[i].isEmpty = 1;
	}
}

void ImprimirUnPasajero (Passenger pasajero){

	printf("%4d | %6s | %6s | %8f | %8s | %10d | %12d\n", pasajero.id, pasajero.name, pasajero.lastName, pasajero.price, pasajero.flycode, pasajero.typePassenger, pasajero.statusFlight);

}

int printPassenger(Passenger list[], int length)
{
	int retorno;
	retorno = -1;

	printf ("Lista de pasajeros: \n");

	if (list != NULL && length >0){
		printf ("%4s | %6s | %6s | %8s | %8s | %10s | %12s\n", "id", "Name", "Last Name", "Price", "Fly Code", "Type Passenger", "Status Flight");
		for(int i=0; i<length; i++){
			if (list[i].isEmpty == 0){
				ImprimirUnPasajero (list[i]);
				retorno = 0;
			}
		}
	}

	return retorno;
}

int addPassenger (Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFlight)
{
	int retorno;

	retorno = -1;

	printf("HOLAAAAA\n");
		if (len >0){
			printf("HOLAAAAA");
			for (int i = 0; i<len; i++){
					if (list[i].isEmpty == 1){
						list[i].id = id;
						strcpy(list[i].name, name);
						strcpy(list[i].flycode, flycode);
						strcpy(list[i].lastName, lastName);
						list[i].price = price;
						list[i].typePassenger = typePassenger;
						list[i].statusFlight = statusFlight;
						list[i].isEmpty = 0;
						retorno = 0;
						break; //encontró lugar
					}
				}
		}

	return retorno;
}

int PedirPasajero (char name[], char lastName[], char flycode[], float* precio, int* typePassenger, TypePassenger lista[], int tam, StatusFlight lista2[], int tam2, int* statusFlight){//fijarse si es necesario usar scanf("%[^\n]", nombre); en vez de gets en PedirCadena
	int retorno;
	retorno = -1;

	if (name!=NULL && lastName != NULL && flycode != NULL){
		PedirCadena("Ingrese el nombre: \n", name);
		PedirCadena("Ingrese el apellido: \n", lastName);
		PedirCadena("Ingrese el codigo de vuelo: \n", flycode);
		*precio = PedirFlotante("Ingrese el precio del vuelo: ");

		ImprimirTiposPasajero (lista, tam);
		*typePassenger = PedirEntero("Ingrese el tipo de pasajero ", 1, 3); //rango de valores?

		ImprimirEstadosDeVuelo (lista2, tam2);
		*statusFlight = PedirEntero("Ingrese el status flight 1 / 2", 1, 2);
		retorno = 0;
	}
	return retorno;
}
	//agregar if(cantidadDatos > 0). Esto se agrega en el main con el contador

int ModificarDatos (Passenger lista[], int tam, TypePassenger lista2[], int tam2){
	int retorno;
	int idMod;
	int opcionMod;
	int retornoInforme;
	int index;

	retorno = 0;

	if (lista != NULL && lista2 != NULL && tam > 0 && tam2 > 0 ){

		retornoInforme = printPassenger(lista, tam);
		if (retornoInforme == -1){
			printf ("Error al mostrar pasajeros\n");
		}

	idMod = PedirEntero ("Ingrese el id del pasajero del cual desdea modificar los datos: \n", 1, 2000);

	index = findPassengerById(lista, tam, idMod);

	for(int i = 0; i<tam; i++){
		if (lista[i].id == idMod && lista[i].isEmpty == 0){
			do{
				printf("Menu de modificaciones\n");
				printf("1)Nombre\n");
				printf("2)Apellido\n");
				printf("3)Precio\n");
				printf("4)Tipo de pasajero\n");
				printf("5)Codigo de vuelo\n");
				printf("6)Salir");
				opcionMod = PedirEntero ("Seleccione una opcion: \n", 1, 6);

				switch (opcionMod){
				case 1:
					PedirCadena("Ingrese el nuevo nombre: \n", lista[index].name);
					break;

				case 2:
					PedirCadena("Ingrese el nuevo apellido: \n", lista[index].lastName);
					break;

				case 3:
					lista[index].price = PedirFlotante("Ingrese el nuevo precio:\n");
					break;

				case 4:
					ImprimirTiposPasajero(lista2, tam2);
					lista[index].typePassenger = PedirEntero ("Ingrese el nuevo tipo de pasajero: \n", 1, tam2);
					break;

				case 5:
					PedirCadena("Ingrese el nuevo codigo de vuelo: \n", lista[index].flycode);
					break;
					}
				}while (opcionMod!= 6);
				retorno = 1;
			}
		}
	}

	return retorno;
}

int removePassenger(Passenger* list, int len, int id){
	int retorno;
	int index;

	retorno = -1;

	index = findPassengerById(list, len, id);

	if (index > -1){
		list[index].isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}

/** \brief find a Passenger by Id en returns the index position in array.
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len, int id)
{
	int retorno;
	retorno = -1;

	if (list != NULL && len > 0){
		for(int i =0; i<len; i++){
			if (list[i].id == id && list[i].isEmpty == 0){
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


void Ordenar (Passenger list[], int i, int j){
	Passenger aux;

	aux = list[i];
	list[i] = list[j];
	list[j] = aux;
}


/// @fn int sortPassengers(Passenger*, int, int) Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o descendente.
/// @param list
/// @param len
/// @param order
/// @return
///

int sortPassengers(Passenger* list, int len, int order) //order>0: ascendente, order<1: descendente
{
	int retorno;
	retorno = -1;

	if (list!=NULL && len>0){
		if (order > 0) //ASCENDENTE
		{
			for (int i=0; i<len; i++)
			{
				for(int j=i+1; j<len-1; j++)
				{
					if(strcmp(list[i].lastName, list[j].lastName) > 0 )
					{
						Ordenar(list, i, j);
					}
					else
					{
						if (list[i].typePassenger > list[j].typePassenger){
							Ordenar(list, i, j);
						}
					}
				}
			}
		}
		else //DESCENDENTE
		{
			for (int i=0; i<len; i++)
			{
				for(int j=i+1; j<len-1; j++)
				{
					if(strcmp(list[i].lastName, list[j].lastName) < 0)
					{
						Ordenar(list, i, j);
					}
					else
					{
						if ( list[i].typePassenger < list[j].typePassenger){
							Ordenar(list, i, j);
						}
					}
				}
			}
		}

		retorno = 0;
	}

	return retorno;
}

/**@fn Ordena el array de pasajeros por código de vuelo y estado de vuelo de manera ascendente o descendente.
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*/
int sortPassengersByCode(Passenger list[], int len, int order){
	int retorno;
	retorno = -1;

	if (list!=NULL && len>0){
			if (order == 1){
				for (int i=0; i<len; i++)
				{
					for(int j=i+1; j<len-1; j++)
					{
						if(strcmp(list[i].flycode, list[j].flycode) > 0)
						{
							Ordenar(list, i, j);
						}
						else{
							if(list[i].statusFlight > list[j].statusFlight){
								Ordenar(list, i, j);
							}
						}
					}
				}
			}
			else //DESCENDENTE
			{
				if (order == 0){
					for (int i=0; i<len; i++)
					{
						for(int j=i+1; j<len-1; j++)
						{
							if(strcmp(list[i].flycode, list[j].flycode) < 0)
							{
								Ordenar(list, i, j);
							}
							else{
								if( list[i].statusFlight < list[j].statusFlight){
									Ordenar(list, i, j);
								}
							}
						}
					}
				}
			}

			retorno = 0;
		}

	return retorno;
}

int ImprimirActivos (Passenger lista[], int len){
	int retorno;
	retorno = -1;
	printf ("%4s | %6s | %6s | %8s | %8s | %10s | %12s\n", "id", "Name", "Last Name", "Price", "Fly Code", "Type Passenger", "Status Flight");

	sortPassengersByCode(lista, len, 1);

	for(int i=0; i<len; i++){
		if(lista[i].statusFlight == 1){
			ImprimirUnPasajero(lista[i]);
			retorno = 0;
		}
	}
	return retorno;
}

int MostrarTotalYPromedioDePrecios (Passenger lista[], int len){
	int i;
	int retorno;
	int contador;
	int cantSuperanPromedio;
	float sumaPrecios;
	float promedio;

	retorno = 0;
	contador = 0;
	sumaPrecios = 0;
	cantSuperanPromedio = 0;

	for (i=0; i<len; i++){
		if (lista[i].isEmpty == 0){
			sumaPrecios = sumaPrecios + lista[i].price;
			contador ++;
		}
	}

	promedio = (float)sumaPrecios / contador;

	for (i=0; i<len; i++){
		if (lista[i].isEmpty == 0){
			if (lista[i].price > promedio){
				cantSuperanPromedio ++;
			}
		}
	}

	printf("El total de los precios de los pasajes es: %.2f\n", sumaPrecios);
	printf("El promedio de los precios de los pasajes es: %.2f\n", promedio);
	printf("%d pasajeros superan el promedio de los precios de los pasajes\n", cantSuperanPromedio);

	return retorno;
}

int Informar (Passenger lista[], int len){
	int opcion;
	int retorno;

	retorno = 0;

	do{
		printf("1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero\n");
		printf("2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio\n");
		printf("3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO'\n");
		printf("4. Salir\n");

		opcion = PedirEntero ("Seleccione una opcion: \n", 1, 4);

		switch(opcion){
		case 1:
			sortPassengers(lista, len, 1);
			printPassenger(lista, len);
			break;

		case 2:
			MostrarTotalYPromedioDePrecios(lista, len);
			break;

		case 3:
			ImprimirActivos(lista, len);
			break;
		}
		retorno = 1;
	}while(opcion != 4);

	return retorno;
}
