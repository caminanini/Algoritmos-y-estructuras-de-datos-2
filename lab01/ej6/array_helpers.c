#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

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

void array_swap(int a[],unsigned int i, unsigned int j){
    int temp;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void change_array (int a[], unsigned int length ){
    unsigned int ind=0,nl=length-1;
    while(ind<nl){
    array_swap(a,ind,nl);
    ind=ind+1;
    nl=nl-1;
    }
}

bool array_is_sorted(int a[], unsigned int length){
  unsigned int i;
  bool res;
  for ( i = 0 ; i < length ; i++) {
            res= res && a[i] <= a[i+1];
    }
    return res;
}