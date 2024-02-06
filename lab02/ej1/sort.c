#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "sort_helpers.h"


static void insert(int a[], unsigned int i) {
    while (i>0 && goes_before(a[i],a[i-1])) {
        swap(a,i-1,i);
        i=i-1;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
    //assert(array_is_sorted(a,i));
        insert(a, i);
        assert(array_is_sorted(a,i));
    }
}
