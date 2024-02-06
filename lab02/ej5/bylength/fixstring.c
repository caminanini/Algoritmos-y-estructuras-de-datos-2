#include <stdbool.h>
#include <assert.h>


#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    unsigned int i=0, cont=0;
    while(s[i] != '\0'){
            cont= cont + 1;
            i=i+1;
    }
    return cont;
}

bool fstring_eq(fixstring s1, fixstring s2) {
   bool res = true;
   for (int i=0;i<FIXSTRING_MAX;i++){
        if(s1[i]=='\0' || s1[i]=='\0' ){
        return false;
    }
    else{
        res = res && s1[i] == s2[i];
    }
   }
   return res;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
     	if(fstring_length(s1)>fstring_length(s2)){
     		return false;
     	}
     return true;
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux,s1);
    fstring_set(s1,s2);
    fstring_set(s2,aux);
}