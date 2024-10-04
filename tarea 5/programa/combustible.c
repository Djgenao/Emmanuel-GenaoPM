#include <stdio.h>

int main()
{

    float consumo_min, consumo_max, precio_galon, costo_por_km;
    const float litros_por_galon = 3.785; // Constante para convertir galones a litros

//Entrada de valores
    printf("Ingrese el consumo minimo (litros/100 km): ");
    scanf("%f", &consumo_min);

    printf("Ingrese el consumo maximo (litros/100 km): ");
    scanf("%f", &consumo_max);

    printf("Ingrese el precio del galón de combustible: ");
    scanf("%f", &precio_galon);

// Tabla
    printf("\nTabla de consumo (litros/100 km) y costo por km:\n");
    printf("Consumo (litros/100 km)\tCosto por km\n");
    printf("-------------------------------------\n");

    for (float consumo = consumo_min; consumo <= consumo_max; consumo += 1)   // Incremento de 1
    {

        // Calcular el costo por km
        costo_por_km = (consumo /100)/litros_por_galon*(precio_galon);
        printf("%.2f\t\t\t%.4f\n", consumo, costo_por_km);
    }

    return 0;
}
