/* Programa para criptografar e descriptografar
o primeiro nome e o sobrenome de uma pessoa, sendo que
ambos podem ser nomes compostos */

#include <stdio.h>

const char LF = 10; // caracter de fim de linha (Line Feed)

void ler_nome(char nome[], int qtde_letras);
void criptografar_nome(char nome[], char nome_criptografado[], int shift);
void descriptografar_nome(char nome_criptografado[], char nome_descriptografado[], int shift);


int main()
{
    const int MAX_LETRAS = 9; // máximo de letras para as strings
    const int TAMANHO_BUFFER = MAX_LETRAS + 1; // tamanho do buffer nas strings (precisa do caracter de encerramento ao fim)

    const int PRIMEIRO_NOME_SHIFT = 1; // shift no alfabeto para a string primeiro_nome
    const int SOBRENOME_SHIFT = 2; // shift no alfabeto para a string sobrenome


    char primeiro_nome[TAMANHO_BUFFER];
    char sobrenome[TAMANHO_BUFFER];

    // LEITURA DO PRIMEIRO NOME:
    printf("Digite o primeiro nome e tecle ENTER: ");
    ler_nome(primeiro_nome, MAX_LETRAS);
    printf("Primeiro nome armazenado: %s\n", primeiro_nome);

    // LEITURA DO SOBRENOME:
    printf("Digite o sobrenome e tecle ENTER: ");
    ler_nome(sobrenome, MAX_LETRAS);
    printf("Sobrenome armazenado: %s\n", sobrenome);


    char primeiro_nome_criptografado[TAMANHO_BUFFER];
    char sobrenome_criptografado[TAMANHO_BUFFER];

    // CRIPTOGRAFIA DO PRIMEIRO NOME:
    criptografar_nome(primeiro_nome, primeiro_nome_criptografado, PRIMEIRO_NOME_SHIFT);
    
    // CRIPTOGRAFIA DO SOBRENOME:
    criptografar_nome(sobrenome, sobrenome_criptografado, SOBRENOME_SHIFT);

    // RESULTADOS DA CRIPTOGRAFIA:
    printf("Primeiro nome criptografado: %s\n", primeiro_nome_criptografado);
    printf("Sobrenome criptografado: %s\n", sobrenome_criptografado);


    char primeiro_nome_descriptografado[TAMANHO_BUFFER];
    char sobrenome_descriptografado[TAMANHO_BUFFER];

    // DESCRIPTOGRAFIA DO PRIMEIRO NOME:
    descriptografar_nome(primeiro_nome_criptografado, primeiro_nome_descriptografado, PRIMEIRO_NOME_SHIFT);
    
    // DESCRIPTOGRAFIA DO SOBRENOME:
    descriptografar_nome(sobrenome_criptografado, sobrenome_descriptografado, SOBRENOME_SHIFT);

    // RESULTADOS DA DESCRIPTOGRAFIA:
    printf("Primeiro nome descriptografado: %s\n", primeiro_nome_descriptografado);
    printf("Sobrenome descriptografado: %s\n", sobrenome_descriptografado);


    return 0;
}


// LEITURA DE UM NOME (E GRAVAÇÃO NO PRÓPRIO ARRAY PASSADO)
void ler_nome(char nome[], int qtde_letras) {
    int i, nao_fim_linha;

    i = 0;
    nao_fim_linha = 1;

    while (i < qtde_letras && nao_fim_linha)
    {
        char c = getchar();
        if (c == LF) // verifica se é fim de linha
            nao_fim_linha = 0;
        else
        {
            nome[i] = c;
            i++;
        }
    }

    nome[i] = '\0'; // termina a string

    while (nao_fim_linha) // descarta tudo até o fim da linha
    {
        char c = getchar();
        if (c == LF) // verifica se é fim de linha
            nao_fim_linha = 0;
    }
}

// CRIPTOGRAFIA DE UM NOME (E GRAVAÇÃO NO OUTRO ARRAY PASSADO)
void criptografar_nome(char nome[], char nome_criptografado[], int shift) {
    int i = 0;
    while (nome[i]) // enquanto não for da string
    {
        nome_criptografado[i] = nome[i] + shift; // criptografa o caracter
        i++;
    }

    nome_criptografado[i] = '\0'; // termina a string
}

// DESCRIPTOGRAFIA DE UM NOME (E GRAVAÇÃO NO OUTRO ARRAY PASSADO)
void descriptografar_nome(char nome_criptografado[], char nome_descriptografado[], int shift) {
    int i = 0;
    while (nome_criptografado[i]) // enquanto não for fim da string
    {
        nome_descriptografado[i] = nome_criptografado[i] - shift; // descriptografa o caracter
        i++;
    }

    nome_descriptografado[i] = '\0'; // termina a string
}
