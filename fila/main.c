/*
Código de uma fila.
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h" // biblioteca de fila

int main(int argc, char* argv[]){

    QueueNode* root = NULL; // criar a fila

    enqueue(&root , 'V'); // adicionar elementos na fila
    enqueue(&root , 'A');
    enqueue(&root , 'S');

    printf("%cProximo da fila: \n", peek(root)); // mostrar o próximo da fila

    display(root); // printar fila inteira

    printf("\nElemento removido: %c\n", dequeue(&root)); // remover elemento

    printf("Proximo da fila: %c\n", peek(root)); // mostrar o próximo da fila

    display(root); // printar fila inteira

    return 0;
}