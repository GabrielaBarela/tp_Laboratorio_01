#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayPassenger.h"
#include "utn.h"

int mainMenu()
{
    int option;

    printf("\t ******MENU DE OPERACIONES******\n\t ------------------------------\n\t|  1 .ALTA                     |\n\t|  2 .MODIFICAR                |\n\t|  3 .BAJA                     |\n\t|  4 .INFORMAR                 |\n\t|  5 .SALIR                    |\n\t ------------------------------\n\nElija una opcion: ");
    setbuf(stdout,NULL);
    scanf("%d",&option);

    return option;
}


void printOnePassengers(ePassenger passanger)
{
    printf("%d %7s %10s %15.3f %7d %10d %15s\n",passanger.id,passanger.name,passanger.lastName,passanger.price,passanger.statusFlight,passanger.typePassenger,passanger.flycode);
}


int printPassenger(ePassenger* list, int length)
{
    int base=-1;
    int i;
    if(list!=NULL && length>0)
    {
        printf("\nID   Nombre  Apellido       Precio      Estado       Tipo     Codigo  \n\n");
        for(i=0;i<length;i++)
        {
            if(list[i].isEmpty==0)
            {
                printOnePassengers(list[i]);
            }
        }
        base=0;
    }
    return base;
}


int initPassengers(ePassenger* list, int len)
{
    int base=-1;
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0;i<len;i++)
            {
                list[i].isEmpty=TRUE;///si esta vacio 1=verdadero 0=flaso
                base=0;
            }
    }
    return base;
}


int findPassengersFreeSpace(ePassenger* list, int len)
{
    int head=-1;
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty == TRUE)
        {
            head= i;
            break;
        }
    }
    return head;
}


int generateNextId()
{
    static int id=0;
    id ++;
    return id;
}


int findPassengersById(ePassenger* list, int len,int id)
{
    int head=-1;
    int i;
    for(i=0; i < len; i++)
    {
        if(list[i].isEmpty == FALSE && list[i].id == id)
        {
            head = i;
            break;
        }
    }
    return head;
}


int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger,int status, char flycode[])
{
    int base;
    int head=-1;
    if(list!=NULL && name!=NULL && lastName !=NULL && flycode !=NULL)
    {
        base=findPassengersFreeSpace(list,len);
        if(base!= -1)
        {
            system("cls");
            printf("\nAlta Pasajeros\n");

            list[base].id=generateNextId();
            id++;

            getValidString("Ingrese nombre :","ERROR,ingrese el nombre nuevamente (solo letras)","ERROR, se exedio del limite de la cadena\n",name,1,51);
            setbuf(stdout,NULL);
            strcpy(list[base].name,name);

            getValidString("Ingrese apellido :","ERROR, ingrese apellido nuevamente (solo letras)","ERROR, se exedio del limite de la cadena\n",lastName,1,51);
            setbuf(stdout,NULL);
            strcpy(list[base].lastName,lastName);

            getValidFloat("Ingrese precio :","ERROR ingrese precio nuevamente (solo numeros)",0,1000000,&price);
            setbuf(stdout,NULL);
            list[base].price=price;

            printf("\nIngrese Codigo de vuelo: ");
            setbuf(stdout,NULL);
            scanf("%s",flycode);
            strcpy(list[base].flycode,flycode);

            getValidInt("\nIngrese el tipo de pasajero: \n1.Vip\n2.Turista\n3.Promocional\n","ERROR ingrese Tipo nuevamente <1-3>",1,3,&typePassenger);
            setbuf(stdout,NULL);
            list[base].typePassenger=typePassenger;

            printf("\nIngrese el estado del vuelo: \n1.Activo\n2.Demorado\n3.Cancelado\n");
            scanf("%d",&status);
            list[base].statusFlight=status;

            list[base].isEmpty=FALSE;
            printf("\n\t***Alta del pasajero***\n");
            printf("\n\nID Nombre    Apellido    Precio      Estado       Tipo     Codigo  \n\n");
            printOnePassengers(list[base]);
            head=0;
        }
        else
        {
            printf("\nSISTEMA COMPLETO\n");
        }
    }
    return head;
}


