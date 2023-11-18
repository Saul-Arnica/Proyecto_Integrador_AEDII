#include"listaDoblementeEnlazada.h"

//Tipos de datos compuestos


//Prototipado de funciones

void menu();
void ingresarProducto();
void inicializarListas();
//Variables globales

FILE *stockAlimentos, *stockBebidas, *stockHigiene, *stockLimpeza;
int codCampAnterior;
t_Producto *alimentos, *bebidas, *cuidadoPersonal, *limpieza;
//Funcion Principal  
int main() {
    inicializarListas();

return 0;
}
//Implementacion
void inicializarListas() {
    inicializarLista(&alimentos); 
    inicializarLista(&bebidas);  
    inicializarLista(&cuidadoPersonal); 
    inicializarLista(&limpieza);
    printf("Se inicializaron las categorias! Listas para gestionar el stock!...\n");
}
void menu() {

}
void ingresarProducto() {

}

/*conclase.net*//*gits.github.com*/
//esto pisa lo de arriba, para moverme debo hacerlo mas dinamico,
//al ingresar el producto y elegir el codProducto que 
//ahi se empiece a mover
