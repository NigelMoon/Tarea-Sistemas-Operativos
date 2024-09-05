# Programa de INFO198 Tarea Semestral
## Descripcion
En el curso __INFO198 Sistemas Operativos__ se nos dio la tarea de crear un programa en C/C++ que tomara argumentos por medio del ejecutable y realize acciones con estos argumentos.

## Requisitos
* __Compilador :__ gcc
* __Libreria/s :__ Jansson
* __Sistema :__ Subsistema Linux o Sistema Linux
* __Ubicacion :__ Carpeta __Trabajo Semestral__

## Instalacion / Compilacion
* Instalar la unica dependencia actual del programa, siendo libreria Jansson.
```bash
sudo apt install libjansson-div
```
* Luego de instalar las dependencias, utilizamos el __make__ de Linux para asi compilar los Archivos .c y tener el ejecutable. Asegurarse de estar en la carpeta __Trabajo Semestral__
```bash
make
```

## Ejecucion
Una vez compilado, se llama la funcion de la manera:
```bash
./app -u usuario1 -p contraseña -t texto1 -v vector -n numero
```
Donde:

| Argumento | Descripcion | Formato |
| -------- | ----------- | --------- |
| -u | Especifica el usuario | Nombre de usuario (Cadena de texto)|
| -p | Especifica la contraseña del usuario | Contraseña (Cadena de texto) |
| -t | Especifica el texto ingresado por el usuario | Texto Libre (Cadena de texto)|
| -v | Especifica el vector ingresado por el usuario | Lista de enteros separados por un separador definido (por defecto ;) |
| -n | Especifica el numero ingresado por el usuario | Numero entero o decimal |

### Ejemplos de Uso : 
```bash
./app -u luisveas -p clave12345678 -t "amo a la blanca paloma" -v "1;2;3;4;6;12;1231;10" -n 1.0
```
```bash
./app -u luisveas -p clave12345678 -t "amo a la blanca paloma" -n 41.313
```

## Configuracion de Entorno
Estas son las variables de entorno que se utilizan en el programa
* .env:
    * __USERPATH__ = Usuarios.json [Nombre del archivo con los usuarios]
    * __VECTORSEPARATOR__ = ; [Separador para el vector de enteros]

## Funciones
Funcion principal:
* ```main()``` : Funcion donde se obtiene la mayor parte de los datos, Maneja las opciones del usuario y lanza los errores de ingreso.
* ```printmenu()```: Funcion que imprime el menu principal con distintas variantes en caso de que un dato no fue ingresado
* ```imprimiringresado()```: Funcion que imprime los datos que fueron ingresado unicamente si la opcion esta disponible

Funciones de utilidad:
* Funciones para Usuario:
    * ```read_json()```: Funcion para leer el archivo "Usuarios.json" y extraer los datos necesarios
    * ```ingresoDeUsuario()```: Funcion para comprobar si el usuario ingresado fue correcto y retorna Verdadero o Falso

* Funciones para el texto:
    * ```contarLetras()```: Explora el texto ingresado por el usuario y cuenta las letras que hay en este texto.
    * ```isPalindromo()```: Verifica si la palabra ingresada es palindromo o no, sin importar que el texto tenga espacios o no, mostrando su resultado via consola.
    * ```contarVocales()```: Cuenta las vocales de la palabra o sentencia y muestra la cantidad total via consola.

* Funciones para el Vector:
    * ```transformarAVector()```: Funcion que toma el vector en forma de una lista de caracteres y lo pasa a una lista de numeros enteros (C no maneja la estructura Vector).
    * ```calcularSumProm()```: Funcion que calcula la suma y el promedio de los numeros dentro del vector, imprimiendo estos valores.
    * ```comprobarVector()```: Comprueba que el vector ingresado sea correctou que no tenga cosas en vacio, no permitiendo el ingreso incorrecto.

* Funcion para el numero:
    * ```evaluarFuncion()```: Evalua la funcion en el punto dado por el usuario e imprime el resultado de este.

* Carga de las variables de entorno:
    * ```cargar_env()```: Al no encontrar alguna libreria que pueda cargar los .env en C, tuve que conseguir una funcion que pueda asignar las variables de entorno de manera manual, abriendo el .env y cargandola.

# Comentarios
Durante la implementacion del codigo, queria implementar la codificacion de las contraseñas y asi tenerlas de manera mas seguras, pero devido a que se generaban multiples errores de __Segmentation Fault (Core Dumped)__ no se me fue posible implementarlo.