#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH_CATALOGO 5 // Tamanho máximo do catalogo
#define MAX_LENGTH_CHAR_DESCRICAO 30 // Tamanho máximo de caracteres em uma descrição de um produto
#define MAX_LENGTH_SIZE_DESCRICAO (MAX_LENGTH_CHAR_DESCRICAO + 1) // Tamanho máximo de uma descrição de um produto (considerando o caracter de finalização de um string)

typedef enum {ELETRODOMESTICO, FERRAMENTA, VESTUARIO} Categorias; // ENUM com as categorias possíveis para um produto
const char* const categorias_nomes[] = { // Nomes das categorias em ordem de índice compatível com o ENUM Categorias
      "ELETRODOMESTICO",
      "FERRAMENTA",
      "VESTUARIO"
};

typedef struct { // Estrututa base para um produto dentro do catálogo
      int codigo;
      int estoque;
      char descricao[31];
      Categorias categoria;
      bool isFilled;
} Produto;

Produto catalogo[MAX_LENGTH_CATALOGO];
int contadorCodigo = 0;


void IHC_inserir_produto();
void IHC_remover_produto();
void IHC_atualizar_estoque();
void IHC_aumentar_estoque();
void IHC_diminuir_estoque();

bool inserir_produto();
bool remover_produto();
bool atualizar_estoque();
bool aumentar_estoque();
bool diminuir_estoque();

void listar_catalogo();

void printHeader();
void printSucess();
void printError();


int main() {

      const int sizeMenuOpcoes = 7; // Tamanho das opções para o menu
      const char* const menuOpcoes[] = { // Opções que aparecerão no menu para o usuário em ordem alinhada com a seleção para ele
            "Listar todo o catálogo",
            "Inserir um novo produto no catálogo",
            "Remover um produto do catálogo",
            "Atualizar o estoque de um produto",
            "Aumentar o estoque de um produto",
            "Diminiuir o estoque de um produto",
            "Sair do programa"
      };

      for (int i = 0; i < MAX_LENGTH_CATALOGO; i ++)
            catalogo[i].isFilled = false;

      bool isRunning = true;
      int opcao;

      while (isRunning) {
            // Mostra as opções na tela
            puts("\n--------------------------------------");
            printHeader("Mostrando menu...");

            printf("\nOpções do menu:\n");
            for (int i = 0; i < sizeMenuOpcoes; i++) {
                  printf("(%d) - %s\n", i + 1, menuOpcoes[i]);
            }

            // Captura a opção selecionada pelo usuário
            printf("\nSelecione um opção:\n> ");
            scanf("%d", &opcao);
            fflush(stdin);

            // Realiza as ações de acordo com a opção do usuário
            switch (opcao) {
                  case 1:
                        listar_catalogo();
                        break;
                  case 2:
                        IHC_inserir_produto();
                        break;
                  case 3:
                        IHC_remover_produto();
                        break;
                  case 4:
                        IHC_atualizar_estoque();
                        break;
                  case 5:
                        IHC_aumentar_estoque();
                        break;
                  case 6:
                        IHC_diminuir_estoque();
                        break;
                  case 7:
                        printHeader("PROGRAMA ENCERRADO!");
                        isRunning = false;
                        break;
                  
                  default:
                        printError("Opção inválida.");
            }

      }

      return 0;
}

// Captura as informações necessárias e insere produto
void IHC_inserir_produto() {
      printHeader("Inserindo novo produto...");

      // Captura a descrição para o produto
      printf("\nDigite a descrição para o produto:\n> ");
      char descricao[MAX_LENGTH_SIZE_DESCRICAO];
      for (int i = 0; i < MAX_LENGTH_CHAR_DESCRICAO; i++) {
            descricao[i] = getchar();
            if (descricao[i] == '\n') {
                  descricao[i] = '\0';
                  break;
            }
      }
      descricao[MAX_LENGTH_CHAR_DESCRICAO] = '\0';
      fflush(stdin);
      printf("\nDescrição dada: %s\n", descricao);
      
      // Captura a categoria do produto
      int categoria;
      puts("\nOpções de categoria para o produto:");
      for (int i = 0; i < 3; i++) {
            printf("(%d) - %s\n", i + 1, categorias_nomes[i]);
      }
      printf("\nSelecione um opção:\n> ");
      scanf("%d", &categoria);
      fflush(stdin);
      categoria--;

      // Insere o produto
      if (inserir_produto(descricao, categoria)) {
            printSucess("Produto adicionado com sucesso.");
      } else {
            printError("Erro ao adicionar produto.");
      }
}

// Captura as informações necessárias e remove produto
void IHC_remover_produto() {
      printHeader("Removendo um produto...");

      // Captura o código para o produto
      int codigo;
      printf("\nDigite o código do produto:\n> ");
      scanf("%d", &codigo);
      fflush(stdin);

      // Remove o produto
      if (remover_produto(codigo)) {
            printSucess("Produto removido com sucesso.");
      } else {
            printError("Erro ao remover produto.");
      }
}

// Captura as informações necessárias e atualiza o estoque
void IHC_atualizar_estoque() {
      printHeader("Atualizando o estoque de um produto...");

      // Captura o código para o produto
      int codigo;
      printf("\nDigite o código do produto:\n> ");
      scanf("%d", &codigo);
      fflush(stdin);

      // Captura o estoque para o produto
      int estoque;
      printf("\nDigite o estoque do produto:\n> ");
      scanf("%d", &estoque);
      fflush(stdin);

      // Atualiza o estoque do produto
      if (atualizar_estoque(codigo, estoque)) {
            printSucess("Estoque do produto atualizado com sucesso.");
      } else {
            printError("Erro ao atualizar estoque do produto.");
      }
}

