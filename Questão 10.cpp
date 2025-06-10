#include <stdio.h>

typedef struct {
    char nome[50];
    int quant;
    float preco;
} Produto;

Produto produto;

void cadastrarProduto() {
    printf("Digite o nome do produto: ");
    scanf("%49s", produto.nome);
    printf("Digite a quantidade: ");
    scanf("%d", &produto.quant);
    printf("Digite o preço do produto: ");
    scanf("%f", &produto.preco);
    printf("Produto cadastrado com sucesso!\n");
}

void visualizarProduto() {
    printf("Informações do produto:\n");
    printf("Nome: %s\n", produto.nome);
    printf("Quantidade: %d\n", produto.quant);
    printf("Preço: R$ %.2f\n", produto.preco);
}

void realizarCompra() {
    int quantCompra;
    printf("Digite a quantidade a ser comprada: ");
    scanf("%d", &quantCompra);
    if (quantCompra <= produto.quant) {
        float valorTotal = quantCompra * produto.preco;
        produto.quant -= quantCompra;
        printf("Compra feita!\n");
        printf("Quantidade do estoque: %d\n", produto.quant);
        printf("Valor total da compra: R$ %.2f\n", valorTotal);
    } else {
        printf("Quantidade de estoque insuficiente!\n");
    }
}

int main() {
    int opcao;
    do {
        printf("1 - Cadastrar produto\n");
        printf("2 - ver produto\n");
        printf("3 - Comprar\n");
        printf("0 - Sair\n");
        printf("Selecione uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                visualizarProduto();
                break;
            case 3:
                realizarCompra();
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
