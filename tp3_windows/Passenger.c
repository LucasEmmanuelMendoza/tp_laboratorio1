#include "Passenger.h"

int Passenger_setId(Passenger* this, int id){
	int retorno;
	retorno = -1;

	if (this!=NULL){
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getId(Passenger* this, int* id){
	int retorno;
	retorno = -1;

	if(this != NULL){
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setNombre (Passenger* this, char* nombre){
	int retorno;
	retorno = -1;

	if(this != NULL){
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}

int Passenger_getNombre(Passenger* this, char* nombre){
	int retorno;
	retorno = -1;

	if(this != NULL){
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setApellido(Passenger* this, char* apellido){
	int retorno;
	retorno = -1;

	if(this!=NULL && apellido !=NULL){
		strcpy(this->apellido, apellido);
		retorno = 0;
	}

	return retorno;
}

int Passenger_getApellido(Passenger* this, char* apellido){
	int retorno;
	retorno = -1;

	if(this != NULL){
		strcpy( apellido, this->apellido);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo){
	int retorno;
	retorno = -1;

	if(this!=NULL && codigoVuelo !=NULL){
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}

	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo){
	int retorno;
	retorno = -1;

	if(this != NULL){
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero){
	int retorno;
	retorno = -1;

	if(this!=NULL){
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}

	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero){
	int retorno;
	retorno = -1;

	if(this != NULL){
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setPrecio(Passenger* this, float precio){
	int retorno;
	retorno = -1;

	if(this != NULL && precio>0){
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}

int Passenger_getPrecio(Passenger* this, float* precio){
	int retorno;
	retorno = -1;

	if(this!=NULL){
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setEstadoDeVuelo(Passenger* this, int estadoDeVuelo){
	int retorno;
	retorno = -1;

	if(this !=NULL){
		this->estadoDeVuelo = estadoDeVuelo;
		retorno = 0;
	}

	return retorno;
}

int Passenger_getEstadoDeVuelo(Passenger* this, int* estadoDeVuelo){
	int retorno;
	retorno = -1;

	if(this != NULL){
		*estadoDeVuelo = this->estadoDeVuelo;
		retorno = 0;
	}

	return retorno;
}

void Passenger_delete(Passenger* this){
	if(this != NULL){
		free(this);
	}
}

PassengerBinary* PassengerB_new(){
	PassengerBinary* pasajeroB;

	pasajeroB = (PassengerBinary*)malloc(sizeof(PassengerBinary));

	if(pasajeroB != NULL){
		pasajeroB = calloc(1, sizeof(PassengerBinary));
	}

	return pasajeroB;

}

Passenger* Passenger_new(){
	Passenger* pasajero;

	pasajero = (Passenger*)malloc(sizeof(Passenger));

	if (pasajero != NULL){
		pasajero = calloc(1, sizeof(Passenger));
	}

	return pasajero;
}

Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoDeVueloStr, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2){
	Passenger* pasajero;

	int auxTipoPasajero;
	int auxEstadoDeVuelo;
	int i;
	int j;

	pasajero = Passenger_new();

	for(j=0; j<tam2; j++){
		if(strcmp(tiposPasajero[j].descripcion, tipoPasajeroStr)==0){
			auxTipoPasajero = tiposPasajero[j].id;
			break;
		}
	}

	for(i=0; i<tam1; i++){
		if(strcmp(estadosDeVuelo[i].descripcion, estadoDeVueloStr)==0){
			auxEstadoDeVuelo = estadosDeVuelo[i].id;
			break;
		}
	}

	if(pasajero != NULL){
		Passenger_setId(pasajero, atoi(idStr));
		Passenger_setNombre(pasajero, nombreStr);
		Passenger_setApellido(pasajero, apellidoStr);
		Passenger_setPrecio(pasajero, atof(precioStr));
		Passenger_setCodigoVuelo(pasajero, codigoVueloStr);
		Passenger_setTipoPasajero(pasajero, auxTipoPasajero);
		Passenger_setEstadoDeVuelo(pasajero, auxEstadoDeVuelo);
	}

	return pasajero;
}


void PrintOnePassenger (Passenger* pasajero, StatusFlight estadosDeVuelo[], int tam1, TypePassenger tiposPasajero[], int tam2){
	int i;
	int j;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	int estadoDeVuelo;
	int tipoPasajero;

	if(pasajero != NULL){
		Passenger_getEstadoDeVuelo(pasajero, &estadoDeVuelo);
		Passenger_getTipoPasajero(pasajero, &tipoPasajero);
		for(i=0; i<tam1; i++){
			if(estadoDeVuelo == estadosDeVuelo[i].id){
				for(j=0; j<tam2; j++){
					if(tipoPasajero == tiposPasajero[j].id){
						Passenger_getId(pasajero, &id);
						Passenger_getNombre(pasajero, nombre);
						Passenger_getApellido(pasajero, apellido);
						Passenger_getPrecio(pasajero, &precio);
						Passenger_getCodigoVuelo(pasajero, codigoVuelo);
						printf("%4d - %15s - %15s - %7.2f - %15s - %15s - %20s\n", id, nombre, apellido, precio, codigoVuelo,tiposPasajero[j].descripcion, estadosDeVuelo[i].descripcion);
					}
				}
			}
		}
	}
}

void PrintEstadosVuelo(StatusFlight estadosDeVuelo[], int tam1){
	printf("%s - %s \n", "Id", "Descripcion");
		for(int i=0; i<tam1; i++){
			printf("%d - %s\n", estadosDeVuelo[i].id, estadosDeVuelo[i].descripcion);
		}
}

void PrintTiposPasajero(TypePassenger tiposPasajero[], int tam2){
	printf("%s - %s \n", "Id", "Descripcion");
	for(int i=0; i<tam2; i++){
		printf("%d - %s\n", tiposPasajero[i].id, tiposPasajero[i].descripcion);
	}
}

Passenger* Passenger_getPassengerById(LinkedList* this, int tam, int idBusqueda){
	Passenger* pasajero;

	if(this!= NULL){
		for(int i=0; i<tam ; i++){
			pasajero = ll_get(this, i);
			if(pasajero->id == idBusqueda){
				break;
			}
		}
	}
	return pasajero;
}

int CompararNombre(void* pasajero1, void* pasajero2){
	int retorno;
	char nombre1[50];
	char nombre2[50];
	retorno = -1;

	pasajero1 = (Passenger*) pasajero1;
	pasajero2 = (Passenger*) pasajero2;

	Passenger_getNombre(pasajero1, nombre1);
	Passenger_getNombre(pasajero2, nombre2);

	retorno = strcmp(nombre1, nombre2);

	return retorno;
}

int CompararApellido(void* pasajero1, void* pasajero2){
	int retorno;
	char apellido1[50];
	char apellido2[50];
	retorno = -1;

	pasajero1 = (Passenger*) pasajero1;
	pasajero2 = (Passenger*) pasajero2;

	Passenger_getNombre(pasajero1, apellido1);
	Passenger_getNombre(pasajero2, apellido2);

	retorno = strcmp(apellido1, apellido2);

	return retorno;
}
