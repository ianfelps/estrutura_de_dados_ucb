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
    No* n6 = no('O', NULL);

    // adicionar os nós
    inserir_no(H, n2);
    inserir_no(H, n3);
    inserir_no(H, n4);
    inserir_no(H, n5);
    inserir_no(H, n6);

    // copiar lista
    No* Hc = copiar_lista(H);

    // printar listas
    printf("lista original: ");
    imprimir_lista(H);
    printf("\ncopia: ");
    imprimir_lista(Hc);

    // alterar e adicionar valores
    // Hc -> valor = 'v';
    // H -> proximo_no -> valor = 'a';
    inserir_no(Hc, no('!', NULL));
    
    // printar listas alteradas
    printf("\n\ncopia alterada: ");
    imprimir_lista(Hc);

    // printar a quantidade de nós
    printf("\n\nquantidade de nos da original: %d", quantidade_nos(H));
    printf("\nquantidade de nos da copia: %d", quantidade_nos(Hc));

    // verificar existencia de um caractere em um nó
    printf("\n\ncaractere 'A' existe na lista? %d", verificar_existencia(H, 'A'));
    printf("\ncaractere 'B' existe na lista? %d", verificar_existencia(H, 'B'));

    // verificar quantas vezes um caractere aparece em uma lista
    printf("\n\nquantas vezes o caractere 'O' aparece na lista? %d", verificar_ocorrencias(H, 'O'));

    // imprimir lista invertida
    printf("\n\nlista invertida: ");
    imprimir_lista_inversa(Hc);

    // adicionar um novo nó em i
    inserir_no_i(Hc, 'X', 2);
    printf("\n\nnovo no em i: ");
    imprimir_lista(Hc);

    // remover um nó em i
    remover_no_i(Hc, 2);
    remover_no_i(Hc, 4);
    printf("\n\nno removido em i: ");
    imprimir_lista(Hc);

    return 0;
}