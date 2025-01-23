//Tarea Algoritmos
//Simulador de Universidad: Se necesita la informacion de los estudiantes de una universidad,
//se necesita la edad, la cantidad de materias finales aprobadas y desaprobradas,
//se debe mostrar el porcentaje de materias aprobadas y desaprobadas; la edad si tiene el triple de aprobadas a desaprobadas,
//y finalmente, la cantidad estudiantes que tienen 21 años y 2 o más materias desaprobadas. 
//Nombre: Martin Olalla
//Docente: Anita Yanez
//Fecha: 12-12-2024
//Declaracion de librerias
#include <stdio.h>

int main(){
    //Variables
    int i, materiasa_aprobadas, materias_desaprobadas, edad, mayorde21;
    int estudiantes, total_maaterias;
    //Contadores inicializados
    mayorde21=0;
    //Presentacion del prrama
    printf("\t**********************************\n");
    printf("\t      Simulador de Universidad    \n");
    printf("\t**********************************\n\n");
    //Datos de entrada
    //Sentencias Repetir Mientras Que para validar datos de entrada
    do{
        printf("Ingrese la cantidad de estudiantes(Mayor a 0)\n");
        scanf("%d", &estudiantes);
        if (estudiantes<=0){
            printf("Datos no validos\n"); //Mensaje de rechazo de datos
        }
    }while(estudiantes<=0);
    
    //Definicion de arreglos para almacenar el porcentaje de materias aprobadas y desaprobadas 
    float aprobadas [estudiantes], desaprobadas [estudiantes];
    for ( i = 0; i < estudiantes; i++){
        //Ingreso de edad del estudiante
        do{
            printf("Ingrese la edad del estudiante %d (Mayor a 0)\n", i+1);
            scanf("%d", &edad);
            if (edad<=0){
                printf("Dato no valido\n"); //Mensaje de rechazo de datos
            }
        }while(edad<=0 || edad<18);
        //Ingreso de materias aprobadas del estudiante
        do{
            printf("Ingrese la cantidad de materias finales aprobadas del estudiante %d\n",i+1);
            scanf("%d", &materiasa_aprobadas);
            if (materiasa_aprobadas<0){
                printf("Datos no validos\n"); //Mensaje de rechazo de datos
            }
        }while(materiasa_aprobadas<0); //Bucle en el caso de ingresar valores menores a 0
        //Ingreso de materias desaprobadas del estudiante
        do{
            printf("Ingrese la cantidad de materias finales desaprobadas del estudiante %d\n",i+1);
            scanf("%d", &materias_desaprobadas);
            if(materias_desaprobadas<0){
                printf("Datos no validos\n"); //Mensaje de rechazo de datos
            }
        }while(materias_desaprobadas<0); //Bucle en el caso de ingresar valores menores a 0

        //Total de materias, se obtiene de sumar la cantidad de materias aprobadas y desaprobadas
        total_maaterias=(materiasa_aprobadas)+(materias_desaprobadas);
        //Arreglos para guardar los porcentajes de la materias aprobadas y desaprobadas
        aprobadas[i]=((float)materiasa_aprobadas/(float)total_maaterias)*100;
        desaprobadas[i]=((float)materias_desaprobadas/(float)total_maaterias)*100;
        //Si la edad del estudiante es mayor a 21 y si desaprobo 2 materias finales se inicializa un contador
        if (edad>21 && materias_desaprobadas>2){
            mayorde21++;
        }
        //Condicional si la cantidad de materias aprobadas es el triple de las desaprobadas, se muestra la edad del estudiante
        if (materiasa_aprobadas==(3*materias_desaprobadas)){
            printf("La edad del estudiante que tiene el triple de aprobadas que desaprobadas es %d\n\n", edad);
        }
    }  
    //Salida con la cantidad de estudiantes mayores a 21 y que desaprobaron más de 2 materias
    printf("\nLa cantidad de estudiantes mayores a 21 y que desaprobaron mas de 2 materias finales es %d\n\n", mayorde21);
    //Mostrar los porcentajes de aprobados y desaprobados de cada estudiante
    printf("El porcentaje total de materias aprobadas de los estudiantes\n\n");
    for ( i = 0; i < estudiantes; i++){
       printf("Estudiante %d: %.2f%%\n", i+1, aprobadas[i]); //Mostrar los porcentaje de materias aprobadas de cada estudiante, gracias a los arreglos
    }
    printf("\nEl porcentaje total de materias desaprobadas de los estudiantes\n\n");
    for ( i = 0; i < estudiantes; i++){
       printf("Estudiante %d: %.2f%%\n", i+1, desaprobadas[i]); //Mostrar los porcentaje de materias desaprobadas de cada estudiante, gracias a los arreglos
    }
    return 0;
}