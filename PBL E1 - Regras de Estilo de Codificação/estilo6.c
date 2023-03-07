#include <stdio.h>
#include <stdbool.h>

// MESES DO ANO
enum Mes {JANEIRO, FEVEREIRO, MARCO, ABRIL, MAIO, JUNHO, JULHO, AGOSTO, OUTUBRO, NOVEMBRO, DEZEMBRO};

// DIAS DA SEMANA
enum Dia {SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA, SABADO, DOMINGO};

// NOMES DOS MESES
const char* MESES[] = { "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
    "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro" };

// NOMES DOS DIAS DA SEMANA
const char* DIAS_DA_SEMANA[] = { "Segunda-feira", "Terça-feira", "Quarta-feira",
    "Quinta-feira", "Sexta-feira", "Sábado", "Domingo" };

int selecao_do_mes();
int selecao_do_dia();
bool isDescansar(int mes_selecionado, int dia_selecionado);


int main()
{
    int mes_selecionado;
    mes_selecionado = selecao_do_mes();

    int dia_selecionado;
    dia_selecionado = selecao_do_dia();

    putchar('\n');
    if (isDescansar(mes_selecionado, dia_selecionado))
    {
        puts("Descansar!\n");
    }
    else
    {
        puts("Trabalhar!\n");
    }

    return 0;
}


// SELEÇÃO DO MÊS DO ANO
// Retorna o inteiro correspondente ao mês no "enum Mes"
int selecao_do_mes() {
    puts("Meses do ano: ");
    
    for (int m = JANEIRO; m <= DEZEMBRO; m++)
    {
        printf("\t(%2d) %s\n", m, MESES[m]);
    }

    int mes_selecionado;

    puts("Selecione um mês pelo seu número: ");
    scanf("%d", &mes_selecionado);
    printf("Mês selecionado: %s\n", MESES[mes_selecionado]);

    return mes_selecionado;
}

// SELEÇÃO DO DIA DA SEMANA
// Retorna o inteiro correspondente ao dia no "enum Dia"
int selecao_do_dia() {
    putchar('\n');
    puts("Dias da semana: ");

    for (int d = SEGUNDA; d <= DOMINGO; d++)
    {
        printf("\t(%2d) %s\n", d, DIAS_DA_SEMANA[d]);
    }

    int dia_selecionado;
    puts("Selecione um dia pelo seu número: ");
    scanf("%d", &dia_selecionado);
    printf("Dia selecionado: %s\n", DIAS_DA_SEMANA[dia_selecionado]);

    return dia_selecionado;
}

// TOMADA DE DECISÃO
// Retorna true se é para descansar ou false se é para trabalhar
bool isDescansar(int mes_selecionado, int dia_selecionado) {
    if (mes_selecionado == JANEIRO || dia_selecionado == DOMINGO)
    {
        return true;
    }
    else
    {
        return false;
    }
}
