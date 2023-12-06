#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;
} Produto;

typedef struct Nodo {
    Produto produto;
    struct Nodo* proximo;
} Nodo;

Nodo* inicializaLista() {
    return NULL;
}

Nodo* adicionaProduto(Nodo* lista) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    
    printf("Digite o código do produto: ");
    scanf("%d", &novoNodo->produto.codigo);
    
    printf("Digite a descrição do produto: ");
    scanf("%s", novoNodo->produto.descricao);
    
    printf("Digite a quantidade do produto: ");
    scanf("%d", &novoNodo->produto.quantidade);
    
    printf("Digite o valor do produto: ");
    scanf("%f", &novoNodo->produto.valor);
    
    novoNodo->proximo = lista;
    
    return novoNodo;
}

void imprimeRelatorio(Nodo* lista) {
    Nodo* atual = lista;
    
    while (atual != NULL) {
        printf("Código: %d | Descrição: %s | Quantidade: %d | Valor: %.2f\n",
               atual->produto.codigo, atual->produto.descricao,
               atual->produto.quantidade, atual->produto.valor);
        atual = atual->proximo;
    }
}

void pesquisaProduto(Nodo* lista, int codigo) {
    Nodo* atual = lista;
    while (atual != NULL) {
        if (atual->produto.codigo == codigo) {
            printf("Código: %d | Descrição: %s | Quantidade: %d | Valor: %.2f\n",
                   atual->produto.codigo, atual->produto.descricao,
                   atual->produto.quantidade, atual->produto.valor);
            return;
        }
        atual = atual->proximo;
    }
    printf("Produto não encontrado.\n");
}

Nodo* removeProduto(Nodo* lista, int codigo) {
    Nodo* atual = lista;
    Nodo* anterior = NULL;

    while (atual != NULL) {
        if (atual->produto.codigo == codigo) {
            if (anterior == NULL) {
                Nodo* temp = atual->proximo;
                free(atual);
                return temp;
            } else {
                anterior->proximo = atual->proximo;
                free(atual);
                return lista;
            }
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("Produto não encontrado.\n");
    return lista;
}

int main() {
    Nodo* lista = inicializaLista();
    int opcao, codigo;

    do {
        printf("\n=== Menu ===\n");
        printf("1. Adicionar produto\n");
        printf("2. Imprimir relatório\n");
        printf("3. Pesquisar produto\n");
        printf("4. Remover produto\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                lista = adicionaProduto(lista);
                break;
            case 2:
                imprimeRelatorio(lista);
                break;
            case 3:
                printf("Digite o código do produto a ser pesquisado: ");
                scanf("%d", &codigo);
                pesquisaProduto(lista, codigo);
                break;
            case 4:
                printf("Digite o código do produto a ser removido: ");
                scanf("%d", &codigo);
                lista = removeProduto(lista, codigo);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    Nodo* atual = lista;
    Nodo* proximo;
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    return 0;
}
