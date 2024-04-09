/*
Instruções
1- O seu programa deve receber como argumento o nome de um arquivo qualquer;
2- O arquivo recebido contém números inteiros, sendo um número por linha;
3- O seu programa deve abrir o arquivo no modo leitura e carregar os números na memória;
4- O seu programa deve gerar um arquivo de saída chamado "saida.txt" que contém os mesmos números do arquivo lido mas em ordem crescente;
*/

#include <stdio.h>
#include <stdlib.h>

// função de comparação para qsort
int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]) {
    
    // abrir o arquivo para leitura
    FILE *arq_csv = fopen(argv[1], "r");

    // verificar se o arquivo abriu
    if (arq_csv == NULL) {
        printf("Erro ao abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    // determinar o número de elementos no arquivo
    int tamanho = 0;
    int numero;
    while (fscanf(arq_csv, "%d", &numero) != EOF) {
        tamanho++;
    }

    // voltar ao início do arquivo
    rewind(arq_csv);

    // ler os números do arquivo e alocar na memoria
    int *numeros = malloc(sizeof(int) * tamanho);
    for (int i = 0; i < tamanho; i++) {
        fscanf(arq_csv, "%d", &numeros[i]);
    }

    // fechar o arquivo
    fclose(arq_csv);

    // ordenar os números em ordem crescente com qsort
    qsort(numeros, tamanho, sizeof(int), comparar);
    // usei o qsort porque o bubble sort demorava absurdamente por causa da quantidade de números no arquivo :)

    // criar o arquivo de saída
    FILE *saida_txt = fopen("saida.txt", "w");
    if (saida_txt == NULL) {
        printf("Erro ao criar o arquivo de saída\n");
        return 1;
    }

    // escrever os números ordenados no arquivo de saída
    for (int i = 0; i < tamanho; i++) {
        fprintf(saida_txt, "%d\n", numeros[i]);
    }

    // fechar o arquivo de saída
    fclose(saida_txt);

    // liberar a memória alocada
    free(numeros);

    // print de confirmação
    printf("Arquivo de saida gerado!\n");

    return 0;
}