#include <stdlib.h> 
#include <stdio.h> 

void absolute(int x, int *y){ 
if (x >= 0){    
 *y = x; 
} 
else{     
*y = -x; 
}
} 

int main(void) {     
int a=0, res=0;   
int *p = NULL;  
a = -10;     
p=&res;
absolute(a,p);     
printf("%d\n",res);  
   
return EXIT_SUCCESS; 
} 
/* ¿El parámetro int *y de absolute() es de tipo in, de tipo out o de tipo in/out?
Es de tipo in.
¿Qué tipo de parámetros tiene disponibles C para sus funciones?
Parámetros in --> Son las que se colocan entre los paréntesis al principio de la función, en c
se da un caso particular en el que una función puede iniciar con un tipo void()
Parámetros out --> Se puede relacionar con aquellos que se devuelven con un return al final de la función.
*/