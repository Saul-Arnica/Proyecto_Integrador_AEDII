#ifndef OPERACIONES_ADMIN_USER
#define OPERACIONES_ADMIN_USER

#include"operacionesBasicas.h"

//Interfaz Publica

//Funciones de ingreso.

void ingresarProductos(t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, tr_Productos*, int);
void cargarProducto(t_ListaProducto**, tr_Productos*);

//Funciones de eliminar.

void eliminarProductos(t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, t_ListaProducto**,tr_Productos*, int);
void elimProductos(t_ListaProducto**, tr_Productos*, int); //Funcion para elegir de que forma eliminar
void eliminarProductoPorNombre(t_ListaProducto**, const char*);

//Funciones de Buscar.

void buscar_Productos(t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, t_ListaProducto*, char*, int, int*);
void buscar_Producto(t_ListaProducto**, t_ListaProducto*, char*, int, int*); //Funcion para elegir de que forma buscar
t_ListaProducto *buscarProduct(t_ListaProducto**, const int*); //Buscamos el producto por codigo de producto
t_ListaProducto *buscarProductoNombre(t_ListaProducto**, const char*); //Buscamos el producto por nombre de producto
void buscarProducto(t_ListaProducto**, const char*); //Buscamos los productos por nombre de producto

//Funciones de Modificar.


void modificar_Productos(t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, t_ListaProducto*, char*, int, int*); //Elejimos la categoria
void modificarProductos(t_ListaProducto**, t_ListaProducto*, int);//Elejimos que deseamos modificar
void procesarCambio(t_ListaProducto**, t_ListaProducto*, int, int);
void modificarProductoCompleto(t_ListaProducto**, int);

//Funciones para visualizar

void visualizar_Listas(t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, int);
void visualizarListas(t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, int);
void procesarVisualizarcion(t_ListaProducto**, t_ListaProducto**, t_ListaProducto**,t_ListaProducto**, int);


//Funciones varias necesarias para el funcionamiento de las funciones anteriores.

char *ingresarNombreProducto(char*);

int ingresarCodProducto(int);



void imprimirProducto(t_ListaProducto*);


//Interfaz Privada

void buscarProducto(t_ListaProducto **v_Lista, const char *nombreProducto) {
    t_ListaProducto *productoActual;
    productoActual = *v_Lista;
    printf("\tLos productos con esa descripcion son:\n");
    printf("| COD PRODUCTO | NOMB PRODUCTO | PRECIO UNITARIO | CANT TOTAL |\n");
    while(productoActual != NULL) {
        if(strstr(productoActual->producto.nombreProduct, nombreProducto) != NULL) {
            printf("| %d | %s | %.2f | %d |\n", productoActual->producto.codProducto, productoActual->producto.nombreProduct,
                                                    productoActual->producto.precioUnit, productoActual->producto.cantTtal);
        }
        productoActual = productoActual->sig;
    }
}

t_ListaProducto *buscarProduct(t_ListaProducto **v_Lista, const int *pCodProducto) {
    t_ListaProducto *productoActual;
    productoActual = *v_Lista;
    while(productoActual != NULL) {
        if(productoActual->producto.codProducto == *pCodProducto) {
            return productoActual;
        }
        productoActual = productoActual->sig;
    }
    return NULL;
}

t_ListaProducto *buscarProductoNombre(t_ListaProducto **v_Lista, const char *nombreProducto) {
    t_ListaProducto *productoActual;
    productoActual = *v_Lista;
    while(productoActual != NULL) {
        if(strstr(productoActual->producto.nombreProduct, nombreProducto) != NULL) {
            return productoActual;
        }
        productoActual = productoActual->sig;
    }
    return NULL;
}

