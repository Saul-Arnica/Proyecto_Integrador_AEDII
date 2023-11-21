#ifndef INICIO_PROGRAMA
#define INICIO_PROGRAMA
#include"listasDoblementeEnlazadas.h"



//Interfaz Publica

void inicializarListas(t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, t_ListaProducto**);
void inicializarArchivos(FILE**, FILE**, FILE**, FILE**);
void cargarDesdeArchivo(t_ListaProducto**, const char*);
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

void inicializarArchivos(FILE **archivo1, FILE **archivo2, FILE **archivo3, FILE **archivo4) {

    *archivo1 = fopen("alimentosBackup", "w+b");
    if (*archivo1 == NULL) {
        printf("Error al abrir el archivo alimentosBackup\n");
        exit(EXIT_FAILURE);
    }

    *archivo2 = fopen("bebidasBackup", "w+b");
    if (*archivo2 == NULL) {
        printf("Error al abrir el archivo alimentosBackup\n");
        exit(EXIT_FAILURE);
    }

    *archivo3 = fopen("higieneBackup", "w+b");
    if (*archivo3 == NULL) {
        printf("Error al abrir el archivo alimentosBackup\n");
        exit(EXIT_FAILURE);
    }

    *archivo4 = fopen("limpiezaBackup", "w+b");
    if (*archivo4 == NULL) {
        printf("Error al abrir el archivo alimentosBackup\n");
        exit(EXIT_FAILURE);
    }

    fclose(*archivo1);
    fclose(*archivo2);
    fclose(*archivo3);
    fclose(*archivo4);

}

void cargarDesdeArchivo(t_ListaProducto **v_Lista, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL) {
        printf("Se pudo abrir el archivo.\n");
    }else{
        printf("Se pudo abrir el archivo.\n");
    }

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

bool archivoExiste(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL){
        fclose(archivo);
        return true;
    }else{
        return false;
    }
}

#endif