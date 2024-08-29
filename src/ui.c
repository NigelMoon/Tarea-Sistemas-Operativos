#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "funciones.h"

void imprimiringresados(int* ingreso, char* texto, char* lista_numero, int numero);
void printmenu(int* ingreso);
int noingresados(int* ingreso, int option);

int main(int argc, char* argv[]){ 
    int opt;
    int user_in = 0;
    char aux[1];
    int option;
    char* user = NULL;
    char* password = NULL;
    char* texto = NULL;
    char* lista_numeros = NULL;
    int numero = 0;
    int ingreso[5] = {0,0,0,0,0};
    while((opt=getopt(argc,argv,"u:p:t:v:n"))!=-1){
        switch(opt){
            case 'u':
                if(ingreso[3]!=0){
                    printf("Ya se utilizo el -u, no se puede volver a usar\n");
                    exit(EXIT_FAILURE);
                }
                user = optarg;
                user_in += 1;
                ingreso[3] = 1;
                break;
            
            case 'p':
                if(ingreso[4]!=0){
                    printf("Ya se utilizo el -p, no se puede volver a usar\n");
                    exit(EXIT_FAILURE);
                }
                password = optarg;
                user_in += 1;
                ingreso[4] = 1;
                break;
            
            case 't':
                if(ingreso[0]!=0){
                    printf("Ya se utilizo el -t, no se puede volver a usar\n");
                    exit(EXIT_FAILURE);
                }
                texto = optarg;
                ingreso[0] = 1;
                break;

            case 'v':
                if(ingreso[1]!=0){
                    printf("Ya se utilizo el -v, no se puede volver a usar\n");
                    exit(EXIT_FAILURE);
                }
                lista_numeros = optarg;
                ingreso[1] = 1;
                break;
            case 'n':
                if(ingreso[2]!=0){
                    printf("Ya se utilizo el -n, no se puede volver a usar\n");
                    exit(EXIT_FAILURE);
                }
                numero = atoi(optarg);
                ingreso[2] = 1;
                break;

            default:
                printf("Error, se ingreso una opcion no disponible\n"
                "El uso del programa deberia ser:"
                "\n ./programa -u 'Nombre del Usuario' -p 'Contraseña' -t 'Sentencia' -v 'num1;num2;...;numN' -n 'num'");
                exit(EXIT_FAILURE);
        }
    }

    if(user_in != 2){
        printf("Error!!! no se a ingresado nada en el inicio de sesion del usuario o falta algun dato\n");
        exit(EXIT_FAILURE);
    }
    else{
        //Comprobar que si sea la contraseña
        printf("using %s, %s, %s, %s, %d \n",user,password,texto,lista_numeros,numero);
    }

    if(texto == NULL && ingreso[0] != 0){
        printf("Error!!! Una de las opciones ingresadas no fue completada correctamente\n");
        exit(EXIT_FAILURE);
    }
    printf("El ingreso del usuario se a realizado correctamente!!!\n\n");
    while (1){
        printmenu(ingreso);
        do{
            printf(" Ingrese una opcion: ");
            scanf("%s",aux);
            option = atoi(aux);
        }while (noingresados(ingreso,option));
        
        switch (option)
        {
        case 1:
            contarvocales(texto);
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            break;
        case 6:
            imprimiringresados(ingreso,texto,lista_numeros,numero);
            sleep(1);
            break;
        case 7:
            exit(EXIT_SUCCESS);
        }
        sleep(2);
    }
}

int noingresados(int* ingreso, int option){
    if(option>7 || option<1) return 1;
    switch (option)
    {
    case 1:
    case 2:
    case 3:
        return ingreso[0]==0;
    case 4:
        return ingreso[1]==0;
    case 5:
        return ingreso[2]==0;
    case 6: return ingreso[0]==0 && ingreso[1]==0 && ingreso[2]==0;
    default:
        return 0;
    }
}

void imprimiringresados(int* ingreso, char* texto, char* lista_numero, int numero){
    if(ingreso[0]!=0){
        printf("texto = '%s'\n",texto);
    }
    if(ingreso[1]!=0){
        printf("Lista de numeros ingresados = '%s'\n",lista_numero);
    }
    if(ingreso[2]!=0){
        printf("numero = '%d'\n",numero);
    }
}

//Imprime el menu para el usuario
void printmenu(int* ingreso){
    printf("x-------------------------Menu-----------------------x\n\n"
    " Elija entre las opciones para iterar su entrada : \n");
    
    // Comprobacion de ingreso de un texto
    if(ingreso[0]!=0){
        printf("  1) Verificar si la palabra es palindromo\n"
        "  2) aqui no se que iba\n" "  3) aqui tampoco jeje\n");
    }
    else{
        printf("  1)-------texto no ingresado------\n"
        "  2)-------texto no ingresado------\n"
        "  3)-------texto no ingresado------\n");
    }

    // Comprobacion de ingreso de un vector
    if(ingreso[1]!=0){
        printf("  4) Promedio y Sumatoria de un vector\n");
    }
    else{
        printf("  4)------vector no ingresado------\n");
    }
    // Comprobacion de ingreso de un numero
    if(ingreso[2]!=0){
        printf("  5) Calcular f(x) = 5x^2 + 1/x\n");
    }
    else{
        printf("  5)------numero no ingresado------\n");
    }
    if( ingreso[0]!=0 || ingreso[1]!=0 || ingreso[2]!=0){
        printf("  6) Ver Dato/s ingresado/s\n");
    }
    else{
        printf("  5)------nada ingresado------\n");
    }
    printf("  7) Salir\n\n");
}