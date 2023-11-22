
// switch(opc) {
//                 case 1:{
//                     strcpy(pProducto->producto.nombreProduct , ingresarNombreProducto(pNombreProduc));
//                     pProducto = buscarProducto(v_Lista1, pProducto->producto.nombreProduct);
//                     imprimirProducto(pProducto);
//                     break;

//                 }
//                 case 2:{  

//                     strcpy(pProducto->producto.nombreProduct , ingresarNombreProducto(pNombreProduc));
//                     pProducto = buscarProducto(v_Lista2, pProducto->producto.nombreProduct);
//                     if(pProducto == NULL) {
//                         printf("No se encontro\n");
//                     }else{ 
//                         printf("El producto buscado es: %d %s %.2f %d \n", pProducto->producto.codProducto, pProducto->producto.nombreProduct,
//                                                                             pProducto->producto.precioUnit, pProducto->producto.cantTtal);
//                     }
//                     break;

//                 }
//                 case 3:{    

//                     strcpy(pProducto->producto.nombreProduct , ingresarNombreProducto(pNombreProduc));
//                     pProducto = buscarProducto(v_Lista3, pProducto->producto.nombreProduct);
//                     if(pProducto == NULL) {
//                         printf("No se encontro\n");
//                     }else{ 
//                         printf("El producto buscado es: %d %s %.2f %d \n", pProducto->producto.codProducto, pProducto->producto.nombreProduct,
//                                                                             pProducto->producto.precioUnit, pProducto->producto.cantTtal);
//                     }
//                     break;

//                 }
//                 case 4:{    

//                     strcpy(pProducto->producto.nombreProduct , ingresarNombreProducto(pNombreProduc));
//                     pProducto = buscarProducto(v_Lista4, pProducto->producto.nombreProduct);
//                     if(pProducto == NULL) {
//                         printf("No se encontro\n");
//                     }else{ 
//                         printf("El producto buscado es: %d %s %.2f %d \n", pProducto->producto.codProducto, pProducto->producto.nombreProduct,
//                                                                             pProducto->producto.precioUnit, pProducto->producto.cantTtal);
//                     }
//                     break;

//                 }
//             }



// void imprimirProducto(t_ListaProducto *pProducto) {
//     if(pProducto == NULL) {
//         printf("No se encontro\n");
//     }else{ 
//         printf("\tLos productos con esa descripcion son:\n");
//         printf("| COD PRODUCTO | NOMB PRODUCTO | PRECIO UNITARIO | CANT TOTAL |\n");
//         printf("| %d | %s | %.2f | %d |\n", pProducto->producto.codProducto, pProducto->producto.nombreProduct,
//                                                             pProducto->producto.precioUnit, pProducto->producto.cantTtal);
//     }

// } */