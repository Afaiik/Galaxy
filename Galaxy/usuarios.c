#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "usuarios.h"

#define arUsuarios "arUsuarios.dat"

#define ESC 27

#define CODADMIN "asd"
#define TIPOADMIN 1
#define TIPONORMAL 0

void cargaArchivoUsuarios(){

}

stUsuario crearUnUsuario()
{
    stUsuario newuser;
    char codAdmin[20];
    int valido = 0;

    char genAux = 0;
    char nombreAux[30];
    newuser.activo = 1;
    newuser.idUsuario = getUltimoIdUsuario(arUsuarios)+1;
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
        int debugCheck = checkExisteUsuarioNombre(nombreAux,arUsuarios);

        if( debugCheck == 0)
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
    //printf("\nIngrese su fecha de nacimiento (Formato: AAAA/MM/DD");
    //scanf("%d")

    valido = 0;
    while(!valido){

        printf("\nGenero(M/F).................:");
        fflush(stdin);
        scanf("%c", &genAux);
        if(tolower(genAux) == 'f' || tolower(genAux) == 'm'){
            newuser.genero = genAux;
            valido = 1;
        }
    }

    printf("\nPAIS........................:");
    fflush(stdin);
    gets(newuser.pais); /// Si queremos rebuscarla mucho, hacemos un archivo con paises existentes, y si no lo encuentra ahí, le pedimos que ingrese uno que exista.
    char tieneCod = 0; /// Si tiene codigo 'S', sino 'N'
    valido = 0;
    while(!valido){

        printf("\nPosee codigo de administrador ? S/N");
        fflush(stdin);
        scanf("%c", &tieneCod);
        if(tolower(tieneCod) == 's' || tolower(tieneCod) == 'n')
            valido = 1;
    }

    if(tolower(tieneCod) == 's'){
        printf("\nIngrese su codigo de administrador: ");
        fflush(stdin);
        scanf("%s", codAdmin);

    }

    if(strcmp(codAdmin, CODADMIN) == 0)
        newuser.tipo = 1;
    else///TIPO DE USUARIO 1 ADMIN 0 USUARIO REGULAR
        newuser.tipo = 0;

    ///mostrarUnUsuario(newuser);
    return newuser;
}

void crearUnUsuarioEnArchivo() /// Adaptada.
{
    stUsuario newuser = crearUnUsuario();
    guardarUsuario(newuser);
}

void guardarUsuario(stUsuario newuser){ /// Adaptada.
    FILE * pArchUsuarios = fopen(arUsuarios,"a+b");
    if(pArchUsuarios){
        fwrite(&newuser, sizeof(stUsuario),1,pArchUsuarios);
        fclose(pArchUsuarios);
    }
}


