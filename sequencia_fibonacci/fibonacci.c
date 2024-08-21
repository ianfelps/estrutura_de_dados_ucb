#include <stdio.h>
#include <stdlib.h>

int main(){

    int pos;
    long num1 = 1, num2 = 1, aux;

    printf("Digite a posicao do termo de Fibonacci: ");
    scanf("%d", &pos);

    for (int i = 2; i < pos; i++){
        aux = num2;
        num2 = num1 + num2;
        num1 = aux;
    }

    printf("O %do da sequencia de Fibonacci eh %ld!", pos, num2);

    return 0;
}