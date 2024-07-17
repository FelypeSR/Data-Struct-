#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node {
  int num;
  struct node *esq;
  struct node *dir;
} No;

No *remover(No *node, int num);
if (node == NULL){
  return node;

}
//remover a esquerda//
if (num < node ->num){
  node ->num = delete(node ->esq, num);

}
//remover a direita//
 if (num < node ->num){
  node -> num = delete(node ->dir, num);
 }
//caso do no com um filho ou nenhum //
//para estes casos deve ser mulo a direção//
if (node -> esq == NULL || node -> dir == NULL){
  //
}

No *criar_no(int num = -1) {
  No *node = (No *)malloc(sizeof(No));

  if (num == -1) {
    // printf("Digite o numero: ");
    // scanf("%d", &node->num);
    node->num = rand() % 100;
    printf("%d, ", node->num);
  } else {
    node->num = num;
  }

  node->esq = NULL;
  node->dir = NULL;

  return node;
}

void inserir_no(No *node, No *novo) {
  if (node == NULL) {
    printf("Erro\n");
    return;
  }

  if (node->num == novo->num) {
    printf("Número já existe\n");
    return;
  }

  if (node->num < novo->num) {
    if (node->dir == NULL) {
      node->dir = novo;
      return;
    }
    inserir_no(node->dir, novo);
  } else {
    if (node->esq == NULL) {
      node->esq = novo;
      return;
    }
    inserir_no(node->esq, novo);
  }
}

No *buscar_no(No *node, int num) {
  if (node == NULL) {
    // printf("Número não encontrado\n");
    return NULL;
  }

  if (node->num == num) {
    return node;
  }

  if (node->num < num) {
    return buscar_no(node->dir, num);
  } else {
    return buscar_no(node->esq, num);
  }
}

void imprimir(No *node, int tab = 0) {
  if (node == NULL) return;

  imprimir(node->dir, tab + 1);
  for (int i = 0; i < tab; i++) {
    printf("\t");
  }
  printf("%d\n", node->num);
  imprimir(node->esq, tab + 1);
}

void inserir_raiz(No **raiz) {
  if (*raiz == NULL) {
    *raiz = criar_no();
    return;
  }

  No *novo = criar_no();
  inserir_no(*raiz, novo);
}

void buscar_raiz(No *raiz) {
  int num = 0;
  printf("Digite o numero: ");
  scanf("%d", &num);
  No *res = buscar_no(raiz, num);
  if (res == NULL) {
    printf("Numero não encontrado");
  } else {
    imprimir(res);
  }
}

int altura(No *node) {
  if (node == NULL) {
    return 0;
  }

  if ((node->esq == NULL) && (node->dir == NULL)) {
    return 1;
  }

  return 1 + fmax(altura(node->esq), altura(node->dir));

  // int altura_esq = altura(node->esq);
  // int altura_dir = altura(node->dir);
  // if (altura_esq > altura_dir) {
  //   return altura_esq + 1;
  // } else {
  //   return altura_dir + 1;
  // }
}

int fator_balanceamento(No *node) {
  return altura(node->esq) - altura(node->dir);
}

No *buscar_pai(No *node, int num) {
  if (node == NULL) return NULL;

  if ((node->esq != NULL) && (node->esq->num == num)) {
    return node;
  }

  if ((node->dir != NULL) && (node->dir->num == num)) {
    return node;
  }

  if (node->num < num) {
    return buscar_pai(node->dir, num);
  } else {
    return buscar_pai(node->esq, num);
  }
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  No *no = criar_no(5);
  No *root = no;

  no = criar_no(6);
  inserir_no(root, no);
  No *no4 = criar_no(4);
  inserir_no(root, no4);
  no = criar_no(2);
  inserir_no(root, no);
  no = criar_no(1);
  inserir_no(root, no);
  // no = criar_no(3);
  // inserir_no(root, no);

  imprimir(root);
  printf("================\n");
  printf("Altura arvore: %d\n", altura(root));
  printf("FB raiz: %d\n", fator_balanceamento(root));

  return 0;
}
