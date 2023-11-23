#include"listasDoblementeEnlazadas.h"
#include"inicioDePrograma.h"
#include"operacionesBasicas.h"
#include"operacionesUser.h"

//#include"finDePrograma.h"
//Prototipado de funciones

void inicializacionPrograma();
void menu();

//Variables globales

t_ListaProducto *alimentos, *bebidas, *cuidadoPersonal, *limpieza;

FILE *stockAlimentos, *stockBebidas, *stockCuidadoPersonal, *stockLimpieza, *archivoAdminstradores, *archivoEmpleados;


//Funcion principal
int main() {
    inicializacionPrograma();
    imprimirTitulo();
    menu();
    system("pause");
return 0;
}

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
    int opc, codProducto;
    tString nombreProducto;
    tr_Productos product;
    t_ListaProducto nuevoProducto;
    printf("\nElija una opcion:"
    "1-Ingresar un producto | 2-Eliminar un producto | 3-Buscar Un producto | 4-Modificar un producto | 5-Visualizar Productos |"
    " 0-Salir:");
    scanf("%d", &opc);
    switch(opc) {
        case 1:{

            ingresarProductos(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, &product, opc);
            menu();
                                                    break;

        }
        case 2:{

            eliminarProductos(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, &product, opc);
            menu();
                                                    break;

        }
        case 3:{

            buscar_Productos(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, &nuevoProducto, nombreProducto, opc, &codProducto);
            menu();
                                                    break;

        }
    case 4:{

            modificar_Productos(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, &nuevoProducto, nombreProducto, opc, &codProducto);
            menu();    
                                                    break;

        }
        case 5:{

            visualizar_Listas(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, opc);
            menu();
                                                    break;

        }
        case 0:{
            printf("Gracias por usar nuestro software!\n");
            printf("\tCualquier incoveniente enviar al correo: ""retailMate@outlook.com""");
            sleep(5);
            printf("\n");
        }
        default:{
            printf("Opcion incorrecta\n");
            sleep(1);
            printf("\033[H\033[J");
            menu();
        } 
    }
}
