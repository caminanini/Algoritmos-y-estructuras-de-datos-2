/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
     if(x->tournaments < y->tournaments){
        return false;
     }
    return true;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void swap(player_t p[], unsigned int i, unsigned int j) {
    player_t temp = p[i];
    p[i] = p[j];
    p[j] = temp;
}


static unsigned int partition(player_t a[], unsigned int izq, unsigned int der) {
    unsigned int pivot = izq; 
    unsigned int i = izq + 1;
    unsigned int j = der;
    while (i <= j) {
        if (goes_before(a[i],a[pivot])) {
            i=i+1;
        } 
        else if (goes_before(a[pivot],a[j])) {
            j=j-1;
        } 
        else if (goes_before(a[pivot],a[i] ) && goes_before(a[j],a[pivot]) ) {
            swap(a,i,j);
        }
    }
    swap(a,izq,j);
    pivot=j;
    return pivot;
}

static void quick_sort_rec(player_t a[], unsigned int izq, unsigned int der) {
 unsigned int ppiv;
 if(der > izq){
    ppiv = partition(a,izq,der);
    if(ppiv == izq){
        quick_sort_rec (a,izq,ppiv);
    }
    else{
        quick_sort_rec (a,izq,ppiv-1);
    }
    quick_sort_rec (a,ppiv+1u,der);
}
}

void sort(player_t a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

