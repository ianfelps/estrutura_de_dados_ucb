/*
Criar e editar arquivos em C
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    // declarar arquivo
    FILE *arq_txt;

    // abrir arquivo, apagar infos existentes e criar novas zeradas ("w")
    // arq_txt = fopen("arq.txt", "w");

    // abrir arquivo e adicionar infos ("a")
    arq_txt = fopen("arq.txt", "a");

    // verificar se o arquivo foi aberto
    if (arq_txt == NULL){
        printf("Erro ao abrir arquivo arq.txt");
        exit(1);
    }

    // escrever no arquivo
    fprintf(arq_txt, argv[1]);

    // quebrar linha para nova mensagem
    fprintf(arq_txt, "\n");

    // fechar arquivo
    fclose(arq_txt);

    return 0;
}