#include "servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int mostrarServicio(eServicio servicio){
    int todoOk = 1;
    printf("    %d     %10s     %.2f\n", servicio.id, servicio.descripcion, servicio.precio);
    return todoOk;
}
int mostrarServicios(eServicio servicios[], int tam){
    int todoOk = 1;
    printf("     Servicios \n\n");
    printf("  id        Descripcion        Precio\n");
    if(servicios != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            mostrarServicio(servicios[i]);
        }
    }
    return todoOk;
}
int validarServicio(int idServicio, eServicio servicios[], int tam){
    int todoOk = 0;

        if(servicios != NULL && tam > 0){
            for(int i = 0; i < tam; i++){
                if(servicios[i].id == idServicio){
                    todoOk = 1;
                    break;
                }
            }
        }
    return todoOk;
}
int cargarDescServicio(int idServicio, eServicio servicios[], int tam, char desc[]){
    int todoOk = 0;

        if(idServicio >= 20000 && idServicio <= 20003 && servicios != NULL && tam > 0 && desc != NULL){
            for(int i = 0; i < tam; i++){
                if(servicios[i].id == idServicio){
                    strcpy(desc, servicios[i].descripcion);
                    todoOk = 1;
                    break;
                }
            }
        }
    return todoOk;
}
int buscarServicio(int id, eServicio servicios[], int tam){
    int indice = -1;
    if(servicios != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(servicios[i].id == id){
                indice = i;
                break;
            }
        }
    }
    return indice;
}
