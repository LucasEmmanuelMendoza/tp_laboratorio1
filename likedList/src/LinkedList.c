#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = malloc (sizeof(LinkedList));

    if (this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int retorno;

	retorno = -1;

	if (this != NULL)
	{
		retorno = this->size;
	}
	return retorno;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */

static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* nodoReturn;
	int i;
	int tamLista;

	nodoReturn = NULL;

	if (this != NULL)
	{
		tamLista = ll_len(this);

		if(tamLista > nodeIndex && nodeIndex > -1)
		{
			nodoReturn = this->pFirstNode;

		 	 for (i=0; i<nodeIndex+1; i++)
			 {
		 		 if (i > 0)
		 		 {
		 		  nodoReturn = nodoReturn->pNextNode;
		 		 }
			 }
		}
	}

    return nodoReturn;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
	int retorno;
	int tamLista;
	Node* newNode;
	Node* nodoAnterior;

	retorno = -1;

	tamLista = ll_len (this);

	if (this != NULL && nodeIndex > -1 && nodeIndex <= tamLista)
	{
		newNode = (Node*) malloc (sizeof(Node));
		newNode->pNextNode = NULL;
		newNode->pElement = pElement;

		if (nodeIndex == 0)
		{
			newNode->pNextNode = this->pFirstNode;
			this->pFirstNode = newNode;
		}
		else
		{
			if (nodeIndex > 0)
			{
				nodoAnterior = getNode (this, nodeIndex-1);

				newNode->pNextNode = nodoAnterior->pNextNode;
				nodoAnterior->pNextNode = newNode;
			}
		}

		this->size ++;
		retorno = 0;
	}
	return retorno;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */


int ll_add(LinkedList* this, void* pElement)
{
	int retorno;
	int retornoAddNode;
	int tamLista;

	retorno = -1;

	if (this != NULL)
	{
		tamLista = ll_len(this);

		retornoAddNode = addNode (this, tamLista , pElement);

		if (retornoAddNode == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    Node* nodoAux;
    void* returnAux;
    int tamLista;

    returnAux = NULL;

    if (this != NULL)
    {
        tamLista = ll_len(this);

    	if ( index < tamLista && index > -1 )
    	{
    		nodoAux = getNode (this, index);

			returnAux = nodoAux->pElement;
    	}
    }
    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement)
{
    int retorno;
    int tamLista;
    Node* auxNode;

    retorno = -1;

    tamLista = ll_len (this);

    if (this != NULL && index >-1 && index < tamLista && index >-1)
    {
    	auxNode = getNode(this, index);
    	auxNode->pElement = pElement;
    	retorno = 0;
    }
    return retorno;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this, int index)
{
    int retorno;
    int tamLista;
    Node* nodoRemove;
    Node* nodoAnterior;

    retorno = -1;

    tamLista = ll_len(this);

    if (this != NULL && index >-1 && index < tamLista )
    {
    	nodoRemove = getNode (this, index);

    	if (index == 0)
    	{
    		this->pFirstNode = nodoRemove->pNextNode;
    	}
    	else
    	{
    		if (index > 0)
    		{
    			nodoAnterior = getNode (this, index-1);

    			nodoAnterior->pNextNode = nodoRemove->pNextNode;
    		}
    	}
    	free (nodoRemove);

    	this->size = tamLista -1;

		retorno = 0;
    }
    return retorno;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	int retorno;
	int tamLista;
	int i;

	retorno = -1;

	tamLista = ll_len (this);

	if (this != NULL)
	{
		for (i=0; i<tamLista; i++)
		{
			ll_remove (this, i);
			retorno = 0;
		}
	}
	return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int retorno;
    retorno = -1;

    if (this != NULL)
    {
    	free (this);
    	retorno = 0;
    }
    return retorno;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int retorno;
    int i;
    int tamLista;
    Node* nodo;

    tamLista = ll_len(this);

    retorno = -1;

    for (i=0; i<tamLista; i++)
    {
    	nodo = getNode (this, i);

    	if (nodo->pElement == pElement)
    	{
    		retorno = i;
    		break;
    	}
    }
    return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
   int retorno;

   retorno = -1;

   if (this != NULL)
   {
	   retorno = 1;

	   if (this->size > 0)
	   {
		   retorno = 0;
	   }

   }
   return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

int ll_push(LinkedList* this, int index, void* pElement)
{
    int retorno;
    int tam;
    int retornoAddNode;

    retorno = -1;
    tam = ll_len(this);

    if (this != NULL && index >-1 && index <= tam)
    {
    	retornoAddNode = addNode (this, index, pElement);
    	if (retornoAddNode == -1)
    	{
    		printf ("Error al agregar un elemento");
    	}

    	retorno = 0;
    }
    return retorno;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */

void* ll_pop(LinkedList* this, int index)
{
    void* retorno;
    int tam;

    tam = ll_len(this);

    if (this != NULL && index >-1 && index <tam)
    {
    	retorno = ll_get (this, index);

        ll_remove (this, index);
    }

    return retorno;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
	int retorno;
	int tam;
	int i;
	Node* nodoGet;

	retorno = -1;

	if (this!= NULL)
	{
		tam = ll_len (this);

		retorno = 0;

		for (i=0; i<tam; i++)
		{
			nodoGet = getNode (this, i);

			if (nodoGet->pElement == pElement)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
	int retorno;
	Node* nodo2;
	int i;
	int tam2;

	retorno = -1;

	if (this != NULL && this2 != NULL)
	{
		tam2 = ll_len (this2);

		 retorno = 1;

		for (i=0; i<tam2; i++)
		{
 			 nodo2 = getNode (this2, i);

 			 if (ll_contains(this, nodo2->pElement) == 0)
 			 {
 			 	retorno = 0;
 			 	break;
 			 }
		}
	}
	return retorno;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a las listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this, int from, int to)
{
    LinkedList* listReturn;
    void* element;
    int i;
    int tamLista;

    listReturn = NULL;

    if (this != NULL)
    {
    	tamLista = ll_len(this);

    	if (from >-1 && from < tamLista && to> from && to <=tamLista)
    	{
        	listReturn = ll_newLinkedList();

        		for (i=from; i<to; i++)
        		{
        			element = ll_get (this, i);

        			ll_add (listReturn, element);
        		}
    	}
    }

    return listReturn;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* listaClonada;
    int retornoContains;
    LinkedList* retorno;
    int tam;

    listaClonada = NULL;

    if (this != NULL)
    {
    	listaClonada = (LinkedList*) malloc (sizeof(LinkedList));

    	tam = ll_len(this);

    	listaClonada = ll_subList (this, 0, tam);

    	retornoContains = ll_containsAll(listaClonada, this);

    	if (retornoContains == 1)
    	{
    		retorno = listaClonada;
    	}
    }
    return retorno;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int retorno;
    int i;
    int j;
    int tamLista;
    void* element1;
    void* element2;
    void* auxElement;

    retorno = -1;

    if (this!=NULL && pFunc != NULL && (order == 0 || order == 1))
    {
    	tamLista = ll_len (this);

    	for (i=0; i <tamLista-1; i++)
    	{
    		for (j=i+1; j<tamLista; j++)
    		{
    			element1 = ll_get (this, i);
    			element2 = ll_get (this, j);

    			if ((order == 1 && pFunc(element1, element2) >0) || (order == 0 && pFunc(element1, element2) < 0))
    			{
					auxElement = element1;
					ll_set (this, i, element2);
					ll_set (this, j, auxElement);
    			}

    			retorno = 0;
    		}
    	}
    }
    return retorno;
}

