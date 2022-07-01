#ifndef ARRAYPASSENGER_H_INCLUDED
#define ARRAYPASSENGER_H_INCLUDED
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

int initPassengers(ePassenger* list, int len);

int generateNextId();

int loadPassenger(ePassenger* list,int len);

int sortPassengers(ePassenger* list, int len, int order);

int sortCodexActive(ePassenger* list, int len);

void printOnePassengers(ePassenger passanger);

int findPriceMax(ePassenger* list, int len);

int printPassenger(ePassenger* list, int length);

int findPassengersById(ePassenger* list, int len,int id);

int findPassengersFreeSpace(ePassenger* list, int len);

int modifyPassenger(ePassenger* list, int len, int id);

int removePassenger(ePassenger* list, int len, int id);

int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger,int status, char flycode[]);
#endif // ARRAYPASSENGER_H_INCLUDED
