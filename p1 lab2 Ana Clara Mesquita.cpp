#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ALUNOS 2000

typedef struct {
    char nome[100];
    int cpf;
    float peso;
    float altura;
} Aluno;

int total = 0;

// Função para calcular e exibir IMC
void calcularIMC(Aluno aluno) {
    float imc = aluno.peso / (aluno.altura * aluno.altura);
    printf("O IMC do aluno eh %.2f\n", imc);
    if (imc < 18.5)
        printf("O aluno esta abaixo do peso ideal.\n");
    else if (imc > 24)
        printf("O aluno esta acima do peso ideal.\n");
    else
        printf("O aluno esta no peso ideal.\n");
}

// Função para cadastrar alunos
void cadastrarAlunos(Aluno alunos[]) {
    int qtd;
    printf("Quantos alunos voce deseja cadastrar: ");
    scanf("%d", &qtd);
    getchar(); // limpa o buffer do teclado

    for (int i = 0; i < qtd; i++) {
        printf("\n--- Cadastro do aluno %d ---\n", i + 1);
        printf("Insira o nome do aluno: ");
        fgets(alunos[total].nome, 100, stdin);
        alunos[total].nome[strcspn(alunos[total].nome, "\n")] = 0; // remove o \n do final

        printf("Insira o CPF do aluno: ");
        scanf("%d", &alunos[total].cpf);

        printf("Insira o peso do aluno (em kg): ");
        scanf("%f", &alunos[total].peso);

        printf("Insira a altura do aluno (em metros): ");
        scanf("%f", &alunos[total].altura);
        getchar(); // limpa o buffer

        calcularIMC(alunos[total]);
        total++;
    }
}

// Função para exibir os dados de um aluno pelo CPF
void exibirAluno(Aluno alunos[]) {
    if (total == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    int cpf;
    printf("Digite o CPF do aluno para exibir os dados: ");
    scanf("%d", &cpf);

    for (int i = 0; i < total; i++) {
        if (alunos[i].cpf == cpf) {
            printf("\n--- Dados do aluno ---\n");
            printf("Nome: %s\n", alunos[i].nome);
            printf("CPF: %d\n", alunos[i].cpf);
            printf("Peso: %.2f\n", alunos[i].peso);
            printf("Altura: %.2f\n", alunos[i].altura);
            calcularIMC(alunos[i]);
            return;
        }
    }

    printf("Aluno com CPF %d nao encontrado.\n", cpf);
}

// Função para imprimir todos os alunos cadastrados
void imprimirAlunos(Aluno alunos[]) {
    if (total == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("\n--- Lista de alunos cadastrados ---\n");
    for (int i = 0; i < total; i++) {
        printf("[%d] Nome: %s | CPF: %d | Peso: %.2f | Altura: %.2f\n",
               i + 1, alunos[i].nome, alunos[i].cpf, alunos[i].peso, alunos[i].altura);
    }
}

// Função principal do menu
void menu(Aluno alunos[]) {
    int op;

    do {
        printf("\n=== MENU ===\n");
        printf("1 - Cadastrar alunos\n");
        printf("2 - Exibir aluno por CPF\n");
        printf("3 - Imprimir todos os alunos\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);
        getchar(); // limpa buffer

        switch (op) {
            case 1:
                cadastrarAlunos(alunos);
                break;
            case 2:
                exibirAluno(alunos);
                break;
            case 3:
                imprimirAlunos(alunos);
                break;
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (op != 4);
}

int main() {
    Aluno alunos[MAX_ALUNOS];
    menu(alunos);
    return 0;
}

