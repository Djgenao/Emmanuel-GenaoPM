#include <stdio.h>
/* Búsqueda binaria. */
const int MAX = 100;

void Lectura(int A[], int T); /* Prototipos de funciones */
int Binaria(int A[], int T, int E);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);   /* Se verifica que el tamaño del arreglo sea correcto. */

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Binaria(VEC, TAM, ELE); /* Se llama a la función que busca en el arreglo. */

    if (RES)
    {
        /* Si RES tiene un valor verdadero (diferente de 0), se escribe la posición en la que se encontró el elemento. */
        printf("\nEl elemento se encuentra en la posición: %d", RES);
    }
    else
    {
        printf("\nEl elemento no se encuentra en el arreglo");
    }

    return 0; /* Terminación exitosa */
}

void Lectura(int A[], int T)
/* La función Lectura se utiliza para leer un arreglo unidimensional de T elementos de tipo entero. */
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Binaria(int A[], int T, int E)
/* Esta función se utiliza para realizar una búsqueda binaria del elemento E en el arreglo unidimensional A de T elementos.
Si se encuentra el elemento, la función regresa la posición correspondiente. En caso contrario, regresa 0. */
{
    int IZQ = 0, DER = T - 1, CEN, RES = 0;

    while (IZQ <= DER && RES == 0)
    {
        CEN = (IZQ + DER) / 2;

        if (E == A[CEN])
        {
            RES = CEN + 1; /* Devolvemos la posición (1-based index) */
        }
        else if (E > A[CEN])
        {
            IZQ = CEN + 1;
        }
        else
        {
            DER = CEN - 1;
        }
    }

    return RES; /* Regresa la posición encontrada o 0 si no se encontró */
}
