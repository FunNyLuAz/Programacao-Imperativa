#include <stdio.h>

void transpor(double* matriz_ptr, int linhas, int colunas, double* transposta_ptr);

int main() {

      #define ROWS 3
      #define COLS 2

      double matriz[ROWS][COLS] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6};
      double matriz_t[COLS][ROWS];

      transpor(matriz, ROWS, COLS, matriz_t);

      puts("\nMatriz inicial:");
      for (int i = 0; i < ROWS; i++) {
            printf("| ");
            for (int j = 0; j < COLS; j ++) {
                  printf("%.2lf ", matriz[i][j]);
            }
            puts("|");
      }

      puts("\nMatriz transposta:");
      for (int i = 0; i < COLS; i++) {
            printf("| ");
            for (int j = 0; j < ROWS; j ++) {
                  printf("%.2lf ", matriz_t[i][j]);
            }
            puts("|");
      }

      return 0;
}

void transpor(double* matriz_ptr, int linhas, int colunas, double* transposta_ptr) {
      for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                  double* cur_transp = transposta_ptr + j * linhas + i;
                  *cur_transp = *(matriz_ptr + i * colunas + j);
            }
      }
}