int removePassenger(ePassenger* list, int len, int id)
{
    int head=-1;
    int base;
    char confirm;
    system("cls");
    printf("***Baja Pasajero***\n");

    printPassenger(list,len);

    printf("\nIngrese ID del Pasajero: ");
    scanf("%d",&id);
    base=findPassengersById(list,len,id);
    if(base==-1)
    {
        printf("\nNo hay registro de un Pasagero con el id: %d",id);
    }
    else
    {

        printOnePassengers(list[base]);
        printf("\nConfirma Baja?(s/n)");
        setbuf(stdout,NULL);
        scanf("%c",&confirm);

        if(confirm=='s')
        {
            list[base].isEmpty=TRUE;
            printf("\nSe a realizado la baja con exito\n");
        }
        else
        {
            printf("\nSe ha cancelado la operacion");
        }
    }
    return head;
}


int modifyPassenger(ePassenger* list, int len, int id)
{
    int head=-1;
    int base;
    int options;
    char confirm;

    char name[51];
    char lastName[51];
    char flyCode[10];
    float price;
    int typePassenger;
    int statusFlight;

        if(list!=NULL && len>0)
        {
            printf("Modificar Pasajeros");
            printPassenger(list,len);

            printf("\nIngrese Id:");
            scanf("%d",&id);

            base=findPassengersById(list,len,id);

            if(base==-1)
            {
                printf("\nNo hay registro de un Pasajero con el id: %d",id);
            }
            else
            {
                printOnePassengers(list[id]);

                printf("\nModificar empleado?(s/n)");
                fflush(stdin);
                scanf("%c",&confirm);
                if(confirm=='s')
                {
                    printf("\nQue desea modificar?");
                    printf("\n1.Nombre");
                    printf("\n2.Apellido");
                    printf("\n3.Precio");
                    printf("\n4.Codigo de vuelo");
                    printf("\n5.Tipo de Pasajero");
                    printf("\n6.Estatus de vuelo\n\n");
                    scanf("%d",&options);
                    switch(options)
                    {
                    case 1:
                        getValidString("Ingrese nombre :","ERROR,ingrese el nombre nuevamente (solo letras)","ERROR, se exedio del limite de la cadena\n",name,1,51);
                        setbuf(stdout,NULL);
                        strcpy(list[base].name,name);
                        break;
                    case 2:
                        getValidString("Ingrese apellido :","ERROR, ingrese apellido nuevamente (solo letras)","ERROR, se exedio del limite de la cadena\n",lastName,1,51);
                        setbuf(stdout,NULL);
                        strcpy(list[base].lastName,lastName);
                        break;
                    case 3:
                        getValidFloat("Ingrese precio :","ERROR ingrese precio nuevamente (solo numeros)",0,1000000,&price);
                        setbuf(stdout,NULL);
                        list[base].price=price;
                        break;
                    case 4:
                        printf("\nIngrese Codigo de vuelo: ");
                        setbuf(stdout,NULL);
                        gets(flyCode);
                        strcpy(list[base].flycode,flyCode);
                        break;
                    case 5:
                        getValidInt("\nIngrese el tipo de pasajero: \n1.Vip\n2.Turista\n3.Promocional\n","ERROR ingrese Tipo nuevamente <1-3>",1,3,&typePassenger);
                        setbuf(stdout,NULL);
                        list[base].typePassenger=typePassenger;
                        break;
                    case 6:
                        getValidInt("\nIngrese el estado del vuelo: \n1.Activo\n2.Demorado\n3.Cancelado\n","ERROR ingrese Tipo nuevamente <1-3>",1,3,&statusFlight);
                        setbuf(stdout,NULL);
                        list[base].statusFlight=statusFlight;
                        break;
                    }
                  printf("\nSe a realizado la modificacion con exito\n");
                }
                else
                {
                    printf("\nSe ha cancelado la operacion");
                }
            }
        }
    return head;
}


