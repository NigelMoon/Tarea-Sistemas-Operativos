#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include "funciones.h"

char* read_json(const char* filename, char* user) {
    char* clave = NULL;
    json_error_t error;
    json_t *root = json_load_file(filename, 0, &error);
    if (!root) {
        printf("Error cargando el JSON: %s\n", error.text);
        return NULL;
    }

    json_t *name = json_object_get(root, user);
    if (json_is_string(name)) {
        const char *value = json_string_value(name);
        clave = malloc(strlen(value) + 1);
        if (clave) {
            strcpy(clave, value);
        } else {
            printf("Error de memoria al asignar clave\n");
        }
    } else {
        printf("El usuario no se encuentra en el JSON o el valor no es una cadena\n");
    }
    json_decref(root);
    return clave;
}

int ingresoDeUsuario(char* usuario, char* password) {
    char* path = getenv("USERPATH");
    if (!path) {
        printf("Variable de entorno USERPATH no está definida\n");
        return 1;
    }

    char* clave = read_json(path, usuario);
    if (!clave) {
        printf("No se pudo obtener la clave para el usuario: %s\n", usuario);
        return 1;
    }

    int resultado = strcmp(password, clave);
    free(clave);
    return resultado == 0 ? 0 : 1;
}
