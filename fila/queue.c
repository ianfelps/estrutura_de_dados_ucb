#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h" // biblioteca de fila

// adicionar elemento na fila (último)
void enqueue(QueueNode** root, char data){
    QueueNode* qNode = malloc(sizeof(QueueNode)); // criar o nó
    qNode->data = data; // armazena valor recebido
    qNode->next = NULL; // aponta para ninguém (está no final da fila)
    
    if (isEmpty(*root)){ // verificar se a fila está vazia
        *root = qNode; // nó criado passa a ser o primeiro da fila
    } else{ // se já tiver elementos
        QueueNode* tmp = (*root)->next; // criar nó temporário para percorrer a fila
        if (tmp == NULL){ // verificar se tem vaga no próximo lugar
            (*root)->next = qNode;
        } else{ // se não houver vaga
            do{ // percorrer a fila para encontrar o último
                if (tmp->next == NULL){ // se um nó apontar para um lugar vazio
                    tmp->next = qNode; // entra nessa vaga
                } else{ // se não
                    tmp = tmp->next; // aponta para o próximo
                }
            } while (tmp->next != NULL); // percorrer até achar um nó que aponte para nada
        }
    }
}

// remover elemento da fila (primeiro)
char dequeue(QueueNode** root){
    if (isEmpty(*root)){ // se a fila estiver vazia
        return CHAR_MIN; // retorna o menor caractere possível
    } else{ // se não estiver vazia
        QueueNode* tmp = *root; // criar nó temporário para verificar o primeiro da fila
        *root = tmp->next; // passa o primeiro lugar para o próximo
        char tmpData = tmp->data; // pega o valor do nó que será removido
        free(tmp); // liberar a memória
        return tmpData; // retorna o valor do nó removido
    }
}

// verificar próximo da fila
char peek(QueueNode* root){
    if (isEmpty(root)){ // se a fila estiver vazia
        return CHAR_MIN; // retorna o menor caractere possível
    } else{ // se não estiver vazia
        return root->data; // retorna o valor do próximo da fila
    }
}

// verificar se a fila esta vazia
int isEmpty(QueueNode* root){
    return root == NULL; // verifica se o nó "root" está nulo
}

// mostrar todos elementos da fila
void display(QueueNode* root){
    QueueNode* tmp = root; // criar nó temporário para percorrer a fila
    while (tmp != NULL){ // percorrer a fila até achar o último da fila
        printf("%c -> ", tmp->data); // printar nó
        tmp = tmp->next; // passar para o próximo
    }
}