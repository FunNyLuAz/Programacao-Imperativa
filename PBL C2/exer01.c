// Lucas Azevedo Dias

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

      system("chcp 65001"); // Configura o prompt para o UTF-8

      char const vowels[6] = "aeiou"; // Declara as vogais possíveis
      char input; // Declara a entrada

      // Declara as quantidades de vogais, cosoantes e outros caracteres
      int qv = 0, qc = 0, qo = 0;

      while (1) {
            // Entrada de valores
            puts("\nDigite um caractere [0 para parar]:");
            scanf("%c", &input);

            // Verifica se é o caractere de encerramento
            if (input == '0') {
                  puts("\nEncerrado");
                  break;
            }

            // Verifica se é uma letra
            if (isalpha(input)) {
                  // Verifica se o input está nas vogais
                  if (strchr(vowels, input) != NULL) {
                        puts("\nÉ vogal!");
                        qv++;
                  } else {
                        puts("\nÉ consoante!");
                        qc++;
                  }
            } else {
                  puts("\nNão é uma letra!");
                  qo++;
            }

            // Limpa o buffer de entrada
            fflush(stdin);
      }

      // Imprime os resultados
      printf("\nVogais = %d\nConsoantes = %d\nOutros caracteres = %d\n", qv, qc, qo);

      return 0;
}
