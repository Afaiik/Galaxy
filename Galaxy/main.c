#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "arbol.h"
#include "Listas.h"

#define arUsuarios "arUsuarios.dat"
#define arLogs "arLogs.dat"

void menuLogin();
void showTituloBienvenido();
void doLogin();
void flash();
void menuPrincipal(stUsuario usuaLogueado);
void menuInstrucciones(stUsuario usuaLogueado);
void menuGestionMiUsuario(stUsuario usuaLogueado);
void menuEstadisticas(stUsuario usuaLogueado);
void menuAdministracion(stUsuario usuaLogueado);
void jugar();
int runGalaxy();
void printMarcianito();
void imprimirBienvenidaJuego();

int main()
{
    system("color f0");
    srand(time(NULL));
    hidecursor(0);
    menuLogin();

    return 0;
}

void showTituloBienvenido(){
    printf(" .d8888b.         d8888 888             d8888 Y88b   d88P Y88b   d88P \n");
    printf("d88P  Y88b       d88888 888            d88888  Y88b d88P   Y88b d88P  \n");
    printf("888    888      d88P888 888           d88P888   Y88o88P     Y88o88P   \n");
    printf("888            d88P 888 888          d88P 888    Y888P       Y888P    \n");
    printf("888  88888    d88P  888 888         d88P  888    d888b        888     \n");
    printf("888    888   d88P   888 888        d88P   888   d88888b       888     \n");
    printf("Y88b  d88P  d8888888888 888       d8888888888  d88P Y88b      888     \n");
    printf("  Y8888P88 d88P     888 88888888 d88P     888 d88P   Y88b     888     \n");
}

void menuLogin()
{
    int opcion;
    int opcionValida = 0;
    system("cls");
    showTituloBienvenido();
    printf("\n");
    printf("\n\t1- Crear Usuario");
    printf("\n\t2- Loguearse");
    printf("\n\t0- Salir");

    fflush(stdin);
    opcion = getch();
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
                fflush(stdin);
                getch();
                gotoxy(0,0);
                system("cls");
                menuLogin();
                break;

            case 50:
                opcionValida = 1;
                doLogin();
                break;

            case 48:
                opcionValida = 1;
                printf("\nGracias por usar Galaxy!\n");
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
                if(strcmpi(usua.pass,pass) == 0)
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
            fflush(stdin);
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
            fflush(stdin);
            getch();
            gotoxy(0,0);
            system("cls");
            menuPrincipal(usua);
        }
    }
}

void flash(){
    int cont = 0;
    while(cont != 30){
        if(cont % 2 == 0){
            system("color 0f");
        }else{
            system("color f0");
        }
        system("cls");
        printMarcianito();
        cont++;
    }
    system("color 0f");
}

