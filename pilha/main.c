#include <stdio.h>
#include <stdlib.h>
#include "stack.h" // biblioteca da pilha

int main(int argc, char* argv[]){

    StackNode* top = NULL; // criar pilha

    push(&top, 'S'); // adicionar nó ao topo
    push(&top, 'A');
    push(&top, 'V');

    display(top); // exibir toda pilha

    printf("%c \n", pop(&top)); // remover nó do topo

    display(top); // exibir toda pilha novamente
    
    printf("%c \n", peek(top)); // exibe nó do topo

    printf("%c ", pop(&top)); // remove os ultimos nós
    printf("%c ", pop(&top));

    return 0;
}