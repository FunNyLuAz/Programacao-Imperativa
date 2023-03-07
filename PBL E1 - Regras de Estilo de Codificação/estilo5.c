/* Programa para calcular as raízes de uma
equação de segundo grau */

#include <stdio.h>
#include <math.h>

int main() {

  float coeficiente_a, coeficiente_b, coeficiente_c;
  

  puts("Digite a: ");
  scanf("%f", &coeficiente_a);

  puts("Digite b: ");
  scanf("%f", &coeficiente_b);

  puts("Digite c: ");
  scanf("%f", &coeficiente_c);
  

  float delta = pow(coeficiente_b, 2) - 4 * coeficiente_a * coeficiente_c;
  printf("%f\n", delta);


  if (delta < 0)
  {
    puts("Nao existe raiz!");
  }
  else if (delta == 0)
  {
    puts("Existe uma raiz:");

    float result = -coeficiente_b / (2 * coeficiente_a);
    printf("%f\n", result);
  }
  else
  {
    puts("Existem duas raizes:");

    float sqrt_delta = pow(delta, 0.5);

    float result = (-coeficiente_b + sqrt_delta) / (2 * coeficiente_a);
    printf("%f\n", result);

    result = (-coeficiente_b - sqrt_delta) / (2 * coeficiente_a);
    printf("%f\n", result);
  }

  
  return 0;
}
