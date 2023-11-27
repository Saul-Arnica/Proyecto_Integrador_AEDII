#ifndef FIN_DE_PROGRAMA 
#define FIN_DE_PROGRAMA

#include"inicioDePrograma.h"

//Interfaz Publica
void visualizarUsuarios(FILE**, const char*);
void eliminarUsuario(tr_UsuarioInfo**);
tr_UsuarioInfo registrarUsuario();


//interfaz privada

void visualizarUsuarios(FILE **archivo, const char *nombreArchivo) {

    tr_UsuarioInfo usuario;
    *archivo = fopen(nombreArchivo, "r+b");
    fread(&usuario, sizeof(tr_UsuarioInfo), 1, *archivo);
    printf("\nLos usuarios registrados son:\n");
    printf("| %-13s | %-20s | %-9s |\n", "COD USUARIO", "NOMBRE USUARIO", "PASSWORD");
    while(!feof(*archivo)) {
        printf("| %-14d| %-20s | %-8s |\n", usuario.ID, usuario.nombre, usuario.contra);
        fread(&usuario, sizeof(tr_UsuarioInfo), 1, *archivo);
    }

    fclose(*archivo);
}

void eliminarUsuario(tr_UsuarioInfo **pUsuario) {
    FILE *archivoUsuarios;
    FILE *archivoTemporal;
    tr_UsuarioInfo usuario;    

    archivoUsuarios = fopen("archivoUsuarios.dat", "r+b");
    if(archivoUsuarios == NULL) {
        printf("No se pudo abrir el archivo.\n");
    }
    archivoTemporal = fopen("archivoSinImportancia.dat", "w+b");
    if(archivoUsuarios == NULL) {
        printf("No se pudo abrir el archivo.\n");
    }

    fread(&usuario, sizeof(tr_UsuarioInfo), 1, archivoUsuarios);
    while (!feof(archivoUsuarios)) {
        if((*pUsuario)->ID != usuario.ID) {
            fwrite(&usuario, sizeof(tr_UsuarioInfo), 1, archivoTemporal);
        }
        fread(&usuario, sizeof(tr_UsuarioInfo), 1, archivoUsuarios);
    }

    fclose(archivoUsuarios);
    fclose(archivoTemporal);

    archivoTemporal = fopen("archivoSinImportancia.dat", "r+b");
    if(archivoUsuarios == NULL) {
        printf("No se pudo abrir el archivo.\n");
    }
    archivoUsuarios = fopen("archivoUsuarios.dat", "w+b");
    if (archivoUsuarios == NULL) {
        printf("El archivo no pudo ser sobreescrito!\n");
        fclose(archivoTemporal); // Cerrar el archivo temporal si no se puede reescribir el original
    }
    fread(&usuario, sizeof(tr_UsuarioInfo), 1, archivoTemporal);
    
    while(!feof(archivoTemporal)) {

        fwrite(&usuario, sizeof(tr_UsuarioInfo), 1, archivoUsuarios);

        fread(&usuario, sizeof(tr_UsuarioInfo), 1, archivoTemporal);
    }

    fclose(archivoUsuarios);
    fclose(archivoTemporal);

    printf("El usuario con ID %d fue eliminado exitosamente\n", (*pUsuario)->ID);

    if(remove("archivoSinImportancia.dat") != 0) {
        clearerr(archivoTemporal);
    }
}


tr_UsuarioInfo registrarUsuario() {
    tr_UsuarioInfo usuario;
    printf("Ingrese su Nro de ID Unico:");
    scanf("%d", &usuario.ID);
    printf("Ingrese su nombre de usuario:");
    fflush(stdin);
    scanf("%[^\n]s", &usuario.nombre);
    printf("Ingrese su contrasena:");
    fflush(stdin);
    scanf("%[^\n]s", &usuario.contra);
    printf("Ingrese su rol(1-Administrador | 2-Empleado):");
    scanf("%d", &usuario.rol);
    return usuario;
}


#endif