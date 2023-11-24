#ifndef FIN_DE_PROGRAMA 
#define FIN_DE_PROGRAMA

#include"inicioDePrograma.h"

//Interfaz Publica

void eliminarUsuario(int idUsuario);
tr_UsuarioInfo registrarUsuario();


//interfaz privada

void eliminarUsuario(int pIdUsuario) {

    tr_UsuarioInfo usuario;

    FILE *archivoOriginal, *archivoTemporal;

    //Abrimos el archivo original para "clonar"
    archivoOriginal = fopen("archivoUsuarios", "rb");
    if(archivoOriginal == NULL) {
        printf("El archivo no pudo ser encontrado o abierto!\n");
    }

    //Creamos un nuevo archivo clonado del orignal 
    archivoTemporal = fopen("archivoTemporal", "wb");
    if(archivoTemporal == NULL) {
        printf("El archivo no pudo ser encontrado o abierto!\n");
    }

    fread(&usuario, sizeof(tr_UsuarioInfo), 1, archivoOriginal);

    while(!feof(archivoOriginal)) {
//Si el usuario leido tiene un ID diferente al que queremos eliminar, lo clonamos como esta, sino, no lo clonamos (ahi eliminamos el usuario registrado)
        if(pIdUsuario != usuario.ID) {
            fwrite(&usuario,sizeof(tr_UsuarioInfo), 1, archivoTemporal);
        }

        fread(&usuario, sizeof(tr_UsuarioInfo), 1, archivoOriginal);
    }
    
    //Una vez terminada la "clonacion" del archivo original pasamos al 2do paso.
        //Cerramos los archivos
        fclose(archivoOriginal);
        fclose(archivoTemporal);
            //Una vez cerrado los archivos procedemos a eliminar el orginal.(El 3er paso)
            remove("archivoUsuarios");
                //Una vez eliminado el original el temporal, lo renombramos para convertirlo en el orginal.(4to paso)
                rename("archivoTemporal", "archivoUsuarios");
                    //Una vez terminado el proceso identificamos al usuario eliminado por el ID.(5to y ultimo paso)
                    printf("El usuario %d fue eliminado exitosamente\n", pIdUsuario);
}

tr_UsuarioInfo registrarUsuario() {
    tr_UsuarioInfo usuario;
    printf("Ingrese su N° ID Unico:");
    scanf("%d", &usuario.ID);
    printf("Ingrese su nombre de usuario:");
    fflush(stdin);
    scanf("%[^\n]s", &usuario.nombre);
    printf("Ingrese su contrasena:");
    fflush(stdin);
    scanf("%[^\n]s", &usuario.contraseña);
    printf("Ingrese su rol(1-Administrador | 2-Empleado):");
    scanf("%d", &usuario.rol);
    return usuario;
}


#endif