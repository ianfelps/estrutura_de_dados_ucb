// algoritmo para calcular a n-esima posicao na sequencia de fibonacci

#include <stdio.h>
#include <stdlib.h>

// funcao recursiva
long fibo(int posicao){
    if (posicao <= 2){
        return 1;
    } else {
        return fibo(posicao - 1) + fibo(posicao - 2);
    }
}

int main(){

    int pos;
    // long num1 = 1, num2 = 1, aux;

    printf("Digite a posicao do termo de Fibonacci: ");
    scanf("%d", &pos);

    /* calculo com for
    for (int i = 2; i < pos; i++){
        aux = num2;
        num2 = num1 + num2;
        num1 = aux;
    } */

    printf("O %do da sequencia de Fibonacci eh %ld!", pos, fibo(pos));

    return 0;
}