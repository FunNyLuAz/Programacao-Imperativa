#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BUFFER_SIZE 8

int main(int argc, char* argv[]) {

      if (argc < 2) {
            puts("\nFalta o nome do arquivo.");
            return 101;
      } else if (argc > 2) {
            puts("\nExcesso de parâmetros.");
            return 102;
      }


      // Leitura de arquivo
      char* path = argv[1];
      printf("\nLendo arquivo em %s...\n", path);

      FILE* file = fopen(path, "r");
      if (!file) {
            puts("\nErro na leitura do arquivo");
            return 100;
      }


      // Salva caracteres em buffer
      size_t size_buffer = sizeof(char) * INITIAL_BUFFER_SIZE;
      int cur_posbuffer = 0;

      char* buffer = (char*) malloc(size_buffer);
      char c = fgetc(file);

      while (c != EOF) {
            if (size_buffer <= cur_posbuffer) {
                  size_buffer *= 2;
                  buffer = (char*) realloc(buffer, size_buffer);
            }
            *(buffer + cur_posbuffer) = c;
            c = fgetc(file);
            cur_posbuffer++;
      }
      

      // Imprime os caracteres invertidos
      puts("\nCaracteres do arquivo invertidos:");
      for (int i = 0; i < cur_posbuffer + 1; i++) {
            putchar(*(buffer + cur_posbuffer - i));
      }
      puts("");


      // Fecha o arquivo
      fclose(file);


      puts("\nFim do programa.");

      return 0;
}
