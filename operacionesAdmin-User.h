#include"listaDoblementeEnlazada.h"
//Interfaz Publica
t_Producto *buscarProducto(t_Producto**, const char*); //Buscamos de 
void cargarProducto(t_Producto**, tr_Productos);
void ingresarProducto(t_Producto**, tr_Productos);
void modificarProducto(t_Producto**, int, tr_Productos);
void pasarMayuscula(char*);