// estrutura dos nós
typedef struct No{
    int valor;
    struct No* no_esquerdo;
    struct No* no_direito;
} No;

No* arvoreNo(int valor); // função para criar o primeiro nó
void inserir_no(No** H, int valor); // função para inserir nós
void inOrder(No* H); // função para percurso em ordem
void preOrder(No* H); // função para percurso pré-ordem
void postOrder(No* H); // função para percurso pós-ordem
No* buscar_no(No* H, int valor); // função para buscar nós
No* remover_no(No** H, int valor); // função para remover nós