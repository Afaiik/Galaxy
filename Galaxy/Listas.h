#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED


#include "usuarios.h"

typedef struct{
    stUsuario user;
    struct stNodoUsuario * sig;
}stNodoUsuario; /// Para la lista de usuarios.

typedef struct{
    stLog dato;
    struct stNodoLog * sig;
}stNodoLog;

typedef struct{
    stUsuario user;
    stNodoLog * listaDeLog;
}stCelda;

// FUNCIONES LISTA USUARIO.
stNodoUsuario * inicLista();
stNodoUsuario * crearNodo (stUsuario newuser);
stNodoUsuario * agregarPrincipio (stNodoUsuario * lista, stNodoUsuario * newnodo);
stNodoUsuario * agregarFinal(stNodoUsuario * lista, stNodoUsuario * newnodo);
stNodoUsuario * buscarUltimo(stNodoUsuario * lista);
stNodoUsuario * borrarTodaLaLista(stNodoUsuario * lista);
stNodoUsuario * eliminarPrimero(stNodoUsuario * lista);
stNodoUsuario * cargarLista(stNodoUsuario * lista);
stNodoUsuario * cargarListaEnOrdenNombre(stNodoUsuario * lista);
void mostrarUnNodo(stNodoUsuario * nodo);
void mostrarListaCompleta(stNodoUsuario * nodo);
stNodoUsuario * extraerNodo(stNodoUsuario ** lista);
stNodoUsuario * agregarEnOrdenByNombre(stNodoUsuario * lista, stNodoUsuario * newnodo);

// FUNCIONES LISTA LOG.
stNodoLog * crearNodoLog(stLog newlog);
stNodoLog * agregarPrincipioLog(stNodoLog * lista, stNodoLog * newnodo);
stNodoLog * agregarFinalLog(stNodoLog * lista, stNodoLog * newnodo);
stNodoLog * buscarUltimoLog(stNodoLog * lista);
void mostrarNodoLog(stNodoLog * nodo);
void mostrarListaLog(stNodoLog * lista);

///Secci�n de funciones de arreglo de listas para el TPF.

int buscarPosUsuario(stCelda adl[], int validos, int idBuscado);
int agregarCeldaVacia(stCelda adl[],int validos,stUsuario newuser);
int cargarAdl(stCelda adl[], int validos,stUsuario newuser);
stNodoLog * cargaListaEnAdl();
int usuarios2arreglo(stCelda adl[],int validos, int dim);
stNodoLog * logeos2listaEnAdl(stNodoLog * lista);
void mostrarAdl(stCelda adl[],int validos);

///Muestra un log.
void mostrarLog(stLog logMostrado);

#endif // LISTAS_H_INCLUDED
