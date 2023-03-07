#include <stdio.h>

int main()
{
    float operando1, operando2; // operandos
    double RESULTADO = 0; // resultado da operação
    char operador; // operador na forma de caracter

    puts("Digite o primeiro operando: ");
    scanf("%f", &operando1);

    puts("Digite o segundo operando: ");
    scanf("%f", &operando2);

    getchar();
    puts("Digite um operador (+, -, *, /): ");
    operador = getchar();

    switch (operador)
    {
    case '+':
        RESULTADO = operando1 + operando2;
        break;
    case '-':
        RESULTADO = operando1 - operando2;
        break;
    case '*':
        RESULTADO = operando1 * operando2;
        break;
    case '/':
        RESULTADO = operando1 / operando2;
        break;
    default:
        puts("Operador inválido");
    }

    printf("Resultado = %.2f\n", RESULTADO);
    return 0;
}