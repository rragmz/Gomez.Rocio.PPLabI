#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "color.h"


int mostrarColor(eColor color){
    int todoOk = 1;
    printf("    %d     %10s\n", color.id, color.nombreColor);
    return todoOk;
}

int mostrarColores(eColor colores[], int tam){
    int todoOk = 1;
    printf("     Colores \n\n");
    printf("  id        Descripcion\n");
    if(colores != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            mostrarColor(colores[i]);
        }
    }
    return todoOk;
}

int validarColor(int idColor, eColor colores[], int tam){
    int todoOk = 0;

    if(colores != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(colores[i].id == idColor){
                todoOk = 1;
                break;
            }
        }
    }
return todoOk;
}

int cargarNombreColores(int idColor, eColor colores[], int tam, char nombre[]){
int todoOk = 0;

    if(idColor >= 5000 && idColor <= 5004 && colores != NULL && tam > 0 && nombre != NULL){
        for(int i = 0; i < tam; i++){
            if(colores[i].id == idColor){
                strcpy(nombre, colores[i].nombreColor);
                todoOk = 1;
                break;
            }
        }
    }
return todoOk;
}

int buscarColor(int id, eColor colores[], int tam){
    int indice = -1;
    if(colores != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(colores[i].id == id){
                indice = i;
                break;
            }
        }
    }
    return indice;
}
