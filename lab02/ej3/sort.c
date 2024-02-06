#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int pivot = izq; 
    unsigned int i = izq + 1;
    unsigned int j = der;
    while (i <= j) {
     //En caso de no querer usar goes_before 
     //a[i] <= a[pivot]
     //a[j] >= a[pivot]
     //a[i] > a[pivot] && a[j] < a[pivot]
        if (goes_before(a[i],a[pivot])) {
            i=i+1;
        } 
        else if (goes_before(a[pivot],a[j])) {
            j=j-1;
        } 
        else if (goes_before(a[pivot],a[i] ) && goes_before(a[j],a[pivot]) ) {
            swap(a,i,j);
        //se pueden sacar las ultimas lineas.
            i=i+1;
            j=j-1;
        }
    }
    swap(a,izq,j);
    pivot=j;
    return pivot;
}


static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
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


void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

