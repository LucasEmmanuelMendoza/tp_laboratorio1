#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
#define ESTADOSVUELO 4
#define TIPOSPASAJERO 3
#define MAXOPTION 10

int main()
{
	setbuf(stdout, NULL);

	int option;
	int flag1;
	int flag2;

	flag1 = 0;
	flag2 = 0;
    StatusFlight estadosVuelo[ESTADOSVUELO]={{1, "En Horario"},{2, "En Vuelo"},{3,"Aterrizado"},{4, "Demorado"}};
    TypePassenger tiposPasajero[TIPOSPASAJERO] = {{1, "EconomyClass"}, {2, "FirstClass"}, {3, "ExecutiveClass"}};

    LinkedList* listaPasajeros = ll_newLinkedList();


    do{
    	option = Menu(flag1, flag2, MAXOPTION);

        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros, estadosVuelo, ESTADOSVUELO, tiposPasajero, TIPOSPASAJERO);
                flag1 = 1;
                break;
            case 2:
            	flag2 = 1;
            	break;
            case 3:
            	controller_addPassenger(listaPasajeros, estadosVuelo, ESTADOSVUELO, tiposPasajero, TIPOSPASAJERO);
            	break;
            case 4:
            	controller_editPassenger(listaPasajeros, estadosVuelo, ESTADOSVUELO, tiposPasajero, TIPOSPASAJERO);
            	break;
            case 5:
            	controller_removePassenger(listaPasajeros, estadosVuelo, ESTADOSVUELO, tiposPasajero, TIPOSPASAJERO);
            	break;
            case 6:
            	controller_ListPassenger(listaPasajeros, estadosVuelo, ESTADOSVUELO, tiposPasajero, TIPOSPASAJERO);
            	break;
            case 7:
            	controller_sortPassenger(listaPasajeros);
            	break;
            case 8:
            	controller_saveAsText("data.csv",listaPasajeros, estadosVuelo, ESTADOSVUELO, tiposPasajero, TIPOSPASAJERO);
            	break;
            case 9:
            	//controller_saveAsBinary();
            	break;
        }
    }while(option != 10);
    return 0;
}

