#include <stdio.h>
#include <string.h>

#define MAX_CDS 100
#define MAX_NOME 50

typedef struct {
    char banda[100];
    int ano;
    char genero[100];
    int quantidade;
    float preco;
} CD;

CD cds[MAX_CDS];
int numCds = 0;

void cadastrarCd() {
    if (numCds < MAX_CDS) {
        printf("Digite o nome da banda: \n");
        scanf("%s", cds[numCds].banda);
        printf("Digite o ano do CD: \n");
        scanf("%d", &cds[numCds].ano);
        printf("Digite o gênero do CD: \n");
        scanf("%s", cds[numCds].genero);
        printf("Digite a quantidade do CD: \n");
        scanf("%d", &cds[numCds].quantidade);
        printf("Digite o preço do CD: \n");
        scanf("%f", &cds[numCds].preco);
        numCds++;
        printf("CD cadastrado com sucesso!\n");
    } else {
        printf("Limite de CDs atingido!\n");
    }
}

void venderCd() {
    char banda[MAX_NOME];
    int quantidade;
    printf("Digite a banda: ");
    scanf("%s", banda);
    printf("Digite a quantidade da comprada: ");
    scanf("%d", &quantidade);
    for (int i = 0; i < numCds; i++) {
        if (strcmp(cds[i].banda, banda) == 0) {
            if (cds[i].quantidade >= quantidade) {
                float valorTotal = quantidade * cds[i].preco;
                cds[i].quantidade -= quantidade;
                printf("Compra realizada com sucesso!\n");
                printf("Valor total: R$ %.2f\n", valorTotal);
                printf("Quantidade restante: %d\n", cds[i].quantidade);
                return;
            } else {
                printf("Sem estoque!\n");
                return;
            }
        }
    }
    printf("CD não encontrado!\n");
}

void pesquisarPorGenero() {
    char genero[MAX_NOME];
    printf("Digite o gênero: ");
    scanf("%s", genero);
    int encontrado = 0;
    for (int i = 0; i < numCds; i++) {
        if (strcmp(cds[i].genero, genero) == 0) {
            printf("Banda: %s\n", cds[i].banda);
            printf("Ano: %d\n", cds[i].ano);
            printf("Quantidade: %d\n", cds[i].quantidade);
            printf("Preço: R$ %.2f\n", cds[i].preco);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhum CD encontrado com esse gênero!\n");
    }
}

void consultarCd() {
    char banda[MAX_NOME];
    printf("Digite o nome da banda: ");
    scanf("%s", banda);
    for (int i = 0; i < numCds; i++) {
        if (strcmp(cds[i].banda, banda) == 0) {
            printf("Banda: %s\n", cds[i].banda);
            printf("Ano: %d\n", cds[i].ano);
            printf("Quantidade: %d\n", cds[i].quantidade);
            printf("Preço: R$ %.2f\n", cds[i].preco);
            
        }
    }
    printf("CD não encontrado!\n");
}

int main() {
    int opcao;
    do {
        printf("1 - Cadastrar CD\n");
        printf("2 - Vender CD\n");
        printf("3 - Pesquisar por gênero\n");
        printf("4 - Consultar CD\n");
        printf("0 - Sair\n");
        printf("Selecione uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrarCd();
                break;
            case 2:
                venderCd();
                break;
            case 3:
                pesquisarPorGenero();
                break;
            case 4:
                consultarCd();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);
    return 0;
}
