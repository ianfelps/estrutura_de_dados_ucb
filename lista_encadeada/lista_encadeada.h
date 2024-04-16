// 2 pedaços de memoria, um valor e um ponteiro para o proximo struct (proximo nó)
typedef struct No{
    char valor;
    struct No* proximo_no;
} No;

// funções da "biblioteca"
No* no(char valor, No* proximo_no);
void inserir_no(No* H, No* no);
void imprimir_lista(No* H);
int quantidade_nos(No* H);
No* copiar_lista(No* H);
void liberar_lista(No* H);