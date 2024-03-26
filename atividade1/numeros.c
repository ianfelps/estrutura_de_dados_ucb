/*
Instruções:
Criar um programa que receba N números inteiros;
O seu programa deve imprimir uma mensagem de erro caso nenhum número seja informado;
Caso receba 1 ou mais números, o seu programa deverá imprimir:
- A quantidade de números recebidos;
- O valor médio dos números;
- O menor número;
- O maior número;
- A lista de números em ordem crescente;
*/

#include <stdio.h>
#include <stdlib.h>

// Função para trocar dois números
void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char *argv[]) {
    float media = 0;
    float maior = atof(argv[1]);
    float menor = atof(argv[1]);
    float numeros[argc - 1];

    if (argc <= 1) {
        printf("Nenhum numero fornecido como argumento.\n");
        return 1;
    }

    // Converter argumentos para float e calcular maior e menor numero
    for (int i = 1; i < argc; i++) {
        numeros[i - 1] = atof(argv[i]);
        media += numeros[i - 1];
        if (numeros[i - 1] > maior) {
            maior = numeros[i - 1];
        }
        if (numeros[i - 1] < menor) {
            menor = numeros[i - 1];
        }
    }

    // Calcular media
    media /= (argc - 1);

    // Ordenar numeros em ordem crescente (bubble sort)
    for (int i = 0; i < argc - 2; i++) {
        for (int j = 0; j < argc - i - 2; j++) {
            if (numeros[j] > numeros[j + 1]) {
                swap(&numeros[j], &numeros[j + 1]);
            }
        }
    }

    // Imprimir estatisticas
    printf("\n---------------------------------------------------------------\n");
    printf("Quantidade de numeros recebidos: %d\n", argc - 1);
    printf("Valor medio dos numeros: %.1f\n", media);
    printf("Menor numero: %.f\n", menor);
    printf("Maior numero: %.f\n", maior);
    printf("Numeros em ordem crescente: ");
    for (int i = 0; i < argc - 1; i++) {
        printf("%.f ", numeros[i]);
    }
    printf("\n---------------------------------------------------------------\n");

    return 0;
}