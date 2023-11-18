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
    struct producto *ant;
}t_Producto;

//Prototipado de funciones

void inicializarLista(t_Producto**);
bool listaVacia(t_Producto*);
void insproductoV1(t_Producto**, tr_Productos);
void insproductoV2(t_Producto**, tr_Productos);
void insproductoPosk(t_Producto**, tr_Productos, int);
void elimproducto(t_Producto**);
void elimproductoPosk(t_Producto**, int);
void visualizarLista(t_Producto**);
//Implementacion de las funciones 

void inicializarLista(t_Producto **v_Lista) {
    *v_Lista = NULL;
}

bool listaVacia(t_Producto *vP_Lista) {
    return vP_Lista == NULL;
}
//Funcion para instartar un producto de forma ordenada en la lista.
void insproducto(t_Producto **v_Lista, tr_Productos pProducto) {
    t_Producto *nuevoProducto, *productoActual; // creamos el nuevo nodo y un auxiliar para el actual.
    nuevoProducto =(t_Producto*)malloc(sizeof(t_Producto));// asignamos memoria
    nuevoProducto->producto = pProducto; //cargamos el producto
    productoActual = *v_Lista; //Al actual lo igualamos al ultimo 
    //Nos colocamos el inicio de la lista.
    if(productoActual != NULL) {
        while(productoActual->ant != NULL) {
            productoActual = productoActual->ant;
        }
    }
    //Si la lista esta vacia o el primer producto/elemento es mayor que el nuevo entonces asignamos.
    if(productoActual == NULL || productoActual->producto.precioUnit < pProducto.precioUnit) {
        nuevoProducto->sig = productoActual;
        nuevoProducto->ant = NULL;

        if(productoActual == NULL) {
            productoActual->ant = nuevoProducto;
        }

        if(*v_Lista != NULL) {
            *v_Lista = nuevoProducto;
        }

    }else{

        while(productoActual->sig && productoActual->sig->producto.precioUnit <= pProducto.precioUnit) {
            productoActual = productoActual->sig;
        }
        // Insertamos el nuevo nodo después del nodo anterior */
        nuevoProducto->sig = productoActual->sig;
        productoActual->sig = nuevoProducto;
        nuevoProducto->ant = productoActual;

        if(nuevoProducto->sig != NULL) {
            nuevoProducto->sig->ant = nuevoProducto;
        }

    }
}
//Esta funcion ingresa un producto nuevo al final de la lista. 
void insproductoV2(t_Producto **v_Lista, tr_Productos pProducto) {
    t_Producto *nuevoProducto;
    t_Producto *aux;
    aux = *v_Lista;
    nuevoProducto = (t_Producto*)malloc(sizeof(t_Producto));
    nuevoProducto->producto = pProducto;
    nuevoProducto->sig = NULL;
    if(!listaVacia(*v_Lista)) {
        while(aux->sig != NULL) {
        aux = aux->sig;
        }
    aux->sig = nuevoProducto;
    nuevoProducto->ant = aux;
    }else{
        *v_Lista = nuevoProducto;
        nuevoProducto->ant = NULL;
    }
}

void insproductoPosk(t_Producto **v_Lista, tr_Productos pProducto, int pos) {
    t_Producto *aux;
    t_Producto *nuevoProducto;
    int i;
    aux = *v_Lista;
    if(pos == 0) {
        nuevoProducto = (t_Producto*)malloc(sizeof(t_Producto));
        nuevoProducto->producto = pProducto;
        nuevoProducto->sig = aux;

        if(aux != NULL) {
            aux->ant = nuevoProducto;
        }
        *v_Lista = nuevoProducto;
    }else{
        for(i=0; i<pos && aux != NULL; i++) {
            aux = aux->sig;
        }
        if(aux != NULL) {
            nuevoProducto = (t_Producto*)malloc(sizeof(t_Producto));
            nuevoProducto->producto = pProducto;
            nuevoProducto->sig = aux->sig;
            nuevoProducto->ant = aux;
            if(aux->sig != NULL) {
                aux->sig->ant = nuevoProducto;
            }
            aux->sig = nuevoProducto;
        }else{
            printf("La posición es mayor que la longitud de la lista.\n");
        }
    }
}

void elimproducto(t_Producto **v_Lista) {
    if(!listaVacia(*v_Lista)) {
        t_Producto *productoSuprimir;
        productoSuprimir = *v_Lista;
        *v_Lista = productoSuprimir->sig;
        if(*v_Lista != NULL) {
            (*v_Lista)->ant = NULL;
        }
        printf("Se elimino el producto:%s...\n", productoSuprimir->producto.nombreProduct);
        free(productoSuprimir);
        productoSuprimir = NULL;
    } else {
        printf("No hay productos!....\n");
    }
}


void elimproductoPosk(t_Producto **v_Lista, int pos) {
    int i;
	if(!listaVacia(*v_Lista)) {
		if(pos == 1) {
			elimproducto(&(*v_Lista));
		}else{
			t_Producto *aux;
			t_Producto *productoSuprimir;
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

void visualizarLista(t_Producto **v_Lista) {
	t_Producto *aux;
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