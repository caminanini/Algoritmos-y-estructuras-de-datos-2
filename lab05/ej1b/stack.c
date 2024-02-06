#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack {
    stack_elem elem;
    stack next;
    unsigned int size;
};

stack stack_empty(){
    stack s=malloc(sizeof(struct _s_stack));
    s->elem = 0;
    s->next = NULL;
    s->size = 0;
    return s;
}

stack stack_push(stack s, stack_elem e){
    stack new_node = malloc(sizeof(struct _s_stack));
    if(s->size == 0){
        new_node->elem = e;
        new_node->next = NULL;
        new_node->size = 1;
    }
    else{
        new_node->elem = e;
        new_node->next = s;
        new_node->size = s->size + 1;  
    }
    return new_node;
}

stack stack_pop(stack s){
    //revisar
    assert(!stack_is_empty(s));
    stack fst=s->next;
    fst->size=fst->size-1;
    free(s);
    return fst;
}

unsigned int stack_size(stack s){
    return s->size;
}

stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    return s->elem;
}

bool stack_is_empty(stack s){
    return s->size==0;
}

stack_elem* stack_to_array(stack s){ 
    if (s==NULL) {
        return NULL;
    }

    int size = stack_size(s);
    stack_elem* array = calloc(size,sizeof(stack_elem));
    int i = size - 1;
    stack p=s;
    while (p!=NULL) {
        array[i] = p->elem;
        p = p->next;
        i--;
    }
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