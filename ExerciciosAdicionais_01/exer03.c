/*
3. Escreva um programa na Linguagem C para calcular e apresentar o valor do
volume de uma lata de óleo cilíndrica.
*/

#include <stdio.h>

int main() {

      double pi = 3.14159;
      double volume, radius, height;

      printf("Digite o raio do cilindro:\n");
      scanf("%lf", &radius);

      printf("Digite a altura do cilindro:\n");
      scanf("%lf", &height);

      volume = pi * pow(radius, 2) * height;
      printf("O volume é: %.2lf", volume);

      return 0;
}
