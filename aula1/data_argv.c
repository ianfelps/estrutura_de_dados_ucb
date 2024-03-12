#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]){
    int mes;
    char *nomemes [] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio",
                        "Junho", "Julho", "Agosto", "Setembro", "Outubro",
                        "Novembro", "Dezembro"};

    if(argc == 4){
        mes = atoi(argv[2]);  /* argv contem strings. A string referente ao mes deve ser
                                transformada em um numero inteiro. A funcao atoi esta
                                sendo usada para isto: recebe a string e transforma no
                                inteiro equivalente */

        if (mes<1 || mes>12)  /* Testa se o mes e' valido */
            printf("Erro!\nUso: data dia mes ano, todos inteiros");
        else
        printf("\n%s de %s de %s", argv[1], nomemes[mes-1], argv[3]);
    }

    else printf("Erro!\nUso: data dia mes ano, todos inteiros");
}