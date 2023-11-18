#ifndef LISTA_DINAMICA_H /* -> Se utiliza en C y C++ para crear bloques condicionales de compilación*/
#define LISTA_DINAMICA_H       /*Evitan la inclusión repetida de código en un archivo de encabezado*/
#include<stdio.h>                /*garantiza que el código solo se incluya una vez en un programa*/
#include<stdlib.h>          
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define MAX_CHAR 50

//Tipos de producto compuestos

typedef char tString[MAX_CHAR];
typedef struct {
    int codProducto;
    tString nombreProduct;
    float precioUnit;
    int cantTtal;
    float precioTtal;
}tr_Productos;
typedef struct producto {
    tr_Productos producto;
    struct producto *sig;
}t_Lista;

//Prototipado de funciones

void inicializarLista(t_Lista**);
bool listaVacia(t_Lista*);
void insproducto(t_Lista**, tr_Productos);
void insproductoPosk(t_Lista**, tr_Productos, int);
void elimproducto(t_Lista**);
void elimproductoPosk(t_Lista**, int);
void visualizarLista(t_Lista**);
//Implementacion de las funciones 

void inicializarLista(t_Lista **v_Lista) {
    *v_Lista = NULL;
}

bool listaVacia(t_Lista *vP_Lista) {
    return vP_Lista == NULL;
}

void insproducto(t_Lista **v_Lista, tr_Productos pProducto) {
    t_Lista *nuevoProducto;
    nuevoProducto = (t_Lista*)malloc(sizeof(t_Lista));
    nuevoProducto->producto = pProducto;
    if(!listaVacia(*v_Lista)) {
        nuevoProducto->sig = NULL;
    }else{
        nuevoProducto->sig = *v_Lista;
    }
    *v_Lista = nuevoProducto;
}

void insproductoPosk(t_Lista **v_Lista, tr_Productos pProducto, int pos) {
    t_Lista *aux;
    t_Lista *nuevoProducto;
    int i;
    aux = *v_Lista;
    for(i=0;i<pos;i++) {
        aux = aux->sig;
    }
    nuevoProducto = (t_Lista*)malloc(sizeof(t_Lista));
    nuevoProducto->producto = pProducto;
    nuevoProducto->sig = aux->sig;
    aux->sig = nuevoProducto;
}

void elimproducto(t_Lista **v_Lista) {
    if(!listaVacia(*v_Lista)) {
        t_Lista *productoSuprimir;
        productoSuprimir = *v_Lista;
        *v_Lista = productoSuprimir->sig;
        printf("Se elimino el producto:%s ...\n", productoSuprimir->producto.nombreProduct);
        free(productoSuprimir);
        productoSuprimir = NULL;
    }else{
        printf("No hay productos!....\n");
    }
}

void elimproductoPosk(t_Lista **v_Lista, int pos) {
    int i;
	if(!listaVacia(*v_Lista)) {
		if(pos == 1) {
			elimproducto(&(*v_Lista));
		}else{
			t_Lista *aux;
			t_Lista *productoSuprimir;
			aux = *v_Lista;
			for(i=1;i<pos-1;i++) {
				aux = aux->sig;
			}
			productoSuprimir = aux->sig;
			aux->sig = productoSuprimir->sig;
			printf("Se elimino %s en la posicion %d!...\n", productoSuprimir->producto.nombreProduct, pos);
			free(productoSuprimir);
			productoSuprimir = NULL;
		}
	}else{
		printf("No hay productos!...\n");
	}
}

void visualizarLista(t_Lista **v_Lista) {
	t_Lista *aux;
	aux = *v_Lista;
	if(!listaVacia(aux)) {
		printf("| Codigo de Producto | Descripcion |\n");
		while(aux != NULL) {
			printf("|\t%d \t    | \t %s \t  |\n", aux->producto.codProducto, aux->producto.nombreProduct);
			aux = aux->sig;
		}
		printf("\n");
	}else{
		printf("Lista sin productos\n");
	}
}
#endif