#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

int menu();

float requestKm();

float requestPrice();

float requestPriceLATAM();

float priceMenu();

float creditCard(float price);

float debitCard(float price);

float bitCoin(float price);

float unitPrice(float price,float km);

float priceDifference(float price, float LATAMprice);
#endif // BIBLIOTECA_H_INCLUDED
