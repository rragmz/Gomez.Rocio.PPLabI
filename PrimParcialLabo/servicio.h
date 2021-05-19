#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id; //Comienza en 20000
    char descripcion[25];
    float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED

int mostrarServicio(eServicio servicio);
int mostrarServicios(eServicio servicios[], int tam);
int validarServicio(int idServicio, eServicio servicios[], int tam);
int cargarDescServicio(int idServicio, eServicio servicios[], int tam, char desc[]);
int buscarServicio(int id, eServicio servicios[], int tam);
