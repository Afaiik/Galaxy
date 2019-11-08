#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "usuarios.h"

#define arUsuarios "usuarios.dat"

#define ESC 27

#define CODADMIN 123
#define TIPOADMIN 1
#define TIPONORMAL 0

void cargaArchivoUsuarios(){

}

stUsuario crearUnUsuario() /// Adaptada.
{
    stUsuario newuser;
    char codAdmin[20];
    int valido = 0;

    char genAux;
    char nombreAux[30];
    newuser.activo = 1;
    newuser.idUsuario = getUltimoIdUsuario(archivoUsuarios)+1;
    system("cls");

    while(valido == 0)
    {
        printf("\n\t\t<<<<<<<<<< CREACION DE USUARIO >>>>>>>>>>");
        printf("\nNombre de Usuario..............:");
        fflush(stdin);
        gets(nombreAux);
       // int anioNacimiento;
        char genero;
        char pais[20];

        if(checkExisteUsuarioNombre(nombreAux,archivoUsuarios) == 0)
        {
            valido = 1;
            strcpy(newuser.nombreUsuario, nombreAux);
        }else
        {
            system("cls");
            printf("\a");
            gotoxy(15,5);
            //color(4);
            printf("Ese usuario ya se encuentra en uso!");
            getch();
            gotoxy(0,0);
            system("cls");
        }
    }
    printf("\nPassword.....................:");
    fflush(stdin);
    gets(newuser.pass);
    printf("\nGenero(M/F).................:");
    fflush(stdin);
    scanf("%c",&genAux);
    while(tolower(genAux) != 'f' || tolower(genAux) != 'm'){
        printf("\nOPCION INCORRECTA, INGRESE UNA VALIDA (M/F)");
        fflush(stdin);
        scanf("%c",&genAux);
    }
    strcpy(newuser.genero,genAux);
    printf("\nPAIS........................:");
    fflush(stdin);
    gets(newuser.pais); /// Si queremos rebuscarla mucho, hacemos un archivo con paises existentes, y si no lo encuentra ahí, le pedimos que ingrese uno que exista.

    char tieneCod = 0; /// Si tiene codigo 'S', sino 'N'

        printf("\nPosee codigo de administrador ? S/N");
        fflush(stdin);
        scanf("%c", &tieneCod);
        while(tolower(tieneCod) != 's' || tolower(tieneCod) != 'n'){
            printf("\nOPCION INCORRECTA");
            fflush(stdin);
            scanf("%c", &tieneCod);
        }

    if(tolower(tieneCod) == 's'){
        printf("\nIngrese su codigo de administrador: ");
        scanf("%d", &codAdmin);

        if(strcmp(codAdmin, CODADMIN) == 0)
            newuser.tipo = TIPOADMIN;
        else///TIPO DE USUARIO 1 ADMIN 0 USUARIO REGULAR
            newuser.tipo = TIPONORMAL;

        guardarUsuario(newuser);
    }

    return newuser;
}

void crearUnUsuarioEnArchivo() /// Adaptada.
{
    stUsuario newuser = crearUnUsuario();
    guardarUsuario(newuser);
}

void guardarUsuario(stUsuario newuser){ /// Adaptada.
    FILE *pArchUsuarios = fopen(archivoUsuarios,"a+b");
    if(pArchUsuarios){
        fseek(pArchUsuarios, sizeof(stUsuario), SEEK_END);
        fwrite(&newuser, sizeof(stUsuario),1,pArchUsuarios);
        fclose(pArchUsuarios);
    }
}


void mostrarUnUsuario(stUsuario newuser)
{
    if(newuser.activo == 1)
    {
        printf("\n ID: %d", newuser.idUsuario);
        printf("\n Activo: %d", newuser.activo);
        printf("\n Tipo: %d", newuser.tipo);
        printf("\n Nombre: %s", newuser.nombreUsuario);
        printf("\n Password: %s", newuser.pass);
        if(tolower(newuser.genero) == 'm'){
            printf("\nGenero: Masculino");
        }else{
            printf("\nGenero: Femenino");
        }
        printf("\n Pais: %s",newuser.pais);
        printf("\n____________________");
    }
}

void mostrarArregloUsuarios(stUsuario user[], int val)
{
    int i;
    for(i = 0; i < val; i++)
    {
        mostrarUnUsuario(user[i]);
    }
}

