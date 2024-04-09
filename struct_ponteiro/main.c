/*
Aula de Ponteiros e Struct e Alocaçao de Memoria
*/

#include <stdio.h>
#include <stdlib.h>

// def struct
typedef struct Ponto{ // plano cartesiano (ponto 'x' e ponto 'y')
    int x, y;
} Ponto;

int main(int argc, char* argv[]){

    int a = 2, b = a, *p = &a; // 'p' recebe endereço de 'a'

    // printar variaveis
    printf("a = %d \t b = %d \n", a, b);

    // printar endereço das variaveis
    printf("&a = %p \t &b = %p \n", &a, &b);

    // alterar somente 'b'
    b = 3;
    printf("\na = %d \t b = %d \n", a, b);

    // alterar somente 'a'
    a= 4;
    printf("\na = %d \t b = %d \n", a, b);

    // endereço de 'p', valor de 'p' (guarda endereço de 'a'), acessar valor de 'a' a partir de endereço em 'p'
    printf("\n&p = %p \t p = %p \t *p = %d\n", &p, p, *p);

    // alterar valor de 'a' a prtir de 'p'
    *p = 5;
    printf("\na = %d \t b = %d \n", a, b);

    // alocar 'p' na memoria
    p = malloc(sizeof(int)*5);
    p[0] = 3; // == *p = 3;
    p[1] = 55;

    printf("\n&p = %p \t p = %p \t *p = %d\n", &p, p, *p); // indice 0 de 'p'
    printf("&p = %p \t p = %p \t *p = %d\n", &p, &p[1], p[1]); // indice 1 de 'p'
    printf("\na = %d \t b = %d \n", a, b); // 'a' mantem o valor

    Ponto A; // declarar struct 'A'
    A.x = 4; // declarar ponto x de 'A'
    A.y = 4; // declarar ponto y de 'A'
    printf("\nA(%d, %d)\n", A.x, A.y);

    return 0;
}