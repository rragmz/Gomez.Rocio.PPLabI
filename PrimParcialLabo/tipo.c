#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tipo.h"

int mostrarTipo(eTipo tipo){
    int todoOk = 1;
    printf("    %d     %10s\n", tipo.id, tipo.descripcion);
    return todoOk;
}

int mostrarTipos(eTipo tipos[], int tam){
    printf("     Tipos \n\n");
    printf("  id        Descripcion\n");
    if(tipos != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            mostrarTipo(tipos[i]);
        }
    }
}

int validarTipo(int idTipo, eTipo tipos[], int tam){
    int todoOk = 0;

    if(tipos != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(tipos[i].id == idTipo){
                todoOk = 1;
                break;
            }
        }
    }
return todoOk;
}

int cargarDescripcionTipos(int idTipo, eTipo tipos[], int tam, char desc[]){
int todoOk = 0;

    if(idTipo >= 1000 && idTipo <= 1003 && tipos != NULL && tam > 0 && desc != NULL){
        for(int i = 0; i < tam; i++){
            if(tipos[i].id == idTipo){
                strcpy(desc, tipos[i].descripcion);
                todoOk = 1;
                break;
            }
        }
    }
return todoOk;
}

int buscarTipo(int id, eTipo tipos[], int tam){
    int indice = -1;
    if(tipos != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(tipos[i].id == id){
                indice = i;
                break;
            }
        }
    }
    return indice;
}
