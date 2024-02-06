#include "string.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


int main(void) {
    
    const char *str1 = "Farmacia";
    const char *str2 = "Farmacias";
    string s1 = string_create(str1);
    string s2 = string_create(str2);
    
    printf("La cadena s1 es ");
    string_dump(s1, stdout);
    printf("Y su longitud es: %u\n", string_length(s1));
    printf("La cadena s2 es ");
    string_dump(s2, stdout);
    printf("Y su longitud es: %u\n", string_length(s2));
    
    if(string_eq(s1,s2)){
        printf("La cadenas s1 y s2 son iguales\n");
    }
    else if(string_less(s1,s2)){
        printf("La cadena s1 es menor a s2\n");
    }
    else{
        printf("La cadena s1 es mayor a s2\n");
    }
    
    s1 = string_destroy(s1);
    s2 = string_destroy(s2);
    
    return EXIT_SUCCESS;
}
