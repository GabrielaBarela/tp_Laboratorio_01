#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int choice;
    printf("\n1.  Ingrese Kilometros: (km=x)\n");
    printf("\n2.  Ingresar Precio de Vuelos:\n");
    printf("\n3.  Calcular todos los costos:\n");
    printf("\n4.  Informar Resultados\n");
    printf("\n5.  Cargar forzada de datos\n");
    printf("\n6. Salir\n");
    scanf("%d",&choice);
    return choice;
}

float requestKm()
{
   float km;
    printf("\nIngrese precio: ");
    scanf("%f",&km);
    return km;
}

float requestPrice()
{
    float price;
    printf("\nIngrese precio: ");
    scanf("%f",&price);
    return price;
}
float requestPriceLATAM()
{
    float price;
    printf("\nIngrese precio LATAM: ");
    scanf("%f",&price);
    return price;
}
float debitCard(float price)
{
    int debit=10;
    float discount;
    float finalPrice;
    discount=(price*debit)/100;
    finalPrice=price-discount;
    return finalPrice;
}
float creditCard(float price)
{
    int credit=25;
    float interest;
    float finalPrice;
    interest=(price*credit)/100;
    finalPrice=price+interest;
    return finalPrice;
}
float bitCoin(float price)
{
    float bit=4606954.55;
    float finalPrice;
    finalPrice=price/bit;
    return finalPrice;
}
float unitPrice(float price,float km)
{
    float finalPrice;
    finalPrice=price/km;
    return finalPrice;
}
float priceDifference(float price, float LATAMprice)
{
    float differnce;
    differnce=price-LATAMprice;
    if(differnce<=0)
    {
        differnce=differnce*-1;
    }
    return differnce;
}
