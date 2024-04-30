#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

int main(int argc, char* argv[]){

    // criar nós
    No* H = no('V', NULL);
    inserir_no(H, 'A');
    inserir_no(H, 'S');
    inserir_no(H, 'C');
    inserir_no(H, 'O');

    // imprimir lista
    printf("\nlista circular: ");
    imprimir_lista(H);

    // remover nó
    remover_no(H, 'O');
    printf("\n\nlista sem 'O': ");
    imprimir_lista(H);

    remover_no(H, 'C');
    printf("\n\nlista sem 'O' e 'C': ");
    imprimir_lista(H);

    // liberar lista
    liberar_lista(H);

    return 0;
}