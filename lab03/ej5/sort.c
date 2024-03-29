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
     if(x.tournaments < y.tournaments){
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

static void insert(player_t a[], unsigned int i) {
    while (i>0 && goes_before(a[i],a[i-1])) {
        swap(a,i-1,i);
        i=i-1;
    }
}

void sort(player_t a[], unsigned int length) {
        for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
        }
}

