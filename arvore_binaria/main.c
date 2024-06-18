#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

int main (int argc, char *argv[]){
    
    // criar árvore
    No* H = NULL;

    // inserir nós
    inserir_no(&H, 10);
    inserir_no(&H, 5);
    inserir_no(&H, 15);
    inserir_no(&H, 3);
    inserir_no(&H, 7);
    inserir_no(&H, 12);
    inserir_no(&H, 18);
    
    /*
        Representação da Árvore:
                 10
               /    \
              5      15
             / \     / \
            3   7   12  18
    */

    // printar em ordem
    printf("\nEm ordem: ");
    inOrder(H);

    // printar em pré-ordem
    printf("\nEm pre-ordem: ");
    preOrder(H);

    // printar em pós-ordem
    printf("\nEm pos-ordem: ");
    postOrder(H);

    // buscar um nó
    No* buscar = buscar_no(H, 5); // buscar o nó
    if (buscar != NULL){ // verifica se a função de busca não retornou NULL
        printf("\n\nValor encontrado: %d \n", buscar->valor); // se não retornou NULL, valor encontrado
    } else { // se não:
        printf("\n\nValor nao encontrado. \n"); // valor não encontrado
    }

    // remover um nó
    No* remover = remover_no(&H, buscar->valor); // remover o nó encontrado na busca
    // printar em ordem após remoção
    printf("Em ordem apos remocao: ");
    inOrder(H);

    /*
        Representação da Árvore após a remoção:
                 10
               /    \
              7      15
             /       / \
            3       12  18
    */
    
    return 0;
}