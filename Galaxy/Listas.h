#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED


#include "usuarios.h"

typedef struct {
    Usuario dato;
    struct stNodo * Siguiente;
} stNodo;

// FUNCIONES BASICAS / GENERICAS
stNodo * InicLista();
stNodo * CrearNodo (Usuario Usuario);

stNodo * AgregarPpio (stNodo * lista, stNodo * nuevoNodo);
stNodo * AgregarFinal(stNodo * lista, stNodo * nuevoNodo);

stNodo * BuscarUltimo(stNodo * lista);
stNodo * BorrarTodaLaLista(stNodo * lista);

stNodo * EliminarPrimero(stNodo * lista);

//eliminar ultimo
stNodo * CargarLista(stNodo * lista);
stNodo * CargarListaEnOrdenNombre(stNodo * lista);
//stNodo * CargarListaEnOrdenEdad(stNodo * lista);

void MostrarUnNodo(stNodo * nodo);
void MostrarListaCompleta(stNodo * nodo);

//extraer primero Complejidad, devolver puntero al nodo extraido
//y desde la funcion con puntero doble modificar el otro

stNodo * ExtraerNodo(stNodo ** lista);

//FUNCIONES QUE TRABAJAN CON LA ESTRUCTURA Usuario
stNodo * AgregarEnOrdenByNombre(stNodo * lista, stNodo * nuevoNodo);

//stNodo * BorrarNodoByNombre(char nombre[20], stNodo * lista);
//stNodo * BorrarNodoByEdad(int edad, stNodo * lista);

//stNodo * BuscarNodoByNombre(char nombre[20], stNodo * lista);
//stNodo * BuscarNodoByEdad(int edad, stNodo * lista);

#endif // LISTAS_H_INCLUDED
