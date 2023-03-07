// Lucas Azevedo Dias

/*
Exercício 1 (valor: 5,0 pontos): Uma P.A. (progressão aritmética) é uma 
sequência de números reais na qual a diferença entre dois números consecutivos 
quaisquer é constante, denominada a razão da P.A. Como exemplos, temos as 
seguintes sequências como P.A.: 
 
{ 2, 5, 8, 11, 14, 17, 20 } 
o primeiro termo da P.A. é 2 e a razão da P.A. é 3 
 
{ -4.5, -3.0, -1.5, 0, 1.5, 3.0, 4.5 } 
o primeiro termo da P.A. é -4.5 e a razão é 1.5 
 
{ 10, 6, 2, -2, -6, -10 } 
o primeiro termo da P.A. é 10 e a razão é -4 
 
Escreva um programa na Linguagem C que calcule e imprima (na tela do 
computador) o n-ésimo termo de uma P.A., dados (via leitura do teclado) o 
primeiro termo e a razão da P.A., além do próprio n. Por exemplo, se os dados 
fornecidos para o programa forem: 
• primeiro termo: 2 
• razão: 3 
• n: 4 
o valor impresso pelo programa será 11. 
 
IMPORTANTE: O programa não pode usar qualquer comando de repetição!
*/

#include <stdio.h>

int main() {

      int n; // Índice do termo da P.A.
      double a1; // Primeiro termo da P.A.
      double r; // Razão da P.A.
      double an; // n-ésimo termo da P.A.

      // Registra a1
      puts("\nDigite o primeiro termo da P.A.:");
      scanf("%lf", &a1);

      // Registra n
      puts("\nDigite o indice do termo da P.A. a ser calculado:");
      scanf("%d", &n);

      // Registra r
      puts("\nDigite a razao da P.A.:");
      scanf("%lf", &r);

      // Calcula an
      an = a1 + (n - 1) * r;

      // Exibe an
      printf("\nO %do termo da P.A. sera %.3lf\n", n, an);

      return 0;
}
