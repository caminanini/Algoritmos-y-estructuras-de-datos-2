#include <stdio.h>
#include <stdlib.h>

typedef struct _person {
    int age;
    char name_initial;
} person_t;

int main(void) {
    int x = 1;
    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};

    
    /* Al finalizar la ejecución las variables deben tener los siguientes valores
       x = 9
       m = (100, F)
       a[1] = 42
    */

    int *puntero_int = NULL;
    char *puntero_char = NULL;

    puntero_int=&x;
    *puntero_int = *puntero_int + 8;

    puntero_int=&m.age;
    *puntero_int = *puntero_int + 10;
    puntero_char=&m.name_initial;
    *puntero_char = 'F';

    puntero_int=&a[1];
    *puntero_int = 42;

    printf("x = %d\n", x);
    printf("m = (%d, %c)\n", m.age, m.name_initial);
    printf("a[1] = %d\n", a[1]);

    return EXIT_SUCCESS;
}