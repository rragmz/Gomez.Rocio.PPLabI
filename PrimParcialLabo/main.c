#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu.h"
#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "bicicleta.h"
#include "servicio.h"
#include "trabajo.h"

#define TAMT 4
#define TAMC 5
#define TAMS 4
#define TAMB 10
#define TAMTR 10
int main()
{
    char salir;
    int flag = 0;

    int nextIdBici = 200;
    int nextIdTrabajo = 300;

    eTipo tipos[TAMT] = {
    {1000, "Rutera"},
    {1001, "Carrera"},
    {1002, "Mountain"},
    {1003, "BMX"},
    };

    eColor colores[TAMC] = {
    {5000, "Gris"},
    {5001, "Negro"},
    {5002, "Blanco"},
    {5003, "Azul"},
    {5004, "Rojo"},
    };

    eServicio servicios[TAMS] = {
        {20000, "Limpieza", 250},
        {20001, "Parche", 300},
        {20002, "Centrado", 400},
        {20003, "Cadena", 350},
    };

    eBicicleta listabicis[TAMB];
    inicBicis(listabicis, TAMB);

    eTrabajo trabajos[TAMTR];
    inicTrabajo(trabajos, TAMTR);

    do{
    switch(menu()){
        case 'A':
            system("cls");
            if(altaBicicleta(listabicis, TAMB, tipos, TAMT, colores, TAMC, &nextIdBici)){
                printf("\nSe realizo correctamente el alta!!\n");
                flag = 1;
            }
            else{
                printf("No se pudo realizar el alta \n");
            }
            break;
        case 'B':
            system("cls");
            if(flag){
                if(modificarBicicleta(listabicis, TAMB, tipos, TAMT, colores, TAMC)){
                    printf("\nSe realizo correctamente la modificacion!!\n");
                }
                else{
                    printf("No se pudo realizar la modificacion \n");
                }
            }
            else{
                printf("Primero haga un alta\n");
            }
            break;
        case 'C':
            system("cls");
            if(flag){
                if(bajaBicicleta(listabicis, TAMB, tipos, TAMT, colores, TAMC)){
                    printf("\nSe realizo correctamente la baja!!\n");
                }
                else{
                    printf("No se pudo realizar la baja \n");
                }
            }
            else{
                printf("Primero haga un alta\n");
            }
            break;
        case 'D':
            system("cls");
            ordenarBicicleta(listabicis, TAMB, tipos, TAMT, colores, TAMC);
            mostrarBicicletas(listabicis, TAMB, tipos, TAMT, colores, TAMC);
            break;
        case 'E':
            system("cls");
            mostrarTipos(tipos, TAMT);
            break;
        case 'F':
            system("cls");
            mostrarColores(colores, TAMC);
            break;
        case 'G':
            system("cls");
            mostrarServicios(servicios, TAMS);
            break;
        case 'H':
            system("cls");
            break;
        case 'I':
            system("cls");
            break;
        case 'J':
            system("cls");
            printf("Confirma salida? s/n: ");
            scanf("%c", &salir);
            salir = tolower(salir);
            break;
        default:
            printf("Esta no es una opcion\n");
            break;
        }
        system("pause");
    }while(salir != 's');
}
