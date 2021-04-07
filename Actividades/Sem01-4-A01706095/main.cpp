// Naomi Estefanía Nieto Vega A01706095
// main.cpp
// Actividad Individual 2 - Sem01-4-A01706095
// Lunes 15 de febrero de 2021

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int fibonacciIterativo(int n) {
    /* Método Iterativo Complejidad lineal O(n) */
    int contador1 = 0;
    int contador2 = 1;

    for (int i = 1; i < n; i++){
        int j=0;
        j = contador1+contador2;
        contador1=contador2;
        contador2=j;
    }
    return contador2;
}
int fibonacciRecursivo(int n) {
    /* Metodo Recursivo */
    if (n < 2) {
        return n;
    }
    else {
        return fibonacciRecursivo(n-2)+fibonacciRecursivo(n-1);
    }
}

float bacteriaIterativa(int n) {
    float crecimiento = 1.44;
    float bacterias = 1.0;

    for (int i = 0; i < n; i++) {
        bacterias *= crecimiento;
    }
    return bacterias;
}

float bacteriaRecursiva(int n) {
    float crecimiento = 1.44;

    if (n == 0) {
        return 1;
    }
    else {
        return bacteriaRecursiva(n-1)*crecimiento;
    }
}

float inversionIterativa(int n, float cantInicial) {
    float tasaInteres = 1.1875;

    for (int i = 0; i < n; i++) {
        cantInicial *= tasaInteres;
    }
    return cantInicial;
}
float inversionRecursiva(int n, float cantInicial) {
    float tasaInteres = 1.1875;

    if (n == 0) {
        return cantInicial;
    }
    else {
        return inversionRecursiva(n-1,cantInicial)*tasaInteres;
    }
}

int potenciaIterativa(int x, int y) {
    if (y != 0) {
        return pow(x,y);
    }
    else {
        return 1;
    }
}
int potenciaRecursiva(int x, int y) {
    
    if (y != 0) {
        return x*potenciaRecursiva(x,y-1);
    }
    else {
        return 1;
    }
}


/* ======================== Menu ======================== */
int main(int argc, const char * argv[]) {
    int opc;

    while (opc != 5) {
        cout << endl;
        cout << "Hola. Ingrese un número de ejercicio (1-4) o 5 para salir" << endl;
        cout << "\t1. Cálculo del número de Fibonacci de N" << endl;
        cout << "\t2. Cálculo del número de bacterias en N días " << endl;
        cout << "\t3. Cálculo del monto final de interés en N meses" << endl;
        cout << "\t4. Cálculo del x^y" << endl;
        cout << "\t5. Salida/Exit" << endl;
        cout << "Opción: "; 
        cin >> opc;

        switch (opc) {
            int metodo, resultado, n, numElevar, potencia;
            float cantidad;

            case 1: /* Ejercicio 1 */
                cout << "Elige el método por el cuál deseas resolver: " << endl;
                cout << "\t 1. fibonacciIterativo" << endl;
                cout << "\t 2. fibonacciRecursivo" << endl;
                cin >> metodo;

                if (metodo == 1) {
                    cout << "Introduce el número N: ";
                    cin >> n;
                    resultado = fibonacciIterativo(n);
                    cout << "El resultado de evaluar " << n << " es: " << resultado << endl;
                }
                else if (metodo == 2) {
                    cout << "Introduce el número N: ";
                    cin >> n;
                    resultado = fibonacciRecursivo(n);
                    cout << "El resultado de evaluar " << n << " es: " << resultado << endl;
                }
                else {
                    cout << "Ingresa una opción válida (1 ó 2)" << endl;
                }
        
                break;
    
            case 2: /* Ejercicio 2 */
                cout << "Elige el método por el cuál deseas resolver: " << endl;
                cout << "\t 1. bacteriaIterativa" << endl;
                cout << "\t 2. bacteriaRecursiva" << endl;
                cin >> metodo;

                if (metodo == 1) {
                    cout << "Introduce el número de días: ";
                    cin >> n;
                    resultado = bacteriaIterativa(n);
                    cout << "La cantidad de bacterias en " << n << " días será de: " << resultado << endl;
                }
                else if (metodo == 2) {
                    cout << "Introduce el número de días: ";
                    cin >> n;
                    resultado = bacteriaRecursiva(n);
                    cout << "La cantidad de bacterias en " << n << " días será de: " << resultado << endl;
                }
                else {
                    cout << "Ingresa una opción válida (1 ó 2)" << endl;
                }
                break;

            case 3: /* Ejercicio 3 */
                cout << "Elige el método por el cuál deseas resolver: " << endl;
                cout << "\t 1. inversionIterativa" << endl;
                cout << "\t 2. inversionRecursiva" << endl;
                cin >> metodo;

                if (metodo == 1) {
                    cout << "Introduce el número de meses: ";
                    cin >> n;
                    cout << "Introduce la cantidad inicial: ";
                    cin >> cantidad;
                    resultado = inversionIterativa(n,cantidad);
                    cout << "El monto final de invertir " << cantidad << " en " << n << " meses es: " << resultado << endl;
                }

                else if (metodo == 2) {
                    cout << "Introduce el número de meses: ";
                    cin >> n;
                    cout << "Introduce la cantidad inicial: ";
                    cin >> cantidad;
                    resultado = inversionRecursiva(n,cantidad);
                    cout << "El monto final de invertir " << cantidad << " en " << n << " meses es: " << resultado << endl;
                }

                else {
                    cout << "Ingresa una opción válida (1 ó 2)" << endl;
                }

                break;

            case 4: /* Ejercicio 4 */
                cout << "Elige el método por el cuál deseas resolver: " << endl;
                cout << "\t 1. potenciaIterativa" << endl;
                cout << "\t 2. potenciaRecursiva" << endl;
                cin >> metodo;

                if (metodo == 1) {
                    cout << "Introduce el número a elevar: ";
                    cin >> numElevar;
                    cout << "Introduce la potencia: ";
                    cin >> potencia;

                    resultado = potenciaIterativa(numElevar,potencia);
                    cout << "El resultado de "<< numElevar << "^" << potencia << " es: " << resultado << endl;
                }
                else if (metodo == 2) {
                    cout << "Introduce el número a elevar: ";
                    cin >> numElevar;
                    cout << "Introduce la potencia: ";
                    cin >> potencia;

                    resultado = potenciaRecursiva(numElevar,potencia);
                    cout << "El resultado de "<< numElevar << "^" << potencia << " es: " << resultado << endl;
                }
                else {
                    cout << "Ingresa una opción válida (1 ó 2)" << endl;
                }

                break;

            case 5: /* Salir */
                cout << "\n ¡Hasta pronto!" << endl;
        
                break;

            default: /* Opción no válida */
                if (opc != 5) {
                    cout << "\nOpción inválida. Por favor introduzca una opción válida (1-5)." << endl;
                }
                break;
        } /* End of switch statement */
    } /* End while */

    return 0;
}; /* End main */
