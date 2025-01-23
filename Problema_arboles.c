/*
    Problemas sentencias repetitivas Do- While
    Nombres: Martin Olalla y Andres Paqui
    Docente: Anita Yanez
    Fecha: 07-01-2025
    Descripción: Realizar un programa en C que resuelva el siguiente problema: 
    En un bosque se necesita saber el promedio de diámetro de cada tronco de ciprés y el promedio de su altura. 
    El proceso termina cuando el usuario responde con una ‘N’, mientras tanto, debe responder con ‘S’.
*/
//Declaración de librerias
#include <stdio.h>

int main() {
    //Declaración de variables
    float diametro, altura, sum_diametro=0, sum_altura=0; //Acumuladores inicializados
    float prom_diametro, prom_altura;
    int i=0; //Contador inicializado 
    char respuesta; 
    //Presentación del programa
    printf("\t*********************************************************\n");
    printf("\t  Simulador del promedio de diametro y altura de troncos \n");
    printf("\t*********************************************************\n");
    
    do{
        printf("Ingrese los siguientes datos acerca de los troncos de cipres de un bosque\n");
        //Se solicita al usuario ingresar el diametro de cada tronco de cirpres
        do{
            printf("Ingrese el diametro del tronco %d (en cm)\n", i+1);
            scanf("%f",&diametro);
            if (diametro<0 || diametro>100){
                printf("Diametro no valido (No puede ser menor a 0 ni mayor a 1 m)\n");
            }
        } while (diametro<0 || diametro>100);
        //Se solicita al usuario ingresar la altura de cada tronco
        do{
            printf("Ingrese la altura del arbol %d (en metros)\n", i+1);
            scanf("%f",&altura);
            if (altura<0 || altura>30){
                printf("Altura no valida (No puede ser menor a 0 ni mayor a 30 m)\n");
            }
        } while (altura<0 || altura>30);
        
        //Acumuladores para tener un total de todos los datos ingresados
        sum_diametro+=diametro;
        sum_altura+=altura;
        //Paso del contador
        i++;
        //Preguntar si el usuario desea ingresar más valores
        printf("Desea ingresara otro tronco de cipres (N/S)\n");
        scanf(" %c", &respuesta);
        
    } while (respuesta =='S' || respuesta =='s'); //El proceso se repite mientras la respuesta ingresada por el usuario sea 'S'
    //Salida
    //Se calcula el promedio del diametro con la cantidad total del acumulador dividido por la cantidad que el contador repitió
    prom_diametro=(sum_diametro/(float)i);
    //Se calcula el promedio de la altura con la cantidad total del acumulador dividido por la cantidad que el contador repitió
    prom_altura=(sum_altura/(float)i);
    printf("*********************************************************\n");
    //Se despliega un mensaje que muestra el promedio del diametro de los troncos de cipres usando la formula de promedio de diametro de arriba
    printf("El promedio de diametro de los troncos en el bosque es %.2f cm\n", prom_diametro);
    //Se despliega un mensaje que muestra el promedio de altura de los troncos de cipres usando la formula de promedio de altura se arriba
    printf("El promedio de altura de los troncos en el bosque es %.2f m\n", prom_altura);
    
    return 0;
}
