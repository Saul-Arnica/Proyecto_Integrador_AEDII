#include"inicioDePrograma.h"
#include"operacionesAdmin.h"
#include"operacionesUser.h"
#include"finPrograma.h"

//Prototipado de funciones

void inicializacionStock();
void inicioPrograma();
void menu1();
void menu2();
void terminacionDePrograma();

//Variables globales

t_ListaProducto *alimentos, *bebidas, *cuidadoPersonal, *limpieza;

tr_UsuarioInfo usuario;

FILE *stockAlimentos, *stockBebidas, *stockCuidadoPersonal, *stockLimpieza, *archivoUsuarios;

//Funcion principal

int main() {
    inicializacionStock();
    inicioPrograma();
return 0;
}

//Implementacion de funciones

void inicializacionStock() {

    inicializarListas(&alimentos, &bebidas, &cuidadoPersonal, &limpieza);

    if(archivoExiste("stockAlimentos.dat") && archivoExiste("stockBebidas.dat") 
        && archivoExiste("stockCuidadoPersonal.dat") && archivoExiste("stockLimpieza.dat")) {

        cargarDesdeArchivo(&alimentos, "stockAlimentos.dat");
        cargarDesdeArchivo(&bebidas, "stockBebidas.dat");
        cargarDesdeArchivo(&cuidadoPersonal, "stockCuidadoPersonal.dat");
        cargarDesdeArchivo(&limpieza, "stockLimpieza.dat");

    }else{

        inicializarArchivo(&stockAlimentos, "stockAlimentos.dat");
        inicializarArchivo(&stockBebidas, "stockBebidas.dat");
        inicializarArchivo(&stockCuidadoPersonal, "stockCuidadoPersonal.dat");
        inicializarArchivo(&stockLimpieza, "stockLimpieza.dat");

    }
    imprimirInicio();
}

void inicioPrograma() {
    int estado;

    if(archivoExiste("archivoUsuarios.dat")) {


        usuario = ingresarUsuario();
        estado = verificarUsuarios(&archivoUsuarios, "archivoUsuarios.dat", usuario);
        switch(estado) {
            case 1:{
                printf("Bienvenido administrador %d - %s", usuario.ID, usuario.nombre);
                sleep(2);
                menu1();
                                                    break;
            }
            case 2:{
                printf("Bienvenido empleado %d - %s", usuario.ID, usuario.nombre);
                sleep(2);
                menu2();
                                                    break;
            }
            case 0:{
                printf("Usuario incorrecto, intente de nuevo...");
                sleep(2);
                inicioPrograma();
                                                    break;
            }
        }

    }else{

        inicializarArchivo(&archivoUsuarios, "archivoUsuarios.dat");
        printf("\t\t\tBienvenido al Software RetailMate\n");
        printf("Ingrese un usuario Administrador\n\n");
        usuario = registrarUsuario();
        grabarUsuario(&archivoUsuarios, usuario, "archivoUsuarios.dat");
        printf("Bienvenido administrador %d - %s", usuario.ID, usuario.nombre);
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
            printf("Opciones disponibles(1-Agregar usuario | 2-Elimiar usuario | 3-Visualizar usuarios registrados):");
            scanf("%d", &opc);
            switch(opc) {
                case 1:{
                    usuario = registrarUsuario();
                    grabarUsuario(&archivoUsuarios, usuario, "archivoUsuarios.dat");
                    printf("Usuario %d - %s guardado exitosamente\n", usuario.ID, usuario.nombre);
                                                    break;
                }
                case 2:{
                    int confirmacion;
                    printf("Ingrese el ID del usuario a eliminar:");
                    scanf("%d", &usuario.ID);
                    eliminarUsuario(usuario);
                                                    break;
                }
                case 3:{
                    visualizarUsuarios(&archivoUsuarios, "archivoUsuarios.dat");
                                                    break;
                }
            }
            menu1();
                                                    break;
        }
        case 0:{
            printf("Gracias por usar nuestro software!\n");
            printf("\n\tCualquier incoveniente enviar al correo: ""retailMate@outlook.com""");
            terminacionDePrograma();
            imprimirGuardado();
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

void terminacionDePrograma() {
    procesarGuardado(&stockAlimentos, &stockBebidas, &stockCuidadoPersonal, &stockLimpieza, &archivoUsuarios,
                        &alimentos, &bebidas, &cuidadoPersonal, &limpieza, usuario);
}