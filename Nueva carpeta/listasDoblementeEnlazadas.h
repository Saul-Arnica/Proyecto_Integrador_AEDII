#ifndef LISTA_DOBLEMENTE_ENLAZADA_H
#define LISTA_DOBLEMENTE_ENLAZADA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <windows.h>

#define MAX_CHAR 50

//Tipos de producto compuestos

typedef char tString[MAX_CHAR];

typedef struct {
    int codProducto;
    tString nombreProduct;
    float precioUnit;
    int cantTtal;
}tr_Productos;

typedef struct producto {
    tr_Productos producto;
    struct producto *sig;
    struct producto *ant;
}t_ListaProducto;


// Prototipos de funciones

void inicializarLista(t_ListaProducto**);
bool listaVacia(t_ListaProducto*);
void insAlInicio(t_ListaProducto**, tr_Productos);
void insFinal(t_ListaProducto**, tr_Productos);
void elim_Producto(t_ListaProducto**, tr_Productos);
void elimpUltimoroducto(t_ListaProducto **);
void visualizarLista(t_ListaProducto*);

// Implementacion de las funciones
void inicializarLista(t_ListaProducto **lista) {
    *lista = NULL;
}

bool listaVacia(t_ListaProducto *lista) {
    return lista == NULL;
}

void insAlInicio(t_ListaProducto **lista, tr_Productos pProducto) {
    t_ListaProducto* nuevoProducto;
    nuevoProducto = (t_ListaProducto*)malloc(sizeof(t_ListaProducto));
    if (nuevoProducto == NULL) {
        printf("No se pudo asignar memoria!...\n");
        exit(EXIT_FAILURE);
    }
    nuevoProducto->producto = pProducto;
    nuevoProducto->sig = *lista;
    nuevoProducto->ant = NULL;
    if (*lista != NULL) {
        (*lista)->ant = nuevoProducto;
    }
    *lista = nuevoProducto;
}

void insFinal(t_ListaProducto** lista, tr_Productos pProducto) {
    t_ListaProducto* nuevoProducto;
    nuevoProducto = (t_ListaProducto*)malloc(sizeof(t_ListaProducto));
    if (nuevoProducto == NULL) {
        printf("No se pudo asignar memoria!...\n");
        exit(EXIT_FAILURE);
    }
    nuevoProducto->producto = pProducto;
    nuevoProducto->sig = NULL;

    if (*lista == NULL) {
        nuevoProducto->ant = NULL;
        *lista = nuevoProducto;
    }else{
        t_ListaProducto* final;
        final = *lista; 
        while (final->sig != NULL) {
            final = final->sig;
        }
        final->sig = nuevoProducto;
        nuevoProducto->ant = final;
    }
}

void elim_Producto(t_ListaProducto **lista, tr_Productos pProducto) {
    if (*lista == NULL) {
        printf("La lista está vacía!...\n");
        return;
    }

    t_ListaProducto *aux = *lista;
    t_ListaProducto *prev = NULL;

    if (aux != NULL && aux->producto.codProducto == pProducto.codProducto) {
        *lista = aux->sig;
        if (*lista != NULL) {
            (*lista)->ant = NULL;
        }
        free(aux);
        return;
    }

    while (aux != NULL && aux->producto.codProducto != pProducto.codProducto) {
        prev = aux;
        aux = aux->sig;
    }

    if (aux == NULL) {
        printf("El elemento no está presente en la lista!...\n");
        return;
    }

    prev->sig = aux->sig;
    if (aux->sig != NULL) {
        aux->sig->ant = prev;
    }
    free(aux);
}

void elimpUltimoroducto(t_ListaProducto **v_Lista) {
    if(!listaVacia(*v_Lista)) {
        t_ListaProducto *productoSuprimir;
        productoSuprimir = *v_Lista;
        while(productoSuprimir->sig != NULL) {
            productoSuprimir = productoSuprimir->sig;
        }
        if(productoSuprimir->ant != NULL) {
            productoSuprimir->ant->sig = NULL;
        }
        productoSuprimir->ant = NULL;
        productoSuprimir->sig = NULL;
        printf("| COD PRODUCTO | NOMB PRODUCTO |\n");
        printf("Se elimino el producto: %d %s...\n", productoSuprimir->producto.codProducto,
                                                        productoSuprimir->producto.nombreProduct);
        productoSuprimir = NULL;
        free(productoSuprimir);
        
    }else {
        printf("No hay productos!....\n");
    }
}

void elimpUltimoroducto(t_ListaProducto **v_Lista) {
    if(!listaVacia(*v_Lista)) {
        t_ListaProducto *productoSuprimir;
        productoSuprimir = *v_Lista;
        while(productoSuprimir->sig != NULL) {
            productoSuprimir = productoSuprimir->sig;
        }
        if(productoSuprimir->ant != NULL) {
            productoSuprimir->ant->sig = NULL;
        }else{
            // Si el nodo a suprimir es también el primer nodo
            *v_Lista = NULL;
        }
        printf("| COD PRODUCTO | NOMB PRODUCTO |\n");
        printf("Se elimino el producto: %d %s...\n", productoSuprimir->producto.codProducto,productoSuprimir->producto.nombreProduct);
        
        productoSuprimir = NULL;
        free(productoSuprimir);
    }else {
        printf("No hay productos!....\n");
    }
}


void visualizarLista(t_ListaProducto *lista) {
    t_ListaProducto *productoActual;
    productoActual = lista;
    if(productoActual != NULL) {
        while(productoActual->ant != NULL) {
            productoActual = productoActual->ant;
        }
    printf("| COD PRODUCTO | NOMB PRODUCTO | PRECIO UNITARIO | CANT TOTAL |\n");
    while (productoActual != NULL) {
        printf("| %-8d | %-12s | %-5.2f | %-5d | \n", productoActual->producto.codProducto,productoActual->producto.nombreProduct, 
                                                        productoActual->producto.precioUnit,productoActual->producto.cantTtal);
        productoActual = productoActual->sig;
    }
    printf("\n");
	}else{
        printf("No hay productos!");
    }
}
#endif
