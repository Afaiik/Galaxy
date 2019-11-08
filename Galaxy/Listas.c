#include <stdio.h>
#include <stdlib.h>
#include "Listas.h "

#define arUsuarios "usuarios.dat" /// OJO QUE DEFINI EL ARCHIVO EN LISTAS.C

#define ESC 27

//Funciones de nodoUsuario
stNodoUsuario * inicLista()
{
    return NULL;
}

stNodoUsuario * crearNodo(stUsuario newuser)
{
    stNodoUsuario * aux =(stNodoUsuario*)malloc(sizeof(stNodoUsuario));
    aux->user = newuser;
    aux->sig = NULL;

    return aux;
}

stNodoUsuario * agregarPrincipio(stNodoUsuario * lista, stNodoUsuario * newnodo)
{
    newnodo->sig = lista;
    lista = newnodo;

    return lista;
}

stNodoUsuario * agregarFinal(stNodoUsuario * lista, stNodoUsuario * newnodo)
{
    if(!lista){
        lista = newnodo;
    }else{
        stNodoUsuario * ultimo = buscarUltimo(lista);
        ultimo->sig = newnodo;
    }
    return lista;
}

stNodoUsuario * buscarUltimo(stNodoUsuario * lista)
{
    stNodoUsuario * seg = lista;
    if(seg)
        while(seg->sig)
        {
            seg = seg->sig;
        }
    return seg;
}

stNodoUsuario * borrarTodaLaLista(stNodoUsuario * lista)
{
    stNodoUsuario * proximo;
    stNodoUsuario * seg = lista;
    while(seg)
    {
        proximo = seg->sig;
        free(seg);
        seg = proximo;
    }
    return seg;
}


void mostrarUnNodo(stNodoUsuario * nodo)
{
    mostrarUnUsuario(nodo->user);
    //printf("\nSiguiente.....: %p", nodo->sig);
}


void mostrarListaCompleta(stNodoUsuario * lista)
{
    stNodoUsuario * seg = lista;
    while(seg)
    {
        mostrarUnNodo(seg);
        seg = seg->sig;
    }
}

stNodoUsuario * cargarLista(stNodoUsuario * lista)
{
    int opcion = 0;
    stNodoUsuario * newnodo;
    stUsuario newuser;
    while(opcion != ESC)
    {
        newuser = crearUnUsuario();
        newnodo = crearNodo(newuser);
        lista = agregarPrincipio(lista, newnodo);
        printf("\n\t\tESC PARA SALIR");
        opcion = getch();
        system("cls");
    }
    return lista;
}

stNodoUsuario * cargarListaEnOrdenNombre(stNodoUsuario * lista)
{
    int opcion = 0;
    stNodoUsuario * newnodo;
    stUsuario newuser;
    while(opcion != ESC)
    {
        newuser = crearUnUsuario();
        newnodo = crearNodo(newuser);
        lista = agregarEnOrdenByNombre(lista, newnodo);
        printf("\n\t\tESC PARA SALIR");
        opcion = getch();
        system("cls");
    }
    return lista;
}


stNodoUsuario * extraerNodo(stNodoUsuario ** lista)
{
    stNodoUsuario * primero = NULL;

    if ((*lista))
    {
        primero = (*lista);
        (*lista) = primero->sig;
        primero->sig = NULL;
    }
    return primero;
}


stNodoUsuario * agregarEnOrdenByNombre(stNodoUsuario * lista, stNodoUsuario * newnodo)
{
    if(lista)
    {
        lista = newnodo;
    }
    else
    {
        if(strcmpi(newnodo->user.nombreUsuario,lista->user.nombreUsuario)<0)
        {
            lista = agregarPrincipio(lista, newnodo);
        }
        else
        {
            stNodoUsuario * ante = lista;
            stNodoUsuario * seg = lista->sig;
            while((seg) && (strcmpi(newnodo->user.nombreUsuario,seg->user.nombreUsuario)>0))
            {
                ante = seg;
                seg = seg->sig;
            }
            newnodo->sig = seg;
            ante->sig = newnodo;
        }
    }
    return lista;
}

//Funciones de nodoLog

stNodoLog * crearNodoLog(stLog newlog){
    stNodoLog * newnodo = (stNodoLog*)malloc(sizeof(stNodoLog));
    newnodo->dato = newlog;
    newnodo->sig = NULL;

    return newnodo;
}

stNodoLog * agregarPrincipioLog(stNodoLog * lista, stNodoLog * newnodo){

    lista->sig = newnodo;
    newnodo = lista;

    return lista;

}

stNodoLog * agregarFinalLog(stNodoLog * lista, stNodoLog * newnodo){
    if(!lista){
        lista == newnodo;
    }else{
        stNodoLog * ultimo = buscarUltimoLog(lista);
        ultimo->sig = newnodo;
    }
    return lista;
}
stNodoLog * buscarUltimoLog(stNodoLog * lista){
    stNodoLog * ultimo = NULL;
    if(lista){
        ultimo = buscarUltimo(lista->sig);
    }
    return ultimo;
}
void mostrarNodoLog(stNodoLog * nodo){ /// RECURSIVA.
    mostrarLog(nodo->dato);
}
void mostrarListaLog(stNodoLog * lista){ /// RECURSIVA.

    if(lista){
        mostrarNodoLog(lista);
        mostrarListaLog(lista->sig);
    }
}


///Sección de funciones de arreglo de listas para el TPF.

int buscarPosUsuario(stCelda adl[], int validos, int idBuscado){ /// Retorna la posicion del usuario buscandolo mediante su ID.
    int pos = -1;
    int i = 0;
    while((i<validos) && (pos==-1)){
        if(adl[i].user.idUsuario == idBuscado){
            pos = i;
        }
        i++;
    }
    return pos;
}

int agregarCelda(stCelda adl[],int validos,stUsuario newuser){ /// Agrega
    adl[validos].user = newuser;
    adl[validos].listaDeLog = inicLista();
    validos++;

    return validos;
}

int cargarAdl(stCelda adl[], int validos,stUsuario newuser){
    int pos = buscarPosUsuario(adl,validos,newuser.idUsuario);
    if(pos==-1){
        validos = agregarCelda(adl,validos,newuser);
        pos = validos-1;
    }
    adl[validos].listaDeLog = inicLista();
    return validos;
}

int archivo2adl(stCelda adl[],int validos, int dim){
    FILE * pArchi = fopen(arUsuarios,"rb");
    int i = 0;
    if(pArchi){
        stUsuario newuser;
        while((fread(&newuser,sizeof(stUsuario),1,pArchi)>0) &&(validos<dim)){

            validos = cargarAdl(adl,validos,newuser);
        }
        fclose(pArchi);
    }

    return validos;
}

