#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



void evaluarFuncion(float num){
    float resultado = 5.0*num*num + 1.0/num;

    printf("-----------------------------------\n\n");
    printf("La funcion 5*x*x + 1/x evaluado en %f es %f\n\n",num,resultado);
}