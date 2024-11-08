#ifndef INICIO_PROGRAMA
#define INICIO_PROGRAMA

#include"operacionesBasicas.h"

//Interfaz Publica


void inicializarListas(t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, t_ListaProducto**);

void inicializarArchivo(FILE**, const char*);

void cargarDesdeArchivo(t_ListaProducto**, const char*);

tr_UsuarioInfo *ingresarUsuario();

int verificarUsuarios(FILE**, const char*, tr_UsuarioInfo**);

bool archivoExiste(const char*);

//Interfaz Privada

void inicializarListas(t_ListaProducto **v_Lista1, t_ListaProducto **v_Lista2, 
                        t_ListaProducto **v_Lista3, t_ListaProducto **v_Lista4) {

    inicializarLista(&(*v_Lista1));
    if(*v_Lista1 != NULL) {
        printf("No se pudo inicializar\n");
    }
    inicializarLista(&(*v_Lista2));
    if(*v_Lista2 != NULL) {
        printf("No se pudo inicializar\n");
    }
    inicializarLista(&(*v_Lista3));
    if(*v_Lista3 != NULL) {
        printf("No se pudo inicializar\n");
    }
    inicializarLista(&(*v_Lista4));
    if(*v_Lista4 != NULL) {
        printf("No se pudo inicializar\n");
    }

}

void inicializarArchivo(FILE **archivo, const char *pNombreArchivo) {

    *archivo = fopen(pNombreArchivo, "w+b");
    if (*archivo == NULL) {
        printf("Error al abrir el archivo!!\n");
        exit(EXIT_FAILURE);
    }

    fclose(*archivo);
}

void cargarDesdeArchivo(t_ListaProducto **v_Lista, const char *nombreArchivo) {

    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+b");
    if(archivo != NULL) {
        printf("Se pudo abrir el archivo.\n"); //no es optimo.
    }else{
        printf("No se pudo abrir el archivo.\n");
    }
    printf("\033[H\033[J");


    t_ListaProducto *nuevoProducto;
    tr_Productos productoLeido;
    fread(&productoLeido, sizeof(tr_Productos), 1, archivo);

    while(!feof(archivo)) {
        nuevoProducto = (t_ListaProducto*)malloc(sizeof(t_ListaProducto));
        nuevoProducto->producto = productoLeido;
        nuevoProducto->sig = NULL;
        nuevoProducto->ant = NULL;

        if(*v_Lista == NULL) {
            *v_Lista = nuevoProducto;
        } else {
            t_ListaProducto *aux = *v_Lista;

            while(aux->sig != NULL) {
                aux = aux->sig;
            }

            aux->sig = nuevoProducto;
            nuevoProducto->ant = aux;
        }

        fread(&productoLeido, sizeof(tr_Productos), 1, archivo);
    }

    fclose(archivo);
}

int verificarUsuarios(FILE **archivoUsuarios, const char *nombreArchivo , tr_UsuarioInfo **pUsuarioIngresado) {

    bool flag = false;

    tr_UsuarioInfo usuarioRegistro;

    *archivoUsuarios = fopen(nombreArchivo, "r+b");

    if (*archivoUsuarios == NULL) {
        printf("Error al abrir el archivo!!\n");
        exit(EXIT_FAILURE);
    }

    fread(&usuarioRegistro, sizeof(tr_UsuarioInfo), 1, *archivoUsuarios);

    while(!feof(*archivoUsuarios)) {

        if(strcmp(usuarioRegistro.nombre, (*pUsuarioIngresado)->nombre) == 0 
                    && strcmp(usuarioRegistro.contra, (*pUsuarioIngresado)->contra) == 0 && usuarioRegistro.rol == 1) {
            
            flag = true;
            **pUsuarioIngresado = usuarioRegistro;
            return 1;

        }else if(strcmp(usuarioRegistro.nombre, (*pUsuarioIngresado)->nombre) == 0 
                    && strcmp(usuarioRegistro.contra, (*pUsuarioIngresado)->contra) == 0 && usuarioRegistro.rol == 2) {
            
            flag = true;
            **pUsuarioIngresado = usuarioRegistro;
            return 2;

        }

        fread(&usuarioRegistro, sizeof(tr_UsuarioInfo), 1, *archivoUsuarios);
    }
    if(flag == false) {
        return 0;
    }
    fclose(*archivoUsuarios);
}

tr_UsuarioInfo *ingresarUsuario() {
    tr_UsuarioInfo *usuario;
    usuario = malloc(sizeof(tr_UsuarioInfo));
    printf("\nIngrese su nombre de usuario:");
    fflush(stdin);
    scanf("%[^\n]s", &usuario->nombre);
    printf("Ingrese su contrasena:");
    fflush(stdin);
    scanf("%[^\n]s", &usuario->contra);
    return usuario;
}

bool archivoExiste(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r+b");
    if(archivo != NULL){
        fclose(archivo);
        return true;
    }else{
        return false;
    }
}

#endif
