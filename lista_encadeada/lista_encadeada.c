#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

// estrutura de um nó
No* no(char valor, No* proximo_no){
    No* no= malloc(sizeof(No));
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