
#include"listaDoblementeEnlazada.h"
#include"inicioDePrograma.h"
#include"operacionesBasicas.h"
#include"operacionesAdmin-User.h"
#include"finDePrograma.h"

//Prototipado de funciones
void procesarElInicio();
void menu();

//Variables globales

FILE *stockAlimentos, *stockBebidas, *stockHigiene, *stockLimpeza;
t_Producto *alimentos, *bebidas, *cuidadoPersonal, *limpieza;

//Funcion Principal  

int main() {
    procesarElInicio();
    imprimirTitulo();
    menu();    
return 0;
}

//Implementacion

void procesarElInicio() {
    inicializarListas();
    if(archivoExiste("alimentosBackup") && archivoExiste("bebidasBackup") 
        && archivoExiste("higieneBackup") && archivoExiste("limpiezaBackup")) {

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
    
}

void inicializarListas() {
    inicializarLista(&alimentos); 
    inicializarLista(&bebidas);  
    inicializarLista(&cuidadoPersonal); 
    inicializarLista(&limpieza);
}

void inicializarArchivos() {
    stockAlimentos = fopen("alimentosBackup", "w+b");
    stockBebidas = fopen("bebidasBackup", "w+b");
    stockHigiene = fopen("higieneBackup", "w+b");
    stockLimpeza = fopen("limpiezaBackup", "w+b");
}

void cargarProducto(t_Producto **v_Lista, tr_Productos producto) {
    printf("Ingrese el codigo del producto:");
    scanf("%d", &producto.codProducto);
    printf("Ingrese el nombre del producto:");
    fflush(stdin);
    scanf("%[^\n]s", producto.nombreProduct);
    pasarMayuscula(producto.nombreProduct);
    printf("Ingrese el precio por unidad del producto:");
    scanf("%f", &producto.precioUnit);
    printf("Ingrese la cantidad en stock del producto:");
    scanf("%d", &producto.cantTtal);
    insproducto(&v_Lista, producto);
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

void pasarMayuscula(char *nombreProducto) {
    for(int i = 0; nombreProducto[i]; i++){
        nombreProducto[i] = toupper(nombreProducto[i]);
    }
}

void menu() {
    int opc;
    tr_Productos product;
    t_Producto *producto;
    printf("\033[H\033[J");
    printf("\t*** Bienvenidos a RetailMate lo mejor para tu comercio :D ***\n");
    printf("\nElija una opcion 1-Ingresar un producto | 2-Eliminar un producto | 3-Buscar Un producto | 4-Modificar un producto "
            "| 5-Visualizar Productos | 6-Guardar stock | 7-Guardar todo el stock cargado | 8-Salir:");
    scanf("%d", &opc);
    switch(opc) {
        case 1:{
            printf("En que sector quiere ingresar el producto?(1-alimentos 2-bebidas 3-cuidadoPersonal 4-limpieza):");
            scanf("%d", &opc);
            switch(opc) {
                case 1:{    
                    cargarProducto(&bebidas, product);
                    break;
                }
                case 2:{    
                    cargarProducto(&bebidas, product);
                    break;
                }
                case 3:{    
                    cargarProducto(&bebidas, product);
                    break;
                }
                case 4:{    
                    cargarProducto(&bebidas, product);
                    break;
                }
            }
            menu();
                    break;
        }
        case 2:{
            printf("En que sector quiere eliminar el producto?(1-alimentos 2-bebidas 3-cuidadoPersonal 4-limpieza):");
            scanf("%d", &opc);
            switch(opc) {
                case 1:{    
                    elimproducto(&alimentos);
                    break;
                }
                case 2:{    
                    elimproducto(&bebidas);
                    break;
                }
                case 3:{    
                    elimproducto(&cuidadoPersonal);
                    break;
                }
                case 4:{    
                    elimproducto(&limpieza);
                    break;
                }
            }
            menu();
            break;
        }
        case 3:{
            printf("En que sector quiere buscar el producto?(1-alimentos 2-bebidas 3-cuidadoPersonal 4-limpieza)");
            scanf("%d", &opc);
            switch(opc) {
                case 1:{
                    
                    tString nombreProduc;
                    printf("Ingrese el nombre del producto a buscar:");
                    fflush(stdin);
                    scanf("%[^\n]s", nombreProduc);
                    pasarMayuscula(nombreProduc);
                    producto = buscarProducto(&alimentos, nombreProduc);
                    if(producto == NULL) {
                        printf("No se encontro\n");
                    }else{
                        printf("El producto buscado es: %d %s %.2f %d %.2f\n", producto->producto.codProducto, producto->producto.nombreProduct,
                                                        producto->producto.precioUnit, producto->producto.cantTtal);
                    }
                    break;
                }
                case 2:{    
                    tString nombreProduc;
                    printf("Ingrese el nombre del producto a buscar:");
                    fflush(stdin);
                    scanf("%[^\n]s", nombreProduc);
                    pasarMayuscula(nombreProduc);
                    buscarProducto(&bebidas, nombreProduc);
                    break;
                }
                case 3:{    
                    tString nombreProduc;
                    printf("Ingrese el nombre del producto a buscar:");
                    fflush(stdin);
                    scanf("%[^\n]s", nombreProduc);
                    pasarMayuscula(nombreProduc);
                    buscarProducto(&cuidadoPersonal, nombreProduc);
                    break;
                }
                case 4:{    
                    tString nombreProduc;
                    printf("Ingrese el nombre del producto a buscar:");
                    fflush(stdin);
                    scanf("%[^\n]s", nombreProduc);
                    pasarMayuscula(nombreProduc);
                    buscarProducto(&limpieza, nombreProduc);
                    break;
                }
            }
            menu();
            break;
        }
        case 4:{
            
            menu();
            break;
        }
        case 5:{

            menu();
            break;
        }
        case 6:{

            menu();
            break;
        }
        case 7:{

            menu();
            break;
        }
        case 8:{

            menu();
            break;
        }
        case 9:{

            menu();
            break;
        }
    }
}