// Captura as informações necessárias e aumenta o estoque
void IHC_aumentar_estoque() {
      printHeader("Aumentando o estoque de um produto...");

      // Captura o código para o produto
      int codigo;
      printf("\nDigite o código do produto:\n> ");
      scanf("%d", &codigo);
      fflush(stdin);

      // Captura o aumento do estoque para o produto
      int estoque;
      printf("\nDigite o aumento do estoque do produto:\n> ");
      scanf("%d", &estoque);
      fflush(stdin);

      // Aumenta o estoque do produto
      if (aumentar_estoque(codigo, estoque)) {
            printSucess("Estoque do produto aumentado com sucesso.");
      } else {
            printError("Erro ao aumentar estoque do produto.");
      }
}

// Captura as informações necessárias e diminui o estoque
void IHC_diminuir_estoque() {
      printHeader("Diminuindo o estoque de um produto...");

      // Captura o código para o produto
      int codigo;
      printf("\nDigite o código do produto:\n> ");
      scanf("%d", &codigo);
      fflush(stdin);

      // Captura a diminuição do estoque para o produto
      int estoque;
      printf("\nDigite a diminuição do estoque do produto:\n> ");
      scanf("%d", &estoque);
      fflush(stdin);

      // Diminui o estoque do produto
      if (diminuir_estoque(codigo, estoque)) {
            printSucess("Estoque do produto diminuído com sucesso.");
      } else {
            printError("Erro ao diminuir estoque do produto.");
      }
}


// Insere um produto ao catálogo
bool inserir_produto(char* descricao, Categorias categoria) {
      if (categoria < ELETRODOMESTICO || categoria > VESTUARIO) {
            return false;
      }

      for (int i = 0; i < MAX_LENGTH_CATALOGO; i ++) {
            if (catalogo[i].isFilled == false) {
                  catalogo[i].codigo = contadorCodigo;
                  strcpy(catalogo[i].descricao, descricao);
                  catalogo[i].estoque = 0;
                  catalogo[i].categoria = categoria;
                  catalogo[i].isFilled = true;

                  contadorCodigo++;
                  return true;
            }
      }
      
      return false;
}

// Remove um produto do catálogo
bool remover_produto(int codigo) {
      int id = catalogo[0].codigo;
      for (int i = 0; i < MAX_LENGTH_CATALOGO; i++) {
            if (id == codigo) {
                  printf("a");
                  if (catalogo[i + 1].isFilled == true) {
                        printf("b");
                        catalogo[i].codigo = catalogo[i + 1].codigo;
                        catalogo[i].estoque = catalogo[i + 1].estoque;
                        strcpy(catalogo[i].descricao, catalogo[i + 1].descricao);
                        catalogo[i].categoria = catalogo[i + 1].categoria;
                  } else {
                        printf("c");
                        catalogo[i].isFilled = false;
                  }
            } else {
                  printf("d");
                  id = catalogo[i + 1].codigo;
            }

      }

      if (id == codigo) {
            return true;
      } else {
            return false;
      }
}

// Muda o estoque do produto para o dado
bool atualizar_estoque(int codigo, int estoque) {
      for (int i = 0; i < MAX_LENGTH_CATALOGO; i++) {
            if (catalogo[i].codigo == codigo) {
                  catalogo[i].estoque = estoque;
                  return true;
            }
      }
      
      return false;
}

// Incrementa o estoque do produto pelo valor dado
bool aumentar_estoque(int codigo, int estoque) {
      for (int i = 0; i < MAX_LENGTH_CATALOGO; i++) {
            if (catalogo[i].codigo == codigo) {
                  catalogo[i].estoque += estoque;
                  return true;
            }
      }
      
      return false;
}

// Decrementa o estoque do produto pelo valor dado
bool diminuir_estoque(int codigo, int estoque) {
      for (int i = 0; i < MAX_LENGTH_CATALOGO; i++) {
            if (catalogo[i].codigo == codigo) {
                  catalogo[i].estoque -= estoque;
                  return true;
            }
      }

      return false;
}


// Lista o catálogo com seus produtos na tela
void listar_catalogo() {
      puts("\033[33;1m\nListando o catálogo...\n\033[m");
      
      puts("Catálogo de produtos:");
      bool isEmpty = true;
      printf("Cód. %-32s %-16s %-7s\n", "Descrição", "Categoria", "Estoque");
      for (int i = 0; i < MAX_LENGTH_CATALOGO; i++) {
            if (catalogo[i].isFilled) {
                  printf("#%03d %-30s %-16s %07d\n", catalogo[i].codigo, catalogo[i].descricao, categorias_nomes[catalogo[i].categoria], catalogo[i].estoque);
                  isEmpty = false;
            }
      }

      if (isEmpty)
            puts("Catálogo está vazio!");
}


// Imprime no console um cabeçalho
void printHeader(char* prompt) {
      printf("\n\033[33;1m%s\n\033[m", prompt);
}

// Imprime no console um sucesso
void printSucess(char* prompt) {
      printf("\033\n[34;1m%s\n\033[m", prompt);
}

// Imprime no console um erro
void printError(char* prompt) {
      printf("\n\033[31;1m%s\n\033[m", prompt);
}
