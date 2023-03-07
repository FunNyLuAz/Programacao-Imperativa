#include <stdio.h>

typedef struct {
      char nome[40];
      int idade;
} Pessoa; 

void preencher(Pessoa* p);

int main() {

      Pessoa pessoa;

      puts("\nCadastrando uma nova pessoa...");
      preencher(&pessoa);

      printf("\nOs dados cadastrados foram:\nNome: %s\nIdade: %d anos\n", pessoa.nome, pessoa.idade);

      return 0;
}

void preencher(Pessoa* p) {
      // Preenche os dados de um struct com entradas do teclado
      puts("\nDigite o nome da pessoa:");
      scanf("%s", p->nome);

      fflush(stdin);

      puts("\nDigite a idade da pessoa:");
      scanf("%d", &p->idade);
}
