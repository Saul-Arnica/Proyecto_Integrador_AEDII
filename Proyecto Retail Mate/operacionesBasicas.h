#ifndef OPERACIONES_BASICAS
#define OPERACIONES_BASICAS

#include"listasDoblementeEnlazadas.h"

#define MAX 10
#define REPETICIONES 4


//Interfaz Publica
void imprimirInicio();
void imprimirGuardado();
void pasarMayuscula(char*);

//Interfaz Privada

#include <stdio.h>
#include <unistd.h>

#define MAX 10

void imprimirInicio() {
    int i;
    int num_punto = 0;
    int max_punto = 3; // Número máximo de puntos a mostrar
    fflush(stdout);
    printf("\t\t\t\t\t\tBienvenidos a RetailMate lo mejor para tu comercio :D\n\n");
    printf("\n\nCargando");

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

    printf("\nCargado exitoso.\n");
}


void imprimirGuardado() {

    int i;
    int num_punto = 0;
    int max_punto = 3; // Número máximo de puntos a mostrar

    printf("\n\nGuardando");

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

    printf("\n\nGuardado completo.\n");
}

void pasarMayuscula(char *nombreProducto) {
	int i;
    for(i = 0; nombreProducto[i]; i++){
        nombreProducto[i] = toupper(nombreProducto[i]);
    }
}

#endif
