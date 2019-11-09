#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "Listas.h"

#define arUsuarios "arUsuarios.dat"

//Menu de acceso al sistema donde te registras o logueas
void menuLogin();
void showTituloBienvenido();
void doLogin();

int main()
{
    //system("color f0");
    srand(time(NULL));
    hidecursor(0);
    //printMarcianito();
    menuLogin();
    return 0;
}

void showTituloBienvenido(){
    ///color(10);
    printf("\n########  #### ######## ##    ## ##     ## ######## ##    ## #### ########   #######  \n##     ##  ##  ##       ###   ## ##     ## ##       ###   ##  ##  ##     ## ##     ## \n##     ##  ##  ##       ####  ## ##     ## ##       ####  ##  ##  ##     ## ##     ## \n########   ##  ######   ## ## ## ##     ## ######   ## ## ##  ##  ##     ## ##     ## \n##     ##  ##  ##       ##  ####  ##   ##  ##       ##  ####  ##  ##     ## ##     ## \n##     ##  ##  ##       ##   ###   ## ##   ##       ##   ###  ##  ##     ## ##     ## \n########  #### ######## ##    ##    ###    ######## ##    ## #### ########   #######  \n");

}

void menuLogin()
{
    int opcion;
    int opcionValida = 0;
    system("cls");
    showTituloBienvenido();
    printf("\n");
    printf("\n\t1- Crear Usuario");
    printf("\n\t2- Loguearse\n\t");

    opcion = getch();
    printf("\n %d", opcion);
    while(opcionValida != 1)
    {
        switch(opcion) {

            case 49:
                opcionValida = 1;
                crearUnUsuarioEnArchivo();
                system("cls");
                gotoxy(30,10);
                //color(10);
                printf("-.CREACION OK.-");
                getch();
                gotoxy(0,0);
                system("cls");
                menuLogin();
                break;

            case 50:
                opcionValida = 1;
                doLogin();
                break;

            default:
                system("cls");
                gotoxy(30,10);
                //color(4);
                printf("OPCION INVALIDA");
                getch();
                gotoxy(0,0);
                system("cls");
                menuLogin();
                break;
        }
    }
}


void doLogin()
{
    stUsuario usua;
    char nombreUsua[30];
    char pass[30];
    int existe;
    int login = 0;
    while(login == 0)
    {
        system("cls");
        showTituloBienvenido();
        printf("\n\t\tNombre de usuario.......: ");
        fflush(stdin);
        scanf("%s", nombreUsua);
        printf("\n\t\tPassword................: ");
        fflush(stdin);
        scanf("%s", pass);
        existe = checkExisteUsuarioNombre(nombreUsua, arUsuarios);
        if(existe == 1)
        {
            usua = getUsuarioByNombre(nombreUsua, arUsuarios);
            if(usua.idUsuario != -1)
            {
                if(strcmp(strlwr(usua.pass), strlwr(pass)) == 0)
                {
                    login = 1;
                }
            }
        }
        if(login != 1)
        {
            system("cls");
            printf("\a");
            gotoxy(30,10);
            //color(4);
            printf("DATOS INCORRECTOS");
            getch();
            gotoxy(0,0);
            system("cls");
            menuLogin();
        }else
        {
            system("cls");
            gotoxy(30,10);
            //color(10);
            printf("-.LOGIN OK.-");
            getch();
            gotoxy(0,0);
            system("cls");
            menuPrincipal(usua);
        }
    }
}

void showTituloPrincipal(){
    printf("\n########  #### ######## ##    ## ##     ## ######## ##    ## #### ########   #######  \n##     ##  ##  ##       ###   ## ##     ## ##       ###   ##  ##  ##     ## ##     ## \n##     ##  ##  ##       ####  ## ##     ## ##       ####  ##  ##  ##     ## ##     ## \n########   ##  ######   ## ## ## ##     ## ######   ## ## ##  ##  ##     ## ##     ## \n##     ##  ##  ##       ##  ####  ##   ##  ##       ##  ####  ##  ##     ## ##     ## \n##     ##  ##  ##       ##   ###   ## ##   ##       ##   ###  ##  ##     ## ##     ## \n########  #### ######## ##    ##    ###    ######## ##    ## #### ########   #######  \n");
}

