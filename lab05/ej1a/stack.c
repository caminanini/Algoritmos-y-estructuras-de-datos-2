#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack {
    stack_elem elem;
    stack next;
};

stack stack_empty(){
    stack s=NULL;
    assert(s==NULL);
    return s;
}

stack stack_push(stack s, stack_elem e){
    stack add=malloc(sizeof(struct _s_stack));
    add->elem=e;
    add->next=s;
    assert(add!=NULL);
    return add;
}

stack stack_pop(stack s){
    assert(s!=NULL);
    stack fst=NULL;
    fst=s->next;
    s->next=NULL;
    free(s);
    return fst;
}

unsigned int stack_size(stack s){
    assert(s!=NULL);
    unsigned int l=0;
    stack count=s;
    while(count!=NULL){
        l++;
        count=count->next;
    }
    return l;
}

stack_elem stack_top(stack s){
    return s->elem;
}

bool stack_is_empty(stack s){
    return s==NULL;
}

stack_elem* stack_to_array(stack s){ //Devuelve un puntero a un array (stack_elem*) que contiene los elementos de la pila.
    if (s==NULL) {
        array=NULL;
    }
    int size = stack_size(s);
    stack_elem* array = calloc(size,sizeof(stack_elem));
    if(array==NULL){
        printf("Error en calloc()");
        exit(EXIT_FAILURE);
    }
    /*La función calloc() toma dos argumentos: el número de elementos que se deben asignar y el tamaño de 
    cada elemento en bytes. El valor devuelto es un puntero al primer byte del bloque de memoria asignado.*/
    int i = size-1;
    stack p=s;
    while (p!=NULL) {
        array[i] = p->elem;
        p = p->next;
        i--;
    }
    free(p);
    return array;
}

stack stack_destroy(stack s){
    stack p;
    while(s!=NULL){
        p=s;
        s=s->next;
        free(p);
    }
    assert(s==NULL);
    return s;
}