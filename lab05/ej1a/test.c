# include <stdio.h>
# include <stdbool.h>
#include <stdlib.h>
# include "stack.h"

int main (){

// Verificar stack_pop() para pilas de tamaño 1
    stack s=stack_empty();
    s = stack_push(s, 1);
    s = stack_pop(s);
    if(s != NULL) {
        printf("Error en stack_pop() para pilas de tamaño 1\n");
        exit(EXIT_FAILURE);
    }

    // Verificar si puedo volver a insertar elementos en una pila vacía
    s = stack_push(s,2);
    if(stack_top(s)!= 2) {
        printf("Error al insertar elementos en una pila vacía\n");
        exit(EXIT_FAILURE);
    }
    
    // Verificar si stack_to_array() devuelve NULL para una pila vacía y si devuelve los elementos en el orden correcto
    s = stack_empty();
    stack_elem *a = stack_to_array(s);
    if(a != NULL) {
        printf("Error en stack_to_array() para una pila vacía\n");
        free(a);
        exit(EXIT_FAILURE);
    }
    s = stack_push(s, 1);
    s = stack_push(s, 2);
    s = stack_push(s, 3);
    a = stack_to_array(s);
    if(a[0] != 1 || a[1] != 2 || a[2] != 3) {
        printf("Error en el orden de los elementos en stack_to_array()\n");
        free(a);
        exit(EXIT_FAILURE);
    }
    free(a);
    
    printf("Pruebas exitosas\n");

    exit(EXIT_SUCCESS);
}