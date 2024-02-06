#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"
#include "weather_utils.h"

void print_help(char *program_name) {
    printf("Usage: %s <input file path>\n\n"
           "Load climate data from a given file in disk.\n"
           "\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           "<year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>\n\n"
           "Those elements must be integers and will be copied into the multidimensional integer array 'a'.\n"
           "The dimensions of the array are given by the macro tclimate.\n"
           "\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;
    int a[YEARS];
    int b[MONTHS];

    filepath = parse_filepath(argc, argv);

    WeatherTable array;

    array_from_file(array, filepath);

   // array_dump(array);

    printf("Minima historica %d\n",historical_minimum(array));

    printf("\n");printf("\n");

    max_for_year(array,a);
    for(unsigned int h=0; h<YEARS; h++){
        printf("%d\t",a[h]);
    }

    printf("\n");printf("\n");

    month_rainfall(array,b);
    for(unsigned int j=0; j<MONTHS; j++){
        printf("%d\t",a[j]);
    }

    return (EXIT_SUCCESS);
}