int sortPassengers(ePassenger* list, int len, int order)
{
    ePassenger auxP;
    int head=-1;
    int i;
    int j;
    if(list!=NULL && len>0)
    {
    for(i=0;i<len;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(list[i].isEmpty==0)
            {
                if(list[i].typePassenger>list[j].typePassenger)
                {
                    auxP=list[i];
                    list[i]=list[j];
                    list[j]=auxP;
                }
                else if(list[i].typePassenger == list[j].typePassenger)
                {
                    if(strcmp(list[i].lastName,list[j].lastName)>0)
                    {
                        auxP=list[i];
                        list[i]=list[j];
                        list[j]=auxP;
                    }
                    else if(strcmp(list[i].lastName,list[j].lastName)==order)
                    {
                        auxP=list[i];
                        list[i]=list[j];
                        list[j]=auxP;
                    }
                }
                head=1;
            }
        }
    }
    }
    printPassenger(list,len);
    return head;
}


int sortCodexActive(ePassenger* list, int len)
{
    ePassenger auxP;
    int head=-1;
    int i;
    int j;

    if(list!=NULL && len>0)
    {

        for(i=0;i<len;i++)
        {
            system("cls");
            for(j=i+1;j<len;j++)
            {
                if(list[i].isEmpty==0)
                {
                    if(list[i].flycode == list[j].flycode)
                    {
                        if(strcmp(list[i].flycode,list[j].flycode)<0)
                        {
                            auxP=list[i];
                            list[i]=list[j];
                            list[j]=auxP;
                        }
                        else if(strcmp(list[i].flycode,list[j].flycode))
                        {
                            auxP=list[i];
                            list[i]=list[j];
                            list[j]=auxP;
                        }
                    }
                    head=1;
                }
            }

    }
    printf("\n\nID Nombre    Apellido    Precio      Estado       Tipo     Codigo  \n\n");
        for(i=0;i<len;i++)
        {
           if(list[i].statusFlight==1 && list[i].isEmpty==0)
           {
               printOnePassengers(list[i]);
           }
        }
    }
    return head;
}


int findPriceMax(ePassenger* list, int len)
{
    float totalPrice=0;
    float avaragePrice=0;

    int averageCounter=0;
    int head=-1;
    int counterPassanger=0;

    int i;

    if(list!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==0 && list[i].price>0)
            {
                totalPrice+=list[i].price;
                counterPassanger++;
                head=1;
            }
            avaragePrice=totalPrice/counterPassanger;
            if(list[i].price>avaragePrice && list[i].isEmpty==0)
            {
                averageCounter++;
            }
        }
        printf("\nLa suma de todos los Precios es: %.2f\n",totalPrice);
        printf("El promedio de los Precios es: %.3f\n",avaragePrice);
        printf("La cantidad de pasajeros que superan el promedio es: %d\n",averageCounter);
    }
    return head;
}


int loadPassenger(ePassenger* list,int len)
{
    int head=-1;
    int i;

    int typePassenger[5]={1,2,3,1,2};
    int statusFlight[5]={1,2,1,2,1};

    char name[5][51]={"Juan","Pepito","Marcelo","Bautista","Teresa"};
    char lastName[5][51]={"Perez","Pepon","Piso","Benitez","Lomelio"};
    char flyCode[5][10]={"qqq222","eee333","www111","rrr444","ttt555"};

    float price[5]={100000,150000,300000,250000,200000};

    if(list!=NULL)
    {
        for(i=0;i<5;i++)
        {
            list[i].id=generateNextId();
            list[i].typePassenger=typePassenger[i];
            list[i].statusFlight=statusFlight[i];
            list[i].price=price[i];

            strcpy(list[i].name,name[i]);
            strcpy(list[i].lastName,lastName[i]);
            strcpy(list[i].flycode,flyCode[i]);

            list[i].isEmpty=0;
        }
        head=1;
    }
    printf("\n\t***Harcodeo con EXITO!!!***");
    return head;
}
