typedef struct No{
    char valor;
    struct No* proximo_no;
} No;

// funções da "biblioteca"
No* no(char valor, No* proximo_no);
void inserir_no(No* H, char valor);
void imprimir_lista(No* H);
void remover_no(No* H, char valor);
void liberar_lista(No* H);