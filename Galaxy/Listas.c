#include <stdio.h>
#include <stdlib.h>
#include "Listas.h "

#define ESC 27

//Funciones de stNodo
stNodo * InicLista()
{
    return NULL;
}


stNodo * CrearNodo(Usuario usuario)
{
    stNodo * aux = (stNodo*) malloc(sizeof(stNodo));
    aux->dato = usuario;
    aux->Siguiente = NULL;

    return aux;
}

stNodo * AgregarPpio(stNodo * lista, stNodo * nuevoNodo)
{

    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->Siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

stNodo * AgregarFinal(stNodo * lista, stNodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        stNodo * ultimo = BuscarUltimo(lista);
        ultimo->Siguiente = nuevoNodo;
    }
    return lista;
}

stNodo * BuscarUltimo(stNodo * lista)
{
    stNodo * seg = lista;
    if(seg != NULL)
        while(seg->Siguiente != NULL)
        {
            seg = seg->Siguiente;
        }
    return seg;
}

stNodo * BorrarTodaLaLista(stNodo * lista)
{
    stNodo * proximo;
    stNodo * seg = lista;
    while(seg != NULL)
    {
        proximo = seg->Siguiente;
        free(seg);
        seg = proximo;
    }
    return seg;
}


void MostrarUnNodo(stNodo * nodo)
{
    mostrarUnUsuario(nodo ->dato);
    printf("\nSiguiente.....: %p", nodo->Siguiente);
}


void MostrarListaCompleta(stNodo * lista)
{
    stNodo * seg = lista;
    while(seg != NULL)
    {
        MostrarUnNodo(seg);
        seg = seg->Siguiente;
    }
}

stNodo * CargarLista(stNodo * lista)
{
    int opcion = 0;
    stNodo * nuevo;
    Usuario persona;
    while(opcion != ESC)
    {
        persona = crearUnUsuario();
        nuevo = CrearNodo(persona);
        lista = AgregarPpio(lista, nuevo);
        printf("\n\t\tESC PARA SALIR");
        opcion = getch();
        system("cls");
    }
    return lista;
}

stNodo * CargarListaEnOrdenNombre(stNodo * lista)
{
    int opcion = 0;
    stNodo * nuevo;
    Usuario persona;
    while(opcion != ESC)
    {
        persona = crearUnUsuario();
        nuevo = CrearNodo(persona);
        lista = AgregarEnOrdenByNombre(lista, nuevo);
        printf("\n\t\tESC PARA SALIR");
        opcion = getch();
        system("cls");
    }
    return lista;
}


stNodo * ExtraerNodo(stNodo ** lista)
{
    stNodo * primero = NULL;

    if ( (*lista) != NULL)
    {
        primero = (*lista);
        (*lista) = primero->Siguiente;
        primero->Siguiente = NULL;
    }
    return primero;
}


//FUNCIONES QUE TRABAJAN CON LA ESTRUCTURA PERSONA

stNodo * AgregarEnOrdenByNombre(stNodo * lista, stNodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if(strcmp(tolower(nuevoNodo->dato.Nombre),tolower(lista->dato.Nombre))<0)
        {
            lista = AgregarPpio(lista, nuevoNodo);
        }
        else
        {
            stNodo * ante = lista;
            stNodo * seg = lista->Siguiente;
            while((seg != NULL) && (strcmp(tolower(nuevoNodo->dato.Nombre),tolower(seg->dato.Nombre))>0))
            {
                ante = seg;
                seg = seg->Siguiente;
            }
            nuevoNodo->Siguiente = seg;
            ante->Siguiente = nuevoNodo;
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

