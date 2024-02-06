#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], int length) {
    struct bound_data res;
    int i=0;
    bool aux1=true,aux2=true,aux3=false;
    while (i<length){
        aux1 = aux1 && value >= arr[i];
        aux2= aux2 && value<=arr[i];
    if(value==arr[i]){
        aux3= aux3 || 1;
        res.where=i;
    } else {;}
    i=i+1;
    }
    res.is_upperbound = aux1;
    res.is_lowerbound = aux2;
    res.exists = aux3;
    return res;
}

void pedirArreglo(int a[], int n_max){
  int i,e;i=0;
  do{
    printf("Ingrese el valor para el lugar %d\n",i); scanf("%d",&e);
    a[i]=e;
    i=i+1;
  } while(i<n_max);
}

void trueofalse (bool num){
if (num == 1){
    printf("True\n");
}else{
    printf("False\n");
}
}


int main(void) {
    int m,c;
    printf("Dar el largo de un arreglo\t");
    scanf("%d",&m);
    int a[m];
    pedirArreglo(a,m);
    printf("Dar el valor a comparar\t");
    scanf("%d",&c);
    struct bound_data result = check_bound(c, a, m);
    printf("Es cota superior?\n");trueofalse (result.is_upperbound); 
    printf("Es cota inferior?\n");trueofalse (result.is_lowerbound); 
    printf("Existe ese numero en el array?\n");trueofalse (result.exists);         
    printf("Su lugar es %d\n", result.where);     

    return EXIT_SUCCESS;
}