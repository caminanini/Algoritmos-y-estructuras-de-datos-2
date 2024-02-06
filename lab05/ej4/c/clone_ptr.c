#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *string_clone(const char *str, size_t length) {
    char clone[length + 1];
    char *output=calloc(length+1,sizeof(char));
    for (size_t i=0; i<length; i++) {
        clone[i] = str[i];
    }
    clone[length] = '\0';
    
    char *p=clone;
    char *q=output;
    while(*p!='\0'){
        *q=*p;
        q++;
        p++;
    }

    return output;
}


int main(void) {
    char *original=""
         "______ time ago in a galaxy far, far away...\n\n\n"
         "         _______..___________.     ___      .______             \n"
         "        /       ||           |    /   \\     |   _  \\          \n"
         "       |   (----``---|  |----`   /  ^  \\    |  |_)  |          \n"
         "        \\   \\        |  |       /  /_\\  \\   |      /        \n"
         "    .----)   |       |  |      /  _____  \\  |  |\\  \\----.    \n"
         "    |_______/        |__|     /__/     \\__\\ | _| `._____|     \n"
         "                                                                \n"
         "____    __    ____      ___      .______           _______.     \n"
         "\\   \\  /  \\  /   /     /   \\     |   _  \\         /       |\n"
         " \\   \\/    \\/   /     /  ^  \\    |  |_)  |       |   (----` \n"
         "  \\            /     /  /_\\  \\   |      /         \\   \\    \n"
         "   \\    /\\    /     /  _____  \\  |  |\\  \\----..----)   |   \n"
         "    \\__/  \\__/     /__/     \\__\\ | _| `._____||_______/     \n"
         "\n\n\n"
         "                     Episode IV \n\n"
         "                     A NEW HOPE \n\n"
         "                     It is a period of civil war. Rebel\n"
         "spaceships, striking from a hidden base, have won their\n"
         "first victory against the evil Galactic Empire. During the\n"
         "battle, Rebel spies managed to steal secret plans to the\n"
         "Empire’s ultimate weapon, the DEATH STAR, an armored space\n"
         "station with enough power to destroy an entire planet.\n"
         "Pursued by the Empire’s sinister agents, Princess Leia\n"
         "races home aboard her starship, custodian of the stolen\n"
         "plans that can save her people and restore freedom to the\n"
         "galaxy...\n";

    char *copy=NULL;
    copy = string_clone(original, sizeof(original)/sizeof(char) - 1);
    printf("Original: %s\n", original);
    copy[0] = 'A';
    copy[1] = ' ';
    copy[2] = 'l';
    copy[3] = 'o';
    copy[4] = 'n';
    copy[5] = 'g';
    printf("Copia   : %s\n", copy);
    free(copy);

    return EXIT_SUCCESS;
}

/*Al cambiar el tipo ocurre este error:
clone_ptr.c:56:51: error: division ‘sizeof (char *) / sizeof (char)’ does not compute the number of array elements [-Werror=sizeof-pointer-div]
   56 |     copy = string_clone(original, sizeof(original)/sizeof(char) - 1);
      |                                                   ^
clone_ptr.c:26:11: note: first ‘sizeof’ operand was declared here
   26 |     char *original=""
Lo que nos indica que se da por un error de tipos a la hora de hacer la división
*/