void mostrarArchivoUsuarios(char arUsuarios[])
{
    FILE *archi;
    archi = fopen(arUsuarios, "rb");
    stUsuario usuaAux;

    if(archi)
    {
        while(fread(&usuaAux, sizeof(stUsuario),1,archi)>0)
        {
            if(usuaAux.activo == 1)
            {
                mostrarUnUsuario(usuaAux);
            }
        }
        fclose(archi);
    }
}

void mostrarUsuariosAdministradores(char arUsuarios[])
{
    FILE *archi;
    archi = fopen(arUsuarios, "rb");
    stUsuario usuaAux;

    if(archi != NULL)
    {
        while(fread(&usuaAux, sizeof(Usuario),1,archi)>0)
        {
            if((usuaAux.activo == 1) && (usuaAux.tipo == TIPOADMIN))
            {
                mostrarUnUsuario(usuaAux);
            }
        }
        fclose(archi);
    }
}

int getUltimoIdUsuario(char archivo[])
{
    int mayor = 0;
    FILE *archi;
    archi = fopen(archivo, "rb");
    Usuario usuaAux;

    if(archi != NULL)
    {
        while(!feof(archi)) ///Se cambio de fread > 0 a !feof porque no funcionaba
        {
            fread(&usuaAux,sizeof(Usuario),1,archi);
            if(!feof(archi))
            {
                if(usuaAux.Id > mayor)
                    mayor = usuaAux.Id;
            }
        }
        fclose(archi);
    }
    return mayor;
}

int checkExisteUsuarioId(int idBuscado, char arUsuarios[])
{
    Usuario usua;
    int flag = -1; /// -1 error no abrio archivo, 0 no encontro ID, 1 encontro ID
    FILE *pArch = fopen(arUsuarios, "rb");

    if(pArch != NULL)
    {
        while(fread(&usua, sizeof(Usuario), 1, pArch) > 0)
        {
            if((usua.Id == idBuscado) && (usua.Activo == 1))
            {
                flag = 1;
            }
        }
        if(flag != 1)
        {
            flag = 0;
        }
    fclose(pArch);
    }

   return flag;
}

int checkExisteUsuarioNombre(char nombreBuscado[], char arUsuarios[])
{
    stUsuario user;
    int flag = -1; /// -1 error no abrio archivo, 0 no encontro ID, 1 encontro ID
    FILE *pArch;
    pArch = fopen(arUsuarios, "rb");

    if(pArch)
    {
        while(fread(&user, sizeof(stUsuario), 1, pArch)>0)
        {
            if((strcmpi(user.nombreUsuario,nombreBuscado)== 0) && (user.activo == 1))
            {
                flag = 1;
            }
        }
        if(flag != 1)
        {
            flag = 0;
        }
        fclose(pArch);
    }

   return flag;
}

int checkTipoUsuarioById(int usuaId, char arUsuarios[])
{

    Usuario usua;
    int flag = -1; /// -1 error no abrio archivo, 0 no es admin, 1 es admin
    FILE *pArch;
    pArch = fopen(arUsuarios, "rb");
    if(usuaId <= getUltimoIdUsuario(arUsuarios))
    {
        if(pArch != NULL)
        {
            while(fread(&usua, sizeof(Usuario), 1, pArch)>0)
            {
                if(usua.Id == usuaId)
                {
                    if(usua.Tipo == 1)
                        flag = 1;
                }
            }
            if(flag != 1)
            {
                flag = 0;
            }
            fclose(pArch);
        }
    }else
    {
        system("cls");
        printf("\a");
        gotoxy(15,5);
        printf("No existe ningun usuario con ese id.");
        getch();
        gotoxy(0,0);
        system("cls");

    }
   return flag;
}

Usuario getUsuarioById(int idBuscado, char arUsuarios[])
{
    Usuario usua;
    int flag = 0;
    char stringAux[30] = "Usuario no encontrado";
    FILE *pArch;
    pArch = fopen(arUsuarios, "rb");

    if(idBuscado <= getUltimoIdUsuario(arUsuarios))
    {
        if(pArch != NULL)
        {
            while((flag == 0) && (fread(&usua, sizeof(Usuario), 1, pArch)>0))
            {
                if(usua.Id == idBuscado)
                {
                    flag = 1;
                }
            }
            if((flag == 0) || (usua.Activo == 0))
            {
                usua.Id = -1;
                strcpy(usua.Nombre, stringAux);
            }

            fclose(pArch);
        }
    }else
    {
        system("cls");
        printf("\a");
        gotoxy(15,5);
        printf("No existe ningun usuario con ese id.");
        getch();
        gotoxy(0,0);
        system("cls");

    }

   return usua;
}

