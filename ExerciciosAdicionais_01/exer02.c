/*
2. Escreva um programa na Linguagem C que leia uma temperatura em gruas Celsius
e apresente a temperatura convertida em graus Fahrenheit.
*/

#include <stdio.h>

int main() {

      double c, f;

      printf("Em Celcius: ");
      scanf("%lf", &c);

      f = (1.8 * c) + 32;

      printf("Em Fahrenheit: %.2lf", f);

      return 0;
}
