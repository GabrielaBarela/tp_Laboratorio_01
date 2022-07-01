#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* fp = fopen(path,"r");
	int todoOk=0;
	if(fp != NULL)
	{
		parser_PassengerFromText(fp,pArrayListPassenger);
		todoOk=1;
	}
	else
	{
		printf("El archivo no se pudo cargar.\n");
        fclose(fp);
		exit(EXIT_FAILURE);
	}
	fclose(fp);
    return todoOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* fp = fopen(path,"r");
	int todoOk=0;
	if(fp != NULL)
	{
		parser_PassengerFromBinary(fp,pArrayListPassenger);
		todoOk=1;
	}
	else
	{
		printf("El archivo no se pudo cargar.\n");
        fclose(fp);
		exit(EXIT_FAILURE);
	}
	fclose(fp);
    return todoOk;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	Passenger* newPassenger = Passenger_new();
	char idAux[20],nameAux[50],lastNameaux[50],priceAux[50],typeAux[50],codeFly[50];
	int lenList = ll_len(pArrayListPassenger);
	int auxIdInt;
	int i;
	if(pArrayListPassenger != NULL)
	{
		auxIdInt= getValidInt(" Ingrese el ID: ","Error! ", 1, 1000);
		itoa(auxIdInt, idAux, 10);

		for(i=0; i < lenList ;i++)
		{
			newPassenger=(Passenger*)ll_get(pArrayListPassenger, i);
			if(newPassenger->id == auxIdInt)
			{
				mostrar_Passenger(newPassenger);
				todoOk = 0;
				printf("El id que desea agregar ya existe!\n");
				break;
			}
		}
		if(newPassenger->id != auxIdInt)
		{
			getValidStringEspaciosYLetras("Ingrese el nombre del pasajero: ", "Error, nombre no valido.", nameAux);
			getValidStringEspaciosYLetras("Ingrese el apellido del pasajero: ", "Error, nombre no valido.", lastNameaux);
			getValidStringNumerosFlotantes("Ingrese el precio del vuelo: ","Error, sueldo no valido", priceAux);
			getValidStringNumeros("Ingrese el tipo de pasajero: ","Error, horas no validas", typeAux);
			getValidStringEspaciosYLetras("Ingrese el codigo del vuelo: ", "Error, nombre no valido.", codeFly);
			newPassenger=Passenger_newParametros(idAux,nameAux,lastNameaux,priceAux,typeAux,codeFly);
			ll_add(pArrayListPassenger,newPassenger);
			todoOk = 0;
		}
	}
    return todoOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* auxPassenger;
	int todoOk = 1;
	int lenList=ll_len(pArrayListPassenger);
	int i;

	char idAux[20],nameAux[50],lastNameaux[50],priceAux[50],typeAux[50],codeFly[50];

	int id_Aux;
	float precio_Aux;
	int tipoPasajero_Aux;

	int elegir;
	int auxIdInt;
	char seguir = 'n';

	Passenger* newPassenger;

	if(pArrayListPassenger != NULL)
	{
		lenList = ll_len(pArrayListPassenger);
		idAux =  getValidInt("Ingrese el id que desea modificar:  ", "Error, no es valido el id.", 1, 5000);

		for(i=0 ; i < lenList ;i++)
		{
			auxPassenger=(Passenger*)ll_get(pArrayListPassenger,i);
			if(id_Aux == auxPassenger->id)
			{
				do{

					system("cls");
					mostrar_Passenger(auxPassenger);

					printf("Elija la opcion que desea modificar: \n");
					printf("1. ID\n");
					printf("2. Nombre\n");
					printf("3. Apellido\n");
					printf("4. Precio\n");
					printf("5. Tipo de Pasajero\n");
					printf("6. Codigo de Vuelo\n");
					printf("7. Salir\n");

					scanf("%d", &elegir);

					switch(elegir)
					{
					case 1:

						auxIdInt = getValidInt(" Ingrese el ID: ","Error! ", 1, 5000);
						atoi(auxIdInt,idAux,10);
						for(i=0 ; i < lenList ; i++)
						{
							newPassenger = (Passenger*)ll_get(pArrayListPassenger,i);
							if(newPassenger->id == auxIdInt)
							{
								mostrar_Passenger(newPassenger);
								todoOk = 0;
								printf("El id que desea agregar ya existe!\n");
								break;
							}
						}
						if (newPassenger->id != auxIdInt)
						{
							id_Aux = aoti(idAux);
							Passenger_setId(auxPassenger,id_Aux);
						}
						break;
					case 2:
						getValidString("Ingrese nuevo nombre: ", "Error al ingresar nombre",nameAux);
						Passenger_setNombre(auxPassenger,nameAux);
						break;
					case 3:
						getValidString("Ingrese nuevo Apellido: ", "Error al ingresar Apellido",lastNameaux);
						Passenger_setNombre(auxPassenger,lastNameaux);
						break;
					case 4:
						if(getStringNumerosFlotantes("Ingrese precio nuevo: ",   priceAux)!=1)
						{
							printf("Error, ingrese solo numeros.\n");
						}
						precio_Aux=atof(priceAux);
						break;
					case 5:
						if(getStringNumerosFlotantes("Ingrese tipo: ",   typeAux)!=1)
						{
							printf("Error, ingrese solo numeros.\n");
						}
						tipoPasajero_Aux=atof(typeAux);
						break;
					case 6:
						getValidString("Ingrese nuevo nombre: ", "Error al ingresar nombre",codeFly);
						Passenger_setCodigoVuelo(auxPassenger,codeFly);
						break;
					case 7:
						printf("Volviendo al menu!\n");
						seguir = 's';
                        break;//Mejor
						default:
						printf("Error, dato no valido.\n");
					}
				}
				while(seguir != 's');
				todoOk=0;
				break;
			}
		}
		if(id_Aux != auxPassenger->id)
		{
			printf("No existe ese id!\n\n");
			todoOk = 1;
		}
	}
    return todoOk;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

