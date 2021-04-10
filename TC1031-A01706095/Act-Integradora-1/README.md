# 📌 README.md Act-Integradora-1

## 👩🏻‍💻 Autora
* ID:          A01706095
* Name:        Naomi Estefanía Nieto Vega 
* Date:        14/03/2021
* File name:   README.txt
* Title:       Act-Integradora-1

## Instrucciones para compilar:

Primero se debe abrir el archivo en un entorno que permita compilar C++, puede ser un compilador en línea como [Replit](https://replit.com/) o uno local como Visual Studio Code o directamente desde consola. Para compilar en consola únicamente tecleamos g++ main.cpp y se generará un archivo /a.out. En caso de ser en un IDE en línea después de que abrimos el archivo damos clic en compilar o ejecutar programa y seguimos los siguientes pasos: 
*Nota: Es importante que antes de compilar revisemos que este incluido el archivo ```bitacora.txt```para que pueda leer los datos. 

1. Aparecerá en el menú algo similar a esto:
```
=======================================================
Ingrese la fecha de inicio para buscar: 
Month (Ex: Jun, Jul, Aug, Sep, Oct): 
Day (Ex: 22): 
Hour (Ex: 04): 
Minutes (Ex: 17): 
Seconds (Ex: 34): 
=======================================================
```
  Cada línea irá desplegándose una vez que introducimos el valor que solicita cada variable, el formato para ingresarlos es en el ```Month``` un string de 3 letras con el mes como se muestra en el ejemplo, posteriormente en el ```Day``` se introduce el día que puede ir desde el 01 hasta el 30-31 según sea el mes. Para la hora se utiliza el formato de 24 horas, por lo que en ```Hour``` se debe introducir la hora en un rango de 00 a 23, en los ```Minutes``` y ```Seconds```es un número de 00 al 59.

2. Posteriormente se desplegará otro menú muy similar al del paso 2 pero para solicitar la fecha de fin, por lo que únicamente introducimos la fecha usando el mismo formato descrito anteriormente.
```
=======================================================
Ingrese la fecha de fin para buscar: 
Month (Ex: Jun, Jul, Aug, Sep, Oct): 
Day (Ex: 22): 
Hour (Ex: 04): 
Minutes (Ex: 17): 
Seconds (Ex: 34): 
=======================================================
```
4. Finalmente, si el resultado es favorable, se desplegará en la consola el resultado de la búsqueda solicitada y además se escribirán 2 archivos, un archivo llamado ```sortedData.txt```que almacenará toda la bitácora ordenada por fecha y hora en el siguiente formato: ```mm dd hh:mm:ss ipAddress errorMsg```. El otro archivo será llamado ```queryResults.txt```y en este se almacenará el resultado de la búsqueda en el rango solicitado.


