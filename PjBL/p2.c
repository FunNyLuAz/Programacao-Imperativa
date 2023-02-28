#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabela.h"

void insertCarro(CARRO*, size_t);
void deleteCarro(CARRO*, size_t);
double getAvgPrecosCarros(CARRO*, size_t);
CARRO* getCarroMenorKm(CARRO*, size_t);

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

      printf("\nCarregando dados do arquivo em binário \"%s\" para serem salvos no arquivo de texto \"%s\"...\n", pathIn, pathOut);


      // Tenta abrir o arquivo de entrada
      FILE* fileIn = fopen(pathIn, "rb");

      if (fileIn == NULL) {
            printf("Arquivo de entrada em \"%s\" não exite\n", pathIn);
            return 100;
      }


      // Determina o tamanho dos dados de entrada baseado nos primeiros bytes
      size_t qtdeCarros;
      fread(&qtdeCarros, sizeof(size_t), 1, fileIn);


      // Insere os dados de entrada na lista
      CARRO* tableCarros = (CARRO*) calloc(qtdeCarros, sizeof(CARRO));
      fread(tableCarros, sizeof(CARRO), qtdeCarros, fileIn);

      
      // Fecha o arquivo de entrada
      fclose(fileIn);


      // Realiza operações sobre a lista de acordo com o usuário
      int opcao;
      do {
            puts("\nEscolha uma opção de operação:");
            puts("      1 - Mostrar tabela");
            puts("      2 - Inserir carro");
            puts("      3 - Deletar carro");
            puts("      4 - Obter média dos preços dos carros");
            puts("      5 - Obter carro com menos quilometros rodados");
            puts("      0 - Finalizar programa e salvar alterações");

            // Pega a opção do usuário
            printf("> ");
            scanf("%d", &opcao);
            fflush(stdin);

            // Verifica se a opção passada (se for inválida, pede para tentar novamente)
            CARRO* carro;
            switch (opcao) {
                  case 0: // Finalizar programa e salvar alterações
                        puts("\nFinalizando programa e salvando alterações...");
                        break;
                  case 1: // Mostrar tabela
                        printf("\nTabela de carros:\n");
                        printTabelaCarros(tableCarros, qtdeCarros);
                        break;
                  case 2: // Inserir carro
                        puts("\nInserindo carro...");
                        insertCarro(tableCarros, qtdeCarros);
                        qtdeCarros++;
                        break;
                  case 3: // Deletar carro
                        puts("\nDeletando carro...");
                        deleteCarro(tableCarros, qtdeCarros);
                        qtdeCarros--;
                        break;
                  case 4: // Obter média dos preços dos carros
                        printf("\nA média dos preços dos carros é %.2lf\n", getAvgPrecosCarros(tableCarros, qtdeCarros));
                        break;
                  case 5: // Obter carro com menos quilometros rodados
                        carro = getCarroMenorKm(tableCarros, qtdeCarros);
                        printf("\nO carro com menos quilometros rodados é o carro %s %d da marca %s que custa %.2lf\n", carro->nome, carro->ano, convertMarcaEnumStr(carro->marca), carro->preco);
                        break;
                  default: // Inválido
                        puts("\nOpção inválida, tente novamente.");
                        break;
            }

      } while(opcao != 0);


      // Abre ou cria o arquivo de saída
      FILE* fileOut = fopen(pathOut, "w");
      fprintf(fileOut, "%d", qtdeCarros); // Escreve a quantidade de carros
      for (int i = 0; i < qtdeCarros; i++) { // Escreve os carros
            CARRO* carro = tableCarros + i;
            fprintf(fileOut, "\n%s,%s,%d,%.2lf,%d", carro->nome, convertMarcaEnumStr(carro->marca), carro->ano, carro->preco, carro->km);
      }

      printf("\nDados armazenados com sucesso em texto em \"%s\".\n", pathOut);


      // Fecha o arquivo de saída
      fclose(fileOut);


      return 0;
}