void cargarProducto(t_ListaProducto **v_Lista, tr_Productos *producto) {
    printf("Ingrese el codigo del producto:");
    scanf("%d", &producto->codProducto);
    printf("Ingrese el nombre del producto:");
    fflush(stdin);
    scanf("%[^\n]s", producto->nombreProduct);
    pasarMayuscula(producto->nombreProduct);
    printf("Ingrese el precio por unidad del producto:");
    scanf("%f", &producto->precioUnit);
    printf("Ingrese la cantidad en stock del producto:");
    scanf("%d", &producto->cantTtal);
    if(*v_Lista == NULL) {
        insAlInicio(v_Lista, *producto);
    }else if(*v_Lista != NULL) {
        insFinal(v_Lista, *producto);
    }
}

void ingresarProductos(t_ListaProducto **v_Lista1, t_ListaProducto **v_Lista2, t_ListaProducto **v_Lista3, 
                        t_ListaProducto **v_Lista4, tr_Productos *producto, int opc) {
    printf("Seleccione la categoria a ingresar(1-Alimentos | 2-Bebidas | 3-Cuidado Personal | 4-Limpieza):");
    scanf("%d", &opc);
    switch(opc) {
        case 1:{    
            cargarProducto(v_Lista1, producto);
                break;
        }
        case 2:{    
            cargarProducto(v_Lista2, producto);
                break;
        }
        case 3:{    
            cargarProducto(v_Lista3, producto);
                break;
        }
        case 4:{    
            cargarProducto(v_Lista4, producto);
                break;
        }
    }
}

void eliminarProductos(t_ListaProducto **v_Lista1, t_ListaProducto **v_Lista2, t_ListaProducto **v_Lista3, 
                        t_ListaProducto **v_Lista4, tr_Productos *producto, int opc) {
    printf("Seleccione la categoria donde desea eliminar(1-Alimentos | 2-Bebidas | 3-Cuidado Personal | 4-Limpieza):");
    scanf("%d", &opc);
    switch(opc) {
        case 1:{
            elimProductos(v_Lista1, producto, opc);
                break;
        }
        case 2:{    
            elimProductos(v_Lista2, producto, opc);
                break;
        }
        case 3:{    
            elimProductos(v_Lista3, producto, opc);
                break;
        }
        case 4:{    
            elimProductos(v_Lista4, producto, opc);
                break;
        }
    }

}

void elimProductos(t_ListaProducto **v_Lista, tr_Productos *producto, int opc) {
    tString nombreProducto;
    printf("Seleccione la forma a eliminar(1-Ultimo producto agregado | 2-Por codigo de producto | 3-Por nombre):");
    scanf("%d", &opc);
    switch(opc) {
        case 1:{
            elimUltimoroducto(v_Lista);
                        break;
        }
        case 2:{
            opc = ingresarCodProducto(opc);
            producto->codProducto = opc;
            elim_Producto(v_Lista, *producto);
                        break;
        }
        case 3:{
            printf("Ingrese el nombre del producto a Eliminar:");
            fflush(stdin);
            scanf("%[^\n]s", nombreProducto);
            pasarMayuscula(nombreProducto);
            eliminarProductoPorNombre(v_Lista, nombreProducto); 
                        break;
        }
    }
}

void eliminarProductoPorNombre(t_ListaProducto **v_Lista, const char *nombreProducto) {
    t_ListaProducto* productoAEliminar;
    productoAEliminar = buscarProductoNombre(v_Lista, nombreProducto);
    if (productoAEliminar != NULL) {
        elim_Producto(v_Lista, productoAEliminar->producto);
    } else {
        printf("El producto no se encontró en la lista.\n");
    }
}

