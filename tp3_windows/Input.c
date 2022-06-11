#include "Input.h"

int PedirEntero (char mensaje[], int min, int max)
{
	int i;
	int retorno;
	char numero[15];
	int tam;
	int numeroAux;

	retorno = 1;

	do {
		printf ("%s", mensaje);
		fflush(stdin);
		scanf ("%s", numero);
		tam = strlen (numero);

			for (i=0; i<tam; i++)
			{
				if (isdigit(numero[i]) == 0)
				{
					printf ("¡Error, debe ingresar un número entero!\n");
					printf ("%s", mensaje);
					fflush(stdin);
					scanf ("%s", numero);
					tam = strlen (numero);
					i=0;
				}
			}

			numeroAux = atoi (numero);

	}while (numeroAux < min || numeroAux > max);

	retorno = numeroAux;

	return retorno;
}

float PedirFlotante (char mensaje[])
{
	float retorno;
	char numero[30];
	int tam;

	printf ("%s", mensaje);
	scanf ("%s", numero);

	tam = strlen (numero);

	while(CAL_esFloat(numero, tam) == 0)
	{
		printf ("%s", mensaje);
		scanf ("%s", numero);

		tam = strlen (numero);
	}

	retorno = atof (numero);

	return retorno;
}

int CAL_esFloat(char cadena[], int dimension)
{
	int retorno;
	int i;
	int contadorPunto;

	contadorPunto = 0;
	retorno = 1;

	for (i = 0; i < dimension && cadena[i] != '\0'; i++) {
		if (i == 0 && (cadena[i] == '-' || cadena[i] == '+')) {
			continue;
		}
		if (cadena[i] > '9' || cadena[i] < '0') {
			if (cadena[i] == '.') {
				contadorPunto++;
				if (contadorPunto > 1) {
					retorno = 0;
					break;
				}

			} else {
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int PedirCadenaNums (char mensaje[], char cadena[])
{
	int i;
	int retorno;
	int tam;

	retorno = 0;

	printf ("%s", mensaje);
	fflush (stdin);
	scanf("%[^\n]", cadena);
	//gets (cadena);

	tam = strlen (cadena);

	for (i=0; i<tam; i++)
	{
		if (cadena[i] != 32 && isalpha(cadena[i]) == 0 && isdigit(cadena[i]) == 0) //32 = código ASCII del espacio //si lo que ingresó el usuario no es una letra
		{
			printf ("Error!!!");
			printf ("%s", mensaje);
			fflush (stdin);
			scanf("%[^\n]", cadena);
			//gets (cadena);
		}
	}

	//ArregloNombrePropio (cadena);

	return retorno;
}

int PedirCadena (char mensaje[], char cadena[])
{
	int i;
	int retorno;
	int tam;

	retorno = 0;

	printf ("%s", mensaje);
	fflush (stdin);
	scanf("%[^\n]", cadena);
	//gets (cadena);

	tam = strlen (cadena);

	for (i=0; i<tam; i++)
	{
		if (cadena[i] != 32 && isalpha(cadena[i]) == 0) //32 = código ASCII del espacio //si lo que ingresó el usuario no es una letra
		{
			printf ("Error!!!");
			printf ("%s", mensaje);
			fflush (stdin);
			scanf("%[^\n]", cadena);
			//gets (cadena);
		}
	}

	//ArregloNombrePropio (cadena);

	return retorno;
}

void ArregloNombrePropio (char cadena1[])
{
	int tam;
	tam = strlen (cadena1);
	int i;

	//strlwr (cadena1);

	for (i=0; i<tam; i ++)
	{
		if (i== 0 || cadena1[i-1] == 32)
		{
			cadena1[i] = toupper (cadena1[i]);
		}
	}
}

int Menu(int flag1, int flag2, int maxOption){
	int opcion;

	printf("Menu:1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n3. Alta de pasajero\n4. Modificar datos de pasajero\n5. Baja de pasajero\n6. Listar pasajeros\n7. Ordenar pasajeros\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n10. Salir\n");
	opcion = PedirEntero("Ingrese una opcion: \n", 1, maxOption);

	while((opcion == 1 && flag2 == 1) || (opcion == 2 && flag1 == 1)){
		opcion = PedirEntero("Ingrese una opcion: \n", 1, maxOption);
	}

	return opcion;
}

