// Lucas Azevedo Dias

/*
Exercício 2 (valor: 5,0 pontos): Em certo país, as placas dos veículos possuem 4 algarismos, sendo:
• O primeiro algarismo corresponde a um estado do país
• O segundo algarismo corresponde a uma cidade daquele estado
• O terceiro e o quarto algarismos formam o número do veículo em sua cidade
Por exemplo, o veículo com placa 5832 indica que está registrado no estado 5, na cidade 8 (do estado 5) e tem o número 32 na cidade.
Escreva um programa na Linguagem C que leia um valor inteiro de quatro algarismos correspondente à placa de um veículo e imprima separadamente o número do estado, o número da cidade no estado e o número do veículo na cidade.
IMPORTANTE: O resultado da leitura do número da placa do veículo tem, necessariamente, que ser armazenado em uma variável de um dos seguintes tipos: int, unsigned int, short ou unsigned short.
*/

#include <stdio.h>

int main() {

      unsigned int placa;
      unsigned char digits[4];

      puts("\nDigite a placa:");
      scanf("%4d", &placa);

      if (placa / 1000 <= 0) {
            puts("\n\033[1;31mErro! Numero possui menos de 4 digitos.\033[m");
            return 1;
      }

      for (char i = 0; i < 4; i++) {
            
            digits[i] = placa % 10;
            placa /= 10;
      }
      
      printf("\nEstado: %d\n", digits[3]);
      printf("Cidade: %d\n", digits[2]);
      printf("Estado: %d%d\n", digits[1], digits[0]);

      return 0;
}
