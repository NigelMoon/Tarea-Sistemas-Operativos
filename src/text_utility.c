#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

void contarvocales(char* texto){
    int cont = 0;
    for(int i = 0; i<strlen(texto); i++){
        switch (tolower(texto[i]))
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cont++;
            break;
        default:
            break;
        }
    }
    printf("-----------------------------------\n\n"
    "En la palabra '%s' hay %d vocal/es \n\n",texto,cont);
}
