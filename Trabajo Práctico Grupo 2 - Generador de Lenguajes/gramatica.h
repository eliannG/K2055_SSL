#ifndef GRAMATICA_H
#define GRAMATICA_H

typedef struct nodoProduccion {
    char no_terminal_izquierdo;
    char* lado_derecho;
    struct NodoProduccion* siguiente;
} NodoProduccion;

typedef struct {
    char* terminales;
    char* no_terminales;
    char axioma;
    NodoProduccion* producciones;
} Gramatica;

Gramatica* crear_gramatica();
void ingresar_gramatica(Gramatica* g);
void mostrar_gramatica(const Gramatica* g);
void liberar_gramatica(Gramatica* g);

#endif