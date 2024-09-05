#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

/**
 * @brief Verifica que no estea vacio y el texto sea correcto
 * @details que el texto sea correcto y no sea solo vacios
 * contando la cantidad de vacios y elementos distintos a
 * esto, si la cantidad de vacios es mayor a el resto,
 * da falso
 * @param texto Texto ingresado por el usuario
 * @return 1 si el texto esta vacio y 0 si no
 */
int noVacio(char* texto);

/**
 * @brief Imprime los datos ingresados
 * @details Imprime los datos que el usuario ingreso al inicializar
 * el codigo, en caso de que no se hubiera ingresado uno de los datos
 * no se muestra
 * @param ingreso Verificador de ingreso del usuario
 * @param texto Arreglo de Caracteres con el texto del usuario
 * @param lista_numero Arreglo con los numeros del usuario para el vector
 * @param numero Numero ingresado por el usuario
 */
void imprimiringresados(int ingreso, char* texto, char* lista_numero, float numero);

/**
 * @brief Imprime el menu
 * @details Imprime el menu del usuario, mostrando en el las opciones
 * que puede utilizar el usuario dependiendo de lo que el
 * usuario coloco, utilizando casos distintos si el usuario coloco
 * solo algunas opciones
 * @param ingreso verificador por si se ingreso el numero
 * @param texto Texto ingresado por el
 * @param lista_numero Lista de numeros en forma de texto
 */
void printmenu(int ingreso,char* texto, char* lista_numero);

/**
 * @brief Verifica el ingreso con la opcion
 * @details Comprueba si en el arreglo del ingreso existe el
 * texto que acepta la opcion, en caso de que no exista
 * retorna verdadero, en caso contrario, da falso
 * @param ingreso V con el ingreso del numero
 * @param option Opcion escogida por el usuario
 * @param texto Texto ingresado con los usuarios
 * @param lista_num Lista con los numeros del vector
 * @return 1 si es verdadero, 0 en caso contrario
 */
int noingresados(int ingreso, int option, char* texto, char* lista_num);

/**
 * @brief Funcion Main | Interfaz Usuario-Computador
 * @details Funcion origen que se ejecuta cuando el usuario
 * crea el usuario con el makefile. Muestra una interfaz
 * que da distintas opciones al usuario de lo que puede hacer
 * con los valores que ingreso
 * @param argc Cantidad de argumentos que se pasaron
 * @param argv Arreglo con lo que se pasa por el ejecutable
 * @return 1 si la ejecucion fue exitosa, 0 en caso de error
 */
int main(int argc, char* argv[]){ 
    cargar_env(".env");
    char*endptr;
    int opt;
    char aux[10];
    int option;
    char* user = NULL;
    char* password = NULL;
    char* texto = NULL;
    char* lista_numeros = NULL;
    float numero = 0.0;
    int ingreso = 0;
    while((opt=getopt(argc,argv,"u:p:t:v:n:"))!=-1){
        switch(opt){
            case 'u':
                if(user!=NULL){
                    printf("Ya se utilizo el -u, no se puede volver a usar\n");
                    exit(EXIT_FAILURE);
                }
                user = strdup(optarg);
                break;
            
            case 'p':
                if(password!=NULL){
                    printf("Ya se utilizo el -p, no se puede volver a usar\n");
                    exit(EXIT_FAILURE);
                }
                password = strdup(optarg);
                break;
            
            case 't':
                if(texto!=NULL){
                    printf("Ya se utilizo el -t, no se puede volver a usar\n");
                    exit(EXIT_FAILURE);
                }
                texto = strdup(optarg);
                break;

            case 'v':
                if(lista_numeros!=NULL){
                    printf("Ya se utilizo el -v, no se puede volver a usar\n");
                    exit(EXIT_FAILURE);
                }
                lista_numeros = strdup(optarg);
                break;
            case 'n':
                if(ingreso!=0){
                    printf("Ya se utilizo el -n, no se puede volver a usar\n");
                    exit(EXIT_FAILURE);
                }
                numero = strtof(optarg,&endptr);
                if(*endptr!='\0'){
                    printf("Error, el ingreso de -n es incorrecto, deberia ser entero o flotante!!\n");
                    exit(EXIT_FAILURE);
                }
                ingreso = 1;
                break;
            case '?':
            default:
                printf("Error, se ingreso una opcion no disponible\n"
                "El uso del programa deberia ser:"
                "\n ./programa -u Nombre_del_Usuario -p Contraseña -t 'Sentencia' -v 'num1%snum2%s...%snumN' -n 'num'\n",getenv("VECTORSEPARATOR"),getenv("VECTORSEPARATOR"),getenv("VECTORSEPARATOR"));
                exit(EXIT_FAILURE);
        }
    }

    if(user==NULL || password==NULL){
        printf("Error!!! no se a ingresado nada en el inicio de sesion del usuario o falta algun dato\n");
        exit(EXIT_FAILURE);
    }
    else{
        int valor = ingresoDeUsuario(user,password) ;
        if(valor){
            printf("Usuario o clave incorrecta\n");
            exit(EXIT_FAILURE);
        }
    }

    if(texto!=NULL && strlen(texto)<=0 && noVacio(texto)){
        printf("Error!!! el texto introducido esta vacio o es incorrecto\n");
        exit(EXIT_FAILURE);
    }

    //Comprueba que no ingreso un vector vacio
    if(lista_numeros!=NULL && comprobarVector(lista_numeros) ){
        printf("Error!!! El Vector ingresado es incorrecto\n");
        exit(EXIT_FAILURE);
    }

    printf("El ingreso del usuario se a realizado correctamente!!!\n\n");
    while (1){
        printmenu(ingreso,texto,lista_numeros);
        do{
            printf(" Ingrese una opcion: ");
            scanf("%s",aux);
            option = atoi(aux);
        }while (noingresados(ingreso,option,texto,lista_numeros));
        
        switch (option)
        {
        case 1:
            isPalindromo(texto);
            break;
        case 2:
            contarVocales(texto);
            break;
        case 3:
            contarLetras(texto);
            break;
        case 4:
            calcularSumProm(lista_numeros);
            break;
        case 5:
            if(numero==0){
                printf("Error, el numero ingresado no pertenece a el dominio !!\n\n");
                break;
            }
            evaluarFuncion(numero);
            break;
        case 6:
            imprimiringresados(ingreso,texto,lista_numeros,numero);
            break;
        case 7:
            exit(EXIT_SUCCESS);
        }
        sleep(3);
    }
}

