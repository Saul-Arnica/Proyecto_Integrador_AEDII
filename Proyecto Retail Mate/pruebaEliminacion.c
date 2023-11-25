#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void crearArchivo();
void cambiarNombre();
void eliminarArhivo();

FILE *archivo1, *archivo2;

int main() {
    crearArchivo();
    cambiarNombre();
    eliminarArhivo();
    return 0;
}


void crearArchivo() {
    archivo1 = fopen("prueba.dat", "wb");
    sleep(1);
    archivo2 = fopen("prueba1.dat", "wb");
    sleep(1);
    if(archivo1 == NULL && archivo2 == NULL) {
        printf("No se pudo crear el archivo");
    }
    fclose(archivo1);
    fclose(archivo2);
}
void cambiarNombre() {

    rename("prueba.dat", "nuevaPrueba.dat");
    sleep(4);
    remove("prueba1.dat");
    sleep(4);
}
void eliminarArhivo() {

}