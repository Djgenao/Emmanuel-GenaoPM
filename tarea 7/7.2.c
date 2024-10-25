#include <stdio.h>
#include <ctype.h>

void main (void)
{
    char p1;
    printf("\nIngrese un caracter para analizar si este es un digito: ");
    p1 = getchar();
    if (isdigit(p1))
        printf("%c es un dígito \n", p1);
    else
        printf("%c no es un digito \n", p1);


    fflush(stdin);
    printf("\nIngrese un caracter para examinar si este es una letra: ");
    p1 = getchar();
    if (isalpha(p1))
        printf("%c es una letra \n", p1);
    else
        printf("%c no es una letra \n", p1);

    fflush(stdin);
    printf("\nIngrese un caracter para examinar si este es una letra minúscula: ");
    p1 = getchar();
    if (isalpha(p1))
        if (islower(p1))
            printf("%c es una letra minúscula: \n", p1);
        else
            printf("%c no es una letra minúscula \n", p1);

    fflush(stdin);
    printf("\nIngrese una letra para convertirla de mayúscula a minúscula: ");
    p1 = getchar();
    if (isalpha(p1))
        if (isupper(p1))
            printf("%c fue convertida de mayúscula a minúsucula \n", tolower(p1));
        else
            printf("%c es una letra minúscula \n", p1);
    else
        printf("%c no es una letra \n", p1);

}
