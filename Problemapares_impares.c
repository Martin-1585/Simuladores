/*
    Problemas sentencias repetitivas Do- While
    Nombres: Martin Olalla y Andres Paqui
    Docente: Anita Yanez
    Fecha: 07-01-2025
    Descripción: Realizar un programa en C que cuente la cantidad de veces que se ingresan números pares y la cantidad de números impares hasta que se ingrese un número negativo. 
    El cero no se cuenta.
*/
//Declaracion de librerias 
#include <stdio.h>

int main (){
    //Declaración de variables
    int num;
    int num_pares=0, num_impares=0; //Contadores inicializados 
    //Presentación del programa
    printf("\t***************************************\n");
    printf("\t Simulador de numeros pares e impares\n");
    printf("\t***************************************\n");
    do{
        //Se solcita al usuario ingresar un numero
        printf("Ingrese un numero\n");
        scanf("%d",&num);
        //Se debe determinar si el numero ingresado es par o impar
        if (num>0 && num%2==0){
            //Si el residuo del número dividido con 2 es 0 es par
            //El contador de pares aumenta en paso 1
            num_pares++;
        } else if (num>0 && num%2==1){
            //Si el residuo del numero dividido con 2 es 1 es impar
            //El contador de impares aumenta en paso 1
            num_impares++;
        }
    } while (num>=0); //Mientras el numero sea mayor a 0 el ciclo se repite
    //Salida
    printf("***************************************\n");
    //Se despliega un mensaje que muestra la cantidad total de pares obtenidos por el contador de pares
    printf("La cantidad de numeros pares ingresados es %d\n", num_pares);
    //Se despliega un mensaje que muestra la cantidad total de impares obtenidos por el contador de impares
    printf("La cantidad de numeros impares ingresados es %d\n", num_impares);

    return 0;
}