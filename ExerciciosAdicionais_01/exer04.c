/*
4. Escreva um programa na Linguagem C que leia um valor de hora no formato
hora:minutos e informe (calcule) o total de minutos que se passaram desde o início
do dia (0:00h).
*/

#include <stdio.h>

int main() {

      int hour, minute, totm;

      printf("\nDigite a hora abaixo [hh:mm]:\n");
      scanf("%d:%d", &hour, &minute);

      if(hour >= 24) {
            hour %= 24;
      }
      
      if(minute >= 60) {
            hour += minute / 60;
            minute %= 60;
      }

      totm = hour * 60 + minute;

      printf("\nSe passaram %d minutos desde o início do dia\n", totm);

      return 0;
}
