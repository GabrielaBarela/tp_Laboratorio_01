/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#include "Parser.h"

Passenger* Passenger_new()
{
	return(Passenger*)calloc(1,sizeof(Passenger));
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* priceStr,char* tipoPasajeroStr,char* codeStr)
{
	Passenger* auxPassenger = Passenger_new();

	if(auxPassenger != NULL)
	{
		int id = atoi(idStr);
		Passenger_setId(auxPassenger,id);
		int tipoPasajero = atoi(tipoPasajeroStr);
		Passenger_setTipoPasajero(auxPassenger,tipoPasajero);
		Passenger_setNombre(auxPassenger, nombreStr);
		Passenger_setApellido(auxPassenger,apellidoStr);
		Passenger_setCodigoVuelo(auxPassenger,codeStr);
		float price = atof(priceStr);
		Passenger_setPrecio(auxPassenger,price);


	}
	return auxPassenger;
}

void Passenger_delete(Passenger* this)
{
	if(this!=NULL)
	free(this);
}

int Passenger_setId(Passenger* this,int id)
{
	int todoOk=0;
	if(this!=NULL)
	{
		if(id>0)
		{
			this->id=id;
			todoOk=1;
		}
	}
	return todoOk;
}

int Passenger_getId(Passenger* this,int* id)
{
	int todoOk=0;
	if(this!=NULL)
	{
		*id = this->id;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int todoOk=0;
	if(this!=NULL && strlen(nombre)!=0)
	{
		strcpy(this->nombre,nombre);
		todoOk=1;
	}
	return todoOk;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int todoOk = 0;
	if(this!=NULL)
	{
		strcpy(nombre,this->nombre);
		todoOk=1;
	}
	return todoOk;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int todoOk=0;
	if(this!=NULL && strlen(apellido)!=0)
	{
		strcpy(this->apellido,apellido);
		todoOk=1;
	}
	return todoOk;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int todoOk = 0;
	if(this != NULL)
	{
		strcpy(apellido,this->apellido);
		todoOk=1;
	}
	return todoOk;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk=0;
	if(this!=NULL && strlen(codigoVuelo)!=0)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		todoOk=1;
	}
	return todoOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk=0;
	if(this!=NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		todoOk=1;
	}
	return todoOk;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int todoOk=0;
	if(this!=NULL)
	{
		if(tipoPasajero > 0 || tipoPasajero < 3)
		{
			this->tipoPasajero = tipoPasajero;
			todoOk=1;
		}
	}
	return todoOk;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int todoOk=0;
	if(this!=NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		todoOk=1;
	}
	return todoOk;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int todoOk=0;
	if(this!=NULL)
	{
		if(precio > 1000 || precio <1000000)
		{
			this->precio=precio;
			todoOk=1;
		}
	}
	return todoOk;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int todoOk=0;
	if(this!=NULL)
	{
		*precio= this->precio;
		todoOk=1;
	}
	return todoOk;
}


void mostrar_Passenger(Passenger* passengerAux)
{
	printf("%5d  %10s %10s %15.2f %10d %10s\n",passengerAux->id,passengerAux->nombre,passengerAux->apellido,passengerAux->precio,passengerAux->tipoPasajero,passengerAux->codigoVuelo);
}




