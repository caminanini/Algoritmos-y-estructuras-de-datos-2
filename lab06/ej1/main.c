/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "abb.h" /* TAD abb */


void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

abb abb_from_file(const char *filepath) {
    FILE *file = NULL;
    abb read_tree;

    read_tree = abb_empty();
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0u;
    unsigned int size = 0u;
    int res = 0;
    res = fscanf(file, " %u ", &size);
    if (res != 1) {
        fprintf(stderr, "Invalid format.\n");
        exit(EXIT_FAILURE);
    }
    while (i < size) {
        abb_elem elem;
        res = fscanf(file," %d ", &(elem));
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
        read_tree = abb_add(read_tree, elem);

       ++i;
    }
    fclose(file);
    return read_tree;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* parse the file to obtain an abb with the elements */
    abb tree = abb_from_file(filepath);

    /*dumping the tree*/
    //Como estaba el archivo Originalmente
    /*abb_dump(tree);
    !abb_is_empty(tree)
    if (tree!=NULL) {
        printf("\n");
        printf("raiz: %d\n minimo: %d\n maximo: %d\n", abb_root(tree),
                                                       abb_min(tree),
                                                       abb_max(tree));
    } else {
        printf("\nÁrbol vacío\n");
    }*/
    unsigned int i=0;
   while(i!=7){
        printf("¿Que operacion hacer ahora?\n");
        scanf("%u",&i);

        if(i==1){
            printf("Arbol actual\n");
            abb_dump(tree);
            printf("\n");
        }else if(i==2){
            int help;
            printf("Agregar un elemento al arbol existente\n");
            scanf("%d",&help);
            tree = abb_add(tree,help);
        }else if(i==3){
            int help;
            printf("Eliminar un elemento al arbol existente\n");
            scanf("%d",&help);
            tree = abb_remove(tree,help);
            if(abb_is_empty(tree)){
                printf("El arbol esta vacio\n");
            }
        }else if(i==4){
            int help;
            bool check;
            printf("Chequear si existe un elemento en el arbol actual\n");
            scanf("%d",&help);
            check = abb_exists(tree,help);
            if (check == true){
                printf("El elemento si existe\n");
            }
            else{
                printf("El elemento no existe\n");
            }
        }else if(i==5){
            printf("La longitud del arbol es %d \n",abb_length(tree));
        }else if(i==6){
            assert(!abb_is_empty(tree));
            if (tree!=NULL) {
                printf("\n");
                printf("raiz: %d\n minimo: %d\n maximo: %d\n", abb_root(tree),
                                                       abb_min(tree),
                                                       abb_max(tree));
            } else {
            printf("\nÁrbol vacío\n");
            }
        }else if(i==7){
            printf("Fin del programa\n");
        }else{
            printf("Operacion no definida, elija una de las siguientes:\n"
            "1. Mostrar el árbol por pantalla\n"
            "2. Agregar un elemento\n"
            "3. Eliminar un elemento\n"
            "4. Chequear existencia de elemento\n"
            "5. Mostrar la longitud del árbol\n"
            "6. Mostrar raiz, máximo y mínimo del árbol\n"
            "7. Salir del programa\n");
        }
    }

    tree = abb_destroy(tree);

    return (EXIT_SUCCESS);
}
