#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "ArrayPassenger.h"
#include "utn.h"
#define LEN 10

int main()
{
    char seguir;
    int nextId=1;
    int passangerExist=0;
    int loadExist=0;
    int option;
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
            printf("\n\t***MENU INFORMES***\n");
            printf("\n1. Listado Ordenado por Apellido y tipo");
            printf("\n2. Total y promedio de Precios y quienes superan el promedio");
            printf("\n3. Listado por codigo de vuelo y vuelos *ACTIVOS*");
            printf("\nElija una opcion:    ");
            scanf("%d",&option);
            switch(option)
            {
            case 1:
                sortPassengers(list,LEN,0);
                break;
            case 2:
                findPriceMax(list,LEN);
                break;
            case 3:
                sortCodexActive(list,LEN);
                break;
            }

            break;
        case 5:
            printf("\nConfirma salida?\t");
            setbuf(stdout,NULL);
            scanf("%c",&seguir);
            break;
        }
    }while(seguir!='s');
	return EXIT_SUCCESS;
}
