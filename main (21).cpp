#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;

Aluno Alunos[3];

void listarAlunos() {
    for (int i = 0; i < 3; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", Alunos[i].nome);
        printf("Idade: %d\n", Alunos[i].idade);
        printf("Nota: %.2f\n", Alunos[i].nota);
    }
}

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\nDigite os dados do aluno %d: \n", i + 1);
        printf("Nome: \n");
        scanf("%s", Alunos[i].nome);
        printf("Idade: \n");
        scanf("%d", &Alunos[i].idade);
        printf("Nota: \n");
        scanf("%f", &Alunos[i].nota);
    }
    listarAlunos();
    return 0;
}