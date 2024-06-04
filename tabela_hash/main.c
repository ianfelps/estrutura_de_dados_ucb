#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h" // bliblioteca hash

int main(int argc, char* argv[]){

    char** tabela = tabela_hash(); // inicializar a tabela hash

    put("AA", "Clube", tabela); // inserir valores na tabela 
    put("AB", "de Regatas", tabela);
    put("BA", "Vasco", tabela);
    put("BB", "da Gama", tabela);

    printf("%s\n", get("AA", tabela)); // retornar valores
    printf("%s\n", get("AB", tabela));
    printf("%s\n", get("BA", tabela));
    printf("%s\n", get("BB", tabela));

    printf("Contains BA? %d\n", contains("BA", tabela)); // verificar se há algum valor em uma chave
    remover("BA", tabela); // remover valor de uma chave
    printf("Contains BA? %d\n", contains("BA", tabela)); // verificar se há algum valor em uma chave após a remoção

    return 0;
}