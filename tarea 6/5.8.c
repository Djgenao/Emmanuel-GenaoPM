#include <stdio.h>
#include <math.h>
/* Primos.
El programa almacena en un arreglo unidimensional los primeros 100 n�meros
primos. */
const int TAM = 100;

void Imprime(int[], int); /* Prototipo de la funci�n Imprime */
void Primo(int, int *);   /* Prototipo de la funci�n Primo */

int main(void)
{
    int P[TAM] = {2}; /* El primer n�mero primo es 2 */
    int FLA, J = 1, PRI = 3;

    while (J < TAM)
    {
        FLA = 1;
        Primo(PRI, &FLA); /* Se llama a la funci�n que determina si PRI es primo. */
        if (FLA) /* Si FLA es 1, entonces PRI es primo. */
        {
            P[J] = PRI;
            J++;
        }
        PRI += 2; /* Solo probamos con n�meros impares, ya que los pares > 2 no son primos */
    }

    Imprime(P, TAM);

    return 0; /* Indica la terminaci�n exitosa */
}

void Primo(int A, int *B)
/* Esta funci�n determina si A es primo, en cuyo caso el valor de *B no se altera. */
{
    int DI = 3;
    while (*B && (DI <= sqrt(A))) /* Comprobamos solo hasta la ra�z cuadrada de A */
    {
        if ((A % DI) == 0)
            *B = 0;
        DI += 2; /* Incrementamos por 2 para saltar los pares */
    }
}

void Imprime(int Primos[], int T)
/* Esta funci�n imprime el arreglo unidimensional de n�meros primos. */
{
    int I;
    for (I = 0; I < T; I++)
        printf("\nPrimos[%d]: %d", I, Primos[I]);
}
