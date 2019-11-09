#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED

typedef struct{
    int Id;
    int Tipo;
    int Activo;
    char Nombre[30];
    char Contra[30];
}Usuario;


typedef struct{
    int idUsuario;
    int tipo; // 1 o 0 si es admin o no
    char nombreUsuario[30];
    char pass[20];
    char genero;
    char pais[20];
    int activo;   // 1 o 0 si esta activo
}stUsuario;

typedef struct{
    int idUsuario; /// Id del usuario a usar.
    int idLog; /// Numero de registro.
    int puntaje; /// Puntaje del usuario.
}stLog;


/*
typedef struct
{
    stUsuario user;
    nodoPuntaje * listaDePuntajes;
}stCelda /// Para el arreglo de puntajes.
*/

///Crea usuarios en loop
void cargaArchivoUsuarios();

///Crear un usuario
stUsuario crearUnUsuario();

///Crear un usuario en archivo
void crearUnUsuarioEnArchivo();

///Guarda un usuario (Usada por cargaArchivoUsuarios)
void guardarUsuario(stUsuario newuser);

///Muestra un usuario
void mostrarUnUsuario(stUsuario newuser);

///Muestra un arreglo de usuarios (usa MostrarUnUsuario)
void mostrarArregloUsuarios(stUsuario user[], int val);

///Mostrar un archivo de usuarios (usa MostrarUnUsuario)
void mostrarArchivoUsuarios();
///Mostrar Administradores
void mostrarUsuariosAdministradores(char arUsuarios[]);

///Busca el mayor ID dentro de los usuarios
int getUltimoIdUsuario(char archivo[]);

///Busca si existe un ID indicado, devuelve 1 o 0
int checkExisteUsuarioId(int idBuscado, char arUsuarios[]);
///IDEM pero busca por nombre
int checkExisteUsuarioNombre(char nombreBuscado[], char arUsuarios[]);

///Busca un usuario por ID y checkea si es ADMIN, devuelve -1 error no abrio archivo, 0 no es admin, 1 es admin
int checkTipoUsuarioById(int usuaId, char arUsuarios[]);

///Devuelve el usuario buscado por ID
stUsuario getUsuarioById(int idBuscado, char arUsuarios[]);
///IDEM pero busca por nombre
stUsuario getUsuarioByNombre(char nombreBuscado[], char arUsuarios[]);

///Baja Logica de usuario buscandolo por ID (Activo = 0)
int eliminarUsuarioById(int usuaId);
///Interfaz de eliminacion de usuario
void eliminacionDeUsuario(stUsuario usuaLogueado);
///Eliminacion del propio usuario
void eliminarMiUsuario(stUsuario usuaLogueado);



#endif // USUARIOS_H_INCLUDED
