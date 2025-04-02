//ANTHONY FIALLOS Y MARTIN OLALLA
#include <stdio.h>
#include <ctype.h>
// Definición de constante
#define ASISTENCIA 70  

int main() {
    //Declaración de variables 
    int num_students, days, valid, attendances = 0;
    float porcentaje;
    char attendance;
    //Presentación del simulador
    printf("\t\x1B[34m*******************************\n");
    printf("\t\x1B[35m    Simulador de asistencia    \n");
    printf("\t\x1B[34m*******************************\x1B[0m\n");
    //Validaión de datos, se utiliza un pointer y una función para limpiar el buffer del teclado 
    do{
        printf("Ingrese la cantidad de estudiantes: ");
        valid = scanf("%d", &num_students);
        if (valid!= 1 || num_students < 0){
            printf("\x1B[33mDato no valido\x1B[0m\n");
            while (getchar() != '\n'); //Funcion para limpiar el buffer de entrada de datos 
        } 
    } while (valid != 1 || num_students < 0); //Mientras que el usuario ingrese un dato que no sea un dígito o un numero negativo la instrucción se repite
    do{
        printf("Ingrese la cantidad de días a registrar: ");
        valid = scanf("%d", &days);
        if (valid != 1 || days < 0){
            printf("\x1B[33mDato no valido\x1B[0m\n"); //Mensaje de rechazo de datos 
            while (getchar() != '\n'); //Funcion para limpiar el buffer de entrada de datos
        }
    } while (valid != 1 || days < 0); //Mientras que el usuario ingrese un dato que no sea un dígito o un numero negativo la instrucción se repite 
    for (int i = 0; i < num_students; i++) {
        //Se solicita al usuario ingresar la asistencia de los estudiantes con la letra A, en caso contrario con F
        printf("\nIngrese las asistencias del estudiante %d (A para presente, F para falta):\n", i + 1);
        for (int j = 0; j < days; j++) {
            do{
                printf("Día %d: ", j + 1); //Se usa un ciclo For para pedir al usuario que ingrese el registro de asistencias 
                scanf(" %c", &attendance);
                attendance = toupper(attendance); //Aunque el usuario meta un letra minúscula la función toupper la trnasforma en mayúscula para tener un código más optimizado
                if (attendance != 'A' && attendance != 'F'){
                    printf("\x1B[33mDato no valido\x1B[0m\n");
                    while (getchar() != '\n'); //Funcion para limpiar el buffer de entrada de datos
                }
            } while (attendance != 'A' && attendance != 'F'); //Cada que el usuario ingresa caracteres que no sean A o F se repite la instrucción 
            if (attendance == 'A') {
                attendances++; //Contador aumenta solo y solo si se ingresa la letra A
            }
        }
        //Se calcula el porcentaje dividiendo el valor del contador sobre la cantidad de días, y este valor multiplicarlo por 100
        porcentaje = ((float)attendances++ / (float)days) * 100;
        printf("Estudiante %d: %.2f%% asistencia", i + 1, porcentaje);
        if (porcentaje < ASISTENCIA) {
            printf(" - Reprobado por inasistencias (minimo 70%%)"); //Si el estudiante tiene un porcentaje por debajo de 70% se lo considera reprobado 
        }
        printf("\n");
        attendances = 0; //Reinicio de contador
    }
   
    return 0;
}
