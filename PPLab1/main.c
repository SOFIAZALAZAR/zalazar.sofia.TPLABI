#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moto.h"
#include "utn.h"

#define TAM  1000
#define TAM_TRABAJO  500
#define TAMTIPO 4
#define TAMCOLOR 5
#define TAMSERV 4

int buscarLibreMoto(eMoto lista[], int tam);
int altaMoto(eMoto lista[],int tam , eTipo tipos[], int tamTipos, eColor colores[], int tamColor, int* pId);

int main()
{
    int idTrabajo = 0000;//autoincremental
    int idMoto = 100;//autoincremental
    eTipo tipos[TAMTIPO]= {{1000,"Enduro"},{1001,"Chopera"},{1002,"Scooter"},{1003,"Ciclomotor"}};
    eColor colores[TAMCOLOR]= {{10000,"Gris"},{10001,"Negro"},{10002,"Blanco"},{10003,"Azul"},{10004,"Rojo"}};
    eServicio servicios[TAMSERV]= {{2000,"Limpieza",250},{2001,"Ajuste",300},{2002,"Balanceo",17},{2003,"Cadena",190}};
    eMoto motos[TAM];
    inicializarMotos(motos,TAM);
    eTrabajo trabajos[TAM_TRABAJO];
    inicializarTrabajos(trabajos,TAM_TRABAJO);
    char salir = 'n';

    do
    {

        switch (menu())
        {
        case 'A':
            altaMoto(motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR,&idMoto);

            break;
        case 'B':
            modificarMoto(motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR);

            break;
        case 'C':
             bajaMoto(motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR);
            break;
        case 'D':
            listarMotos(motos,TAM,tipos,TAMTIPO,colores,TAMCOLOR);
            break;
        case 'E':
            listarTipos(tipos,TAMTIPO);
            break;
        case 'F':
            listarColores(colores,TAMCOLOR);
            break;
        case 'G':
            listarServicios(servicios,TAMSERV);

            break;
        case 'H':

            break;
        case 'I':

            break;
        case 'J':
            printf("Confirma salida?: ");
            fflush(stdin);
            salir = getchar();
            while(salir!= 'n' && salir!= 's')
            {
                printf("Confirma salida?: ");
                fflush(stdin);
                salir = getchar();
            }
            printf("\n\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(salir == 'n');



    return 0;
}

int buscarLibreMoto(eMoto lista[], int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaMoto(eMoto lista[],int tam , eTipo tipos[], int tamTipos, eColor colores[], int tamColor, int* pId)
{
    int ok = 0;
    eMoto auxMoto;
    int i;
    system("cls");
    printf("   Alta Moto\n\n");
    printf("ID Moto: %d\n", *pId);
    if(lista!= NULL && tam > 0 && pId!=NULL)
    {
        i = buscarLibreMoto(lista,tam);
        if(i == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            utn_getTexto(auxMoto.marca,20,"Ingrese marca: ","Error ",10);
            listarTipos(tipos,tamTipos);
            utn_getNumero(&auxMoto.idTipo,"Ingrese ID tipo: ","Error ",1000,1003,10);
            listarColores(colores,tamColor);
            utn_getNumero(&auxMoto.idColor,"Ingrese ID color: ","Error ",10000,10004,10);
            utn_getNumero(&auxMoto.cilindrada,"Ingrese cilindrada: ","Error ",50,750,10);
            auxMoto.isEmpty = 0;
            auxMoto.id = *pId;
            lista[i] = auxMoto;
            (*pId)++;
            ok = 1;
        }
    }
    return ok;
}













