#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

void isPalindromo(char* texto){
    int palindromo = 0;
    int i = 0;
    int j = strlen(texto)-1;
    while (i < j) {
        while (i < j && isspace(texto[i])) {
            i++;
        }

        while (i < j && isspace(texto[j])) {
            j--;
        }
        if (tolower(texto[i]) != tolower(texto[j])) {
            palindromo = 1;
            break;
        }
        i++;
        j--;
    }
    printf("-----------------------------------\n\n");
    if(palindromo){
        printf("La palabra %s no es un palindromo \n\n",texto);
    }
    else{
        printf("La palabra %s es un palindromo \n\n",texto);
    }
}

void contarVocales(char* texto){
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

void contarLetras(char* texto){
    int cantidad = 0;
    for(int i = 0; texto[i]!='\0';i++){
        if(isalpha(texto[i])){
            cantidad++;
        }
    }
    printf("-----------------------------------\n\n");
    printf("La palabra %s tiene %d letras \n\n",texto, cantidad);
}