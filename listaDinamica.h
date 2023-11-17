/*Escribir un TDA para cargar y mostrar los elementos de una lista dinámica, en donde el nodo tenga un 
campo identificador de tipo entero y un campo descripción de tipo cadena de caracteres.
Luego desarrolle un programa para probar dicho TDA.*/

#ifndef LISTA_DINAMICA_H /* ->se utiliza en C y C++ para crear bloques condicionales de compilación*/
#define LISTA_DINAMICA_H    /*Evitan la inclusión repetida de código en un archivo de encabezado*/
#include<stdlib.h>          /*garantizar que el código solo se incluya una vez en un programa*/
#include<stdio.h>
#include<stdbool.h>
#define MAX_CHAR 25

//Tipos de datos compuestos

typedef char tString[MAX_CHAR];
typedef struct {
    int identificador;
    tString descripcion;
}tr_Datos;
typedef struct Nodo {
    tr_Datos datos;
    struct Nodo *sig;
}t_Lista;

//Prototipado de funciones

void inicializarLista(t_Lista**);
bool listaVacia(t_Lista*);
void insNodo(t_Lista**, tr_Datos);
void insNodoPosk(t_Lista**, tr_Datos, int);
void elimNodo(t_Lista**);
void elimNodoPosk(t_Lista**, int);
void visualizarLista(t_Lista**);
//Implementacion de las funciones 

void inicializarLista(t_Lista **v_Lista) {
    *v_Lista = NULL;
}

bool listaVacia(t_Lista *vP_Lista) {
    return vP_Lista == NULL;
}

void insNodo(t_Lista **v_Lista, tr_Datos pDato) {
    t_Lista *nuevoNodo;
    nuevoNodo = (t_Lista*)malloc(sizeof(t_Lista));
    nuevoNodo->datos = pDato;
    if(!listaVacia(*v_Lista)) {
        nuevoNodo->sig = NULL;
    }else{
        nuevoNodo->sig = *v_Lista;
    }
    *v_Lista = nuevoNodo;
}

void insNodoPosk(t_Lista **v_Lista, tr_Datos pDato, int pos) {
    t_Lista *aux;
    t_Lista *nuevoNodo;
    int i;
    aux = *v_Lista;
    for(i=0;i<pos;i++) {
        aux = aux->sig;
    }
    nuevoNodo = (t_Lista*)malloc(sizeof(t_Lista));
    nuevoNodo->datos = pDato;
    nuevoNodo->sig = aux->sig;
    aux->sig = nuevoNodo;
}

void elimNodo(t_Lista **v_Lista) {
    if(!listaVacia(*v_Lista)) {
        t_Lista *nodoSuprimir;
        nodoSuprimir = *v_Lista;
        *v_Lista = nodoSuprimir->sig;
        printf("Se elimino el producto:%s ...\n", nodoSuprimir->datos.descripcion);
        free(nodoSuprimir);
        nodoSuprimir = NULL;
    }else{
        printf("No hay productos!....\n");
    }
}

void elimNodoPosk(t_Lista **v_Lista, int pos) {
    int i;
	if(!listaVacia(*v_Lista)) {
		if(pos == 1) {
			elimNodo(&(*v_Lista));
		}else{
			t_Lista *aux;
			t_Lista *nodoSuprimir;
			aux = *v_Lista;
			for(i=1;i<pos-1;i++) {
				aux = aux->sig;
			}
			nodoSuprimir = aux->sig;
			aux->sig = nodoSuprimir->sig;
			printf("Se elimino %s en la posicion %d!...\n", nodoSuprimir->datos.descripcion, pos);
			free(nodoSuprimir);
			nodoSuprimir = NULL;
		}
	}else{
		printf("No hay productos!...\n");
	}
}

void visualizarLista(t_Lista **v_Lista) {
	t_Lista *aux;
	aux = *v_Lista;
	if(!listaVacia(aux)) {
		printf("|Codigo de Producto | Descripcion |\n");
		while(aux != NULL) {
			printf("|\t%d \t    | \t %s \t  |\n", aux->datos.identificador, aux->datos.descripcion);
			aux = aux->sig;
		}
		printf("\n");
	}else{
		printf("Lista sin productos\n");
	}
}
#endif