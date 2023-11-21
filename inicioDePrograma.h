
#include"listaDoblementeEnlazada.h"
#define MAX 10
#define REPETICIONES 5

//Interfaz Publica

void inicializarListas(t_Producto**, t_Producto**, t_Producto**, t_Producto**);
void inicializarArchivos(FILE**, FILE**, FILE**, FILE**);
void cargarDesdeArchivo(t_Producto**, const char*);
bool archivoExiste(const char*);

//Interfaz Privada

void inicializarListas(t_Producto **v_Lista1, t_Producto **v_Lista2, t_Producto **v_Lista3, t_Producto **v_Lista4) {

    inicializarLista(v_Lista1); 
    inicializarLista(v_Lista2);  
    inicializarLista(v_Lista3); 
    inicializarLista(v_Lista4);
    
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

void cargarDesdeArchivo(t_Producto **v_Lista, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL) {
        printf("Se pudo abrir el archivo.\n");
    }else{
        printf("Se pudo abrir el archivo.\n");
    }

    t_Producto *nuevoProducto;
    tr_Productos productoLeido;
    fread(&productoLeido, sizeof(tr_Productos), 1, archivo);

    while(!feof(archivo)) {
        nuevoProducto = (t_Producto*)malloc(sizeof(t_Producto));
        nuevoProducto->producto = productoLeido;
        nuevoProducto->sig = NULL;
        nuevoProducto->ant = NULL;

        if(*v_Lista == NULL) {
            *v_Lista = nuevoProducto;
        } else {
            t_Producto *aux = *v_Lista;

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

