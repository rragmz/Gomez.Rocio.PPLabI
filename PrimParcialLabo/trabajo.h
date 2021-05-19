#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"


typedef struct{
    int id;
    int idBicicleta; //validar
    int idServicio; //validar
    eFecha fecha; //validar
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

int inicTrabajo(eTrabajo trabajos[], int tam);
int buscarLibreTrabajo(eTrabajo trabajos[], int tam);
int buscarTrabajo(eTrabajo trabajos[], int tam);
int mostrarTrabajo(eTrabajo trabajo);
int mostrarTrabajos(eTrabajo trabajos[], int tam);
int validarTrabajo(int idTrabajo, eTrabajo trabajos[], int tam);
int buscarTrabajo(int id, eTrabajo trabajos[], int tam);
int altaTrabajo(eTrabajo trabajos[], int tam, eBicicleta listBicis[], int tamB, eServicio servicios[], int tamS);
