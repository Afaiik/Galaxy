#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"

#define archivoUsuarios "arUsuarios.dat"

#define ESC 27

#define CODADMIN 123
#define TIPOADMIN 1
#define TIPONORMAL 0

void cargaArchivoUsuarios(){

    Usuario usua;
    int codAdmin;
    int valido = 0;
    char nombreAux[30];
    usua.Activo = 1;
    usua.Id = getUltimoIdUsuario(archivoUsuarios)+1;
    system("cls");

    while(valido == 0)
    {
        printf("\n\t\t<<<<<<<<<< CREACION DE USUARIO >>>>>>>>>>");
        printf("\nNombre de Usuario..............:");
        fflush(stdin);
        scanf("%s", &nombreAux);
        if(checkExisteUsuarioNombre(nombreAux,archivoUsuarios) == 0)
        {
            valido = 1;
            strcpy(usua.Nombre, nombreAux);
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
    gets(usua.Contra);

    printf("\nSi posee codigo de Administrador, Ingreselo..:");
    scanf("%d", &codAdmin);
    if(codAdmin == CODADMIN)
        usua.Tipo = TIPOADMIN;
    else///TIPO DE USUARIO 1 ADMIN 0 USUARIO REGULAR
        usua.Tipo = TIPONORMAL;

    guardarUsuario(usua);

}

Usuario crearUnUsuario()
{
    Usuario usua;
    int codAdmin;
    int valido = 0;
    char nombreAux[30];
    int checkExist = 2;
    usua.Activo = 1;
    usua.Id = getUltimoIdUsuario(archivoUsuarios)+1;
    system("cls");

    while(valido == 0)
    {
        //color(10);
        printf("\n\t\t<<<<<<<<<< CREACION DE USUARIO >>>>>>>>>>");
        printf("\nNombre de Usuario..............:");
        fflush(stdin);
        scanf("%s", &nombreAux);
        checkExist = checkExisteUsuarioNombre(nombreAux, archivoUsuarios);
        if((checkExisteUsuarioNombre(nombreAux, archivoUsuarios) == 0) || (checkExisteUsuarioNombre(nombreAux, archivoUsuarios) == -1))
        {
            valido = 1;
            strcpy(usua.Nombre, nombreAux);
        }else
        {
            system("cls");
            printf("\a");
            gotoxy(15,5);
            printf("Ese usuario ya se encuentra en uso!");
            getch();
            gotoxy(0,0);
            system("cls");
        }
    }
    printf("\nPassword.....................:");
    fflush(stdin);
    gets(usua.Contra);

    printf("\nSi posee codigo de Administrador, Ingreselo..:");
    scanf("%d", &codAdmin);
    if(codAdmin == CODADMIN)
        usua.Tipo = TIPOADMIN;
    else///TIPO DE USUARIO 1 ADMIN 0 USUARIO REGULAR
        usua.Tipo = TIPONORMAL;

    return usua;
}

void crearUnUsuarioEnArchivo()
{
    Usuario usua = crearUnUsuario();
    guardarUsuario(usua);
}

void guardarUsuario(Usuario usua){
    FILE *pArchUsuarios = fopen(archivoUsuarios,"a+b");
    if(pArchUsuarios != NULL){
        fseek(pArchUsuarios, sizeof(Usuario), SEEK_END);
        fwrite(&usua, sizeof(Usuario),1,pArchUsuarios);
        fclose(pArchUsuarios);
    }
}

void mostrarUnUsuario(Usuario usua)
{
    if(usua.Activo == 1)
    {
        printf("\n ID: %d", usua.Id);
        printf("\n Activo: %d", usua.Activo);
        printf("\n Tipo: %d", usua.Tipo);
        printf("\n Nombre: %s", usua.Nombre);
        printf("\n contrase�a: %s", usua.Contra);
        printf("\n____________________");
    }
}

void mostrarArregloUsuarios(Usuario usua[], int val)
{
    int i;
    for(i = 0; i < val; i++)
    {
        mostrarUnUsuario(usua[i]);
    }
}

void mostrarArchivoUsuarios(char arUsuarios[])
{
    FILE *archi;
    archi = fopen(arUsuarios, "rb");
    Usuario usuaAux;

    if(archi != NULL)
    {
        while(fread(&usuaAux, sizeof(Usuario),1,archi)>0)
        {
            if(usuaAux.Activo == 1)
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
    Usuario usuaAux;

    if(archi != NULL)
    {
        while(fread(&usuaAux, sizeof(Usuario),1,archi)>0)
        {
            if((usuaAux.Activo == 1) && (usuaAux.Tipo == TIPOADMIN))
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
    Usuario usua;
    int flag = -1; /// -1 error no abrio archivo, 0 no encontro ID, 1 encontro ID
    FILE *pArch;
    pArch = fopen(arUsuarios, "rb");

    if(pArch != NULL)
    {
        while(fread(&usua, sizeof(Usuario), 1, pArch)>0)
        {
            if((strcmp(strlwr(usua.Nombre), strlwr(nombreBuscado)) == 0) && (usua.Activo == 1))
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

void eliminarMiUsuario(Usuario usuaLogueado)
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
        flag = eliminarUsuarioById(usuaLogueado.Id);
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
    mostrarUnUsuario(usua);
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
