#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
#include "Listas.h"


typedef struct nodoArbol
{
    int dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;


nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(int dato);
nodoArbol * insertar (nodoArbol * arbol, int dato);
void inorder(nodoArbol * arbol);
void preorder(nodoArbol * arbol);
void postorder(nodoArbol * arbol);
void mostrarNodoInt(nodoArbol * arbol);
nodoArbol * cargarPuntajesEnRanking(nodoArbol * arbol, stCelda adl[],int validos);

#endif // ARBOL_H_INCLUDED
