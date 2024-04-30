#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

// estrutura de um nó
No* no(char valor, No* proximo_no){
    No* no = malloc(sizeof(No));
    no -> valor = valor;
    no -> proximo_no = proximo_no;
    return no; 
}

// função para inserir um novo nó
void inserir_no(No* H, char valor){
    if (H != NULL){
        if (H -> proximo_no == NULL){
            H -> proximo_no = no(valor, H);
        } else{
            No* aux = H -> proximo_no;
            while(aux -> proximo_no != H){
                aux = aux -> proximo_no;
            }
            aux -> proximo_no = no(valor, H);
        }
    }
}

// função para printar a lista circular
void imprimir_lista(No* H){
    if (H != NULL){
        printf("%c ", H -> valor);
        No* aux = H -> proximo_no;
        while(aux != H && aux != NULL){
            printf("%c ", aux -> valor);
            aux = aux -> proximo_no;
        }
    }
}

// função para remover um nó da lista circular
void remover_no(No* H, char valor){
    if (H != NULL){
        No* aux;
        No* aux_ant;

        aux = H -> proximo_no;
        aux_ant = H;

        while(aux != H && aux != NULL){
            if (aux -> valor == valor){
                aux_ant -> proximo_no = aux -> proximo_no;
                free(aux);
                aux = aux_ant -> proximo_no;
            } else {
                aux_ant = aux;
                aux = aux -> proximo_no;
            }
        }
    }
}


void liberar_lista(No* H){
    if (H != NULL){
        free(H);
    }
}