#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED 123
typedef struct
{
    int estado;
    int idProducto;
    char descripcion[50];
    int stock;
    float precioUnitario;

}eProducto;
#endif

int buscarLibre(arrayeProducto[], int tam);

eProducto pedirProducto();

int ingresarProductoEnLista(eProducto[], int);

int modificarProducto(eProducto[], int, int);

int borrarProducto(eProducto[], int, int);

void mostrarListaDeProductos(eProducto[], int);

void mostrarUnProducto(eProducto);

void ordenarProductos(eProducto[], int);
