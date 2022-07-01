#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "BIBLIOTECA.h"

int main()
{
    fflush(stdin);
    int flagKm=0;
    int flagPrice=0;
    int flagAllOk=0;
    int flagForced=0;

    char confirm;
    char choice='s';
    float kilometros=0;

    float price=0;
    float priceLATAM=0;

    float unitLatam=0;
    float unit=0;
    float priceDiscontLATAM=0;
    float priceInterestLATAM=0;
    float priceDiscont=0;
    float priceInterest=0;
    float bitLatam=0;
    float bit=0;
    float differece=0;


    //int flagKm=0;
    //int flagCa$h=0;

    do
    {
        switch(menu())
        {
        case 1:
            kilometros=requestKm();
            flagKm=1;
            break;
        case 2:
               price=requestPrice();
               priceLATAM=requestPriceLATAM();
               flagPrice=1;
            break;
        case 3:
            if(flagKm==1 && flagPrice==1)
            {
                priceDiscont=debitCard(price);
                priceInterest=creditCard(price);
                bit=bitCoin(price);
                unit=unitPrice(price,kilometros);

                priceDiscontLATAM=debitCard(priceLATAM);
                priceInterestLATAM=creditCard(priceLATAM);
                bitLatam=bitCoin(priceLATAM);
                unitLatam=unitPrice(priceLATAM,kilometros);

                differece=priceDifference(price,priceLATAM);

                printf("\nCalculando los datos\n");
            }
            else if(flagForced==1)
            {
                priceDiscont=debitCard(price);
                priceInterest=creditCard(price);
                bit=bitCoin(price);
                unit=unitPrice(price,kilometros);

                priceDiscontLATAM=debitCard(priceLATAM);
                priceInterestLATAM=creditCard(priceLATAM);
                bitLatam=bitCoin(priceLATAM);
                unitLatam=unitPrice(priceLATAM,kilometros);

                differece=priceDifference(price,priceLATAM);

                printf("\nCalculando los datos\n");
            }
            else
            {
                printf("\nERROR!!!\tIngrese todos los Datos\n");
            }
                flagAllOk=1;
            break;
        case 4:
            if(flagAllOk==1 || flagForced==1)
            {
                printf("\nKMs Ingresados: %.2f km",kilometros);
                printf("\n\nPrecio Aerolineas: $ %.2f",price);
                printf("\na)Precio con tarjeta de debito: $ %.2f",priceDiscont);
                printf("\nb)Precio con tarjeta de credito: $ %.2f",priceInterest);
                printf("\nc)Precio pagando con BITCOIN: $ %f",bit);
                printf("\nd)Mortrar precio unitario: $ %.2f",unit);
                printf("\n\nPrecio LATAM: $ %.2f",priceLATAM);
                printf("\na)Precio con tarjeta de debito: $ %.2f",priceDiscontLATAM);
                printf("\nb)Precio con tarjeta de credito: $ %.2f",priceInterestLATAM);
                printf("\nc)Precio pagando con BITCOIN: $ %f",bitLatam);
                printf("\nd)Mortrar precio unitario: $ %.2f",unitLatam);
                printf("\n\nLa diferencia de precio es: $ %.2f\n",differece);
            }
            break;

        case 5:
            kilometros=123000;
            price=100000;
            priceLATAM=200000;
            printf("\nCarga forzosa ejecutada");
            flagForced=1;

            break;

        case 6:
            printf("\nConfirmar salida? (s/n)\n - ");
            fflush(stdin);
            scanf("%c",&confirm);
            if(confirm=='s')
            {
                choice='n';
            }
            fflush(stdin);
        }
        system("pause");
        system("cls");
    }
    while(choice == 's');

    return 0;
}
