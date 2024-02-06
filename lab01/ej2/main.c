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


int array_from_stdin(int array[], unsigned int max_size) {
  unsigned int i=0;

    printf("Valor del largo\t");
    fscanf(stdin,"%u",&max_size);

    printf("Recordar apretar CTRL+D (Linux) o CTRL+Z (Windows)\n"
            "para enviar la señal de EOF \n");
 while (!feof(stdin)){
    printf("Valor del lugar %u\t",i);
    fscanf(stdin,"%d",&array[i]);
    i=i+1;
 }
   
  return max_size;
}
             
void array_dump(int a[],unsigned int length) {
   unsigned int j=0;
    printf("[");
    for(j=0;j<length;j++){
        printf("%d",a[j]);
        printf(" ");
    }
    printf("]");
}


int main() {
    
    int array[MAX_SIZE];
    
    unsigned int length = array_from_stdin(array, MAX_SIZE);
    
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