void buscar_Productos(t_ListaProducto **v_Lista1, t_ListaProducto **v_Lista2, t_ListaProducto **v_Lista3, 
                        t_ListaProducto **v_Lista4, t_ListaProducto *pProducto, char *pNombreProduc, int opc, int *pCodProducto) {

    printf("Seleccione la categoria donde desea buscar(1-Alimentos | 2-Bebidas | 3-Cuidado Personal | 4-Limpieza):");
    scanf("%d", &opc);
    switch(opc) {
        case 1:{
            buscar_Producto(v_Lista1, pProducto, pNombreProduc, opc, pCodProducto);
                                            break;
        }
        case 2:{    
            buscar_Producto(v_Lista2, pProducto, pNombreProduc, opc, pCodProducto);
                                            break;
        }
        case 3:{    
            buscar_Producto(v_Lista3, pProducto, pNombreProduc, opc, pCodProducto);
                                            break;
        }
        case 4:{    
            buscar_Producto(v_Lista4, pProducto, pNombreProduc, opc, pCodProducto);
                                            break;
        }
    }
}

void buscar_Producto(t_ListaProducto **v_Lista, t_ListaProducto *pPoducto, char *pNombreProduc, int opc, int *pCodProducto) {
    printf("Elija de que forma quiere buscar(1-Por nombre general | 2-Por codigo de producto):");
    scanf("%d", &opc);
    switch(opc) {
        case 1:{
            pNombreProduc = ingresarNombreProducto(pNombreProduc);
            buscarProducto(v_Lista, pNombreProduc);
                                break;
        }
        case 2:{
            *pCodProducto = ingresarCodProducto(*pCodProducto);
            pPoducto = buscarProduct(v_Lista, pCodProducto);
            imprimirProducto(pPoducto);
                                break;
        }
    }
}


char *ingresarNombreProducto(char *pNombreProduc) {
    printf("Ingrese el nombre del producto a buscar:");
    fflush(stdin);
    scanf("%[^\n]s", pNombreProduc);
    pasarMayuscula(pNombreProduc);
    return pNombreProduc;
}

int ingresarCodProducto(int pCodProducto) {
    printf("Ingrese el codigo de producto a buscar:");
    scanf("%d", &pCodProducto);
    return pCodProducto;
}

void imprimirProducto(t_ListaProducto *pProducto) {
    if(pProducto == NULL) {
        printf("No se encontro\n");
    }else{ 
        printf("\tLos productos con esa descripcion son:\n");
        printf("| COD PRODUCTO | NOMB PRODUCTO | PRECIO UNITARIO | CANT TOTAL |\n");
        printf("| %d | %s | %.2f | %d |\n", pProducto->producto.codProducto, pProducto->producto.nombreProduct,
                                                            pProducto->producto.precioUnit, pProducto->producto.cantTtal);
    }
}

void modificar_Productos(t_ListaProducto **v_Lista1, t_ListaProducto **v_Lista2, t_ListaProducto **v_Lista3, 
                            t_ListaProducto **v_Lista4, t_ListaProducto *pProducto, char *pNombreProduc, int opc, int *pCodProducto) {

    printf("Seleccione la categoria en la que desea modificar el producto:(1-Alimentos | 2-Bebidas | 3-Cuidado Personal |4-Limpieza):");
    scanf("%d", &opc);
    switch(opc) {
        case 1:{
            modificarProductos(v_Lista1, pProducto, opc);
                break;
        }
        case 2:{    
            modificarProductos(v_Lista2, pProducto, opc);
                break;
        }
        case 3:{    
            modificarProductos(v_Lista3, pProducto, opc);
                break;
        }
        case 4:{    
            modificarProductos(v_Lista4, pProducto, opc);
                break;
        }
    }
}

void modificarProductos(t_ListaProducto **v_Lista, t_ListaProducto *pProducto, int opc) {
    int codProducto;
    printf("Ingrese el codigo de producto a modificar:");
    scanf("%d", &codProducto);
    pProducto = buscarProduct(v_Lista, &codProducto);
    printf("Elija que desea modificar del producto seleccionado(1-Precio | 2-Cantidad | 3-Descripcion | 4-Todo):");
    scanf("%d", &opc);
    switch(opc) {
        case 1:{
            procesarCambio(v_Lista, pProducto, opc, codProducto);
                                break;
        }
        case 2:{
            procesarCambio(v_Lista, pProducto, opc, codProducto);
                                break;
        }
        case 3:{    
            procesarCambio(v_Lista, pProducto, opc, codProducto);
                                break;
        }
    }
}