void printMarcianito(){

printf("              .,,,,,.                            .,,,,,.              \n");
printf("              ;xkkkd,                            ;xkkkx;              \n");
printf("              ;xkkkx;                            ;xkkkx;              \n");
printf("              .;;;;:c::::,.                .,::::c:;;;;.              \n");
printf("                   .lkkkko.                .okkkkc.                   \n");
printf("                   .lkkxko'                'okkkxl.                   \n");
printf("              'cllloxkkkkxolllllllllllllllloxkkkkdllllc'              \n");
printf("              ;xkkkkkkkkkkkxkkkkkkkkkkkkkkkkkkkkkkkkkkx;              \n");
printf("          ....:xkkkkxxxxxxkkkkkkkkkkkkkkkkkxxxxxxxkkkkx:....          \n");
printf("        .cooooxxkkkxc'...;dkkkkkkkkkkkkkxkkd;...'cxkkkxdooooc.        \n");
printf("        'dkkkkkkkkkx;    'dkkkkkkkkkkkkkkkko.    ;xkkkkxkkkko.        \n");
printf("   .....;dkkkkkkkxkx:....;dkkkkkkkkkkkkkkkkd;....cxkkxkkkkkkd;.....   \n");
printf("  .cxxxxxxkkkkkkxkkkxxxxxxkkkkkkkkkkkkkkkkkxxxxxxxkkkkkkkkkkkxdxxx:.  \n");
printf("  .lkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkc.  \n");
printf("  .lkkkkxolllldxkkkkkxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkxdlllloxkkkkc.  \n");
printf("  .lkkkko'   .:xkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkx;.   'okkkkc.  \n");
printf("  .lkkkko.    ;xkkkxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkx;    .okkkkc.  \n");
printf("  .lkkkko.    ;xkkkxo::::::::::::::::::::::::::::oxkkkx;    .okkkkc.  \n");
printf("  .lkkkko.    ;xkkkx;                            ;xkkkx;    .okkkkc.  \n");
printf("  .lkkkko.    ;xkkkx;                            ;xkkkx;    .okkkkc.  \n");
printf("   .,,,,'     .,,,,;ccccccccccc,      ,ccccccccccc;,,,,.    .',,,,.   \n");
printf("                   .lkkkkkkkkkkc.    .ckkkkkkkkkkc.                   \n");
printf("                   .cxxxxxxxxxx:.    .cxxxxxxxxxxc.                   \n");
printf("                    ..''''''''..      ..''''..''..                    \n");
printf("                                                                      \n");
printf("\n");

}

void menuPrincipal(stUsuario usuaLogueado){
    int opcion;
    int opcionValida = 0;
    system("cls");
    showTituloPrincipal();
    printf("\n");
    printf("\n\t1- JUGAR");
    printf("\n\t2- Instrucciones");
    printf("\n\t3- Gestionar mi usuario");
    printf("\n\t4- Mostrar Estadisticas");
    if(usuaLogueado.tipo == 1){
        printf("\n\t5- Administrar sistema");
    }

    opcion = getch();
    while(opcionValida != 1)
    {
        switch(opcion) {

            case 49:
                opcionValida = 1;
                int score = 0;
                runGalaxy(usuaLogueado);
                printf("\n\t\tSu Score Fue %d", score);
                getch();
                menuPrincipal(usuaLogueado);
                break;

            case 50:
                opcionValida = 1;
                menuInstrucciones(usuaLogueado);
                break;

            case 51:
                opcionValida = 1;
                menuGestionMiUsuario(usuaLogueado);
                break;

            case 52:
                opcionValida = 1;
                menuEstadisticas(usuaLogueado);
                break;

            case 53:
                if(usuaLogueado.tipo == 1){
                    opcionValida = 1;
                    menuAdministracion(usuaLogueado);
                    break;
                }///Sin else no hay break por lo tanto va a default

            default:
                system("cls");
                gotoxy(30,10);
                //color(4);
                printf("OPCION INVALIDA");
                getch();
                gotoxy(0,0);
                system("cls");
                menuPrincipal(usuaLogueado);
                break;
        }
    }
}



