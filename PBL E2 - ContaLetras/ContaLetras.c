#include <stdio.h>

#define NUM_LETTERS 26 // Quantidade de letras no alfabeto
#define ASCII_CODE_A 65 // Código ASCII para o "A"

char toUpperCase(char);

int main(int argc, char* argv[]) {
      puts("");
      if (argc < 2) {
            // Finaliza programa se não houver um argumento
            puts("Falta o nome do arquivo de entrada");
            return 101;
      } else if (argc > 2) {
            // Finaliza programa se houver mais de um argumentos
            puts("Excesso argumentos!");
            return 102;
      }

      char* path = argv[1];

      printf("Contando letras do arquivo \"%s\"...\n\n", path);

      // Tenta abrir o arquivo
      FILE* file = fopen(path, "r");

      if (file == NULL) {
            printf("Arquivo \"%s\" não exite", file);
            return 100;
      }

      int countLetras[NUM_LETTERS];
      for (int i = 0; i < NUM_LETTERS; i++) { // Formata o Array para o valor inteiro default de 0
            countLetras[i] = 0;
      }

      // Conta a quantidade de cada letra
      char c = NULL;
      while (c != EOF) { // Enquanto não for final do arquivo (EndOfFile) continua a ler
            c = toUpperCase(fgetc(file));
            if (c >= ASCII_CODE_A && c <= ASCII_CODE_A + NUM_LETTERS) {
                  countLetras[c - ASCII_CODE_A]++;
            }
      }

      // Imprime tabela com a quantidade de cada letra do alfabeto
      puts("Tabela com a quantidade de cada letra:");
      puts("  Char.    Qtde.");
      for (int i = 0; i < NUM_LETTERS; i++) {
            printf("  \"%c\"      %d\n", ASCII_CODE_A + i, countLetras[i]);
      }

      fclose(file);

      puts("\nContado com sucesso.");

      return 0;
}

char toUpperCase(char c) {
      #define ASCII_CODE_a 97 // Código ASCII para o "a"
      if (c >= ASCII_CODE_a && c <= ASCII_CODE_a + NUM_LETTERS) {
            c += ASCII_CODE_A - ASCII_CODE_a;
      }
      return c;
}
