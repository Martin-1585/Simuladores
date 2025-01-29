/*
    Examen progreso 3
    Nombre: Martin Olalla
    Docente:Anita Yanez
*/
//Declaracion de librerias
#include <stdio.h>
#include <ctype.h>
//Variables fijas
#define BASICA 2000
#define INTERMEDIA 3000
#define COMPLETA 5000 
#define year_ 2025

int main(){
    //Declaracion de variables
    int dia, mes, year, edad, historial_medico, incremento;
    float poliza;
    char cobertura, respuesta;
    int dia_actual=29, mes_actual_= 1;
    //Presentación del programa
    printf("\t********************************************\n");
    printf("\t           Simulador de cobertura\n");
    printf("\t********************************************\n");
    do{
        //Se solicita al usuario ingresar una opcion de cobertura
        do{
            printf("Ingrese el tipo de cobertura(B para Basica, I para intermedia, C para Completa)\n");
            scanf(" %c", &cobertura);
            cobertura=toupper(cobertura);
            if (cobertura != 'B' && cobertura != 'I' && cobertura != 'C'){
               printf("Cobertura no valida\n");
            }
        } while (cobertura != 'B' && cobertura != 'I' && cobertura != 'C' );
        //Se solicita al usuario ingresar su fecha de nacimiento
        do{
            printf("Ingrese su fecha de nacimiento\n");
            scanf("%d %d %d", &dia, &mes, &year);
            if (dia<0 || dia>31){
                printf("Dia no valido\n");
            } 
            if (mes <0 || mes >12){
                printf("Mes no valido\n");
            }
            if (year<1925 || year>2025){
                printf("Anio no valido\n");
            }
        } while (dia<0 || dia>31 || mes <0 || mes >12 || year<1900 || year>2025);
        edad=year_-year;
        if (mes > mes_actual_ || (mes==mes_actual_ && (dia>dia_actual))){
            edad--;
        }
        printf("Tiene de edad: %d\n", edad);
        //Se le pregunta al usuario cual es su historial medico
        do{
            printf("Tiene historial con enfermedades cronicas(1. Si/ 0. No)\n");
            scanf("%d", &historial_medico);
            if (historial_medico<0 || historial_medico>1){
                printf("Dato no valido\n");
            }
        } while (historial_medico<0 || historial_medico>1);
        //En base a la corbetura se comienza a calcular
        switch (cobertura){
        case 'B':
            //Si el historial medico es 1 se incrementa un 30%
            if (historial_medico==1){
                incremento=BASICA*0.30;
                poliza=BASICA+incremento;
            } else if (edad>50){ //Si la edad es mayor a 50 sin enfermedades cronicas se incrementa un 20%
                incremento=BASICA*0.20;
                poliza=BASICA+incremento;    
            }else{
                poliza=BASICA; //Si no cumple ninguno de los puntos anteriores el valor de la poliza no aumenta
            }
            printf("El costo de la poliza de salud es: %.2f\n", poliza);
            break;
        case 'I':
            //Si el historial medico es 1 se incrementa un 30%
            if (historial_medico==1){
                incremento=INTERMEDIA*0.30;
                poliza=INTERMEDIA+incremento;
            } else if (edad>50){ //Si la edad es mayor a 50 sin enfermedades cronicas se incrementa un 20%
                incremento=INTERMEDIA*0.20;
                poliza=INTERMEDIA+incremento; 
            }else{ //Si no cumple ninguno de los puntos anteriores el valor de la poliza no aumenta
                poliza=INTERMEDIA;
            }
            printf("El costo de la poliza de salud es: %.2f\n", poliza);
            break;

        case 'C':
            //Si el historial medico es 1 se incrementa un 30%
            if (historial_medico==1){ 
                incremento=COMPLETA*0.30;
                poliza=COMPLETA+incremento;
            } else if (edad>50){ //Si la edad es mayor a 50 sin enfermedades cronicas se incrementa un 20%
                incremento=COMPLETA*0.20;
                poliza=COMPLETA+incremento; 
            }else{ //Si no cumple ninguno de los puntos anteriores el valor de la poliza no aumenta
                poliza=COMPLETA;
            }
            printf("El costo de la poliza de salud es: %.2f\n", poliza);
            break;
        
        default:
            printf("Opcion no valida\n"); //Si elige una opcion no valida 
            break;
        }
        do{
            //Se le pregunta al usuario si desea ingresar otros datos
            printf("Desea calcular otra poliza (S/N)\n"); 
            scanf(" %c", &respuesta); 
            respuesta=toupper(respuesta);
            if (respuesta != 'S' && respuesta !='N'){ //Si la respuesta no es S o N se muestra un rechazo de datos
                printf("Dato no valido, ingrese nuevamente\n");
            }
        } while (respuesta != 'S' && respuesta !='N'); 
    } while (respuesta=='S'); //El programa termina cuando el usuario ingresa N
    printf("\tFIN DEL PROGRAMA\n");
    
    return 0;
}