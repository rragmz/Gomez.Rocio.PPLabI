#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "utn.h"

int inicBicis(eBicicleta listBicis[], int tam){
int todoOk = 0;
    if(listBicis != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
                listBicis[i].isEmpty = 1;
                todoOk = 1;
            }
        }
return todoOk;
}

int buscarLibre(eBicicleta listBicis[], int tam){
int indice = -1;

    if(listBicis != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            //Analizo si está vacío
            if(listBicis[i].isEmpty){
                //De estarlo, devuelvo el índice
                indice = i;
                //Rompemos para que nos muestre el PRIMER lugar libre
                break;
            }
        }
    }
    return indice;
}

int buscarBici(int id, eBicicleta listBicis[], int tam){
int indice = -1;
    if(listBicis != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(listBicis[i].id == id){
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int mostrarBicicleta(eBicicleta bicicleta, eTipo tipos[], int tamT, eColor colores[], int tamC){
char descTipo[20];
char color[20];
cargarDescripcionTipos(bicicleta.idTipo, tipos, tamT, &descTipo);
cargarNombreColores(bicicleta.idColor, colores, tamC, &color);

    printf("    %d  \t  %10s  \t  %10s   \t  %10s  \t  %.2f\n", bicicleta.id, bicicleta.marca, descTipo, color, bicicleta.rodado);
    int todoOk = 1;
    return todoOk;
}

int mostrarBicicletas(eBicicleta listBicis[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC){
printf("     Bicicletas \n\n");
    printf("  id        Marca        Tipo        Color        Rodado\n");
    if(listBicis != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0){
        for(int i = 0; i < tam; i++){
            if(!listBicis[i].isEmpty){
                mostrarBicicleta(listBicis[i], tipos, tamT, colores, tamC);
            }
        }
    }
}



int altaBicicleta(eBicicleta listBicis[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, int* pIdBici){
    int todoOk = 0;

    eBicicleta nuevaBici;
    //Es la que voy a utilizar para pedir la información, una vez que haya validado
    int indice;
    int idTipo;
    int idColor;

    system("cls");
    printf("          Alta Bicicleta\n");
    //Le mostramos al usuario cuál sería el id de bici que le corresponde de realizarse correctamente el alta
    printf("Id: %d\n", *pIdBici);

        //Hago las validaciones generales
        if(listBicis != NULL && tam > 0 && pIdBici != NULL){
            //Llamo a la funcion buscar libre para pedirle el primer índice vacío disponible
            indice = buscarLibre(listBicis, tam);

            //Si el índice es -1, es porque no hay lugar. Printeamos.
            if(indice == -1){
                printf("No hay lugar en el sistema\n");
            }
            //Sino, es porque sí hay lugar, procedemos a la carga de datos
            else{
                printf("Ingrese marca: ");
                fflush(stdin);
                gets(nuevaBici.marca);
                while(!esSoloLetras(nuevaBici.marca) || strlen(nuevaBici.marca) > 20){
                    printf("Error. Ingrese marca: ");
                    fflush(stdin);
                    gets(nuevaBici.marca);
                }

                mostrarTipos(tipos, tamT);
                printf("Ingrese ID tipo: ");
                scanf("%d", &nuevaBici.idTipo);
                while(!validarTipo(nuevaBici.idTipo, tipos, tamT)){
                    printf("Error. Ingrese ID tipo: ");
                    scanf("%d", &nuevaBici.idTipo);
                }


                mostrarColores(colores, tamC);
                printf("Ingrese sexo: ");
                printf("Ingrese ID color: ");
                scanf("%d", &nuevaBici.idColor);
                while(!validarColor(nuevaBici.idColor, colores, tamC)){
                    printf("Error. Ingrese ID color: ");
                    scanf("%d", &nuevaBici.idColor);
                }

                printf("Ingrese rodado (20/26/27.5/29): ");
                scanf("%f", &nuevaBici.rodado);
                while(nuevaBici.rodado != 20 && nuevaBici.rodado != 26 && nuevaBici.rodado != 27.5 && nuevaBici.rodado != 29){
                    printf("Ingrese rodado: ");
                    scanf("%f", &nuevaBici.rodado);
                }

                nuevaBici.id = *pIdBici; //Accedo al valor que tengo en el puntero, y se lo asigno a esta nueva bici luego de las validaciones.
                //Informo que ya no está vacío
                nuevaBici.isEmpty = 0;
                //Incremento el valor del id, para próximas cargas
                (*pIdBici)++;

                //Ahora tenemos que copiar lo que está en la variable auxiliar a la posición[indice] de nuestro array
                listBicis[indice] = nuevaBici;
                todoOk = 1;


                }//Cierro el else
        }
    return todoOk;
}

int modificarBicicleta(eBicicleta listBicis[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC){

eBicicleta auxBici;
    int indice;
    int id;
    int todoOk = 0;
    int opcion;

    mostrarBicicletas(listBicis, tam, tipos, tamT, colores, tamC);

    printf("Ingrese ID a modificar: ");
    scanf("%d", &id);

    indice = buscarBici(id,listBicis, tam);

    if(indice == -1){
        printf("No hay bicicletas con ese id\n");
    }
    else{
        auxBici = listBicis[indice];
        mostrarBicicleta(auxBici, tipos, tamT, colores, tamC);
        printf("1. Tipo\n");
        printf("2. Rodado\n");
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
            system("cls");
            mostrarTipos(tipos, tamT);
                printf("Ingrese ID tipo: ");
                scanf("%d", &auxBici.idTipo);
                while(!validarTipo(auxBici.idTipo, tipos, tamT)){
                    printf("Error. Ingrese ID tipo: ");
                    scanf("%d", &auxBici.idTipo);
                }
            break;
        case 2:
            system("cls");
            printf("Ingrese rodado (20/26/27.5/29): ");
                scanf("%f", &auxBici.rodado);
                while(auxBici.rodado != 20 && auxBici.rodado != 26 && auxBici.rodado != 27.5 && auxBici.rodado != 29){
                    printf("Ingrese rodado: ");
                    scanf("%f", &auxBici.rodado);
                }
            break;
        default:
            printf("Opcion invalida\n");
        }
        mostrarBicicleta(auxBici, tipos, tamT, colores, tamC);
        printf("Confirma cambios? s/n: ");
        fflush(stdin);
        scanf("%c",&opcion);
        if(opcion == 's'){
            listBicis[indice] = auxBici;
            todoOk = 1;
        }
        else{
            printf("Modificación cancelada por el usuario. \n");
        }
    }
 return todoOk;
}

int bajaBicicleta(eBicicleta listBicis[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC){
    int todoOk = 0;
    int id;
    int indice;
    char confirma;

    system("cls");
    printf("       Baja Bicicleta");

    if(listBicis != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0){
        mostrarBicicletas(listBicis, tam, tipos, tamT, colores, tamC);
        printf("Ingrese ID: ");
        scanf("%d", &id);

        indice = buscarBici(id, listBicis, tam);

        if(indice == -1){
            printf("No hay ninguna bicicleta registrada con el ID %d \n", id);
        }
        else{
            mostrarBicicleta(listBicis[indice], tipos, tamT, colores, tamC);
            printf("Confirma baja? s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's'){
                listBicis[indice].isEmpty = 1;
                todoOk = 1;
            }
            else{
                printf("Baja cancelada por el usuario \n");
            }
        }
    }

    return todoOk;
}

int ordenarBicicleta(eBicicleta listBicis[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC){
    int todoOk = 0;
    eBicicleta auxBicicleta;

    for(int i = 0; i < tam-1; i++){
        for(int j = i+1; j < tam; j++){
                if(listBicis[i].idTipo > listBicis[j].idTipo || listBicis[i].idTipo == listBicis[j].idTipo &&
                   listBicis[i].rodado > listBicis[j].rodado){
                    auxBicicleta = listBicis[i];
                    listBicis[i] = listBicis[j];
                    listBicis[j] = auxBicicleta;
                }
            }
    }
}
