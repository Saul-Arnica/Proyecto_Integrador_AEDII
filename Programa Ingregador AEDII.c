#include"listaDoblementeEnlazada.h"

//Prototipado de funciones
void procesarElInicio();
void inicializarListas();
void inicializarArchivos();
bool archivoExiste(const char*);
void cargarDesdeArchivo(t_Producto**, const char*);
void modificarProducto(t_Producto**, int, tr_Productos);
tr_Productos ingresarProducto();
void imprimirTitulo();
void menu();

//Variables globales

FILE *stockAlimentos, *stockBebidas, *stockHigiene, *stockLimpeza;
int codCampAnterior;
int flag = 0;
t_Producto *alimentos, *bebidas, *cuidadoPersonal, *limpieza;

//Funcion Principal  

int main() {
    procesarElInicio();
    menu();    
return 0;
}

//Implementacion

void procesarElInicio() {
    inicializarListas();
    if(archivoExiste("alimentosBackup") && archivoExiste("bebidasBackup") && archivoExiste("higieneBackup") && archivoExiste("limpiezaBackup")) {
        cargarDesdeArchivo(&alimentos, "alimentosBackup");
        cargarDesdeArchivo(&bebidas, "bebidasBackup");
        cargarDesdeArchivo(&cuidadoPersonal, "higieneBackup");
        cargarDesdeArchivo(&limpieza, "limpiezaBackup");
    }else{
        inicializarArchivos();
    }
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

void imprimirTitulo() {
    int i, j, rep;

    for(rep = 0; rep < REPETICIONES; rep++) {
        for(i = 0; i < MAX; i++) {
            for(j = 0; j < i; j++) printf(" ");
            printf("*");
            for(j = 0; j < MAX - i; j++) printf(" ");
            printf("Bienvenidos a RetailMate lo mejor para tu comercio :D");
            for(j = 0; j < MAX - i; j++) printf(" ");
            printf("*\n");
            usleep(100000); // Espera 0.1 segundos
            printf("\033[H\033[J"); // Limpia la pantalla
        }
    }
    printf("\t*** Bienvenidos a RetailMate lo mejor para tu comercio :D ***\n");
}

void inicializarListas() {
    inicializarLista(&alimentos); 
    inicializarLista(&bebidas);  
    inicializarLista(&cuidadoPersonal); 
    inicializarLista(&limpieza);
    printf("Se inicializaron las categorias! Listas para gestionar el stock!...\n");
}

void inicializarArchivos() {
    stockAlimentos = fopen("alimentosBackup", "w+b");
    stockBebidas = fopen("bebidasBackup", "w+b");
    stockHigiene = fopen("higieneBackup", "w+b");
    stockLimpeza = fopen("limpiezaBackup", "w+b");
}

tr_Productos ingresarProducto() {
    tr_Productos producto;
    printf("Ingrese el codigo del producto:");
    scanf("%d", &producto.codProducto);
    printf("Ingrese el nombre del producto:");
    fflush(stdin);
    scanf("%[^\n]s", producto.nombreProduct);
    printf("Ingrese el precio por unidad del producto:");
    scanf("%f", &producto.precioUnit);
    printf("Ingrese la cantidad en stock del producto:");
    scanf("%d", &producto.cantTtal);
    return producto;
}

void modificarProducto(t_Producto **v_Lista, int pos, tr_Productos nuevoProducto) {
    t_Producto *aux;
    int i;
    aux = *v_Lista;
    for(i=0; i<pos && aux != NULL; i++) {
        aux = aux->sig;
    }
    if(aux != NULL) {
        aux->producto = nuevoProducto;
    } else {
        printf("La posición es mayor que la longitud de la lista.\n");
    }
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

void menu() {
    int opc;
    imprimirTitulo();
    printf("\nElija una opcion: 1-Ingresar un producto | 2-Eliminar un producto | 3-Buscar Un producto | 4-Modificar un producto "
            "| 5-Visualizar Productos | 6-Guardar stock  | 7-Guardar todo el stock cargado | 8-Salir");
}
