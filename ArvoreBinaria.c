#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char nome[20];
    int quantidadeGrammy;
} Artista;

typedef struct no {
    Artista artista;
    struct no *direita, *esquerda;
} NoArv;

Artista cadastrarArtista() {
    Artista a;
    printf("Digite o nome do artista e a quantidade de Grammy:");
    scanf("%s %d", a.nome, &a.quantidadeGrammy);
    return a;
}

NoArv* inserir_versao_1(NoArv* raiz, Artista a) {
    if (raiz == NULL) {
        NoArv* aux = malloc(sizeof(NoArv));
        aux->artista = a;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    } else {
        if (a.quantidadeGrammy < raiz->artista.quantidadeGrammy)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, a);
        else
            raiz->direita = inserir_versao_1(raiz->direita, a);
        return raiz;
    }
}

void inserir_versao_2(NoArv** raiz, Artista a) {
    if (*raiz == NULL) {
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->artista = a;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    } else {
        if (a.quantidadeGrammy < (*raiz)->artista.quantidadeGrammy)
            inserir_versao_2(&((*raiz)->esquerda), a);
        else
            inserir_versao_2(&((*raiz)->direita), a);
    }
}

void inserir_versao_3(NoArv** raiz, Artista a) {
    NoArv* aux = *raiz;
    while (aux) {
        if (a.quantidadeGrammy < aux->artista.quantidadeGrammy)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->artista = a;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

void imprimir_versao_1(NoArv* raiz) {
    if (raiz) {
        printf("\n Nome do artista: %s\t Quantidade de Grammy: %d", raiz->artista.nome, raiz->artista.quantidadeGrammy);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

void imprimir_versao_2(NoArv* raiz) {
    if (raiz) {
        imprimir_versao_2(raiz->esquerda);
        printf("\n Nome do artista: %s\t Quantidade de Grammy: %d", raiz->artista.nome, raiz->artista.quantidadeGrammy);
        imprimir_versao_2(raiz->direita);
    }
}

NoArv* buscar(NoArv* raiz, int quantidadeGrammy) {
    if (raiz == NULL || raiz->artista.quantidadeGrammy == quantidadeGrammy) {
        return raiz;
    }

    if (quantidadeGrammy < raiz->artista.quantidadeGrammy) {
        return buscar(raiz->esquerda, quantidadeGrammy);
    }

    return buscar(raiz->direita, quantidadeGrammy);
}

int tamanho_arvore(NoArv* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int tamanho_esquerda = tamanho_arvore(raiz->esquerda);
    int tamanho_direita = tamanho_arvore(raiz->direita);

    return 1 + tamanho_esquerda + tamanho_direita;
}

int main() {
    Artista a;
    NoArv* raiz = NULL;
    int opcao, valor;

    do {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t4 - Tamanho da arvore\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                a = cadastrarArtista();
                // raiz = inserir_versao_1(raiz, a);
                // inserir_versao_2(&raiz, a);
                inserir_versao_3(&raiz, a);
                break;
            case 2:
                printf("\n\tPrimeira impressao:\n\t");
                imprimir_versao_1(raiz);
                printf("\n");
                printf("\n\tSegunda impressao:\n\t");
                imprimir_versao_2(raiz);
                printf("\n");
                break;
            case 3:
                printf("\n\tDigite a quantidade de Grammy a ser buscada: ");
                scanf("%d", &valor);
                getchar(); // Consumir o caractere de nova linha no buffer
                NoArv* resultado = buscar(raiz, valor);
                if (resultado != NULL) {
                    printf("\n\tArtista encontrado!\n\tNome: %s\tQuantidade de Grammy: %d\n", resultado->artista.nome, resultado->artista.quantidadeGrammy);
                } else {
                    printf("\n\tArtista nao encontrado!\n");
                }
                break;
            case 4:
                printf("\n\tTamanho da arvore: %d\n", tamanho_arvore(raiz));
                break;
            default:
                if (opcao != 0)
                    printf("\n\tOpcao invalida!!!\n");
        }
    } while (opcao != 0);

    return 0;
}
