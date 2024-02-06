#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

#define MAX_SIZE 100000

void print_help(char *program_name) {
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    char *result = NULL;
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    filepath = parse_filepath(argc, argv);
    
    int array[MAX_SIZE];
    
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);
    
    array_dump(array, length);
    printf( "\n""Respondiendo a la prgunta""\n"
        "¿Por qué en la compilación con gcc no se le pasa array_helpers.h como parámetro? " "\n"
        "El archivo array_helpers.h contiene los encabezados/prototipos de las funciones," "\n"
        "entonces al incluir este archivo en el archivo main, por medio de la línea de código" "\n"
        "#include, ocurre que el compilador busca la definición de estas funciones en el archivo de ""\n"
        "encabezado incluido. Luego el último comando de gcc se encarga de conectar array_helpers.c ""\n"
        "con main.c para que de esta forma main busque las definiciones de las funciones de ""\n"
        "array_helpers.h en el array_helpers.c.\n");
    
    printf("\n");

    return EXIT_SUCCESS;
}
