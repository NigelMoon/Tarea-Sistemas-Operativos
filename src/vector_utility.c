#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

/**
 * @brief Transforma el vector a uno de numeros
 * @details el vector en forma de una lista de caracteres
 * a forma numerica
 * @param vector Vector en forma de lista de caracteres
 * @param vector_normal Vector pasado como argumento
 * @return largo del vector
 */
int transformarAVector(char* vector_temp, int** vector_normal){
    int cont = 1;
    char* vector = strdup(vector_temp);
    for (int i = 0; vector[i] != '\0'; i++) {
        if (vector[i] == getenv("VECTORSEPARATOR")[0]) {
            cont++;
        }
    }
    *vector_normal = (int*)malloc(cont * sizeof(int));
    if (*vector_normal == NULL) {
        perror("Error asignando memoria");
        exit(EXIT_FAILURE);
    }

    // Convertir los tokens en números enteros
    int temp = 0;
    char* token = strtok(vector, getenv("VECTORSEPARATOR"));
    while (token != NULL) {
        (*vector_normal)[temp] = atoi(token);
        temp++;
        token = strtok(NULL, getenv("VECTORSEPARATOR"));
    }
    free(vector);
    return cont;
}

void calcularSumProm(char* vector){
    int* vector_new;
    int size = transformarAVector(vector,&vector_new);
    int sum = 0;
    for(int i = 0; i<size;i++){
        sum+=vector_new[i];
    }
    printf("-----------------------------------\n\n");
    printf("La suma entre todos los numeros del vector es %d\n",sum);
    printf("y su promedio es %i\n\n",(sum/size));
    free(vector_new);
}


int comprobarVector(char* vector) {
    char* separator = getenv("VECTORSEPARATOR");
    if (separator == NULL || strlen(separator) != 1) {
        fprintf(stderr, "Error: VECTORSEPARATOR no está configurado correctamente.\n");
        return 1;
    }

    char sep = separator[0]; // Usar solo el primer carácter
    char* vector_copy = strdup(vector); // Crear una copia del vector
    if (vector_copy == NULL) {
        perror("Error al duplicar el vector");
        return 1;
    }

    char* token = strtok(vector_copy, &sep);
    char* endptr;
    int valid = 1; // Asumimos que el vector es válido

    while (token != NULL) {
        strtof(token, &endptr); // Usamos strtof para comprobar si es un flotante
        if (*endptr != '\0') {
            valid = 0; // Encontramos un token no numérico
            break;
        }
        token = strtok(NULL, &sep);
    }

    free(vector_copy); // Liberar la copia del vector
    return valid ? 0 : 1; // Retornar 1 si es inválido, 0 si es válido
}