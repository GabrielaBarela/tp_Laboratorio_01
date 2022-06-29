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
    LinkedList* newList;///declaro un puntero
    newList=(LinkedList*)malloc(sizeof(LinkedList));///asigno memoria dinamica a la likend list
    if(newList !=NULL)///pregunt si le asigno el espacio en memoria
    {
        newList->size=0;///seteo sizeen 0 porque no posee vagones/nodos
        newList->pFirstNode=NULL;///seteo el primer nodo en null ya que no posee un primer nodo
    }
    return newList;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int cant = -1;
    if(this!=NULL)///pregunto si la linkes es nula
    {
        cant= this->size;///guardo el tam de la linkedlist
    }
    return cant;
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
    Node* nodo = NULL;///declaro un puntero a nodo auxiliar
    if(this !=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))///pregunto si la linked list es nula, si el indice pasado sea mayor o igual a 0 y si el indice es menor a tamaño de la linked list
    {
        nodo=this->pFirstNode;///guardo el puentero en el primer lugar/nodo de la linked list
        while(nodeIndex>0)
        {
            nodo=nodo->pNextNode;///el puntero pasa al siguiente lugar de la linked list
            nodeIndex--;
        }
    }
    return nodo;
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
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode=NULL;///asigno puntero
    Node*anterior=NULL;///asigno puntero
    if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))///pregunto si la linkedlist es nula y que el indice se encuentre dentro del rango
    {
        newNode=(Node*)malloc(sizeof(Node));
        if(newNode!=0)
        {
            newNode->pElement=pElement;///se agrega al nodo al que apunte
            newNode->pNextNode=NULL;///porque no tien nodo siguiente
            if(nodeIndex==0)
            {
                newNode->pNextNode=this->pFirstNode;
                this->pFirstNode=newNode;
            }
            else
            {
                anterior=getNode(this,nodeIndex-1);///se posisiona en el nodo anterior
                newNode->pNextNode = anterior->pNextNode;
                anterior->pNextNode=newNode;///el anterior nodo pasa a apuntar al nuevo nodo
            }
            this->size++;///aumento el tamaño de la lista
            returnAux=0;
        }
    }
    return returnAux;
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
    int returnAux = -1;
    if (this!=NULL)///verifico que el parametro no sea nulo
    {
        addNode(this,ll_len(this),pElement);///le agrego la fun addnode con el ultimo index para que se agregue al final
        returnAux=0;
    }

    return returnAux;
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
    void* returnAux = NULL;
    Node* pNode = NULL;///declaro un puntero a nodo aux

    if (this != NULL && index>=0 && index<ll_len(this))///pregunto si la  lista es nula y que el index este en el rango de la lista
    {
        pNode = getNode(this, index);///pido un nodo con otra funcion y le paso el index
        returnAux = pNode->pElement;///guardo en el return el elemento del nodo
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
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node*pNode=NULL;///puntero a nodoaux
    if(this!=NULL && index<ll_len(this)&& index>=0)///verifico que este pasando en el rango de la lista
    {
        pNode = getNode(this, index);///llamo a un nodo con getnode
        pNode->pElement = pElement;///cambio el elemento del nodo que llame
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode = NULL;///declaro un puntero a nodo auxiliar
    Node* pLeftNode = NULL;///declaro un puntero al nodo anterior al que voy a eliminar

    if (this != NULL && index >= 0 && index < ll_len(this))///pregunto que lista pasada no sea nula y que el indice se encuentre en el rango de la linkedlist
    {
        if (index == 0)///si el indice es 0
        {
            pNode = this->pFirstNode;///pnode pasa a apuntar a la direccion de memoria del primer nodo
            this->pFirstNode = pNode->pNextNode;///el primer nodo pasa a apuntar a la direccion de memoria del que sigue al nodo
    ///que tome
        }
        else if (index>=0 && index<ll_len(this))///si el indice es mayor a 0 y menor al size del linked list
        {
            pNode = getNode(this, index);///punteero a node toma la direccion de memoria del nodo del indice pasado
            pLeftNode = getNode(this, index-1);///pido la direccion de memoria del nodo a su izquierda
            pLeftNode->pNextNode = pNode->pNextNode;///el nodo a su izquierda pasa a apuntar al siguiente nodo
        }
        else///si el indice pasado es el ultimo del linked list
        {
            pLeftNode = getNode(this, ll_len(this)-1);///pido el nodo a la izquierda del indice
            pLeftNode->pNextNode = NULL;///el nodo a la izquierda pasa a apuntar a NULL
        }
        free(pNode);///libero al memoria del nodo que saque
        this->size--;///disminuyo el tamanio del linked list
        returnAux = 0;
    }
    return returnAux;
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

    int returnAux = -1;
    if (this != NULL)///verifico que la lista no sea nula
    {
        int i;
        for (i = 0; i < ll_len(this); i++)///recorro la lista
        {
            ll_remove(this, i);///elimino el nodo
        }
        returnAux = 0;
    }

    return returnAux;
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
    int returnAux = -1;
    if(this !=NULL)///pregunto si es nula lista
    {
        ll_clear(this);///elimino los lugares/nodos/vagones de la lista
        free(this);///limpio la memoria de la linked list
        returnAux=0;
    }

    return returnAux;
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
    int returnAux = -1;
    void* pAuxElement = NULL;///puntero a auxiliar de elemento

    if (this != NULL)///verifico que la lista pasada no sea nula
    {
        int i;
        for (i=0; i<ll_len(this); i++)///recorro toda la lista
        {
            pAuxElement = ll_get(this, i);///guardo el elemento de la posicion i en el auxiliar

            if (pAuxElement == pElement)///si el auxiliar es igual al elemento pasado como parametro
            {
                returnAux = i;///retorno el indice
                break;
            }
        }
    }
    return returnAux;
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
    int returnAux = -1;

    if (this != NULL)///verifica que la lista pasada no sea nula
    {
        returnAux = 1;

        if (this->size != 0)///verifica que el tamanio sea distinto a 0
        {
            returnAux = 0;
        }
    }
    return returnAux;
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
    int returnAux = -1;

    if (this != NULL && index >= 0 && index <= ll_len(this))///verifica que la lista no sa nula, y que el indice este dentro del rango
        ///del linked list
    {
        if (addNode(this, index, pElement) == 0)///agrega un nodo en la posicion pasada como parametro
        {
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if (this != NULL && index >= 0 && index < ll_len(this))///verifica que la lista no sea nula y que el indice este dentro del rango
        ///del linked list
    {
        returnAux = ll_get(this, index);///guardo la direccion de memoria en el retorno auxiliar
        ll_remove(this, index);///remuevo el nodo con el indice pasado como parametro
    }
    return returnAux;
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
    int returnAux = -1;
    if(this!=NULL)
    {
        if(ll_indexOf(this,pElement)>=0)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }
    return returnAux;
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
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
     int returnAux = -1;
    void* pAuxElement = NULL;///puntero a elemento auxiliar

    if (this != NULL && this2 != NULL)///verifico que las listas no sean nulas
    {
        returnAux = 1;
        int i;
        for (i=0; i < ll_len(this2); i++)///recorro la lista 2
        {
            pAuxElement = ll_get(this2, i);///guardo en el auxiliar el elemento i de this2
            if (ll_contains(this, pAuxElement) == 0)///verifico que el elemento i de this2 este en la lista this
            {
                returnAux = 0;///si no esta, guarda el retorno
                break;///sale del for
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if(!(this==NULL || from<0 || from>ll_len(this)|| to<=from||to>ll_len(this)))///pregunto si el dato es valido
    {
        cloneArray=ll_newLinkedList();///asigno memoria
        if(cloneArray!=NULL)
        {
            for(int i=from;i<to;i++)
            {
                ll_add(cloneArray,ll_get(this,i));
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)///pregunto si la lista es nula
    {
        cloneArray=ll_subList(this,0,ll_len(this));///llamo la funcion que va a clonar el index desde 0
    }

    return cloneArray;
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
    int returnAux =-1;
    void* auxElement;
    int tam;
    if(this!=NULL &&pFunc!=NULL &&order>=0&&order<=1)
    {
        tam=ll_len(this);
        for(int i=0; i<tam-1;i++)
        {
            for(int j=i+1;j<tam;j++)
            {
                if(pFunc(ll_get(this,i),ll_get(this,j))>0&& order==1)
                {
                    auxElement=ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,auxElement);
                }
                else if(pFunc(ll_get(this,i),ll_get(this,j))<0&& order==0)
                {
                    auxElement=ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,auxElement);
                }
            }
        }
        returnAux=0;
    }
    return returnAux;
}

