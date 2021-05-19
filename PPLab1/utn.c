#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int esNumerica(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena!=NULL && strlen(cadena)>0)
    {
        while(cadena[i] != '\0')
            {
                if(cadena[i] < '0' || cadena[i] > '9')
                {
                    retorno = 0;
                    break;
                }
                i++;
            }
    }
    return retorno;
}
int getInt(int* pResultado)
{
    int ret = -1;
    char buffer[256];
    scanf("%s", buffer);
    if(esNumerica(buffer))
    {
      *pResultado = atoi(buffer);
      ret = 1;
    }

    return ret;
}
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int ret = -1;
    int num;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){

    for(int i=0; i<reintentos; i++)
    {
       printf("%s", mensaje);
       if(getInt(&num)== 1)
        {
       if(num <=maximo && num >= minimo)
       {
         ret = 0;
        *pResultado = num;
         break;
       }
       }
       fflush(stdin);
       printf("%s", mensajeError);
    }
    }
    return ret;
}

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
    int ret = -1;
    char bufferChar;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){

    for(int i=0; i<reintentos; i++)
    {
       printf("%s", mensaje);
       fflush(stdin);
       if(scanf("%c", &bufferChar)== 1)
        {
       if(bufferChar <=maximo && bufferChar >= minimo)
       {
        *pResultado = bufferChar;
         ret = 0;
         break;
       }
       }
       fflush(stdin);
       printf("%s", mensajeError);
    }
    }
    return ret;
}


int utn_getTexto(char* texto, int tam, char* mensaje, char* mensajeError, int reintentos)
{
    int ret = -1;
    char buffer[tam];
    if(texto!=NULL && mensaje!=NULL && mensajeError!=NULL && tam>0 && reintentos>=0)
    {
        for(int i = 0; i<reintentos; i++)
        {
           printf("%s",mensaje);
           fflush(stdin);
           if(getString(buffer,tam))
           {
             strcpy(texto,buffer);
             ret = 0;
             break;
           }
           printf("%s", mensajeError);

        }
    }



    return ret;
}

int getString(char* texto, int tam)
{
    int ret = 0;
    char buffer[tam];
    scanf("%s", buffer);
    if(!esNumerica(buffer))
    {
      strcpy(texto, buffer);
      ret = 1;
    }

    return ret;
}


float getFloat(float* pResultado)
{
    int ret = -1;
    char buffer[256];
    scanf("%s", buffer);
    if(esNumericaFlotante(buffer))
    {
      *pResultado = atof(buffer);
      ret = 1;
    }

    return ret;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int ret = -1;
    float num;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){

    for(int i=0; i<reintentos; i++)
    {
       printf("%s", mensaje);
       if(getFloat(&num)== 1)
        {
       if(num <=maximo && num >= minimo)
       {
         ret = 0;
        *pResultado = num;
         break;
       }
       }
       fflush(stdin);
       printf("%s", mensajeError);
    }
    }
    return ret;
}

int esNumericaFlotante(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena!=NULL && strlen(cadena)>0)
    {
        while(cadena[i] != '\0')
            {
                if(cadena[i] < '0' || cadena[i] > '9')
                {
                    if(cadena[i]!= '.')
                    {
                        retorno = 0;
                        break;
                    }

                }
                i++;
            }
    }
    return retorno;
}

int getFecha(eFecha* unaFecha,int anioActual)
{
   int todoOk =0;
   eFecha auxFecha;
   if(unaFecha!=NULL && anioActual>0){
   if(
    utn_getNumero(&auxFecha.dia,"ingrese dia: ","Dato invalido. ",1,31,2)==0 &&
    utn_getNumero(&auxFecha.mes,"ingrese mes: ","Dato invalido. ",1,12,2)==0 &&
    utn_getNumero(&auxFecha.anio,"ingrese anio: ","Dato invalido. ",1,anioActual,2)==0
    ){

    if((auxFecha.mes == 4 ||auxFecha.mes == 6 ||auxFecha.mes == 9||auxFecha.mes == 11) && auxFecha.dia > 30)
    {
        printf("Fecha invalida!!");
    }
    if((auxFecha.mes == 2) && auxFecha.dia > 28)
    {
       printf("Fecha invalida!!");
    }else
    {
        *unaFecha = auxFecha;
    }
    }
   todoOk = 1;
   }
   return todoOk;
}
