/*
Instruções
No seu repositório de atividades, crie uma pasta atividade2;
Dentro dessa pasta, crie um arquivo verificar_numero_primo.c;
O seu programa deve receber um número inteiro como argumento (via terminal) e 
imprimir "true" caso seja número primo ou "false" caso não seja número primo;
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    int num = atoi(argv[1]), result = 0;

    if (argc <= 1) {
        printf("Nenhum numero fornecido como argumento.\n");
        return 1;
    }

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            result++;
            break;
        }
    }

    if (result == 0 && num > 1)
        printf("//true\n");
    else
        printf("//false\n");

    return 0;
}