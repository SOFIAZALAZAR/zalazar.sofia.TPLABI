#include "utn.h"

#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];


} eTipo;
typedef struct
{
    int id;
    char normbreColor[20];

} eColor;
typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int cilindrada;
    int isEmpty;
} eMoto;

typedef struct
{
    int id;
    char descripcion[20];
    float precio;

} eServicio;


typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;

#endif // MOTO_H_INCLUDED
int mostrarMoto(eMoto unaMoto,eTipo tipos[], int tamTipos, eColor colores[], int tamColor);
int listarMotos(eMoto motos[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor);
int inicializarMotos(eMoto lista[], int tam);
int inicializarMotos(eMoto lista[], int tam);

void mostrarTipo(eTipo unTipo);
int listarTipos(eTipo lista[],int tam);

void mostrarColor(eColor unColor);

int listarColores(eColor lista[],int tam);

void mostrarServicio(eServicio unServicio);
int listarServicios(eServicio lista[],int tam);

char menu();

int cargarDescripcionTipo(int id, eTipo tipos[],int tam, char desc[]);

int cargarDescripcionColor(int id, eColor colores[],int tam, char desc[]);


int buscarMotoById(eMoto lista [],int tam, int id);


int bajaMoto(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor);

int modificarMoto(eMoto lista[],int tam , eTipo tipos[], int tamTipos, eColor colores[], int tamColor);

int menuModificar();
