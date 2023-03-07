#include <stdio.h>

#define NUM_LETRAS 10 // Número máximo de letras a serem digitadas

int main()
{
    char letras[NUM_LETRAS];

    // Lê letras separadamente
    printf("Digite %d letras:\n", NUM_LETRAS);

    for (int i = 0; i < NUM_LETRAS; i++)
    {
        printf("letra %d: ", i + 1);
        letras[i] = getchar();
        fflush(stdin); // Limpa o buffer de entrada
    }

    printf("As %d letras digitadas foram:\n", NUM_LETRAS);

    for (int i = 0; i < NUM_LETRAS; i++)
    {
        putchar(letras[i]);
    }
    putchar('\n');
    //

    // Lê letras em uma string de tamanho limitado
    printf("Digite uma sequência de, no máximo, %d letras:\n", NUM_LETRAS - 1);

    for (int i = 0; i < NUM_LETRAS - 1; i++)
    {
        letras[i] = getchar();
    }
    fflush(stdin); // Limpa o buffer de entrada
    letras[NUM_LETRAS - 1] = '\0'; // Põe o caracter de finalização de string no final

    printf("Sequência digitada: %s", letras);
    putchar('\n');
    //

    return 0;
}
