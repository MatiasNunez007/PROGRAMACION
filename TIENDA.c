#include <stdio.h>
#include <string.h>

int main() {

    int id, stock = 0;
    char nombre[20];
    float precio, ganancias = 0.0;
    int opcion;

    printf("--- REGISTRO INICIAL DEL PRODUCTO ---\n");
    printf("Ingrese ID: ");
    scanf("%d", &id);
    printf("Ingrese nombre: ");
    getchar(); 
    fgets(nombre, 20, stdin);
    nombre[strcspn(nombre, "\n")] = 0;
    printf("Ingrese stock inicial: ");
    scanf("%d", &stock);
    printf("Ingrese precio unitario: ");
    scanf("%f", &precio);

    do {
        
        printf("\n--- GESTION DE TIENDA ---\n");
        printf("1. Vender producto\n");
        printf("2. Reabastecer stock\n");
        printf("3. Consultar informacion\n");
        printf("4. Ver ganancias totales\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: { 
                int cantidad;
                float descuento = 0;
                printf("\nCantidad a vender: ");
                scanf("%d", &cantidad);

                if (cantidad > 0 && cantidad <= stock) {
                    printf("Ingrese porcentaje de descuento (0-100): ");
                    scanf("%f", &descuento);
                    
                    float precio_final = precio * (1 - (descuento / 100));
                    stock -= cantidad;
                    ganancias += (cantidad * precio_final);
                    
                    printf("Venta realizada. Total: $%.2f\n", cantidad * precio_final);
                } else if (cantidad > stock) {
                    printf("Error: Stock insuficiente (Disponible: %d)\n", stock);
                } else {
                    printf("Error: Cantidad no valida.\n");
                }
                break;
            }

            case 2: {
                int cantidad;
                printf("\nCantidad a agregar al stock: ");
                scanf("%d", &cantidad);
                if (cantidad > 0) {
                    stock += cantidad;
                    printf("Stock actualizado: %d\n", stock);
                } else {
                    printf("Error: Debe ingresar un valor positivo.\n");
                }
                break;
            }

            case 3:
                printf("\n--- DATOS DEL PRODUCTO ---\n");
                printf("ID:\t\t%d\n", id);
                printf("Nombre:\t\t%s\n", nombre);
                printf("Stock:\t\t%d unidades\n", stock);
                printf("Precio:\t\t$%.2f\n", precio);
                break;

            case 4:
                printf("\nGanancias acumuladas: $%.2f\n", ganancias);
                break;

            case 5:
                printf("Salio del programa\n");
                break;

            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 5);
    return 0;
}