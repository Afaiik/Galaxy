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

///Para el menu estadisticas usar ARBOL
void mostrarLogEnArbol(char nombreArchivo[]){

    nodoArbol * arbol = inicArbol();
    stLog aux;
    nodoArbol * nuevo;
    FILE * pArchi = fopen(nombreArchivo, "rb");
    if(pArchi){
        while(fread(&aux, sizeof(stLog), 1, pArchi) > 0){
            arbol = insertar(arbol, aux.puntaje);
        }
        fclose(pArchi);
    }
    inorder(arbol);
}

void mostrarArchivoLogsByNombreEnArbol(char nombreArchivo[], char nombreUsuario[]){
    stUsuario user = getUsuarioByNombre(nombreUsuario, arUsuarios);
    stLog aux;
    nodoArbol * arbol = inicArbol();
    nodoArbol * nuevo;
    FILE * pArchi = fopen(nombreArchivo, "rb");
    if(pArchi){
        while(fread(&aux, sizeof(stLog), 1, pArchi) > 0){
            if(aux.idUsuario == user.idUsuario){
                arbol = insertar(arbol, aux.puntaje);
            }
        }
        fclose(pArchi);
    }
    inorder(arbol);
}

nodoArbol * cargarArbolRanking(nodoArbol * arbol, int dato){
    if(arbol){
        arbol = insertar(arbol,dato);
    }else{
        if(arbol);
    }
}


El ranking consta de 10 puntajes, si el ultimo puntaje es mayor que el ultimo, lo cambia.
