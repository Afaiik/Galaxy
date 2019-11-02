#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED

typedef struct
{
    int Id;
    int Tipo;
    int Activo;
    char Nombre[30];
    char Contra[30];
}Usuario;

typedef struct
{
    int idUsuario;
    int tipo; // 1 o 0 si es admin o no
    char nombreUsuario[30];
    char pass[20];
    int anioNacimiento;
    char genero; 
    char pais[20];
    int activo;   // 1 o 0 si esta activo
} stUsuario;

///Crea usuarios en loop
void cargaArchivoUsuarios();

///Crear un usuario
stUsuario crearUnUsuario();

///Crear un usuario en archivo
void crearUnUsuarioEnArchivo();

///Guarda un usuario (Usada por cargaArchivoUsuarios)
void guardarUsuario(Usuario usua);

///Muestra un usuario
void mostrarUnUsuario(Usuario usua);

///Mostrar un archivo de usuarios (usa MostrarUnUsuario)
void mostrarArchivoUsuarios(char arUsuarios[]);
///Mostrar Administradores
void mostrarUsuariosAdministradores(char arUsuarios[]);

///Muestra un arreglo de usuarios (usa MostrarUnUsuario)
void mostrarArregloUsuarios(Usuario usua[], int val);

///Busca el mayor ID dentro de los usuarios
int getUltimoIdUsuario(char archivo[]);

///Busca si existe un ID indicado, devuelve 1 o 0
int checkExisteUsuarioId(int idBuscado, char arUsuarios[]);
///IDEM pero busca por nombre
int checkExisteUsuarioNombre(char nombreBuscado[], char arUsuarios[]);

///Busca un usuario por ID y checkea si es ADMIN, devuelve -1 error no abrio archivo, 0 no es admin, 1 es admin
int checkTipoUsuarioById(int usuaId, char arUsuarios[]);

///Devuelve el usuario buscado por ID
Usuario getUsuarioById(int idBuscado, char arUsuarios[]);
///IDEM pero busca por nombre
Usuario getUsuarioByNombre(char nombreBuscado[], char arUsuarios[]);

///Baja Logica de usuario buscandolo por ID (Activo = 0)
int eliminarUsuarioById(int usuaId);
///Interfaz de eliminacion de usuario
void eliminacionDeUsuario(Usuario usuaLogueado);
///Eliminacion del propio usuario
void eliminarMiUsuario(Usuario usuaLogueado);


#endif // USUARIOS_H_INCLUDED
