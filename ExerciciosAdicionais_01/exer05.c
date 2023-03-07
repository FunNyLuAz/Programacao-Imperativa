/*
5. Escreva um programa na Linguagem C que efetue o cálculo do volume de
combustível gasto em uma viagem, sabendo-se que o carro faz 12 km com um litro de
combustível. Deverão ser fornecidos como entrada do programa os seguintes dados: o
tempo gasto na viagem e a velocidade média.
      Distância = Tempo x Velocidade.
      Volume = Distância / 12.
O programa deverá exibir a distância percorrida e o volume de combustível gasto na
viagem.
*/

#include <stdio.h>

int main() {

      const double GASTOPORLITRO = 12;
      double speed, time;

      printf("\nVelocidade média:\n");
      scanf("%lf", &speed);

      printf("\nTempo de viagem:\n");
      scanf("%lf", &time);

      printf("\nSerá gasto na viagem %.2lf litros de combustível.\n", speed * time / GASTOPORLITRO);

      return 0;
}
