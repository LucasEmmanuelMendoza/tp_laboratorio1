#include "Controller.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2)
{
	int retorno;
	int retornoParser;
	FILE* pArchivo;

	retorno = -1;

	pArchivo = fopen(path, "r");

	if (pArchivo != NULL){

		retornoParser = parser_PassengerFromText(pArchivo, pArrayListPassenger, estadosDeVuelo, tam1, tiposPasajero, tam2);

		if (retornoParser == 0){
			retorno = 0;
		}
	}

	fclose(pArchivo);

    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2)
{
	int retorno;
	FILE* pArchivo;

	retorno = -1;

	pArchivo = fopen(path, "rb");

	if(pArchivo != NULL && pArrayListPassenger != NULL){
		parser_PassengerFromBinary(pArchivo, pArrayListPassenger, estadosDeVuelo, tam1, tiposPasajero, tam2);
		retorno = 0;
	}else{
		printf("Error al cargar los datos\n");
	}

	return retorno;
}



/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2)
{
	Passenger* pasajero;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	int auxTipoPasajero;
	char auxCodigoVuelo[4];
	int auxEstadoVuelo;
	int retorno;
	int ultimoId;
	FILE* fileUltimoId;

	retorno = -1;

	pasajero = Passenger_new();

	fileUltimoId = fopen("ultimoId.txt", "r");
	fscanf(fileUltimoId, "%d", &ultimoId);
	fclose(fileUltimoId);

	ultimoId = ultimoId + 1;

	PedirCadena("Ingrese el nombre: \n", auxNombre);

	PedirCadena("Ingrese el apellido: \n", auxApellido);

	auxPrecio = PedirFlotante ("Ingrese el precio: \n");

	PedirCadena("Ingrese el codigo de vuelo: \n", auxCodigoVuelo);

	PrintTiposPasajero(tiposPasajero, tam2);
	auxTipoPasajero = PedirEntero("Ingrese el tipo de pasajero: \n", 1, tam2);

	PrintEstadosVuelo(estadosDeVuelo, tam1);
	auxEstadoVuelo = PedirEntero("Ingrese el estado de vuelo: \n", 1, tam1);

	Passenger_setId(pasajero, ultimoId);
	Passenger_setNombre(pasajero, auxNombre);
	Passenger_setApellido(pasajero, auxApellido);
	Passenger_setPrecio(pasajero, auxPrecio);
	Passenger_setCodigoVuelo(pasajero, auxCodigoVuelo);
	Passenger_setTipoPasajero(pasajero, auxTipoPasajero);
	Passenger_setEstadoDeVuelo(pasajero, auxEstadoVuelo);

	ll_add(pArrayListPassenger, pasajero);

	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2)
{
	int retorno;
	Passenger* pasajeroMod;
	int indicePasajero;
	int opcion;
	int idMod;
	int tam;
	int seguir=1;

	char nombreMod[50];
	char apellidoMod[50];
	float precioMod;
	char codigoVueloMod[4];
	int tipoPasajeroMod;
	int estadoVueloMod;

	retorno = -1;

	if(pArrayListPassenger!=NULL){
		controller_ListPassenger(pArrayListPassenger, estadosDeVuelo, tam1, tiposPasajero, tam2);

		tam = ll_len(pArrayListPassenger);

		idMod = PedirEntero("Ingrese el id del pasajero a modificar: \n", 1, tam);

		pasajeroMod = Passenger_getPassengerById(pArrayListPassenger, tam, idMod);

		indicePasajero = ll_indexOf(pArrayListPassenger, pasajeroMod);

		do{
			opcion = PedirEntero("Seleccione el dato que desea modificar: 1-Nombre\n 2-Apellido\n 3-Precio\n 4-Codigo De Vuelo\n 5-Tipo De Pasajero\n 6-Estado De Vuelo\n", 1, 6);

			switch(opcion){
			case 1:
				PedirCadena("\nIngrese el nuevo nombre: ", nombreMod);
				Passenger_setNombre(pasajeroMod, nombreMod);
				break;
			case 2:
				PedirCadena("\nIngrese el nuevo apellido: ", apellidoMod);
				Passenger_setNombre(pasajeroMod, apellidoMod);
				break;
			case 3:
				precioMod = PedirFlotante("\nIngrese el nuevo precio: ");
				Passenger_setPrecio(pasajeroMod, precioMod);
				break;
			case 4:
				PedirCadenaNums("\nIngrese el nuevo codigo de vuelo: ", codigoVueloMod);
				Passenger_setCodigoVuelo(pasajeroMod, codigoVueloMod);
				break;
			case 5:
				PrintTiposPasajero(tiposPasajero, tam2);
				tipoPasajeroMod = PedirEntero("\nIngrese el nuevo tipo de pasajero: ", 1, tam2);
				Passenger_setTipoPasajero(pasajeroMod, tipoPasajeroMod);
				break;
			case 6:
				PrintEstadosVuelo(estadosDeVuelo, tam1);
				estadoVueloMod = PedirEntero("\nIngrese el nuevo estado de vuelo: ", 1, tam1);
				Passenger_setEstadoDeVuelo(pasajeroMod, estadoVueloMod);
				break;
			}
			seguir = PedirEntero("Desea continuar modificando?\n", 1, 2);
		}while(seguir == 1);

		ll_set(pArrayListPassenger, indicePasajero, pasajeroMod);
	}

    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2)
{
	Passenger* pasajeroARemover;
	int indicePasajero;
	int retornoRemove;
	int retorno;
	int tamLista;
	int auxId;

	retorno = -1;

	if(pArrayListPassenger != NULL){
		tamLista = ll_len(pArrayListPassenger);

		//PrintPassengers(pArrayListPassenger, estadosDeVuelo,tam1, tiposPasajero, tam2);
		controller_ListPassenger(pArrayListPassenger, estadosDeVuelo, tam1, tiposPasajero, tam2);

		auxId = PedirEntero("Ingrese el id del pasajero a remover: ", 1, tamLista);

		pasajeroARemover = Passenger_getPassengerById(pArrayListPassenger, tamLista, auxId);

		indicePasajero = ll_indexOf(pArrayListPassenger, pasajeroARemover);

		retornoRemove = ll_remove(pArrayListPassenger, indicePasajero);

		if(retornoRemove == 0){
			printf("Pasajero removido con exito\n");
			retorno = 0;
		}
	}

	Passenger_delete(pasajeroARemover);

    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2)
{
	int retorno;
	Passenger* pasajero;
	int tam;

	retorno = -1;

		pasajero = Passenger_new();
		if(pArrayListPassenger != NULL){
			tam = ll_len(pArrayListPassenger);
			for(int i=0; i<tam; i++){
				pasajero = ll_get(pArrayListPassenger, i);
				PrintOnePassenger(pasajero, estadosDeVuelo, tam1, tiposPasajero, tam2);
			}
			retorno = 0;
		}

    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int retornoSort1;
	int retornoSort2;
	int opcion;
	retorno = -1;

	opcion = PedirEntero("1)Ordenar por nombre\n 2)Ordenar por apellido\n", 1, 2);

	if(pArrayListPassenger != NULL){
		switch(opcion){
			case 1:
				retornoSort1 = ll_sort(pArrayListPassenger, CompararNombre, 1);
				break;

			case 2:
				retornoSort2 = ll_sort(pArrayListPassenger, CompararApellido, 1);
				break;
		}
		if(retornoSort1 || retornoSort2){
			retorno = 0;
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2)
{
	int retorno;
	FILE* pArchivo;
	int tam;
	Passenger* pasajero;
	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	char auxCodigoVuelo[4];
	int auxTipoPasajero;
	int auxEstadoVuelo;
	char auxTipoPasajeroStr[20];
	char auxEstadoVueloStr[20];
	int j;

	retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL){
		pArchivo = fopen(path, "w");

		tam = ll_len(pArrayListPassenger);

		for(int i=0; i<tam; i++){
			pasajero = ll_get(pArrayListPassenger, i);
			Passenger_getId(pasajero, &auxId);
			Passenger_getNombre(pasajero, auxNombre);
			Passenger_getApellido(pasajero, auxApellido);
			Passenger_getPrecio(pasajero, &auxPrecio);
			Passenger_getCodigoVuelo(pasajero, auxCodigoVuelo);

			Passenger_getTipoPasajero(pasajero, &auxTipoPasajero);
			for(j=0; j<tam2; j++){
				if(tiposPasajero[j].id == auxTipoPasajero){
					strcpy(auxTipoPasajeroStr, tiposPasajero[j].descripcion);
				}
			}

			Passenger_getEstadoDeVuelo(pasajero, &auxEstadoVuelo);
			for(j=0; j<tam1; j++){
				if(estadosDeVuelo[j].id == auxEstadoVuelo){
					strcpy(auxEstadoVueloStr, estadosDeVuelo[j].descripcion);
				}
			}

			fprintf(pArchivo, "%d,%s,%s,%f,%s,%s,%s" , auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajeroStr, auxEstadoVueloStr);
		}
		retorno = 0;
	}

	fclose(pArchivo);

	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2){
	int retorno;
	int i;
	int j;
	int tamLista;
	Passenger* pasajero;
	PassengerBinary* pasajeroB;
	FILE* pArchivo;

	int idAux;
	char nombreAux[50];
	char apellidoAux [50];
	float precioAux;
	char codigoVueloAux[4];
	int tipoPasajeroAux;
	int estadoVueloAux;

	retorno = -1;

	pArchivo = fopen(path, "wb");

	if(path != NULL && pArrayListPassenger != NULL && estadosDeVuelo != NULL && tiposPasajero != NULL){
		tamLista = ll_len(pArrayListPassenger);

		if(pArchivo != NULL){
			for(i=0; i<tamLista; i++){
				pasajero = (Passenger*) ll_get(pArrayListPassenger, i);

				pasajeroB = PassengerB_new();

				Passenger_getId(pasajero, &idAux);
				pasajeroB->id = idAux;

				Passenger_getNombre(pasajero, nombreAux);
				strcpy(pasajeroB->nombre, nombreAux);

				Passenger_getApellido(pasajero, apellidoAux);
				strcpy(pasajeroB->apellido, apellidoAux);

				Passenger_getPrecio(pasajero, &precioAux);
				pasajeroB->precio = precioAux;

				Passenger_getCodigoVuelo(pasajero, codigoVueloAux);
				strcpy(pasajeroB->codigoVuelo, codigoVueloAux);

				Passenger_getTipoPasajero(pasajero, &tipoPasajeroAux);
				for(j=0; j<tam2; j++){
					if(tiposPasajero[j].id == tipoPasajeroAux){
						strcpy(pasajeroB->tipoPasajero, tiposPasajero[j].descripcion);
					}
				}

				Passenger_getEstadoDeVuelo(pasajero, &estadoVueloAux);
				for(j=0; j<tam1; j++){
					if(estadosDeVuelo[j].id == estadoVueloAux){
						strcpy(pasajeroB->estadoDeVuelo, estadosDeVuelo[j].descripcion);
					}
				}
				fwrite(pasajeroB, sizeof(PassengerBinary), 1, pArchivo);
			}
		}
	}

	fclose(pArchivo);

	return retorno;
}

