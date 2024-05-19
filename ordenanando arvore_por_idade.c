//criar uma lista atribuindo nome, idade e codigo, organizando por idade a arvore//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura básica para os dados
typedef struct pessoa {
    char nome[50];
    int idade;
    int code;
    struct pessoa *next;
    struct pessoa *prev;
} pessoa;

// Função para criar uma nova pessoa
pessoa* criar_pessoa(int idade, int code) {
    // Alocar memória
    pessoa *novapessoa = (pessoa*)malloc(sizeof(pessoa));
    if (novapessoa == NULL) {
        printf("Erro ao alocar dados\n");
        return NULL;
    }

    novapessoa->idade = idade;
    novapessoa->code = code;

    printf("Digite o nome: ");
    fgets(novapessoa->nome, sizeof(novapessoa->nome), stdin);
    
    // Remove a nova linha do final do nome, se existir
    size_t len = strlen(novapessoa->nome);
    if (len > 0 && novapessoa->nome[len - 1] == '\n') {
        novapessoa->nome[len - 1] = '\0';
    }

    novapessoa->next = NULL;
    novapessoa->prev = NULL;

    return novapessoa;
}

// Função para inserir pessoa na árvore
pessoa* inserir_pessoa(pessoa *raiz, int idade, int code) {
    if (raiz == NULL) {
        // Se a raiz for nula, retorna uma nova pessoa
        return criar_pessoa(idade, code);
    }

    if (idade < raiz->idade) {
        raiz->prev = inserir_pessoa(raiz->prev, idade, code);
    } else {
        raiz->next = inserir_pessoa(raiz->next, idade, code);
    }

    return raiz;
}

// Função para imprimir a árvore em ordem
void imprimir_ordem(pessoa *raiz) {
    if (raiz != NULL) {
        imprimir_ordem(raiz->prev);
        printf("Nome: %s, Idade: %d, Code: %d\n", raiz->nome, raiz->idade, raiz->code);
        imprimir_ordem(raiz->next);
    }
}

int main(void) {
    pessoa *raiz = NULL;
    int options;

    while (1) {
        printf("-- Menu --\n");
        printf("1 - Inserir pessoa\n");
        printf("2 - Ver lista ordenada\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &options);
        getchar(); // Limpar o buffer de entrada para fgets funcionar corretamente

        switch (options) {
            case 1: {
                int idade, code;
                printf("Digite a idade da pessoa: ");
                scanf("%d", &idade);
                printf("Digite o código da pessoa: ");
                scanf("%d", &code);
                getchar(); // Limpar o buffer de entrada

                raiz = inserir_pessoa(raiz, idade, code);
                break;
            }
            case 2:
                printf("Lista ordenada de pessoas:\n");
                imprimir_ordem(raiz);
                break;
            case 3:
                printf("Saindo...\n");
                exit(0);
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }

    return 0;
}