Usuario getUsuarioByNombre(char nombreBuscado[], char arUsuarios[])
{
    Usuario usua;
    int flag = 0;
    char stringAux[30] = "Usuario no encontrado";
    FILE *pArch;
    pArch = fopen(archivoUsuarios, "rb");

        if(pArch != NULL)
        {
            while((flag == 0) && (fread(&usua, sizeof(Usuario), 1, pArch)>0))
            {
                if(strcmp(strlwr(usua.Nombre), strlwr(nombreBuscado)) == 0)
                {
                    flag = 1;
                }
            }
            if((flag == 0) || (usua.Activo == 0))
            {
                usua.Id = -1;
                strcpy(usua.Nombre, stringAux);
            }

            fclose(pArch);
        }
   return usua;
}


int eliminarUsuarioById(int usuaId)
{
    Usuario usua;
    int flag = 0;
    FILE *pArch;
    pArch = fopen(archivoUsuarios, "r+b");

    if(pArch != NULL)
    {
        while((flag == 0) && (fread(&usua, sizeof(Usuario), 1, pArch)>0))
        {
            if(usua.Id == usuaId)
            {
                if(usua.Activo == 1)
                {
                    flag = 1;
                }
            }
        }
    usua.Activo = 0;
    fseek(pArch, sizeof(Usuario)*(-1), SEEK_CUR);
    fwrite(&usua, sizeof(Usuario), 1, pArch);
    fclose(pArch);
    }
   return flag;
}

void eliminarMiUsuario(stUsuario usuaLogueado)
{
    Usuario usua;
    int flag = -1;
    FILE *pArch;
    char opcion;
    system("cls");
    printf("\n\t\t<<<<<<<<<ELIMINACION DE USUARIO>>>>>>>>>");
    printf("\n\n\t\tESTA SEGURO DE ELIMINAR SU USUARIO ?? S/N \n");
    fflush(stdin);
    scanf("%c", &opcion);
    if((opcion == 'S') || (opcion == 's'))
    {
        printf("\nMI USUARIO:");
        mostrarUnUsuario(usuaLogueado);
        getch();
        flag = eliminarUsuarioById(usuaLogueado.idUsuario);
        if(flag == 1)
        {
            system("cls");
            printf("\a");
            gotoxy(15,5);
            printf("\nEliminacion exitosa.");
            getch();
            gotoxy(0,0);
            system("cls");
//            menuLogin();
        }else
        {

            system("cls");
            printf("\a");
            gotoxy(15,5);
            printf("\nNo se pudo completar la operacion.");
            getch();
            gotoxy(0,0);
            system("cls");
//            menuLogin();
        }
    }
}


void eliminacionDeUsuario(Usuario usuaLogueado)
{
    Usuario usua;
    int flag = -1;
    FILE *pArch;
    char opcion;
    char nombreUsua[30];
    system("cls");
    printf("\n\t\t<<<<<<<<<ELIMINACION DE USUARIO>>>>>>>>>");
    printf("Introduzca el nombre del usuario que desea eliminar");
    fflush(stdin);
    gets(nombreUsua);
    usua = getUsuarioByNombre(nombreUsua, archivoUsuarios);

    printf("\n\n\t\tESTA SEGURO DE ELIMINAR EL SIGUIENTE USUARIO ?? S/N \n");
//    mostrarUnUsuario(usua);
    fflush(stdin);
    scanf("%c", &opcion);
    if((opcion == 'S') || (opcion == 's'))
    {
        flag = eliminarUsuarioById(usua.Id);
        if(flag == 1)
        {
            system("cls");
            printf("\a");
            gotoxy(15,5);
            printf("\nEliminacion exitosa.");
            getch();
            gotoxy(0,0);
            system("cls");
//            menuLogin();
        }else
        {

            system("cls");
            printf("\a");
            gotoxy(15,5);
            printf("\nNo se pudo completar la operacion.");
            getch();
            gotoxy(0,0);
            system("cls");
//            menuLogin();
        }
    }else
    {
//        menuGestionUsuarios(usuaLogueado);
    }

}

void mostrarLog(stLog logMostrado){
    printf("\nID USUARIO: %d",logMostrado.idUsuario);
    printf("\nID LOG: %d",logMostrado.idLog);
    printf("\nSCORE: %d",logMostrado.puntaje);
}
