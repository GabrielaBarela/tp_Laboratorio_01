/*
 * biblioteca.h
 *
 *  Created on: 16 abr. 2022
 *      Author: VAIO
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

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

#endif /* BIBLIOTECA_H_ */
