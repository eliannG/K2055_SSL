#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gramatica.h"

Gramatica* crear_gramatica() {
    Gramatica* g = (Gramatica*) malloc(sizeof(Gramatica));

    g->terminales = NULL;
    g->no_terminales = NULL;
    g->axioma = '\0';
    g->producciones = NULL;

    return g;
}

void ingresar_gramatica(Gramatica* g) {
    char buffer[100];

    printf("ingrese lña gramática\n");

    printf("ingrese los simbolos terminales: ");
    scanf("%s", buffer);
    g->terminales = (char*) malloc(strlen(buffer) + 1);
    strcpy(g->terminales, buffer);

    printf("ingrese los símbolos no terminales en mayúscula: ");
    scanf("%s", buffer);
    g->no_terminales = (char*) malloc(strlen(buffer) + 1);
    strcpy(g->no_terminales, buffer);

    printf("ingrese el símbolo inicial o axioma: ");
    scanf(" %c", &g->axioma);
    
    while(getchar() != '\n'); 

    printf("ingrese una produccion:\n");
    NodoProduccion* ultimo_nodo = NULL;

    while (1) {
        printf("producción: ");
        scanf("%99[^\n]", buffer);
        
        while(getchar() != '\n');

        if (strcmp(buffer, "fin") == 0) {
            break;
        }

        NodoProduccion* nuevo_nodo = (NodoProduccion*) malloc(sizeof(NodoProduccion));
        nuevo_nodo->no_terminal_izquierdo = buffer[0];
        
        nuevo_nodo->lado_derecho = (char*) malloc(strlen(buffer) - 2);
        strcpy(nuevo_nodo->lado_derecho, &buffer[3]);
        
        nuevo_nodo->siguiente = NULL;

        if (g->producciones == NULL) {
            g->producciones = nuevo_nodo;
        } else {
            ultimo_nodo->siguiente = nuevo_nodo;
        }
        ultimo_nodo = nuevo_nodo;
    }
}

void mostrar_gramatica(const Gramatica* g) {
    printf("terminales:    {%s}\n", g->terminales);
    printf("no Terminales: {%s}\n", g->no_terminales);
    printf("axioma:        %c\n", g->axioma);
    printf("producciones:\n");

    NodoProduccion* actual = g->producciones;
    while (actual != NULL) {
        printf("\t%c -> %s\n", actual->no_terminal_izquierdo, actual->lado_derecho);
        actual = actual->siguiente;
    }
}

void liberar_gramatica(Gramatica* g) {
    if (g == NULL) return;

    free(g->terminales);
    free(g->no_terminales);

    NodoProduccion* actual = g->producciones;
    while (actual != NULL) {
        NodoProduccion* siguiente = actual->siguiente;
        
        free(actual->lado_derecho);
        free(actual);
        
        actual = siguiente;
    }

    free(g);
}

int es_regular(const Gramatica* g) {
    NodoProduccion* actual = g->producciones;

    while (actual != NULL) {
        int longitud = strlen(actual->lado_derecho);

        if (longitud == 1) {
            if (strchr(g->terminales, actual->lado_derecho[0]) == NULL) {
                return 0; 
            }
        } else if (longitud == 2) {
            if (strchr(g->terminales, actual->lado_derecho[0]) == NULL ||
                strchr(g->no_terminales, actual->lado_derecho[1]) == NULL) {
                return 0; 
            }
        } else {
            return 0;
        }
        actual = actual->siguiente;
    }}
    return 1; 
}
