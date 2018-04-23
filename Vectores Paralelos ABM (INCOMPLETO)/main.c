#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "Productos.h"

#define T 3

int main()
{
    int idProducto[T]= {1, 2, 3};
    char descripcion[T][50]={"Coca", "Fanta", "Secco"};
    int stock[T]={10,12,50};
    float precioUnitario[T] ={10,15,21};
    int opcion;
    int posicion;

    do
    {
        printf("1. Cargar\n2. Mostrar\n3.Ordenar\n4.Modificar\n5.Bajar\n9.Salir");
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                printf("CARGO\n");

                posicion = buscarLibre(idProducto, T);
                if(posicion!=-1)
                {
                    printf("Ingrese ID: ");
                    scanf("%d", &idProducto[posicion]);
                    printf("Ingrese descripcion: ");
                    fflush(stdin);
                    scanf("%[^\n]", descripcion[posicion]);
                    //gets(descripcion[posicion-1]);
                    printf("Ingrese stock: ");
                    scanf("%d", &stock[posicion]);
                    printf("Ingrese precio unitario: ");
                    scanf("%f", &precioUnitario[posicion]);

                }
                else
                {
                    printf("No hay espacio!");
                }
                break;
            case 2:
                printf("LISTADO:\n");
                mostrarProductos(idProducto, descripcion, stock, precioUnitario, T);
                break;
            case 3:
                printf("ORDENO\n");

                ordenarProductos(idProducto, descripcion, stock, precioUnitario, T);

                break;
            case 4:
                printf("MODIFICAR\n");

                modificarProductos(idProducto,descripcion,stock,T);
                break;
            case 5:
                printf("LISTADO:\n");
                mostrarProductos(idProducto, descripcion, stock, precioUnitario, T);
                printf("BAJAR:\n");
                bajaProductos(idProducto,descripcion,stock,T);
                break;
        }

        system("pause");
        system("cls");
    }
    while(opcion!=9);

    return 0;
}

