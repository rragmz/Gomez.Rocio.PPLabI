#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id; //comienza en 5000
    char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED

int mostrarColor(eColor color);
int mostrarColores(eColor colores[], int tam);
int validarColor(int idColor, eColor colores[], int tam);
int cargarNombreColores(int idColor, eColor colores[], int tam, char nombre[]);
int buscarColor(int id, eColor colores[], int tam);
