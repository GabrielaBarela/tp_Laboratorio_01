#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* auxPassenger = Passenger_new();
	int r;
	int i=0;
	char idAux[20],nameAux[50],lastNameaux[50],priceAux[50],typeAux[50],codeFly[50];

	if(pFile == NULL)
	{
		return -1;
	}

	r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,lastNameaux,priceAux,typeAux,codeFly);

	while(!feof(pFile))
	{
		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,lastNameaux,priceAux,typeAux,codeFly);
		if(r==4)
		{
			auxPassenger = Passenger_newParametros(idAux,nameAux,lastNameaux,priceAux,typeAux,codeFly);
			i++;
		}
		break;
	}
	printf("Se cargaron %d pasajeros a la lista con exito !\n", i);
    return i;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* passengerAux;

	int i =0;

	fread(&passengerAux, sizeof(Passenger),1,pFile);

	while(!feof(pFile))
	{
		Passenger* auxPassenger = Passenger_new();
		Passenger_setId(auxPassenger,passengerAux->id);
		Passenger_setNombre(auxPassenger,passengerAux->nombre);
		Passenger_setApellido(auxPassenger,passengerAux->apellido);
		Passenger_setCodigoVuelo(auxPassenger,passengerAux->codigoVuelo);
		Passenger_setTipoPasajero(auxPassenger,passengerAux->tipoPasajero);
		Passenger_setPrecio(auxPassenger,passengerAux->precio);
		i++;
		ll_add(pArrayListPassenger,passengerAux);
		fread(&passengerAux,sizeof(Passenger),1,pFile);
	}
	printf("Se han cargado %d de usuarios!\n", i);
    return 1;
}
