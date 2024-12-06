#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Alumno
typedef struct
{
    char nombre[50];    // Nombre del alumno (máximo 50 caracteres)
    float promedio;     // Promedio del alumno
    char carrera[50];   // Carrera del alumno (máximo 50 caracteres)
} Alumno;

// Prototipos de funciones
void nuevoArchivo(const char *nombreArchivo); // Crear un nuevo archivo vacío
void abrirArchivo(const char *nombreArchivo); // Leer y mostrar contenido del archivo
void guardarArchivo(const char *nombreArchivo); // Agregar un registro al archivo
void buscarEnArchivo(const char *nombreArchivo, const char *nombreBuscado); // Buscar un registro por nombre
int archivoExiste(const char *nombreArchivo); // Verificar si un archivo existe

int main()
{
    int opcion;                // Variable para guardar la opción seleccionada del menú
    char nombreArchivo[100];   // Almacena el nombre del archivo a manipular
    char nombreBuscado[50];    // Almacena el nombre del alumno que se desea buscar

    do
    {
        // Mostrar el menú principal
        printf("\n--- Sistema de Gestión de Alumnos ---\n");
        printf("1. Crear nuevo archivo\n");
        printf("2. Abrir archivo\n");
        printf("3. Guardar archivo\n");
        printf("4. Buscar por nombre\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);  // Leer la opción ingresada por el usuario
        getchar();             // Limpiar el buffer para evitar problemas con las entradas de texto

        // Evaluar la opción seleccionada
        switch (opcion)
        {
        case 1:
            // Crear un nuevo archivo
            printf("Ingrese el nombre del archivo a crear: ");
            scanf("%s", nombreArchivo); // Leer el nombre del archivo
            nuevoArchivo(nombreArchivo); // Llamar a la función para crear el archivo
            break;

        case 2:
            // Abrir y mostrar el contenido de un archivo
            printf("Ingrese el nombre del archivo a abrir: ");
            scanf("%s", nombreArchivo); // Leer el nombre del archivo
            abrirArchivo(nombreArchivo); // Llamar a la función para abrir y mostrar el contenido
            break;

        case 3:
            // Agregar un registro al archivo
            printf("Ingrese el nombre del archivo a guardar: ");
            scanf("%s", nombreArchivo); // Leer el nombre del archivo
            guardarArchivo(nombreArchivo); // Llamar a la función para guardar el registro
            break;

        case 4:
            // Buscar un registro por nombre
            printf("Ingrese el nombre del archivo donde buscar: ");
            scanf("%s", nombreArchivo); // Leer el nombre del archivo
            if (archivoExiste(nombreArchivo))   // Verificar si el archivo existe
            {
                printf("Ingrese el nombre del alumno a buscar: ");
                scanf("%s", nombreBuscado); // Leer el nombre del alumno
                buscarEnArchivo(nombreArchivo, nombreBuscado); // Llamar a la función para buscar
            }
            else
            {
                printf("El archivo no existe.\n"); // Mostrar mensaje si el archivo no existe
            }
            break;

        case 5:
            // Salir del sistema
            printf("Saliendo del sistema...\n");
            break;

        default:
            // Manejar opciones inválidas
            printf("Opción no válida.\n");
        }
    }
    while (opcion != 5);   // Repetir el menú mientras no se elija salir

    return 0;
}

// Crear un nuevo archivo vacío
void nuevoArchivo(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "w"); // Abrir el archivo en modo escritura
    if (archivo == NULL)   // Verificar errores al abrir el archivo
    {
        printf("No se pudo crear el archivo.\n");
        return;
    }
    printf("Archivo '%s' creado exitosamente.\n", nombreArchivo);
    fclose(archivo); // Cerrar el archivo
}

// Leer y mostrar el contenido de un archivo
void abrirArchivo(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "r"); // Abrir el archivo en modo lectura
    if (archivo == NULL)   // Verificar errores al abrir el archivo
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    Alumno alumno; // Variable para leer registros de tipo Alumno
    printf("\n--- Contenido del archivo '%s' ---\n", nombreArchivo);
    while (fread(&alumno, sizeof(Alumno), 1, archivo))   // Leer cada registro del archivo
    {
        // Mostrar los datos del alumno
        printf("Nombre: %s | Promedio: %.2f | Carrera: %s\n", alumno.nombre, alumno.promedio, alumno.carrera);
    }

    fclose(archivo); // Cerrar el archivo
}

// Agregar un nuevo registro al archivo
void guardarArchivo(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "ab"); // Abrir el archivo en modo agregar (append)
    if (archivo == NULL)   // Verificar errores al abrir el archivo
    {
        printf("No se pudo abrir el archivo para guardar.\n");
        return;
    }

    Alumno alumno; // Variable para almacenar datos del nuevo alumno
    // Leer datos del usuario
    printf("Ingrese el nombre del alumno: ");
    scanf("%s", alumno.nombre);
    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &alumno.promedio);
    printf("Ingrese la carrera del alumno: ");
    scanf("%s", alumno.carrera);

    // Escribir el registro en el archivo
    fwrite(&alumno, sizeof(Alumno), 1, archivo);
    printf("Registro guardado exitosamente.\n");

    fclose(archivo); // Cerrar el archivo
}

// Buscar un registro por nombre en el archivo
void buscarEnArchivo(const char *nombreArchivo, const char *nombreBuscado)
{
    FILE *archivo = fopen(nombreArchivo, "r"); // Abrir el archivo en modo lectura
    if (archivo == NULL)   // Verificar errores al abrir el archivo
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    Alumno alumno; // Variable para leer registros del archivo
    int encontrado = 0; // Bandera para indicar si el registro fue encontrado
    while (fread(&alumno, sizeof(Alumno), 1, archivo))   // Leer cada registro
    {
        if (strcmp(alumno.nombre, nombreBuscado) == 0)   // Comparar nombres
        {
            // Mostrar los datos del alumno encontrado
            printf("\nAlumno encontrado:\n");
            printf("Nombre: %s | Promedio: %.2f | Carrera: %s\n", alumno.nombre, alumno.promedio, alumno.carrera);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)   // Si no se encontró el registro
    {
        printf("Alumno con nombre '%s' no encontrado.\n", nombreBuscado);
    }

    fclose(archivo); // Cerrar el archivo
}

// Verificar si un archivo existe
int archivoExiste(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "r"); // Intentar abrir el archivo en modo lectura
    if (archivo)   // Si se puede abrir, el archivo existe
    {
        fclose(archivo);
        return 1;
    }
    return 0; // Si no se puede abrir, el archivo no existe
}
