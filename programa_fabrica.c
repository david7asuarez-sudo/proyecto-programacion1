
#include <stdio.h>
#include <string.h>

#define MAX 100

char nombres[MAX][50];
int cantidades[MAX];
float tiempos[MAX];
float recursos[MAX];
int totalProductos = 0;

void agregarProducto() {
    printf("\nNombre del producto: ");
    scanf("%s", nombres[totalProductos]);

    printf("Cantidad demandada: ");
    scanf("%d", &cantidades[totalProductos]);

    printf("Tiempo de fabricacion por unidad: ");
    scanf("%f", &tiempos[totalProductos]);

    printf("Recursos por unidad: ");
    scanf("%f", &recursos[totalProductos]);

    totalProductos++;

    printf("\nProducto agregado correctamente.\n");
}

void mostrarProductos() {
    int i;

    printf("\nLISTA DE PRODUCTOS\n");

    for(i = 0; i < totalProductos; i++) {
        printf("\nProducto %d\n", i + 1);
        printf("Nombre: %s\n", nombres[i]);
        printf("Cantidad: %d\n", cantidades[i]);
        printf("Tiempo: %.2f\n", tiempos[i]);
        printf("Recursos: %.2f\n", recursos[i]);
    }
}

void editarProducto() {
    char buscar[50];
    int i;

    printf("\nIngrese el nombre del producto a editar: ");
    scanf("%s", buscar);

    for(i = 0; i < totalProductos; i++) {
        if(strcmp(buscar, nombres[i]) == 0) {

            printf("Nuevo nombre: ");
            scanf("%s", nombres[i]);

            printf("Nueva cantidad: ");
            scanf("%d", &cantidades[i]);

            printf("Nuevo tiempo: ");
            scanf("%f", &tiempos[i]);

            printf("Nuevos recursos: ");
            scanf("%f", &recursos[i]);

            printf("\nProducto editado correctamente.\n");
            return;
        }
    }

    printf("\nProducto no encontrado.\n");
}

void eliminarProducto() {
    char buscar[50];
    int i, j;

    printf("\nIngrese el nombre del producto a eliminar: ");
    scanf("%s", buscar);

    for(i = 0; i < totalProductos; i++) {
        if(strcmp(buscar, nombres[i]) == 0) {

            for(j = i; j < totalProductos - 1; j++) {
                strcpy(nombres[j], nombres[j + 1]);
                cantidades[j] = cantidades[j + 1];
                tiempos[j] = tiempos[j + 1];
                recursos[j] = recursos[j + 1];
            }

            totalProductos--;

            printf("\nProducto eliminado correctamente.\n");
            return;
        }
    }

    printf("\nProducto no encontrado.\n");
}

void calcularProduccion() {
    int i;
    float totalTiempo = 0;
    float totalRecursos = 0;

    float tiempoDisponible;
    float recursosDisponibles;

    for(i = 0; i < totalProductos; i++) {
        totalTiempo += cantidades[i] * tiempos[i];
        totalRecursos += cantidades[i] * recursos[i];
    }

    printf("\nTiempo total requerido: %.2f\n", totalTiempo);
    printf("Recursos totales requeridos: %.2f\n", totalRecursos);

    printf("\nIngrese tiempo disponible: ");
    scanf("%f", &tiempoDisponible);

    printf("Ingrese recursos disponibles: ");
    scanf("%f", &recursosDisponibles);

    if(totalTiempo <= tiempoDisponible && totalRecursos <= recursosDisponibles) {
        printf("\nLa fabrica SI puede cumplir con la demanda.\n");
    } else {
        printf("\nLa fabrica NO puede cumplir con la demanda.\n");
    }
}

int main() {

    int opcion;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Editar producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Calcular produccion\n");
        printf("6. Salir\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {

            case 1:
                agregarProducto();
                break;

            case 2:
                mostrarProductos();
                break;

            case 3:
                editarProducto();
                break;

            case 4:
                eliminarProducto();
                break;

            case 5:
                calcularProduccion();
                break;

            case 6:
                printf("\nSaliendo del programa...\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
        }

    } while(opcion != 6);

    return 0;
}
