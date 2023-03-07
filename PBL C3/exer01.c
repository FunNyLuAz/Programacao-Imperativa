// Lucas Azevedo Dias

#include <stdio.h>
#include <stdlib.h>

int main() {

      system("chcp 65001");

      int n;

      printf("\nDigite o tamanho da sequência a ser mostrado: ");
      scanf("%d", &n);

      printf("\nSequência de Fibonacci até a posição %d:\n", n);
      long long old1 = 0, old2 = 1, cur;
      for (int i = 0; i < n; i++) {
            if (i + 1 < n) {
                  printf("%lld, ", old1);
            } else {
                  printf("%lld\n", old1);
            }

            cur = old1 + old2;
            old1 = old2;
            old2 = cur;
      }

      return 0;
}
