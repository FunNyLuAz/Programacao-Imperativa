#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

      system("chcp 65001"); // Configura o prompt para o UTF-8

      int val1, val2; // Declara o valor inicial e o valor final
      int tent = 0; // Declara o número de tentativas para o usuário digitar os limites do intervalo

      int const MULT = 3; // Múltiplo base para o cálculo

      while (tent < 3) {
            // Entrada dos valores do intervalo
            puts("\nDigite dois valores para o intervalo:");
            scanf("%d %d", &val1, &val2);

            // Verificação da validade dos valores dados
            if (val1 < val2) {
                  puts("\nCalculando...\n");
                  printf("Resultado dos múltiplos de %d no intervalo de %d a %d: ", MULT, val1, val2);

                  // Loop for para por todos os valores e imprime apenas os múltiplos de MULT
                  for (int i = val1; i <= val2; i++) {
                        if (i % MULT == 0) {
                              if (i + MULT > val2) {
                                    // Verificação para identificar o valor final e não imprimir aa vírgula
                                    printf("%d\n", i);
                                    continue;
                              }
                              printf("%d, ", i);
                        }
                  }
                  break; // Saída do loop (pois já foram dados valores corretos)
            } else if (val1 > val2) {
                  puts("\nErro! Valor inicial é maior do que o Valor final.\n");
            } else {
                  puts("\nErro! Valor inicial é igual ao Valor final.\n");
            }

            // Incremento de tentativas usadas
            tent++;
      }

      puts("\nPrograma encerrado!");

      // Verifica se saída do loop while foi por excesso de tentativas
      if (!(tent < 3)) {
            return 15; // Retorna 15 para indicar erro
      }

      return 0;
}
