#include <stdio.h>
#include <stdlib.h>
#include "Listas.h "
#include "arbol.h"

#define arUsuarios "arUsuarios.dat"
#define arLogs "arLogs.dat"

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

///Guardar Log en Archivo
void guardarLogPartida(int puntaje, stUsuario usuaLogueado, char archivo[]){
    stLog newLog;
    newLog.idLog = getUltimoIdLog(archivo) + 1;
    newLog.idUsuario = usuaLogueado.idUsuario;
    newLog.puntaje = puntaje;

    FILE * pArchi = fopen("arLogs.dat", "a+b");
    if(pArchi){
        fwrite(&newLog, sizeof(stLog), 1, pArchi);
        fclose(pArchi);
    }
}

int getUltimoIdLog(char archivo[])
{
    int mayor = 0;
    FILE * pArchi = fopen(archivo, "rb");
    if(pArchi){
        fseek(pArchi,0,SEEK_END);
        int bytes = ftell(pArchi);
        mayor = bytes / sizeof(stLog);
    }

    return mayor;
}

//Funciones de nodoLog

stNodoLog * inicListaLog(){
    return NULL;
}

stNodoLog * crearNodoLog(stLog newlog){
    stNodoLog * newnodo = (stNodoLog*)malloc(sizeof(stNodoLog));
    newnodo->dato = newlog;
    newnodo->sig = NULL;

    return newnodo;
}

stNodoLog * agregarPrincipioLog(stNodoLog * lista, stNodoLog * newnodo){

    newnodo->sig = lista;
    lista = newnodo;

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
void mostrarNodoLog(stNodoLog * nodo){
    mostrarLog(nodo->dato);
}
void mostrarListaLog(stNodoLog * lista){ /// RECURSIVA.

    if(lista){
        mostrarLogSimple(lista->dato);
        mostrarListaLog(lista->sig);
    }
}

///Secci�n de funciones de arreglo de listas para el TPF.

int buscarPosUsuario(stCelda adl[], int validos, int idBuscado){ /// Retorna la posicion del usuario buscandolo mediante su ID.
    int pos = -1;
    int i = 0;
    while((i < validos) && (pos == -1)){
        if(adl[i].user.idUsuario == idBuscado){
            pos = i;
        }
        i++;
    }
    return pos;
}

int agregarCeldaVacia(stCelda adl[],int validos,stUsuario newuser){ /// Agrega una celda al ADL. La inicializa en vacio para luego llenar los datos de la lista con los registros del archivo log.
    adl[validos].user = newuser;
    adl[validos].listaDeLog = inicListaLog();

    validos++;

    return validos;
}

int cargarAdl(stCelda adl[], int validos, stUsuario newuser){
    int pos = buscarPosUsuario(adl,validos,newuser.idUsuario);
    if(pos == -1){
        validos = agregarCeldaVacia(adl,validos,newuser);
        pos = validos-1;
    }
    adl[pos].listaDeLog = logeos2listaEnAdl(adl[pos].listaDeLog,newuser.idUsuario);

    return validos;
}

int usuarios2arreglo(stCelda adl[],int validos, int dim){
    FILE * pArchi = fopen(arUsuarios,"r+b");
    stUsuario newuser;
    if(pArchi){
        while( (fread(&newuser, sizeof(stUsuario), 1, pArchi) > 0) && (validos < dim)){
            if(newuser.activo == 1){
                validos = cargarAdl(adl,validos,newuser);
            }
        }
        fclose(pArchi);
    }

    return validos;
}


stNodoLog * logeos2listaEnAdl(stNodoLog * lista, int userId){
    FILE * pArchiLog = fopen("arLogs.dat","rb");
    if(pArchiLog){
        stLog newlog;
        stNodoLog * newnodo;
        while(fread(&newlog, sizeof(stLog), 1, pArchiLog) > 0){
            if(newlog.idUsuario == userId){
                newnodo = crearNodoLog(newlog);
                lista = agregarPrincipioLog(lista,newnodo);
            }
        }
        fclose(pArchiLog);
    }
    return lista;
}


void mostrarLog(stLog logMostrado){
    printf("\nID USUARIO: %d",logMostrado.idUsuario);
    printf("\nID LOG: %d",logMostrado.idLog);
    printf("\nSCORE: %d",logMostrado.puntaje);
}

void mostrarAdl(stCelda adl[],int validos){
    int i;
    for(i=0;i<validos;i++){
        mostrarUnUsuario(adl[i].user);
        printf("\n************************\n");
        printf("LISTA DE LOGS");
        printf("\n************************\n");
        mostrarListaLog(adl[i].listaDeLog);
        printf("\n_______________________________________________\n");
    }
}
void mostrarLogSimple(stLog log){
    printf("\nLog ID..: %d   UserId..: %d   Score..: %d", log.idLog, log.idUsuario, log.puntaje);
}


void mostrarArchivoLogs(char nombreArchivo[]){
    stLog aux;
    FILE * pArchi = fopen(nombreArchivo, "rb");
    if(pArchi){
        while(fread(&aux, sizeof(stLog), 1, pArchi) > 0){
            mostrarLogSimple(aux);
        }
        fclose(pArchi);
    }
}


void mostrarArchivoLogsByNombre(char nombreArchivo[], char nombreUsuario[]){
    stUsuario user = getUsuarioByNombre(nombreUsuario, arUsuarios);
    stLog aux;
    FILE * pArchi = fopen(nombreArchivo, "rb");
    if(pArchi){
        while(fread(&aux, sizeof(stLog), 1, pArchi) > 0){
            if(aux.idUsuario == user.idUsuario){
                mostrarLogSimple(aux);
            }
        }
        fclose(pArchi);
    }
}

void interfazMostrarLogsByNombre(stUsuario usuaLogueado){

    stUsuario usua;
    int flag = -1;
    FILE *pArch;
    char opcion;
    char nombreUsua[30];
    system("cls");
    printf("\n\t\t<<<<<<<<<MOSTRAR LOGS POR NOMBRE DE USUARIO>>>>>>>>>\n");
    printf("\n\tIntroduzca el nombre del usuario del que desea ver puntajes...: ");
    fflush(stdin);
    gets(nombreUsua);
    usua = getUsuarioByNombre(nombreUsua, arUsuarios);

    if(usua.idUsuario != -1){
        printf("\nPuntajes de %s\n", usua.nombreUsuario);
        puts("\n");
        mostrarArchivoLogsByNombreEnArbol(arLogs, usua.nombreUsuario);
        getch();
        menuAdministracion(usuaLogueado);
    }else
    {
        system("cls");
        printf("\a");
        gotoxy(15,5);
        printf("\nNo existe ningun usuario con ese nombre.");
        getch();
        gotoxy(0,0);
        system("cls");
        menuAdministracion(usuaLogueado);
    }

}
int buscarMayorScore(stNodoLog * lista){
    int scoreMax = 0;
    stNodoLog * seg = lista;
    while(seg){
        if(seg->dato.puntaje > scoreMax){
            scoreMax = seg->dato.puntaje;
        }
        seg = seg->sig;
    }

    return scoreMax;
}

