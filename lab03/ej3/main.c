#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int data_from_file(const char *path, 
                            unsigned int indexes[MAX_SIZE],
                            char letters[MAX_SIZE],
                            unsigned int max_size){                   
    FILE *file= fopen(path,"r");
    unsigned int n=0u;
     while(!feof(file) && n<max_size){
      int res = fscanf(file,"%u -> *%c* ",&indexes[n],&letters[n]);
      if(res<2){
          printf("Error de lectura (linea %d\n)",n);
          exit(EXIT_FAILURE);
      }
       n++;
     }
    fclose(file);
 return n;                            
}

unsigned int reconstruccion (char sorted[MAX_SIZE], unsigned int indexes[], 
                            char letters[],unsigned int max_size){
 unsigned int pos, pos_final;
 for(pos=0u;pos<max_size;pos++){
       pos_final=indexes[pos];
     if(pos_final>MAX_SIZE){
        return 0;
     }
     sorted[pos_final]=letters[pos];
    }
 return 1;
}

int main(int argc, char *argv[]) {
    FILE *filepath = NULL;
    unsigned int length=0; 
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    const char *path = NULL;
    if (argc < 2) {
        return EXIT_FAILURE;
    }
    else{
        path = argv[1];
    }

    filepath = fopen(path, "r");
    if (!filepath) {
        return EXIT_FAILURE;
    } 

    length = data_from_file(path,indexes,letters,MAX_SIZE);

    fclose(filepath);

    if(length > MAX_SIZE){
        printf("Error:Se paso de MAX_SIZE\n");
    }
    if (reconstruccion (sorted,indexes,letters,length)== 1){
    dump(sorted, length);
    }
    else{
        printf("Error:Hay uno o mas valores que se va a ubicar\n"
                        "por fuera del arreglo\n");
    }

    return EXIT_SUCCESS;
}
