#include <stdio.h>

int main()
{
    const char LETRA = 'H'; // letra a ser impressa
    const int NUM = 10; // número de vezes que a letra deve ser impressa
    
    for (int i = 1; i <= NUM; i++)
        putchar(LETRA);
    putchar('\n');

    int val = NUM; // valor a ser impresso
    while (val > 0)
    {
        printf("%d ", val);
        val--;
    }
    putchar('\n');

    return 0;
}
