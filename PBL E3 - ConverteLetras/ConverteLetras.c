#include <stdio.h>

#define NUM_LETTERS 26 // Quantidade de letras no alfabeto
#define ASCII_CODE_A 65 // Código ASCII para o "A"

char toUpperCase(char);

int main(int argc, char* argv[]) {
      puts("");
      if (argc < 2) {
            // Finaliza programa se não houver nenhum argumento
            puts("Falta o nome do arquivo de entrada e de saída");
            return 101;
      } else if (argc == 2) {
            // Finaliza programa se não houver dois argumentos
            puts("Falta o nome do arquivo de saída");
            return 102;
      } else if (argc > 3) {
            // Finaliza programa se houver mais de um argumentos
            puts("Excesso argumentos!");
            return 103;
      }

      char* pathIn = argv[1];
      char* pathOut = argv[2];

      printf("Copiando dados do arquivo \"%s\" para o arquivo \"%s\"...\n\n", pathIn, pathOut);

      // Tenta abrir os arquivos
      FILE* fileIn = fopen(pathIn, "r");
      FILE* fileOut = fopen(pathOut, "w");

      if (fileIn == NULL) {
            puts("Arquivo de entrada não exite");
            return 100;
      }

      // Copia os caracteres do arquivo de entrada para o de saída
      char c = fgetc(fileIn);
      while (c != EOF) {
            fputc(toUpperCase(c), fileOut);
            c = fgetc(fileIn);
      }

      fclose(fileIn);
      fclose(fileOut);

      puts("Copiado com sucesso.");

      return 0;
}

char toUpperCase(char c) {
      #define ASCII_CODE_a 97 // Código ASCII para o "a"
      if (c >= ASCII_CODE_a && c <= ASCII_CODE_a + NUM_LETTERS) {
            c += ASCII_CODE_A - ASCII_CODE_a;
      }
      return c;
}
