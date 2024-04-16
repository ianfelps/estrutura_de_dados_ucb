#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

int main(int argc, char* argv[]){

    // criar os nós
    No* H = no('V', NULL);
    No* n2 = no('A', NULL);
    No* n3 = no('S', NULL);
    No* n4 = no('C', NULL);
    No* n5 = no('O', NULL);

    // adicionar os nós
    inserir_no(H, n2);
    inserir_no(H, n3);
    inserir_no(H, n4);
    inserir_no(H, n5);

    // printar lista
    printf("lista original: ");
    imprimir_lista(H);

    // copiar lista
    No* Hc = copiar_lista(H);

    // printar a quantidade de nós
    printf("\nquantidade de nos da original: %d", quantidade_nos(H));
    printf("\nquantidade de nos da copia: %d", quantidade_nos(Hc));

    // alterar valores
    Hc -> valor = 'v';
    H -> proximo_no -> valor = 'a';
    inserir_no(H, no('!', NULL));
    
    // printar listas alteradas
    printf("\noriginal alterada: ");
    imprimir_lista(H);
    printf("\ncopia: ");
    imprimir_lista(Hc);

    // liberar lista da memoria
    liberar_lista(Hc);

    return 0;
}