void mostrarUnUsuario(stUsuario newuser)
{
    if(newuser.activo == 1){
        printf("\n ID: %d", newuser.idUsuario);
        printf("\n Activo: %d", newuser.activo);
        printf("\n Tipo: %d", newuser.tipo);
        printf("\n Nombre: %s", newuser.nombreUsuario);
        printf("\n Password: %s", newuser.pass);
        //printf("\n Año: ",newuser.anioNacimiento);
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

void mostrarArchivoUsuarios()
{
    FILE *archi;
    archi = fopen("arUsuarios.dat", "r+b");
    stUsuario usuaAux;
    if(archi != NULL)
    {
        while(fread(&usuaAux, sizeof(stUsuario),1,archi) > 0)
        {
            if(usuaAux.activo == 1)
            {
                mostrarUnUsuario(usuaAux);
            }
        }
        fclose(archi);
    }
}

void mostrarUsuariosAdministradores(char archivoUsuarios[])
{
    FILE *archi;
    archi = fopen(archivoUsuarios, "rb");
    stUsuario usuaAux;

    if(archi != NULL)
    {
        while(fread(&usuaAux, sizeof(stUsuario),1,archi)>0)
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
    FILE * pArchi = fopen(archivo, "rb");
    stUsuario usuaAux;
    if(pArchi){
        fseek(pArchi,0,SEEK_END);
        int bytes = ftell(pArchi);
        mayor = bytes / sizeof(stUsuario);
    }

    return mayor;
}

int checkExisteUsuarioId(int idBuscado, char archivoUsuarios[])
{
    stUsuario usua;
    int flag = -1; /// -1 error no abrio archivo, 0 no encontro ID, 1 encontro ID
    FILE *pArch = fopen(archivoUsuarios, "rb");

    if(pArch)
    {
        while(fread(&usua, sizeof(stUsuario), 1, pArch) > 0)
        {
            if((usua.idUsuario == idBuscado) && (usua.activo == 1))
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

int checkExisteUsuarioNombre(char nombreBuscado[], char archivoUsuarios[])
{
    stUsuario user;
    int flag = -1; /// -1 error no abrio archivo, 0 no encontro ID, 1 encontro ID
    FILE *pArch;
    pArch = fopen(archivoUsuarios, "rb");

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

int checkTipoUsuarioById(int usuaId, char archivoUsuarios[])
{

    Usuario usua;
    int flag = -1; /// -1 error no abrio archivo, 0 no es admin, 1 es admin
    FILE *pArch;
    pArch = fopen(archivoUsuarios, "rb");
    if(usuaId <= getUltimoIdUsuario(archivoUsuarios))
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

stUsuario getUsuarioById(int idBuscado, char archivoUsuarios[])
{
    stUsuario usua;
    int flag = 0;
    char stringAux[30] = "Usuario no encontrado";
    FILE *pArch;
    pArch = fopen(archivoUsuarios, "rb");

    if(idBuscado <= getUltimoIdUsuario(archivoUsuarios))
    {
        if(pArch != NULL)
        {
            while((flag == 0) && (fread(&usua, sizeof(stUsuario), 1, pArch)>0))
            {
                if(usua.idUsuario == idBuscado)
                {
                    flag = 1;
                }
            }
            if((flag == 0) || (usua.activo == 0))
            {
                usua.idUsuario = -1;
                strcpy(usua.nombreUsuario, stringAux);
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

stUsuario getUsuarioByNombre(char nombreBuscado[], char archivoUsuarios[])
{
    stUsuario usua;
    int flag = 0;
    char stringAux[30] = "Usuario no encontrado";
    FILE *pArch = fopen(archivoUsuarios, "rb");

        if(pArch != NULL)
        {
            while((flag == 0) && (fread(&usua, sizeof(stUsuario), 1, pArch)>0))
            {
                if(strcmpi(usua.nombreUsuario, nombreBuscado) == 0 && usua.activo == 1)
                {
                    flag = 1;
                }
            }
            if((flag == 0) || (usua.activo == 0))
            {
                usua.idUsuario = -1;
                strcpy(usua.nombreUsuario, stringAux);
            }

            fclose(pArch);
        }
   return usua;
}


int eliminarUsuarioById(int usuaId)
{
    stUsuario usua;
    int flag = 0;
    FILE *pArch;
    pArch = fopen(arUsuarios, "r+b");

    if(pArch != NULL)
    {
        while((flag == 0) && (fread(&usua, sizeof(stUsuario), 1, pArch)>0))
        {
            if(usua.idUsuario == usuaId)
            {
                if(usua.activo == 1)
                {
                    flag = 1;
                }
            }
        }
    usua.activo = 0;
    fseek(pArch, sizeof(stUsuario)*(-1), SEEK_CUR);
    fwrite(&usua, sizeof(stUsuario), 1, pArch);
    fclose(pArch);
    }
   return flag;
}

void eliminarMiUsuario(stUsuario usuaLogueado)
{
    stUsuario usua;
    int flag = -1;
    char opcion;
    system("cls");
    printf("\n\t\t<<<<<<<<<ELIMINACION DE USUARIO>>>>>>>>>");
    printf("\n\n\t\tESTA SEGURO DE ELIMINAR SU USUARIO ?? S/N \n");
    fflush(stdin);
    scanf("%c", &opcion);
    if((tolower(opcion)=='s'))
    {
        printf("\nMI USUARIO:");
        mostrarUnUsuario(usuaLogueado);
        printf("\nPresione una tecla para confirmar ");
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
            menuLogin();
        }else
        {

            system("cls");
            printf("\a");
            gotoxy(15,5);
            printf("\nNo se pudo completar la operacion.");
            getch();
            gotoxy(0,0);
            system("cls");
            menuLogin();
        }
    }else{
        printf("\nEliminacion de usuario cancelada.");
        printf("\nPresiona una tecla para volver al menu anterior");
        getch();
        menuPrincipal(usuaLogueado);
    }
}


void eliminacionDeUsuario(stUsuario usuaLogueado)
{
    stUsuario usua; //Funcion sin adaptar, @TODO@
    int flag = -1;
    FILE *pArch;
    char opcion;
    char nombreUsua[30];
    system("cls");
    printf("\n\t\t<<<<<<<<<ELIMINACION DE USUARIO>>>>>>>>>");
    printf("Introduzca el nombre del usuario que desea eliminar");
    fflush(stdin);
    gets(nombreUsua);
    usua = getUsuarioByNombre(nombreUsua, arUsuarios);

    printf("\n\n\t\tESTA SEGURO DE ELIMINAR EL SIGUIENTE USUARIO ?? S/N \n");
    mostrarUnUsuario(usua);
    fflush(stdin);
    scanf("%c", &opcion);
    if((opcion == 'S') || (opcion == 's'))
    {
        flag = eliminarUsuarioById(usua.idUsuario);
        if(flag == 1)
        {
            system("cls");
            printf("\a");
            gotoxy(15,5);
            printf("\nEliminacion exitosa.");
            getch();
            gotoxy(0,0);
            system("cls");
            menuLogin();
        }else
        {

            system("cls");
            printf("\a");
            gotoxy(15,5);
            printf("\nNo se pudo completar la operacion.");
            getch();
            gotoxy(0,0);
            system("cls");
            menuLogin();
        }
    }else
    {
//        menuGestionUsuarios(usuaLogueado);
    }

}

void modificarPassword(stUsuario usuaLogueado, char newPass[30])
{
    stUsuario usuaAux;
    int flag = 0;
    FILE *pArch= fopen(arUsuarios, "r+b");
    if(pArch != NULL)
    {
        while((flag != 1) && (fread(&usuaAux, sizeof(stUsuario), 1, pArch) > 0))
        {
            if(usuaAux.idUsuario == usuaLogueado.idUsuario)
            {
                flag = 1;
            }
        }
    strcpy(usuaLogueado.pass, newPass);
    fseek(pArch,sizeof(stUsuario) * (-1), SEEK_CUR);
    fwrite(&usuaLogueado,sizeof(stUsuario), 1, pArch);
    fclose(pArch);
    }

}


void menuModificarPassword(stUsuario usuaLogueado)
{
    char newPass[30];
    char newPassAux[30];
    char passActual[30];
    int valido = 0;

    while(valido != 1)
    {

        while(valido != 1)
        {
            system("cls");
            printf("\n\t\t<<<<<<<<<<Modificacion de Password>>>>>>>>>>>");
            printf("\nIngrese su password actual......:   ");
            fflush(stdin);
            scanf("%s", passActual);
            if(strcmp(strlwr(passActual),strlwr(usuaLogueado.pass)) != 0)
            {
                system("cls");
                printf("\a");
                gotoxy(15,5);
                printf("Ese no es su password !!");
                getch();
                gotoxy(0,0);
                menuGestionMiUsuario(usuaLogueado);
            }else
            {
                valido = 1;
            }
        }
        valido = 0;
        printf("\nIngrese su nuevo password........:   ");
        fflush(stdin);
        scanf("%s", newPass);

        if(strcmp(strlwr(newPass),strlwr(usuaLogueado.pass)) == 0)
        {
            system("cls");
            printf("\a");
            gotoxy(15,5);
            printf("No puede ingresar la misma clave que tenia !! Grow up a little !");
            getch();
            gotoxy(0,0);
            menuGestionMiUsuario(usuaLogueado);
        }

        printf("Repita su nuevo password...........:   ");
        scanf("%s", newPassAux);
        if(strcmp(strlwr(newPass), strlwr(newPassAux)) == 0)
        {
            valido = 1;

            modificarPassword(usuaLogueado, newPass);

            system("cls");
            printf("\a");
            gotoxy(15,5);
            printf("SU CONTRASEÑA HA SIDO CAMBIADA ! :)");
            getch();
            gotoxy(0,0);
            system("cls");
        }else
        {
            system("cls");
            printf("\a");
            gotoxy(15,5);
            printf("DATOS INCORRECTOS !");
            getch();
            gotoxy(0,0);
            system("cls");
        }
    }
    menuLogin();
}
