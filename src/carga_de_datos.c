#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void cargar_env(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error al abrir el archivo .env");
        exit(EXIT_FAILURE);
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // Eliminar el salto de línea al final de la línea
        line[strcspn(line, "\r\n")] = '\0';

        // Encontrar el índice del signo igual
        char *equals = strchr(line, '=');
        if (equals) {
            *equals = '\0'; // Reemplazar el signo igual con '\0'
            char *key = line;
            char *value = equals + 1;

            // Establecer la variable de entorno
            if (setenv(key, value, 1) != 0) {
                perror("Error al establecer la variable de entorno");
            }
        }
    }

    fclose(file);
}
