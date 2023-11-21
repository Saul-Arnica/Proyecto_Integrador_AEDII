#include"inicioDePrograma.h"
#include"operacionesBasicas.h"
#include"operacionesAdmin-User.h"
#include"finDePrograma.h"

//Prototipado de funciones
void inicializacionPrograma();
void menu();

//Variables globales

t_ListaProducto *alimentos, *bebidas, *cuidadoPersonal, *limpieza;

FILE *stockAlimentos, *stockBebidas, *stockCuidadoPersonal, *stockLimpieza;

//Funcion principal

int main() {
    inicializacionPrograma();
    imprimirTitulo();
    menu();
return 0;
}

//Implementacion

void inicializacionPrograma() {

    inicializarListas(&alimentos, &bebidas, &cuidadoPersonal, &limpieza);
    
    if(archivoExiste("stockAlimentos") && archivoExiste("stockBebidas") &&
        archivoExiste("stockCuidadoPersonal") && archivoExiste("stockLimpieza")) {

            cargarDesdeArchivo(&alimentos, "stockAlimentos");
            cargarDesdeArchivo(&bebidas, "stockBebidas");
            cargarDesdeArchivo(&cuidadoPersonal, "stockCuidadoPersonal");
            cargarDesdeArchivo(&limpieza, "stockLimpieza");

        }else{

            inicializarArchivos(&stockAlimentos, &stockBebidas, &stockCuidadoPersonal, &stockLimpieza);

        }

}

void menu() {
    int opc;
    tr_Productos *product;
    t_ListaProducto *nuevoProducto;
    imprimirTitulo();
    printf("\nElija una opcion:"
    "1-Ingresar un producto | 2-Eliminar un producto | 3-Buscar Un producto | 4-Modificar un producto | 5-Visualizar Productos |"
    " | 6- 7- 8- etc");
    scanf("%d", &opc);
    switch(opc) {
        case 1:{
            ingresarProductos(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, product, opc);
            menu();
            break;
        }
        case 2:{
            break;
        }
        case 3:{
            break;
        }
        case 4:{
            break;
        }
        case 5:{
            break;
        }
    }
}


