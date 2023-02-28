#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabela.h"

void writeDataInCarro(CARRO* carro, char* nome, MARCA marca, int ano, double preco, int km) {
      // Grava no carro com os dados passados
      strcpy(carro->nome, nome);
      carro->marca = marca;
      carro->ano = ano;
      carro->preco = preco;
      carro->km = km;
}

void addCarroInTableCarros(CARRO* tableCarros, size_t qtdeCarros, char* nome, MARCA marca, int ano, double preco, int km) {
      // Adiciona um carro à tabela de carros (no final)
      tableCarros = realloc(tableCarros, (qtdeCarros + 1) * sizeof(CARRO));
      writeDataInCarro((tableCarros + qtdeCarros), nome, marca, ano, preco, km);
}

void removeCarroInTableCarros(CARRO* tableCarros, size_t qtdeCarros, int index) {
      // Remove o carro de índice passado da tabela de carros
      for (int i = 0; i < (int) qtdeCarros - 1; i++) {
            if (i >= index)  {
                  CARRO* nextCarro = tableCarros + i + 1;
                  writeDataInCarro(tableCarros + i, nextCarro->nome, nextCarro->marca, nextCarro->ano, nextCarro->preco, nextCarro->km);
            }
      }

      tableCarros = realloc(tableCarros, sizeof(CARRO) * (qtdeCarros - 1));
}

void printTabelaCarros(CARRO* tableCarros, size_t qtdeCarros) {
      // Imprime a tabela com seus dados
      #define TABLE_MASK "%-5s  %-30s  %-4s  %-12s  %-9s  %-8s\n" // Máscara para impressão da tabela
      CARRO* carro;

      printf(TABLE_MASK, "INDEX", "NOME", "ANO", "MARCA", "PREÇO", " KM");
      for (int i = 0; i < (int) qtdeCarros; i++) {
            carro = tableCarros + i;

            char index[6];
            sprintf(index, "%d", i);

            char ano[5];
            sprintf(ano, "%d", carro->ano);

            char km[9];
            sprintf(km, "%d", carro->km);

            char preco[10];
            sprintf(preco, "%.2lf", carro->preco);
            *(strchr(preco, '.')) = ',';  // Converte '.' em ','

            printf(TABLE_MASK, index, carro->nome, ano, convertMarcaEnumStr(carro->marca), preco, km);
      }
}

MARCA convertMarcaStrEnum(char* marca) {
      // Converte a marca de uma string para o enum
      if (!strcmp(marca, "VOLKSWAGEN")) {
            return VOLKSWAGEN;
      } else if (!strcmp(marca, "RENAULT")) {
            return RENAULT;
      } else if (!strcmp(marca, "FORD")) {
            return FORD;
      } else if (!strcmp(marca, "FIAT")) {
            return FIAT;
      } else if (!strcmp(marca, "CHEVROLET")) {
            return CHEVROLET;
      } else if (!strcmp(marca, "HYUNDAI")) {
            return HYUNDAI;
      } else {
            return OUTROS;
      }
}

char* convertMarcaEnumStr(MARCA marca) {
      // Converte a marca de um enum MARCA para uma string
      switch (marca) {
            case VOLKSWAGEN:
                  return "VOLKSWAGEN";
            case RENAULT:
                  return "RENAULT";
            case FORD:
                  return "FORD";
            case FIAT:
                  return "FIAT";
            case CHEVROLET:
                  return "CHEVROLET";
            case HYUNDAI:
                  return "HYUNDAI";
            default:
                  return "OUTROS";
      }
}

void toUpperStr(char* str) {
      #define NUM_LETTERS 26 // Quantidade de letras no alfabeto
      #define ASCII_CODE_A 65 // Código ASCII para o "A"
      #define ASCII_CODE_a 97 // Código ASCII para o "a"

      char* c = str;
      while(*c != '\0') {
            if (*c >= ASCII_CODE_a && *c <= ASCII_CODE_a + NUM_LETTERS) {
                  *c += ASCII_CODE_A - ASCII_CODE_a;
            }
            c++;
      }
}
