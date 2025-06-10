#include <stdio.h>
#include <string.h>

#define MAX_PIZZAS 100
#define MAX_CLIENTES 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    float preco;
} Pizza;

typedef struct {
    char nome[MAX_NOME];
    char endereco[MAX_NOME];
} Cliente;

Pizza pizzas[MAX_PIZZAS];
int numPizzas = 0;

Cliente clientes[MAX_CLIENTES];
int numClientes = 0;

void cadastrarPizza() {
    if (numPizzas < MAX_PIZZAS) {
        printf("Digite o nome da pizza: ");
        scanf("%s", pizzas[numPizzas].nome);
        printf("Digite o preço da pizza: ");
        scanf("%f", &pizzas[numPizzas].preco);
        numPizzas++;
        printf("Pizza cadastrada com sucesso!\n");
    } else {
        printf("Limite de pizzas atingido!\n");
    }
}

void cadastrarCliente() {
    if (numClientes < MAX_CLIENTES) {
        printf("Digite o nome do cliente: ");
        scanf("%s", clientes[numClientes].nome);
        printf("Digite o endereço do cliente: ");
        scanf("%s", clientes[numClientes].endereco);
        numClientes++;
        printf("Cliente cadastrado com sucesso!\n");
    } else {
        printf("Limite de clientes atingido!\n");
    }
}

void listarPizzas() {
    printf("Pizzas cadastradas:\n");
    for (int i = 0; i < numPizzas; i++) {
        printf("%s - R$ %.2f\n", pizzas[i].nome, pizzas[i].preco);
    }
}

void listarClientes() {
    printf("Clientes cadastrados:\n");
    for (int i = 0; i < numClientes; i++) {
        printf("%s - %s\n", clientes[i].nome, clientes[i].endereco);
    }
}

void venderPizza() {
    char nomeCliente[MAX_NOME];
    printf("Digite o nome do cliente: ");
    scanf("%s", nomeCliente);
    int clienteEncontrado = -1;
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].nome, nomeCliente) == 0) {
            clienteEncontrado = i;
            break;
        }
    }
    if (clienteEncontrado == -1) {
        printf("Cliente não encontrado!\n");
        return;
    }
    printf("Pizzas disponíveis:\n");
    for (int i = 0; i < numPizzas; i++) {
        printf("%d - %s - R$ %.2f\n", i + 1, pizzas[i].nome, pizzas[i].preco);
    }
    float total = 0;
    printf("Digite o número da pizza que deseja comprar (0 para finalizar): ");
    int opcao;
    printf("Compras:\n");
    while (1) {
        scanf("%d", &opcao);
        if (opcao == 0) {
            break;
        }
        if (opcao > 0 && opcao <= numPizzas) {
            total += pizzas[opcao - 1].preco;
            printf("%s - R$ %.2f\n", pizzas[opcao - 1].nome, pizzas[opcao - 1].preco);
        } else {
            printf("Opção inválida!\n");
        }
        printf("Digite o número da pizza que deseja comprar (0 para finalizar): ");
    }
    printf("Total: R$ %.2f\n", total);
}

int main() {
    int opcao;
    printf("Seja bem-vindo(a) a Nostra Pizzaria :)\n");
    printf("Como podemos ajudar?\n");
    do {
        printf("1 - Cadastrar pizza\n");
        printf("2 - Cadastrar cliente\n");
        printf("3 - Listar pizzas\n");
        printf("4 - Listar clientes\n");
        printf("5 - Vender pizza\n");
        printf("0 - Sair\n");
        printf("Selecione uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrarPizza();
                break;
            case 2:
                cadastrarCliente();
                break;
            case 3:
                listarPizzas();
                break;
            case 4:
                listarClientes();
                break;
            case 5:
                venderPizza();
                break;
            case 0:
                printf("Obrigado volte sempre...");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);
    return 0;
}