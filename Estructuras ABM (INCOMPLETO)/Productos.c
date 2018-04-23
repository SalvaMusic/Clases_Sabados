#include <stdio.h>
#include "Productos.h"

eProducto pedirProducto()
{
    char descripcion [20];
    int cantidad;
    float precio;

    printf("Ingrese nombre del producto: ");
    fflush(stdin);
    scanf("%s", descripcion);
    printf("Ingrese cantidad del producto: ");
    scanf("%d", &cantidad);
    printf("Ingrese precio del producto: ");
    scanf("%2f", &precio);

}
/*
int ingresarProductoEnLista(eProducto[], int);
{

    return 0;
}
*/
int buscarLibre( arrayeProducto[], int tam)
{
    int index = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(!eProducto[i].idProducto)
        {
            index = i;
            break;
        }
    }
    return index;
}

