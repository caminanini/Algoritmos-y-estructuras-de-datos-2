#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

int main(void) {
    char user_input[MAX_LENGTH];
    char help[MAX_LENGTH];

    printf("Ingrese su nombre y apellido: ");

    fgets(user_input, MAX_LENGTH , stdin);

    unsigned int i=0;
    while(user_input[i]!='\0'){
        if(user_input[i]!='\n'){
            help[i]=user_input[i];
        }
        i++;
    }

    printf("Te damos la bienvenida %s a este maravilloso programa!\n",help);

    return EXIT_SUCCESS;
}

