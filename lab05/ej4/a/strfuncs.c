#include <stdio.h>
#include <stdlib.h>

#include "strfuncs.h"

size_t string_length(const char *str){
    size_t res=0;
    while (*str!='\0'){
        res++;
        str++;
    }
 return res;
}

char * string_filter(const char *str, char c){
    char *res=malloc(sizeof(string_length(str)));
    char *help=res;
    while(*str!='\0'){
        if(*str!=c){
            *help=*str;
            help++;
            str++;            
        }
        else{
            str++;
        }
    }
    return res;
}