void showTituloPrincipal(){
    printf(" .d8888b.         d8888 888             d8888 Y88b   d88P Y88b   d88P \n");
    printf("d88P  Y88b       d88888 888            d88888  Y88b d88P   Y88b d88P  \n");
    printf("888    888      d88P888 888           d88P888   Y88o88P     Y88o88P   \n");
    printf("888            d88P 888 888          d88P 888    Y888P       Y888P    \n");
    printf("888  88888    d88P  888 888         d88P  888    d888b        888     \n");
    printf("888    888   d88P   888 888        d88P   888   d88888b       888     \n");
    printf("Y88b  d88P  d8888888888 888       d8888888888  d88P Y88b      888     \n");
    printf("  Y8888P88 d88P     888 88888888 d88P     888 d88P   Y88b     888     \n");

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
    printf("\n\t0- Salir de Galaxy");
    fflush(stdin);
    opcion = getch();
    while(opcionValida != 1)
    {
        switch(opcion) {

            case 48:
                opcionValida = 1;
                printf("\nGracias por usar Galaxy, lo esperamos nuevamente!");
                break;

            case 49:
                opcionValida = 1;
                jugar(usuaLogueado);
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
                }///Sin cumplir el IF no hay break por lo tanto va a default

            default:
                system("cls");
                gotoxy(30,10);
                //color(4);
                printf("OPCION INVALIDA");
                fflush(stdin);
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
    printf("  Si perdes la UTN explota. \n \n \n \n");
    Sleep(1000);
    printf("\n \n \n \n \tBuena suerte :)");
    fflush(stdin);
    getch();
    flash();
}



int runGalaxy(){

    int alto = 27;
    int largo = 60;
    int yi, y, x;
    char mapa[alto][largo];
    char nave = 'W';
    char proyectil = '*';
    char enemigo = '1';
    char enemigoFuerte = '2';
    char enemigoLaser = '|';
    char explosion = 'X';
    int puntaje = 0;
    int victoria = 0;
    int laserListo = 1;
    int enemigoListo = 0;

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
    ///Se define como Izq o Der
    char direccion = 'I';
    ///Variable donde se almacenara la tecla presionada
    char keyPress;
    ///inicializar variable de enemigos actuales
    int enemigosActuales = cantEnemigos;

    while((enemigosActuales > 0) && (victoria == 0)) {
        int moverEnemigo = 0;
        int velocidad = 1 + 10 * enemigosActuales / cantEnemigos;
        laserListo++;

        ///Imprimir Mapa
        system("cls");
        printf("\tPUNTAJE.............: %d", puntaje);
        printf("\n");

        ///Variable y definida al principio
        for (y = 0; y < alto; y ++) {
        printf("|"); ///impresion de mapa
            for (x = 0; x < largo; x ++) {
                printf("%c",mapa[y][x]);
            }
        printf("|");
        printf("\n");
        }

        ///Movimiento del laser
        for (x = 0; x < largo; x ++) {
            for (y = alto-1; y >= 0; y --) {
                ///Si la posicion es par (mueve de a dos), en donde se encuentre un laser enemigo
                if (i % 2 == 0 && mapa[y][x] == enemigoLaser
                ///Si la posicion siguiente en alto no choca con nada
                && (mapa[y+1][x] != enemigo & mapa[y+1][x] != enemigoFuerte)){
                    ///Mueve el laser y borra el anterior
                    mapa[y+1][x] = enemigoLaser;
                    mapa[y][x] = ' ';
                }
                ///Sino si es posicion par, en donde se encuentre el laser enemigo
                else if (i % 2 == 0 && mapa[y][x] == enemigoLaser
                //Si el lugar siguiente es un enemigo
                && (mapa[y+1][x] == enemigo | mapa[y+1][x] == enemigoFuerte)){
                    ///Borra la posicion
                    mapa[y][x] = ' ';
                }
            }
        }

        ///Oootro ciclo para recorrer todo el mapa
        for (x = 0; x < largo; x ++) {
            for (y = 0; y < alto; y ++) {

                if ((i % 5) == 0 && (mapa[y][x] == enemigoFuerte
                ///Si encuentra un enemigo y es una posicion valida
                | mapa[y][x] == enemigo) && (rand() % 15) > 13
                ///Si en la siguiente posicion no hay colision
                && mapa[y+1][x] != proyectil) {
                    ///Recorro todo el alto
                    for (yi = y+1; yi < alto; yi ++) {
                        ///Si hay una colision
                        if (mapa[yi][x] == enemigo
                        | mapa[yi][x] == enemigoFuerte) {
                            enemigoListo = 0;
                            ///PseudoBreak para ahorrar tiempo
                            yi = alto;
                        }
                        enemigoListo = 1;
                    }
                    if (enemigoListo) {
                        mapa[y+1][x] = enemigoLaser;
                    }
                }


                /// CHECKEAR COLISIONES

                ///Si la siguiente posicion es enemigo para la proxima vuelta lo borro
                if (mapa[y][x] == proyectil && mapa[y-1][x] == enemigo) {
                    mapa[y][x] = ' ';
                    ///Corregir lugar de la fucking explosion @TODO@
                    mapa[y-1][x] = explosion;
                    enemigosActuales --;
                    puntaje += 20;
                }
                else if (mapa[y][x] == proyectil && mapa[y-1][x] == enemigoFuerte) {
                    mapa[y][x] = ' ';
                    ///mapa[y+1][x] = enemigo;
                    mapa[y-1][x] = enemigo;
                    enemigosActuales --;
                    puntaje += 20;
                }
                ///Que el laser enemigo se coma el proyectil
                else if (mapa[y][x] == enemigoLaser && mapa[y-1][x] == enemigoLaser) {
                    mapa[y][x] = ' ';
                }
                ///Borrar explosionnnnnnnn
                else if (mapa[y][x] == explosion) {
                    mapa[y][x] = ' ';
                }
                ///Si chocas un laser enemigo perdiste u.u
                else if ((i+1) % 2 == 0 && mapa[y][x] == enemigoLaser && mapa[y+1][x] == nave) {
                    mapa[y+1][x] = explosion;
                    mapa[y][x] = ' ';
                    victoria = 1;
                }
                ///Si no paso nada que avance el disparo
                else if (mapa[y][x] == proyectil && mapa[y-1][x] != enemigoLaser) {
                    mapa[y][x] = ' ';
                    mapa[y-1][x] = proyectil;
                }
            }
        }


        ///Mover enemigos
        for (y = 0; y < alto; y ++) {
            ///Si esta sobre la derecha cambian de direccion
            if (mapa[y][0] == enemigo) {
                direccion = 'D';
                moverEnemigo = 1;
                break;///cambiar los breaks @TODO@
            }
            ///Idem por izquierda
            if (mapa[y][largo-1] == enemigo){
                direccion = 'I';
                moverEnemigo = 1;
                break;
            }
        }

                                                    // Dia 373 sin dormir. Pude estabilizar el movimiento de izquierda a derecha y desaparecer las explosiones. Hola Profe!

        ///ACTUALIZAR MAPA
        if (i % velocidad == 0) {
            if (direccion == 'I') {

                for (x = 0; x < largo - 1; x ++) {
                    for (y = 0; y < alto; y ++) {

                        if (moverEnemigo && (mapa[y-1][x+1] == enemigo || mapa[y-1][x+1] == enemigoFuerte)){
                                mapa[y][x] = mapa[y-1][x+1];
                                mapa[y-1][x+1] = ' ';
                        }
                        else if (!moverEnemigo && (mapa[y][x+1] == enemigo || mapa[y][x+1] == enemigoFuerte)) {
                            mapa[y][x] = mapa[y][x+1];
                            mapa[y][x+1] = ' ';
                        }
                    }
                }
            }
            else {
                for (x = largo; x > 0; x --) {
                    for (y = 0; y < alto; y ++) {
                        ///Mismo checkeo pero para el otro costado
                        if (moverEnemigo && (mapa[y-1][x-1] == enemigo || mapa[y-1][x-1] == enemigoFuerte)) {
                            mapa[y][x] = mapa[y-1][x-1];
                            mapa[y-1][x-1] = ' ';
                        }
                        else if (!moverEnemigo && (mapa[y][x-1] == enemigo || mapa[y][x-1] == enemigoFuerte)) {
                            mapa[y][x] = mapa[y][x-1];
                            mapa[y][x-1] = ' ';
                        }
                    }
                }
            }
            for (x = 0; x < largo; x ++) {
                if (mapa[alto - 1][x] == enemigo) {
                    victoria = 0;
                }
            }
        }


        ///KeyboardHit by Conio
        ///movimiento WASD, disparo P
        if(kbhit()){
            keyPress = getch();
        }
        else {
            keyPress = ' ';
        }
        if (keyPress == 'a') {
            for (x = 0; x < largo; x = x+1) {
                if ( mapa[alto-1][x+1] == nave) {
                    mapa[alto-1][x] = nave;
                    mapa[alto-1][x+1] = ' ';
                }
            }
        }

        if (keyPress == 'd') {
            for (x = largo - 1; x > 0; x = x-1) {
                if ( mapa[alto-1][x-1] == nave) {
                    mapa[alto-1][x] = nave;
                    mapa[alto-1][x-1] = ' ';
                }
            }
        }
        if (keyPress == 'm' && laserListo > 2) {
            for (x = 0; x < largo; x = x+1) {
                if ( mapa[alto-1][x] == nave) {
                    mapa[alto - 2][x] = proyectil;
                    laserListo = 0;
                }
            }
        }
        ///I misteriosa de la muerte.
                i ++;

        ///Si no duerme no se ve la mitad de abajo del mapa
        Sleep(55);
    }

    system("cls");
    printf("     PUNTAJE:    %d", puntaje);
    printf("\n");
    for (y = 0; y < alto; y ++) {
        printf("|");
            for (x = 0; x < largo; x ++) {
                printf("%c",mapa[y][x]);
            }
        printf("|");
        printf("\n");
    }
    getch();
    system("cls");

    if (victoria == 0) {
        printf("\n \n \n \n \n \n\t\t\tFELICITACIONES");
        Sleep(500);
        printf("\n \n\n \n \n \n \n \t\tPUNTAJE: %d", puntaje);
        int bonus = puntaje * 5 - i;
        printf("\n \n\n \t\tBONUS: %d", bonus);
        printf("\n \n\n \t\tPUNTAJE TOTAL: %d", puntaje + bonus);

        Sleep(1000);
        printf("\n\n\t\tHas salvado la UTN <3");
        getch();
    }
    else {
        printf("\n \n \n \n \n \n\t\t\tPERDISTE :(");
        printf("\n \n \n \n \n \n \t\t\tLa UTN ha Explotado");
        Sleep(1000);
        printf("\n \n\t\t\tPuntaje Final: %d", puntaje);
        getch();
        Sleep(500);
    }

    system("color f0");
    return puntaje;
}

void menuInstrucciones(stUsuario usuaLogueado){
    system("cls");
    showTituloBienvenido();
    printf("\n\tINSTRUCCIONES\n");
    printf("\n\tMovimiento: WASD\n");
    printf("\n\tDisparos: Barra espaciadora\n");
    printf("\n\tSalir: ESC\n");
    printf("\n\tBuena suerte soldado!");
    printf("\nPresione una tecla para volver al menu principal");
    fflush(stdin);
    getch();
    menuPrincipal(usuaLogueado);
}

void menuGestionMiUsuario(stUsuario usuaLogueado){
    int opcion;
    int opcionValida = 0;
    system("cls");
    showTituloPrincipal();
    printf("\n");
    printf("\n\t1- Modificar mi password");
    printf("\n\t2- Eliminar mi usuario");
    printf("\n\t3- Volver al menu anterior ");

    fflush(stdin);
    opcion = getch();
    while(opcionValida != 1)
    {
        switch(opcion) {

            case 49:
                opcionValida = 1;
                menuModificarPassword(usuaLogueado);
                break;

            case 50:
                opcionValida = 1;
                eliminarMiUsuario(usuaLogueado);
                break;

            case 51:
                opcionValida = 1;
                menuPrincipal(usuaLogueado);
                break;

            default:
                system("cls");
                gotoxy(30,10);
                //color(4);
                printf("OPCION INVALIDA");
                fflush(stdin);
                getch();
                gotoxy(0,0);
                system("cls");
                menuPrincipal(usuaLogueado);
                break;
        }
    }
}

void menuAdministracion(stUsuario usuaLogueado){
    int opcion;
    int opcionValida = 0;
    system("cls");
    showTituloPrincipal();
    printf("\n");
    printf("\n\t1- Mostrar todos los usuarios");
    printf("\n\t2- Eliminar usuario por Nombre");
    printf("\n\t3- Eliminar usuario por ID");
    printf("\n\t4- Volver al menu anterior");

    ///Alguna opcion mas para el admin ?
    fflush(stdin);
    opcion = getch();
    while(opcionValida != 1)
    {
        switch(opcion) {

            case 49:
                opcionValida = 1;
                mostrarArchivoUsuarios(arUsuarios);
                getch();
                menuAdministracion(usuaLogueado);
                break;
            case 50:
                opcionValida = 1;
                eliminacionDeUsuario(usuaLogueado);
                break;
            case 51:
                opcionValida = 1;
                eliminacionDeUsuarioById(usuaLogueado);
                break;
            case 52:
                opcionValida = 1;
                menuPrincipal(usuaLogueado);
                break;

            default:
                system("cls");
                gotoxy(30,10);
                //color(4);
                printf("OPCION INVALIDA");
                fflush(stdin);
                getch();
                gotoxy(0,0);
                system("cls");
                menuPrincipal(usuaLogueado);
                break;
        }
    }
}


void menuEstadisticas(stUsuario usuaLogueado){
    int opcion;
    int opcionValida = 0;
    int dim = getUltimoIdUsuario(arUsuarios); ///Esta función cuenta la cantidad de usuarios del archivo mediante Ftell / sizeof(usuario)
    stCelda adlUsers[dim];
    int validos = 0;
    validos = usuarios2arreglo(adlUsers, validos, dim);

    system("cls");
    showTituloPrincipal();
    printf("\n");
    printf("\n\t1- Mostrar ranking global");
    printf("\n\t2- Mostrar mis score");
    printf("\n\t3- Buscar los score de un usuario");
    printf("\n\t0- Volver al menu anterior");

    fflush(stdin);
    opcion = getch();
    while(opcionValida != 1)
    {
        switch(opcion) {

            case 49:
                opcionValida = 1;
                ///ARBOL
                break;
            case 50:
                opcionValida = 1;
                int pos = buscarPosUsuario(adlUsers,validos,usuaLogueado.idUsuario);
                if(adlUsers[pos].listaDeLog){
                    mostrarListaLog(adlUsers[pos].listaDeLog);
                }else{
                    printf("\nNo tenes ningun score:(\n");
                }
                getch();
                menuPrincipal(usuaLogueado);
                break;
            case 51:
                opcionValida = 1;

                break;
            case 48:
                opcionValida = 1;
                menuPrincipal(usuaLogueado);
                break;

            default:
                system("cls");
                gotoxy(30,10);
                //color(4);
                printf("OPCION INVALIDA");
                fflush(stdin);
                getch();
                gotoxy(0,0);
                system("cls");
                menuPrincipal(usuaLogueado);
                break;
        }
    }
}


void jugar(stUsuario usuaLogueado){
    int scorePartida = runGalaxy();
    guardarLogPartida(scorePartida,usuaLogueado,arLogs);
    fflush(stdin);
    printf("\nPresione una tecla para volver al menu principal\n");
    getch();
    menuPrincipal(usuaLogueado);
}
