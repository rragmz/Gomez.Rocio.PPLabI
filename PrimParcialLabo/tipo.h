#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
 int id; //comienza en 1000
 char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

int mostrarTipo(eTipo tipo);
int mostrarTipos(eTipo tipos[], int tam);
int validarTipo(int idTipo, eTipo tipos[], int tam);
int cargarDescripcionTipos(int idTipo, eTipo tipos[], int tam, char desc[]);
int buscarTipo(int id, eTipo tipos[], int tam);
