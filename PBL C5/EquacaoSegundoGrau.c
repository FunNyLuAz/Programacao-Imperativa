#include <stdio.h>

double obter_coeficiente(char *);
double calcular_delta(double, double, double);

void responder_sem_raiz();
void responder_uma_raiz(double, double);
void responder_duas_raizes(double, double, double);

int main()
{
    printf("Forma geral da equação do segundo grau: a x**2 + b x + c = 0\n");
    double coef_a = obter_coeficiente("Digite o coeficiente a: ");
    if (coef_a == 0)
    {
        printf("O coeficiente a não pode ser zero!\n");
        return 0;
    }
    double coef_b = obter_coeficiente("Digite o coeficiente b: ");
    double coef_c = obter_coeficiente("Digite o coeficiente c: ");
    double delta = calcular_delta(coef_a, coef_b, coef_c);
    if (delta < 0)
        responder_sem_raiz();
    else if (delta == 0)
        responder_uma_raiz(coef_a, coef_b);
    else
        responder_duas_raizes(coef_a, coef_b, delta);

    return 0;
}

// Obtem o coeficiente por um prompt mostrado no console e o retorna
double obter_coeficiente(char* prompt) {
    double coef;
    printf(prompt);
    scanf("%lf", &coef);
    fflush(stdin);
    return coef;
}

// Calcula delta e retorna
double calcular_delta(double coef_a, double coef_b, double coef_c) {
    return (pow(coef_b, 2) - 4 * coef_a * coef_c);
}

// Responde para o caso de não haver raízes
void responder_sem_raiz() {
    printf("A equação não possui raízes reais.");
}

// Responde para o caso de haver apenas uma raiz
void responder_uma_raiz(double coef_a, double coef_b) {
    double result = -coef_b / (2 * coef_a);
    printf("A equação possui somente uma raiz: %lf.", result);
}

// Responde para o caso de haver duas raízes
void responder_duas_raizes(double coef_a, double coef_b, double delta) {
    double result1 = (-coef_b + pow(delta, 0.5)) / (2 * coef_a);
    double result2 = (-coef_b - pow(delta, 0.5)) / (2 * coef_a);
    printf("A equação possui duas raízes: %lf e %lf.", result1, result2);
}
