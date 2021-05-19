#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moto.h"
#include "utn.h"



char menu()
{
    int opcion;
    printf("\t\t***Menu Empleados***\n\n");
    printf("A.	ALTA MOTO\n");
    printf("B.	MODIFICAR MOTO\n");
    printf("C.	BAJA MOTO\n");
    printf("D.	LISTAR MOTOS\n");
    printf("E.	LISTAR TIPOS\n");
    printf("F.	LISTAR COLORES\n");
    printf("G.	LISTAR SERVICIOS\n");
    printf("H.	ALTA TRABAJO\n");
    printf("I.	LISTAR TRABAJOS\n");
    printf("J.	SALIR\n");
    utn_getCaracter(&opcion,"Ingrese Opcion: ","Opcion invalida, ",'A','J',10);
    printf("\n\n");
    return opcion;
}


void mostrarTipo(eTipo unTipo)
{
    printf(" %d\t\t%s\n",unTipo.id,unTipo.descripcion);

}

void mostrarColor(eColor unColor)
{
    printf(" %d\t\t%s\n",unColor.id,unColor.normbreColor);
}

void mostrarServicio(eServicio unServicio)
{

    printf(" %d\t\t%s\t\t%.2f\n",unServicio.id,unServicio.descripcion,unServicio.precio);

}
int listarTipos(eTipo lista[],int tam)
{
    int todoOk = -1;
    if(lista!=NULL && tam > 0)
    {
        printf("\n                     |   Tipos De Moto   |   \n\n");
        printf("  ID            Tipo \n\n");
        for(int i=0; i < tam; i++)
        {
            mostrarTipo(lista[i]);
        }
        todoOk = 0;
    }

    return todoOk;
}
int listarColores(eColor lista[],int tam)
{

    int todoOk = -1;
    if(lista!=NULL && tam > 0)
    {
        printf("\n                     |   Colores De Moto   |   \n\n");
        printf("  ID            Color \n\n");
        for(int i=0; i < tam; i++)
        {
            mostrarColor(lista[i]);
        }
        todoOk = 0;
    }

    return todoOk;

}

int listarServicios(eServicio lista[],int tam)
{

    int todoOk = -1;
    if(lista!=NULL && tam > 0)
    {
        printf("\n                     |   Servicios   |   \n\n");
        printf("  ID            Descripcion           Precio\n\n");
        for(int i=0; i < tam; i++)
        {
            mostrarServicio(lista[i]);
        }
        todoOk = 0;
    }

    return todoOk;


}


