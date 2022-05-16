/*
 * ArrayPassenger.h
 *
 *  Created on: 15 may. 2022
 *      Author: VAIO
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define TRUE 1
#define FALSE 0
 typedef struct
{
    int id;
    char lastName[51];
    char name[51];
    float price;
    char flycode[50];
    int typePassenger;
    int statusFlight;
    int isEmpty;
} ePassenger;

int mainMenu();
/** \brief Funcion encargada imprimir en pantalla un menu
 *
 * \param La funcion no recibe parametros
 * \param La funcion no recibe parametros
 * \return Retorna el valor  entero "option"
 *
 */
int initPassengers(ePassenger* list, int len);
/** \brief Funcion encargada de inicializar todos los elementos del array de pasajeros en un estado libre para cargar datos
 *
 * \param pasajeros* Recibe un puntero al array de pasajeros
 * \param int recibe la cantidad de elementos en el array
 * \return int retorna -1 si hubo algun error y 0 si no hubo ningun error
 *
 */
int generateNextId();
/** \brief Funcion encargada de genera un numero de ID y autoincrementarlo
 *
 * \param La funcion no recibe parametros
 * \param La funcion no recibe parametros
 * \return Retorna el ID generado autoincrementado
 *
 */
int loadPassenger(ePassenger* list,int len);

int sortPassengers(ePassenger* list, int len, int order);
/** \brief Funcion encargada de validar si existe un empleado cargado en el array
 *
 * \param list pasajeros* Recibe un puntero al array de pasajeros
 * \param len int la cantidad de elementos en el array
 * \return int Retorna -1 si no hay pasajeros y 0 si encontro
 *
 */

int sortCodexActive(ePassenger* list, int len);
/** \brief Funcion encargada de validar si existe un empleado cargado en el array
 *
 * \param list pasajeros* Recibe un puntero al array de pasajeros
 * \param len int la cantidad de elementos en el array
 * \return int Retorna -1 si no hay pasajeros y 0 si encontro
 *
 */

void printOnePassengers(ePassenger passanger);
/** \brief Funcion encargada de mostrar a un pasajeros
 *
 * \param pasajeros Recibe un dato de tipo pasajeros
 * \return void La funcion no retorna nada
 *
 */

int findPriceMax(ePassenger* list, int len);
/** \brief Funcion encargada de ordenar a los pasajeros ascendente o descendentemente por apellido y si los apellidos se repiren por sector
 *
 * \param pasajeros* Recibe un puntero al array de pasajeros
 * \param int Recibe la cantidad de elementos en el array
 * \return int Retorna -1 si hubo algun error y 0 si se pudieron ordenar los datos correctamente
 *
 */

int printPassenger(ePassenger* list, int length);
/** \brief Funcion encargada de mostrar el listado de todos los pasajeros
 *
 * \param pasajeros* Recibe un puntero al array de pasajeros
 * \param int recibe la cantidad de elementos en el array
 * \return int Retorna -1 si hubo algun error y 0 si se pudieron mostrar los pasajeros correctamente
 *
 */

int findPassengersById(ePassenger* list, int len,int id);
/** \brief Funcion que busca al pasajeros por su numero de ID
 *
 * \param pasajeros* Recibe un puntero al array de pasajeros
 * \param int recibe la cantidad de elementos en el array
 * \param int recibe el ID generado
 * \return int retorna la posicion del array donde se encuentra el ID generado
 *
 */


int findPassengersFreeSpace(ePassenger* list, int len);
/** \brief Funcion encargada de buscar algun espacio libre en el array de pasajeros para cargar un nuevo dato
 *
 * \param pasajeros* Recibe un puntero al array de pasajeros
 * \param int recibe la cantidad de elementos en el array
 * \return int Retorna la primera posicion libre que encuentra la funcion
 *
 */
int modifyPassenger(ePassenger* list, int len, int id);
/** \brief Funcion encargada de buscar al pasajeros y modificarlo
 *
 * \param pasajeros* Recibe un puntero al array de empleados
 * \param int recibe la cantidad de elementos en el array
 * \return int Retorna -1 si hubo un error y 0 si se pudo modificar correctamente al pasajeros
 *
 */

int removePassenger(ePassenger* list, int len, int id);
/** \brief Funcion encargada de dar de baja a un pasajeros
 *
 * \param pasajeros* Recibe un puntero al array de pasajeros
 * \param int Recibe la cantidad de elementos en el array
 * \return int Retorna -1 si hubo un error o 0 si se dio de baja exitosamente
 *
 */

int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger,int status, char flycode[]);
/** \brief Funcion encargada de añadir a los pasajeros en la estructura
 *
 * \param list pasajeros* Recibe un puntero al array de pasajeros
 * \param len int recibe la cantidad de elementos en el array
 * \param id int recibe el ID generado
 * \param name[] char recibe un array de caracteres para guardar el nombre del pasajeros
 * \param lastName[] char recibe un array de caracteres para guardar el apellido del pasajeros
 * \param salary float  Recibe una variable flotante para guardar el salario del pasajeros
 * \param sector int Recibe una variable entera para guardar el sector del pasajeros
 * \return int  Retorna -1 si hubo un error y 0 si el pasajeros fue cargado correctamente
 *
 */

#endif /* ARRAYPASSENGER_H_ */
