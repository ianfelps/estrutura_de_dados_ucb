#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

// função para criar o primeiro nó
No* arvoreNo(int valor){
    No* no = (No*) malloc(sizeof(No)); // aloca espaço na memória
    no->valor = valor; // atribui o valor recebido
    no->no_esquerdo = NULL; // aponta o nó esquerdo para ninguém
    no->no_direito = NULL; // aponta o nó direito para ninguém
    return no; // retorna o nó
}

// função para inserir nós
void inserir_no(No** H, int valor){
    if(*H != NULL){ // verifica se existe um nó
        if(valor <= (*H)->valor){ // verifica se o valor recebido é menor que o valor do nó
            inserir_no(&(*H)->no_esquerdo, valor); // se sim, chama a função novamente para o nó esquerdo
        } else if(valor >= (*H)->valor){ // verifica se o valor recebido é maior que o valor do nó
            inserir_no(&(*H)->no_direito, valor); // se sim, chama a função novamente para o nó direito
        }
    } else{
        *H = arvoreNo(valor); // se não houver um nó, utiliza a função acima para criar
    }
}

// função para percurso em ordem
void inOrder(No* H){
    if(H != NULL){ // verifica se existe um nó
        inOrder(H->no_esquerdo); // percorre os nós esquerdos e os printa
        printf("%d ", H->valor); // printa a raiz
        inOrder(H->no_direito); // percorre os nós direitos e os printa
    }
}

// função para percurso pré-ordem
void preOrder(No* H){
    if(H != NULL){ // verifica se existe um nó
        printf("%d ", H->valor); // printa a raiz
        preOrder(H->no_esquerdo); // percorre os nós esquerdos e os printa
        preOrder(H->no_direito); // percorre os nós direitos e os printa
    }
}

// função para percurso pós-ordem
void postOrder(No* H){
    if(H != NULL){ // verifica se existe um nó
        postOrder(H->no_esquerdo); // percorre os nós esquerdos e os printa
        postOrder(H->no_direito); // percorre os nós direitos e os printa
        printf("%d ", H->valor); // printa a raiz
    }
}

// função para buscar nós
No* buscar_no(No* H, int valor){
    if (H != NULL){ // verifica se existe um nó
        if(H->valor == valor){ // se o valor do nó for igual ao valor da raiz
            return H; // retorna a raiz
        } else if (valor < H->valor){ // se for menor que a raiz
            return buscar_no(H->no_esquerdo, valor); // passa para o nó esquerdo
        } else if (valor > H->valor){ // se for maior que a raiz
            return buscar_no(H->no_direito, valor); // passa para o nó direito
        }
    }
    return NULL;
}

// função para remover nós
No* remover_no(No** H, int valor){
    if(H != NULL){ // verifica se existe um nó
        if(valor < (*H)->valor){ // verifica se o valor recebido é menor que o valor do nó
            (*H)->no_esquerdo = remover_no(&(*H)->no_esquerdo, valor); // passa para o nó esquerdo
        } else if (valor > (*H)->valor){ // verifica se o valor recebido é maior que o valor do nó
            (*H)->no_direito = remover_no(&(*H)->no_direito, valor); // passa para o nó direito
        } else {
            // se o nó tiver apenas um ou nenhum nó
            if((*H)->no_esquerdo == NULL){ // se não houver nós na esquerda
                No* tmp = (*H)->no_direito; // cria um nó temporário com o valor da direita
                free(*H); // libera a memória
                return tmp; // retorna o nó temporário
            } else if((*H)->no_direito == NULL){ // se não houver nós na direita
                No* tmp = (*H)->no_esquerdo; // cria um nó temporário com o valor da esquerda
                free(*H); // libera a memória
                return tmp; // retorna o nó temporário
            }
            // se houver dois nós
            No* tmp = (*H)->no_direito; // cria um nó temporário com o valor da direita
            while(tmp && tmp->no_esquerdo != NULL){ // enquanto o nó temporário tiver um nó esquerdo
                tmp = tmp->no_esquerdo; // passa para o nó esquerdo
            }
            (*H)->valor = tmp->valor; // atribui o valor do nó temporário
            (*H)->no_direito = remover_no(&(*H)->no_direito, tmp->valor); // passa para o nó direito
        }
    }
    return *H;
}