#ifndef FUNCIONES_H
#define FUNCIONES_H

// Funciones para la 1) a la 3)

/**
 * @author NigelMoon
 * @brief Verificar si es Palindromo
 * @details Toma el texto ingresado por el usuario y
 * calcula que este sea palindromo, mostrando por medio
 * de un printf si es o no palindromo
 * @param texto Arreglo de caracteres del texto
 */
void isPalindromo(char* texto);

/**
 * @author NigelMoon
 * @brief Cuenta las Vocales
 * @details Toma el texto ingresado por el usuario y
 * calcula cuantas vocales tiene el texto y luego muestra
 * cuantas vocales son en total
 * @param texto Arreglo de caracteres del texto
 */
void contarVocales(char* texto);

/**
 * @author NigelMoon
 * @brief Cuenta las Letras
 * @details Toma el texto ingresado por el usuario y
 * calcula cuantas letras tiene el texto y luego muestra
 * cuantas letras son en total
 * @param texto Arreglo de caracteres del texto
 */
void contarLetras(char* texto);

//Funcion 4)

/**
 * @author NigelMoon
 * @brief Calcula la Suma y el Promedio de un vector
 * @details Con el vector ingresado por el usuario, el programa
 * transforma esta a un arreglo de enteros y calcula la suma de los numeros
 * y muestra el resultado, luego calcula el promedio y lo muestra
 * @param vector Arreglo de caracteres del vector
 */
void calcularSumProm(char* vector);

/**
 * @author NigelMoon
 * @brief Comprueba que el vector sea correcto
 * @details Cuenta la cantidad de separadores que hay en el Vector
 * ingresado por el usuario y en caso de que sean mas o por lo menos
 * no hubiera un numero, el resultado sera verdadero, entrando en el if
 * que retorna el error
 * @param vector Arreglo de caracteres del vector
 * @return 1 Si el Vector es incorrecto, 0 en caso contrario
 */
int comprobarVector(char* vector);

//Funcion 5)

/**
 * @author NigelMoon
 * @brief Evalua una funcion con num
 * @details La funcion transforma la funcion almacenada en la variable de entorno
 * y nos retorna su dominio y la evaluacion de esta, en caso de que esta se cambie desde ahi,
 * en caso de que el numero ingresado por el usuario no pertenezca al dominio, tira un error y vuelve
 * al inicio, y si pertenece, muestra el resultado correcto
 * @param num Numero ingresado por el usuario
 */
void evaluarFuncion(float num);

//Funciones para la comprobacion de usuario

/**
 * @author NigelMoon
 * @brief Verifica el ingreso
 * @details Utilizando la libreria de sodium, implementa una funcion
 * de hash para encriptar la clave del usuario y desencriptarla para verificar
 * si la que ingreso mediante la ejecucion del programa, no se permite el ingreso al
 * programa
 * @param usuario Nombre del usuario
 * @param password Clave del usuario anteriormente dado
 * @return 1 si el ingreso es incorrecto, 0 si es correcto
 */
int ingresoDeUsuario(char* usuario,char* password);

//Funciones extras para la ejecucion correcta

/** 
 * @author Tio ChatGPT
 * @brief Función para cargar las variables de entorno desde un archivo .env
 * @details Asigna los valores dentro del .env como variables de entorno y asi
 * poder utilizarlo durante la ejecucion del programa
 * @param filename nombre del archivo
 * */ 
void cargar_env(const char *filename);

#endif