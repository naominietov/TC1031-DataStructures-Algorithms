# Actividad Sem07-3. Listas encadenadas

En esta actividad se desarrollan varias funciones para ser utilizadas con listas encadenadas mediante la creación de un ADT que represente una estructura de datos lineal.

## Autores

- A01706095 Naomi Estefanía Nieto Vega
- A01283687 Ramsés Herrera

## Instrucciones para compilar 

Inicialmente se debe abrir el archivo en un entorno que permita compilar C++, puede ser un compilador en línea como [Replit](https://replit.com/) o uno local como Visual Studio Code o directamente desde consola. Para compilar en consola únicamente tecleamos g++ main.cpp y se generará un archivo /a.out. En caso de ser en un IDE en línea después de que abrimos el archivo damos clic en compilar o ejecutar programa y seguimos los siguientes pasos:

Nota: Es importante revisar que todos los archivos .h y .cpp estén dentro de la misma carpeta para que funcione.

1. Una vez que compile el programa aparecerá un menú similar al que se muestra a continuación:
```
Hola!! Bienvenido.
=====================================================
a) Elige un tipo de dato para las listas: 
    1. Entero 
    2. Char 
=====================================================
Opción: 
```
En este paso únicamente se debe introducir el número (1 ó 2) dependiendo del tipo de dato que se desea usar para las listas.
2. Después nos preguntará si deseamos generar la lista aleatoriamente o manual. Sólo se ingresa la opción númerica (1-2).
```
=====================================================
b) Tipos de lista a generar disponibles: 
    1. Generar lista aleatoria 
    2. Generar lista manualmente 
=====================================================
Opción: 
```
3. En caso de seleccionar manual, se irán desplegando los espacios para insertar los valores en la lista principal y en una lista secundaria. 

**IMPORTANTE: Esta lista secundaria es únicamente para la opción 7 (sobrecarga del signo =), ya que por default el programa siempre hará los cambios en la lista principal (Lista 1) a menos que se modifique directamente en el main. Por lo que, en la lista 2 nunca se verán cambios reflejados con las acciones en ninguna opción que sea diferente a la 7.**

4. Por último preguntará el tamaño de la lista que se desea generar, en este paso sólo se introduce un número entero.
```
=====================================================
c) Introduce el tamaño de la lista: 
```
5. Después se imprimirán una confirmación de los datos. Y aquí es donde podremos ver la segunda lista :) como se muestra en el ejemplo a continuación.
```
Cool! Elegiste crear una listas aleatorias de tipo int!
Lista 1:  [  84  87  78  16  94  ]
Lista 2:  [  36  87  93  50  22  ]
Listas creadas con éxito!
```
6. Por último nos mostrará las opciones disponibles a realizar:
```
=====================================================
d) Opciones disponibles para realizar
    1. Insertar un elemento
    2. Borrar un elemento
    3. Leer el valor de un dato (getData)
    4. Actualizar un elemento
    5. Encontrar un elemento dado (findData)
    6. Leer y/o actualizar elemento (uso [])
    7. Actualizar lista con base en otra lista (uso =)
=====================================================
Opción:
```
Al final desplegará el resultado según sea el caso de la función elegida.



⌨️ con ❤️ 