/**
 * Implementacion del codigo
 */
int noingresados(int ingreso, int option, char* texto,char* lista_num){
    if(option>7 || option<1) return 1;
    switch (option)
    {
    case 1:
    case 2:
    case 3:
        return texto==NULL;
    case 4:
        return lista_num==NULL;
    case 5:
        return ingreso==0;
    case 6: 
        return texto==NULL && lista_num==NULL && ingreso==0;
    default:
        return 0;
    }
}

/**
 * Implementacion del codigo
 */
void imprimiringresados(int ingreso, char* texto, char* lista_numero, float numero){
    printf("x---------------------Valor/es ingresado/s---------------------x\n\n");
    if(texto!=NULL){
        printf("  texto = '%s'\n",texto);
    }
    if(lista_numero!=NULL){
        printf("  Lista de numeros ingresados = '%s'\n",lista_numero);
    }
    if(ingreso!=0){
        printf("  numero = '%f'\n",numero);
    }
}

/**
 * Implementacion del codigo
 */
void printmenu(int ingreso,char* texto, char* lista_numero){
    printf("x-------------------------Menu-----------------------x\n\n"
    " Elija entre las opciones para iterar su entrada : \n");
    
    // Comprobacion de ingreso de un texto
    if(texto!=NULL){
        printf("  1) Verificar si la palabra es palindromo\n"
        "  2) Cantidad de Vocales\n" "  3) Cantidad de Letras\n");
    }
    else{
        printf("  1)-------texto no ingresado------\n"
        "  2)-------texto no ingresado------\n"
        "  3)-------texto no ingresado------\n");
    }

    // Comprobacion de ingreso de un vector
    if(lista_numero!=NULL){
        printf("  4) Promedio y Sumatoria de un vector\n");
    }
    else{
        printf("  4)------vector no ingresado------\n");
    }
    // Comprobacion de ingreso de un numero
    if(ingreso!=0){
        printf("  5) Calcular f(x) = 5x*x + 1/x\n");
    }
    else{
        printf("  5)------numero no ingresado------\n");
    }
    if( texto!=NULL || lista_numero!=NULL || ingreso!=0){
        printf("  6) Ver Dato/s ingresado/s\n");
    }
    else{
        printf("  6)--------nada ingresado!--------\n");
    }
    printf("  7) Salir\n\n");
}

/**
 * Implementacion del codigo
 */
int noVacio(char* texto){
    int contador_espacios = 0;
    int contador_letras = 0;
    int largo = strlen(texto)-1;
    if(texto[0]==' ' || texto[largo]!='\0') return 1;
    for(int i = 0; texto[i]!='\0';i++){
        if(isspace(texto[i])){
            contador_espacios++;
        }
        else{
            contador_letras++;
        }
    }
    if(contador_espacios>=contador_letras){
        return 1;
    }
    return 0;
}