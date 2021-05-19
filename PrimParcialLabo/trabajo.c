#include "trabajo.h"

int inicTrabajo(eTrabajo trabajos[], int tam){
    int todoOk = 0;
        if(trabajos != NULL && tam > 0){
            for(int i = 0; i < tam; i++){
                    trabajos[i].isEmpty = 1;
                    todoOk = 1;
                }
            }
    return todoOk;
}
int buscarLibreTrabajo(eTrabajo trabajos[], int tam){
    int indice = -1;

    if(trabajos != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            //Analizo si está vacío
            if(trabajos[i].isEmpty){
                //De estarlo, devuelvo el índice
                indice = i;
                //Rompemos para que nos muestre el PRIMER lugar libre
                break;
            }
        }
    }
    return indice;
}

int buscarTrabajo(eTrabajo trabajos[], int tam){
    int indice = -1;
    if(trabajos != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(trabajos[i].id == id){
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int mostrarTrabajo(eTrabajo trabajo, listBicis, tam, servicios, tamS){
char servicio[20];
cargarDescServicio(trabajo.idServicio, servicios, tamS, &servicio);

    int todoOk = 1;
    printf("    %d     %10s     %10s     %d/%d/%d\n", trabajo.id, trabajo.idBicicleta, servicio, trabajo.fecha);
    return todoOk;
}

int mostrarTrabajos(eTrabajo trabajos[], int tam){
int todoOk = 0;
    printf("     Trabajos \n\n");
    printf("  id        id Bicicleta        Servicio        Fecha\n");
    if(servicios != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            mostrarTrabajo(trabajos[i]);
            todoOk = 1;
        }
    }
    return todoOk;
}
int validarTrabajo(int idTrabajo, eTrabajo trabajos[], int tam){
    int todoOk = 0;

            if(trabajos != NULL && tam > 0){
                for(int i = 0; i < tam; i++){
                    if(trabajos[i].id == idTrabajo){
                        todoOk = 1;
                        break;
                    }
                }
            }
        return todoOk;
}
int buscarTrabajo(int id, eTrabajo trabajos[], int tam){
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

int altaTrabajo(eTrabajo trabajos[], int tam, eBicicleta listBicis[], int tamB, eServicio servicios[], int tamS, eTipo tipos[], int tamT, eColor colores[], int tamC int* pIdTrabajo){
int todoOk = 0;

    eTrabajo nuevoTrabajo;
    int indice;
    int idBici;
    int idServicio;

    system("cls");
    printf("          Alta Trabajo\n");

    printf("Id: %d\n", *pIdTrabajo);

        //Hago las validaciones generales
        if(trabajos != NULL && tam > 0 listBicis != NULL && tamB > 0 servicios != NULL && tamS > 0 &&
           tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && pIdTrabajo != NULL){
            //Llamo a la funcion buscar libre para pedirle el primer índice vacío disponible
            indice = buscarLibreTrabajo(trabajos, tam);

            //Si el índice es -1, es porque no hay lugar.
            if(indice == -1){
                printf("No hay lugar en el sistema\n");
            }
            //Sino, es porque sí hay lugar, procedemos a la carga de datos
            else{
                mostrarBicicletas(listBicis, tamB, tipos, tamT, colores, tamC);
                printf("Ingrese ID de la bicicleta: ");
                scanf("%d", &idBici);

                mostrarServicios(servicios, tamS);
                printf("Ingrese ID servicio: ");
                scanf("%d", &idServicio);
                while(!validarServicio(idServicio, servicios, tamS)){
                    printf("Error. Ingrese ID servicio: ");
                    scanf("%d", &idServicio);
                }

                printf("Ingrese fecha (dd/mm/aaaa): ");
                scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);
                while(nuevoTrabajo.fecha.dia < 1 || nuevoTrabajo.fecha.dia > 31 || nuevoTrabajo.fecha.mes < 1 ||
                      nuevoTrabajo.fecha.mes>12 || nuevoTrabajo.fecha.anio < 1900 || nuevoTrabajo.fecha.anio > 2023){
                        printf("Ingrese fecha (dd/mm/aaaa): ");
                      }

                nuevoTrabajo.id = *pIdBici;
                //Informo que ya no está vacío
                nuevoTrabajo.isEmpty = 0;
                //Incremento el valor del id, para próximas cargas
                (*pIdTrabajo)++;

                //Ahora tenemos que copiar lo que está en la variable auxiliar a la posición[indice] de nuestro array
                trabajos[indice] = nuevoTrabajo;
                todoOk = 1;


                }//Cierro el else
        }
    return todoOk;
}
