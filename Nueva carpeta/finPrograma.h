#ifndef FIN_PROGRAMA_H
#define FIN_PROGRAMA_H

#include"operacionesBasicas.h"

//Interfaz Publica

void procesarGuardado(FILE**, FILE**, FILE**, FILE**, FILE**, t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, tr_UsuarioInfo);
void grabarLista(FILE**, t_ListaProducto*, const char *);
void grabarUsuario(FILE**, tr_UsuarioInfo, const char *);

//interfaz privada

void procesarGuardado(FILE **archivo1, FILE **archivo2, FILE **archivo3, FILE **archivo4, FILE **archivo5, 
                        t_ListaProducto **v_Lista1, t_ListaProducto **v_Lista2, t_ListaProducto **v_Lista3,
                                t_ListaProducto **v_Lista4, tr_UsuarioInfo pUsuario) {

    //Grabamos todas las listas de forma ordenada en el archivo
    grabarLista(archivo1, *v_Lista1, "stockAlimentos.dat");
    grabarLista(archivo2, *v_Lista2, "stockBebidas.dat");
    grabarLista(archivo3, *v_Lista3, "stockCuidadoPersonal.dat");
    grabarLista(archivo4, *v_Lista4, "stockLimpieza.dat");

    //Grabamos el usuario
    //grabarUsuario(archivo5, pUsuario, "archivoUsuarios");

}

void grabarLista(FILE **archivo, t_ListaProducto *v_Lista, const char *nombreArchivo) {
                    
    tr_Productos producto;
    t_ListaProducto *aux;
    aux = v_Lista;

    *archivo = fopen(nombreArchivo, "w+b");
    if(*archivo == NULL) {
        printf("No se pudo abrir el archivo para guardar!\n");
    }
    while(aux != NULL) {
        producto = aux->producto;
        fwrite(&producto, sizeof(tr_Productos), 1, *archivo);
        aux = aux->sig;
    }
    fclose(*archivo);
}

void grabarUsuario(FILE **archivoUsuarios, tr_UsuarioInfo pUsuario, const char *nombreArchivo) {

    tr_UsuarioInfo usuario;

    *archivoUsuarios = fopen(nombreArchivo, "a+b");
    if(*archivoUsuarios == NULL) {
        printf("No se pudo abrir el archivo para guardar!\n");
    }
    usuario = pUsuario;

    fwrite(&usuario, sizeof(tr_UsuarioInfo), 1, *archivoUsuarios);

    fclose(*archivoUsuarios);
}

#endif