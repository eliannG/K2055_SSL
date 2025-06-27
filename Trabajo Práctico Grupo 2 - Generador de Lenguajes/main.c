#include <stdio.h>
#include <stdlib.h>
#include "gramatica.h"

int main() {
    Gramatica* g = NULL;
    int opcion;

    do {
        printf("1. Crear gramatica\n");
        printf("2. Ingresar gramatica\n");
        printf("3. Mostrar gramatica\n");
        printf("4. Verificar si es regular\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        while(getchar() != '\n'); // Limpieza de buffer

        switch(opcion) {
            case 1:
                if (g != NULL) {
                    liberar_gramatica(g);
                }
                g = crear_gramatica();
                break;

            case 2:
                    ingresar_gramatica(g);
                break;

            case 3:
                if (g == NULL) {
                    printf("Primero debe crear una gramatica.\n");
                } else {
                    mostrar_gramatica(g);
                }
                break;

            case 4:
                if (g == NULL) {
                    printf("Primero debe crear una gramatica.\n");
                } else {
                    if (es_regular(g)) {
                        printf("Es regular.\n");
                    } else {
                        printf("NO es regular.\n");
                    }
                }
                break;

            default:
                printf("Opcion no valida.\n");
        }

    } while(opcion != 5);

    if (g != NULL) liberar_gramatica(g);

    return 0;
}