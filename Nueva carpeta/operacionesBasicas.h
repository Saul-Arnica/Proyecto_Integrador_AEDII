#ifndef OPERACIONES_BASICAS
#define OPERACIONES_BASICAS

#include"listasDoblementeEnlazadas.h"

#define MAX 10
#define REPETICIONES 4


//Interfaz Publica

void imprimirTitulo();
void imprimirGuardado();
void pasarMayuscula(char*);

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

void imprimirGuardado() {

    int i;
    int num_punto = 0;
    int max_punto = 3; // Número máximo de puntos a mostrar

    printf("Guardando");

    for (i = 0; i < MAX + 1; ++i) { // Modificar el número total de iteraciones
        usleep(500000); // Espera 0.5 segundos (500,000 microsegundos)

        printf("."); // Muestra un punto
        fflush(stdout); // Limpia el búfer y muestra inmediatamente en la consola

        ++num_punto;
        if (num_punto > max_punto) {
            for (int j = 0; j < max_punto + 1; ++j) { // Borra solo los puntos impresos
                printf("\b \b"); // Borra un punto
                fflush(stdout);
            }

            num_punto = 0; // Restablece la cuenta de puntos
        }
    }

    printf("\nGuardado completo.\n");
}

void pasarMayuscula(char *nombreProducto) {
	int i;
    for(i = 0; nombreProducto[i]; i++){
        nombreProducto[i] = toupper(nombreProducto[i]);
    }
}

#endif
