#include"listasDoblementeEnlazadas.h"
#include"inicioDePrograma.h"
#include"operacionesBasicas.h"
#include"operacionesUser.h"

//#include"finDePrograma.h"
//Prototipado de funciones

void inicializacionStock();
void inicioPrograma();
void menu1();
void menu2();


//Variables globales

int confirmacion;

t_ListaProducto *alimentos, *bebidas, *cuidadoPersonal, *limpieza;

tr_UsuarioInfo usuario;

FILE *stockAlimentos, *stockBebidas, *stockCuidadoPersonal, *stockLimpieza, *archivoUsuarios;

//Funcion principal
int main() {
    //inicializacionStock();
    //imprimirTitulo();
    //inicioPrograma();
    imprimirGuardado();
    //system("pause");
return 0;
}

void inicializacionStock() {

    inicializarListas(&alimentos, &bebidas, &cuidadoPersonal, &limpieza);

    if(archivoExiste("stockAlimentos") && archivoExiste("stockBebidas") && archivoExiste("stockCuidadoPersonal") && archivoExiste("stockLimpieza")) {

        cargarDesdeArchivo(&alimentos, "stockAlimentos");
        cargarDesdeArchivo(&bebidas, "stockBebidas");
        cargarDesdeArchivo(&cuidadoPersonal, "stockCuidadoPersonal");
        cargarDesdeArchivo(&limpieza, "stockLimpieza");

    }else{

        inicializarArchivo(&stockAlimentos);
        inicializarArchivo(&stockBebidas);
        inicializarArchivo(&stockCuidadoPersonal);
        inicializarArchivo(&stockLimpieza);

    }
}

void inicioPrograma() {

    if(archivoExiste("archivoUsuarios")) {

            usuario = ingresarUsuario();

            if(verificarUsuarios(&archivoUsuarios, "archivoUsuarios", usuario) == 1) {
                printf("Bienvenido administrador %s", usuario.usuario);
                sleep(2);
                menu1();
            }else if(verificarUsuarios(&archivoUsuarios, "archivoUsuarios", usuario) == 2) {
                printf("Bienvenido empleado %s", usuario.usuario);
                sleep(2);
                menu2();
            }else if(verificarUsuarios(&archivoUsuarios, "archivoUsuarios", usuario) == 0) {
                printf("Usuario incorrecto, intente de nuevo...");
                sleep(2);
                inicioPrograma();
            }

        }else{
            inicializarArchivo(&archivoUsuarios);
            printf("\t\t\tBienvenido al Software RetailMate\n");
            printf("Ingrese un usuario Administrador\n\n");
            usuario = ingresarUsuario();
            printf("Bienvenido administrador %s", usuario.usuario);
            sleep(2);
            menu1();
        }
}

void menu1() {
    int opc, codProducto;
    tString nombreProducto;
    tr_Productos product;
    t_ListaProducto nuevoProducto;
    printf("\nElija una opcion:"
    "1-Ingresar un producto | 2-Eliminar un producto | 3-Buscar Un producto | 4-Modificar un producto | 5-Visualizar Productos "
    "| 6-Opciones administrador | 0-Salir:");
    scanf("%d", &opc);
    switch(opc) {
        case 1:{

            ingresarProductos(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, &product, opc);
            menu1();
                                                    break;

        }
        case 2:{

            eliminarProductos(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, &product, opc);
            menu1();
                                                    break;

        }
        case 3:{

            buscar_Productos(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, &nuevoProducto, nombreProducto, opc, &codProducto);
            menu1();
                                                    break;

        }
        case 4:{

            modificar_Productos(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, &nuevoProducto, nombreProducto, opc, &codProducto);
            menu1();    
                                                    break;

        }
        case 5:{

            visualizar_Listas(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, opc);
            menu1();
                                                    break;

        }
        case 6:{
            menu1();
                                                    break;
        }
        case 0:{
            printf("Gracias por usar nuestro software!\n");
            printf("\tCualquier incoveniente enviar al correo: ""retailMate@outlook.com""");
            sleep(5);
            printf("\n");
                                                    break;
        }
        default:{
            printf("Opcion incorrecta\n");
            sleep(1);
            printf("\033[H\033[J");
            menu1();
        } 
    }
}

void menu2() {
    int opc, codProducto;
    tString nombreProducto;
    tr_Productos product;
    t_ListaProducto nuevoProducto;
    printf("\nElija una opcion:"
    "1-Ingresar un producto | 2-Eliminar un producto | 3-Buscar Un producto | 4-Modificar un producto | 5-Visualizar Productos "
    "| 0-Salir:");
    scanf("%d", &opc);
    switch(opc) {
        case 1:{

            ingresarProductos(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, &product, opc);
            menu2();
                                                    break;

        }
        case 2:{

            eliminarProductos(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, &product, opc);
            menu2();
                                                    break;

        }
        case 3:{

            buscar_Productos(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, &nuevoProducto, nombreProducto, opc, &codProducto);
            menu2();
                                                    break;

        }
        case 4:{

            modificar_Productos(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, &nuevoProducto, nombreProducto, opc, &codProducto);
            menu2();    
                                                    break;

        }
        case 5:{

            visualizar_Listas(&alimentos, &bebidas, &cuidadoPersonal, &limpieza, opc);
            menu2();
                                                    break;

        }
        case 0:{
            printf("Gracias por usar nuestro software!\n");
            printf("\tCualquier incoveniente enviar al correo: ""retailMate@outlook.com""");
            sleep(4);
            printf("\n");
                                                    break;
        }
        default:{
            printf("Opcion incorrecta\n");
            sleep(1);
            printf("\033[H\033[J");
            menu2();
        } 
    }
}


