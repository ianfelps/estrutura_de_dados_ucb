#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tabela_hash.h" // bliblioteca hash

// retornar indice de um valor a partir de uma chave
int hash(char* chave){
    return (toupper(chave[0])-65)*TAM_ALFABETO + toupper(chave[1])-65; // considerar as duas primeiras letras da chave
}

// criar a tabela
char** tabela_hash(){
    char** tabela = malloc(sizeof(char*)*TAM_TABELA); // alocar memória para tabela

    for(int i = 0; i < TAM_TABELA; i++){ // percorrer todos os componentes da tabela
        tabela[i] = malloc(sizeof(char)*TAM_VALOR); // alocar cada componente da tabela na memória
        strcpy(tabela[i], ""); // "garantir" espaço de memória para requisições futuras
    }

    return tabela; // retorna a tabela
}

// guardar valores na tabela hash
void put(char* chave, char* valor, char** tabela){
    strcpy(tabela[hash(chave)], valor); // copiar string "valor" para uma posição da tabela
}

// retornar valor a partir de uma chave
char* get(char* chave, char** tabela){
    return tabela[hash(chave)]; // retorna o valor de uma posição da tabela
}

// verificar se há tem algum valor para uma chave
int contains(char* chave, char** tabela){
    int tam = strlen(tabela[hash(chave)]); // verificar tamanho da string em uma chave

    if(tam > 0){ // se a string for maior que 0
        return 1; // retorna 1
    }
    return 0; // se não, retorna 0
}

// remover um valor da tabela a partir de uma chave
void remover(char* chave, char** tabela){
    strcpy(tabela[hash(chave)], ""); // copiar string vazia para uma posição da tabela, removendo o valor
}