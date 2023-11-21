#include"operacionesBasicas.h"



//Interfaz Publica

t_ListaProducto *buscarProducto(t_ListaProducto**, const char*); //Buscamos por nombre el producto
void cargarProducto(t_ListaProducto**, tr_Productos*);
void ingresarProductos(t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, tr_Productos*, int);
void eliminarProductos(t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, int);
void buscarProductos(t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, t_ListaProducto**, t_ListaProducto*, int);
void modificarProducto(t_ListaProducto**, int, tr_Productos);

//Interfaz Privada

t_ListaProducto* buscarProducto(t_ListaProducto **v_Lista, const char *nombreProducto) {
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

void modificarProducto(t_ListaProducto **v_Lista, int pos, tr_Productos nuevoProducto) {
    t_ListaProducto *aux;
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
    insproducto(v_Lista, *producto);
}

void ingresarProductos(t_ListaProducto **v_Lista1, t_ListaProducto **v_Lista2, t_ListaProducto **v_Lista3, 
                        t_ListaProducto **v_Lista4, tr_Productos *producto, int opc) {
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
                        t_ListaProducto **v_Lista4, int opc) {
    switch(opc) {
        case 1:{    
            elimproducto(v_Lista1);
                break;
        }
        case 2:{    
            elimproducto(v_Lista2);
                break;
        }
        case 3:{    
            elimproducto(v_Lista3);
                break;
        }
        case 4:{    
            elimproducto(v_Lista4);
                break;
        }
    }

}
void buscarProductos(t_ListaProducto **v_Lista1, t_ListaProducto **v_Lista2, t_ListaProducto **v_Lista3, 
                        t_ListaProducto **v_Lista4, t_ListaProducto *producto, int opc) {
    switch(opc) {
                case 1:{
                    tString nombreProduc;
                    printf("Ingrese el nombre del producto a buscar:");
                    fflush(stdin);
                    scanf("%[^\n]s", nombreProduc);
                    pasarMayuscula(nombreProduc);
                    producto = buscarProducto(v_Lista1, nombreProduc);
                    if(producto == NULL) {
                        printf("No se encontro\n");
                    }else{
                        printf("El producto buscado es: %d %s %.2f %d \n", producto->producto.codProducto, producto->producto.nombreProduct, producto->producto.precioUnit, 
                                                                            producto->producto.cantTtal);
                    }
                    break;
                }
                case 2:{    
                    tString nombreProduc;
                    printf("Ingrese el nombre del producto a buscar:");
                    fflush(stdin);
                    scanf("%[^\n]s", nombreProduc);
                    pasarMayuscula(nombreProduc);
                    producto = buscarProducto(v_Lista2, nombreProduc);
                    break;
                }
                case 3:{    
                    tString nombreProduc;
                    printf("Ingrese el nombre del producto a buscar:");
                    fflush(stdin);
                    scanf("%[^\n]s", nombreProduc);
                    pasarMayuscula(nombreProduc);
                    buscarProducto(v_Lista3, nombreProduc);
                    break;
                }
                case 4:{    
                    tString nombreProduc;
                    printf("Ingrese el nombre del producto a buscar:");
                    fflush(stdin);
                    scanf("%[^\n]s", nombreProduc);
                    pasarMayuscula(nombreProduc);
                    buscarProducto(v_Lista4, nombreProduc);
                    break;
                }
            }
}

