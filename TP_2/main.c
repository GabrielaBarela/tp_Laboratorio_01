/*
1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.
3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayPassenger.h"
#include "utn.h"

#define LEN 10
int main()
{
    char seguir;
    int nextId=1;
    int passangerExist=0;
    int loadExist=0;

    ePassenger list[LEN];
    ePassenger passanger;
    initPassengers(list,LEN);

            if(loadPassenger(list,LEN)==1)
            {
                printPassenger(list,LEN);
                printf("\n\n");
                loadExist=1;
            }
            else
            {
                printf("Error\n\n");
            }
    do
    {
        switch(mainMenu())
        {
        case 1:
            if(addPassenger(list,LEN,nextId,passanger.name,passanger.lastName,passanger.price,passanger.typePassenger,passanger.statusFlight,passanger.flycode)==0)
            {
                nextId++;
                passangerExist=1;
                printf("\nCargado con exito\n\n");
            }
            else
            {
                printf("Error\n\n");
            }
            break;
        case 2:
            if(passangerExist==1 || loadExist==1)
            {
                modifyPassenger(list,LEN,nextId);
            }
            else
            {
                printf("\nERROR!!!\nPrimero debe agregar un pasajero\n\n");
            }
            break;
        case 3:
            if(passangerExist==1 || loadExist==1)
            {
               removePassenger(list,LEN,nextId);
            }
            else
            {
                printf("\nERROR!!!\nPrimero debe agregar un pasajero\n\n");
            }
            break;
        case 4:
                findPriceMax(list,LEN);
                sortPassengers(list,LEN,0);
                sortCodexActive(list,LEN);
            break;
        case 5:
            printf("\nConfirma salida?\t");
            fflush(stdin);
            scanf("%c",&seguir);
            break;
        }
    }while(seguir!='s');
    return 0;
}
