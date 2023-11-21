#ifndef LISTA_DOBLEMENTE_ENLAZADA_H
#define LISTA_DOBLEMENTE_ENLAZADA_H

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<ctype.h>

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
void visualizarListas(t_ListaProducto*);

#endif

// Implementación de las funciones
void inicializarLista(t_ListaProducto **lista) {
    *lista = NULL;
}

bool listaVacia(t_ListaProducto *lista) {
    return lista == NULL;
}

void insAlInicio(t_ListaProducto **lista, tr_Productos pruducto) {
    t_ListaProducto* nuevoProducto = (t_ListaProducto*)malloc(sizeof(t_ListaProducto));
    if (nuevoProducto == NULL) {
        printf("No se pudo asignar memoria\n");
        return;
    }
    nuevoProducto->producto = pruducto;
    nuevoProducto->sig = *lista;
    nuevoProducto->ant = NULL;
    if (*lista != NULL) {
        (*lista)->ant = nuevoProducto;
    }
    *lista = nuevoProducto;
}
void insFinal(t_ListaProducto** lista, tr_Productos pProducto) {
    t_ListaProducto* nuevoProducto = (t_ListaProducto*)malloc(sizeof(t_ListaProducto));
    if (nuevoProducto == NULL) {
        printf("Error: memoria no asignada.\n");
        return;
    }
    nuevoProducto->producto = pProducto;
    nuevoProducto->sig = NULL;

    if (*lista == NULL) {
        nuevoProducto->ant = NULL;
        *lista = nuevoProducto;
        return;
    }

    t_ListaProducto* ultimo = *lista;
    while (ultimo->sig != NULL) {
        ultimo = ultimo->sig;
    }

    ultimo->sig = nuevoProducto;
    nuevoProducto->ant = ultimo;
}

void eliminart_ListaProducto(t_ListaProducto **lista, tr_Productos pProducto) {
    if (*lista == NULL) {
        printf("La lista está vacía.\n");
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
        printf("El elemento no está presente en la lista.\n");
        return;
    }

    prev->sig = aux->sig;
    if (aux->sig != NULL) {
        aux->sig->ant = prev;
    }
    free(aux);
}

void visualizarListas(t_ListaProducto *lista) {
    printf("Lista: ");
    while (lista != NULL) {
        printf("%d ", lista->producto);
        lista = lista->sig;
    }
    printf("\n");
}

