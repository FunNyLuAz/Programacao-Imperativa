#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese"); //habilita a acentuação para o português

    char nomeDoPaciente[20]; // nome do paciente
    puts("Digite o seu nome: ");
    scanf("%s", nomeDoPaciente);

    int idadeDoPaciente = 0; // idade do paciente
    puts("Digite a sua idade: ");
    scanf("%d", &idadeDoPaciente);
    
    printf("%s, você tem %d anos.\n", nomeDoPaciente, idadeDoPaciente);
    
    return 0;
}