#include <string.h>
/* Estructuras-2.
El programa muestra la manera en que se declara una estructura, así como la
➥forma en que se tiene acceso a los campos de los apuntadores de tipo estructura
➥tanto para lectura como para escritura. Se utiliza además una función que
➥recibe como parámetro un apuntador de tipo estructura. */

struct alumno
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    char direccion[20];
};

void Lectura(struct alumno *);

int main(void)
{
    struct alumno a0 = {120, "María", "Contabilidad", 8.9, "Querétaro"};
    struct alumno *a3, *a4, *a5, a6;
    a3 = &a0;

    // Asignación dinámica de memoria para las estructuras
    a4 = (struct alumno *)malloc(sizeof(struct alumno));
    if (a4 == NULL)
    {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    /* En la lectura de los campos de la variable a4 se utilizan como ejemplo ambos formatos. */
    printf("\nIngrese la matrícula del alumno 4: ");
    scanf("%d", &a4->matricula);
    getchar(); // Limpiar el buffer de entrada
    printf("Ingrese el nombre del alumno 4: ");
    fgets(a4->nombre, 20, stdin);
    a4->nombre[strcspn(a4->nombre, "\n")] = 0; // Eliminar el salto de línea
    printf("Ingrese la carrera del alumno 4: ");
    fgets(a4->carrera, 20, stdin);
    a4->carrera[strcspn(a4->carrera, "\n")] = 0; // Eliminar el salto de línea
    printf("Ingrese promedio del alumno 4: ");
    scanf("%f", &a4->promedio);
    getchar(); // Limpiar el buffer de entrada
    printf("Ingrese la dirección del alumno 4: ");
    fgets(a4->direccion, 20, stdin);
    a4->direccion[strcspn(a4->direccion, "\n")] = 0; // Eliminar el salto de línea

    // Asignación dinámica de memoria para a5
    a5 = (struct alumno *)malloc(sizeof(struct alumno));
    if (a5 == NULL)
    {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    Lectura(a5); /* En este caso se pasa el apuntador de tipo estructura alumno a5 a la función Lectura. */
    Lectura(&a6); /* En este caso se pasa la variable de tipo estructura alumno a6, a la función Lectura. Observa que en este caso debemos utilizar el operador de dirección para preceder a la variable. */

    printf("\nDatos del alumno 3\n");
    /* Observa la forma de escribir los campos de los apuntadores de tipo estructura. */
    printf("%d\t%s\t%s\t%.2f\t%s\n", a3->matricula, a3->nombre, a3->carrera, a3->promedio, a3->direccion);

    printf("\nDatos del alumno 4\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a4->matricula, a4->nombre, a4->carrera, a4->promedio, a4->direccion);

    printf("\nDatos del alumno 5\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a5->matricula, a5->nombre, a5->carrera, a5->promedio, a5->direccion);

    printf("\nDatos del alumno 6\n");
    /* Observa la forma de escribir los campos de la variable tipo estructura. */
    printf("%d\t%s\t%s\t%.2f\t%s\n", a6.matricula, a6.nombre, a6.carrera, a6.promedio, a6.direccion);

    // Liberar la memoria asignada dinámicamente
    free(a4);
    free(a5);

    return 0;
}

void Lectura(struct alumno *a)
{
    /* Esta función permite leer los campos de un apuntador de tipo estructura alumno. */
    printf("\nIngrese la matrícula del alumno: ");
    scanf("%d", &a->matricula);
    getchar(); // Limpiar el buffer de entrada
    printf("Ingrese el nombre del alumno: ");
    fgets(a->nombre, 20, stdin);
    a->nombre[strcspn(a->nombre, "\n")] = 0; // Eliminar el salto de línea
    printf("Ingrese la carrera del alumno: ");
    fgets(a->carrera, 20, stdin);
    a->carrera[strcspn(a->carrera, "\n")] = 0; // Eliminar el salto de línea
    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &a->promedio);
    getchar(); // Limpiar el buffer de entrada
    printf("Ingrese la dirección del alumno: ");
    fgets(a->direccion, 20, stdin);
    a->direccion[strcspn(a->direccion, "\n")] = 0; // Eliminar el salto de línea
}
