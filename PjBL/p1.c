#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabela.h"

char* readLinesOfFile(FILE*, size_t);
char* readLineOfLines(char*);
void saveCarroInLine(char*, CARRO*);

int main(int argc, char* argv[]) {
      if (argc < 2) {
            // Finaliza programa se não houver nenhum argumento
            puts("\nFalta o nome do arquivo de entrada e de saída");
            return 101;
      } else if (argc == 2) {
            // Finaliza programa se não houver dois argumentos
            puts("\nFalta o nome do arquivo de saída");
            return 102;
      } else if (argc > 3) {
            // Finaliza programa se houver mais de um argumentos
            puts("\nExcesso de argumentos!");
            return 103;
      }

      char* pathIn = argv[1];
      char* pathOut = argv[2];

      printf("\nPassando dados do arquivo \"%s\" para o arquivo em binário \"%s\"...\n", pathIn, pathOut);


      // Tenta abrir o arquivo de entrada
      FILE* fileIn = fopen(pathIn, "r");

      if (fileIn == NULL) {
            printf("Arquivo de entrada em \"%s\" não exite\n", pathIn);
            return 100;
      }


      // Carrega os dados de entrada para lines
      char* lines = readLinesOfFile(fileIn, 8);

      
      // Fecha o arquivo de entrada
      fclose(fileIn);


      // Determina o tamanho dos dados de entrada baseado no valor da primeira linha
      size_t qtdeCarros = atoi(readLineOfLines(lines));


      // Salva os dados de entrada em lines para a lista
      CARRO* tableCarros = (CARRO*) calloc(qtdeCarros, sizeof(CARRO));
      for (int i = 0; i < (int) qtdeCarros; i++) {
            saveCarroInLine(readLineOfLines(lines), tableCarros + i);
      }

      printf("\nDados do arquivo de entrada \"%s\" salvos e formatados corretamente.\n", pathIn);


      // Abre ou cria o arquivo de saída (em binário)
      FILE* fileOut = fopen(pathOut, "wb");
      fwrite(&qtdeCarros, sizeof(size_t), 1, fileOut); // Escreve a quantidade de carros
      fwrite(tableCarros, sizeof(CARRO), qtdeCarros, fileOut); // Escreve os carros

      printf("\nDados armazenados com sucesso em binário em \"%s\".\n", pathOut);
      

      // Fecha o arquivo de saída
      fclose(fileOut);


      return 0;
}

char* readLinesOfFile(FILE* file, size_t initialLineSize) {
      // Lê todas as linhas do arquivo e as retornam como uma string única
      char* lines = (char*) malloc(sizeof(char) * initialLineSize + 1);
      size_t line_size = initialLineSize;
      size_t cur_pos = 0;

      char c;
      do {
            c = getc(file);

            if (cur_pos >= line_size) { // Aloca mais memória se necessário
                  line_size += initialLineSize;
                  lines = (char*) realloc(lines, line_size + 1);
            }

            // Salva o caractere na última posição
            *(lines + cur_pos) = c;
            cur_pos++;

      } while(c != EOF); // Lê até o final do arquivo
      *(lines + cur_pos) = '\0';

      return lines;
}

char* readLineOfLines(char* lines) {
      // Lê uma linha da string com as linhas e o retorna (além de pular a posição dela na string de linhas)
      size_t next_line_pos = strcspn(lines, "\n") + 1; // Verifica a posição do próximo '\n'
      if (next_line_pos > strlen(lines)) { // Verifica se não há o '\n' nas linhas (nesse caso, retorna o todo)
            return lines;
      }

      char* line = (char*) malloc(sizeof(char) * next_line_pos + 1);
      *(line + next_line_pos) = '\0';
      strncpy(line, lines, next_line_pos); // Passa todos os caracteres até antes do '\n' para a linha
      strcpy(lines, lines + next_line_pos); // Pula a posição da linha atual

      return line;
}

void saveCarroInLine(char* cur_line, CARRO* carro) {
            // Salva os dados do carro na linha passada no endereço passado

            // Captura os dados baseado no separador
            size_t sep_pos = 0;

            sep_pos = strcspn(cur_line, ",");
            char* nome = (char*) malloc(sizeof(char) * sep_pos + 1);
            *(nome + sep_pos) = '\0';
            strncpy(nome, cur_line, sep_pos);
            cur_line += sep_pos + 1;
            
            sep_pos = strcspn(cur_line, ",");
            char* marca = (char*) malloc(sizeof(char) * sep_pos + 1);
            *(marca + sep_pos) = '\0';
            strncpy(marca, cur_line, sep_pos);
            cur_line += sep_pos + 1;
            
            sep_pos = strcspn(cur_line, ",");
            char* ano = (char*) malloc(sizeof(char) * sep_pos + 1);
            *(ano + sep_pos) = '\0';
            strncpy(ano, cur_line, sep_pos);
            cur_line += sep_pos + 1;
            
            sep_pos = strcspn(cur_line, ",");
            char* preco = (char*) malloc(sizeof(char) * sep_pos + 1);
            *(preco + sep_pos) = '\0';
            strncpy(preco, cur_line, sep_pos);
            cur_line += sep_pos + 1;
            
            sep_pos = strcspn(cur_line, "\n");
            char* km = (char*) malloc(sizeof(char) * sep_pos + 1);
            *(km + sep_pos) = '\0';
            strncpy(km, cur_line, sep_pos);
            
            // Salva os dados capturados
            toUpperStr(nome);
            toUpperStr(marca);
            writeDataInCarro(
                  carro,
                  nome,
                  convertMarcaStrEnum(marca),
                  atoi(ano),
                  strtod(preco, NULL),
                  atoi(km)
            );

            // Desaloca o espaço alocado temporariamente
            free(nome);
            free(marca);
            free(ano);
            free(preco);
            free(km);
}
