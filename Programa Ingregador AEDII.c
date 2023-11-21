
#include"listaDoblementeEnlazada.h"
#include"inicioDePrograma.h"
#include"operacionesBasicas.h"
#include"operacionesAdmin-User.h"
#include"finDePrograma.h"

//Prototipado de funciones
void procesarInicio();
void menu();

//Variables globales

FILE *stockAlimentos, *stockBebidas, *stockHigiene, *stockLimpeza;
t_Producto *alimentos, *bebidas, *cuidadoPersonal, *limpieza;

//Funcion Principal  

int main() {
    procesarInicio();
    imprimirTitulo();
    menu();    
return 0;
}

//Implementacion

void procesarInicio() {
    inicializarListas(&alimentos, &bebidas, &cuidadoPersonal, &limpieza);

    if(archivoExiste("alimentosBackup") && archivoExiste("bebidasBackup") 
        && archivoExiste("higieneBackup") && archivoExiste("limpiezaBackup")) {

        cargarDesdeArchivo(&alimentos, "alimentosBackup");
        cargarDesdeArchivo(&bebidas, "bebidasBackup");
        cargarDesdeArchivo(&cuidadoPersonal, "higieneBackup");
        cargarDesdeArchivo(&limpieza, "limpiezaBackup");

    }else{
        inicializarArchivos(&stockAlimentos, &stockBebidas, &stockHigiene, &stockLimpeza);
    }
}

void menu() {
    int opc;
    tr_Productos *product;
    t_Producto *producto;
    tString nombreProducto;
    printf("\033[H\033[J");
    printf("\t*** Bienvenidos a RetailMate lo mejor para tu comercio :D ***\n");
    printf("\nElija una opcion 1-Ingresar un producto | 2-Eliminar un producto | 3-Buscar Un producto | 4-Modificar un producto "
            "| 5-Visualizar Productos | 6-Opciones de guardado | 8-Salir:");
    scanf("%d", &opc);
    switch(opc) {
        case 1:{
            printf("En que sector quiere ingresar el producto?(1-alimentos 2-bebidas 3-cuidadoPersonal 4-limpieza):");
            scanf("%d", &opc);
            ingresarProductos(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, product, opc);
            menu();
                    break;
        }
        case 2:{
            printf("En que sector quiere eliminar el producto?(1-alimentos 2-bebidas 3-cuidadoPersonal 4-limpieza):");
            scanf("%d", &opc);
            eliminarProductos(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, opc);
            menu();
            break;
        }
        case 3:{
            printf("En que sector quiere buscar el producto?(1-alimentos 2-bebidas 3-cuidadoPersonal 4-limpieza)");
            scanf("%d", &opc);
            buscarProductos(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, producto, opc);
            menu();
            break;
        }
        case 4:{
            
            menu();
            break;
        }
    }
}