void imprimirBienvenidaJuego(){
    system("cls");
    system("color 0f");
    printf("\n \n     Bienvenido ! \n \n \n \n");
    Sleep(1000);
    printf("  Si perdes la UTN explota. \n \n \n \n");
    printf("\n \n \n \n \tMala suerte :)");
    getch();
}

int runGalaxy(stUsuario usuaLogueado){


    int alto = 27;
    int largo = 60;
    int x, y;
    char mapa[alto][largo];
    char nave = 'W';
    char proyectil = '*';
    char enemigo = '1';
    char enemigoFuerte = '2';
    char enemigoLaser = '|';
    char explosion = 'X';
    int puntaje = 0;
    int victoria = 1;
    int laserListo = 1;

    imprimirBienvenidaJuego();

    ///Utilizamos el total de enemigos como contador
    int cantEnemigos = 0;
    ///Por cada lugar del ancho
    for (x = 0; x < largo; x ++) {
            ///Y por cada posicion del alto
        for (y = 0; y < alto; y ++) {
            ///Si es posicion impar de alto
            if ((y % 2 != 0) && (y < 7 && x > 4)
                ///Y si es posicion par de largo y dejamos 5 lugares de espacio
            && x < largo - 7 && x % 2 ==0) {
                mapa[y][x] = enemigo;
                cantEnemigos ++;
            }
            ///Si es posicion impar de alto y dejamos espacios
            else if ((y % 2 != 0) && y >= 7 && y < 9 && x > 4
                     ///Si es posicion par de X y menos el espacio
            && x < largo - 7 && x % 2 ==0){
                mapa[y][x] = enemigoFuerte;
                cantEnemigos = cantEnemigos + 2;
            }
            else {
                mapa[y][x] = ' ';
            }
        }
    }
    ///Ubicamos al jugador al fondo y al medio
    mapa[alto - 1][largo / 2] = nave;


    int i = 1;
    ///Se define como char el movimiento hacia un lado y otro
    char direccion = 'l';
    ///Variable donde se almacenara la tecla presionada
    char keyPress;
    ///inicializar variable de enemigos actuales
    int enemigosActuales = cantEnemigos;

    while((enemigosActuales > 0) && victoria) {

        int velocidad = 1 + 10 * enemigosActuales / cantEnemigos;
        //laser ???;

        ///Imprimir Mapa
        system("cls");
        printf("\tPUNTAJE.............: %d", puntaje);
        printf("\n");

        ///Variable y definida al principio
        for (y = 0; y < alto; y ++) {
        printf("|");
            for (x = 0; x < largo; x ++) {
                printf("%c",mapa[y][x]);
            }
        printf("|");
        printf("\n");
        }


    Sleep(100);
    }
    system("color f0");
    return puntaje;
}

void menuInstrucciones(stUsuario usuaLogueado){
    printf("\nMENU INSTRUCCIONES");
    enDesarrollo(usuaLogueado);
}

void menuGestionMiUsuario(stUsuario usuaLogueado){
    printf("\nMENU MI USUARIO");
    enDesarrollo(usuaLogueado);
}

void menuEstadisticas(stUsuario usuaLogueado){
    printf("\nMENU ESTADISTICAS");
    enDesarrollo(usuaLogueado);
}

void menuAdministracion(stUsuario usuaLogueado){
    printf("\nMENU ADMINISTRACION");
    enDesarrollo(usuaLogueado);
}

void enDesarrollo(stUsuario usuaLogueado){
    puts("\n\t\t\tFuncion En Desarrollo :( ");
    getch();
    menuPrincipal(usuaLogueado);
}
