#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
  unsigned int i=0;
    FILE * folder = fopen( filepath ,"r");
    fscanf(folder,"%u",&max_size);

 if (folder == NULL) {
        printf("Error: No se pudo abrir el archivo %s\n", filepath);
        return EXIT_FAILURE;
    }

 if(max_size < i ){
    printf("Error: El largo del array es negativo\n");
    return EXIT_FAILURE;
    }

 if(max_size > MAX_SIZE ){
    printf("Error: El largo del array se pasa de la cantidad permitida \n");
    return EXIT_FAILURE;
    }
 if(max_size == 0){
    printf("Error: El largo del array se pasa de la cantidad permitida \n");
    return EXIT_FAILURE;
    }

    for(i=0;i<max_size;i++){
   fscanf(folder,"%d",&array[i]);
   if (feof(folder)!=0) {
        printf("Error: largo mayor a la cantidad de elementos\n");
     return EXIT_FAILURE;
    }
 }

 fclose(folder);


  return max_size;
}


void array_dump(int a[], int unsigned length) {
    unsigned int j;
    if (length != 0){
    printf("[");
    for(j=0;j<length-1;j++){
        printf("%d",a[j]);
        printf(",");
    }
    printf("]");
    }
    else{printf("[]");}

}


int main(int argc, char *argv[]) {
    char *filepath = NULL;

    filepath = parse_filepath(argc, argv);
    
    int array[MAX_SIZE];
    
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);
    
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
