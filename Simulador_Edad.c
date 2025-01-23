//Tarea Algoritmos
//Simulador de edad (Adivina la edad de Matusalen): El usuario debe ingresar una edad intentando adivinar la edad,
//si la edad ingresada es menor a la de Matusalen, se despliega un mensaje indicado esto, y es mayor lo mismo.
//Si el usuario adivina la edad se debe finalizar el programa. 
//Nombre:Martín Olalla
//Docente: Anita Yanez
//Fecha: 10-12-2024

//Declaracion de librerias
#include <stdio.h>

//Inicio del programa
int main(){
    int numero, edad, respuesta;
    int i=0; //Contador inicializado
    
    edad=969;
    //Ingreso al bucle
    //Mientras que la respuestas no sea 0 se ingresa al bucle
    while (respuesta!=0){
        //Presentacion del simulador
        printf("\t*******************************\n");
        printf("\t       Simulador de edad\n");
        printf("\t Adivine la edad de Matusalen\n");
        printf("\t*******************************\n");
        //Mientras que la edad ingresada no sea igual a la de Matusalen y el contador sea menor a 3, ingresa al bucle  
        while (i<3 && numero!=edad){
        i++; //Contador inicializado
        //Ingreso de datos de entrada (Edad del usuario)
        //Validacion de datos de entrada con Repetir Mientras Que
        do{
            printf("\nIntente adivinar la edad de Matusalen\n");
            scanf("%d", &numero);
            if (numero<0){
                printf("Edad no valida (Mayor a 0)\n"); //Mensaje de rechazo de datos si ingresa edades menores a 0
            }
        }while (numero<0); //Bucle mientras el usuario ingrese edades menores a 0

        //Sentencias condicionales
        //Mensaje si la edad ingresada es menor 
        if (numero<edad){
            printf("La edad ingresada es menor a la de Matusalen\n"); 
        } else if (numero>edad){
            //Mensaje si la edadingresada es mayor
            printf("La edad ingresada es mayor a la de Matusalen\n");
        }
        //Mensaje si se terminan los 3 intentos
        if (i==3 && numero != edad){ 
            printf("\nHa perdido el juego ;(\n");
            //Mostrar la edad correcta 
            printf("\nLa edad era %d\n", edad); 
        }
        }
        //Sentencias condicionales
        if (i==3 && numero != edad){
           //Si se terminan los 3 intentos y no se acerto la edad, se debe preguntar si se desea repetir
           printf("Desea reiniciar el programa (1.Si / 0. No)\n");
           scanf("%d", &respuesta);
           i=0; //Reinicio de contadores
        } else if (numero==edad){
           //Mensaje de salida si se adivina la edad 
           printf("Bravooo... Adivino la edad de Matusalen");
           respuesta=0; //Valor para acabar el programa
        }
                 
    }
    return 0;

}