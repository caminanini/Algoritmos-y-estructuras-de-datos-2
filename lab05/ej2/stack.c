#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"
#define CAPACITY 20

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

//Agregar a las ops
/*bool invrep (stack s){
    bool b = s!= NULL;
    b= b && s->elems != NULL;
    b= b && s->size != 0 && s->capacity >= s->size;
    return b;
}*/

//Revisar representación de vacio
stack stack_empty() {
    stack s = malloc(sizeof(struct _s_stack));
    if (s == NULL) {
        printf("ERROR: Fallo de malloc()");
        exit(EXIT_FAILURE);
    }

    s->capacity = CAPACITY;
    s->elems = calloc(s->capacity, sizeof(stack_elem));
    if (s->elems == NULL) {
        printf("ERROR: Fallo de calloc()");
        exit(EXIT_FAILURE);
    }
    else{
        s->elems = 0;
    }
    s->size = 0;
    assert(s!=NULL && s->elems!=NULL);
    //invrep (stack s)
    return s;
}


stack stack_push(stack s, stack_elem e){
  if (s->size < s->capacity) {
        s->elems[s->size] = e;
        s->size = s->size + 1;
    } else {
        s->capacity = s->capacity * 2;
        stack_elem* new_elems = realloc(s->elems, s->capacity * sizeof(stack_elem));
        if (new_elems == NULL) {
            printf("ERROR: Fallo de realloc()");
            exit(EXIT_FAILURE);
        }
        s->elems = new_elems;
        s->elems[s->size] = e;
        s->size = s->size + 1;
    }
    return s;
}

stack stack_pop(stack s){
   assert(s->size > 0 && s->elems!=NULL);
    s->size=s->size-1;
    return s;
}

unsigned int stack_size(stack s){
    return s->size;
}

stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    return s->elems[0];
}

bool stack_is_empty(stack s){
    return s->size == 0 && s->elems!=NULL;
}

stack_elem *stack_to_array(stack s){
    if (s->size == 0) {
        return NULL;
    }
    stack_elem *arr = malloc(sizeof(stack_elem) * s->size);
    unsigned int i=0u;
    while (i < s->size) {
        arr[i] = s->elems[s->size - 1 - i]; 
        i++;
    }
    return arr;
}

stack stack_destroy(stack s){
    //invrep (stack s)
    free(s->elems);
    free(s);
    return s;
}