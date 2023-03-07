/*
1. Escreva um programa na Linguagem C que efetue o cálculo do salário líquido de
um professor horista. Os dados fornecidos serão: valor da hora aula, número de aulas
dadas no mês e percentual de desconto do INSS e o percentual de desconto do
Imposto de Renda.
*/

#include <stdio.h>

int main() {

      int numaula;
      double valha, ha, inss, irpf, salario;

      printf("Digite o número das aulas:\n");
      scanf("%d", &numaula);

      printf("Digite o valor da hora-aula:\n");
      scanf("%lf", &valha);

      printf("Digite as horas por aula:\n");
      scanf("%lf", &ha);

      printf("Digite o percentual de INSS:\n");
      scanf("%lf", &inss);

      printf("Digite o percentual de IRPF:\n");
      scanf("%lf", &irpf);

      salario = numaula * valha * ha * (1 * (inss + irpf) / 100);

      printf("O salário ao final do mês seria de: %lf", salario);

      return 0;
}
