#include <stdio.h>
#include <stdlib.h>
#include "Listas.h "

#define ESC 27

//Funciones de stNodo
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
        newnodo = CrearNodo(newuser);
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


//FUNCIONES QUE TRABAJAN CON LA ESTRUCTURA PERSONA

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

/*
stNodo * BuscarNodoByNombre(char nombre[20], stNodo * lista)   ///Ex BuscarNodo
{
    stNodo * seg = lista;
    while ((seg != NULL) && (strcmp(tolower(nombre), tolower(seg->Usuario.Nombre))!=0 ))
    {
        seg=seg->Siguiente;
    }
    return seg;
}

stNodo * BuscarNodoByEdad(int edad, stNodo * lista)
{
    stNodo * seg = lista;
    while ((seg != NULL) && (edad != seg->Usuario.Edad))
    {
        seg=seg->Siguiente;
    }
    return seg;
}

stNodo * BorrarNodoByNombre(char nombre[20], stNodo * lista)
{
    stNodo * seg;
    stNodo * ante;
    if(lista != NULL)
    {
        if((strcmp(tolower(nombre), tolower(lista->Usuario.Nombre))==0 ))
        {
            stNodo * aux = lista;
            lista = lista->Siguiente;
            free(aux);
        }
        else
        {
            seg = lista;
            while((seg != NULL) && (strcmp(tolower(nombre), tolower(seg->Usuario.Nombre))!=0 ))
            {
                ante = seg;
                seg = seg->Siguiente;
            }
            if(seg!=NULL)
            {
                ante->Siguiente = seg->Siguiente;
                free(seg);
            }
        }

    }
    return lista;
}

stNodo * BorrarNodoByEdad(int edad, stNodo * lista)
{
    stNodo * seg;
    stNodo * ante;
    if(lista != NULL)
    {
        if(edad == lista->Usuario.Edad)
        {
            stNodo * aux = lista;
            lista = lista->Siguiente;
            free(aux);
        }
        else
        {
            seg = lista;
            while((seg != NULL) && (edad != seg->Usuario.Edad))
            {
                ante = seg;
                seg = seg->Siguiente;
            }
            if(seg!=NULL)
            {
                ante->Siguiente = seg->Siguiente;
                free(seg);
            }
        }
    }

    return lista;
}*/

///Sección de funciones de listas para el TPF.



