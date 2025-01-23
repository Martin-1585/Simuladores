/*
    Proyecto Final
    Algoritmos
    Nombres: Martín Olalla, Andres Paqui, Ihoshua Terán
    Fecha: 19-01-2025
    Docente: Anita Yanez
    Descripción: El programa simula el funcionamiento de una máquina expendedora: 
    1.	Presenta al usuario tres opciones de refrescos con precios diferentes. 
    2.	Solicita la selección del refresco y el ingreso del monto. 
    3.	Calcula el cambio y devuelve monedas de 10, 5, 2 y 1 peso. 
    4.	Valida si el monto ingresado es suficiente y permite múltiples intentos si no lo es. 
*/
//Declaracion de librerias
#include <stdio.h>

int main() {
    // Declaración de variables
    int option, cambio, price, falta, new_value; 
    int value, prices [3]= {20, 15, 10}; //Arreglo con los precios de las bebidas 
    char respuesta;
    int coins[4]={10, 5, 2, 1}; //Arreglo con el cambio que puede dar la máquina
    int amount[4]={0}; //Arreglo que determina la cantidad de cada monedas que tendra el usuario  
    //Presentación del programa
    printf("\t*********************************\n");
    printf("\tSimulador de maquina de refrescos\n");
    printf("\t*********************************\n");
    //Presentación del menu
    do{
        printf("\t-----------------MENU-------------\n");
        printf("1. Coca Cola - 20 pesos\n");
        printf("2. Fanta - 15 pesos\n");
        printf("3. Sprite - 10 pesos\n");
        printf("\t---------------------------------\n");
        //Se solicita al usuario ingresar una opcion del menu
        do{
            printf("Ingrese su eleccion (1, 2, 3)\n");
            scanf("%d", &option);
            if (option<=0 || option>3){
                printf("Porfavor ingrese una opcion valida\n"); //Cada que el usuario ingrese una opción invlaida se desplega un mensaje de rechazo
            }
        } while (option<=0 || option>3); //Hasta que el usuario no ingrese una opción válida se repite la instrucción

        //Se solicita al usuario ingresar un monto entero 
        do{
            printf("Ingrese el monto a pagar\n");
            scanf("%d", &value);
            if (value<=0){
                printf("Monto no valido (Deber ser mayor a 0)\n"); //Cada que el usuario ingrese una monto invalido se despliega un mensaje de rechazo
            }
        } while (value<=0); //Hasta que el usuario no ingrese un monto válido se repite la instrucción
        //Para obtener el precio de la bebida se asigna a la variable price los valores del arreglo prices, 
        //Para selecionar el valor del arreglo se resta a la opción escogida una unidad.
        price=prices[option-1]; 
        //Se analiza si el monto es menor al precio de la bebida escogida 
        while (value < price){
            falta=price-value; //Se realiza una operación la cual va a mostrar al usuario cuantos pesos le hace falta para completar el precio
            do{
                printf("El monto ingresado es insuficiente, porfavor ingrese %d pesos\n", falta); //Mensaje que muestra la cantidad de pesos faltantes
                scanf("%d", &new_value);
                if (new_value<=0){
                    printf("Monto no valido (Deber ser mayor a 0)\n"); //Si el monto que hace falta es menor o igual a 0, se pide al usuario ingresar nuevamente el monto
                }
            } while (new_value<=0);
            value=value+new_value; //El monto anterior se le suma la nueva cantidad ingresada, si el monto es mayor o igual al precio se sale del bucle
        }
        //Se necesita calcular el cambio, esto se logra restando el monto ingresado por el precio de la bebida seleccionada
        cambio= value - price;
        //Presentación del cambio
        printf("Cambio:\n");
        if(cambio == 0){
            //Si el cambio es cero se despliega un mensaje que indica que el usuario no va a recibir cambio ya que ingreso el valor justo de la bebida
            printf("No tiene cambio \n");
        }            
        else{
            //Calculo del calculo en monedas si el usuario ingresa un monto mayor al del precio 
            for (int i = 0; i < 4; i++){
                //Para calcular la cantidad de cada monedad se debe dar de cambio se usa el arreglo amount el cual no posee valores
                //Para hacer la operación se divide el cambio por el arreglo coins, el cual va cambiando de valor de monedas mientras la condición del FOR sea verdadera 
                amount[i]=cambio/coins[i];
                //En cada interación del FOR a la variable cambio se divide de manera para entera por la cantidad de monedas del arreglos coins 
                //En cada iteración el valor de coins cambia debido al contador (i) que usa los valores de distintos índices del arreglos mientras se de el FOR 
                cambio %= coins[i];
            }

            //Mostrar el cambio
            for (int i = 0; i < 4; i++){
                //Despues del anterior FOR se usa un condicional para determinar valores que estan en el arreglo amount son mayores a 0
                if (amount[i] > 0){
                    //Si el valor obtenido en amount es mayor a 0 se despliega el mensanje que dice cuantas de cada moneda se necesita para dar un cambio correcto
                    printf("%d de moneda(s) de %d pesos\n", amount[i], coins[i]);
                }
            }
        }
        printf("\t----------------------------------\n");
        //Se le pregunta al usuario si desea realizar otra compra
        do{
            printf("Desea realizar otra compra (N/S)\n");
            scanf(" %c", &respuesta);
            //Cada que la respuesta del usuario sea diferentes de N o S se solicita una respuesta valida
            if(respuesta != 'S' && respuesta != 's' && respuesta != 'N' && respuesta != 'n'){
                printf("Opcion no valida, vuelva a ingresar su respuesta \n");
            }
        } while(respuesta != 'S' && respuesta != 's' && respuesta != 'N' && respuesta != 'n'); //Hasta que el usuario ingrese una respuesta valida se repite la instruccion 
    } while (respuesta=='S' || respuesta=='s'); //Cada que el usuario ingrese la respuesta S o s se repite todo el proceso.
    //Mensaje de despedida al terminar el programa cuando el usuario ingrese N o n
    printf("\t------------SALIDA-------------\n");
    printf("Muchas gracias por usar esta maquina\n\n");
    printf("\tFIN DEL PROGRAMA\n");

    return 0;
}
