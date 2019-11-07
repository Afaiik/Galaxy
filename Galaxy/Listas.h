#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED


#include "usuarios.h"

typedef struct {
    stUsuario user;
    struct stNodoUsuario * sig;
}stNodoUsuario; /// Para la lista de usuarios.

// FUNCIONES BASICAS / GENERICAS
stNodoUsuario * inicLista();
stNodoUsuario * crearNodo (stUsuario newuser);

stNodoUsuario * agregarPrincipio (stNodoUsuario * lista, stNodoUsuario * newnodo);
stNodoUsuario * agregarFinal(stNodoUsuario * lista, stNodoUsuario * newnodo);

stNodoUsuario * buscarUltimo(stNodoUsuario * lista);
stNodoUsuario * borrarTodaLaLista(stNodoUsuario * lista);

stNodoUsuario * eliminarPrimero(stNodoUsuario * lista);

//eliminar ultimo
stNodoUsuario * cargarLista(stNodoUsuario * lista);
stNodoUsuario * cargarListaEnOrdenNombre(stNodoUsuario * lista);
//stNodo * cargarListaEnOrdenEdad(stNodo * lista);

void mostrarUnNodo(stNodoUsuario * nodo);
void mostrarListaCompleta(stNodoUsuario * nodo);

//extraer primero Complejidad, devolver puntero al nodo extraido
//y desde la funcion con puntero doble modificar el otro

stNodoUsuario * extraerNodo(stNodoUsuario ** lista);

//FUNCIONES QUE TRABAJAN CON LA ESTRUCTURA Usuario
stNodoUsuario * agregarEnOrdenByNombre(stNodoUsuario * lista, stNodoUsuario * newnodo);

//stNodo * BorrarNodoByNombre(char nombre[20], stNodo * lista);
//stNodo * BorrarNodoByEdad(int edad, stNodo * lista);

//stNodo * BuscarNodoByNombre(char nombre[20], stNodo * lista);
//stNodo * BuscarNodoByEdad(int edad, stNodo * lista);

#endif // LISTAS_H_INCLUDED
