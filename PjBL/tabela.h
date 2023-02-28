#ifndef TABELA_H
#define TABELA_H

typedef enum {
      OUTROS,
      VOLKSWAGEN,
      RENAULT,
      FORD,
      FIAT,
      CHEVROLET,
      HYUNDAI
} MARCA; // Marcas possíves de carros

typedef struct {
      char nome[31];
      MARCA marca;
      int ano;
      double preco;
      int km;
} CARRO; // Dados de um carro específico

void writeDataInCarro(CARRO*, char*, MARCA, int, double, int);
void addCarroInTableCarros(CARRO*, size_t, char*, MARCA, int, double, int);
void removeCarroInTableCarros(CARRO*, size_t, int);
void printTabelaCarros(CARRO*, size_t);
MARCA convertMarcaStrEnum(char*);
char* convertMarcaEnumStr(MARCA);
void toUpperStr(char*);

#endif
