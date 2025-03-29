/* Taller 1 - Programación I
Docente: Bernarda Sandoval
Nombres: Martin Olalla y Ihoshua Teran 
Fecha: 26/03/2025
Descripción: Un pequeño comerciante necesita un programa en C para gestionar la venta de un único producto en su tienda, 
el programa debe permitir ventas del producto con restricciones de stock, reabastecer el stock, consultar la información del producto y ver las ganancias totales
*/
//Declaración de librerias
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    //Declaración de variables 
    int id, stock, cantidad, opcion, valido;
    float precio, total_ganancias = 0, ventas, descuento, ventas_des;
    char nombre[30];
    //Presentación del programa
    printf("\t\x1B[34m*****************************\n");
    printf("\t\x1B[35m Simulador de un comerciante \n");
    printf("\t\x1B[34m*****************************\n");
    do{
        printf("\x1B[0mIngrese el ID del producto (4 digitos): "); //Se solicita el ID del producto a vender (Solo digitos)
        valido = scanf("%d", &id); //La variable "valido" no es más que una variable estática de tipo entera, por lo que cualquier dato que no sea entero es rechazado
        if (valido != 1 || id < 1000 || id > 9999){
           printf("\x1B[33mID no valido\n"); //Mensaje de rechazo de datos 
           fflush(stdin); //Se usa fflush para limpiar el buffer de scanf
        } else {
            break;
        }
    } while (1); //Ciclo do-while para validar que los datos ingresados en ID sean validos
    fflush(stdin); //Se debe limpiar el buffer para que fgets funcione
    printf("\x1B[0mIngrese el nombre del producto: "); //Se solicita el nombre del producto
    fgets(nombre, sizeof(nombre), stdin); //Función fgets para registrar el nombre 
    do{
        printf("\x1B[0mIngrese la cantidad inicial en stock: "); //Se solicita la cantidad inicial de stock del producto
        valido = scanf("%d", &stock); //La variable "valido" no es más que una variable estática de tipo entera, por lo que cualquier dato que no sea entero es rechazado
        if (valido != 1 || stock <= 0){
            printf("\x1B[33mStock no valido\n"); //Mensaje de rechazo de datos
            fflush(stdin); //Se usa fflush para limpiar el buffer de scanf
        } else {
            break;
        }
    } while (1); //Ciclo do-while para validar que los datos ingresados en stock sean validos
    do{
        printf("\x1B[0mIngrese el precio unitario del producto: $ "); //S solicita el precio unitario del producto
        valido = scanf("%f", &precio); //La variable "valido" no es más que una variable estática de tipo entera, por lo que cualquier dato que no sea entero es rechazado
        if (valido != 1 || precio < 0){
            printf("\x1B[33mPrecio no valido\n"); //Mensaje de rechazo de datos
            fflush(stdin); //Se usa fflush para limpiar el buffer de scanf
        } else {
            break;
        }
    } while (1); //Ciclo de-while para validar que los datos ingresados en precio sean validos
    do {
        //Se presenta un menu de las posibles opciones que puede realizar el comerciante
        printf("\n\t\x1B[0mMenu de Opciones\n");
        printf("\x1B[0m1. Vender producto\n");
        printf("\x1B[0m2. Reabastecer producto\n");
        printf("\x1B[0m3. Mostrar informacion del producto\n");
        printf("\x1B[0m4. Mostrar total de ganancias\n");
        printf("\x1B[0m5. Salir\n");
        printf("\x1B[0mSeleccione una opcion: ");
        valido = scanf("%d", &opcion); //La variable "valido" no es más que una variable estática de tipo entera, por lo que cualquier dato que no sea entero es rechazado
        if (valido != 1){ //Con este condicional se valida que los datos ingresados sean digitos y no caracteres
            printf("\n\x1B[33mOpción inválida. Intente nuevamente.\n");
            fflush(stdin); //Se debe limpiar el buffer de scanf para que se permita la entrada de un nuevo dato
            continue; //La función continue permite que el programa continue
        }
        switch(opcion) {
            case 1:
                if (stock == 0){ //Si el usuario ya vendio todo su stock se despliega un mensaje que recomeinda reabastecer
                    printf("\n\x1B[33mNo hay suficiente stock, por favor reabastecer\n");
                    break;
                }
                printf("\n\x1B[0mSu stock actual es de %d unidades\n", stock); //Se despliega la cantidad de stock actual
                do{
                    printf("\x1B[0mIngrese el porcentaje descuento a aplicar al producto: %% "); //Se solicita al usuario ingresar un porcentaje de descuanto en cada venta
                    valido = scanf("%f", &descuento); //Con el pointer int se determina que los valores a ingresar solo sean numeros reales
                    if (valido != 1){
                        printf("\x1B[31mDatos ingresados no validos\n"); //Mensaje de rechazo en caso del ingreso de caracteres
                        fflush(stdin); //Limpiar el buffer por la entrada de datos no validos
                    } else if (descuento < 0 || descuento > 50){
                        printf("\x1B[33mDescuento no valido (Maximo 50%%)\n"); //Mensaje de rechazo en caso de un descuento negativo o superior a 50
                        fflush(stdin); //Limpiar el buffer por la entrada de datos no validos
                    } else {
                        break;
                    }
                } while (1);
                do{
                    printf("\n\x1B[0mIngrese la cantidad a vender: ");
                    valido = scanf("%d", &cantidad); //Con el pointer int se determina que los valores a ingresar solo sean numeros reales
                    if (valido != 1 || cantidad < 1){
                        printf("\x1B[31mLa cantidad a vender debe ser al menos una unidad, por favor ingrese nuevamente\n"); //Se muestra este mensaje solo si la cantidad es menor a 1 o invalida
                        fflush(stdin); //Se debe limpiar el buffer de scanf para el nuevo ingreso de datos
                    } else if (cantidad > stock){
                        printf("\x1B[33mLa cantidad a vender supera al stock, por favor ingrese nuevamente\n");
                        fflush(stdin); // Se debe limpiar el buffer de scanf para aceptar nuevos datos
                    } else {
                        break; //Si el usuario ingresa una cantidad valida se rompe la estructura repetitiva y se continua a la siguiente línea 
                    }
                } while (1); //Ciclo do-while que valida que no se ingresen caracteres ni numeros negativos
                ventas = (cantidad * precio);  //Para calcular las ventas se necesita que se multiplique la cantidad de unidades a vender por el precio unitario
                if (descuento > 0){
                    ventas_des =(ventas * (descuento/100)); //Se calcula el descuento multiplicando ventas por el descuento
                    ventas = ventas - ventas_des; //Para obtener el valor real del descuento se realiza una resta entra el valor de ventas y descuento
                    printf("\x1B[0mDio un ahorro de: $ %.2f\n", ventas_des); //Se muestra el ahorro que se da al cliente
                } 
                total_ganancias+=ventas; //Se acumula los valores de las ventas en la variable total_ganancias
                stock -= cantidad; //Se realiza una resta del stock después de cada venta
                printf("\x1B[0mVenta realizada. Con una ganancia de $ %.2f\n", ventas); //Mensaje informando cuanto se estima de ganancia  
                printf("\x1B[0mQuedan %d unidades en stock\n", stock); //Mensaje informando cuantas unidades de stock quedan    
                break;
            case 2:
                do{
                    printf("\n\x1B[0mIngrese la cantidad a agregar al stock: ");
                    valido = scanf("%d", &cantidad); //Con el pointer int se determina que los valores a ingresar solo sean numeros reales
                    if (valido != 1 || cantidad < 0){
                        printf("\n\x1B[33mLa cantidad ingresada no es valida, ingrese nuevamente\n");
                        fflush(stdin); //Se debe limpiar el buffer de scanf para permitir el ingreso de nuevos datos
                    } else {
                        break; //Si el usuario ingresa una cantidad valida se rompe la estructura repetitiva y se continua a la siguiente línea 
                    }
                } while (1); //Ciclo do-while para validar que los datos no sean ni caracteres ni menores a 0
                if (cantidad == 0){ 
                    printf("\n\x1B[0mNo se ha aumentado stock\n"); //Si la cantidad ingresada es 0 se despliega un mensaje y sale de la opción 
                    break;
                } 
                stock+=cantidad; //Usando la variable stock como acumulador se suma la cantidad de reabastecimiento
                printf("\n\x1B[0mStock actualizado. Se tiene %d unidades\n", stock); //Mensaje mostrando el nuevo stock
                break;
            case 3:
                printf("\n\t\x1B[0mInformacion del producto:\n"); //Se muestra como titulo con \t para dar una impresión más estética
                printf("\x1B[0mID: %d\n", id); //Se muestra el ID ingresado
                printf("\x1B[0mNombre: %s", nombre); //Se muestra el nombre ingresado
                printf("\x1B[0mStock disponible: %d\n", stock); //Se muestra el stock actual
                printf("\x1B[0mPrecio unitario: $ %.2f\n", precio); //Se muestra el precio uinitario
                break;
            case 4:
                printf("\n\x1B[0mTotal de ganancias: $%.2f\n", total_ganancias); //Se despliega la cantidad acumulada de las anteriores ventas realizadas en el programa
                break;
            case 5:
                printf("\n\x1B[0mSaliendo del programa...\n"); //Si el usuario decide terminar el programa, se muestra este mensaje
                break;
            default:
                printf("\n\x1B[33mOpción inválida. Intente nuevamente.\n"); //Si se ingresa una opción invalida se despliega este mensaje
        }
    } while (opcion != 5); 

    return 0;
}