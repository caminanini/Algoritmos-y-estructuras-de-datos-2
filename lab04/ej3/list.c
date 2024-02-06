#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "list.h"

struct node {
    list_elem elem;
    list next;
};

list empty(){
    return NULL;
}

list addl (list_elem e, list l){
    list p = malloc(sizeof(struct s_node));
    p->elem=e;
    p->next=l;
    return p;
}

list destroy (list l){
  if(l != NULL) {
    list a, b;
    a = l;
    b = a->next;
    while(a != NULL) {
      free(a);
      a = b;
      if(a != NULL) {
        b = a->next;
      }
    }
    l = a;
  }
  return l;
}

bool is_empty(list l){
    return (NULL==l);
}

list_elem head(list l){
 assert(!is_empty(l));
    return l->elem;
}

list tail(list l) {
    assert(!is_empty(l));
    list p = l;
    p = p->next;
    return p;
}

//VER
list addr (list l,list_elem e){
list n = malloc(sizeof(struct s_node));
  n->elem = e;
  n->next = NULL;
  if(l != NULL) {
    list i;
    i = l;
    while(i->next != NULL) {
      i = i->next;
    }
    i->next = n;
  } else {
    l = n;
  }

  return l;
}

list_elem length(list l){
    list_elem k=0;
    list p=l;
    while(p != NULL){
        k=k+1;
        p=p->next;
    }
    return k;
}

//VER
list concat(list l1, list l2) {
  list res = empty();
  list p = l1;
  while(p->next !=NULL) {
    addr(res, p->elem);
  }
  list q = l2;
  while(q->next !=NULL) {
    addr(res, q->elem);
  }
  return res;
}


list_elem index(list l,list_elem n){
    assert(length(l) > n);
    list p=l;
    for(int i=0;i<n;i++){
        p=p->next;
    }
    return p->elem;
}

//VER
list take(list l,list_elem n){
    list p=l,q;
    for(unsigned int i=0u;i<n;i++){
        p=p->next;
    }
    q=p;
    free(p);
    q=NULL;
    return l;
}

//VER
list drop(list l,list_elem n){
      assert(n<=length(l));
  while(n>0) {
    l = l->next;
    n--;
  }

  return l;
}

list copy_list(list l){
    unsigned int ln = length(l);
    list p = l , aux;
    aux = empty();
    for(unsigned int i=0u; i< ln; i++) {
        aux = addr(aux, p->elem);
  }
  return aux;
}