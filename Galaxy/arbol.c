#include "arbol.h"


nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol * crearNodoArbol(int dato)
{
    nodoArbol* aux = (nodoArbol*) malloc(sizeof(nodoArbol));
    aux->dato = dato;
    aux->izq = NULL;
    aux->der = NULL;
    return aux;
}


nodoArbol * insertar (nodoArbol * arbol, int dato)
{
    if(!arbol)
    {
        arbol = crearNodoArbol(dato);
    }
    else
    {
        if(dato > arbol->dato)
        {
            arbol->der = insertar(arbol->der, dato);
        }
        else
        {
            arbol->izq = insertar(arbol->izq, dato);
        }
    }
    return arbol;
}

void inorder(nodoArbol * arbol)
{
    if(arbol!=NULL)
    {
        inorder(arbol->izq);
        mostrarNodoInt(arbol);
        inorder(arbol->der);
    }
}

void preorder(nodoArbol * arbol)
{
    if(arbol!=NULL)
    {
        mostrarNodoInt(arbol);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

void postorder(nodoArbol * arbol)
{
    if(arbol!=NULL)
    {
        postorder(arbol->izq);
        postorder(arbol->der);
        mostrarNodoInt(arbol);
    }
}

void mostrarNodoInt(nodoArbol * arbol)
{   
    printf("%d \n", arbol->dato);
}
