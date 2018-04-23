#include <stdio.h>
#include "Productos.h"
#include <string.h>

int buscarLibre(int id[], int tam)
{
    int index = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(id[i]==0)
        {
            index = i;
            break;
        }
    }
    return index;
}
void bajaProductos(int idProducto[], char descripcion [][50],int stock[],int cant)
{
    int i;
    int idUsuario;
    char continuar;
    int flag=0;

    printf("Ingrese el ID del producto: ");
    scanf("%d", &idUsuario);

    for(i=0;i<cant;i++)
    {
        if(idUsuario==idProducto[i])
        {
            printf("\nVa a dar de baja el producto '%s'. Desea continuar? (s/n): ", descripcion[i]);
            fflush(stdin);
            scanf("%c", &continuar);
            if (continuar=='s')
            {

                idProducto[i]=0;
                printf("\nDado de baja con exito\n");
            }
            else
            {
                    printf("\nOperacion cancelada\n");
            }
            flag=1;
        }

    }
    if(flag==0)
    {
        printf("\nNo se encontro el ID");
    }
}

void modificarProductos(int idProducto[], char descripcion [][50],int stock[],int cant)
{
    int i;
    int idUsuario;
    char continuar;
    int auxStock;
    int flag=0;

    printf("Ingrese el ID del producto: ");
    scanf("%d", &idUsuario);

    for(i=0;i<cant;i++)
    {
        if(idUsuario==idProducto[i])
        {
            printf("\nVa a modificar el stock de '%s'. Desea continuar? (s/n): ", descripcion[i]);
            fflush(stdin);
            scanf("%c", &continuar);
            if (continuar=='s')
            {
                printf("\nIngrese el stock: ");
                scanf("%d", &auxStock);
                printf("\ndesea guardar esta modificacion? (s/n): ");
                fflush(stdin);
                scanf("%c", &continuar);
                if (continuar=='s')
                {
                    stock[i]=auxStock;
                    printf("\nModificado con exito\n");
                }
                else
                {
                    printf("\nOperacion cancelada\n");
                }
            }
            else
            {
                printf("\nOperacion cancelada\n");
            }
            flag=1;
        }

    }
    if(flag==0)
    {
        printf("\nNo se encontro el ID");
    }
}

void mostrarProductos(int idProducto[], char descripcion[][50], int stock[], float precioUnitario[], int cant)
{
    int i;
    printf("%5s %20s %5s %s\n","id","descripcion","stock","precio");
    for(i=0; i<cant; i++)
    {
        if(idProducto[i]!=0)
        {
            printf("%5d %20s %5d %.2f\n", idProducto[i], descripcion[i], stock[i], precioUnitario[i]);
        }
    }
}

void ordenarProductos(int idProducto[], char descripcion[][50], int stock[], float precioUnitario[], int cant)
{
    int auxInt;
    float auxFloat;
    char auxString[50];
    int i;
    int j;
    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(stricmp(descripcion[i],descripcion[j])>0)
            {
                strcpy(auxString,descripcion[i]);
                strcpy(descripcion[i],descripcion[j]);
                strcpy(descripcion[j], auxString);


                auxInt = idProducto[i];
                idProducto[i]= idProducto[j];
                idProducto[j]=auxInt;


                auxInt = stock[i];
                stock[i]= stock[j];
                stock[j]=auxInt;


                auxFloat = precioUnitario[i];
                precioUnitario[i]= precioUnitario[j];
                precioUnitario[j]=auxFloat;


            }
        }
    }




}

