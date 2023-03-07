#include <stdio.h>

int contar(char* texto, char chave);

int main() {

      char* texto = "Lorem ipsum dolor sit amet.";
      char chave = 'o';

      printf("\nNo texto, houve a aparição de %d caracteres \'%c\'.\n", contar(texto, chave), chave);

      return 0;
}

int contar(char* texto, char chave) {
      // Conta a quantidade de aparições do caracter chave passado
      int contador = 0;

      while (*texto != '\0') {
            if (*texto == chave) {
                  contador++;
            }
            texto++;
      }

      return contador;
}
