#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

// estrutura de um nó
No* no(char valor, No* proximo_no){
    No* no= malloc(sizeof(No));
    no -> valor = valor;
    no -> proximo_no = proximo_no;
    return no; 
}