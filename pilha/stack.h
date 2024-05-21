// criar struct do nó para a pilha
typedef struct StackNode{
    char data;
    struct StackNode* next;
} StackNode;

// criar operações/funções
void push(StackNode** root, char data); // adiconar nó ao topo
char pop(StackNode** root); // remover nó do topo
char peek(StackNode* root); // vizualizar nó do topo
int isEmpty(StackNode* root); // verificar se a pilha está vazia
void display(StackNode* root); // mostra todos elementos empilhdos