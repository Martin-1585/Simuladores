//Declaración de librerias
#include <stdio.h>
#include <ctype.h>
//Declaración de constantes
#define NUM_STUDENTS 5
#define SUBJECTS 3
#define MAX_GRADES 10
 
int main(){
    //Declaración de variables
    char materia_1 = 'M', materia_2 = 'F', materia_3 = 'L';
    float grades_M[NUM_STUDENTS][MAX_GRADES], sum_M, prom_M[NUM_STUDENTS],sum_promM = 0, prom_totalM;
    float grades_F[NUM_STUDENTS][MAX_GRADES], sum_F, prom_F[NUM_STUDENTS],sum_promF = 0, prom_totalF;
    float grades_L[NUM_STUDENTS][MAX_GRADES], sum_L, prom_L[NUM_STUDENTS],sum_promL = 0,prom_totalL;
    float prom_student[NUM_STUDENTS][SUBJECTS], mayor[SUBJECTS], menor[SUBJECTS], sum_generalstudent[NUM_STUDENTS] = {0}, prom_generalstudent[NUM_STUDENTS] = {0};
    int approve_M = 0, approve_F = 0, approve_L = 0, works_M, works_F, works_L;
    int notapprove_M = 0, notapprove_F = 0, notapprove_L = 0, valid;
    //Presentación del simulador
    printf("\t\x1B[35m             ********************\x1B[0m\n");
    printf("\t\x1B[34m             Simulador de escuela\x1B[0m\n");
    printf("\t\x1B[35m             ********************\x1B[0m\n");    
    printf("\t\x1B[33m                MATEMATICAS\x1B[0m\n");
    do{
        printf("Ingresa la cantidad de trabajos para la asignatura %c: ", materia_1); //Se solicita al usuario ingresar la cantidad de trabajos a recibir una nota 
        valid = scanf("%d", &works_M);
        while(getchar() != '\n'); //Se limpia el buffer del teclado
        if (valid != 1 || works_M < 1 || works_M > MAX_GRADES){
            printf("\x1B[31mDato no valido, ingrese nuevamente\x1B[0m\n"); //Mensaje de rechazo de datos 
        }
    } while (valid != 1 || works_M < 1 || works_M > MAX_GRADES);
    printf("\n");
    for (int i = 0; i < NUM_STUDENTS; i++){ //Con la estructura FOR se logra asignar diferentes valores de fila
        sum_M = 0; //Se debe reiniciar el acumuldor para en cada vuelta tome las notas de cada estudiante
        for (int j = 0; j < works_M; j++){ //Con la estructura FOR se logra asignar diferentes valores de columna
            do{
                printf("Ingrese la nota del estudiante %d en la actividad %d: ", i + 1, j + 1);
                valid = scanf("%f", &grades_M[i][j]); //Con la ayuda de un pointer de tipo entero se determina que los valores a ingresar solo sean digitos
                while(getchar() != '\n'); //Funcion gethcar() para limpiar el buffer del teclado 
                if (valid != 1 || grades_M[i][j] < 0 || grades_M[i][j] > 10){
                    printf("\x1B[31mDato no valido, ingrese nuevamente\x1B[0m\n"); //Mensaje de rechazo cada que el usuario ingresa un caracter, valores negativos o valores superiores a 10
                }
            } while (valid != 1 || grades_M[i][j] < 0 || grades_M[i][j] > 10);
            sum_M += grades_M[i][j];//El acumulador suma las notas ingresadas por el usuario 
        }
        prom_M[i] = sum_M/works_M; //En un arreglo unidimensional se guarda todos los promedios de la materia de Matemáticas
        sum_promM +=prom_M[i]; //Con otro acumulador se suma todos los promedios de la materia
        if (prom_M[i] >= 6){ //Una vez obtenido el promedio se realiza un análisis, si el promedio del estudiante es mayor o igual a 6 entonces el contador de aprobados de la materia aumenta
            approve_M++;
        } else { //En caso contrario, aumenta el contador de desaprobados
            notapprove_M++;
        }
        printf("\t------------------------------------------------------\n");
    }
    prom_totalM = sum_promM / NUM_STUDENTS; //Para sacar el promedio de la clase en la materia se toma el acumulador de promedios y se lo divide para la cantidad de estudiantes
    printf("\t\x1B[33m                FISICA\x1B[0m\n");
    do{
        printf("Ingresa la cantidad de trabajos para la asignatura %c: ", materia_2); //Se solicita que ingrese la cantidad de trabajos por materias
        valid = scanf("%d", &works_F);
        while(getchar() != '\n'); //Se debe limpiar el buffer del teclado
        if (valid != 1 || works_F < 1 || works_F > MAX_GRADES){
            printf("\x1B[31mDato no valido, ingrese nuevamente\x1B[0m\n"); //Mensaje de rechazo de datos
        }
    } while (valid != 1 || works_F < 1 || works_F > MAX_GRADES);
    printf("\n");
    for (int i = 0; i < NUM_STUDENTS; i++){ //Con la estructura FOR se logra asignar diferentes valores de fila 
        sum_F = 0; //Se debe reiniciar el acumulador para que sume solo las notas de un estudiante a la vez    
        for (int j = 0; j < works_F; j++){ //Con la estructura FOR se logra asignar diferentes valores de columna
            do{
                printf("Ingrese la nota del estudiante %d en la actividad %d: ", i + 1, j + 1);
                valid = scanf("%f", &grades_F[i][j]); //Con la ayuda de un pointer de tipo entero se determina que los valores a ingresar solo sean digitos
                while(getchar() != '\n'); //Funcion gethcar() para limpiar el buffer del teclado 
                if (valid != 1 || grades_F[i][j] < 0 || grades_F[i][j] > 10){
                    printf("\x1B[31mDato no valido, ingrese nuevamente\x1B[0m\n"); //Mensaje de rechazo cada que el usuario ingresa un caracter, valores negativos o valores superiores a 10
                }
            } while (valid != 1 || grades_F[i][j] < 0 || grades_F[i][j] > 10);
            sum_F+=grades_F[i][j]; //El acumulador suma todas las notas de los estudiantes en la materia de Fisica
        }
        prom_F[i] = sum_F / works_F; //Se guarda todos los promedios de los estudiantes en una arreglo unidimensional 
        sum_promF+=prom_F[i]; //Con un acumulador se suma todos los proemdios de los estudiantes
        if (prom_F[i] >= 6){ //Se analiza si el promedio de cada estudiante es mayor o igual 6 para que el contador de aprobados aumente
            approve_F++;
        } else { //En caso contrario, el contador de desaprobados aumenta 
            notapprove_F++;
        }
        printf("\t------------------------------------------------------\n");
    }
    prom_totalF = sum_promF / NUM_STUDENTS; //Para sacar el promedio de la clase en la materia se toma el acumulador de promedios y se lo divide para la cantidad de estudiantes
    printf("\t\x1B[33m                LENGUAJE\x1B[0m\n");
    do{
        printf("Ingresa la cantidad de trabajos para la asignatura %c: ", materia_3); //Se solicita al usuario que ingrese la cantidad de trabajos en la materia
        valid = scanf("%d", &works_L);
        while(getchar() != '\n'); //Se debe limpiar el buffer del teclado 
        if (valid != 1 || works_L < 1 || works_L > MAX_GRADES){
            printf("\x1B[31mDato no valido, ingrese nuevamente\x1B[0m\n"); //Mensaje de rechazo de datos
        }
    } while (valid != 1 || works_L < 1 || works_L > MAX_GRADES);
    printf("\n");
    for (int i = 0; i < NUM_STUDENTS; i++){ //Con la estructura FOR se logra asignar diferentes valores de fila 
        sum_L = 0; //Se debe reiniciar el acumulador para que sume solo las notas de un estudiante a la vez    
        for (int j = 0; j < works_L; j++){ //Con la estructura FOR se logra asignar diferentes valores de columna
            do{
                printf("Ingrese la nota del estudiante %d en la actividad %d: ", i + 1, j + 1);
                valid = scanf("%f", &grades_L[i][j]); //Con la ayuda de un pointer de tipo entero se determina que los valores a ingresar solo sean digitos
                while(getchar() != '\n'); //Funcion gethcar() para limpiar el buffer del teclado 
                if (valid != 1 || grades_L[i][j] < 0 || grades_L[i][j] > 10){
                    printf("\x1B[31mDato no valido, ingrese nuevamente\x1B[0m\n"); //Mensaje de rechazo cada que el usuario ingresa un caracter, valores negativos o valores superiores a 10
                }
            } while (valid != 1 || grades_L[i][j] < 0 || grades_L[i][j] > 10);
            sum_L+=grades_L[i][j]; //El acumulador suma todas la notas de la materia de Lengua 
        }
        prom_L[i] = sum_L / works_L; //En un arreglo unidimensional se guardan los promedios de los estudiantes 
        sum_promL+=prom_L[i]; //Un acumulador para sumar todos los promedios de la materia de Lengua
        if (prom_L[i] >= 6){ //Se analiza si el promedio es mayor o igual a 6 para que así el contador de aprobados aumente
            approve_L++;
        } else { //Caso contrario, el contador de desaprobados aumenta 
            notapprove_L++;
        }
        printf("\t------------------------------------------------------\n");
    }
    prom_totalL = sum_promL / NUM_STUDENTS; //Para sacar el promedio de la clase en la materia se toma el acumulador de promedios y se lo divide para la cantidad de estudiantes
    for (int i = 0; i < NUM_STUDENTS; i++){ //Se transferir los datos de los arreglos unidimensionales en donde se almacenan los promedios de cada materia a una matriz
        prom_student[i][0]=prom_M[i]; //Para la primera columna se toma los valores de los promedios de Matemáticas 
        prom_student[i][1]=prom_F[i]; //Para la segunda columna se toma los valores de los promedios de Fisica
        prom_student[i][2]=prom_L[i]; //Para la tercera columna se toma los valores de los promedioa de Lengua 
    }

    for (int j = 0; j < SUBJECTS; j++){
        mayor[j] = prom_student[0][j]; //Se declara que el promedio más alto por materia es el primer dato de la matriz en un arreglo unidimensional 
        menor[j] = prom_student[0][j]; //Se declara que el promedio más bajo por materia es el primer dato de la matriz en un arreglo unidimensional 
        for (int i = 1; i < NUM_STUDENTS; i++){ //Se inicializa el contador en 1 para se tome en cuenta desde el siguiente valor de la columna 
            if (prom_student[i][j] > mayor[j]){ //Se compara si los valores posteriores son mayores al primer dato, de ser el caso se reeemplaza la variable con este nuevo dato
                mayor[j] = prom_student[i][j];
            }
            if (prom_student[i][j] < menor [j]){ //Se compara si los valores posteriores son menores al primer dato, de ser el caso se reeemplaza la variable con este nuevo dato
                menor[j] = prom_student[i][j];
            } 
        }
    }
    printf("\t   \x1B[33mRESULTADOS DE LOS ESTUDIANTES\x1B[0m\n");
    for (int i = 0; i < NUM_STUDENTS; i++){
        float max_student = prom_student[i][0]; //Se declara un variable la cual dice que el primer dato de la fila de la matriz es el promedio más alto del estudiante
        float min_student = prom_student[i][0]; //Se declara un variable la cual dice que el primer dato de la fila de la matriz es el promedio más bajo del estudiante
        sum_generalstudent[i] = prom_student[i][0] + prom_student[i][1] + prom_student[i][2]; //Un arreglo unidimanesional guarda la suma de los promedios de las 3 asignaturas 
        prom_generalstudent[i] = sum_generalstudent[i] / SUBJECTS; //Para sacar el promedio por estudiante se necesita tomar la suma previa y dividirla para la cantidad de materias del estudiantes
        for (int j = 1; j < SUBJECTS; j++){ //El contador se inicializa en 1 para se compare desde el siguiente valor de la fila 
            if (prom_student[i][j] > max_student){ //Se compara el siguiente valor de la fila para ver si es mayor al primer dato, de ser el caso se reeemplaza la variable de mayor con este nuevo dato
                max_student = prom_student[i][j];
            }
            if (min_student > prom_student[i][j]){ //Se compara si el primer dato es mayor que el siguiente dato, de ser el caso se reeemplaza la variable de mayor con este nuevo dato
                min_student = prom_student[i][j];
            }
        }

        printf("Estudiante %d:\n", i + 1); //Se despliega los resultados por cada estudiante
        printf("\t  Promedio General: %.2f\n", prom_generalstudent[i]);        
        printf("  Promedios: M = %.2f | F = %.2f | L = %.2f\n",
               prom_student[i][0], prom_student[i][1], prom_student[i][2]); //Se llama a los valores de la matriz de promedio para que se desplieguen los promedios de cada asignatura 
        printf("\x1B[33mMayor promedio\x1B[0m: = %.2f\n", max_student);
        printf("\x1B[33mMenor promedio\x1B[0m: = %.2f\n\n", min_student);
    }
    printf("\t      \x1B[33mRESULTADOS DE LAS ASIGNATURAS\x1B[0m\n");
    printf("Los promedios generales en las asignaturas son:\n\t%c - %.2f | %c - %.2f | %c - %.2f", materia_1, prom_totalM, materia_2, prom_totalF, materia_3, prom_totalL); //Se muestra los promedios generales
    printf("\nLos promedios mas altos en las asignaturas son:\n\t%c - %.2f | %c - %.2f | %c - %.2f", materia_1, mayor[0], materia_2, mayor[1], materia_3, mayor[2]); //Se muestra los valores de los arreglos de mayor con sus índices
    printf("\nLos promedios mas bajos en las asignaturas son:\n\t%c - %.2f | %c - %.2f | %c - %.2f\n", materia_1, menor[0], materia_2, menor[1], materia_3, menor[2]); //Se muestra los valores de los arreglos de menor con sus índices
    printf("Los aprobados en las asignaturas son: \n\t %c - %d | %c - %d | %c - %d\n", materia_1, approve_M, materia_2, approve_F, materia_3, approve_L);
    printf("Los desaprobados en las asignaturas son: \n\t %c - %d | %c - %d | %c - %d", materia_1, notapprove_M, materia_2, notapprove_F, materia_3, notapprove_L);

    return 0;
}