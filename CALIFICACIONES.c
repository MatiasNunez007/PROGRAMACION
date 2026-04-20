#include <stdio.h>

#define estudiantes 2
#define asignaturas 2
#define notas 2

int main() {
    char nombres[estudiantes][30];
    float calificaciones[estudiantes][asignaturas][notas];
    int opc = 0;
    int opc2 = 0;

    printf("=== Sistema de Calificaciones ===\n");
    printf("Registro para %d estudiantes, %d asignaturas y %d notas por asignatura\n", estudiantes, asignaturas, notas);

    for (int i = 0; i < estudiantes; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i);
        scanf("%s", nombres[i]);
    }

    for (int i = 0; i < estudiantes; i++) {
        printf("\n- Ingrese las notas de %s:\n", nombres[i]);
        for (int j = 0; j < asignaturas; j++) {
            printf("  Asignatura %d:\n", j);
            for (int k = 0; k < notas; k++) {
                do {
                    printf("\tNota %d (0-10): ", k);
                    scanf("%f", &calificaciones[i][j][k]);
                    if (calificaciones[i][j][k] < 0.0 || calificaciones[i][j][k] > 10.0) {
                        printf("\tError: La nota debe estar entre 0 y 10\n");
                    }
                } while (calificaciones[i][j][k] < 0.0 || calificaciones[i][j][k] > 10.0);
            }
        }
    }

    do {
        printf("\n--- MENU DE REPORTES ---\n");
        printf("1. Promedio y Extremos por Estudiante\n");
        printf("2. Promedio y Extremos por Asignatura\n");
        printf("3. Contador de Aprobados/Reprobados por Asignatura\n");
        printf(">> Seleccione una opcion: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1: {
                int sel;
                printf("\nSeleccione estudiante (0 a %d): ", estudiantes - 1);
                scanf("%d", &sel);

                if (sel >= 0 && sel < estudiantes) {
                    float suma = 0, notaMax = -1.0, notaMin = 11.0;
                    int totalNotas = asignaturas * notas;

                    for (int j = 0; j < asignaturas; j++) {
                        for (int k = 0; k < notas; k++) {
                            float n = calificaciones[sel][j][k];
                            suma += n;
                            if (n > notaMax) notaMax = n;
                            if (n < notaMin) notaMin = n;
                        }
                    }
                    printf("\n------------------------------------------\n");
                    printf("REPORTE: %s\t| Promedio: %.2f\n", nombres[sel], suma / totalNotas);
                    printf("Nota Mas Alta: %.2f\t| Nota Mas Baja: %.2f\n", notaMax, notaMin);
                    printf("------------------------------------------\n");
                } else printf("Estudiante no valido\n");
                break;
            }

            case 2: {
                int sel2;
                printf("\nSeleccione asignatura (0 a %d): ", asignaturas - 1);
                scanf("%d", &sel2);

                if (sel2 >= 0 && sel2 < asignaturas) {
                    float suma2 = 0, notaMax2 = -1.0, notaMin2 = 11.0;
                    for (int i = 0; i < estudiantes; i++) {
                        for (int k = 0; k < notas; k++) {
                            float n = calificaciones[i][sel2][k];
                            suma2 += n;
                            if (n > notaMax2) notaMax2 = n;
                            if (n < notaMin2) notaMin2 = n;
                        }
                    }
                    printf("\n------------------------------------------\n");
                    printf("ASIGNATURA %d\t| Promedio: %.2f\n", sel2, suma2 / (estudiantes * notas));
                    printf("Nota Mas Alta: %.2f\t| Nota Mas Baja: %.2f\n", notaMax2, notaMin2);
                    printf("------------------------------------------\n");
                } else printf("Asignatura no valida\n");
                break;
            }

            case 3: {
                int sel3;
                printf("\nSeleccione asignatura para conteo (0 a %d): ", asignaturas - 1);
                scanf("%d", &sel3);

                if (sel3 >= 0 && sel3 < asignaturas) {
                    int aprobados = 0, reprobados = 0;
                    printf("\nDetalle de la Asignatura %d:\n", sel3);
                    for (int i = 0; i < estudiantes; i++) {
                        float sumaAlumno = 0;
                        for (int k = 0; k < notas; k++) sumaAlumno += calificaciones[i][sel3][k];
                        
                        float promAlumno = sumaAlumno / notas;
                        if (promAlumno >= 6.0) {
                            printf(" - %-15s: APROBADO (%.2f)\n", nombres[i], promAlumno);
                            aprobados++;
                        } else {
                            printf(" - %-15s: REPROBADO (%.2f)\n", nombres[i], promAlumno);
                            reprobados++;
                        }
                    }
                    printf("\n>>> TOTAL: %d Aprobados | %d Reprobados\n", aprobados, reprobados);
                } else printf("Asignatura no valida\n");
                break;
            }
            default: printf("Opcion no valida.\n");
            break;
        }

        printf("\nConsultar otro reporte? (0:si / 1:no): ");
        scanf("%d", &opc2);
    } while (opc2 == 0);

    return 0;
}