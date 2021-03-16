
/******************************************************************
 ======== funcoesmatematicas.h
 Cabecalhos das funcoes implementadas no modulo funcoesmatematicas.c ,
 que servem para realizar diversos funcoes matematicas e validacao
******************************************************************/


/*
** Entrada: cpf string
** Saida: 1-valido 0-invalido
*/
int validarcpf (char c_pf[]);
/*
** Entrada: vetor com notas
** Entrada: vetor com pesos
** Entrada: tamanho do vetor
** Saida: media ponderada
*/
float mediap(float notas[],float pesos[], int tam);
/*
** Entrada: vetor com notas
** Entrada: tamanho do vetor
** Saida: media aritmetica
*/
float mediaa(float notas[], int tam);
/*
** Retorna o valor da soma de dois numeros recebidos
*/
float soma(float x, float y);
/*
** Retorna o valor da diferenca de dois numeros recebidos
*/
float subtracao(float x, float y);
/*
** Retorna o produto de dois numeros
*/
float produto(float x, float y);
/*
** Retorna o resultado da divisao do numero x pelo y,
** Quando y = 0 retornar 0 e imprimir "Erro: Divisao por zero
*/
float divisao(float x, float y);
/*
** Retorna o quadrado de um numero
*/
float quadrado(float x);
/*
** Retorna o cubo de um numero
*/
float cubo(float x);
/*
** Resto da divisao do numero x pelo y
*/
int restoDivisao(int x, int y);
/*
** Retorna 1 se o numero recebido for par, e 0 caso contrario
*/
int par(int x);
/*
** Retorna 1 caso x seja multiplo de y e 0 caso contrario
*/
int multiplo(int x, int y);
/*
** Retorna 1 caso x seja um numero primo e 0 caso contrario
*/
int primo(int x);
/*
** Retorna um vetor com todos os divisores do numero x
*/
int* divisores(int x);
