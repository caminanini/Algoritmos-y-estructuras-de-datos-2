#include <stdlib.h>
#include <stdio.h>
void absolute(int x, int y){
if (x >= 0){
y = x;
}
else{
y = -x;
}
}

int main(void) {
int a=0, res=0;
a = -10;
absolute(a, res);
printf("%d\n",res);
return EXIT_SUCCESS;
}
/*¿Qué valor se muestra por pantalla? ¿Coincide con el programa en el lenguaje del teórico? 
El valor que se muestra es el 0, esto no coincide con el lenguaje del teórico puesto que debería 
dar el valor absoluto.*/