void procesarCambio(t_ListaProducto **v_Lista, t_ListaProducto *producto, int opc, int pCodProducto) {
    float nuevoPrecio;
    int nuevaCantidad;
    tString nuevaDescripcion;
    switch(opc) {
        case 1:{
            printf("Ingrese el nuevo precio a cambiar:$");
            scanf("%f", &nuevoPrecio);
            producto->producto.precioUnit = nuevoPrecio;
                                break;
        }
        case 2:{
            printf("Ingrese la nueva cantidad a cambiar:");
            scanf("%d", &nuevaCantidad);
            producto->producto.cantTtal = nuevaCantidad;
                                break;
        }
        case 3:{
            printf("Ingrese la nueva descripcion a cambiar:");
            fflush(stdin);
            scanf("%[^\n]s", nuevaDescripcion);
            strcpy(producto->producto.nombreProduct, nuevaDescripcion);
                                break;
        }
        case 4:{
            modificarProductoCompleto(v_Lista, pCodProducto);
            break;
        }
    }
}

void modificarProductoCompleto(t_ListaProducto **v_Lista, int pCodProducto) {
    t_ListaProducto *aux;
    int i;
    tr_Productos nuevoProducto;
    // Pedir al usuario que introduzca los nuevos datos del producto
    printf("Introduce el nuevo nombre del producto: ");
    scanf("%s", nuevoProducto.nombreProduct);
    printf("Introduce el nuevo precio del producto: ");
    scanf("%f", &nuevoProducto.precioUnit);
    printf("Introduce la nueva cantidad total del producto: ");
    scanf("%d", &nuevoProducto.cantTtal);

    aux = *v_Lista;
    while(aux->producto.codProducto != nuevoProducto.codProducto) {
        aux = aux->sig;
    }
    if(aux != NULL) {
        aux->producto = nuevoProducto;
    } else {
        printf("El producto a querer modificar no existe.\n");
    }
}

void visualizar_Listas(t_ListaProducto **v_Lista1, t_ListaProducto **v_Lista2,
                        t_ListaProducto **v_Lista3, t_ListaProducto **v_Lista4, int opc) {
    printf("Seleccione que desea visualizar(1-Categoria en especifico | 2-Todas las categorias):");
    scanf("%d", &opc);
    switch(opc) {
        case 1:{
            printf("Seleccione la categoria a ingresar(1-Alimentos 2-Bebidas 3-Cuidado Personal 4-Limpieza):");
            scanf("%d", &opc);
            switch(opc) {
                case 1:{
                    visualizarLista(*v_Lista1);
                            break;
                }
                case 2:{
                    visualizarLista(*v_Lista2);
                            break;
                }
                case 3:{    
                    visualizarLista(*v_Lista3);
                            break;
                }
                case 4:{    
                    visualizarLista(*v_Lista4);
                            break;
                }
            }
                            break;
        }
        case 2:{
            procesarVisualizarcion(v_Lista1, v_Lista2, v_Lista3, v_Lista4, opc);
                            break;
        }
    }
}
void procesarVisualizarcion(t_ListaProducto **v_Lista1, t_ListaProducto **v_Lista2, t_ListaProducto **v_Lista3, t_ListaProducto **v_Lista4, int opc) {
    printf("\nTodos los productos en la categoria de Alimentos son:\n");
    visualizarLista(*v_Lista1);
    printf("\nTodos los productos en la categoria de Bebidas son:\n");
    visualizarLista(*v_Lista2);
    printf("\nTodos los productos en la categoria de Cuidado personal son:\n");
    visualizarLista(*v_Lista3);
    printf("\nTodos los productos en la categoria de Limpieza son:\n");
    visualizarLista(*v_Lista4);
    printf("\n");
}

#endif 
