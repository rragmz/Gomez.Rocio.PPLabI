#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
#include "tipo.h"
#include "color.h"


typedef struct{
    int id;
    char marca[20];
    int idTipo; //validar;
    int idColor; //validar
    float rodado; //20, 26, 27.5 y 29
    int isEmpty;
}eBicicleta;

#endif // BICICLETA_H_INCLUDED

int inicBicis(eBicicleta listBicis[], int tam);
int buscarLibre(eBicicleta listBicis[], int tam);
int buscarBici(int id, eBicicleta listBicis[], int tam);
int mostrarBicicleta(eBicicleta bicicleta, eTipo tipos[], int tamT, eColor colores[], int tamC);
int mostrarBicicletas(eBicicleta listBicis[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int altaBicicleta(eBicicleta listBicis[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, int* pIdBici);
int modificarBicicleta(eBicicleta listBicis[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int bajaBicicleta(eBicicleta listBicis[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int ordenarBicicleta(eBicicleta listBicis[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
