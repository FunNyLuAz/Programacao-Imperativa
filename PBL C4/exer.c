#include <stdio.h>
#include <string.h>

#define NUM_MESES 12

const int NUM_PINTORES = 20;

enum Mes {JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ};

char mes_str[NUM_MESES][10] = { "janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho",
                            "agosto", "setembro", "outubro", "novembro", "dezembro" };

struct Pessoa
{
    char nome[50];
    enum Mes mes; // mês de aniversário
};

int main()
{
    struct Pessoa pintor[NUM_PINTORES];

    pintor[ 0].mes = JAN; strcpy(pintor[ 0].nome, "Leonardo da Vinci");
    pintor[ 1].mes = ABR; strcpy(pintor[ 1].nome, "Sandro Botticelli");
    pintor[ 2].mes = AGO; strcpy(pintor[ 2].nome, "Georges Seurat");
    pintor[ 3].mes = ABR; strcpy(pintor[ 3].nome, "Vincent van Gogh");
    pintor[ 4].mes = SET; strcpy(pintor[ 4].nome, "Paul Gauguin");
    pintor[ 5].mes = JUN; strcpy(pintor[ 5].nome, "Edouard Manet"); 
    pintor[ 6].mes = OUT; strcpy(pintor[ 6].nome, "Paul Cezanne"); 
    pintor[ 7].mes = JUN; strcpy(pintor[ 7].nome, "Auguste Renoir"); 
    pintor[ 8].mes = JUN; strcpy(pintor[ 8].nome, "Claude Monet");
    pintor[ 9].mes = AGO; strcpy(pintor[ 9].nome, "Pablo Picasso");
    pintor[10].mes = DEZ; strcpy(pintor[10].nome, "Edgar Degas");
    pintor[11].mes = ABR; strcpy(pintor[11].nome, "Edvard Munch");
    pintor[12].mes = JAN; strcpy(pintor[12].nome, "Michelangelo Merisi (Caravaggio)");
    pintor[13].mes = JAN; strcpy(pintor[13].nome, "Michelangelo Buonarroti");
    pintor[14].mes = SET; strcpy(pintor[14].nome, "Tarsila do Amaral"); 
    pintor[15].mes = AGO; strcpy(pintor[15].nome, "Gustav Klimt"); 
    pintor[16].mes = NOV; strcpy(pintor[16].nome, "Rembrandt van Rijn"); 
    pintor[17].mes = MAI; strcpy(pintor[17].nome, "Amedeo Modigliani"); 
    pintor[18].mes = SET; strcpy(pintor[18].nome, "Caillebotte"); 
    pintor[19].mes = SET; strcpy(pintor[19].nome, "Joseph Turner"); 

    puts("\nMeses para a pesquisa:");
    for (int i = 0; i < NUM_MESES; i++)
        printf("(%2d) %s\n", i + 1, mes_str[i]);

    int choice;
    printf("\nEscolha um mês pelo seu número: ");
    scanf("%d", &choice);
    choice--;

    if (choice < 0 || choice > NUM_MESES - 1) {
        puts("\nEscolha inválida!");
        return 1;
    }

    printf("\nPintores nascidos no mês de %s:", mes_str[choice]);
    int counter = 0;
    for (int i = 0; i < NUM_PINTORES; i++)
        if (pintor[i].mes == choice) {
            printf("\n(%d) %s", counter + 1, pintor[i].nome);
            counter++;
        }

    if (counter == 0)
        printf("\n\n==> Nenhum pintor foi encontrado.\n");
    else if (counter == 1)
        printf("\n\n==> Apenas um pintor foi encontrado.\n");
    else
        printf("\n\n==> %d pintores foram encontrados.\n", counter);

    return 0;
}
