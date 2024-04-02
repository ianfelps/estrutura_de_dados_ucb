/*
Ler arquivos .txt em C
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    // variavel para armazenar string
    char txt[100];
    
    // declarar arquivo
    FILE *arq_txt;

    // abrir arquivo para leitura ("r")
    arq_txt = fopen("arq.txt", "r");

    // verificar se o arquivo foi aberto
    if (arq_txt == NULL){
        printf("Erro ao abrir arquivo arq.txt");
        exit(1);
    }

    // ler e printar strings do arquivo
    while (fscanf(arq_txt, "%[^\n]\n", &txt) != EOF){
        printf("%s ", txt);
    }

    // fechar arquivo
    fclose(arq_txt);

    return 0;
}