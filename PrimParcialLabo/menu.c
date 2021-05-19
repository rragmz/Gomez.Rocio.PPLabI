#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"



char menu(){
    char opcion;

    printf("-----BICICLETERIA-----\n");
        printf("A. Alta bicicleta \n");
        printf("B. Modificar bicicleta \n");
        printf("C. Baja bicicleta \n");
        printf("D. Listar bicicletas \n");
        printf("E. Listar tipos \n");
        printf("F. Listar colores \n");
        printf("G. Listar servicios \n");
        printf("H. Alta trabajo\n");
        printf("I. Listar trabajos\n");
        printf("J. Salir\n");

        printf("Ingrese la opción: ");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion = toupper(opcion);

    return opcion;
}
