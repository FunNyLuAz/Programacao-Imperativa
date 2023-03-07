#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH_NOTAS "notas.txt" // Localização do arquivo com os dados das notas
#define INITIAL_LINE_SIZE 1 // Tamanho inicial para alocação de uma linha na memória

typedef struct {
      char nome[20];
      double nota;
} Estudante;

int main() {

      // Leitura de arquivo
      printf("\nLendo arquivo em %s...\n", PATH_NOTAS);

      FILE* file = fopen(PATH_NOTAS, "r");
      if (!file) {
            puts("\nErro na leitura do arquivo");
            return 100;
      }


      // Lê as linhas do arquivo
      size_t line_size = INITIAL_LINE_SIZE;
      char* lines = (char*) malloc(sizeof(char) * line_size);

      size_t cur_pos = 0;
      char c = NULL;
      while (c != EOF) {
            c = fgetc(file);

            if (cur_pos >= line_size) {
                  line_size += INITIAL_LINE_SIZE;
                  lines = (char*) realloc(lines, line_size);
            }

            *(lines + cur_pos) = c;
            cur_pos++;
      }


      // Define a quantidade de estudantes
      size_t next_line_pos = strcspn(lines, "\n");
      char* cur_line = (char*) malloc(sizeof(char) * next_line_pos + 1);
      strncpy(cur_line, lines, next_line_pos);
      lines += next_line_pos + 1;

      size_t qtde_estudantes = atoi(cur_line);

      
      // Passa por cada linha restante e salva as informações de cada estudante
      Estudante* estudantes = (Estudante*) calloc(qtde_estudantes, sizeof(Estudante));

      for (int i = 0; i < qtde_estudantes; i++) {
            next_line_pos = strcspn(lines, "\n");
            cur_line = (char*) malloc(sizeof(char) * next_line_pos + 1);
            strncpy(cur_line, lines, next_line_pos);
            lines += next_line_pos + 1;

            size_t sep_pos = strcspn(cur_line, " ");
            
            char* nome = (char*) malloc(sizeof(char) * sep_pos + 1);
            *(nome + sep_pos) = '\0';
            strncpy(nome, cur_line, sep_pos);

            char* nota = (char*) malloc(sizeof(char) * (next_line_pos - sep_pos) + 1);
            *(nota + sep_pos) = '\0';
            strncpy(nota, cur_line + sep_pos, next_line_pos);
            
            strcpy((estudantes + i)->nome, nome);
            (estudantes + i)->nota = strtod(nota, NULL);

            free(cur_line);
            free(nome);
            free(nota);
      }


      // Imprime os dados armazenados dos estudantes e calcula a média
      double nota_media = 0;

      printf("\nForam encontrados %d estudantes no arquivo, sendo eles:\n", qtde_estudantes);
      for (int i = 0; i < qtde_estudantes; i++) {
            printf("- %s / %.2lf\n", (estudantes + i)->nome, (estudantes + i)->nota);
            nota_media += (estudantes + i)->nota;
      }

      nota_media /= qtde_estudantes;


      // Mostra a média e  os estudantes acima da média
      printf("\nOs estudantes acima da média de %.2lf foram:\n", nota_media);
      for (int i = 0; i < qtde_estudantes; i++) {
            if ((estudantes + i)->nota > nota_media) {
                  printf("- %s / %.2lf\n", (estudantes + i)->nome, (estudantes + i)->nota);
            }
      }
      

      return 0;
}
