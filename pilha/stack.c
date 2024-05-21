#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h" // biblioteca da pilha

// adiconar nó ao topo
void push(StackNode** root, char data){
    StackNode* stackNode = malloc(sizeof(StackNode)); // crio um novo nó
    stackNode->data = data; // preencho com o valor data
    stackNode->next = *root; // novo nó vira o topo
    *root = stackNode; // atualizo o nó
}

// remover nó do topo
char pop(StackNode** root){
    if(isEmpty(*root)){ // verifica se a pilha e vazia
        return CHAR_MIN; // retorna menor caractere possivel
    }
    StackNode* tmp = *root; // variavel auxiliar
    *root = tmp->next; // 
    char tmpData = tmp->data; // 
    free(tmp); // libera a memória
    return tmpData; // retorna nó removido
}

// vizualizar nó do topo
char peek(StackNode* root){
    if(isEmpty(root)){ // verifica se a pilha e vazia
        return CHAR_MIN; // retorna menor caractere possivel
    }
    return root->data; // retorna valor do topo
}

// verificar se a pilha está vazia
int isEmpty(StackNode* root){
    return root == NULL; // verifca se o root está vazio
}

// mostra todos elementos empilhdos
void display(StackNode* root){
    StackNode* tmp = root; // variavel auxiliar
    while (tmp != NULL){ // printa todos os nós até achar o último
        printf("%c -> ", tmp->data); // printar nó
        tmp = tmp->next; // passa para o próximo
    }
    printf("NULL\n"); // quando acabar
}