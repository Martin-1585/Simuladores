//Tarea Algoritmos
//Simulador de edades: Imprima  la  cantidad  de  mujeres  mayores  de  edad  y  la  cantidad  de  hombres  mayores  de  edad  de  un  total  de  N  personas.  
//Muestre  también sus porcentajes.
//Nombre: Martin Olalla
//Docente: Anita Yanez
//Fecha: 12-12-2024
//Declaracion de librerias
#include <stdio.h>

int main(){
    // Declaracion de variables
    int edad, cantidad, i, mujeres_cantidad, hombre_cantidad;
    float porcentaje_m, porcentaje_h;
    char genero;
    //Contadores inicializados
    mujeres_cantidad = 0;
    hombre_cantidad = 0;
    //Presentacion del programa
    printf("\t***********************\n");
    printf("\t  Simulador de edades \n");
    printf("\t***********************\n");
    //Ingreso de datos de entrada
    do{
        printf("Ingrese la cantidad de personas\n");
        scanf("%d", &cantidad);
        if (cantidad<=0){
            printf("Datos no validos\n"); //Bucle hasta que se ingrese un dato de cantidad valido
        }
    }while(cantidad<=0);
    
    for ( i = 0; i < cantidad; i++){
        //Ingreso del genero de la persona
        printf("Ingrese el genero de la persona (Hombre (H)/ Mujer (M))\n");
        scanf(" %c", &genero);
        //Ingreso de la edad de la persona
        do{
            printf("Ingrese la edad de la persona (Mayor de edad)\n");
            scanf("%d", &edad);
            if (edad<=0){
                printf("Datos no validos\n"); //Bucle hasta que se ingrese un dato de cantidad valido            
            }
        }while(edad<=0); 
        
        if (edad>=18){
            switch (genero){
                case 'H': 
                case 'h':
                    //Contador con paso 1 cada vez que se ingrese un hombre mayor de edad
                    hombre_cantidad++;
                    break;

                case 'M':
                case 'm':
                    //Contador con paso 1 cada vez que se ingrese un mujer mayor de edad
                    mujeres_cantidad++;
                    break;
                default:
                    printf("Genero no existente\n");
                    break;
            }
        } else {
            printf("La persona no es mayor de edad\n");
        }
    }
    //Porcentaje de hombres mayores de edad
    porcentaje_h=((float)hombre_cantidad/(float)cantidad)*100;
    //Porcentaje de mujeres mayores de edad
    porcentaje_m=((float)mujeres_cantidad/(float)cantidad)*100;
    //Mostrar la cantidad de hombres y mujeres mayores de edad
    printf("\nLa cantidad de hombres mayores de edad es %d\n", hombre_cantidad);
    printf("La cantidad de mujeres mayores de edad es %d\n", mujeres_cantidad);
    //Mostrar los porcentajes
    printf("\nEl porcentaje de hombres mayores de edad es %.2f%% \n", porcentaje_h);
    printf("El porcentaje de mujeres mayores de edad es %.2f%% \n", porcentaje_m);
    
    return 0;
}