int cargarDescripcionTipo(int id, eTipo tipos[],int tam, char desc[])
{
    int todoOk = 0;
    if(id >= 1000 && id <= 1003 && tipos != NULL && tam > 0 && desc != NULL)
    {
        for(int i = 0; i<tam; i++)
        {
            if(tipos[i].id == id)
            {
                strcpy(desc, tipos[i].descripcion);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}
int cargarDescripcionColor(int id, eColor colores[],int tam, char desc[])
{
    int todoOk = 0;
    if(id >= 10000 && id <= 10004 && colores != NULL && tam > 0 && desc != NULL)
    {
        for(int i = 0; i<tam; i++)
        {
            if(colores[i].id == id)
            {
                strcpy(desc, colores[i].normbreColor);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int mostrarMoto(eMoto unaMoto,eTipo tipos[], int tamTipos, eColor colores[], int tamColor)
{
    char descripcionTipo[20];
    char descripcionColor[20];
    int todoOk = 0;
    if( tipos!=NULL&&tamTipos>0 && colores!=NULL&&tamColor>0){
    if (cargarDescripcionTipo(unaMoto.idTipo,tipos,tamTipos,descripcionTipo) && cargarDescripcionColor(unaMoto.idColor,colores,tamColor,descripcionColor))
    {
        printf(" %d\t\t%s\t\t%s\t\t%s\t\t%d\n"
               ,unaMoto.id
               ,unaMoto.marca
               ,descripcionTipo
               ,descripcionColor
               ,unaMoto.cilindrada
              );
    }
    todoOk = 1;
    }
    return todoOk;

}


int listarMotos(eMoto motos[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor)
{
    int sinMotos = 1;
    int todoOk = 0;
    printf("            Listado de Motos\n\n");
    printf("ID   Marca      Tipo      Color       Cilindrada\n\n");
    if(motos!=NULL&&tam>0 && tipos!=NULL&&tamTipos>0 && colores!=NULL&&tamColor>0)
    {
        todoOk=1;
        for(int i=0; i<tam; i++)
        {
            if(!motos[i].isEmpty)
            {
                mostrarMoto(motos[i],tipos,tamTipos,colores,tamColor);
                sinMotos = 0;
            }
        }
        if(sinMotos)
        {
            printf("No hay Motos que mostrar.");
        }
        printf("\n\n");
    }
    return todoOk;
}
int inicializarMotos(eMoto lista[], int tam)
{
    int todoOk = 0;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int inicializarTrabajos(eTrabajo lista[], int tam)
{
    int todoOk = 0;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarMotoById(eMoto lista [],int tam, int id)
{
    int indice = -1;

    if(lista!= NULL && tam > 0)
    {
        for(int i =0; i<tam; i++)
        {
            if(lista[i].id == id && !lista[i].isEmpty)
            {
                indice = i;
                break;
            }

        }
    }
    return indice;
}

int bajaMoto(eMoto lista[],int tam,eTipo tipos[], int tamTipos, eColor colores[], int tamColor)
{
    int todoOk = 0;
    int id;
    int i;
    char confirmacion = 'n';
    system("cls");
    printf("              Baja Moto\n\n");
    listarMotos(lista,tam,tipos,tamTipos,colores,tamColor);
    printf("Ingrese el ID de la moto que quiere dar de baja: ");
    scanf("%d", &id);
    if(lista!= NULL && tam > 0 )
    {
        i = buscarMotoById(lista,tam,id);
        if(i == -1)
        {
            printf("No hay ninguna moto registrado con el ID: %d\n",id);
        }
        else
        {
            mostrarMoto(lista[i],tipos,tamTipos,colores,tamColor);
            printf("Confirma baja?: ");
            fflush(stdin);
            confirmacion = getchar();
            if(confirmacion == 's')
            {
                lista[i].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }
        }
    }
    return todoOk;
}



int menuModificar()
{
    int opcion;
    printf("  Modificar Moto\n\n");
    printf("1 Marca\n");
    printf("2 Tipo\n");
    printf("3 Color\n");
    printf("4 Cilindrada\n");
    printf("5 Salir\n");
    utn_getNumero(&opcion,"Ingrese Opcion: ","ERROR, ",1,5,10);
    printf("\n\n");
    return opcion;

}

int modificarMoto(eMoto lista[],int tam , eTipo tipos[], int tamTipos, eColor colores[], int tamColor)
{
    int todoOk = 0;
    int id;
    int i;

    char confirmacion = 'n';
    char salir = 'n';

    eMoto auxMoto;
    system("cls");
    listarMotos(lista,tam,tipos,tamTipos,colores,tamColor);
    printf("Ingrese el ID de la moto que quiere modificar: ");
    scanf("%d", &id);
    if(lista!= NULL && tam > 0 )
    {
        system("cls");
        i = buscarMotoById(lista,tam,id);
        if(i == -1)
        {
            printf("No se encontro el ID de la moto: %d\n", id);
        }
        else
        {

            auxMoto = lista[i];
            do
            {
                printf("\n\n");
                mostrarMoto(auxMoto,tipos,tamTipos,colores,tamColor);
                printf("\n\n");
                switch(menuModificar())
                {
                case 1:
                   utn_getTexto(auxMoto.marca,20,"Ingrese marca: ","Error ",10);
                    break;
                case 2:
                  listarTipos(tipos,tamTipos);
                utn_getNumero(&auxMoto.idTipo,"Ingrese ID tipo: ","Error ",1000,1003,10);
                    break;
                case 3:
                  listarColores(colores,tamColor);
                  utn_getNumero(&auxMoto.idColor,"Ingrese ID color: ","Error ",10000,10004,10);
                    break;
                case 4:
                    utn_getNumero(&auxMoto.cilindrada,"Ingrese cilindrada: ","Error ",50,750,10);
                    break;
                case 5:
                    printf("Confirma salida?: ");
                    fflush(stdin);
                    salir = getchar();
                    break;
                }
            }while(salir == 'n');
            system("cls");
            printf("\n\n");
            mostrarMoto(lista[i],tipos,tamTipos,colores,tamColor);
            printf("\nModificacion: \n\n");
            mostrarMoto(auxMoto,tipos,tamTipos,colores,tamColor);
            printf("Confirma modificacion?: ");
            fflush(stdin);
            confirmacion = getchar();
            if(confirmacion == 's')
            {
                lista[i] = auxMoto;
                todoOk = 1;
            }
        }
    }
    return todoOk;
}
