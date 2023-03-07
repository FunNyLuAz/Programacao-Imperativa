#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

      puts("\nIniciando programa...\n");

      if (argc < 2) {
            // Finaliza programa se não houver nenhum argumento
            puts("Falta o nome do arquivo de entrada e de saída.");
            return 101;
      } else if (argc == 2) {
            // Finaliza programa se não houver dois argumentos
            puts("Falta o nome do arquivo de saída.");
            return 102;
      } else if (argc > 3) {
            // Finaliza programa se houver mais de um argumentos
            puts("Excesso de parâmetros.");
            return 103;
      }

      char* pathIn = argv[1];
      char* pathOut = argv[2];

      printf("Copiando bytes do arquivo \"%s\" para o arquivo \"%s\"...\n\n", pathIn, pathOut);

      // Tenta abrir os arquivos
      FILE* fileIn = fopen(pathIn, "rb");
      if (fileIn == NULL) {
            puts("Arquivo de entrada não exite");
            return 100;
      }
      
      FILE* fileOut = fopen(pathOut, "wb");

      // Copia os bytes do arquivo de entrada para o de saída
      int qtde_read;
      char c;
      do {
            qtde_read = fread(&c, 1, 1, fileIn);
            if (qtde_read > 0) { // Sem a condição, escreveria um byte vazio no final do arquivo
                  fwrite(&c, 1, 1, fileOut);
            }
      } while (qtde_read > 0);

      // Fecha os arquivos
      fclose(fileIn);
      fclose(fileOut);

      puts("Copiado com sucesso.");

      return 0;
}
