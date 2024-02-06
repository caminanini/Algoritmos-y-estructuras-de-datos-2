#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"
#include "mybool.h" 

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
  unsigned int i=0,aux=max_size;
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

 if(max_size > aux ){
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

void array_dump(int a[], unsigned int length) {
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

mybool array_is_sorted(int a[], unsigned int length){
  unsigned int i;

  for ( i = 0 ; i < length ; i++) {
        if (a[i] <= a[i+1]) {
            return true;
        }
    }
    return false;
}