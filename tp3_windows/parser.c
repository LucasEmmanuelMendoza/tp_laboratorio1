#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2)
{
	Passenger* pasajero;
	int retorno;

	char buffer[7][128];

	int retornoAdd;
	FILE* ultimoId;

	retorno = -1;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);

	do{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);

		pasajero = Passenger_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], estadosDeVuelo, tam1, tiposPasajero, tam2);

		retornoAdd = ll_add(pArrayListPassenger, pasajero);

		if(retornoAdd == 0){
			retorno = 1;
		}
		//printf("%s %s %s %s\n", buffer[0], buffer[1], buffer[2], buffer[3]);

		ultimoId = fopen("ultimoId.txt", "w");
		fprintf(ultimoId, "%s", buffer[0]);
		fclose(ultimoId);

	}while(!feof(pFile));

	return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2)
{
	int retorno;
	int i;
	PassengerBinary* pasajeroB;
	Passenger* pasajero;

	char auxEstadoVuelo[50];
	char auxTipoPasajero[50];

	retorno = -1;

	if(pFile != NULL && pArrayListPassenger != NULL){
		do{
			pasajero = Passenger_new();
			pasajeroB = PassengerB_new();

			if(pasajeroB != NULL){
				fread(pasajeroB, sizeof(Passenger), 1, pFile);

				Passenger_setId(pasajero, pasajeroB->id);
				Passenger_setNombre(pasajero, pasajeroB->nombre);
				Passenger_setApellido(pasajero, pasajeroB->apellido);
				Passenger_setPrecio(pasajero, pasajeroB->precio);
				Passenger_setCodigoVuelo(pasajero, pasajero->codigoVuelo);

				strcpy(auxEstadoVuelo, pasajeroB->estadoDeVuelo);
				strcpy(auxTipoPasajero, pasajeroB->tipoPasajero);

				for(i=0; i<tam1; i++){
					if(strcmp(estadosDeVuelo[i].descripcion, auxEstadoVuelo)==0){
						Passenger_setEstadoDeVuelo(pasajero, estadosDeVuelo[i].id);
					}
				}

				for(i=0; i<tam2; i++){
					if(strcmp(tiposPasajero[i].descripcion, auxTipoPasajero)){
						Passenger_setTipoPasajero(pasajero, tiposPasajero[i].id);
					}
				}

				if(feof(pFile)){
					break;
				}else
				{
					ll_add(pArrayListPassenger, pasajero);
				}
				retorno = 0;
			}

		}while(!feof(pFile));
	}

    return retorno;
}
