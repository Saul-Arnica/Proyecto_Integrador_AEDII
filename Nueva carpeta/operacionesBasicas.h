#ifndef OPERACIONES_BASICAS
#define OPERACIONES_BASICAS

#include"listasDoblementeEnlazadas.h"

#define MAX 10
#define REPETICIONES 5


//Interfaz Publica


void pasarMayuscula(char*);
void imprimirTitulo();

//Interfaz Privada
void imprimirTitulo() {
    int i, j, rep;
    for(rep = 0; rep < REPETICIONES; rep++) {
        for(i = 0; i < MAX; i++) {
            for(j = 0; j < i; j++) printf(" ");
            printf("*");
            for(j = 0; j < MAX - i; j++) printf(" ");
            printf("Bienvenidos a RetailMate lo mejor para tu comercio :D");
            for(j = 0; j < MAX - i; j++) printf(" ");
            printf("*\n");
            usleep(100000); // Espera 0.1 segundos
            printf("\033[H\033[J"); // Limpia la pantalla
        }
    }
}

void pasarMayuscula(char *nombreProducto) {
	int i;
    for(i = 0; nombreProducto[i]; i++){
        nombreProducto[i] = toupper(nombreProducto[i]);
    }
}

#endif
