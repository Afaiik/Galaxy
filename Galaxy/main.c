#include <stdio.h>
#include <stdlib.h>
#include "Listas.h"



//Menu de acceso al sistema donde te registras o logueas
void menuLogin();
void showTituloBienvenido();


int main()
{
    printf("Hello world!\n");
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
                crearUnUsuario();
                break;

            case 50:
                opcionValida = 1;
                //doLogin();
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
