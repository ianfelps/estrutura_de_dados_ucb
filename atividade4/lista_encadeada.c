#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

// estrutura de um nó
No* no(char valor, No* proximo_no){
    No* no = malloc(sizeof(No));
    no -> valor = valor;
    no -> proximo_no = proximo_no;
    return no; 
}

// estrutura da função de inserir um nó
void inserir_no(No* H, No* no){
    if(H != NULL){
        if(H -> proximo_no == NULL){
            H -> proximo_no = no;
        } else{
            inserir_no(H -> proximo_no, no);
        }
    }
}

// estrutura da função para printar todos os nós
void imprimir_lista(No* H){
    if(H != NULL){
        printf("%c ", H -> valor);
        imprimir_lista(H -> proximo_no);
    }
}

// estrutura da função para coletar a quantidade de nós
int quantidade_nos(No* H){
    if(H != NULL){
        return 1 + quantidade_nos(H -> proximo_no);
    }
    return 0;
}

// estrutura da função para copiar a lista de nós
No* copiar_lista(No* H){
    if(H != NULL){
        return no(H -> valor, copiar_lista(H -> proximo_no));
    }
    return NULL;
}

// estrutura da função para liberar lista da memoria
void liberar_lista(No* H){
    if(H != NULL){
        liberar_lista(H -> proximo_no);
        free(H);
        H = NULL;
    }
}

// estrutura da função para verificar a existencia de um caractere
int verificar_existencia(No* H, char valor_busca){
    if (H != NULL){
        if (H -> valor == valor_busca){
            return 1;
        } else{
            return verificar_existencia(H -> proximo_no, valor_busca);
        }
    }
    return 0;
}

// estrutura da função para verificar quantas vezes um caractere aparece
int verificar_ocorrencias(No* H, char valor_busca){
    if(H != NULL){
        if(H -> valor == valor_busca){
            return 1 + verificar_ocorrencias(H -> proximo_no, valor_busca);
        } else{
            return verificar_ocorrencias(H -> proximo_no, valor_busca);
        }
    }
    return 0;
}

// estrutura da função para printar a lista invertida
void imprimir_lista_inversa(No* H){
    if(H != NULL){
        imprimir_lista_inversa(H -> proximo_no);
        printf("%c ", H -> valor);
    }
}

// estrutura da função para inserir um nó na posicão 'i'
void inserir_no_i(No* H, char caractere, int i){
    if(H != NULL && i > 0){
        if(i == 1){
            No* novo_no = no(caractere, H -> proximo_no);
            H -> proximo_no = novo_no;
            return;
        }
        inserir_no_i(H->proximo_no, caractere, i - 1);
    }
}

// estrutura da função para remover um nó na posicão 'i'
void remover_no_i(No* H, int i){
    if(H != NULL && H != NULL && H -> proximo_no != NULL){
        if(i == 1){
            No* no_remover = H -> proximo_no;
            H -> proximo_no = no_remover -> proximo_no;
            free(no_remover);
            return;
        }
        remover_no_i(H -> proximo_no, i - 1);
    }
}