/*
Instruções
No seu repositório de atividades no github, crie uma pasta chamada trabalho1, contendo um arquivo regressao_linear.c que implementa a solução do problema abaixo.

Crie um programa em C que calcula a regressão linear a partir de um array de coordenadas (pontos).

O programa deve receber por argumento o nome de um arquivo no formato ".csv", identificar a quantidade de registros no arquivo e alocar dinamicamente um array de struct Ponto. 

A regressão linear é uma técnica de análise estatística que busca encontrar a linha que melhor se ajusta aos dados, minimizando os erros quadrados.

Descrição
- Leia os pontos (x,y) no arquivo informado;
- Calcule a média dos valores de x e y;
- Calcule a inclinação (coeficiente angular) da reta de regressão;
- Calcule o ponto de intercepção (coeficiente linear) da reta de regressão;
-Exiba os resultados da equação da regressão linear.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_REGISTROS 256 // definir numero maximo de registros

typedef struct Ponto { // struct para armazenar os registros
    int x;
    float y;
} Ponto;

int main(int argc, char* argv[]){

    // abrir arquivo com os dados a partir do argv
    FILE *arq_dados = fopen(argv[1], "r");
    if (arq_dados == NULL) {
        printf("Erro ao abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    // verificar o número de registros no arquivo
    int tamanho = 0;
    char linhas[MAX_REGISTROS];
    while (fgets(linhas, sizeof(linhas), arq_dados) != NULL) {
        tamanho++;
    }

    // alocar struct na memoria
    Ponto *pontos = (Ponto*) malloc(tamanho * sizeof(Ponto));
    if (pontos == NULL) {
        printf("Erro ao alocar registros na memória");
        return 1;
    }

    // voltar ao inicio do arquive e ler os pontos
    rewind(arq_dados);
    float soma_x = 0, soma_y = 0; // declarar variaveis para calculo da media dos pontos
    for (int i = 0; i < tamanho; i++) {
        if (fgets(linhas, sizeof(linhas), arq_dados) == NULL) {
            printf("Erro ao ler o arquivo");
            return 1;
        }
        sscanf(linhas, "%d,%f", &(pontos[i].x), &(pontos[i].y));
        soma_x += pontos[i].x;
        soma_y += pontos[i].y;
    }

    // calcular a media dos pontos
    float media_x = (float)soma_x / tamanho;
    float media_y = soma_y / tamanho;

    // calcular regressao linear
    float div1 = 0, div2 = 0;
    // inclinacao
    for (int i = 0; i < tamanho; i++) { // somatorio de i = 1 ate n (tamanho)
        div1 = (pontos[i].x - media_x) * (pontos[i].y - media_y); // (x'i - media_x) * (x'i - media_y)
        div2 = (pontos[i].x - media_x) * (pontos[i].x - media_x); // (x'i - media_x)^2
    }
    float inclinacao = div1 / div2;
    // intercepcao
    float intercepcao = media_y - inclinacao * media_x; // media_y - inclinacao * media_x

    // printar o resultado
    printf("Resultado: y = %.2fx + %.2f\n", inclinacao, intercepcao); // y = inclinacao * x + intercepcao

    // liberar memoria
    free(pontos);

    // fechar o arquivo
    fclose(arq_dados);

    return 0;
}