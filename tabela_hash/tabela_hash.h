#define TAM_ALFABETO 26 // definir tamanho do alfabeto
#define TAM_TABELA TAM_ALFABETO * TAM_ALFABETO // definir tamanho da tabela
#define TAM_VALOR 255 // definir tamanho máximo de valores

int hash(char* chave); // retornar indice de um valor a partir de uma chave
char** tabela_hash(); // criar a tabela
void put(char* chave, char* string, char** tabela); // guardar valores na tabela hash
char* get(char* chave, char** tabela); // retornar valor a partir de uma chave
int contains(char* chave, char** tabela); // verificar se há tem algum valor para uma chave
void remover(char* chave, char** tabela); // remover um valor da tabela a partir de uma chave