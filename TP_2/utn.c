#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"


float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

char getSexChar(char mensaje[],char mensajeError[],char* input)
{
    char auxChar;
    int myReturn=-1;

    printf("%s ", mensaje);
    fflush(stdin);
    scanf("%c", &auxChar);
    auxChar=toupper(auxChar);

    while(auxChar !='F' && auxChar !='M')
    {
        printf("\n%s ", mensajeError);
        printf("\n%s :", mensaje);
        fflush(stdin);
        scanf("%c", &auxChar);
        auxChar=toupper(auxChar);
    }
    *input=auxChar;//le asigno el valor de auxchar al contenido de la variable a la que apunta el puntero input
    myReturn=0;

    return myReturn;
}

int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}


/*void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}*/

int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int lowLimit,int maxLenght)
{
    int retorno=-1;
    char buffer[1024];

    while(1)
    {
        if (!getStringLetras(requestMessage,buffer))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        if(strlen(buffer) > maxLenght || strlen(buffer) < lowLimit)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;

    }

     return retorno;
}
int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit,int* input)
{
    char auxStr[256];
    int auxInt;
    int myReturn=-1;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("ERROR, solo ingrese numeros \n");
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        myReturn=0;
        *input=auxInt;
        break;

    }

    return myReturn;
}

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/*void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}*/

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getValidFloat(char requestMessage[],char errorMessage[], float lowLimit, float hiLimit, float* input)
{
    char auxStr[256];
    float auxFloat;
    int myReturn=-1;
    while(1)
    {
        if (!getStringNumerosFlotantes(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxFloat = atof(auxStr);
        if(auxFloat < lowLimit || auxFloat > hiLimit)
        {
            printf ("El salario debe ser mayor a %.3f y menor a %.3f\n",lowLimit,hiLimit);
            continue;

        }
        myReturn=0;
        *input=auxFloat;
        break;

    }

    return myReturn;
}


void stringToUpper(char caracter[])
{
    int i;
    int largo;
    strlwr(caracter);
    caracter[0]=toupper(caracter[0]);
    largo=strlen(caracter);
    for(i=0;i<largo;i++)
    {
        if(caracter[i]==' ')
        {
            i=i+1;
            caracter[i]=toupper(caracter[i]);
        }
    }

}
