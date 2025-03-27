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
    float precio, total_ganancias = 0, ventas;
    char nombre[30];
    //Presentación del programa
    printf("\t*****************************\n");
    printf("\t Simulador de un comerciante \n");
    printf("\t*****************************\n");
    do{
        printf("Ingrese el ID del producto (4 digitos): "); //Se solicita el ID del producto a vender (Solo digitos)
        valido = scanf("%d", &id);
        if (valido != 1 || id < 1000 || id > 9999){
           printf("ID no valido\n"); //Mensaje de rechazo de datos 
           fflush(stdin); //Se usa fflush para limpiar el buffer de scanf
        }
    } while (valido != 1 || id < 1000 || id > 9999); //Ciclo do-while para validar que los datos ingresados en ID sean validos
    fflush(stdin); //Se debe limpiar el buffer para que fgets funcione
    printf("Ingrese el nombre del producto: "); //Se solicita el nombre del producto
    fgets(nombre, sizeof(nombre), stdin); //Función fgets para registrar el nombre 
    do{
        printf("Ingrese la cantidad inicial en stock: "); //Se solicita la cantidad inicial de stock del producto
        valido = scanf("%d", &stock);
        if (valido != 1 || stock <= 0){
            printf("Stock no valido\n"); //Mensaje de rechazo de datos
            fflush(stdin); //Se usa fflush para limpiar el buffer de scanf
        }
    } while (valido !=1 || stock <= 0); //Ciclo do-while para validar que los datos ingresados en stock sean validos
    do{
        printf("Ingrese el precio unitario del producto: $ "); //S solicita el precio unitario del producto
        valido = scanf("%f", &precio);
        if (valido != 1 || precio < 0){
            printf("Precio no valido\n"); //Mensaje de rechazo de datos
            fflush(stdin); //Se usa fflush para limpiar el buffer de scanf
        }
    } while (valido !=1 || precio < 0); //Ciclo de-while para validar que los datos ingresados en precio sean validos

    do {
        //Se presenta un menu de las posibles opciones que puede realizar el comerciante
        printf("\n\tMenu de Opciones\n");
        printf("1. Vender producto\n");
        printf("2. Reabastecer producto\n");
        printf("3. Mostrar información del producto\n");
        printf("4. Mostrar total de ganancias\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        valido = scanf("%d", &opcion);
        if (valido != 1){ //Con este condicional se valida que los datos ingresados sean digitos y no caracteres
            printf("\nOpción inválida. Intente nuevamente.\n");
            fflush(stdin); //Se debe limpiar el buffer de scanf para que se permita la entrada de un nuevo dato
            continue; //La función continue permite que el programa continue
        }
        switch(opcion) {
            case 1:
                if (stock == 0){ //Si el usuario ya vendio todo su stock se despliega un mensaje que recomeinda reabastecer
                    printf("\nNo hay suficiente stock, por favor reabastecer\n");
                    break;
                }
                printf("\nSu stock actual es de %d unidades", stock); //Se despliega la cantidad de stock actual
                do{
                    printf("\nIngrese la cantidad a vender: ");
                    valido = scanf("%d", &cantidad);
                    if (valido != 1 || cantidad < 1){
                        printf("La cantidad a vender debe ser al menos una unidad, por favor ingrese nuevamente\n"); //Se muestra este mensaje solo si la cantidad es menor a 1 o invalida
                        fflush(stdin); //Se debe limpiar el buffer de scanf para el nuevo ingreso de datos
                    } else if (cantidad > stock){
                        printf("La cantidad a vender supera al stock, por favor ingrese nuevamente\n");
                        fflush(stdin); // Se debe limpiar el buffer de scanf para aceptar nuevos datos
                    } else {
                        break;
                    }
                } while (1); //Ciclo do-while que valida que no se ingresen caracteres ni numeros negativos
                ventas = (cantidad * precio); //Para calcular las ventas se necesita que se multiplique la cantidad de unidades a vender por el precio unitario
                total_ganancias+=ventas; //Se acumula los valores de las ventas en la variable total_ganancias
                stock -= cantidad; //Se realiza una resta del stock después de cada venta
                printf("Venta realizada. Con una ganancia de $ %.2f\n", ventas); //Mensaje informando cuanto se estima de ganancia  
                printf("Quedan %d unidades en stock\n", stock); //Mensaje informando cuantas unidades de stock quedan    
                break;
            case 2:
                do{
                    printf("\nIngrese la cantidad a agregar al stock: ");
                    valido = scanf("%d", &cantidad);
                    if (valido != 1 || cantidad < 0){
                        printf("\nLa cantidad ingresada no es valida, ingrese nuevamente\n");
                        fflush(stdin); //Se debe limpiar el buffer de scanf para permitir el ingreso de nuevos datos
                    } else {
                        break;
                    }
                } while (1); //Ciclo do-while para validar que los datos no sean ni caracteres ni menores a 0
                if (cantidad == 0){ 
                    printf("\nNo se ha aumentado stock\n"); //Si la cantidad ingresada es 0 se despliega un mensaje y sale de la opción 
                    break;
                } 
                stock+=cantidad; //Usando la variable stock como acumulador se suma la cantidad de reabastecimiento
                printf("\nStock actualizado. Se tiene %d unidades\n", stock); //Mensaje mostrando el nuevo stock
                break;
            case 3:
                printf("\n\tInformación del producto:\n"); //Se muestra como titulo con \t para dar una impresión más estética
                printf("ID: %d\n", id); //Se muestra el ID ingresado
                printf("Nombre: %s", nombre); //Se muestra el nombre ingresado
                printf("Stock disponible: %d\n", stock); //Se muestra el stock actual
                printf("Precio unitario: $ %.2f\n", precio); //Se muestra el precio uinitario
                break;
            case 4:
                printf("\nTotal de ganancias: $%.2f\n", total_ganancias); //Se despliega la cantidad acumulada de las anteriores ventas realizadas en el programa
                break;
            case 5:
                printf("\nSaliendo del programa...\n"); //Si el usuario decide terminar el programa, se muestra este mensaje
                break;
            default:
                printf("\nOpción inválida. Intente nuevamente.\n"); //Si se ingresa una opción invalida se despliega este mensaje
        }
    } while (opcion != 5);

    return 0;
}