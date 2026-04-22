#include <stdio.h>
#include <string.h>

char nombres[10][50]; 
float precios[10];    
int cantidad = 0; 

void ingresarProducto();
void calcularTotal();
void mostrarExtremos();
void calcularPromedio();
void buscarPorNombre();

int main() {
    int opcion;

    do {
        printf("\n--- GESTION DE TIENDA ---\n");
        printf("1. Ingresar Producto\n");
        printf("2. Calcular Total\n");
        printf("3. Ver Mas Caro y Barato\n");
        printf("4. Calcular Promedio\n");
        printf("5. Buscar Producto\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: ingresarProducto(); break;
            case 2: calcularTotal(); break;
            case 3: mostrarExtremos(); break;
            case 4: calcularPromedio(); break;
            case 5: buscarPorNombre(); break;
            case 6: printf("Saliendo del programa...\n"); break;
            default: printf("Opcion no valida.\n");
        }
    } while (opcion != 6);

    return 0;
}


void ingresarProducto() {
    if (cantidad < 10) {
        printf("Ingrese el nombre del producto: ");
        scanf("%s", nombres[cantidad]);

        do {
            printf("Ingrese el precio: ");
            scanf("%f", &precios[cantidad]);
            
            if (precios[cantidad] < 0) {
                printf("Error: El precio no puede ser negativo. Intente de nuevo.\n");
            }
        } while (precios[cantidad] < 0); 
        cantidad++; 
        printf("Producto guardado con exito.\n");
    } else {
        printf("Error: El inventario esta lleno (maximo 10).\n");
    }
}

void calcularTotal() {
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total = total + precios[i]; 
    }
    printf("El precio total del inventario es: $%.2f\n", total);
}

void mostrarExtremos() {
    if (cantidad == 0) {
        printf("Inventario vacio.\n");
        return;
    }
    int posCaro = 0;
    int posBarato = 0;

    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > precios[posCaro]) {
            posCaro = i;
        }
        if (precios[i] < precios[posBarato]) {
            posBarato = i;
        }
    } 
    printf("Producto mas caro: %s ($%.2f)\n", nombres[posCaro], precios[posCaro]);
    printf("Producto mas barato: %s ($%.2f)\n", nombres[posBarato], precios[posBarato]);
}

void calcularPromedio() {
    if (cantidad == 0) {
        printf("No hay productos para promediar.\n");
        return;
    }
    float suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += precios[i];
    }
    printf("El precio promedio es: $%.2f\n", suma / cantidad); 
}

void buscarPorNombre() {
    char nombreBuscar[50];
    int encontrado = 0;
    printf("Ingrese el nombre a buscar: ");
    scanf("%s", nombreBuscar);

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], nombreBuscar) == 0) {
            printf("Encontrado -> Producto: %s | Precio: $%.2f\n", nombres[i], precios[i]);
            encontrado = 1;
            break;
        }
    }
    if (encontrado == 0) {
        printf("El producto '%s' no existe.\n", nombreBuscar);
    }
}