void insertCarro(CARRO* tableCarros, size_t qtdeCarros) {
      // Insere um carro na lista de acordo com o usuário

      char c; // Buffer para operações seguintes


      // Salvar nome do carro
      #define NOME_SIZE 30
      char* nome = (char*) malloc(sizeof(char) * (NOME_SIZE + 1));
      do {
            printf("\n> Nome: ");
            for (int i = 0; i < NOME_SIZE; i++) {
                  c = getchar();
                  if (c != '\n') {
                        *(nome + i) = c;
                  } else {
                        *(nome + i) = '\0';
                        break;
                  }
            }
            *(nome + NOME_SIZE) = '\0';
            fflush(stdin);
      } while (!(strlen(nome) > 0));
      toUpperStr(nome);

      printf("(%s)\n", nome);


      // Salvar ano do carro
      #define ANO_SIZE 4
      int ano;
      do {
            char* a = (char*) malloc(sizeof(char) * (ANO_SIZE + 1));
            printf("\n> Ano: ");
            for (int i = 0; i < ANO_SIZE; i++) {
                  c = getchar();
                  if (c != '\n') {
                        *(a + i) = c;
                  } else {
                        *(a + i) = '\0';
                        break;
                  }
            }
            *(a + ANO_SIZE) = '\0';
            fflush(stdin);

            ano = atoi(a);
            free(a);
      } while (ano < 1900 || ano > 2100);
      
      printf("(%d)\n", ano);


      // Salvar marca do carro
      puts("\nMarcas possíveis:");
      puts("      1 - VOLKSWAGEN");
      puts("      2 - RENAULT");
      puts("      3 - FORD");
      puts("      4 - FIAT");
      puts("      5 - CHEVROLET");
      puts("      6 - HYUNDAI");
      puts("      0 - OUTROS");

      int m;
      do {
            printf("\n> Marca: ");
            scanf("%d", &m);
            fflush(stdin);
      } while (!(m >= OUTROS && m <= HYUNDAI));

      MARCA marca = (MARCA) m;

      printf("(%s)\n", convertMarcaEnumStr(marca));


      // Salvar preço do carro
      #define PRECO_SIZE 9
      char* p = (char*) malloc(sizeof(char) * (PRECO_SIZE + 1));
      do {
            printf("\n> Preço: ");
            for (int i = 0; i < PRECO_SIZE; i++) {
                  c = getchar();
                  if (c != '\n' && (isdigit(c) || c == ',' || c == '.')) {
                        *(p + i) = c;
                  } else {
                        *(p + i) = '\0';
                        break;
                  }
            }
            *(p + PRECO_SIZE) = '\0';
            fflush(stdin);
      } while (!(strlen(p) > 0));

      char* dot = strchr(p, ','); // Converte ',' em '.' se houver
      if (dot) {
            *(dot) = '.';
      }

      double preco = strtod(p, NULL);
      free(p);

      printf("(%lf)\n", preco);


      // Salvar km do carro
      #define KM_SIZE 8
      char* k = (char*) malloc(sizeof(char) * (KM_SIZE + 1));
      do {
            printf("\n> KM: ");
            for (int i = 0; i < KM_SIZE; i++) {
                  c = getchar();
                  if (c != '\n' && isdigit(c)) {
                        *(k + i) = c;
                  } else {
                        *(k + i) = '\0';
                        break;
                  }
            }
            *(k + KM_SIZE) = '\0';
            fflush(stdin);
      } while (!(strlen(k) > 0));

      int km = atoi(k);
      free(k);

      printf("(%d)\n", km);


      // Registra os dados como um novo carro na lista
      addCarroInTableCarros(tableCarros, qtdeCarros, nome, marca, ano, preco, km);
}

void deleteCarro(CARRO* tableCarros, size_t qtdeCarros) {
      // Deleta um carro na lista de acordo com o usuário

      // Salva o índice do carro a ser deletado
      int index;
      do {
            printf("\n> Índice: ");
            scanf("%d", &index);
            fflush(stdin);
      } while (index < 0 || index >= qtdeCarros);

      // Remove o carro da lista
      removeCarroInTableCarros(tableCarros, qtdeCarros, index);
}

double getAvgPrecosCarros(CARRO* tableCarros, size_t qtdeCarros) {
      // Calcula e retorna a média dos preços dos carros na lista
      double avg = 0;
      
      for (int i = 0; i < (int) qtdeCarros; i++) {
            avg += (tableCarros + i)->preco;
      }
      avg /= qtdeCarros;

      return avg;
}

CARRO* getCarroMenorKm(CARRO* tableCarros, size_t qtdeCarros) {
      // Retorna o endereço do carro na lista com o menor km (em empate, pega o primeiro)
      int index = 0;

      for (int i = 0; i < (int) qtdeCarros; i++) {
            if ((tableCarros + i)->km < (tableCarros + index)->km) {
                  index = i;
            }
      }

      return tableCarros + index;
}
