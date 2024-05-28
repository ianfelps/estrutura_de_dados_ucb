// estrutura dos elementos da fila
typedef struct QueueNode{
    char data;
    struct QueueNode* next;
} QueueNode;

// funções
void enqueue(QueueNode** root, char data); // adicionar elemento na fila (último)
char dequeue(QueueNode** root); // remover elemento da fila (primeiro)
char peek(QueueNode* root); // verificar próximo da fila
int isEmpty(QueueNode* root); // verificar se a fila esta vazia
void display(QueueNode* root); // mostrar todos elementos da fila