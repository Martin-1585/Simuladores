/*
    Examen progreso 3
    Nombre: Martin Olalla
    Docente:Anita Yanez
*/
//Declaracion de librerias
#include <stdio.h>
//Variables fijas
#define BASICA 2000
#define INTERMEDIA 3000
#define COMPLETA 5000 
#define year_ 2025

int main(){
    //Declaracion de variables
    int dia, mes, year, edad, historial_medico, incremento, incremento_cronica;
    float poliza;
    char cobertura, respuesta;
    //Presentación del programa
    printf("\t********************************************\n");
    printf("\t           Simulador de cobertura\n");
    printf("\t********************************************\n");
    do{
        //Se solicita al usuario ingresar una opcion de cobertura
        do{
            printf("Ingrese el tipo de cobertura(B para Basica, I para intermedia, C para Completa)\n");
            scanf(" %c", &cobertura);
            if (cobertura != 'B' && cobertura != 'b' && cobertura != 'I' && cobertura != 'i' && cobertura != 'C' && cobertura != 'c'){
               printf("Cobertura no valida\n");
            }
        } while (cobertura != 'B' && cobertura != 'b' && cobertura != 'I' && cobertura != 'i' && cobertura != 'C' && cobertura != 'c');
        //Se solicita al usuario ingresar su fecha de nacimiento
        do{
            printf("Ingrese su fecha de nacimiento\n");
            scanf("%d %d %d", &dia, &mes, &year);
            if (dia<0 || dia>31 || mes <0 || mes >12 || year<1900 || year>2024){
                printf("Fecha no valida\n");
            }
        } while (dia<0 || dia>31 || mes <0 || mes >12 || year<1900 || year>2025);
        //Se le pregunta al usuario cual es su historial medico
        do{
            printf("Tiene historial con enfermedades cronicas(1. Si/ 0. No)\n");
            scanf("%d", &historial_medico);
            if (historial_medico<0 || historial_medico>1){
                printf("Dato no validSo\n");
            }
        } while (historial_medico<0 || historial_medico>1);
        //Se 
        edad=year_-year;
        //En base a la corbetura se comienza a calcular
        switch (cobertura){
        case 'B':
        case 'b':
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
        case 'i':
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
        case 'c':
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
            if (respuesta != 'S' && respuesta != 's' && respuesta !='N' && respuesta != 'n'){ //Si la respuesta no es S o N se muestra un rechazo de datos
                printf("Dato no valido, ingrese nuevamente\n");
            }
        } while (respuesta != 'S' && respuesta != 's' && respuesta !='N' && respuesta != 'n'); 
    } while (respuesta=='S' || respuesta=='s'); //El programa termina cuando el usuario ingresa N
    printf("\tFIN DEL PROGRAMA\n");
    
    return 0;
}